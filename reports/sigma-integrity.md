# Sigma payload integrity and boot transition

Analysis date: 2026-10-27, America/Los_Angeles. This investigation supports an **offline experimental candidate**, not a device-accepted image. No original or device was modified.

## Source identities

| ID | Source | SHA-256 |
| --- | --- | --- |
| N | `work/sigma/1.1.5/sigma-decoded.bin` | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` |
| C | `work/sigma/1.1.5/SIGMA_Converter_V1.1.5.payload.bin` | `4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282` |
| O | `work/sigma/1.0.20/sigma-decoded.bin` | `3fc925cb7d12f3179a27248b2d86868d0556d7f36be33092b39bcced254c9e20` |

File offsets in N and O map to VA `0x08020000 + offset`. Their original package lineage, AES-256-CTR constants and byte-exact round trips are recorded in [package-inventory.md](package-inventory.md), [sigma-analysis.md](sigma-analysis.md), and the transformation sidecars. The resource named above and `resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin` are byte-identical.

## Established scatter-loading boundary

The original startup is more informative than trailing entropy. N VA `080201A0` loads two relative table offsets from file `0x1CC`: `24 DE 02 00 44 DE 02 00`. Adding the literal's own offset yields table `[0x2DFF0,0x2E010)`. Its entries are:

| Table offset | Source VA | Destination VA | Output bytes | Handler |
| --- | --- | --- | ---: | --- |
| `0x2DFF0` | `0804E018` | `20000000` | `0x7B0` | `080201D4`, compressed initialized data |
| `0x2E000` | `0804E270` | `200007B0` | `0x5DE0` | `08020230`, zero-fill |

N file `[0x1D4,0x22E)` contains the actual decompressor. Each control byte selects a literal count (low three bits, extended if zero), a run count (high four bits, extended if zero), and zero-run versus backward-copy behavior (bit 3). This was transcribed directly in `scripts/integrity_scatter.py`. It consumes **exactly `[0x2E018,0x2E26A)`**, 594 compressed bytes, and yields 1,968 initialized RAM bytes at `20000000`.

Recovered RAM image: `work/sigma/integrity/sigma-1.1.5-initialized-ram.bin`, SHA-256 `d095aaa41ab6511a2d7cb5200ee7845195493ed0cd43f883c47c0879a946c58d`. Its source-range hash is `ee99a6bc562abcfa47cd9443b6944ee4c1c0ea897c4879af47689e6353478e64`. Exact table bytes, decompressor bytes, operation, range and output hash are in `work/sigma/integrity/scatter-evidence.json`.

Six zero bytes follow the consumed stream through `0x2E270`. The zero-fill entry's source points to `0804E270`, although that handler does not read the source. The zero-filled RAM extent ends at `20006590`, equal to the initial stack pointer. This does not make memory above that address available; runtime allocation and physical RAM capacity require separate evidence.

The older O startup uses the same handlers. Its compressed stream `[0x34748,0x34EDA)` expands to `0xCE0` bytes at `20000000`, followed by six zeros. Its zero-fill source is `08054EE0`, exactly the end of the 216,800-byte carrier. Its zero-fill range is `20000CE0 + 0x5E88`, ending at its initial SP `20006B68`. The reconstructed old RAM SHA-256 is `c640be78e19f48694b5755741d29d0c7e2b25b0661c5de91eef7f2afee223412`.

Confidence: high for the recorded tables, routine semantics and reconstructed ranges; the Python transcription is an offline model, not an observation of device startup. An independent instruction-emulator comparison is useful before relying on reconstructed RAM for a patch.

## Final 16 bytes: stronger bounded interpretation

N file `[0x2E270,0x2E280)` is `8D 3E EB 1F 03 28 56 B6 98 7C A0 8C 0D A9 DB 7A`. It lies after the nominal endpoint indicated above and is not consumed by the scatter decompressor. It equals **C file `[0x2E250,0x2E260)`**, the final 16 bytes of the preceding 32-byte encrypted transfer block.

The combined observations strongly support packaging residue: a final 16-byte read into a reused 32-byte buffer would retain the prior block's ciphertext suffix before the next in-place CTR operation. Decrypting that final block recovers precisely that stale suffix. This is a hypothesis about the packer because the original packing code has not been obtained. It is stronger than calling random-looking bytes an integrity tag, but does not establish what the bootloader includes in its checks.

Do not strip or repurpose the bytes based on this inference. Preserve them at their original offsets in an offline candidate. Neither release establishes a firmware checksum/signature trailer in its resource.

## CRC32 present in the application, but for a RAM report

N contains a 1,024-byte CRC32 table at file `[0x2D928,0x2DD28)`, VA `0804D928`. All 256 entries match reflected polynomial `EDB88320`; table SHA-256 is `12f3e0576d447eb37b36d82ba0c1c5481b8f0d12fdc70347ce4a076b229d4c86`.

Routine **`0804505C`**, file `0x2505C`, sets its input pointer to fixed RAM **`20000D20`**, initializes the accumulator to `FFFFFFFF`, uses the table for each byte, and returns its complement. Its directly observed calls are:

| Call VA | Length passed | Result destination |
| --- | ---: | --- |
| `080447EC` | 12 | RAM `20000D2C` onward |
| `080448FE` | 60 | RAM `20000D5C` onward |

At `08045094`, bytes `4D F6 28 12 C0 F6 04 02` construct the table address. The fixed RAM pointer is constructed at `0804505E` and advanced by four at `08045066`. This bounds the meaning: **this CRC routine is report integrity, not an observed checksum over the firmware image**. It does not resolve bootloader authentication. Exact instruction exports are in `work/sigma/integrity/integrity-evidence.json`.

## Update transition touches flash outside the application

N **`0802AE8C`**, file `0xAE8C`, checks received report bytes `03 55 FF AB AD BA BE` in RAM `20000D20..20000D26`. It calls `0802BA20`, which calls **`0802B930`**, then `0802B9F4` to reset.

`0802B930` constructs address **`08018000`** at `0802B934` using bytes `48 F2 00 00 C0 F6 01 00`, sets length `0x800`, unlocks the flash helper, and invokes page-erase helper `08021378`. This is a single 2-KiB page below the application mapping. The reset routine **`0802B9F8`** writes AIRCR at `E000ED0C`, combining the `05FA` key with `SYSRESETREQ`, then loops.

This corroborates the PC updater's boot-entry command from [sigma-analysis.md](sigma-analysis.md). **Interpretation:** erasing `08018000` changes boot-state or validation metadata so the following reset enters update handling. The fact of the erase/reset is high confidence; the page's complete format, and whether it carries an image length/checksum/signature, are unknown. Settings storage is separately referenced at `08019000` by `0802B4B0/0802B4E0`, so these addresses must not be conflated.

The first `0x20000` bytes of the device flash are absent from N. A permissible read-only dump of `[08000000,08020000)`, with particular attention to `[08018000,08018800)`, would directly address the missing bootloader/metadata evidence. This is a requested evidence range, not a claim that a safe read method exists on the exact chip. No readout-protection change or hardware operation was attempted.

## Bounded bootloader search

- A four-word vector-pattern scan of N finds only the application vector table at offset 0. The predicate requires an aligned plausible SRAM SP, a Thumb flash reset pointer, and two plausible handler words. This is not proof that no embedded boot code exists in another representation.
- All **2,847** extracted SimPro member filenames were checked for `sigma`, `cortex`, or `bootloader`; none match. The product SFUs include applications for the listed Simagic devices. Filename absence does not exclude unidentified nested/encoded content.
- A bounded web search for the exact Sigma Cortex/bootloader terms did not yield a verifiable vendor bootloader artifact. The [vendor site](https://sigmasimracing.com/) timed out when opened, and its `/downloads/` path was inaccessible through the browsing tool. No public bootloader-availability claim follows from those failures. No unrelated brand's Sigma firmware was used.

## Candidate construction implications

An **offline, explicitly not-for-flashing candidate** can be built reproducibly now. AES-CTR permits a chosen plaintext patch and deterministic re-encoding. At a fixed offset, unchanged plaintext produces unchanged ciphertext with the same key/counter, making a bounded diff check possible.

For an appended implementation, keep the complete original `0x2E280` bytes in place except declared hook edits and begin appended code at or after offset `0x2E280`, VA `0804E280`. Preserve the opaque 16 bytes at their original location. This avoids assuming they are free code space or relocating the original scatter stream. It **does not** establish that an extended image passes device validation. The older resource is larger, but that size precedent is not a physical-flash or bootloader-capacity guarantee for the user's hardware.

Specific unresolved acceptance conditions are:

1. Whether bootloader metadata at `08018000` or another region stores expected length or integrity values, and how F1 preparation/finalization updates it.
2. Whether it validates any last-block/trailer convention, so preserving the original tail internally rather than at the new end changes validity.
3. Whether its decrypt/write loop accepts the extended resource length and destination range, including erase-page limits and interrupted-update behavior.
4. Whether validation covers all encoded bytes, decoded bytes, an embedded subrange, or an independent expected value.

For a same-length candidate these length-related uncertainties narrow, but integrity and runtime correctness still remain. No reviewed host-side function computes the missing device acceptance value. Do not fabricate one or present CTR reversibility as successful firmware validation.

## Reproduce the added evidence

```sh
work/tools/python/bin/python scripts/integrity_scatter.py
work/tools/python/bin/python scripts/integrity_evidence.py
```

Both scripts pin the decoded input SHA-256 and write only under `work/sigma/integrity/`. The scatter script refuses a differing existing RAM output. No device I/O is present.
