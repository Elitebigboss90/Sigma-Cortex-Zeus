# Sigma Cortex + Simagic Zeus: continuation guide

Updated November 2, 2026 (America/Los_Angeles). This file preserves the useful working context from the Mac investigation so a new chat on Windows or in the cloud can continue from the repository. It is a project summary, not a verbatim chat export.

## Current state

**An experimental Sigma 1.1.8 BETA-based firmware candidate, `zeus-dev3`, has been built and tested offline. It has not been installed or tested on Sigma/PS5 hardware.** The two ZIP downloads are published as a GitHub prerelease. The next outstanding step is stock-updater detection on Windows, without clicking Update.

Do not restart from the old 1.1.5 candidate. Early reports and projects remain useful historical evidence, but their absolute addresses are not the current 1.1.8 bindings.

## Objective and hardware

The user wants a Sigma Cortex Converter firmware that supports:

- **Simagic Zeus Formula Steering Wheel**, connected through **MagLink Pro Xtend**.
- An **Alpha Ultimate** wheelbase and separate pedals.
- PS5 output from Sigma.

The intended connections are wheel/MagLink USB, base USB and pedal USB into Sigma. Zeus's direct USB input path is separate from the base's steering/force-feedback path. Do not assume the wheel's controls arrive through the base.

The user initially selected Sigma 1.1.5, then supplied 1.1.8 and explicitly requested the mod be rebased onto it. They believe the installed unit is already on 1.1.8. **The installed application version has not been independently confirmed.** The package's target version is not proof of the device's current version.

User-supplied board photos confirm the **Nations Technologies N32G455REL7** marking. The user has **no ST-Link/J-Link and no multimeter**. Main-board P1 header signals have not been established. Do not invent a pinout or recommend connecting a programmer to guessed pins. See [board-photo evidence](reports/sigma-hardware-photos.md) and [MCU evidence](reports/sigma-n32-hardware.md).

The user has a Windows PC available. Read-only Mac captures worked through their KVM. A direct Mac connection did not work reliably for them; cable/port cause remains unknown. Do not assume either that the KVM prevents updates or that successful enumeration proves a stable flashing connection.

## Work completed

| Area | Completed work | Main evidence |
| --- | --- | --- |
| Environment | Native arm64 Mac setup; Homebrew tools, REA/Codex integration, matching Ghidra/JDK/decompiler; no Rosetta or VM | [Environment](reports/environment.md) |
| Inputs | Preserved originals, hashes, package inventories and reproducible extraction; obtained additional Sigma releases, SimPro installer and vendor documentation | [Inventory](reports/package-inventory.md) |
| Sigma updater | Static native x86 PE analysis; located embedded payload and reviewed HID update framing and resource replacement | [1.1.8 updater](reports/sigma-1.1.8-updater.md) |
| Firmware decoding | Established AES-256-CTR transformation from embedded vendor constants and verified byte-for-byte round trips | [Sigma analysis](reports/sigma-analysis.md), [Simagic analysis](reports/simagic-analysis.md) |
| Architecture | Established Cortex-M/Thumb mappings, vector/reset evidence, scatter initialization, heap/stack and USB classes | [1.1.8 memory](reports/sigma-1.1.8-memory.md), [USB bindings](reports/sigma-1.1.8-usb-bindings.md) |
| Zeus input | Read-only live USB/HID observations and user-labeled paddle/switch captures through the actual Zeus/Xtend/KVM setup | [Live observations](reports/zeus-live-observation.md), [mapping](reports/zeus-mapping.md) |
| Patch | Built 1.1.5 candidates, then independently re-established bindings and rebased onto 1.1.8 as dev3 | [Current candidate](reports/firmware-candidate-dev3.md), [rebase](reports/sigma-1.1.8-analysis.md) |
| Offline validation | 16 ARM checks, 99 distinct captured frames, and 56 additional non-neutral base-input report comparisons passed | [Emulator results](work/sigma/zeus-dev3/emulator-verification.json), [coexistence results](work/sigma/zeus-dev3/coexistence-verification.json) |
| Recovery observation | User reached manual Bootload mode; Mac read one status response; ordinary power cycle returned to the normal application | [Bootload observation](reports/sigma-bootload-observation.md) |
| Publication | Project, all 40 existing ZIPs, originals, Ghidra databases, captures and candidates pushed; two ZIPs published as prerelease assets and downloaded again to verify hashes | [Publication](reports/repository-publication.md), [release configuration](.github/releases/dev3.json) |

