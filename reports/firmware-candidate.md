# Sigma 1.1.5 Zeus development candidate

**Historical dev1 report. Current work is [dev2](firmware-candidate-dev2.md), which incorporates verified paddle/direction mappings and actual capture replay.** Dev1 artifacts and source snapshots remain in their original directory; the working source files and default build commands now target dev2. Reproducing dev1 requires its retained source snapshot rather than the current profile.

Built October 27, 2026, America/Los_Angeles. **An experimental firmware image and a disabled updater copy now exist. They have not been flashed, booted on Sigma, or validated on PS5. They are not ready for installation.**

The direct USB adapter is implemented. Live KVM enumeration confirms Zeus identity and the recovered descriptor. Both completed recordings contain only idle controls, so physical mapping and active USB/CAN FD routing remain unconfirmed.

## Artifacts and reproduction

Files below are in `work/sigma/zeus-dev1/`:

| Artifact | Bytes | SHA-256 |
| --- | ---: | --- |
| `NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev1.plaintext.bin` | 189,952 | `788ffe72fb2ca1307b1743a2f4768f7757d9a92dc52eb1c495f348b70c155b14` |
| `NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev1.encoded.bin` | 189,952 | `5613b44afd4e5e1fc0bfb43078bfca473ac1d75f855ea6b8106b024f9e6dbb70` |
| `NOT_FOR_FLASHING-SIGMA_Converter_V1.1.5-Zeus-dev1.exe.disabled` | 3,818,496 | `d28ee379d8552d6057e804207af67e2b6b36472b9da2bcb7b515cc83eaa66ae2` |

