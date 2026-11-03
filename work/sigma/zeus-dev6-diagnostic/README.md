# Zeus dev6 USB-discovery diagnostic

This is an experimental Windows diagnostic, not a confirmed wheel-support fix. It has not been installed or hardware-tested. It overwrites vendor input bytes 56–63, so it is not intended for PS5/game use. Keep the updater disabled until the user explicitly chooses this new firmware write. Dev3/dev5 and the vendor originals are preserved.

Dev5 is now independently observed running on the user's Sigma. Its heartbeat works, but repeated reconnect and same-port cold-start captures show wheel address 0, polling disabled, Init status FF (never called), and no input callbacks. Therefore the observed failure happens before the report-length parser. Dev6 probes the original device-descriptor read path and checks the expected Zeus registry slot and vtable pointer. It retains dev5's 23/64-byte ID1-prefix handling.

The updater SHA-256 is:

`d6c3bb2399993b3705492dc05c22cb8cc1531643d154521594d3d79eea2be683`

The application is 192,512 bytes and occupies the same 94 2-KiB application pages as the original/dev3. This does not establish bootloader acceptance or recovery. Nine offline verification groups pass, including 125 distinct captured control prefixes at both lengths, descriptor success/failure/short-read cases, register/stack preservation through the descriptor trampoline, four registry/vtable states, report rejection, timer wraparound and state canaries. Native executable sections and all 749 non-firmware updater resources are unchanged. See the included manifests for exact hashes and limits.

After an explicitly authorized installation, keep the test simple: powered Xtend alone in the Sigma accessory port known to detect the base, with Sigma's console/PC port connected to Windows. A read-only capture command is:

```powershell
.\inspect_windows_hid.ps1 -CaptureDevice Sigma -CaptureSeconds 10 -SnapshotPath .\sigma-dev6-input.json
```

It refuses to overwrite an existing capture and sends no output or feature reports. Return the JSON for analysis. If Python is available, `python decode_sigma_diagnostic.py sigma-dev6-input.json` decodes it.

Each ID1 report has byte 56 = `5A` and byte 57 = `6x`, where x is a changing heartbeat. Even and odd heartbeats select different diagnostic pages:

| Bytes | Even heartbeat | Odd heartbeat |
| --- | --- | --- |
| 58 | Wheel USB address | Last successful full descriptor VID, low byte |
| 59 | Poll-enabled | VID, high byte |
| 60 | Last Zeus Init return (`FF` = never called) | Last successful full descriptor PID, low byte |
| 61 | Last native input length | PID, high byte |
| 62 | Accepted ID1 counter modulo 256 | Last device-descriptor request return (`FF` = never called) |
| 63 | Ignored report counter modulo 256 | Bit 0: Zeus pointer in expected registry slot 6; bit 1: Zeus vtable pointer matches |

The stored VID/PID is the last successful full descriptor read, potentially from another accessory or hub and potentially older than the latest error code. An 8-byte read never populates identity. A registry-slot mismatch does not show where the pointer went; it identifies a deviation from the verified constructor model. A matching vtable pointer does not validate all object contents.

The two left-positioned bars seen in the user's Windows screenshot are Rx/Ry (X/Y Rotation). Live dev5 reports put them at zero while the first four axes are 128. The periodic diagnostic sends these baseline positions even without a bound wheel; they are not detection indicators. Both diagnostic builds retain this report behavior.

The `source` directory is a review snapshot. Rebuilding uses the full repository, preserved dev3 artifacts, and the local analysis dependencies; the ZIP alone is not a complete toolchain. No agent firmware write was performed.
