# Sigma Cortex + Simagic Zeus: continuation guide

Updated November 2, 2026 (America/Los_Angeles). This file preserves the useful working context from the Mac investigation so a new chat on Windows or in the cloud can continue from the repository. It is a project summary, not a verbatim chat export.

## Current state

### Latest result: dev10 working on PS5 — November 2, 2026

**The user reports dev10 installed and working on PS5: “alright dev10 works perfectly on PS5”. Dev10 is the current working build for this setup.** This is the user's physical test result; individual reconnect/cold-start/force-feedback test details were not separately supplied. Preserve the working firmware and package; no further change or installation is needed for the reported issue. The packaged README/manifests record the earlier pre-installation state and remain unchanged. Details and updater hash: [dev10 instructions](work/sigma/zeus-dev10/README.md); package: `work/sigma/zeus-dev10.zip`. Updater SHA-256: `df633e0b66b6aa236c94d4e075c547cc486c5c3cb10fbbd3dc90d579de883001`.

Historical dev8 results: `reports/windows-sigma-dev8-controls-001.json` records both paddles pressing/releasing and seven-way directions. Attaching base/pedals after Xtend lost the base icon/checkmark. Restarting with base/pedals and Xtend disconnected restored the base icon/checkmark; the unit has **no separate pedal icon**. Connecting Xtend last preserved the checkmark, and the user confirmed paddles worked too. `reports/windows-sigma-dev8-base-first-xtend-last-controls-001.json` records steering and two pedal channels moving; a third channel stayed constant. Do not claim all three pedals were tested. The final dev8 physical reconnect test left the base connected but paddles did not return. These failures preceded the reported dev10 PS5 success.

Dev10 removes diagnostic report fields/heartbeat, retains three native hubs and 23/64-byte input, bypasses blind unmatched-device driver claiming using the existing address-only path, and releases the correctly mapped nested-hub subtree on disconnect. Two owned hub objects store parent/physical-port metadata in padding; orphan class objects are released after pool freeing. State remains 228/256 bytes and the image fits 94 pages. Offline actual-image checks pass: 18 groups with 120 bit cases/99 recorded frames, 56 exact base-report comparisons, 52 connection orders, and 30 repeated disconnect/rebind cycles with base/pedal preservation and held-paddle clearing. USB transport/descriptors and peripheral RAM are modeled. PS5 operation is now user-confirmed; do not infer separately measured timing, cold startup, reconnect or force-feedback results from the general success report. Dev9 is an internal draft without reconnect cleanup, not a hardware-tested alternative.

The reported compatibility issue is resolved on the user's PS5 setup. Keep dev10 as the working baseline and retain its ZIP and hashes. Additional tests are only needed for a newly reported problem or requested broader validation. Dev10 has no diagnostic marker; any future capture should read ordinary input reports. No updater was launched or firmware written by the agent. New firmware writes still require explicit user instruction. Earlier entries below preserve investigation history.

### New Windows hardware report — November 2, 2026

The user reports installing the experimental **zeus-dev3 updater**, which displayed **Completed**. Sigma detects the base, but the wheel icon is absent and Zeus buttons/paddles do not respond through Sigma in Windows joy.cpl. Testing only the powered wheel/Xtend, with base/pedals disconnected, also failed. Windows does enumerate Sigma. Completion alone does not establish that the patched application is running. Dev3 adds no explicit wheel-icon update.

A native read-only Windows HID check independently confirmed current Zeus identity **`3670:0804`** and Sigma **`0EB7:0E07`**. A 20-second direct-PC capture with SimPro closed recorded working paddle/seven-way/axis inputs. Windows delivers 64-byte ID1 buffers with the known control prefix and nonzero tails. This does not establish the length Sigma receives on the physical USB bus. Dev3's exact-23-byte gate is a concrete possible failure point. The registry's stored `3670:B804` entry was historical; do not change the identity gate based on it.