Source decoded image: `work/sigma/1.1.5/sigma-decoded.bin`, SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`. Original updater: SHA-256 `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a`. Originals remain unchanged. `build-manifest.json`, `emulator-verification.json`, and `package-manifest.json` beside the artifacts identify exact input/output hashes, edits, symbols, source files, commands and validation.

Source files are `patch/sigma_zeus.c`, `patch/zeus_profile.h`, and `patch/sigma_zeus.ld`.

```sh
work/tools/python/bin/python scripts/build_sigma_zeus.py
work/tools/python/bin/python -u scripts/verify_sigma_patch.py
work/tools/python/bin/python scripts/package_sigma_candidate.py
```

## Changes and evidence

Three original four-byte ranges are edited, changing seven original bytes in total. Firmware file offset = VA minus `08020000`.

| File offset / VA | Change | Supporting original code |
| --- | --- | --- |
| `0x2C8` / `080202C8` | Heap limit `20005590` → `20005490` | Stack/heap initializer `080202AC`; separate stack bounds retained |
| `0x5102` / `08025102` | BL to additional-driver constructor wrapper | Wrapper first calls original `08025149` |
| `0x537C` / `0802537C` | BL to console-report merge wrapper | Wrapper first calls original builder `0802A8B5` |

The 878-byte extension starts at file `0x2E280` / VA `0804E280`, followed by 18 alignment bytes. All original bytes outside those three ranges, including the unclassified final 16 bytes and compressed initialization data, retain their offsets. The candidate is re-encoded using continuous AES-256-CTR. Original and candidate transformations round-trip exactly; unchanged plaintext offsets preserve identical original ciphertext.

The 156-byte driver state fits a 256-byte reservation from the original 4-KiB heap, leaving 3,840 bytes. Stack bounds and declared RAM extent do not change. ROM extension acceptance remains unresolved; being smaller than the separately observed 1.0.20 carrier does not prove acceptance or capacity on the user's unit. Exact bytes and ABI evidence are in [sigma-patch-design.md](sigma-patch-design.md).

The implementation adds a sixth registry entry while retaining the hub and four original application classes. It restricts recognition and endpoint eligibility to `3670:0804`, interface 0, reuses generic HID enumeration/polling, and accepts only ID `01` with length 23 for controls. The interface restriction comes from the shipped configuration descriptor; a complete live configuration capture is still desirable.

Controls are stored separately and merged after the original console builder. Detach and timeout clear controls and request a new console report. Failed first initialization releases an allocated USB address; a busy existing binding remains intact. Exact code behavior is supported by the emulator checks below, not a hardware test.

## Development profile and limitations

Console HID button usages 1–14 map to Zeus usages:

```text
Console:  1  2  3  4   5   6  7  8  9 10 11 12 13 14
Zeus:     1  2  3  4  13  14  5  6  7  8  9 10 11 12
```

Factory firmware assigns the two main shift groups to usages 13/14. Their placement on console usages 5/6 and the remaining numerical mapping are explicit development choices, not observed physical assignments. Left/right orientation and saved-profile overrides require a labeled capture. Factory evidence is in [zeus-mapping.md](zeus-mapping.md).

Rx/Ry are clamped to the declared 0–127 range, scaled to 0–255, and placed in console Rx/Ry bytes 8/9. This does not establish a game's clutch interpretation and does not overwrite separate pedal fields.

**D-pad directions and additional rotary/button usages are not enabled in this profile.** Generic hat merging is implemented, but its four configured usages are zero until direction ordering is verified. RGB/display/telemetry and wheel-update services are outside this input adapter. This is not a complete Zeus feature implementation.

The timeout is 250 counter ticks. Original `08024F20` sets SysTick reload to `0x23280` or 8000, clears its current value, and writes CTRL=7; handler `08024FC0` increments `2000081C`. `08024FD8` scales the counter by 1000 and interpolates the current tick. This supports the software's intended millisecond counter, but the actual Sigma clock was not measured. The timeout is a chosen policy, not a recovered Zeus requirement. Evidence: `work/sigma/zeus-dev1/timing.c`, from the original source hash above.

## Validation performed

`emulator-verification.json` records **13 passing checks** against the exact candidate hash. Unicorn executes the compiled Thumb patch and selected original routines using a Cortex-M4 instruction model. This is an ISA test vehicle, not identification of Sigma's exact chip.

Checks cover original scatter decompression; actual constructor registration; heap/stack bounds; identity/interface filtering; failed/busy initialization cleanup; unchanged output without Zeus; all 120 individual input bits; axis boundaries and malformed/management report rejection; original generic-poll dispatch through the new vtable and fifth stack argument; timeout wraparound; detach releases; the patched BL; and state boundary canaries.

Hardware USB operations are stubbed at documented boundaries. The original generic polling routine is executed with only the low-level USB IN transaction replaced. These tests do not simulate the complete converter, bootloader or PS5. Native JIT memory mapping failed inside the agent sandbox and succeeded outside it. The installed engine's memory-write instrumentation also disturbed Thumb conditional execution in a diagnostic run; removing that instrumentation and using boundary comparisons allowed the original scatter routine to reproduce the independent RAM fixture exactly.

The disabled updater adds a read-only `.zeus` PE section and redirects only `TEXTFILE / IDR_APP_FILE / 1033` to the candidate carrier. The other **749 resources remain byte-identical**. PE section/resource ranges and the ordinary PE checksum verify. That checksum is not firmware authentication. Original updater execution code and displayed 1.1.5 identity remain unchanged; the disabled filename and manifests identify this modified copy. It was not executed.

## What prevents installation

1. **Bootloader acceptance and recovery are unknown.** No demonstrated application command reads bootloader flash. The known update-entry request erases page `08018000` and resets, so it was not used. Permitted image size, write/erase bounds, trailer interpretation and checksum/signature requirements remain unresolved. See [sigma-integrity.md](sigma-integrity.md) and [sigma-readback.md](sigma-readback.md). A permissible read-only dump or authoritative format/recovery evidence is needed; protection changes, erasing or flashing are not part of obtaining it.
2. **Physical controls and routing are unconfirmed.** The KVM captures contain 155,960 successful ID-1 reports at approximately 5-ms host intervals, all with idle axes/buttons. The requested physical paddle sequence has not yet been confirmed. These samples cannot distinguish an untouched USB-mode wheel from hybrid routing over CAN FD. See [zeus-live-observation.md](zeus-live-observation.md).
3. **Hardware regression testing has not occurred.** Enumeration alongside base/pedals, releases under disconnect/reconnect, timing and PS5/game behavior remain untested.

To record the next labeled sequence without output/feature/update commands:

```sh
work/patch-toolchain/capture_zeus_input reports/zeus-live-input-003.jsonl 180
work/tools/python/bin/python scripts/analyze_zeus_capture.py reports/zeus-live-input-003.jsonl
```

Choose a new filename. During the recording, press/release right shift three times, left shift three times, sweep each analog paddle separately, then exercise seven-way up/right/down/left/center with gaps. Preserve the action order. Current artifacts must not be treated as installation-ready before the outstanding questions are resolved.
