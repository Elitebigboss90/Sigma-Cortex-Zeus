# Read-only enumeration of present HID interfaces. No feature/output reports,
# update commands or configuration changes are issued. Optional input capture
# opens only the Zeus interrupt input stream; it sends no device reports.
param([string]$SnapshotPath, [ValidateRange(0,60)][int]$CaptureSeconds = 0,
      [ValidateSet('Zeus','Sigma')][string]$CaptureDevice = 'Zeus')
$ErrorActionPreference = 'Stop'
if (-not ('SigmaHidInspection' -as [type])) {
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;
public static class SigmaHidInspection {
    [DllImport("hid.dll")] static extern void HidD_GetHidGuid(out Guid guid);
    [DllImport("cfgmgr32.dll", CharSet=CharSet.Unicode)]
    static extern uint CM_Get_Device_Interface_List_SizeW(out uint length, ref Guid guid, string device, uint flags);
    [DllImport("cfgmgr32.dll", CharSet=CharSet.Unicode)]
    static extern uint CM_Get_Device_Interface_ListW(ref Guid guid, string device, [Out] char[] buffer, uint length, uint flags);
    [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    static extern SafeFileHandle CreateFile(string path, uint access, uint share, IntPtr security, uint creation, uint flags, IntPtr template);
    [StructLayout(LayoutKind.Sequential)] struct Attributes {
        public int Size; public ushort VendorID, ProductID, VersionNumber;
    }
    [StructLayout(LayoutKind.Sequential)] struct Caps {
        public ushort Usage, UsagePage, InputReportByteLength, OutputReportByteLength, FeatureReportByteLength;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst=17)] public ushort[] Reserved;
        public ushort NumberLinkCollectionNodes, NumberInputButtonCaps, NumberInputValueCaps, NumberInputDataIndices;
        public ushort NumberOutputButtonCaps, NumberOutputValueCaps, NumberOutputDataIndices;
        public ushort NumberFeatureButtonCaps, NumberFeatureValueCaps, NumberFeatureDataIndices;
    }
    [DllImport("hid.dll")] static extern bool HidD_GetAttributes(SafeFileHandle device, ref Attributes attributes);
    [DllImport("hid.dll")] static extern bool HidD_GetPreparsedData(SafeFileHandle device, out IntPtr data);
    [DllImport("hid.dll")] static extern bool HidD_FreePreparsedData(IntPtr data);
    [DllImport("hid.dll")] static extern int HidP_GetCaps(IntPtr data, out Caps caps);
    public class Device {
        public string Identity, Usage, Inspection;
        public int InputReportBytes, OutputReportBytes, FeatureReportBytes;
    }
    static string[] PresentPaths() {
        Guid guid; HidD_GetHidGuid(out guid);
        char[] buffer = null;
        for (int attempt=0; attempt<5; attempt++) {
            uint length;
            uint status=CM_Get_Device_Interface_List_SizeW(out length, ref guid, null, 0);
            if (status!=0) throw new Exception("HID list size failed: 0x"+status.ToString("X"));
            buffer=new char[length];
            status=CM_Get_Device_Interface_ListW(ref guid, null, buffer, length, 0);
            if (status==0) break;
            if (status!=0x1A || attempt==4) throw new Exception("HID list failed: 0x"+status.ToString("X"));
        }
        return new string(buffer).Split(new char[]{'\0'}, StringSplitOptions.RemoveEmptyEntries);
    }
    public static Device[] Inspect() {
        var devices=new List<Device>();
        foreach (string path in PresentPaths()) {
            string lower=path.ToLowerInvariant();
            if (!lower.Contains("vid_3670") && !lower.Contains("vid_0eb7&pid_0e07") &&
                !lower.Contains("vid_046d&pid_c260") && !lower.Contains("vid_0483")) continue;
            // Only retain VID/PID, never device paths or serial numbers.
            int start=lower.IndexOf("vid_");
            var device=new Device { Identity=lower.Substring(start, 17).ToUpperInvariant(), Inspection="Metadata open failed" };
            using (SafeFileHandle handle=CreateFile(path, 0, 3, IntPtr.Zero, 3, 0, IntPtr.Zero)) {
                if (!handle.IsInvalid) {
                    Attributes attributes=new Attributes(); attributes.Size=Marshal.SizeOf(typeof(Attributes));
                    if (HidD_GetAttributes(handle, ref attributes))
                        device.Identity=attributes.VendorID.ToString("X4")+":"+attributes.ProductID.ToString("X4");
                    IntPtr data;
                    if (HidD_GetPreparsedData(handle, out data)) {
                        try {
                            Caps caps;
                            if (HidP_GetCaps(data, out caps)==0x00110000) {
                                device.Usage=caps.UsagePage.ToString("X4")+":"+caps.Usage.ToString("X4");
                                device.InputReportBytes=caps.InputReportByteLength;
                                device.OutputReportBytes=caps.OutputReportByteLength;
                                device.FeatureReportBytes=caps.FeatureReportByteLength;
                                device.Inspection="Present; metadata read";
                            }
                        } finally { HidD_FreePreparsedData(data); }
                    } else device.Inspection="Present; HID caps unavailable";
                }
            }
            devices.Add(device);
        }
        return devices.ToArray();
    }
    public class Frame {
        public long ElapsedMilliseconds;
        public int Length;
        public string Hex;
    }
    public static Frame[] CaptureInput(int seconds, bool sigma) {
        string selected=null;
        foreach (string path in PresentPaths()) {
            if (path.ToLowerInvariant().Contains(sigma ? "vid_0eb7&pid_0e07" : "vid_3670&pid_0804")) {
                // Sigma also exposes a feature-only collection. Select only
                // the input collection, using metadata without any reports.
                bool hasInput=false;
                using (SafeFileHandle metadata=CreateFile(path,0,3,IntPtr.Zero,3,0,IntPtr.Zero)) {
                    IntPtr data;
                    if (!metadata.IsInvalid && HidD_GetPreparsedData(metadata,out data)) {
                        try { Caps caps; hasInput=HidP_GetCaps(data,out caps)==0x00110000 && caps.InputReportByteLength>0; }
                        finally { HidD_FreePreparsedData(data); }
                    }
                }
                if (!hasInput) continue;
                if (selected!=null) throw new Exception("Multiple matching input interfaces present; capture selection is ambiguous");
                selected=path;
            }
        }
        if (selected==null) throw new Exception("Requested input device is not directly attached to Windows");
        var frames=new List<Frame>();
        using (SafeFileHandle handle=CreateFile(selected, 0x80000000, 3, IntPtr.Zero, 3, 0x40000000, IntPtr.Zero)) {
            if (handle.IsInvalid) throw new Exception("Read-only input open failed: "+Marshal.GetLastWin32Error());
            using (var input=new System.IO.FileStream(handle, System.IO.FileAccess.Read, 64, true)) {
                var clock=System.Diagnostics.Stopwatch.StartNew();
                while (clock.ElapsedMilliseconds<seconds*1000 && frames.Count<20000) {
                    byte[] data=new byte[64];
                    var pending=input.ReadAsync(data,0,data.Length);
                    int remaining=Math.Max(1,seconds*1000-(int)clock.ElapsedMilliseconds);
                    if (!pending.Wait(remaining)) {
                        // Disposing the asynchronous handle cancels the pending input.
                        input.Dispose();
                        try { pending.GetAwaiter().GetResult(); } catch (System.IO.IOException) {} catch (ObjectDisposedException) {} catch (OperationCanceledException) {}
                        break;
                    }
                    int length=pending.GetAwaiter().GetResult();
                    if (length==0) break;
                    frames.Add(new Frame { ElapsedMilliseconds=clock.ElapsedMilliseconds, Length=length,
                        Hex=BitConverter.ToString(data,0,length).Replace("-","").ToLowerInvariant() });
                }
            }
        }
        return frames.ToArray();
    }
}
'@
}
$devices = @([SigmaHidInspection]::Inspect())
$snapshot = [ordered]@{
    observed_utc = [DateTime]::UtcNow.ToString('o')
    operation = 'Present HID enumeration and metadata only; no input, output or feature reports; no serial numbers'
    devices = $devices
    limitations = 'Windows report sizes are HID buffer capacities, not actual interrupt transfer lengths. Devices behind Sigma are not visible individually to Windows.'
}
if ($CaptureSeconds) {
    $snapshot.operation = "Present HID metadata plus read-only $CaptureDevice interrupt input capture; no output or feature reports; no serial numbers"
    $snapshot.frames = @([SigmaHidInspection]::CaptureInput($CaptureSeconds, $CaptureDevice -eq 'Sigma'))
}
$json = $snapshot | ConvertTo-Json -Depth 5
if ($SnapshotPath) {
    $absolute = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($SnapshotPath)
    $stream = [System.IO.File]::Open($absolute, [System.IO.FileMode]::CreateNew)
    try {
        $writer = New-Object System.IO.StreamWriter($stream)
        try { $writer.WriteLine($json) } finally { $writer.Dispose() }
    } finally { $stream.Dispose() }
}
$json