**The user subsequently reports installing `zeus-dev5-diagnostic`; its execution is now independently observed in Windows input.** Captures `reports/windows-sigma-after-change-002.json` (50 frames), `reports/windows-sigma-dev5-reconnect-001.json` (201 frames), and `reports/windows-sigma-dev5-coldstart-001.json` (50 frames) all carry the dev5 marker/heartbeat. They report address `0`, poll-enabled `0`, last Init return `FF` (no recorded Init call), native input length/ID `0`, and no accepted controls. The last test used powered Xtend alone in the same Sigma port that had detected the base and a cold start. The wheel is not reaching the instrumented Zeus Init/input path. This does not distinguish physical enumeration failure, another USB identity, or registry/dispatch failure. The length hypothesis is not sufficient to explain this observed earlier failure stage.

**Dev6 is now installed according to the user, and its execution is independently observed.** `reports/windows-sigma-dev6-installed-001.json` contains 50 dev6 frames with changing heartbeat. Binding page: wheel address 0, polling 0, Zeus Init FF, native length 0, accepted/ignored counters 0. Discovery page: cached identity **05E3:0610**, latest device-descriptor return **0D**, registry-slot match true, vtable-pointer match true. Thus the added driver remains present; a device-descriptor read is failing before Zeus initialization. The cached identity denotes a USB hub, not Zeus, and can precede the failed request. Do not replace Zeus's identity gate with the hub ID.

Native dispatch code reads register F8 and masks its low nibble; the matching USB Host Shield/MAX3421E definitions identify 0D as JERR. `reports/sigma-dev6-pre-init-jerr-emulation.json` reproduces the hardware status with an injected descriptor error. The user confirms **Xtend directly into Sigma**, without an intervening hub/KVM/extension. Controlled dev6 captures now show:

- **All accessory ports empty, cold start:** `reports/windows-sigma-dev6-empty-001.json`, identity `1A40:0101` (hub), descriptor result `00`.
- **Only powered Xtend reconnected, no reboot:** `reports/windows-sigma-dev6-xtend-after-empty-001.json`, identity changes to `05E3:0610` (another hub), result `0D`, no Zeus Init.

Original startup has only one hub instance. The captures indicate Sigma's own hub consumes it, leaving Xtend's additional hub unclaimed. `reports/sigma118-nested-hub-model-002.json` reproduces a matching failure via native reset-complete events: with one hub, HID fallback addresses the unclaimed hub and later descriptor reads at address zero return modeled 0D. Adding a second native hub lets both hubs and Zeus initialize. Synthetic descriptors/transport behavior remain model assumptions; physical causation is not yet confirmed. Preliminary model 001 used an unmasked parent in manual child calls and is superseded; native handler 0802BC3E masks parent addresses to three bits.

**Dev7 was subsequently installed, but still did not initialize Zeus.** `reports/windows-sigma-dev7-installed-001.json` contains 51 dev7 reports, both registry checks true, cached `05E3:0610`, descriptor `0D`, no Zeus address/polling/Init/input. The user's product picture is consistent with the hub assembly but does not establish its electrical hub count.

**The full Xtend branch has now been measured: it adds two cascaded hubs.** `reports/windows-sigma-zeus-shared-usb-tree-001.json` shows Zeus under three `05E3:0610` nodes, with the outermost one shared by Sigma's PC connection. The user then unplugged Xtend and moved Sigma's PC plug to the exact same PC socket. `reports/windows-sigma-xtend-same-pc-socket-001.json` has only that one PC-side Genesys hub, then `174C:2174`/root. Thus two hub nodes belong to the Xtend branch; converter-side topology needs three hub instances including Sigma's internal hub. Dev7 supplies two, so it undercounts the measured path. USB tree inspection is read-only and omits serials/instance paths; node tokens compare shared ancestors only within a snapshot.

**Dev8 is installed and has now initialized Zeus on hardware.** `reports/windows-sigma-dev8-installed-001.json` contains 529 dev8 reports over five seconds. Hubs are bound at `41/4A/53`; final hub polling is enabled. Zeus is at **1A**, polling enabled, Init **00**, and its accepted-report counter advances continuously. Native callback length is overwhelmingly **23**, with one observed 64-byte callback; management reports are ignored as intended, though the diagnostic does not identify their IDs. The original exact-23-byte gate is not the observed enumeration blocker. The last descriptor-return field still shows **0D**, which can belong to another USB request/device and must not be interpreted as a Zeus failure when Zeus is actively polled.

