# Sigma 1.1.8 updater and packaging comparison

November 2, 2026, America/Los_Angeles. **The 1.1.8 updater uses the same reviewed update protocol and supports the same resource-replacement packaging strategy as 1.1.5.** Its native executable was rebuilt, so this conclusion is based on a new static import and semantic review, not shifted-address assumptions. Neither executable was executed and this investigation made no device requests.

## Sources

| Release | File | SHA-256 |
| --- | --- | --- |
| 1.1.5 | `originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe` | `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a` |
| 1.1.8 | `work/sigma/1.1.8/package/SIGMA v1.1.8 BETA/SIGMA_Converter_V1.1.8.exe` | `233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a` |

The new EXE is byte-identical to the user-supplied copy inside `originals/SIGMA v1.1.8 BETA/`; the ZIP lineage is `work/sigma/1.1.8/extraction-manifest.json`. Vendor authenticity is not established by the filename or extraction checks.

Both files are native x86 PE32, with no CLR directory, embedded PE signature directory, or overlay. Their 750 resource keys match exactly. **All 749 non-firmware resource payloads are byte-identical.** The only changed resource payload is `TEXTFILE / IDR_APP_FILE / 1033`:

| Release | EXE size | Resource offset / length | Encoded payload SHA-256 |
| --- | ---: | --- | --- |
| 1.1.5 | 3,628,544 | `0x1E7EF8` / 189,056 | `4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282` |
| 1.1.8 | 3,630,592 | `0x1E7EF8` / 191,104 | `880479ed1cc596499f2eeef24cedcfa8a5b3239814c060cdf17d86fc1980fb35` |

The target version is hardcoded in native code: at 1.1.8 VA `0040401D`, file `0x341D`, bytes `6A 08 6A 01 6A 01` push the components used by the version formatter. The decompiled call at `0040402C` is `format(..., "%d.%d.%d", 1, 1, 8)`. This is stronger package-version evidence than relying on filenames alone.

## Rechecked update flow

1.1.8 native VAs in this table map to source file offsets by subtracting `00400C00`, independently checked with the PE section mapping. Full source bytes and instruction lists are saved in the comparison JSON.

| Operation | 1.1.5 VA | 1.1.8 VA / file offset | 1.1.8 supporting bytes / meaning |
| --- | --- | --- | --- |
| GET_FEATURE F1 | `0040204D` | `00401E0D` / `0x120D` | `FF 15 C8 F1 56 00`; helper `00401D80` allocates caps-sized zeroed buffer and sets ID F1 |
| SET_FEATURE | `00402133` | `00401EF3` / `0x12F3` | `FF 15 CC F1 56 00`; helper still ignores API return; the next test is buffer pointer ESI |
| Send report03 update entry | `004042B9` | `00404291` / `0x3691` | `E8 BA DB FF FF` calls SET helper after constructing `55 FF AB AD BA BE` |
| Send F1/02 preparation | `004043DE` | `004043AC` / `0x37AC` | `C6 00 02` at `004043A0`; call `E8 9F DA FF FF` |
| Find embedded firmware | `00404471` | `00404441` / `0x3841` | `FF 15 24 F4 56 00` calls `FindResourceW`, after the preceding SET operations |
| Finalize F1/04 | `004045DF` | `004045AD` / `0x39AD` | `C6 00 04` at `004045A1`; call `E8 9E D8 FF FF` |
| Restart F1/01 | `00404650` | `0040461E` / `0x3A1E` | `C6 00 01` at `00404612`; call `E8 2D D8 FF FF` |
| Display completion | `00404697` | `00404665` / `0x3A65` | `E8 9B A3 01 00`; “Update Complete!” follows without image readback or boot confirmation |

The 1.1.8 top-level routine is `004041B0`. It uses the same fixed embedded-resource lookup and checks a nonzero resource size and pointer at `00404483` / `0040448B`. No external BIN selector or host image-signature/hash validation was found in this reviewed path. The unchanged 1.1.5 preflight limits therefore still apply: entering the update workflow is not a harmless compatibility test. Device-side validation remains a separate unknown.

The F1 version/status interpretation is unchanged: routine `00403E90` calls GET helper `00401D80`, reads u32 at reply offset 8, and chooses the `BL` suffix using the high byte. This does not turn F1 into flash readback or make the previously observed 16-byte boot-mode reply a firmware dump.

## Transfer framing and device selection

Transfer helper `00404BC0` builds `F2 0A n offset_u32le payload`, then pads/sends the device's output-report size. The caller compares remaining bytes with `0x20` at `004044B8` and sends at most 32 payload bytes. The resource size is obtained dynamically; this host path is not hardcoded to the old 189,056-byte carrier.

Supporting writes occur at `00404C47` (`F2`), `00404C53` (`0A`), `00404C63` (count), and `00404C72` through `00404CAC` (four offset bytes). `WriteFile` is called at `00404CC9`, followed by `GetOverlappedResult` at `00404CF3`. These checks establish host transport completion, not device image acceptance. No response carrying a firmware checksum or boot result is parsed by this helper.

Enumeration was refactored/inlined into `00404D70`, but the predicates remain the same. At `00404FDD`–`00405017`, it admits `046D:C260` with UsagePage 1 / Usage 4, or `0EB7:0E07` with UsagePage 1. These match the observed Bootload and normal identities, respectively; this static match is not a Windows execution test. The open mode remains read/write, shared access, existing handle, with CreateFile flags zero in both releases.

## Repackaging implication

The existing technique—append a read-only initialized-data `.zeus` section and redirect only the firmware resource entry—can be reused with **1.1.8 source pins and dynamically computed sizes/addresses**:

- The free 40-byte section-header slot begins at file offset `720` (`0x2D0`), is all zeros and precedes first section data at `0x400`.
- File alignment is 512, section alignment is 4,096.
- The initial added-section RVA for this original is `0x37E000`; aligned raw offset is `3,630,592` (`0x376600`). Do not reuse 1.1.5's `0x37D000` RVA.
- The firmware resource data-entry offset is `1,879,080`; the selected old carrier is 191,104 bytes and has the pinned hash above.
- After replacing the carrier, verify the new resource bytes/length, all other 749 resource payloads, section extents, absence of overlap/overlay, and PE checksum. Keep native updater instructions unchanged.

These are container consistency conditions. A correct PE checksum does not satisfy or establish Sigma firmware integrity/authentication, and an encoded application must be rebased and verified separately.

## Reproduction and bounds

Run `work/tools/python/bin/python scripts/sigma118_updater.py`. It verifies the two source hashes, compares every resource payload, checks section-header capacity and alignment, and exports byte-bound reviewed instruction spans.

- Evidence: `work/sigma/1.1.8/sigma118-updater-comparison.json`, SHA-256 `da23f14f80d653f9419cdee0e48fc3bb15d418883871ddb045255d4be943f9b7`.
- New Ghidra export: `work/sigma/1.1.8/updater-functions.c`, SHA-256 `0428907f3ecbe7dd95a524dab2078731716914df4dbe5b7dbb849f8948bafbaf`.
- Project: `ghidra/sigma-118-updater.gpr`; import log: `work/sigma/1.1.8/updater-ghidra.log`.

Confidence is high for the recorded bytes, resource identity, layout and reviewed update-flow semantics. This is not a claim of whole-program equivalence, a complete bootloader analysis, or verified installation/recovery of a modified image.
