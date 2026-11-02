# Sigma 1.1.8 Zeus dev3

Built November 2, 2026, America/Los_Angeles. **Dev3 is based on the newly supplied Sigma 1.1.8 BETA.** It replaces 1.1.5-based dev2 as the current analysis candidate. Dev2 and all vendor originals remain unchanged. No device has been flashed.

## Artifacts

Directory: `work/sigma/zeus-dev3/`.

| Artifact | Bytes | SHA-256 |
| --- | ---: | --- |
| `NOT_FOR_FLASHING-sigma-1.1.8-zeus-dev3.plaintext.bin` | 192,192 | `236fdf7580f553352ada033468654ebf3bff1ec70898184e988149d15f34c77c` |
| `NOT_FOR_FLASHING-sigma-1.1.8-zeus-dev3.encoded.bin` | 192,192 | `e3fd514ff8d97756efd745e60d483ca7594719ad647a4ec4d8e0dd599f5f90d2` |
| `NOT_FOR_FLASHING-SIGMA_Converter_V1.1.8-zeus-dev3.exe.disabled` | 3,823,104 | `4a5d5eddbef1fe80fd8415448a9bd152929fdd365a8de757ccbbe91b3a977295` |

Original decoded 1.1.8 SHA-256: `6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035`. Original 1.1.8 updater SHA-256: `233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a`. [Package and rebase evidence](sigma-1.1.8-analysis.md) records extraction, semantic bindings and limitations.

The modified updater uses the **1.1.8 executable and embedded application**, with all 749 other resource payloads and all native executable sections preserved. Its PE checksum and redirected resource were verified. It has not been executed; PE consistency is separate from device image acceptance.

## Changes

The measured Zeus profile is unchanged from dev2: right/left shifts 13/14, left seven-way 44/47/46/45/43, right seven-way 63/66/65/64/48, analog ranges 0–127 scaled to console Rx/Ry. Other numbered buttons retain the provisional profile. Additional encoder assignments, physical labels for the remaining buttons, and actual game behavior remain unverified. RGB/display/telemetry are not implemented.

The rebase preserves all six original USB classes and adds Zeus as the seventh. It preserves 1.1.8's new base-parser type-`0x0B` handling, which is consistent with the NeoX patch note. New absolute bindings and callback ABI were re-established from 1.1.8 rather than offset-adjusted from 1.1.5.

Only seven original bytes differ, within three four-byte ranges:

| File offset / VA | Original → replacement | Purpose |
| --- | --- | --- |
| `0x2E8` / `080202E8` | `50 56 00 20` → `50 55 00 20` | Reserve 256 bytes at `20005550` from the existing heap; retain stack bounds |
| `0x473E` / `0802473E` | `07 F0 D7 BE` → `2A F0 C5 BA` | Tail B.W to constructor hook `0804ECCC`; preserve restored caller LR and run original final constructor |
| `0x23B80` / `08043B80` | `02 F0 9E FA` → `0B F0 C6 F8` | BL to merge hook `0804ED10`, which first calls original builder `080460C0` |

The original eight opaque final bytes remain at file `0x2EA78`. New code/constants append at `0804EA80`: 1,070 bytes plus 18 alignment bytes. Candidate end is `0804EEC0`; **stock and dev3 occupy the same 94 2-KiB application pages**, leaving 320 bytes in the original last page. The 156-byte state fits its 256-byte reservation; heap capacity becomes 3,840 bytes and the original 4-KiB stack bounds remain unchanged.

The complete original carrier and candidate round-trip under the recovered continuous AES-256-CTR transform. Unmodified original plaintext offsets retain the original ciphertext. These transformations do not prove integrity/signature acceptance by the bootloader.

## Verification

**16 offline ARM checks pass**, including:

- Actual 1.1.8 scatter reconstruction, constructor chain, tail-branch return behavior and new driver registration.
- Heap/stack bounds, object/vtable layout, VID/PID/interface rejection and failed/busy initialization handling.
- All 120 input bits, observed paddle and seven-way mappings, diagonals/opposites and analog boundaries.
- Replay of **99 distinct recorded Zeus frames**, including releases.
- Actual 1.1.8 generic poll and fifth-stack-argument callback ABI, with the low-level USB IN boundary stubbed.
- Timeout wraparound, detach releases, original console builder behavior, patched merge call and state canaries.

