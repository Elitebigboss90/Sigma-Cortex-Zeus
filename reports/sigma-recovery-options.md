# Sigma recovery and acceptance evidence without a probe

Updated November 2, 2026, America/Los_Angeles. The user's [board photos](sigma-hardware-photos.md) show **N32G455REL7** markings on U1, corroborating the teardown lead and independent Nations N32G45x SDK comparison. They also show an unpopulated four-hole P1 and three-hole CN3, with unverified signal assignments. The user has no multimeter or debug probe. See [the N32 hardware investigation](sigma-n32-hardware.md) for memory, factory BOOT and protection findings. Protection state and usable debug access remain unverified. The subsequent manual Bootload test and one GET_FEATURE status read are documented below; no purchase, erase, flash, unlock, SET_REPORT or output-report command was performed by the investigation.

**Dev2 remains an offline candidate. Manual Bootload entry and normal return are observed, while candidate acceptance and failed-image restoration remain unverified.** The public-package investigation below did not supply a bootloader image or documented flash-read command. Hardware readback remains unavailable with the present equipment.

## Stock updater cannot perform a harmless candidate preflight

**November 2 follow-up:** [manual Bootload entry and return to normal are now observed](sigma-bootload-observation.md). Holding OK at power-on produced the Bootload screen and USB identity `046D:C260`; the Mac read one 16-byte F1 status response through the KVM. A power cycle without OK restored normal `0EB7:0E07` enumeration. This establishes a working entry sequence on the stock unit, while the exact button-check implementation, full flash readback, failed-image restoration, and dev2 acceptance remain unverified. No firmware dump or installation occurred. The [static audit](sigma-recovery-audit.md) records the independent application fault-handler findings.

The additional [updater audit](sigma-updater-preflight.md) establishes the ordering from the original 1.1.5 EXE, SHA-256 `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a`:

- Host VA `004042B9` sends report 03 with the known update-entry payload. The application erases `08018000` and resets on this command.
- The updater first looks up its embedded firmware at `00404471`, after update-entry and F1 preparation.
- F1 status displays version information; no candidate digest/acceptance query was found.
- After transfer, it sends F1/04 and F1/01, then displays completion at `00404697` without an intervening readback or successful-boot check.

The unmodified updater has only its embedded original image. A stock-update attempt would neither test the separate dev2 image nor remain read-only. Confidence: high for the reviewed code path; missing bootloader behavior remains unknown.

## Additional public packages examined

