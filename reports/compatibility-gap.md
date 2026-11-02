# Zeus Formula through MagLink Pro Xtend: compatibility gap and patch proposal

Current target, explicitly changed November 2: **Sigma Cortex 1.1.8 BETA**, **Simagic Zeus Formula**, **MagLink Pro Xtend**, **Alpha Ultimate**, separate pedals. Intended topology: wheel/MagLink USB, base USB and pedal USB all connected to Sigma. The user believes the board already runs 1.1.8; its exact installed application version has not been independently read.

**Static evidence establishes missing Zeus-specific USB recognition and control-report handling. A one-constant PID replacement is insufficient.** The current [1.1.8 dev3 candidate](firmware-candidate-dev3.md) implements a driver and merge using observed paddle/seven-way mappings. Sixteen offline checks and 99 captured input-frame replays pass. No hardware-tested Sigma patch has been produced.

The [1.1.8 rebase](sigma-1.1.8-analysis.md) re-establishes all bindings: five existing non-hub predicates reject Zeus `3670:0804`; the patch preserves six class registrations and adds Zeus seventh. It edits only the heap-limit literal at `080202E8`, final constructor tail branch at `0802473E`, and report-builder call at `08043B80`, then appends code inside the stock final flash page. Native type-`0x0B` base-parser support remains intact. Bootloader acceptance/integrity rules, full readback, failed-image restoration and actual Sigma/PS5 behavior remain unresolved.

Unless explicitly marked as 1.1.8, the source keys, addresses and detailed evidence below are the historical 1.1.5 basis. See the linked 1.1.8 report for current addresses and hashes.

## Source keys

November 2 installation evidence: [OK-button Bootload entry, a status read and normal return are now observed](sigma-bootload-observation.md) on the user's unit through the KVM. No firmware was installed; the read produced 16 status bytes, not a flash dump. The candidate is unchanged; bootloader image acceptance and actual Zeus/PS5 behavior still require verification.

