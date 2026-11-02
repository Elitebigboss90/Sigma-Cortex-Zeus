# Sigma 1.1.8 memory and startup evidence

Analysis date: November 2, 2026, America/Los_Angeles. Static byte inspection and finite instruction emulation only; no hardware or USB I/O.

**The 1.1.8 application retains a mapping at `08020000`, but its startup layout and RAM allocation differ from 1.1.5.** Its initialized RAM fixture has been independently reproduced by the actual Thumb decompressor. A 256-byte state reservation can be made at `[20005550,20005650)` by reducing the declared heap limit; the existing stack bounds remain unchanged.

## Sources and mapping

| Source | Size | SHA-256 |
| --- | ---: | --- |
| `work/sigma/1.1.8/sigma-decoded.bin` | 191,104 | `6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035` |
| `work/sigma/1.1.8/resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin` | 191,104 | `880479ed1cc596499f2eeef24cedcfa8a5b3239814c060cdf17d86fc1980fb35` |
| Earlier decoded 1.1.5 | 189,056 | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` |

The new carrier's extraction and AES-CTR lineage are recorded by `work/sigma/1.1.8/extraction-manifest.json`, the resource inventory, and `sigma-decoded.bin.transform.json`. Cipher round-trip consistency alone is not evidence of integrity validation.

At file offset zero, bytes `50 66 00 20 B1 02 02 08` give little-endian initial SP `20006650` and Thumb reset vector `080202B1`. At file `0x2B0`, the reset code loads two literal function pointers and branches through them: file `0x2D8` contains `08023A21` (SystemInit), and `0x2DC` contains `08020199` (scatter entry). Main begins at `08043A60`, reached by the `BL` at `0802029A`. The later `0802D5D8` call is an exit/loop path, not main.

Main's instructions at `[08043A68,08043A78)` are `4E F6 08 51 CE F2 00 01 00 22 C0 F6 02 02 0A 60`. They construct SCB VTOR address `E000ED08`, construct value `08020000`, and store that value at `08043A76`. This independently confirms the application vector mapping. File offsets therefore map to VAs by adding `08020000`; the image ends at `0804EA80` (exclusive).

SystemInit at `08023A20` enables the floating-point coprocessor access bits and includes the Nations signature check against `1FFFF298 == 49524B42` at `08023AF0..08023B04`, plus the same distinctive `RCC_CFG2=3800`, `RCC_CFG3=3840` values reviewed in [the N32 code comparison](sigma-n32-code-match.md). The Cortex-M little-endian Thumb interpretation is consistent with those facts and the photographed N32G455REL7 marking; no generic ARM-mode loader was used.

Confidence: high for vector, instruction and address facts. Startup code and the known part establish the target interpretation; emulation does not observe device boot or prove the exact installed application release.

## Scatter data

Unlike 1.1.5, the startup loop begins with `ADR r6,#0x50` at `080201A0` and reads its relative table bounds at file `0x1F4`. Stored words are `0002E608` and `0002E628`; adding the literal address yields table `[0x2E7FC,0x2E81C)`.

| Record file offset | Source | Destination | Output bytes | Handler |
| --- | --- | --- | ---: | --- |
| `0x2E7FC` | `0804E820` | `20000000` | `0x7B0` | `080201FC` |
| `0x2E80C` | `0804EA78` | `200007B0` | `0x5EA0` | `0802025C` |

Raw table bytes:

```text
20 e8 04 08 00 00 00 20 b0 07 00 00 fc 01 02 08
78 ea 04 08 b0 07 00 20 a0 5e 00 00 5c 02 02 08
```

The dispatcher supports relative handler entries, but these two entries are absolute even addresses; it sets their Thumb bit before branching. The actual decompressor at file `[0x1FC,0x256)` is byte-identical to 1.1.5's `[0x1D4,0x22E)`, justifying reuse of the existing literal/zero-run/back-copy transcription. The source stream `[0x2E820,0x2EA74)` contains 596 bytes and expands to 1,968 bytes at `[20000000,200007B0)`.

Fixture: `work/sigma/1.1.8/memory/initial-data.bin`, SHA-256 **`56df6503e19c10d9687591be7124de7c849f2a33b2c8cdc4225988b3d40c0ce9`**. The native instruction emulator reproduced every output byte and ended with input pointer `0804EA74`, independently confirming the transcription and consumed input range.

The zero-fill routine at `0802025C` writes `[200007B0,20006650)`, exactly `0x5EA0` bytes. Its source field is not read. Emulation verified zeroing and preservation of a canary beginning at `20006650`.

## Heap and stack reservation

The leaf helper at `080202CC` consists of four PC-relative loads and `BX LR`, returning these values:

| Register / meaning | Literal file offset | Original bytes | Original value |
| --- | --- | --- | --- |
| R0 / heap base | `0x2E0` | `50 46 00 20` | `20004650` |
| R1 / stack top | `0x2E4` | `50 66 00 20` | `20006650` |
| R2 / heap limit | `0x2E8` | `50 56 00 20` | `20005650` |
| R3 / stack base | `0x2EC` | `50 56 00 20` | `20005650` |

Proposed edit: file `0x2E8`, `50 56 00 20` → `50 55 00 20`. This reserves `[20005550,20005650)` for the Zeus object's private storage. The original 4-KiB heap becomes 3,840 bytes; the 4-KiB stack `[20005650,20006650)` stays unchanged. This conclusion depends on the existing heap-allocation strategy and requires the rebased patch to clear/initialize its reserved state.

The emulator executed the original helper, verified all four bounds, applied the proposed edit only in emulator memory, then confirmed that only R2 changed. This memory audit creates no patched firmware file. Confidence: high for the helper's bounds and effect; long-running heap pressure remains a hardware validation item.

## Tail and page geometry

Four zero alignment bytes follow the compressed stream through nominal endpoint `0x2EA78`. The final eight plaintext bytes, `10 8A B3 BD 97 A9 77 B2`, equal carrier ciphertext `[0x2EA58,0x2EA60)`, the final eight bytes of the preceding complete 32-byte transfer block. This repeats the earlier stale-buffer-residue pattern with eight trailing bytes instead of sixteen. It remains a packer hypothesis, not proof that the bootloader ignores these bytes. Preserve all original bytes outside explicitly reviewed edits.

The [photographed N32G455REL7 geometry](sigma-n32-hardware.md), based on the manufacturer datasheet SHA-256 `3a2cda0075958b47d5d815facbe5b37dc3cb2650e3377473cb01a8591eed92f8` and user manual SHA-256 `c345230a200209e522c7cde6c00970e26b1ac2076ae1a0949662aa2e01ce6e8f`, gives 2-KiB main-flash pages. Stock 1.1.8 spans 94 application pages, ending inside `[0804E800,0804F000)` with 1,408 bytes unused in that final page. Appending code within those 1,408 bytes adds no physical page. This arithmetic does not establish the bootloader's allowed length, erase algorithm or image-validation rules.

## Reproduction and limits

```sh
work/tools/python/bin/python scripts/sigma118_memory.py
work/tools/python/bin/python scripts/sigma118_memory.py --emulate
```

`memory/memory-manifest.json` records exact source hashes, byte ranges, operations, input/output hashes, bound literals and geometry. `memory/emulation-verification.json` records four passing finite checks using Unicorn's Cortex-M4 instruction model. Both commands are offline. The native emulator required JIT execution privileges on this Mac; no USB or device access occurred.

Neither the preserved original files nor the earlier dev2 candidate was changed. This establishes the rebasing memory inputs, not a successfully installed firmware image.
