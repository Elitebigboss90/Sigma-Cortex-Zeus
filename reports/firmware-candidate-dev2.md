# Sigma 1.1.5 Zeus dev2 — verified control mapping

Historical candidate: the user changed the target to 1.1.8 on November 2. [Current dev3](firmware-candidate-dev3.md) is rebased onto that release; the dev2 bytes and source snapshots remain unchanged.

Built October 27, 2026, America/Los_Angeles. **The candidate now uses observed shift-paddle and seven-way mappings. It passes offline tests with actual recorded wheel reports. It has not been installed on Sigma and remains NOT FOR FLASHING until bootloader acceptance/recovery is established.**

## Current artifacts

Directory: `work/sigma/zeus-dev2/`. The separate dev1 directory and its source snapshots are retained.

| Artifact | Size | SHA-256 |
| --- | ---: | --- |
| `NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev2.plaintext.bin` | 190,112 | `0152f4f17e23f47f452d2290fe782afb7b70d65b7a854be5e357da36910ab4a8` |
| `NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev2.encoded.bin` | 190,112 | `f7db442c77092c297f847670185892d14b9207f99573262bd81f0efd242fde88` |
| `NOT_FOR_FLASHING-SIGMA_Converter_V1.1.5-zeus-dev2.exe.disabled` | 3,819,008 | `bb04968c46d941d708f1b37ff6b7531f1d5846a6a7ac92bbd6d089941d6c237f` |

The disabled updater was assembled and inspected as data, never executed. All 749 non-firmware resources match the original updater. PE checksum/resource verification is separate from firmware integrity verification.

