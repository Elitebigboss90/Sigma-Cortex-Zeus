# Sigma normal-mode USB observation

Observed October 27, 2026, America/Los_Angeles, after the user confirmed Sigma was connected normally. Only macOS IORegistry was read. No device was opened for this observation, and no HID feature/output or update command was issued.

| Source | SHA-256 |
| --- | --- |
| `reports/sigma-zeus-live-hid-001.json` | `28b0dbfa234e79d33088d2a0219181d8fd18d087c491e391e21fa2d0206d6b19` |
| `reports/sigma-zeus-usb-registry-001.json` | `63813f6c73c3f296c7e992dd6abb9164d1f1f21134f031eead77c8142ad2093b` |

Sigma's observed product string is `FANATEC WHEEL(PS5 / PS4 MODE)`, manufacturer `Fanatec`, USB VID/PID `0EB7:0E07`, bcdDevice `0625`. HID capabilities report maximum input 64 bytes, output 32 bytes and feature 64 bytes. These are application-interface capabilities; they do not establish the bootloader's transfer sizes.

Its 160-byte report descriptor, SHA-256 `9c099ea4b1d5400969a3363d781f1b354efd25e2d382b81b56cf31c81b01cdee`, is byte-identical to file range `[0x268C3,0x26963)` in decoded Sigma 1.1.5 SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`. Device identity and descriptor therefore agree with the target's console-facing interface. They do not prove that every installed firmware byte, board revision, MCU or bootloader matches the offline target.

The USB registry additionally reports one configuration, current configuration 1, EP0 maximum packet 64, and class/subclass/protocol all 0. The selected registry output does not contain complete interface/endpoint descriptors, so no additional bus-framing claim follows from it.

The same observations identify Zeus separately as `3670:0804`/bcdDevice `011A` and a `Dash4` device as `3670:0607`/bcdDevice `0143`. The display identity is not treated as a wheel input device. The new driver explicitly rejects other PIDs, including 0607, in both recognition and endpoint eligibility; its emulator cases include that observed identity.

The scripts omit serial numbers and unrelated-device properties. Reproduce with new output filenames:

```sh
work/tools/python/bin/python scripts/capture_hid_descriptors.py reports/sigma-zeus-live-hid-002.json
work/tools/python/bin/python scripts/capture_usb_registry.py reports/sigma-zeus-usb-registry-002.json
```

Normal-mode identification does not resolve the missing bootloader/integrity evidence. No speculative command was attempted to obtain it.
