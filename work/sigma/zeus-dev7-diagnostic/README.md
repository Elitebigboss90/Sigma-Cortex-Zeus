# Zeus dev7 nested-hub candidate with diagnostics

Dev7 adds a second native USBHub instance for Xtend behind Sigma's own hub. It is an experimental Windows candidate, not a hardware-verified fix or PS5/game build. Its diagnostics overwrite vendor input bytes 56–63. Keep the updater disabled until the user chooses this separate firmware write. Originals and earlier candidates are preserved.

Evidence: with all Sigma accessory ports empty, dev6 reads hub `1A40:0101` successfully. Connecting only powered Xtend directly to Sigma, without reboot, changes the cached descriptor identity to hub `05E3:0610`, followed by return `0D`. Zeus Init never runs. Original Sigma startup constructs one hub class, which is already bound by the time the additional hub appears.

The corrected nested-hub emulator executes Sigma's actual reset-complete event and parent-address masking. With one hub instance, a HID fallback wrongly addresses the unclaimed hub, and later reads at address zero return modeled `0D`; with a second native hub instance, both hubs and Zeus initialize. Dev7's own tests run its constructor and the real nested event path, then native HID polling for both paddles. Synthetic descriptors and mocked transfers remain limits: this is not a physical USB capture or proof that hardware will behave identically.

Updater SHA-256:

`3487116c083da806a0194f1cd08af8d0b87e806c33b8b8bf9562b4cc4b34839d`

The new 24-byte hub object uses reserved RAM at `20005604`; combined state uses 204 of the existing 256 reserved bytes. All original six registrations remain, followed by Zeus at slot 6 and the extra hub at slot 7. Heap and stack bounds remain as in dev3. The image is 192,512 bytes, still 94 application pages. Twelve offline groups pass, including 125 distinct recorded control prefixes at 23/64 bytes, native nested initialization, paddle polling/merge, constructor/registry preservation, boundary canaries and error reporting. Updater native code and all 749 other resources are unchanged.

For the first hardware test after a user-chosen installation, use powered Xtend alone in the known working Sigma accessory port and connect Sigma's console/PC port to Windows. A read-only capture command is:

```powershell
.\inspect_windows_hid.ps1 -CaptureDevice Sigma -CaptureSeconds 10 -SnapshotPath .\sigma-dev7-input.json
```

It sends no output/feature reports and refuses to overwrite an existing file. Return the capture for analysis. If Python is available, use `python decode_sigma_diagnostic.py sigma-dev7-input.json`.

Byte 56 is `5A`; byte 57 is `7x` with a changing heartbeat. Even-heartbeat bytes 58–63 are Zeus USB address, polling flag, Init return (`FF` = never called), native input length, accepted counter, ignored counter. Odd-heartbeat bytes 58–61 are cached descriptor VID/PID in little-endian order, byte 62 is the last descriptor return, and byte 63 has bit 0 for the Zeus registry slot and bit 1 for the additional hub registry slot. The bit-1 meaning differs from dev6.

The last successful descriptor identity can belong to another device and precede the latest error. Registry flags check pointers, not successful binding. No wheel-icon update is included. The two left-positioned Windows rotation bars are baseline Rx/Ry zero values sent by the diagnostic heartbeat; they are not detection indicators.

Physical nested polling, reset/error recovery, detach/reconnect, coexistence under load and PS5 behavior remain unverified. No agent firmware write occurred. Reproduction requires the full repository and preserved dev3 artifacts, not just this ZIP. `source` contains the scripts used for review; the included assembly is the actual additional patch source.