The exact source image remains decoded Sigma 1.1.5 SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`, file offset mapped to VA by adding `08020000`. Original updater SHA-256 is `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a`. Neither original was changed.

`build-manifest.json` identifies the source files, snapshots, compiled symbols, source byte edits, extension, encoding and output hashes. `package-manifest.json` records the added PE section and resource-entry edits. `emulator-verification.json` binds all tests and capture inputs to the exact candidate hash.

## New evidence incorporated

The user confirmed each action sequence during the corresponding live recording:

| Physical input | Observed Zeus usage | Source |
| --- | ---: | --- |
| Right shift paddle | 13 | Capture 003: three separate presses/releases |
| Left shift paddle | 14 | Capture 003: three separate presses/releases |
| Left seven-way Up / Right / Down / Left / Center | 44 / 47 / 46 / 45 / 43 | Capture 005; center independently confirmed in 007 |
| Right seven-way Up / Right / Down / Left / Center | 63 / 66 / 65 / 64 / 48 | Directions in 008; center in 007 |

Both analog fields traverse 0–127 in 003. The physical side of each analog field was not labeled by that sequence and remains unknown. Full hash, raw frame, line and byte-offset provenance is in [zeus-live-observation.md](zeus-live-observation.md), the per-capture correlation files, and [zeus-physical-control-map.json](zeus-physical-control-map.json).

Capture 004 was explicitly identified by the user as an incorrect sequence and is excluded from mapping. Capture 006 contained no changes despite an action confirmation; it is retained as an unresolved inactive interval. The subsequent 007/008 observations positively establish right-side responses. No hardware failure is inferred from 006.

These observed controls establish full USB input delivery through the actual Zeus/Xtend/KVM arrangement. Passive status report 02 also contains communication-mode value 1 under the recovered schema; [zeus-status-report.md](zeus-status-report.md) explains that interpretation and its cross-version caveat. No vendor mode/enable request was sent.

## Implemented profile

- Right shift 13 → console HID button 6; left shift 14 → button 5. This corrects dev1's provisional paddle orientation. These are the standard R1/L1 positions in the existing report convention; actual game assignments still depend on game settings.
- Either seven-way control drives the console hat. Both maps use the observed Up/Right/Down/Left order; diagonal combinations are supported and opposing directions cancel.
- Left center 43 additionally activates console button 11; right center 48 activates button 12, the corresponding stick-click positions. Existing numbered-button sources for those console controls remain available.
- Rx/Ry remain mapped to the matching console fields, scaled from 0–127 to 0–255, without replacing independent base steering or pedal fields.
- Other console buttons keep the provisional numerical mapping from dev1. Additional rotary/thumb-encoder usages and physical labels for the remaining ordinary buttons are not yet assigned. RGB/display/telemetry remain outside this input adapter.

Current console buttons 1–14 primary source table is `1,2,3,4,14,13,5,6,7,8,9,10,11,12`. Centers 43/48 are extra sources for buttons 11/12. The exact profile is recorded in the manifest and `patch/zeus_profile.h`.

## Binary changes and memory

The original firmware edits remain three four-byte ranges: heap limit at file `0x2C8`, constructor BL at `0x5102`, and report-builder BL at `0x537C`. Seven original bytes differ. All other original bytes, including the opaque final 16 bytes, remain at their original offsets.

New code and constants occupy 1,042 bytes at file `0x2E280` / VA `0804E280`, followed by 14 alignment bytes. Important Thumb symbols are constructor `0804E4B5`, report input `0804E3BD`, merge `0804E4F5`; immutable vtable is `0804E634`. The 156-byte state still fits the 256-byte reservation within the original heap, leaving stack bounds unchanged. The architecture/ABI evidence and limits remain in [sigma-patch-design.md](sigma-patch-design.md).

The AES-256-CTR carrier was regenerated with the recovered continuous counter stream, and byte-exact round trips verify. Those checks do not authenticate the firmware or prove the bootloader accepts the extended length.

## Verification

**16 finite ARM emulator checks pass**, including all 120 individual input bits, both hats' diagonals/opposites, wrong-device rejection (including the observed display PID), constructor/poll callback integration, malformed-report rejection, timeout wraparound, detach releases and memory canaries.

Additionally, **99 distinct measured report frames** from 003/005/007/008 were replayed through the compiled patch. Their buttons, hats, analog values and releases produce the expected console fields while independent steering/pedal data remain unchanged. This validates the patch's CPU/RAM behavior with actual input bytes; it does not run the real Sigma USB controller or PS5. USB hardware transaction boundaries are explicitly stubbed in the test manifest.

```sh
work/tools/python/bin/python scripts/build_sigma_zeus.py --build-id zeus-dev2
work/tools/python/bin/python -u scripts/verify_sigma_patch.py --build-id zeus-dev2
work/tools/python/bin/python scripts/package_sigma_candidate.py --build-id zeus-dev2
```

The builder refuses to replace an existing build ID when patch source contents differ. Use a new build ID for another profile/code revision. Source snapshots permit review of older artifacts after the working files evolve.

## Installation remains unresolved

November 2: [manual OK-button Bootload entry and normal return have been verified on the current unit](sigma-bootload-observation.md), including a successful status read through the KVM. This resolves the existence of an accessible manual entry sequence. Full flash backup, bootloader integrity/acceptance rules and restoration after a failed candidate update remain unverified. The candidate bytes are unchanged; no installation has been performed.

Sigma is now observed normally as `0EB7:0E07`, bcdDevice `0625`, with a report descriptor identical to the supplied 1.1.5 image. [sigma-live-observation.md](sigma-live-observation.md) distinguishes that identity match from proof of installed firmware, board revision or bootloader identity.

The normal application has no demonstrated bootloader-readback command. Its known update-entry request erases page `08018000` and resets; it was not used. We still need a matching bootloader/format specification or a permissible read-only hardware dump to establish image size/range handling, integrity validation and recovery. Exact hardware revision/chip/probe information is needed before choosing any debug-read method. See [sigma-readback.md](sigma-readback.md) and [sigma-integrity.md](sigma-integrity.md).

The unit has no reported revision marking and the user has no ST-Link. The subsequent [updater and recovery investigation](sigma-recovery-options.md) found no non-writing candidate preflight or matching bootloader in the additional public packages. Vendor format/recovery information remains a route forward without a probe; dev2 has not been changed or promoted to installation-ready status.

[Photos of the user's own board](sigma-hardware-photos.md) confirm the N32G455REL7 marking and expose candidate P1/CN3 headers, corroborating the independent SDK-family match. The photo-bound [geometry check](sigma-n32-hardware.md) shows stock and dev2 occupy the same 93 2-KiB flash pages, with the extension inside the existing final page. Header wiring, protection state and Sigma-specific bootloader rules remain unresolved; the user has no meter or probe. This identity evidence requires no candidate rebuild and does not verify installation.

No update-mode transition, erase, flash operation, protection change or Windows executable execution occurred. The candidate is available for review and further testing; normal enumeration and successful emulation do not make installation verified.
