# Sigma 1.1.8 BETA analysis and Zeus rebase

November 2, 2026, America/Los_Angeles. The user explicitly changed the target from 1.1.5 to the supplied **1.1.8 BETA** package. The current candidate is **zeus-dev3**. The former 1.1.5 dev2 artifacts and sources remain preserved.

## Inputs and packaging

The ZIP is `originals/SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA.zip`, 2,035,961 bytes, SHA-256 `bd176e95346349fa9352a05ba536e4f4447e61c24e26b4b54dfe2266cb98a9d4`. Both members pass ZIP CRC checks and are byte-identical to the already unpacked copies supplied alongside it. Source compressed byte ranges, hashes, DEFLATE operation and output hashes are in `work/sigma/1.1.8/extraction-manifest.json`, reproduced by `scripts/inventory_sigma118.py`.

The supplied updater `SIGMA v1.1.8 BETA/SIGMA_Converter_V1.1.8.exe` is 3,630,592 bytes, SHA-256 `233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a`. It is a native x86 PE32, with no CLR directory, embedded Authenticode table, or overlay. This is a user-supplied package; no vendor-signature authenticity claim is made.

The 94-byte patch note, SHA-256 `5667ad6d86a34836d587c02e8f6ee4e18e81befd5e5f1a8202b0d26c4497bc30`, says “Add Support for NeoX Hub.” The updater's displayed target version is independently hardcoded as 1.1.8. See [updater comparison](sigma-1.1.8-updater.md).

Firmware resource `TEXTFILE/IDR_APP_FILE/1033` starts at EXE file `0x1E7EF8`, length 191,104; SHA-256 `880479ed1cc596499f2eeef24cedcfa8a5b3239814c060cdf17d86fc1980fb35`. The evidence-derived AES-256-CTR transform decodes and round-trips it exactly. Decoded application `work/sigma/1.1.8/sigma-decoded.bin` has SHA-256 **`6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035`**. Its `.transform.json` records the full lineage and key/IV instruction sources.

All firmware addresses below refer to that decoded hash; file offset = VA − `08020000`. Ghidra project: `ghidra/sigma-118-firmware.gpr`, Cortex/Thumb, little-endian. All analysis is static or offline emulation; no Windows updater or firmware was executed on hardware.

## Why old patch addresses cannot be reused

The image is 2,048 bytes larger, but code and RAM objects were substantially reordered. Reset changes from `08020291` to `080202B1`; initial SP changes from `20006590` to `20006650`. The [memory analysis](sigma-1.1.8-memory.md) independently establishes startup, scatter loading, N32 lineage, heap and stack bounds. The recovered initialized RAM is checked against execution of the actual new Thumb decompressor.

| Role | 1.1.5 binding | 1.1.8 binding / evidence |
| --- | --- | --- |
| Last constructor hook | `08025102`, BL | `0802473E`, tail B.W `07 F0 D7 BE`; caller LR is restored before it |
| Original constructor chain | `080250EC` | `08024720`; six registered classes, independently emulated |
| Last constructor target | `08025149` Thumb | `0802C4F1` Thumb |
| Generic constructor | `08025189` Thumb | `0802910D` Thumb |
| USB host object | `20000820` | `20004488` |
| Generic vtable | old method bindings | `080471B0`; 20 words, same callback/object layout |
| Console builder | `0802A8B4` | `080460C0`, file `0x260C0` |
| Console merge hook | `0802537C` | `08043B80`, BL bytes `02 F0 9E FA` |
| Console output / prior output | `20000C88` / `20000CC8` | `20004608` / `200045C8` |
| Report-dirty flag | `20000000` | `20000040` |
| SysTick counter | `2000081C` | `20002104` |
| Heap-limit literal | file `0x2C8` | file `0x2E8`, `50 56 00 20` |
| Added state reservation | `20005490..20005590` | `20005550..20005650` |

The [USB binding report](sigma-1.1.8-usb-bindings.md) records exact code/bytes for the constructors, vtable methods, enumeration and raw-report callback. The six original class objects occupy the first six registry slots; the new driver is seventh. All five original non-hub predicates reject Zeus `3670:0804` in offline execution. The extra original class's precise product role is not assumed from its location or count.

## Console merge and timing evidence

`work/sigma/1.1.8/main-console.c` and `console-builder.c` were exported read-only from Ghidra. Main `08043A60` sets VTOR to `08020000`. At `08043B62..08043B7C`, it checks mode `200008E4 == 5` and dirty byte `20000040`, then calls the builder at `08043B80` before comparing/sending/copying the output.

Builder `080460C0` writes report ID 1 to `20004608`, copies button/hat sources to output bytes 5–7, clears bytes 8–42, then writes steering at bytes `0x2B..0x2C`, three pedal axes at `0x2D..0x32`, gear at `0x33` and handbrake at `0x34..0x35`. This retains the report layout used by the existing Zeus adapter. The rebased merge calls this original builder before combining wheel controls; it does not redirect steering/pedal fields.

SysTick handler `08023A08`, reached by vector file `0x3C`, increments RAM `20002104`. Setup `080451C4` selects reload `0x23280` or `8000` depending on the HSE-failure flag at `20000848`, matching the prior timing policy. The adapter retains a 250-tick release timeout. Physical scheduling/timing remains unmeasured.

## Preserving new support

The 1.1.8 base parsers at `08024C38` and `08025114` still handle 32/39-byte base reports, and add dispatch case `0x0B` to `0802754C`. Calls at `08024EC8` (`02 F0 40 FB`) and `0802541C` (`02 F0 96 F8`) support this semantic change. The relationship to NeoX is consistent with the patch note; no NeoX hardware capture identifies the subtype independently.

Dev3 preserves those routines and every other original byte except the declared heap-limit, final-constructor branch and report-builder call edits. It therefore retains the new parser implementation and original class registration. Actual NeoX or other-device behavior on PS5 has not been tested.

## Candidate and remaining work

[Dev3 build and verification](firmware-candidate-dev3.md) records the modified 1.1.8 application and repackaged 1.1.8 updater. Sixteen emulator checks, including 99 real Zeus frames, pass. Independent review checked the new tail-branch LR handling, unchanged vtable entries, RAM bindings and page bounds.

[Manual Bootload entry and normal return](sigma-bootload-observation.md) are observed on the user's unit, through the KVM. This rebase performed no device I/O. Bootloader image acceptance/integrity rules, full flash readback, failed-image restoration, and actual Sigma/Zeus/PS5 operation remain unverified. The rebased image is an experimental candidate, not a confirmed functioning release.