| ID | Artifact | SHA-256 |
| --- | --- | --- |
| S | Decoded Sigma `work/sigma/1.1.5/sigma-decoded.bin` | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` |
| Z | Decoded Zeus `work/simagic/zeus-formula-decoded.bin` | `85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a` |
| U | Zeus SFU `ZeusFormula_App-A1.1.15.13445-eb889282.sfu` from official SimPro installer | `571535e07edc9efb8c7403eecf60caf861631ae9bf312a2755acc4d4e26b7e7f` |
| M | `originals/Simagic-documentation/Maglink_Pro_Xtend_User_Manual_EN.pdf` | `c39afe5e482d52cd10cc8dcfcc39875f6bb9d74e4c8baf5edb84daa8739a3ae3` |

S file offset = VA − `0x08020000`; Z file offset = VA − `0x08021E00`. These mappings were independently established from each image's startup and pointers. Complete original-to-decoded lineage is in [package-inventory.md](package-inventory.md), [sigma-analysis.md](sigma-analysis.md), and [simagic-analysis.md](simagic-analysis.md).

## Established mismatch

| Evidence | Observed fact | Implication / confidence |
| --- | --- | --- |
| S VAs `08027108`, `0802BA28`, `0802BB50`, `0802BCD8`; vtables `080467F8`, `080469F4`, `08046A4C`, `08046AA4` | Registered application predicates admit `0483:0522`, `0483:0530`, `3670:0A04`, `0483:0525`, `0483:0524`, `0483:0531` | No `3670:0804` match in these VID/PID predicates; high confidence |
| Z offset `0x1AE14`, descriptor bytes `12 01 00 02 00 00 00 40 70 36 04 08 1f 01 01 02 03 01` | Zeus descriptor declares **VID `3670`, PID `0804`** | Distinct from the existing `3670:0A04` handbrake; high confidence. Live Xtend enumeration independently confirms this VID/PID, with a different bcdDevice revision; see [live observations](zeus-live-observation.md). |
| Z report descriptor offset `0x1AE28`, length `0xA4`; descriptor returned by USB handler `0802A7E0` | Input ID 1 contains 176 payload bits: 22 bytes, **23 with report ID** | A different format from Sigma's base-report parsers; high confidence |
| S VAs `08027280`, `080272E0`, `08027810` | Base callback restricted to `0483:0522`; parsers require exactly 39/32 bytes and dispatch status low-six-bit types 0–6 | Reusing a base parser for Zeus direct USB would misread/ignore it; high confidence |
| M PDF pages 8–10 (zero-based) | Xtend hub has a PC interface and a separate power connection | Wheel USB path can be independent of base USB. This is documented topology, not a live capture |

Sigma's enumeration routine S `080228B0` also attempts unmatched classes in a fallback pass. A missing VID/PID predicate match alone therefore does not locate the live failure at enumeration. The existing callbacks' identity checks and incompatible parsing establish the input-support gap; a Sigma-host trace would determine whether Zeus is unclaimed, partially initialized, or polled and ignored.

The [official manual](https://cdn.shopify.com/s/files/1/0764/6756/8943/files/Maglink_Pro_Xtend_User_Manual_EN.pdf?v=1779688626) supports treating MagLink's host connection separately. The base remains responsible for steering/force feedback. Zeus firmware can expose USB while routing ordinary controls over CAN FD, so enumeration alone would not establish the control path. **Captures 003/005/007/008 now establish full USB control delivery through the user's actual Zeus/Xtend/KVM arrangement**, without a vendor enable command. Whether attachment to Sigma changes that routing still requires hardware observation. No mode-selection command was needed or sent.

## Zeus report layout recovered offline

All byte positions below **include** report ID at byte 0. Source Z report descriptor, `work/simagic/zeus-evidence.json`:

| Byte(s) | Declared field | What is not established |
| --- | --- | --- |
| 0 | Report ID `01` | Live captures confirm the byte is included; Sigma's generic poll path likewise passes raw report bytes |
| 1, 2 | Two unsigned 8-bit Generic Desktop axes, Rx and Ry; declared logical range 0–127 | Physical paddle assignment, calibration and clutch combination behavior |
| 3–17 | 120 one-bit button usages, LSB first within each byte | Shift paddles and both 7-way switches are now mapped from labeled captures; remaining physical button/encoder assignments are incomplete |
| 18–21 | 32 vendor-defined bits | Meaning and relationship to encoder or mode state |
| 22 | One vendor-defined byte | Meaning |

Configuration descriptor Z `0x1ADE8` declares one HID interface with interrupt IN `81` and OUT `01`, maximum packet size 64, interval 1. The logical report length is not the endpoint maximum. IDs `02` and `F9` have 64-byte input reports; they must not be interpreted as ID 1. Feature/output IDs also exist for management and configuration.

**Mode caveat, established in code:** Z callback `080264A4` selects report builders by state. State 1 (`USB`) calls `08025514(0)` and sends the complete 23-byte ID 1 report. State 9 (`USB+CANFD`) calls `08025514(1)`, sends axes/buttons in a separate 20-byte transport-4/message-`0x200` packet, and still sends USB ID 1 with bytes 1–17 zero and vendor bytes 18–22 populated. State 4 (`CANFD`) calls `08025F54` for that 20-byte packet. These software names are linked to executable transitions and log references in `08023438`: state-9 stores at `0802359C` and `08023628` reference strings at Z offsets `0x19E94` and `0x19EBD`; reverse and state-4 branches reference `0x19F55`, `0x19F7A`, and `0x19FA2`. The 23-byte queue is traced to USB endpoint `81` through `08026FE0` → queue worker → `08029A58` → `0802AA58`. See [simagic-analysis.md](simagic-analysis.md) and `work/simagic/zeus-report-packing.c`, `zeus-modes.c`, and `zeus-usb-send.c`. Confidence is high for the bundled code behavior. Live control frames now establish full USB delivery, and passive report 02 indicates mode 1 under the recovered schema; the live firmware revision differs from the bundled revision, as documented in [zeus-status-report.md](zeus-status-report.md).

The reference parser `scripts/zeus_report_decode.py` decodes usage numbers without inventing physical names. `scripts/verify_zeus_decoder.py` checks layout against the recovered descriptor, all 120 individual bit positions, field boundaries and rejection of incorrect lengths/report IDs. Those parser checks are synthetic. The compiled dev2 adapter additionally replays 99 distinct measured wheel frames; its [verification report](firmware-candidate-dev2.md) distinguishes emulated behavior from untested Sigma/PS5 hardware behavior.

## Smallest defensible change

1. **Register one additional HID driver instance for `3670:0804`.** Sigma's registration helper at S `08023AF0` has 16 slots; startup currently constructs the hub plus four application classes. Dev2 adds a Zeus instance with its own state/vtable through the same mechanism, retaining the existing base, pedal, shifter and handbrake registrations. Its 156-byte state occupies a 256-byte reservation obtained by lowering the original heap limit; stack bounds remain unchanged. Code is appended after the complete original image. This placement is supported by startup/heap evidence and offline tests; bootloader acceptance of the extension remains unknown.
2. **Use the existing HID enumeration and interrupt polling path.** Full USB control routing is observed on the Mac. Poll helper S `08024A8C` delivers up to 64 bytes to the driver's callback at vtable offset `0x40`. Dev2 gates VID/PID and interface 0, validates report ID and exact length, and decodes ID 1. No vendor initialization command was needed for the observed streams; actual Sigma enumeration and routing remain untested.
3. **Store Zeus controls separately.** Dev2 keeps the button state, two raw axes, timestamp and connection state outside the base parser's globals. It ignores unrelated report types and clears controls on detach or timeout. The timeout is a provisional 250 timer ticks, chosen with the approximately 5-ms observed Mac report cadence in mind. Firmware timer code indicates millisecond intent, but Sigma's actual timer frequency and USB recovery behavior remain unmeasured; the timeout is a policy to validate on hardware.
4. **Merge at the console report builder, S `0802A8B4`.** It writes the report at RAM `20000C88`: controls at offsets 5–7, steering at `+2B/+2C`, pedals at `+2D..+32`, shifter `+33`, handbrake `+34/+35`. Apply the captured Zeus control mapping while retaining independent base steering and pedal/shifter/handbrake data. The base callbacks rewrite shared control state, so writing only to those globals in the Zeus callback would be vulnerable to later base packets. Ensure a changed Zeus state triggers the existing report-send path and that releases propagate.
5. **Handle encoder semantics explicitly.** Determine whether each rotation is a pulse, persistent bit, or vendor counter. Convert to the corresponding console event without repeat/stuck states. The 120 declared button usages cannot all be represented simultaneously by the existing console report; choose a user-reviewed button map after observing the actual controls. RGB, display telemetry, touchpad and firmware-update services are separate from this basic input-support proposal.

Changing the `0A04` comparison to `0804` is specifically unsuitable: that class copies raw data for the handbrake and its consumer reads a different field. Enlarging base wheel-type cases alone is also insufficient for a separately enumerated USB wheel.

## Integrity and implementation gates

The AES-256-CTR transformation is reproducible and reversible with byte-exact round trips. However, **the converter bootloader's acceptance checks are not in the supplied image**. The PC updater sends the resource unchanged and does not establish device-side checksum/signature behavior. The final opaque Sigma bytes remain unclassified. Original PE has no embedded Authenticode table, which is a different question from firmware authentication.

Before constructing a flashable patch, obtain the bootloader code or equivalent vendor format evidence that establishes: actual encrypted/plaintext extent, trailer semantics, checksum/signature range and algorithm if any, allowable image size, destination map and failure/recovery behavior. A read-only bootloader dump would be useful if the user's hardware permits it; do not disable readout protection, erase or flash to obtain it. Exact chip marking and hardware revision would help select a legitimate read-only method. No such hardware access was attempted.

## Exact additional observations

Offline files establish the format mismatch and integration points. Live captures additionally establish USB identity, full control delivery and the primary paddle/seven-way mappings. The remaining observations below concern incomplete descriptor fields, other controls, behavior when hosted by Sigma, and bootloader acceptance.

1. **Complete descriptor/topology capture:** VID/PID and the HID report descriptor are already captured from the powered Zeus through Xtend/KVM; the live report descriptor matches the bundled Zeus firmware. A separate `3670:0607` Dash4 device is also observed. Full configuration/interface/endpoint descriptors and exact installed firmware versions remain to be captured. On this Mac, the read-only HID helper is:

   ```sh
   work/tools/python/bin/python scripts/capture_hid_descriptors.py \
     reports/zeus-live-hid.json
   ```

   It reads IORegistry only, omits serial numbers and sends no USB commands. The later observations supersede the initial disconnected observation; see [Sigma and Zeus live identity](sigma-live-observation.md). This helper does not capture full configuration descriptors or traffic, so a descriptor/packet capture is still needed for those fields.

2. **Remaining labeled controls:** shift paddles, both seven-way switches and analog ranges are recorded. Capture the remaining ordinary buttons and each encoder one detent in each direction; explicitly label left/right analog paddle identity. Preserve raw report ID, length, complete bytes and monotonic timestamps. Reconnect, loss-of-connection and simultaneous physical inputs still need observation.
3. **Initialization and routing trace:** capture enumeration and the first several seconds with SimPro closed, then the same sequence with SimPro opened. Repeat with the actual base connection/power arrangement and, where supported, the base detached/standalone wheel arrangement. Capture the wheel, base and any display as distinct USB addresses. During labeled inputs, specifically determine whether USB ID 1 bytes 1–17 change or remain zero while its vendor tail changes. This distinguishes full USB controls from the hybrid routing behavior recovered above. Record connection/power transitions as well as descriptors. If hybrid routing is active, establish a supported USB-control-mode selection sequence or capture the alternate base/CAN FD path before implementing the proposed USB-only parser.
4. **Sigma baseline:** record exact Sigma hardware revision, installed base/wheel versions, and what works with base+pedals alone versus after attaching MagLink. If possible capture the Sigma-host↔wheel bus during enumeration with a USB analyzer; a PC-side wheel trace alone cannot show Sigma rejecting it.
5. **Integrity evidence:** provide a permissible read-only dump including the converter bootloader, or its verified packaging/validation specification. This is needed to establish installability, independently of input mapping. The normal application's examined commands do not provide bootloader readback; [sigma-readback.md](sigma-readback.md) records the evidence and identifies why update-entry is not a read-only discovery step.

## Validation achieved and remaining

Completed locally: native arm64 REA/Ghidra setup; original/resource hashes; independent PE inventory; recovered AES code/constants; Sigma and Zeus decode/round-trip; coherent separate Cortex-M mappings; USB descriptors; Sigma class/poll/parser/aggregation paths; semantic comparison with 1.0.20; offline Zeus parser checks.

The final [verification record](verification.json) confirms unchanged originals, 750 Sigma resource slices, 2,847 extracted SimPro members, all three decoded artifact hashes, and the synthetic decoder checks. Previous byte-exact transform round trips are recorded in the corresponding transform manifests.

The current implementation reserves state within the original declared heap and appends code without overwriting existing data. Captures 003/005/007/008 establish full USB control delivery in the user's setup, right/left shift usage 13/14, both seven-way direction/center maps, and both analog ranges 0–127. Dev2 incorporates those observations and passes 16 finite emulator checks, including 99 measured-frame replays. Sigma normal-mode identity and its matching report descriptor are also observed. See [dev2](firmware-candidate-dev2.md), [live wheel evidence](zeus-live-observation.md), and [Sigma observation](sigma-live-observation.md). The earlier dev1 and idle-only recordings are retained as historical artifacts.

Remaining: initialization/disconnect behavior on Sigma, remaining ordinary-button/encoder assignments, game-specific axis mapping, acceptance of the extended image, bootloader integrity/recovery, and hardware/PS5 regression testing. No claim is made that the candidate is a functional installed firmware patch.

The user reports an unmarked Sigma and no ST-Link. Additional stock-updater analysis and older distributor-linked packages do not resolve acceptance: the updater enters erase/reset before resource validation and supplies no demonstrated backup/preflight function. [Recovery options](sigma-recovery-options.md) records the evidence and the vendor information that could resolve this without a probe.

The user's [component-side and rear photos](sigma-hardware-photos.md) confirm the N32G455REL7 marking and locate main-board P1/CN3. [Official-source comparison](sigma-n32-code-match.md) independently supports N32G45x SDK lineage, and the photo-bound [geometry verification](sigma-n32-hardware.md) places unchanged dev2 within the same 93 flash pages as stock. Factory BOOT/protection documentation supplies no general flash-dump command or proof of Sigma recovery. Connector signal assignments and protection state require measurements; the user has no multimeter or debug probe.
