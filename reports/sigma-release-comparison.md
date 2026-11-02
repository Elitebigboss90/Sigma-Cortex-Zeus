# Sigma 1.0.20 → 1.1.5 comparison

Sigma 1.1.5 remains the requested target. This comparison establishes changes in input and output handling, rather than interpreting shifted offsets as features. It does not validate a flashable patch.

## Sources and reproducibility

The older package was downloaded from the [EG Sim Rigs product page](https://www.egsimrigs.co.za/products/sigma-cortex-converter), whose firmware link resolves to [SIGMA_Converter_V1.0.20.exe](https://cdn.shopify.com/s/files/1/0733/4782/5941/files/SIGMA_Converter_V1.0.20.exe?v=1704246254). This is retailer provenance; manufacturer authenticity was not independently established. The supplied 1.1.5 package has no verified external provenance in this project.

| Artifact | Size | SHA-256 |
|---|---:|---|
| `originals/SIGMA v1.0.20/SIGMA_Converter_V1.0.20.exe` | 3,656,192 | `4e251340b80d4227049ef94bfff3ab520cc7c5053cb4b2bd778be870059c3f23` |
| 1.0.20 `TEXTFILE/IDR_APP_FILE/1033` | 216,800 | `42be51e42e118ddee75ae16c288a153ef075bf85757edd6237c6920e55ba95b2` |
| `work/sigma/1.0.20/sigma-decoded.bin` | 216,800 | `3fc925cb7d12f3179a27248b2d86868d0556d7f36be33092b39bcced254c9e20` |
| `originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe` | 3,628,544 | `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a` |
| 1.1.5 `TEXTFILE/IDR_APP_FILE/1033` | 189,056 | `4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282` |
| `work/sigma/1.1.5/sigma-decoded.bin` | 189,056 | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` |

Both resources start at EXE file offset `0x1e7ef8`, resource RVA `0x1ee4f8`. They differ in content and length. The coincidence of resource offsets is not a semantic match. REA's old-package resource inspection is retained in `work/sigma/1.0.20/rea-resources.json`, Evidence ID `ev_cd1a9be496a272eaf37c858093499a8df1be0907825e2beafd01ef434cf51923`.

Run from the project root:

```sh
work/tools/python/bin/python scripts/inspect_pe.py \
  'originals/SIGMA v1.0.20/SIGMA_Converter_V1.0.20.exe' work/sigma/1.0.20/resources
work/tools/python/bin/python scripts/simagic_decode.py \
  work/sigma/1.0.20/resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin \
  work/sigma/1.0.20/sigma-decoded.bin
work/tools/python/bin/python scripts/sigma_compare.py
```

The decode transformation manifest is `work/sigma/1.0.20/sigma-decoded.bin.transform.json`. The script derives AES-256-CTR parameters from the independently inspected SimPro executable; see `simagic-analysis.md`. Encrypting the decoded bytes again reproduces the source resource exactly. This verifies a reversible transformation, not firmware authenticity or device acceptance. `work/sigma/release-comparison.json` records mapping, matched function addresses, file offsets, and supporting first-32-byte spans. Both originals remain unchanged.

## Processor and mapping evidence

High confidence: both decoded blobs contain coherent little-endian Cortex-M vector tables at file offset zero, with reset vector `0x08020291`, hence Thumb code entry `0x08020290`. The older initial stack pointer is `0x20006b68`; 1.1.5 uses `0x20006590`. Both contain the default-handler vector `0x080202ab`, reserved zero vectors at offsets `0x1c..0x2b`, and valid Thumb reset instructions at offset `0x290`. Mapping file offset zero to `0x08020000` makes these relationships consistent. This does not establish the exact MCU part or total physical memory.

The old project `ghidra/sigma-1020-firmware.gpr` uses `ARM:LE:32:Cortex`, Thumb context, and valid vector seeds. Its 128-KiB `RAM_hypothesis` block is an analyst convenience, not a measured hardware size. Relevant decompilation is in `work/sigma/1.0.20/recognition-functions.c` and `shifter-outputs.c`. The target's corresponding exports are `firmware-device-paths.c` and `firmware-dispatch.c` under `work/sigma/1.1.5/`.

## Recognition and wheel dispatch

High confidence, bounded to these matched predicates: the following accepted USB identities are unchanged between the two releases. Each address denotes the decoded file above; decoded file offset is VA minus `0x08020000`.

| Matched role | Accepted condition | 1.0.20 VA | 1.1.5 VA |
|---|---|---|---|
| Base | VID `0483`, PID `0522` | `08028e28` | `08027108` |
| Pedals | VID `0483`, PID `0524` or `0525` | `08025900` | `0802bb50` |
| Handbrake | `0483:0530` or `3670:0a04` | `0802aa1c` | `0802ba28` |
| Shifter | `0483:0531` | `0802a2fc` | `0802bcd8` |

For example, the handbrake predicate decompiles to `(vid == 0x483 && pid == 0x530) || (vid == 0x3670 && pid == 0xa04)` in both releases. `0a04` is distinct from the Zeus Formula module's `0804`. Broadening this handbrake predicate would route a wheel into the wrong parser.

The matched base callbacks (`08025aac` → `08027280`) still select two parsers from object byte `+0x157` bit zero. The legacy parsers (`08025b98` → `08027810`) require exactly 32 bytes; the newer-protocol parsers (`08026028` → `080272e0`) require exactly 39 bytes. The 39-byte path takes a status word at report `+0x1c`, gates wheel presence using `(status >> 6) & 3`, and dispatches `(status & 0x3f)` through cases 0–6 in both releases. The legacy path likewise dispatches those cases after latching its status word from the appropriate multiplexed report. No Zeus-specific case was established in these functions.

These are semantic matches by accepted values, length checks, and field use. Functions and RAM state moved substantially; no constant offset delta is used to infer equivalence.

## Handbrake and shifter changes

High confidence: handbrake treatment changed from thresholded button mapping to explicit analog output fields.

* In 1.0.20, parser `08026028` obtains a 12-bit handbrake value as `(report[7] >> 4) | (report[8] << 4)` and stores it in 16-bit state `20004a98`. Wheel mapping functions, for example `0802863c`, compare this against `0x47f` and set button bit `0x40` when above the threshold. The console report builder is `0804b70c`.
* In 1.1.5, parser `080272e0` stores `report[8]` in byte state `20004520`; the separate USB handbrake path shifts its raw value right by four. Builder `0802a8b4` writes `255 - handbrake` to `20000cbc` and `20000cbd`, offsets `0x34` and `0x35` from its report buffer at `20000c88`. The exact host-visible semantic assignment of both output slots requires the corresponding descriptor/protocol interpretation.

High confidence: sequential-shifter direction is now configurable in the matched console report builder. In 1.0.20 `0804b70c`, the two sequential inputs unconditionally OR bits 0 and 1 respectively into the second button byte. In 1.1.5 `0802a8b4`, a profile setting at `20000d86 + profile * 0x12` chooses the order of those two bits. This is concrete support for the supplied patch note's inversion option.

High confidence: 1.1.5's base parsers maintain a separate mode state `20004534`, set from shifter input mode, and explicitly clear sequential-button state in external H-pattern mode. The newer 39-byte parser's H-pattern state comes from report bytes `0x12/0x13`, with validity at `0x1b`; the older 39-byte parser already has related gear decoding but no corresponding explicit mode variable in that matched routine. In 1.1.5 USB feature handler `0802af3c`, the branch for feature report `0x31` selects `20000096 = 0x40`/`0x41` and `2000009a = 1`/`2` based on `20004534`. This links the new mode state to the console-side feature response. Naming every encoded bit and proving the complete DS-8X interaction remains outside this comparison.

The observed changes support the 1.1.5 handbrake/inversion feature notes. They do not show a new USB wheel class, a widened base wheel-ID dispatch, or Zeus support.

## Packaging observations and limits

The resources initially looked opaque (entropy near 8 bits/byte), but the independently recovered AES-CTR transform establishes encoding here. Similar ciphertext at corresponding positions across versions was explained by reuse of the same counter stream. The earlier narrowly tested LCG/xorshift hypotheses in `prng-hypotheses.json` are superseded and should not be treated as the decoding method.

In 1.1.5, decoded final 16 bytes exactly equal the preceding ciphertext block's final 16 bytes; 1.0.20 does not have this suffix relation for any length 1–32. A reused partial-block buffer during packaging could explain this, but that mechanism and the unpadded image length are not proven. Do not trim the resource or classify this suffix as a checksum or signature from this observation.

No device was flashed or queried. Runtime report routing, physical memory size, bootloader integrity policy, exact timing, and actual Zeus/MagLink USB descriptors remain hardware or capture questions. The offline evidence is sufficient to identify concrete parser and routing differences; it is not sufficient to certify a binary patch.
