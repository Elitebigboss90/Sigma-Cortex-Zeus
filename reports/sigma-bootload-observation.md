# Sigma manual Bootload observation

November 2, 2026, America/Los_Angeles. **The user's OK-button power-on sequence reached Bootload mode, the Mac read a status response through the KVM, and a subsequent power cycle without OK returned to the normal application interface.** No firmware installation or physical flash dump occurred.

This establishes a working manual update-mode entry on the currently functioning unit. It materially narrows the recovery uncertainty. It does not prove the location of the OK check, successful stock restoration after a failed update, or acceptance of dev2.

## Observed sequence and identities

1. The user reported “Bootload mode” after the requested OK-button cold-start sequence. Direct connection to the Mac did not appear to work; the user used the KVM. No cause was established for the direct-connection failure.
2. Mac USB and HID registry observations identified a new Sigma-mode device. Its identity differs from the earlier normal-mode capture.
3. A constrained native helper issued exactly one F1 GET_FEATURE and received a successful 16-byte reply. It issued no SET_REPORT or output report.
4. The user disconnected and reconnected Sigma through the same KVM without holding buttons, then reported the normal screen.
5. Fresh USB/HID observations showed the normal identity and original normal report descriptor at the same USB location ID, `1126400`.

| Property | Bootload observation | Normal after power cycle |
| --- | --- | --- |
| USB VID:PID | `046D:C260` | `0EB7:0E07` |
| Product text | `G29 Driving Force Racing Wheel` | `FANATEC WHEEL(PS5 / PS4 MODE)` |
| bcdDevice | `0400` | `0625` |
| HID descriptor size | 77 bytes | 160 bytes |
| HID descriptor SHA-256 | `8783c2c016de8d3c57d6e18bc21c2df0d6fa47b60da827dfa02e2658a2e3fc0e` | `9c099ea4b1d5400969a3363d781f1b354efd25e2d382b81b56cf31c81b01cdee` |
| Maximum input / output / feature report sizes from registry | 8 / 65 / 33 | 64 / 32 / 64 |

The Logitech/Fanatec labels are USB identities exposed by Sigma, not identification of different physical wheel hardware. Correlation uses the user-operated transition, unique matching devices, and the unchanged USB location. Confidence: high for the recorded identity transition. A matching normal descriptor does not independently identify the installed firmware version or hash the device's flash.

## Boot-mode HID reports

The observed descriptor declares:

| Descriptor offsets | Report | Payload extent |
| --- | --- | --- |
| `0x1C`, `0x2F` | Input ID `01` | Two 8-bit axes plus 40 one-bit buttons: 7 payload bytes |
| `0x3F` | Output ID `F2` | 64 payload bytes |
| `0x49` | Feature ID `F1` | 32 payload bytes |

Including report IDs gives the registry maxima of 8, 65 and 33 bytes. The full 77-byte descriptor does not occur verbatim in the decoded stock 1.1.5 application. This supports a separate mode implementation; it is not proof that the OK-button check executes before all application code.

The updater's existing F2 output transfer writes payloads. An output report declaration does not imply a corresponding upload/read command. The F1 feature declaration alone does not specify all command semantics or establish arbitrary flash readback.

## The single status read

The read is justified by original updater `SIGMA_Converter_V1.1.5.exe`, SHA-256 `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a`: function `00401FC0` zeroes a FeatureReportByteLength-sized buffer, puts `F1` in its first byte, and calls `HidD_GetFeature` at `0040204D`. Version display function `00403EB0` reads the u32 at buffer byte 8. The helper reproduces only this GET operation using the macOS IOHID API; it does not run the Windows updater or its preceding/following SET operations.

Helper admission requires one device with `046D:C260`, USB transport, bcdDevice `0400`, maximum feature size 33, and byte-for-byte equality with the observed 77-byte descriptor. It opens non-exclusively and calls `IOHIDDeviceGetReport` once with feature type, report ID `F1`, and capacity 33.

Observed return: `kIOReturnSuccess`, 16 bytes:

```text
34 12 00 00 01 00 00 00 01 00 01 00 00 00 00 00
```

Little-endian u32 values at response offsets 0, 4, 8, 12 are `00001234`, `00000001`, `00010001`, `00000000`. No leading `F1` byte was returned. Applying the stock updater's version arithmetic to byte 8 yields `1.0.1`, with no high-byte `BL` flag. We retain that as a possible interpretation only: platform framing and complete field semantics remain unverified. The user's screen and changed interface independently establish the observed Bootload state.

**These are 16 status bytes, not a firmware dump.** The known request carries no flash address. No undocumented opcodes, oversized transfers or fuzzing were attempted. No supported method to read `[08000000,08020000)` or the complete device flash has been established.

## Provenance and reproduction

Files below are under `work/sigma/recovery-audit-2026-11-02/`:

| File | SHA-256 |
| --- | --- |
| `bootload-hid-001.json` | `74b62b8a1c2a8eefecffccad68e54b64e004f9fa8957c1ea8e535735bd59a838` |
| `bootload-usb-001.json` | `98891519b32395e37bb4a033eec16d0204cbbb7685e0ca9e8d0aa6b3b57fe7b9` |
| `bootload-status-001.json` | `95766cf412d420c58b647feb7fda2dcfc32b17cee1940707ed40f615bff97a0f` |
| `normal-after-bootload-hid-001.json` | `889d5e0a370d5ec43852733ed283684b010ba0397ef9395f54e88dda2b3093f7` |
| `normal-after-bootload-usb-001.json` | `562e131b1fa02112bfca2332319cb4c1fcd5428bd904bbf5eb5d2875f5025dce` |

Native helper source: `scripts/read_sigma_boot_status.c`, SHA-256 `36ede8ad07ffab74d00707d0e1647f2845f9e20ddfc5d63df0cf6ecc20e8191f`. Compiled helper: `work/tools/read_sigma_boot_status`, SHA-256 `fa07eea55aedac3c3744d8772423e66b1bb3cbe528bf39467ea2bde3534d8c8c`. Built with Apple clang 21.0.0, native arm64, `-Wall -Wextra -Werror`, IOKit and CoreFoundation. The local SDK's `IOHIDDevice.h` documents the GET operation and in/out report length.

`scripts/analyze_sigma_boot_observation.py` pins all five observation hashes, verifies both descriptors and the common USB location, parses the descriptor's short items, and records the response and limitations in `bootload-observation.json`. It is offline and can be rerun without a device:

```sh
python3 scripts/analyze_sigma_boot_observation.py
```

The previous [static recovery audit](sigma-recovery-audit.md) remains useful: application fault handlers loop, whereas this observed manual entry is selected at power-on. The exact bootloader implementation is still missing. No automatic rollback or recovery from deliberately corrupted firmware was tested. The dev2 files remain unchanged and have not been installed.
