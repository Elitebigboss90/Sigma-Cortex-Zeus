# Read only: Windows device-tree metadata. No device reports or USB commands.
# Raw device instance paths and serial numbers are never emitted or saved.
param([string]$SnapshotPath,
      [ValidateSet('Zeus','Sigma','All')][string]$TargetDevice = 'Zeus')
$ErrorActionPreference = 'Stop'
if (-not ('SigmaUsbAncestry' -as [type])) {
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
public static class SigmaUsbAncestry {
    [StructLayout(LayoutKind.Sequential)] struct InterfaceData {
        public uint Size; public Guid ClassGuid; public uint Flags; public IntPtr Reserved;
    }
    [StructLayout(LayoutKind.Sequential)] struct DeviceData {
        public uint Size; public Guid ClassGuid; public uint DevInst; public IntPtr Reserved;
    }
    [DllImport("hid.dll")] static extern void HidD_GetHidGuid(out Guid guid);
    [DllImport("cfgmgr32.dll", CharSet=CharSet.Unicode)]
    static extern uint CM_Get_Device_Interface_List_SizeW(out uint length, ref Guid guid, string device, uint flags);
    [DllImport("cfgmgr32.dll", CharSet=CharSet.Unicode)]
    static extern uint CM_Get_Device_Interface_ListW(ref Guid guid, string device, [Out] char[] buffer, uint length, uint flags);
    [DllImport("cfgmgr32.dll")] static extern uint CM_Get_Parent(out uint parent, uint child, uint flags);
    [DllImport("cfgmgr32.dll")] static extern uint CM_Get_Device_ID_Size(out uint length, uint device, uint flags);
    [DllImport("cfgmgr32.dll", CharSet=CharSet.Unicode)]
    static extern uint CM_Get_Device_IDW(uint device, StringBuilder buffer, uint length, uint flags);
    [DllImport("setupapi.dll", SetLastError=true)]
    static extern IntPtr SetupDiCreateDeviceInfoList(IntPtr classGuid, IntPtr hwnd);
    [DllImport("setupapi.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    static extern bool SetupDiOpenDeviceInterfaceW(IntPtr set, string path, uint flags, ref InterfaceData data);
    [DllImport("setupapi.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    static extern bool SetupDiGetDeviceInterfaceDetailW(IntPtr set, ref InterfaceData data, IntPtr detail, uint size, out uint required, ref DeviceData device);
    [DllImport("setupapi.dll")] static extern bool SetupDiDestroyDeviceInfoList(IntPtr set);
    public class Node {
        public int Depth;
        public string Kind, Identity, NodeToken;
    }
    public class Tree {
        public string TargetIdentity;
        public Node[] Nodes;
    }
    static string[] Paths() {
        Guid guid; HidD_GetHidGuid(out guid);
        for (int attempt=0;attempt<5;attempt++) {
            uint length;
            uint status=CM_Get_Device_Interface_List_SizeW(out length,ref guid,null,0);
            if(status!=0) throw new Exception("HID list size failed: "+status);
            char[] buffer=new char[length];
            status=CM_Get_Device_Interface_ListW(ref guid,null,buffer,length,0);
            if(status==0) return new string(buffer).Split(new char[]{'\0'},StringSplitOptions.RemoveEmptyEntries);
            if(status!=0x1a) throw new Exception("HID list read failed: "+status);
        }
        throw new Exception("USB list changed repeatedly; reconnect and retry");
    }
    static uint DeviceInstance(string path) {
        IntPtr set=SetupDiCreateDeviceInfoList(IntPtr.Zero,IntPtr.Zero);
        if(set==new IntPtr(-1)) throw new Exception("Device metadata list failed");
        try {
            InterfaceData iface=new InterfaceData(); iface.Size=(uint)Marshal.SizeOf(typeof(InterfaceData));
            if(!SetupDiOpenDeviceInterfaceW(set,path,0,ref iface))
                throw new Exception("Interface metadata lookup failed: "+Marshal.GetLastWin32Error());
            DeviceData device=new DeviceData(); device.Size=(uint)Marshal.SizeOf(typeof(DeviceData));
            uint required;
            SetupDiGetDeviceInterfaceDetailW(set,ref iface,IntPtr.Zero,0,out required,ref device);
            if(required==0) throw new Exception("Interface metadata size unavailable");
            IntPtr detail=Marshal.AllocHGlobal((int)required);
            try {
                Marshal.WriteInt32(detail,IntPtr.Size==8 ? 8 : 6);
                if(!SetupDiGetDeviceInterfaceDetailW(set,ref iface,detail,required,out required,ref device))
                    throw new Exception("Interface metadata read failed: "+Marshal.GetLastWin32Error());
                return device.DevInst;
            } finally { Marshal.FreeHGlobal(detail); }
        } finally { SetupDiDestroyDeviceInfoList(set); }
    }
    static string Token(Dictionary<uint,string> tokens,uint node) {
        string token;
        if(!tokens.TryGetValue(node,out token)) {
            token="n"+(tokens.Count+1).ToString(); tokens.Add(node,token);
        }
        return token;
    }
    public static Tree[] Inspect(string requested) {
        var trees=new List<Tree>();
        var firstNodes=new HashSet<uint>();
        var tokens=new Dictionary<uint,string>();
        foreach(string path in Paths()) {
            string lower=path.ToLowerInvariant();
            bool sigma=lower.Contains("vid_0eb7&pid_0e07");
            bool zeus=lower.Contains("vid_3670&pid_0804");
            if(!sigma && !zeus) continue;
            if(requested=="Sigma" && !sigma || requested=="Zeus" && !zeus) continue;
            uint current=DeviceInstance(path);
            var nodes=new List<Node>();
            uint? firstUsb=null;
            for(int depth=0;depth<64;depth++) {
                uint length;
                if(CM_Get_Device_ID_Size(out length,current,0)!=0) throw new Exception("Device metadata node unavailable");
                var id=new StringBuilder((int)length+1);
                if(CM_Get_Device_IDW(current,id,length+1,0)!=0) throw new Exception("Device metadata identifier unavailable");
                string raw=id.ToString().ToUpperInvariant();
                if(raw.StartsWith("USB\\ROOT_HUB")) {
                    nodes.Add(new Node {Depth=depth,Kind="USB root hub",Identity="root",NodeToken=Token(tokens,current)});
                    break;
                }
                if(raw.StartsWith("USB\\")) {
                    var match=Regex.Match(raw,@"VID_([0-9A-F]{4})&PID_([0-9A-F]{4})");
                    if(match.Success) {
                        if(!firstUsb.HasValue) firstUsb=current;
                        nodes.Add(new Node {Depth=depth,Kind=raw.Contains("&MI_") ? "USB interface" : "USB device",
                            Identity=match.Groups[1].Value+":"+match.Groups[2].Value,NodeToken=Token(tokens,current)});
                    }
                }
                uint parent;
                if(CM_Get_Parent(out parent,current,0)!=0) break;
                current=parent;
            }
            if(firstUsb.HasValue && firstNodes.Add(firstUsb.Value))
                trees.Add(new Tree {TargetIdentity=sigma ? "0EB7:0E07" : "3670:0804",Nodes=nodes.ToArray()});
        }
        return trees.ToArray();
    }
}
'@
}
$snapshot = [ordered]@{
    observed_utc = [DateTime]::UtcNow.ToString('o')
    operation = 'Read-only present HID and ancestor devnode metadata; no USB commands; paths/serial numbers omitted'
    direction = 'Target device toward PC root hub'
    trees = @([SigmaUsbAncestry]::Inspect($TargetDevice))
    limitations = 'Includes hubs on the PC connection path; use the recorded physical connection to distinguish Xtend hubs from PC-side hubs'
}
$json = $snapshot | ConvertTo-Json -Depth 7
if ($SnapshotPath) {
    $absolute = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($SnapshotPath)
    $stream = [System.IO.File]::Open($absolute, [System.IO.FileMode]::CreateNew)
    try {
        $writer = New-Object System.IO.StreamWriter($stream)
        try { $writer.WriteLine($json) } finally { $writer.Dispose() }
    } finally { $stream.Dispose() }
}
$json
