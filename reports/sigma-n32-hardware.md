# N32G455REL7 lead: memory, protection and recovery

October 27, 2026, America/Los_Angeles. The initial **Nations N32G455REL7** lead came from a teardown/specification. The user's subsequent [board photos](sigma-hardware-photos.md) visibly confirm `N32G455` and `REL7` markings on their own U1, corroborating the independent [code comparison](sigma-n32-code-match.md). Electrical chip-ID verification, header wiring and protection state remain unobserved. The user has no multimeter or debug probe.

## Primary documents retained

All files are under `originals/Nations-documentation/`; [nations-documentation-manifest.json](nations-documentation-manifest.json) records source/final URLs, lengths and hashes. Product-page download links were used after an older datasheet URL returned 404.

| Document | Official source | SHA-256 |
| --- | --- | --- |
| N32G455 datasheet V2.6.0, 92 pages | [Manufacturer PDF](https://www.nsing.com.sg/uploads/Microcontrollers/N32G455xx_V3.5.0/2-Datasheet/EN_DS_N32G455_Series_Datasheet_V2.6.0.pdf) | `3a2cda0075958b47d5d815facbe5b37dc3cb2650e3377473cb01a8591eed92f8` |
| N32G45x user manual V3.5.0, 818 pages | [Manufacturer PDF](https://www.nsing.com.sg/uploads/Microcontrollers/N32G455xx_V3.5.0/3-User_Manual/EN_UM_N32G45x_Series_User_Manual_V3.5.0.pdf) | `c345230a200209e522c7cde6c00970e26b1ac2076ae1a0949662aa2e01ce6e8f` |
| N32G45x/N32G4FR/N32WB452 BOOT guide V1.2, 33 pages | [Manufacturer PDF](https://www.nationstech.com/uploads/Microcontrollers/N32G4FRxx_V3.2.0/8-User_Guide/EN_UG_N32G45x%26N32G4FR%26N32WB452_Series_BOOT_interface_instruction_use_guide_V1.2.pdf) | `f6ded490b328f8e817bd19d9170dc7d4cdd61b50478afd559b4e97bc527dde19` |

An older 834-page V3.1.0 user manual is retained separately; conclusions below use V3.5.0. Page numbers are one-based PDF page numbers. PDFKit text extractions and rendered figures are under `work/sigma/n32/`. The resource table, LQFP64 pinout and boot-mode table were inspected visually.

## Documented part properties

Datasheet pp.1,9,87 and the official pack's REL7 device block specify Cortex-M4F, up to 144 MHz, LQFP64, 512 KiB main flash and 144 KiB total SRAM. The photographed part marking now supports applying this geometry to the board; protection and allocation still require separate evidence.

User manual pp.51–52,64–65:

| Region | Address range, end exclusive | Size |
| --- | --- | ---: |
| Main flash | `08000000–08080000` | 512 KiB; 2-KiB pages |
| Main SRAM | `20000000–20020000` | 128 KiB |
| Retention SRAM | `20020000–20024000` | 16 KiB |
| Factory system BOOT | `1FFF0000–1FFF4000` | 16 KiB |

Retention SRAM requires initialization for parity. The `10000000` SRAM alias is not another independent RAM bank.

## Dev2 geometry check

`scripts/verify_sigma_n32_geometry.py` pins both image hashes, the current documents and official pack. It parses the exact REL7 flash/RAM declarations and checks containment using the documented page geometry. Output: `work/sigma/n32/geometry-verification.json`.

Run with `--photo-evidence` to also verify both supplied photo hashes and write `work/sigma/n32/geometry-verification-photos.json`. The earlier record is retained as the pre-photo snapshot; visual part identification is distinguished from an electronic ID read.

| Image | SHA-256 | End exclusive | Application pages |
| --- | --- | --- | ---: |
| Original decoded 1.1.5, 189,056 bytes | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` | `0804E280` | 93 |
| Dev2 plaintext, 190,112 bytes | `0152f4f17e23f47f452d2290fe782afb7b70d65b7a854be5e357da36910ab4a8` | `0804E6A0` | 93 |

Both start at the independently established `08020000` and end within page `[0804E000,0804E800)`. **Dev2 adds no flash page** under this geometry; 352 bytes remain in that last page after its end. This is address arithmetic, not an observation of the bootloader's erase algorithm. The new state reservation `[20005490,20005590)` fits main SRAM and retains its existing heap-allocation justification.

These findings narrow the physical-space uncertainty. They do not establish partition permission, the allowed resource length, trailer/integrity semantics or recovery. No reason to rebuild dev2 follows from this memory check alone. Its source, bytes and prior 16 emulator checks remain unchanged.

## Protection controls the readback route

User manual pp.57–58: L0 permits flash reads; L1 blocks external debug flash reads; reverting L1 to L0 automatically erases main flash. L2 disables debug and is irreversible. Thus a probe's unlock function cannot be used to preserve a protected bootloader. Current RDP/partition values are unknown.

## Factory BOOT is distinct from Sigma's updater

The BOOT guide pp.3–6 documents USART1/USB DFU and a vendor command protocol. Its command list contains identification, option/partition queries, programming and CRC verification, but no general flash-read command. Identification is `10/00` (pp.11–12); option read is `40/00` (p.20); partition read is `41/00` (pp.21–23). These are documentation references, not commands sent to Sigma. The CRC command checks supplied expected data and can update management information; it is not established as passive readback. Factory encrypted download uses AES-128-ECB, unlike the recovered Sigma AES-256-CTR carrier. No factory-to-Sigma format equivalence follows.

User manual p.51 selects system BOOT with BOOT0=1, BOOT1=0 at reset; USB requires a supported HSE clock. This documents silicon behavior, not accessible controls on Sigma. Its custom update-entry erase/reset and missing flash-resident loader remain separate. A factory programming interface alone does not supply a backup of Sigma's loader/settings or prove restoration from an application-only package.

## Pins to identify on a matching board

Datasheet p.32, Figure 3-4, and pin definitions identify the following **LQFP64 chip pins**, not Sigma test-pad locations:

| Signal | Port / chip pin |
| --- | --- |
| SWDIO | PA13 / 46 |
| SWCLK | PA14 / 49 |
| Reset | NRST / 7 |
| BOOT0 | Dedicated / 60 |
| BOOT1 | PB2 / 28 |
| USB D− / D+ | PA11 / 44; PA12 / 45 |
| USART1 TX / RX | PA9 / 42; PA10 / 43 |

The supplied photos identify a four-hole main-board **P1** beside U1 and a three-hole **CN3** below it. Their signals are not labeled and end-to-end wiring is not established from the images. The next physical step is a continuity measurement to map the connector, requiring a suitable meter or assistance from someone equipped to do it. No pin has been driven or connected by this analysis. If read-only debug access becomes available and protection permits it, preserve the existing flash/metadata before deciding on an installation. If protection prevents reading, retain the vendor-information route without changing protection.