[NOX Gaming](https://www.noxgaming.ca/product/sigma-cortex-converter/) and [Bolori](https://bolori.es/en/producto/sigma-cortex-converter-ps4-ps5/) link the same [SCCfirmware folder](https://drive.google.com/drive/folders/1aTedVCru4gTWvNfpPdoLB5TV_NqR-zfO) and [Sigma manual](https://drive.google.com/file/d/1ItboEBJZtLVQm-ymsng9ezPzOKaxQJ_r/view). The saved folder response exposes two ZIP entries and an account display name `sigmacortexofficial`. These are distributor-linked files with indicated vendor authorship, not cryptographically authenticated releases. A failed access to `https://sigmasimracing.com/downloads/` through the web tool provided no additional content; it does not establish that the site or unpublished recovery files do not exist.

| Preserved original | Bytes | SHA-256 |
| --- | ---: | --- |
| `originals/SIGMA v1.0.10/SIGMA 1.0.10.zip` | 2,041,809 | `ff91bd6cbe59939bd45976e0a3f7cdb4d9e0cddb39eb69990b78b7717acfee8c` |
| `originals/SIGMA v1.0.11/SIGMA 1.0.11.zip` | 33,789,116 | `0cbce14aa4d7f14949b807009de536aac42dd7cf917bcb3cbb7874942274d3f9` |
| `originals/Sigma-documentation/sigma user manual May 15 .pdf` | 11,630,369 | `2d9d87e15bce258b65c4024acfeff81032a92dbabbee2a7dd83b86ab3f3da8bb` |

[sigma-legacy-input-manifest.json](sigma-legacy-input-manifest.json) records source URLs and filenames. The saved listing is `work/sigma/public-recovery-research/firmware-folder.html`, SHA-256 `d3d92253b1172b3df084968f392437a809e7f1299f16d3e2097ae2bc423492b5`.

`scripts/inventory_sigma_legacy.py` verifies the pinned originals and extracts all **five ZIP members** into separate work directories. `work/sigma/public-recovery-research/extraction-manifest.json` records each exact compressed byte range, range hash, DEFLATE operation and output hash. ZIP CRC32 checks verify archive consistency, not device firmware authentication.

1.0.10 contains one updater and one bulletin. 1.0.11 contains one updater, one bulletin and `sigma user manual_V2.pdf`. Neither ZIP supplies a standalone bootloader or recovery utility. The original double `.exe.exe` filenames and `SIMGA` spelling are preserved. No executables were run.

Both extracted updaters have 750 PE resources, one named firmware resource `TEXTFILE/IDR_APP_FILE/1033`, and no appended overlay. Resource inventories and source ranges are under `work/sigma/{version}/resources/`:

| Release | Updater SHA-256 | Firmware resource EXE offset / length | Encoded payload SHA-256 |
| --- | --- | --- | --- |
| 1.0.10 | `0cd5480295fd27786879ccfc5318f2d3b8376f1ebfc8bfcc2d6457c5ee434ba5` | `0x1E3EF8` / 202,720 | `a345ba13a2ad4eed648f09e4e4c1158995b9786a2a521ff51bf3b619e07ed7c1` |
| 1.0.11 | `41395b9909cb631adcf0fb506b6375c13ef2d31c6e0b9716c62a5c60456805dd` | `0x1E3EF8` / 202,912 | `4cfcc50ac6c2c9ccf642b8b9998b6c078360238e9d1dd0dbf597eec43ff95aa8` |

The existing evidence-derived AES-CTR decoder round-trips both resources exactly. Decoded SHA-256 values are `f42367e350cb4874bcdf42c2ee4bb4520fc8aab89c1b34a5aca6622918fbe7c4` (1.0.10) and `691bc550b4ad98da3b5f73c16b961973564cbb7f26cb9b44bebed25622347cdb` (1.0.11). Each `.transform.json` records the complete operation and range.

At decoded offset 0 their initial SP words are `20006378` and `20006380`; both reset words at offset 4 are `08020291`. At file `[0x290,0x2A6)` both match 1.1.5 startup bytes exactly: `0948804709480047fee7fee7fee7fee7fee7fee7fee7`. This supports an application mapping at `08020000`, rather than a newly supplied bootloader prefix. Exact bytes and limited disassembly are saved in `legacy-vectors.json` and `legacy-startup-evidence.json` under the research directory. Confidence: high for byte facts and matching application startup; this is not an exhaustive search for hidden encoded data or proof of exact silicon.

The bulletins describe the ordinary PC/updater upgrade sequence, with no recovery procedure. Their SHA-256 values are `c2ef0beb5ba4f201840f9ce65f83dc43267026d97d9e038253972a9c0bc430f1` and `e3c02f0ba326b84ab376eb4a1b833619c0efa97ee635b3cd921c7feba29a9924`. Both manuals are single-page imposed sheets; the Upgrade section below Operating Instructions describes connecting USB and using the upgrade program. The supplied V2 PDF has SHA-256 `e649788206f946037b808d13d6ec6c33d183602b406c63ed5784b2ed9165e7d7`. Rendered page images are retained. OCR was incomplete and is not used as evidence of absent text. No bootloader acceptance specification or recovery instruction was identified in the reviewed upgrade sections.

## Information that would unblock installation analysis

A vendor specification or a matching bootloader image could resolve this without buying a probe. Exact questions to send to Sigma or the seller:

1. How is the board/bootloader revision identified on an unmarked unit, without entering update mode?
2. What image length, address range, checksum/signature and trailer rules does the 1.1.5-compatible bootloader enforce? How do F1 preparation/finalization set validation metadata?
3. Does recovery remain available after a failed application update, and what is the documented procedure and required host software? Does recovery require the application to run?
4. Is there a supported read-only bootloader/metadata export, or a matching service bootloader image and format documentation?

No message has been sent. Hardware inspection and a compatible debug probe remain another possible route, but chip identity, pinout and protection state must be established before selecting commands. A generic ST-Link purchase alone would not establish access or recovery. The target remains 1.1.5 and the [dev2 artifacts](firmware-candidate-dev2.md) are unchanged.
