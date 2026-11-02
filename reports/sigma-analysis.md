# Sigma Cortex analysis

Current target, changed at the user's request on November 2: **1.1.8 BETA**. The [1.1.8 analysis](sigma-1.1.8-analysis.md), [USB bindings](sigma-1.1.8-usb-bindings.md), [memory analysis](sigma-1.1.8-memory.md) and [dev3 candidate](firmware-candidate-dev3.md) record the completed rebase and offline verification. No Windows updater was executed or device flashed.

The detailed October 27 analysis below remains the historical **1.1.5 BETA** investigation. Its source hashes and addresses refer only to that version; they must not be applied to 1.1.8.

Subsequent [N32G45x SDK comparison](sigma-n32-code-match.md) strongly identifies Nations firmware lineage. The user's subsequent [board photos](sigma-hardware-photos.md) show N32G455REL7 markings on their own U1. [Current hardware findings](sigma-n32-hardware.md) verify that dev2 fits the reported part's geometry, including the same final flash page as stock; acceptance and recovery remain unresolved.

## Evidence identities and address conventions

| ID | Source | SHA-256 |
| --- | --- | --- |
| S1 | `originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe` | `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a` |
| S2 | `work/sigma/1.1.5/SIGMA_Converter_V1.1.5.payload.bin` | `4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282` |
| S3 | `work/sigma/1.1.5/sigma-decoded.bin` | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` |
| P1 | `originals/SIGMA v1.1.5 BETA/SIGMA v1.1.5 BETA Patch Notes.txt` | `b5c58f64722db6073263552c02fdd9b2b3cac152f6f1195739b73e25b2b965ee` |

All firmware VAs below refer to S3 with **file offset = VA − `0x08020000`**. Updater VAs refer to S1; its application `.text` addresses shown here map to **file offset = VA − `0x00400C00`**. These are different address spaces and processors.

## Packaging and decoding

S1 is a native x86 PE32 GUI executable, image base `0x00400000`, with MFC/C++ code. Its PE signature starts at file `0x110`; the machine field at `0x114` is `4c 01`, optional-header magic at `0x128` is `0b 01`, and CLR directory is zero. The resources include 750 entries. There is no PE overlay. The version resource says `1.0.0.1`, a template application version; the updater code at VA `0x00403EB0` formats the intended firmware version from integers **1, 1, 5**. P1 names DS-8X, analog handbrake and sequential inversion changes. Confidence: high for file/code facts; release-note behavior is separately corroborated in the comparison report.

The firmware carrier is **`TEXTFILE / IDR_APP_FILE / 1033`**, RVA `0x1EE4F8`, original file range **`[0x1E7EF8,0x216178)`**, length **`0x2E280` = 189,056 bytes**. S2 is an identity slice of S1, not decompressed data. The loader at updater VA `0x00404465` invokes `FindResourceW`, `SizeofResource`, `LoadResource`, and `LockResource`, corroborating the resource directory. First 16 carrier bytes: `8e dc 5c af 07 34 04 d1 2e 85 b7 9f 5f 04 a9 05`. Confidence: high.

Initial entropy was 7.99917 bits/byte. **Encryption was established later from code, not inferred from this statistic.** The official SimPro 3.2.3 executable contains AES-256 key expansion, 14-round encryption and CTR increment/XOR routines. Its SFU parser's initialized constants decode S2 into S3. See [simagic-analysis.md](simagic-analysis.md) for source hash, MOV-immediate byte ranges, S-box, key-schedule and CTR implementation evidence.

`scripts/simagic_decode.py` derives the constants from the hash-checked SimPro executable, applies AES-256-CTR with a 128-bit big-endian counter, and checks that reversing the transformation reproduces the entire input range. It removes no padding. Full lineage is in `work/sigma/1.1.5/sigma-decoded.bin.transform.json`. The decoded vector table, valid Thumb startup, explicit VTOR assignment, coherent USB descriptors and embedded firmware version independently support the interpretation. Confidence: high for this transformation and application image; round-trip equality alone is not firmware authentication.

S3's final 16 bytes are `8d3eeb1f032856b6987ca08c0da9db7a`. They equal a preceding block's ciphertext suffix. Their purpose is unresolved; they are retained exactly. No trailer is labelled a checksum, signature, or removable padding without code establishing that meaning.

## PC updater protocol

Sources: S1, `work/sigma/1.1.5/updater-functions.c`, `updater-critical-assembly.txt`, and REA function evidence `ev_d233d8915e8ae1cbd9ec0165f479b6a59a56f7e7268d051838dc7d62720051a4` in `rea-transfer-function.json`.

| Location in S1 | Supporting code / bytes | Interpretation | Confidence |
| --- | --- | --- | --- |
| VA `0x00401D80`, comparisons `0x00401F4A`–`0x00401F87` | `mov eax,0x46d`; `mov edx,0xc260`; alternate `0xeb7`, `0xe07`; HID usage checks | Accepts converter identities `046D:C260` with usage page 1/usage 4, or `0EB7:0E07` with usage page 1 | High; **not a wheel allowlist** |
| VA `0x00401FC0` | First byte `F1`, `HidD_GetFeature`, length from HID caps | Reads status/version; routine `0x00403EB0` reads returned u32 at byte 8 | High |
| VA `0x004041D0` | Feature report ID `03`, payload `55 FF AB AD BA BE 00 00 00` | Requests transition before re-enumeration; bootloader-entry interpretation is strongly supported by sequence | High bytes; medium command name |
| Same routine | Seven sleeps of 150 ms, then up to ten 300 ms discovery attempts; 1000 ms sleep after discovery | Re-enumeration timing; these are PC updater waits, not wheel polling | High |
| Same routine | Feature `F1`, payload first byte `02`; later `04`, then `01` | Prepare / finish / restart candidates surrounding transfer. Exact device-side semantics require bootloader code | High sequence; medium labels |
| VA `0x004044D0`–`0x0040456F` | `resource+offset`, 32-byte increment, call `0x00404C00` | Entire resource sent without a host-side decode, checksum addition or compression step in this path | High, bounded to traced path |
| VA `0x00404C00` | Header `F2 0A n offset_le32`, memcpy to byte 7, `WriteFile`, wait `GetOverlappedResult` | Output report carries resource-relative offset and at most 32 payload bytes; offset is **not** an established flash address | High |

The full transfer size comes from `HidP_GetCaps.OutputReportByteLength`, with zero-filled unused bytes. A full data packet has a 7-byte logical header plus 32 resource bytes. The bootloader's actual report size is not present in the supplied application descriptor and must not be assumed to be 64. `scripts/sigma_payload.py` reconstructs 5,908 logical frames and independently reassembles S2 with the same SHA-256. This script has no USB I/O.

`0x00402090` constructs feature buffers using `FeatureReportByteLength`. It copies the payload starting at byte 1, then zeros from `payload_length`, potentially clearing its last byte; all observed command payload tails are zero. `HidD_SetFeature`'s return value is not checked here. A displayed completion message therefore does not establish device-side integrity verification or successful boot.

## Integrity boundaries

- S1's PE checksum field is zero. REA's certificate inspector reports no `IMAGE_DIRECTORY_ENTRY_SECURITY` table, evidence `ev_210b06652c48d1c3de17446a36e0a1fbe47881e5b0289a938d729a7490166dcd`. This does not rule out external catalog signing.
- The traced updater path neither computes nor verifies a firmware checksum/signature; it transmits S2 unchanged. This is a bounded observation, not proof that the bootloader accepts arbitrary data.
- AES-CTR explains encoding. It is not an authenticity check. The bootloader, its firmware validation rules, permissible image length, and any post-transform checksum/signature remain unavailable.
- Standard reflected CRC32 of S3 excluding its last four bytes does not equal that final word; this one negative check does not rule out other CRC definitions, locations or ranges.
- The initial analysis produced no modified image. The current [dev2 candidate](firmware-candidate-dev2.md) adds observed Zeus control mappings and passes 16 finite emulator checks, including measured-input replay. Bootloader acceptance remains unverified and it is not ready for flashing.

## Processor, memory and entry points

The [architecture evidence report](sigma-architecture-evidence.md) supplies exact bytes and independent instruction decoding. In S3:

| Offset / VA | Evidence | Conclusion |
| --- | --- | --- |
| `0x0` / `0x08020000` | `90 65 00 20` | Initial SP `0x20006590` |
| `0x4` / `0x08020004` | `91 02 02 08` | Reset vector `0x08020291`, Thumb code at `0x08020290` |
| `0x290` / `0x08020290` | `09 48 80 47 09 48 00 47` | Calls initialization then runtime through valid absolute Thumb pointers |
| `0x5264` / `0x08025264` | Constructs VTOR `E000ED08` and writes `08020000` | Independently establishes the application mapping |
| `0x7F8` / `0x080207F8` | CPACR FPU enable, peripheral setup | Cortex-M Thumb-2/FPU build; exact MCU not established |

Ghidra project: `ghidra/sigma-firmware.gpr`; language **`ARM:LE:32:Cortex`**, compiler convention `default`, imported as raw bytes at `0x08020000`. It does not use REA's unsupported generic ARM raw loader. The 64-KiB uninitialized SRAM block in the project is an analysis model covering observed pointers, not a physical-RAM size assertion. The early default VTOR write to `0x08000000` is superseded by the application write above. Bootloader extent is unknown.

## USB recognition and initialization

S3's static constructor chain `0x080250EC` initializes a USB host, a hub class, and four application classes through `0x08025150`, `0x080251B0`, `0x080251E8`, `0x08025220`. Registration routine `0x08023AF0` inserts pointers in a 16-slot table at host-object offset `0x78`. The four application vtables and predicates are:

| State object | Vtable VA | Predicate VA (file offset) | Accepted VID:PID |
| --- | --- | --- | --- |
| `0x200008F4` | `0x080467F8` | `0x08027108` (`0x7108`) | `0483:0522` |
| `0x20000B0C` | `0x080469F4` | `0x0802BA28` (`0xBA28`) | `0483:0530`, `3670:0A04` |
| `0x20000A94` | `0x08046A4C` | `0x0802BB50` (`0xBB50`) | `0483:0525`, `0483:0524` |
| `0x20000BC4` | `0x08046AA4` | `0x0802BCD8` (`0xBCD8`) | `0483:0531` |

Predicates compare their VID/PID arguments directly. Their pointers occupy vtable offset `0x18`; host enumeration calls that slot at `0x080229E4`–`0x080229EE` and `0x08022ABA`–`0x08022AC4`. **None of these VID/PID predicates matches Zeus `3670:0804`.** Enumeration at `0x080228B0` also considers a device-class predicate at vtable `+0x1C` and has a fallback pass that attempts unmatched classes. The four application classes' `+0x1C` methods return zero (`0x08023B90`). Consequently, the missing VID/PID match alone does not prove enumeration stops there; the separately checked input callbacks below establish the lack of Zeus control handling. Sources: `firmware-dispatch.c`, `host-classes.c`, `host-claim.c`; high confidence for these registered application classes. Hub-class handling is separate from wheel input support.

Base initialization `0x0802713C` is restricted again to `0483:0522`. It reads a firmware number into object `+0xAE`; firmware number modulo 1000 in `[150,170]` selects the old parser (`+0x157=0`), other values select the new parser (`+0x157=1`). It then sends several setup requests. Those requests have not all been assigned protocol names; no claim of a complete force-feedback initialization specification is made.

Polling routine `0x08024A8C` reads the discovered interrupt endpoint into a 64-byte stack buffer, caps callback length at 64, and invokes virtual report callback offset `0x40`. Its next deadline is the current counter plus the byte in object `+0x38`. That interval is mutable: base callback `0x08027280` explicitly sets it to 6, so the endpoint's advertised interval does not by itself establish effective polling frequency. There is no need to impose a new fixed 64-byte **logical** input format on Zeus merely because the endpoint maximum packet size is 64.

## Input parsing and console output

Sources: S3, `firmware-device-paths.c`, `firmware-dispatch.c`, `host-enumeration.c`. Confidence is high for the dataflow below; physical control names are limited by lack of captures.

- Base callback **`0x08027280`** admits `0483:0522` only. It selects `0x08027810` or `0x080272E0` from the flag above.
- **`0x08027810`** accepts exactly **32 bytes**, copies them to base-object `+0xE1`, and latches status from object `+0xF7` when packet subtype at `+0xF6` is 7.
- **`0x080272E0`** accepts exactly **39 bytes**. It reads steering u16 at packet `+1`, a packed 64-bit button region starting in the high nibble at `+0xC`, two 12-bit values across `+9..+0xB`, and status u16 at `+0x1C`.
- Both branch on **status low six bits**, cases **0 through 6**, to wheel-specific mapping functions. A direct Zeus USB report is not this base report. USB PID `0804` is not interchangeable with the six-bit base wheel type.
- The mappings write shared state around `0x20004500` and console controls at `0x20004578`/`0x20004580`/`0x20004582`. Steering lives at `0x20004508`; pedal state is independently replaced when separate pedal reports are fresh.
- Separate pedal callback **`0x0802BC20`** accepts 3–64 bytes for its two PIDs, copies into `0x20000EDC`, and timestamps receipt. Main **`0x0802525C`** clears this external pedal state after a counter delta greater than `0x4B0`. Counter-to-millisecond interpretation is consistent with the timer path but no hardware timing was measured.
- Handbrake callback `0x0802BAD8` and shifter callback `0x0802BD44` similarly require their own IDs, non-null buffer and lengths 3–64. Simply replacing one accepted PID would route Zeus data into the wrong parser and sacrifice an existing peripheral.
- Console builder **`0x0802A8B4`** assembles the 64-byte report at **`0x20000C88`**: report ID 1; hat/button state at offsets 5–7; steering at `+0x2B/+0x2C`; pedal fields at `+0x2D..+0x32`; shifter at `+0x33`; inverted 8-bit handbrake at `+0x34/+0x35`. It also records rising edges for four mapped controls. This is the candidate merge point for a separate Zeus input state.

The console-facing descriptor at S3 offset `0x26888` advertises **`0EB7:0E07`**, and string descriptors identify `FANATEC WHEEL(PS5 / PS4 MODE)`. This must not be confused with upstream Simagic device recognition. Existing console-side handling need not change merely to add a wheel input source.

The base parsers refresh shared control state on every accepted base report. A Zeus callback writing those globals directly can be overwritten by the next base update; a separate wheel state merged at report assembly avoids this ordering issue. This is a code-supported design requirement, not a tested patch.

## Release comparison and reproducibility

[sigma-release-comparison.md](sigma-release-comparison.md) compares the separately sourced 1.0.20 release against 1.1.5. The four USB predicates and base-report lengths/type cases are semantically unchanged. Analog handbrake output and shifter inversion/mode handling changed, consistent with P1. Address movement alone was not treated as a functional change.

```sh
source scripts/env.sh
work/tools/python/bin/python scripts/inspect_pe.py \
  'originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe' \
  work/sigma/1.1.5/resources
work/tools/python/bin/python scripts/sigma_payload.py
work/tools/python/bin/python scripts/simagic_decode.py \
  work/sigma/1.1.5/SIGMA_Converter_V1.1.5.payload.bin \
  work/sigma/1.1.5/sigma-decoded.bin
work/tools/python/bin/python scripts/sigma_architecture.py \
  work/sigma/1.1.5/sigma-decoded.bin
```

REA was used for PE resources, certificate-table inspection and native updater function evidence. Direct Ghidra handled the unsupported Cortex-M lane. Existing expanded projects retain the imported programs and analysis; import/export logs and Java scripts remain in the project. See [compatibility-gap.md](compatibility-gap.md) for the proposed change, exact remaining captures and validation limits.