No Windows updater was executed on the Mac. No device firmware was flashed or original firmware file modified during this recorded work.

## What the compatibility problem appears to be

Zeus enumerates as **VID:PID `3670:0804`**, interface 0. Its normal input report is **23 bytes including report ID `01`**:

| Bytes | Meaning |
| --- | --- |
| 0 | Report ID `01` |
| 1–2 | Rx/Ry analog inputs, observed range 0–127 |
| 3–17 | 120 button usage bits, least significant bit first |
| 18–22 | Vendor fields, not fully assigned |

The 64-byte endpoint capacity does not make the ordinary control report 64 bytes. Management IDs `02` and `F9` are different reports and must not be parsed as ID 1.

Static analysis and emulation establish that the existing 1.1.8 device-specific predicates reject Zeus's identity and existing base parsers do not implement its report format. Replacing one PID constant would be insufficient. Fallback enumeration exists, so the exact physical failure stage on Sigma—claiming, initialization, polling or parsing—has not been observed.

Zeus firmware has USB/CAN-FD routing modes. Live captures establish that the user's actual setup delivers full controls over USB without sending a vendor enable command. That does not establish behavior after attachment to Sigma. See [compatibility gap](reports/compatibility-gap.md); sections explicitly labeled historical 1.1.5 must not supply dev3 patch addresses.

### Measured control mappings

These are HID usage numbers, not byte offsets:

| Physical control | Captured usages |
| --- | --- |
| Right shift paddle | 13 |
| Left shift paddle | 14 |
| Left seven-way: Up, Right, Down, Left, Center | 44, 47, 46, 45, 43 |
| Right seven-way: Up, Right, Down, Left, Center | 63, 66, 65, 64, 48 |
| Analog paddles | Both ranges 0–127; physical left/right assignment remains unconfirmed |

Useful labeled captures are `reports/zeus-live-input-003.jsonl`, `005`, `007` and `008`. Capture `004` had an incorrect action sequence; `006` did not establish the intended directions. Do not treat every recording as a successful labeled capture.

Ordinary-button labels, PS/Home mapping, additional encoder behavior and game-specific axis use remain incomplete. RGB, wheel display and telemetry support are outside this candidate.

## Current firmware implementation

Source: [patch/sigma118/sigma_zeus.c](patch/sigma118/sigma_zeus.c), [linker script](patch/sigma118/sigma_zeus.ld), [shared profile](patch/zeus_profile.h).

Dev3 preserves six original USB class registrations and adds a seventh for Zeus. It uses the existing generic HID enumeration/poll path, stores Zeus controls separately, validates identity/report ID/exact length, merges controls after the original console report builder, and clears its controls on release or a provisional 250-tick timeout. Base steering, pedals, gear and handbrake fields are retained.

The 1.1.8 application is mapped at `0x08020000`. Its initial stack pointer is `0x20006650`; the reset vector points to Thumb address `0x080202B1`. Dev3 changes seven original bytes across three four-byte regions:

| File offset / virtual address | Change |
| --- | --- |
| `0x2E8` / `0x080202E8` | Reduce heap limit from `0x20005650` to `0x20005550`, reserving 256 bytes |
| `0x473E` / `0x0802473E` | Redirect the final constructor **tail branch**, preserving LR and the original final constructor |
| `0x23B80` / `0x08043B80` | Call the appended merge hook, which calls original builder `0x080460C0` first |

The added state uses 156 bytes. Original stack bounds remain unchanged. Code/constants append at `0x0804EA80`; candidate end is `0x0804EEC0`. Stock and candidate occupy the same **94 × 2-KiB application pages**. The eight opaque original final bytes at file offset `0x2EA78` remain in place. These facts do not prove the bootloader accepts the longer image or establish its integrity rules.

The modified updater preserves all original native executable sections and all 749 non-firmware resource payloads. It redirects the firmware resource into an appended `.zeus` PE section. PE checksum/resource checks and AES round trips pass; neither establishes device-side signature/checksum acceptance.

## Files and downloads to use