An independent review found no blocking binding/layout issue and checked the new B.W tail hook, vtable preservation, raw RAM references, fixture identity and final flash-page containment. A separate original-constructor/predicate emulation also passes without hardware stubs; see [USB bindings](sigma-1.1.8-usb-bindings.md).

USB controller behavior, sustained timing/heap use and PS5 behavior are outside these tests. [Manual Bootload entry and return](sigma-bootload-observation.md) are observed on the current stock unit, but restoration from a failed candidate and acceptance of this image have not been tested. No full device flash dump has been obtained.

### Supplemental coexistence verification — November 2, 2026

[Reproducible test](../scripts/verify_sigma118_coexistence.py) and [hashed result](../work/sigma/zeus-dev3/coexistence-verification.json): **8 non-neutral base input patterns, 56 exact 64-byte report comparisons, all PASS**. The test executes original constructor `08024720`, original builder `080460C0`, and the compiled dev3 input/merge/release wrappers. It compares against the unmodified 1.1.8 builder with identical base RAM inputs. Steering and three pedal values, gear, handbrake, base buttons, base paddle configurations and held base hats are exercised alongside Zeus controls. Zeus direction release restores the base hat; neutral input, timeout and release restore the full stock report. A fresh input callback after release is accepted. All candidate artifact hashes remain unchanged.

Confidence is high for these finite CPU/RAM cases. Original poll `08028FB0` and release `08028E50` are stubbed in this supplemental test; it does **not** establish physical detach/reattach, simultaneous USB scheduling, or hardware stability. The original 16 checks and 99-frame replay also pass. The result records the exact candidate and script hashes; its source snapshot is retained separately from the original build inputs.

### Next hardware checks

1. On a Windows PC, use the untouched vendor 1.1.8 updater to observe normal-mode device/version detection, without clicking Update. Repeat detection after manual OK-button Bootload entry. Verify the intended data cable/port; the Mac KVM connection has only established enumeration and a status read. Return to normal mode afterward.
2. Before an explicitly authorized experimental installation, retain the stock updater and record the working manual-entry procedure. A successful stock reinstall would establish the ordinary write/restore path, but would itself write flash and would not prove modified-image acceptance or recovery after a corrupted application. It is not a read-only check and has not been performed.
3. After an authorized candidate installation, verify boot and manual Bootload entry, then Zeus input through Sigma, concurrent base/pedals, releases/disconnection, and PS5 navigation/game controls. Ordinary button labels, particularly the intended PS/Home control, remain provisional.

The outstanding bootloader acceptance and failed-image recovery questions cannot be answered by these application-only emulator checks. No firmware write is part of the detection check above.

The user confirmed a Windows PC is available. A [Windows detection handoff ZIP](../work/sigma/windows-detection-check-1.1.8.zip) contains the byte-identical supplied stock updater, instructions, a copy-provenance manifest and file hashes. ZIP SHA-256: `461b72e580b84bafe5611ff5277dd6506c906e1e5ec5a3dbf285250316fa9123`. It contains no modified candidate. [Preparation script](../scripts/prepare_windows_detection_check.py) verifies the pinned original hash, retains the updater filename, validates the ZIP and checks the original again afterward. The Windows detection results are pending; preparation did not access a device.

```sh
source scripts/env.sh
work/tools/python/bin/python scripts/build_sigma118_zeus.py --build-id zeus-dev3
work/tools/python/bin/python -u scripts/verify_sigma118_patch.py --build-id zeus-dev3
work/tools/python/bin/python scripts/package_sigma118_candidate.py --build-id zeus-dev3
```

`build-manifest.json`, `emulator-verification.json` and `package-manifest.json` bind exact source/artifact hashes to the checks. Source snapshots preserve the build inputs. Use a new build ID if patch source changes.
