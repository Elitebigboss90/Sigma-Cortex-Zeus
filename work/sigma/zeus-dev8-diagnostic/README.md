# Zeus dev8 measured Xtend hub-chain candidate

Dev8 provides three native USBHub instances: Sigma's original hub plus two extra instances for the measured Xtend branch. It retains Windows diagnostics and the 23/64-byte ID1 control-prefix parser. It is not yet hardware-tested and is not intended for PS5/game use while diagnostics overwrite vendor report bytes 56–63. Preserve originals and earlier candidates; a new firmware write requires the user's choice.

Dev7 hardware still showed no Zeus initialization, although its additional hub instance was registered. Windows device-tree inspection found three `05E3:0610` ancestors above Zeus. A simultaneous Sigma tree shared the outermost of those hubs and the PC's `174C:2174` hub. The exact-same-PC-socket comparison then showed Sigma itself has only one `05E3:0610` ancestor on that PC path, confirming two additional hub layers in the Xtend branch. Together with Sigma's internal `1A40:0101` hub, the converter must manage three hubs. Dev7 supplied two.

Updater SHA-256:

`630e9a0af1fa7c1b20b2798e27503284eb9687b37bff648f0d9b00f31c7601d8`

Extra native hub objects are at `20005604` and `2000561C`, in registry slots 7 and 8 after Zeus at slot 6. All six original registrations remain. Total reserved state uses 228/256 bytes; original heap/stack bounds are unchanged from dev3. Application size is 192,512 bytes / 94 pages, the same as installed dev6/dev7.

Twelve offline verification groups pass on the actual image, including native reset-complete events through three hubs into Zeus, native paddle polling at 23/64 bytes, 125 distinct control-prefix replays, ABI, canaries and malformed-report rejection. A separate comparison of the actual dev7/dev8 images against the same three-hub transport model reproduces dev7's observed descriptor error `0D`; dev8 binds all hubs and Zeus. Synthetic hub descriptors and mocked control/interrupt transfers remain limits. Physical polling/timing, nested-error recovery, detach/reconnect, coexistence and PS5 behavior remain unverified. Updater native code and all 749 other resource payloads are unchanged.

After a user-chosen installation, connect powered Xtend to the known working Sigma accessory port, leave base/pedals disconnected for the first test, and connect Sigma's console/PC port to Windows. Read-only capture:

```powershell
.\inspect_windows_hid.ps1 -CaptureDevice Sigma -CaptureSeconds 10 -SnapshotPath .\sigma-dev8-input.json
```

Return the capture for decoding, or use `python decode_sigma_diagnostic.py sigma-dev8-input.json` if Python is available. The capture command sends no output/feature reports and refuses to overwrite an existing file.

Byte 56 is `5A`; byte 57 is `8x` with a changing heartbeat. Even-heartbeat bytes 58–63 contain Zeus address, polling flag, Init return (`FF` = never attempted), last native input length, accepted counter, ignored counter. Odd-heartbeat bytes contain:

| Byte | Meaning |
| --- | --- |
| 58 | Original Sigma hub's USB address |
| 59 | First added hub's USB address |
| 60 | Second added hub's USB address |
| 61 | Second added hub's polling flag |
| 62 | Last device-descriptor request return (`FF` = never called) |
| 63 | Bit 0: Zeus slot 6 matches; bit 1: second added hub slot 8 matches |

Version 8 reports hub addresses instead of the cached VID/PID from versions 6/7. It no longer maintains an unused Init-attempt counter. Registry flags prove pointer placement, not successful binding. No wheel-icon update is included. Baseline Rx/Ry axis values can remain zero in Windows until actual wheel data arrives.

No agent firmware write occurred. Reproduction needs the full repository, preserved dev3 artifacts and analysis dependencies. `source` contains the new scripts and the actual assembly is included; this ZIP is not a standalone toolchain.
