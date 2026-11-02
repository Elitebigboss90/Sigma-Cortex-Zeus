# Sigma 1.1.5: Nations N32G45x source comparison

The decoded Sigma startup closely matches the official Nations/NSING N32G45x support code, including a distinctive factory-word check and backup-voltage trim routine. This is strong evidence for **N32G45x SDK lineage**, substantially stronger than the earlier tentative Artery register-map resemblance. The code comparison alone does not identify the exact suffix or physical unit. The user's subsequent [board photos](sigma-hardware-photos.md) independently show N32G455REL7 markings on U1; the original teardown/specification lead is no longer the sole part-identification evidence.

## Sources and reproducibility

Official [Arm device page](https://www.keil.arm.com/devices/nsing-n32g455rel7/processors/) links the [NSING pack entry](https://www.keil.arm.com/packs/n32g45x_dfp-nsing/devices/), which links [NSING.N32G45x_DFP.1.0.7.pack](https://www.nsing.com.sg/public/uploads/armpacks/NSING.N32G45x_DFP.1.0.7.pack). Downloaded 2026-10-27 into `work/tools/nations/packs/`; 1,273,945 bytes, SHA-256 `b4eed0b822131d0563c848f332c914bf558a840b1b4d912d8029e0db148de60a`. The PDSC release date is 2024-08-14. This dates the reference package, not the Sigma build's source version.

The pack's 107 ZIP members were extracted without modification. `work/tools/nations/packs/NSING.N32G45x_DFP.1.0.7.manifest.json` records each member's hash, size and ZIP local-header offset. Referenced paths below are relative to that extracted pack directory.

| Source | SHA-256 |
|---|---|
| `firmware/CMSIS/device/system_n32g45x.c` | `f061fca77483ceae6b941e1b4a1b821f7eea715c6af1ec4aee7684eb295f2b97` |
| `firmware/CMSIS/device/n32g45x.h` | `a1cdac4068ad11e26d8228a91778e88d389818d5e7dc226c5590cd0a74b180b4` |
| `firmware/n32g45x_std_periph_driver/src/n32g45x_flash.c` | `d927291f35f7a409a08db37abd916a7bbea4f6830aae2f755447866214ca1c26` |
| `firmware/n32g45x_std_periph_driver/inc/n32g45x_flash.h` | `76c8885945041c5e9da868bf1526f5c2e37e83f53c54a6da8543468e961f7295` |
| `NSING.N32G45x_DFP.pdsc` | `5c5b53eb65af741221ba212e80e719eac87b7e7d0674a0e1413a32c340aa4eb3` |
| `svd/N32G455.svd` | `048ec45f3ecd82c3bf208cc42fe9fd40a1caba1b41920415ba763aa70a6afc80` |

Sigma input: `work/sigma/1.1.5/sigma-decoded.bin`, 189,056 bytes, SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`. Application mapping is `VA = file offset + 0x08020000`, as independently established in `sigma-architecture-evidence.md`.

Run `work/tools/python/bin/python scripts/integrity_n32_match.py` to verify all eight input hashes and retain exact bytes and Thumb/M-class instruction listings for five relevant spans in `work/tools/nations/sigma-source-match.json`. This is a manual semantic comparison with disassembly evidence, not an assertion that the reference source was compiled into a byte-identical binary. No code or device commands were executed on a target.

## Matches

| Sigma file offset / VA | Supporting bytes or operations | Official source comparison | Interpretation / confidence |
|---|---|---|---|
| `0x08C8` / `0x080208C8` | `4ff29820 c1f6ff70` construct `0x1FFFF298`; word load; `44f64231 c4f65211` construct `0x49524B42`; unequal branch calls `0x08020A50` | `system_n32g45x.c:214–215` checks precisely this address/value and calls `SetVDDDBKTrim()` when unequal | Distinctive exact constant/control-flow match; high. The source treats it as a backup-voltage trim flag, not a USB ID, authentication key or image checksum. |
| `0x0A50–0x0AE4` / `0x08020A50–0x08020AE4` | Enable PWR clock via `0x4002101C` bit 28; read `0x40001800`, extract bits 28:24; add 2, saturate at 31; place in `0x4000700C` bits 9:5; disable PWR clock | `system_n32g45x.c:445–473`, complete `SetVDDDBKTrim()` arithmetic and register sequence | Independent, detailed corroboration of the magic check; high. |
| `0x080A–0x087E` / `0x0802080A–0x0802087E` | RCC base `0x40021000`; masks `F8FFC000`, `FEF6FFFF`, `FFFBFFFF`, `F700FFFF`; `CFG2=3800`, `CFG3=3840`, clock-interrupt register `009F0000`. Immediate encodings for the two CFG defaults: `4ff46051`, `4ff46151` | `system_n32g45x.c:169–190` contains the same ordered reset sequence; `n32g45x.h:1155,1170,1244` computes RCC base | Multiple exact non-generic startup settings; high. Register base alone was insufficient to name a vendor. |
| `0x087E–0x08B6` / `0x0802087E–0x080208B6` | Enable PWR clock, set `PWR CTRL3` bit 0, disable PWR clock; then OR `0x90` into FLASH at `0x40022000` | `system_n32g45x.c:193–198`; header `FLASH_AC_ICAHEN=80`, `FLASH_AC_PRFTBFEN=10` at lines 7333/7336 | Same extended-power-mode/cache-prefetch startup sequence; high. |
| `0x08E8–0x0A50` / `0x080208E8–0x08020A50` | HSE readiness timeout `8000`; flash latency 4; APB2 divider bits `2000`, APB1 bits `500`; PLL mask `F7C0FFFF`, source bit `10000`, multiplier bits `08040000`; wait for PLL and select it | `system_n32g45x.c:322–438`; default clock 144 MHz at line 67, HSE/PLL choice at lines 71–72, multiplier formula lines 415–418. With default HSE 8 MHz (`n32g45x.h:64`) this is HSE /1 ×18 | High for programming sequence; strongly consistent with a 144 MHz build configuration. Actual board oscillator and measured runtime clock remain unobserved. |
| `0x4F38–0x4F50` / `0x08024F38–0x08024F50` | `43f28022 c0f20202` constructs reload `0x23280` = 144000; HSE-failure flag selects 8000 instead; store to SysTick reload `E000E014` | Consistent with the reference's 144 MHz default and 8 MHz HSI fallback | Corroboration, not an exact reference-function match. The stored reload implies 144001 or 8001 ticks per wrap, not mathematically exact 1 kHz. High for constants; medium for intended millisecond cadence. |
| `0x1344–0x13DE` / `0x08021344–0x080213DE` | FLASH key register `40022004`, keys `45670123` / `CDEF89AB`; erase clears status mask `7C`, timeout `B0000`, CTRL `40022010` PER mask `02` / START mask `40`, address at `40022014`, final CTRL AND `3FFD` | `n32g45x_flash.c:97–101,232–236,259–285`, with constants in that source/header | Full unlock/page-erase flow matches the Nations driver. High; keys alone are shared with other MCUs and were not independently decisive. |

There is one observed application adaptation: on external-oscillator startup failure, Sigma writes `1` to RAM `0x20000810` at VA `0x08020966–0x08020972`, and its SysTick setup consumes that flag. Reference `SetSysClock()` instead sets `SystemCoreClock=HSI_VALUE` at source line 345. Therefore this comparison supports shared SDK ancestry and configuration, not identical source or build provenance.

## Scope and effect on earlier conclusions

The structured PDSC family declaration says Cortex-M4 with FPU and little-endian execution (line 25). Its exact `N32G455REL7` device block (lines 757–784) describes LQFP64, flash `0x08000000 + 0x80000` and SRAM `0x20000000 + 0x24000`. These are declarations for that orderable part, not measurements of the connected unit. The same PDSC contains erroneous top-level narrative referring to Cortex-M0/48 MHz; that prose conflicts with its structured declarations and the official Arm device entry, so it should not be used as silicon evidence. Physical SRAM partitioning and protection/recovery behavior require the chip documentation addressed separately.

The earlier Artery possibility in `sigma-architecture-evidence.md` was explicitly tentative and based on overlapping addresses. The rare factory check, full trim routine, clock reset constants and flash-library behavior now strongly favor Nations N32G45x SDK lineage. No contradiction to the reported N32G455REL7 was found in these examined paths. No family-level code match proves REL7 rather than another compatible N32G45x part, and no current physical chip ID, option bytes, bootloader bytes or bootloader acceptance rule was obtained. The candidate's integrity and recovery uncertainties are therefore not resolved by this identification.