The initial five-second observation was neutral. Subsequent physical-control and coexistence results, including the failed reconnect, are recorded in the latest entry above. Standalone hat reads Up (0) without the base; with the recognized base, captured idle hat is neutral (8). Dev10 retains the original baseline builder.

Dev8 adds two native 24-byte hub objects at `20005604` and `2000561C`, slots 7/8, after all original registrations and Zeus slot 6. Total reserved state is 228/256 bytes with unchanged dev3 heap/stack bounds. The actual image passes 12 offline groups including native three-hub events and paddle polling plus 125 captured prefixes at 23/64 bytes. `reports/sigma118-xtend-three-hub-capacity-001.json` compares actual dev7/dev8 images. Image size remains 192,512 bytes / 94 pages. Version 8 exposes hub addresses/final-hub polling instead of cached VID/PID; discovery bit 1 checks slot 8. [Dev8 instructions](work/sigma/zeus-dev8-diagnostic/README.md). Console/game behavior remains unverified; diagnostics overwrite vendor report bytes, so keep the present tests on Windows. Any further firmware installation requires explicit instruction.

Dev6 adds descriptor-helper return/VID/PID observation and expected registry-slot/vtable-pointer checks, alternating diagnostic pages. It retains 23/64-byte handling, fits the same 94 pages, and passes nine offline groups including 125 distinct captured prefixes at both lengths. [Dev6 instructions](work/sigma/zeus-dev6-diagnostic/README.md). Any further installation requires explicit user instruction. The user clarified the screenshot change meant X/Y Rotation bars moved left; live reports confirm Rx/Ry = 0 while the first four axes = 128. Dev5's periodic baseline reporting explains those positions without working wheel input. No base/pedal regression was reported in that clarification.

Dev5 records a heartbeat, USB binding, Init return, native callback length/ID and accepted input in vendor bytes 56–63, and supports 23- or 64-byte ID1 control prefixes. It is for Windows diagnosis, not PS5/game use. Six verification groups passed, including 125 distinct captured control prefixes at both lengths. The package preserves 749 non-firmware resources and still uses 94 application pages. It has not restored controls in the reported hardware test. See [Windows investigation](reports/windows-hardware-troubleshooting.md) and [candidate instructions](work/sigma/zeus-dev5-diagnostic/README.md). Dev3/originals are preserved; preliminary dev4 diagnostic artifacts are retained but are not the current candidate. New firmware writes still require explicit instruction; the user's report of having installed dev5 is not authorization for another write.

The sections below describe the earlier, pre-installation investigation unless explicitly updated.

**Earlier baseline:** dev3 was originally built and tested offline, then published in a GitHub prerelease. The new hardware report above supersedes the earlier statement that installation and Windows detection were still pending. Exact installed bytes have not been read back.

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

## Earlier Windows detection sequence

The user now reports completing these steps and installing dev3, as recorded above. Do not repeat this sequence by default. Exact version/status strings were not preserved; request missing details only to answer a specific remaining question. The original sequence was:

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

> Read CONTINUE_HERE.md and reports/windows-hardware-troubleshooting.md. The user reports dev10 “works perfectly on PS5” on November 2, 2026. Keep dev10 as the working baseline; no additional fix or installation is currently needed. It retains three native hubs and fixes unmatched-driver claiming and nested-hub cleanup, with normal output reports. Offline checks pass (18 groups, 56 base-report comparisons, 52 connection orders, 30 reconnect cycles). General PS5 success is user-reported; separate reconnect/cold-start/force-feedback details were not supplied. Dev8 failures and dev9 internal draft are historical. Preserve the dev10 ZIP, hashes, originals and candidates. No flashing, bootloader writes or option-byte changes without my explicit instruction for that action. Keep explanations brief and report concrete evidence.