[Release page](https://github.com/Elitebigboss90/Sigma-Cortex-Zeus/releases/tag/zeus-dev3-sigma-1.1.8). The repository requires appropriate GitHub access.

| ZIP | Purpose | SHA-256 |
| --- | --- | --- |
| [windows-detection-check-1.1.8.zip](https://github.com/Elitebigboss90/Sigma-Cortex-Zeus/releases/download/zeus-dev3-sigma-1.1.8/windows-detection-check-1.1.8.zip) | Unchanged stock updater, detection instructions and hashes | `461b72e580b84bafe5611ff5277dd6506c906e1e5ec5a3dbf285250316fa9123` |
| [zeus-dev3.zip](https://github.com/Elitebigboss90/Sigma-Cortex-Zeus/releases/download/zeus-dev3-sigma-1.1.8/zeus-dev3.zip) | Experimental 1.1.8 candidate and associated evidence | `ad02c399e8df2318738cf1691d6fd7261786d2b7e6d70cf3920717b70a261b80` |

Both published ZIPs were downloaded inside the release workflow and matched these hashes. The stock detection ZIP does **not** contain the modified candidate. The experimental EXE retains `.exe.disabled`; publishing it did not authorize or perform installation. The ZIP is a fixed snapshot; consult repository `main` for the latest reports and supplemental checks.

Current files under `work/sigma/zeus-dev3/`:

| Artifact | Bytes | SHA-256 |
| --- | ---: | --- |
| `NOT_FOR_FLASHING-sigma-1.1.8-zeus-dev3.plaintext.bin` | 192,192 | `236fdf7580f553352ada033468654ebf3bff1ec70898184e988149d15f34c77c` |
| `NOT_FOR_FLASHING-sigma-1.1.8-zeus-dev3.encoded.bin` | 192,192 | `e3fd514ff8d97756efd745e60d483ca7594719ad647a4ec4d8e0dd599f5f90d2` |
| `NOT_FOR_FLASHING-SIGMA_Converter_V1.1.8-zeus-dev3.exe.disabled` | 3,823,104 | `4a5d5eddbef1fe80fd8415448a9bd152929fdd365a8de757ccbbe91b3a977295` |

Stock 1.1.8 updater SHA-256: `233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a`. Decoded stock application SHA-256: `6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035`.

## Exactly what has and has not been verified

The ARM emulator executes the compiled patch and selected original routines. Checks cover registration, callback ABI, all 120 input bits, measured frame replay, mappings, heap/stack bounds, state canaries, timeout wraparound and merge behavior. Additional checks compare 56 full reports across eight base-input patterns with stock output. Some USB transaction, poll and release boundaries are stubbed, as recorded in the test results. These are finite CPU/RAM checks, not physical USB, timing, heap-load or PS5 tests.

Manual Bootload entry is physically observed:

1. Disconnect Sigma from accessories and power.
2. Hold OK while reconnecting its console/PC USB port; keep holding about five seconds, then release.
3. The user's screen showed **Bootload mode**.
4. A later power cycle without OK returned to the normal screen.

The Mac observed boot-mode identity `046D:C260`, product `G29 Driving Force Racing Wheel`, and normal identity `0EB7:0E07`, product `FANATEC WHEEL(PS5 / PS4 MODE)`. Those are Sigma's emulated USB identities.

A single read-only F1 GET_FEATURE returned:

```text
34 12 00 00 01 00 00 00 01 00 01 00 00 00 00 00
```

**This was a 16-byte status response, not a firmware dump.** Interpreting part of it as `1.0.1` is provisional; platform framing and bootloader fields are not fully established. It does not establish the installed app version. No complete flash or bootloader dump exists.

Still unresolved:

- Whether the bootloader accepts dev3's encoded application, length and preserved opaque bytes.
- The exact bootloader OK-check implementation and guaranteed entry after an invalid/crashing application.
- A demonstrated stock restore following a failed candidate. Manual entry on a working unit is useful evidence, not a restoration test.
- Physical Zeus enumeration, polling, detach/reconnect and coexistence with base/pedals on Sigma.
- Sustained timing/memory behavior, PS5 authentication/navigation and actual game controls.

The updater's “Update Complete” message is not firmware readback or proof of a working boot. Its update-entry command is mutating: the application erases metadata at `0x08018000` and resets. Do not use that command as a harmless identification probe. Do not unlock MCU protection, mass erase, write option bytes or guess undocumented bootloader commands to obtain a dump.

## Next step on Windows

**Windows detection results have not yet been reported.** Start here unless the user supplies new observations:

1. Extract the stock detection ZIP. Disconnect Sigma's accessories and connect its console/PC port to Windows. Prefer a known working data connection; record whether it uses the KVM.
2. Open the stock `SIGMA_Converter_V1.1.8.exe` and record the exact detected device/current version and status. **Do not click Update during this check.** Distinguish installed/current version from the package's target version.
3. Close the updater, power-cycle into manual Bootload mode using the sequence above, reopen the same updater, and record its status/version including any `BL` suffix.
4. Close the updater and power-cycle without OK. Confirm normal operation returns. Record disconnects or failures.

After those observations, evaluate a concrete experimental installation with the user. The prior work authorized development, capture, packaging and publication; it did not authorize flashing. Do not present the mod as functional or restoration as guaranteed. A stock reinstall, if chosen, is itself a flash operation and would not prove modified-image acceptance. Lack of a debug probe is not proof that USB installation is impossible.

If an installation is subsequently explicitly authorized, first record the exact selected artifact/hash, working stock updater and recovery-entry procedure. After installation, verify Sigma boot/manual Bootload entry, then Zeus input, concurrent base/pedals, releases/disconnection, and PS5 controls. Keep observations distinct from assumptions and update this guide with results.

## Environment and reproduction notes

Original workspace: `/Users/ethan/Devs/sigma-re` on native arm64 macOS. The recorded setup uses REA 6.8.0, Node 24.22.1, Ghidra 12.1 with JDK 21 and an arm64 native decompiler, 7-Zip 26.01, LLVM/LLD 23.1.4, OpenSSL 4.1.0, and a Python environment with pefile, Capstone, Unicorn 2.1.4 and pyelftools. Exact versions/commands are in [environment.md](reports/environment.md).

REA's integrated Linux firmware-extraction route was not forced onto macOS. Its generic raw ARM loader excludes Cortex-M/Thumb-only targets, so direct Ghidra `ARM:LE:32:Cortex` imports with evidence-based maps were used for these images. Relevant projects are `ghidra/sigma-118-firmware.gpr`, `sigma-118-updater.gpr`, `zeus-firmware.gpr` and `simagic-main.gpr`.

The repository uses Git LFS for large artifacts. To obtain the complete project:

```sh
git clone https://github.com/Elitebigboss90/Sigma-Cortex-Zeus.git
cd Sigma-Cortex-Zeus
git lfs install --local
git lfs pull
```

Local Python environments and compiler caches were intentionally excluded. Mac paths, native helper binaries and `scripts/env.sh` are not a ready-made Windows setup. Adapt paths/tool versions to the actual host before attempting a rebuild. Reading the reports and doing the stock Windows detection check do not require recreating the complete reverse-engineering environment.

Existing Mac verification commands, for reference:

```sh
source scripts/env.sh
work/tools/python/bin/python scripts/verify_sigma118_patch.py --build-id zeus-dev3
work/tools/python/bin/python scripts/verify_sigma118_coexistence.py
python3 scripts/finalize_sigma118_candidate.py
```

Unicorn required native JIT access outside the Mac agent sandbox. Its test model is explicitly Cortex-M4. Memory-write instrumentation disturbed Thumb conditional execution in this setup, so the verification uses code hooks and post-execution comparisons/canaries.

Preserve dev1/dev2/dev3 and their source snapshots. Use a new build ID for any source/profile change instead of overwriting dev3. Reuse existing reports and captures; request another physical capture only to resolve a specific remaining question. Do not infer a processor, address map or encryption scheme from filenames or entropy alone.

## Prompt for a new chat

> Read CONTINUE_HERE.md and the linked current Sigma 1.1.8/dev3 reports in Elitebigboss90/Sigma-Cortex-Zeus. Continue the Zeus Formula + MagLink Pro Xtend compatibility project from the recorded state. A Windows PC is available; the next pending step is stock updater detection in normal and Bootload modes. First incorporate any new hardware results I provide. Preserve originals and existing candidates. Do not assume any firmware was installed or that recovery/integrity checks are proven. No flashing, bootloader writes or option-byte changes without my explicit instruction for that action. Keep explanations brief and report concrete evidence.
