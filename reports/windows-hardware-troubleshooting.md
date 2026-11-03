# Windows hardware troubleshooting — November 2, 2026

**Latest result:** the user reports dev10 installed and working on PS5: “alright dev10 works perfectly on PS5”. Dev10 is the working baseline for this setup. The entries below preserve the investigation and pre-installation checks; they are not pending instructions to repeat. No separate cold-start, reconnect or force-feedback test details were supplied with the success report.

The user reports flashing the renamed zeus-dev3 updater and seeing Completed. Sigma still detects the base. The wheel icon is absent. Windows joy.cpl sees Sigma, but Zeus buttons/paddles do not respond. Disconnecting the base and pedals and testing only the powered Zeus/Xtend through Sigma did not restore paddle input. These are user-reported results, not firmware readback.

Read-only present-interface enumeration independently observed Sigma `0EB7:0E07`, then both Sigma and directly connected Zeus `3670:0804`. The registry's stored `3670:B804` entry was historical, not a reason to expand the firmware's identity gate. Snapshots: `windows-hid-troubleshooting-001.json` and `002.json`. Initial CIM/PnP access was denied; native Configuration Manager/HID metadata access succeeded.

`windows-zeus-input-002.json` records 20 seconds with SimPro closed. It contains 4,001 ID1 buffers and 19 ID2 buffers. Measured active usages include 13/14 (paddles), 44–47 and 63/65, plus axis values 0–127. All Windows ID1 buffers have length 64; their first 23 bytes carry the known control layout, and their tails are nonzero. This establishes working PC delivery without SimPro initialization. It does not establish the actual interrupt transfer length on the USB bus or the wheel's routing after attachment to Sigma. Capture 001 was neutral and is not a labeled successful input test.

Dev3 rejects every input length except 23. A 64-byte callback reaching Sigma would therefore be discarded even with correct identity and controls. The Windows result makes this a concrete hypothesis, not a confirmed hardware root cause. Changing the PID is not supported by the live identity evidence.

`windows-usb-init-emulation-001.json` adds four successful CPU/RAM cases executing the real original Init, streaming configuration parser, address allocation and host enumeration with the bundled wheel descriptors. Only USB control transfers, delay and debug output are mocked. The SET_IDLE models return either zero or 5. Both initialize/poll-enable successfully. Actual physical control-transfer behavior remains outside the model.

The separate **zeus-dev5-diagnostic** candidate records native callback length/ID, Init result, binding, accepted input and a heartbeat in vendor input bytes 56–63. It also normalizes 64-byte callbacks to the original 23-byte parser prefix; original identity and report-ID checks remain. It fits 94 application pages. Six verification groups pass, including 125 distinct Windows control prefixes at both lengths with byte-identical dev3 output at bytes 0–55, failed-initialization logging, scheduling/wraparound, and state canaries. The PE package preserves all 749 non-firmware resources and native executable sections. Details and hashes are in `work/sigma/zeus-dev5-diagnostic/`.

This is a Windows diagnostic, not a hardware-tested fix or PS5 build. No agent firmware write occurred. A new installation requires explicit user instruction. Dev3 and all originals remain unchanged. The preliminary dev4 diagnostic artifacts are retained but not recommended; dev5 adds the length probe/normalization and is the candidate with completed diagnostic validation.

`windows-sigma-input-dev3-001.json` contains a brief input-only Sigma observation with no frames while the base was disconnected and no controls were arriving. That is consistent with the stock report-change send policy; it does not independently identify the installed image.

Windows analysis used portable Python 3.12.10 from python.org (python.exe Authenticode signature valid for Python Software Foundation) and PyPI wheels verified against their HTTPS metadata SHA-256: Capstone 5.0.6, Unicorn 2.1.4, pyelftools 0.32, pefile 2024.8.26, Keystone 0.9.2. These tools reside in ignored `work/tools/windows-analysis/`; no system installation was performed.

## Dev5 hardware observation

The user reports installing dev5 and supplies a Windows controller-properties screenshot showing the Fanatec/Sigma joystick with axis bars and no reported wheel-button response. The screenshot alone does not identify the firmware or establish axis changes versus dev3.

After reconnection to the PC, native input capture independently observed the dev5 marker/heartbeat: 50/50 frames in `windows-sigma-after-change-002.json` and 201/201 in `windows-sigma-dev5-reconnect-001.json`. All observed statuses were USB address 0, polling disabled, Init status FF (never recorded), native input length 0, report ID 0, accepted count 0. The firmware diagnostic code runs, but the instrumented Zeus Init routine has not been called in these observations. The report-length gate cannot explain this earlier dispatch/binding failure by itself. No physical Sigma-host traffic has been captured, and the current diagnostics do not record registry membership, descriptor-read status, or the identity seen by Sigma.

The first check after the screenshot found neither target attached to Windows; no input capture was written for that failed attempt. `windows-hid-after-change-001.json` records that transient absence. After the user confirmed connection, captures succeeded.

A further isolation test was requested: use the exact Sigma accessory port that had detected the base, disconnect base/pedals, keep Xtend externally powered, and cold-start Sigma with Xtend already attached. This distinguishes a port/startup-path issue before another firmware change is considered.

The user completed that test. `windows-sigma-dev5-coldstart-001.json` contains 50 dev5 frames, cycling through all 16 heartbeat values, still with address 0, polling disabled, Init FF and accepted count 0. The user clarified that the screenshot change meant two axis bars moved left, not a report of base/pedals failing. Raw input independently has first four axis bytes `(128,128,128,128)` and Rx/Ry `(0,0)`. The original builder zeros Rx/Ry before any wheel merge; dev5's heartbeat sends that baseline even without a bound wheel, explaining those two bar positions.

## Dev6 prepared for review

The new `zeus-dev6-diagnostic` preserves dev3 and the 23/64-byte normalization, adds a prologue trampoline around original descriptor helper `0802AA38`, and records the latest descriptor return and the VID/PID from the last successful read of at least 12 bytes. It checks whether host registry slot 6 still points to Zeus state and whether Zeus's vtable pointer matches. Alternating pages expose these fields alongside binding/input status. Identity can come from another device and can predate the last error; it is not a bus capture.

The original four-byte descriptor-helper prologue is pinned as `80 B5 8C B0` (PUSH then stack allocation) and reproduced in the trampoline. Nine CPU/RAM verification groups pass, including full enumeration and SET_IDLE models, failed and short descriptor reads, preserved callee registers/stack, all four registry/vtable flag combinations, 125 distinct control prefixes at both lengths, malformed-input rejection, timeout wraparound and canaries. Application size is 192,512 bytes, exactly 94 pages. The package preserves native EXE sections and all 749 other resources. Sources and manifests are retained in `work/sigma/zeus-dev6-diagnostic/`.

Dev6 has not been installed. Its updater SHA-256 is `d6c3bb2399993b3705492dc05c22cb8cc1531643d154521594d3d79eea2be683`. No agent firmware write occurred. Explicit user authorization remains necessary for this separate firmware write.

## Dev6 hardware result

The user subsequently reports installation. `windows-sigma-dev6-installed-001.json` independently contains 50 dev6 diagnostic reports, 25 per page, with all 16 heartbeat values. Wheel address/polling are zero, Zeus Init is FF, native input length is zero and accepted/ignored counters stay zero. The expected registry slot and vtable pointer both match. The cached descriptor identity is `05E3:0610`; the last device-descriptor request returned `0D`. The identity is from an earlier successful full read and does not identify the device involved in the failing request.

The primary [USB ID Repository entry](https://usb-ids.gowdy.us/read/UD/05e3/0610) identifies `05E3:0610` as a hub. Its physical location (Sigma, Xtend, or an intervening device) has not been isolated. It is not evidence for changing the Zeus VID/PID gate.

Original Sigma dispatch routine `0802A914` reads register `F8` at `0802A9B2`, masks the low nibble at `0802A9B6`, and returns result `0D` without its NAK/timeout retry handling. This matches the register/result convention of the upstream [USB Host Shield MAX3421E header](https://felis.github.io/USB_Host_Shield_2.0/max3421e_8h_source.html), which calls `0D` `hrJERR`. The [upstream enumeration source](https://raw.githubusercontent.com/felis/USB_Host_Shield_2.0/master/Usb.cpp) also returns an initial device-descriptor failure before driver selection; its driver-attempt JERR retries occur later. The reviewed Sigma `0802A400` path has the same early-return structure. This is code-lineage/behavior evidence, not electronic identification of the host-controller chip or proof of a faulty cable.

`sigma-dev6-pre-init-jerr-emulation.json` injects result 13 at the USB control-transfer boundary and seeds only the previously cached identity from the real report. Running original host enumeration performs one descriptor attempt, returns 13, leaves Zeus Init FF and preserves registry/vtable, reproducing discovery payload `5a61e30510060d03`. This explains why the driver never starts under this transport failure; it does not explain the physical source of the error.

A question is pending about the exact Xtend-to-Sigma data path (direct or with hub/KVM/extension). Further useful evidence is a controlled accessory-free baseline or a known-working accessory comparison on the same installed dev6, to determine whether the descriptor failure is specifically triggered by Xtend. No additional firmware has been prepared or written by the agent.

## Direct connection, empty-port baseline and nested-hub candidate

The user confirms Xtend's data cable connects directly to Sigma, with no intervening hub/KVM/extension. After disconnecting all Sigma accessories and cold-starting, `windows-sigma-dev6-empty-001.json` contains 50 dev6 frames: cached descriptor `1A40:0101`, return `00`, Zeus/registry flags intact. The primary [USB ID Repository entry](https://usb-ids.gowdy.us/read/UD/1a40/0101) identifies that device as a hub. Reconnecting only powered Xtend to Sigma without reboot produces `windows-sigma-dev6-xtend-after-empty-001.json`: cached descriptor `05E3:0610`, return `0D`, no Zeus Init, registry/vtable intact. This associates the additional hub and failure with Xtend's attachment. The precise physical ownership of the hubs is inferred from this controlled topology.

Original startup constructs only one native hub instance at `20002734`, via `0802BF94`. That constructor uses a 24-byte object, with vtable `080473B4`, host pointer at +4, USB address at +0E, poll deadline +10 and enable +14. Host registration supports 16 entries. Dev3–dev6 preserve one hub and add Zeus, leaving no unbound hub instance for the additional hub. A 24-byte second instance fits within the existing 256-byte reservation.

`sigma118-nested-hub-model-002.json` executes original constructors, hub Init, host dispatch and actual reset-complete event handler `0802BAF0`. The event handler masks the parent address to its low three bits at `0802BC3E`. Synthetic hub descriptors use the observed identities, while control-transfer behavior models SET_ADDRESS: afterward that device no longer answers at address zero. With one hub instance, fallback consumes the base HID object and subsequent descriptor reads return `0D`, matching the observed pre-Zeus failure. Adding a native hub instance binds Sigma hub address `41`, Xtend hub `4A`, then Zeus `11`, with polling enabled. This is a CPU/transport model, not physical proof. Preliminary model 001 used an unmasked parent in manually invoked child enumeration and is superseded; its fault is not hardware evidence.

The separate **zeus-dev7-diagnostic** candidate adds that second instance at `20005604` in registry slot 7, after Zeus slot 6. Its constructor clears diagnostic/extra-hub storage before constructing the new object. Combined reserved state occupies 204/256 bytes; image length is still 192,512 bytes/94 pages. Diagnostics retain descriptor and binding pages with version 7; discovery bit 1 now checks the additional hub registration rather than Zeus vtable.

Twelve offline groups pass on the actual dev7 image: constructor preservation, idle unbound hub polling, native two-hub reset-complete events through Zeus Init, native HID polling/merge for right and left paddles at 23/64 bytes, 125 distinct recorded control-prefix replays, ABI/canaries, malformed input and failure reporting. The nested model does not emulate physical hub interrupt packets, controller signal/timing, or nested-error recovery. Native EXE code and all 749 other resource payloads remain unchanged.

Dev7 is prepared but not installed. Updater SHA-256: `3487116c083da806a0194f1cd08af8d0b87e806c33b8b8bf9562b4cc4b34839d`. [Candidate instructions](../work/sigma/zeus-dev7-diagnostic/README.md). A new hardware test is required; no confirmed physical fix is claimed. No agent firmware write occurred.

## Dev7 result and measured Xtend hierarchy

The user reports installing dev7 and supplies a product picture showing the Xtend assembly/hub. `windows-sigma-dev7-installed-001.json` independently observes 51 dev7 reports. Zeus remains unbound (address 0, polling 0, Init FF, no accepted/ignored input); both registry checks match, but the cached identity remains `05E3:0610` and descriptor return `0D`. The picture does not establish the electrical hub count.

Read-only Windows SetupAPI/Configuration Manager ancestry inspection was added in `scripts/inspect_windows_usb_tree.ps1`, using Microsoft's documented [interface-details API](https://learn.microsoft.com/en-us/windows/win32/api/setupapi/nf-setupapi-setupdigetdeviceinterfacedetailw) and [parent-node API](https://learn.microsoft.com/en-us/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_get_parent). It does not open devices for reports or send USB commands. Instance paths/serial numbers are omitted; anonymous node tokens allow shared ancestors to be compared within one snapshot.

`windows-zeus-usb-tree-002.json` has Zeus `3670:0804` under three successive `05E3:0610` nodes, then `174C:2174`, then the PC root hub. `windows-sigma-zeus-shared-usb-tree-001.json` confirms the outermost Genesys node, ASMedia node and PC root are shared with Sigma's PC connection. The wheel branch contains two additional Genesys nodes. To rule out different PC socket wiring, the user unplugged Xtend and put Sigma's console/PC plug into the exact same PC socket. `windows-sigma-xtend-same-pc-socket-001.json` still has only one Genesys node before ASMedia/root. Thus the measured Xtend branch adds two hubs, requiring three converter-side hub instances including Sigma's internal hub. Dev7's two-instance model undercounted the physical chain.

The initial ancestry check `windows-zeus-usb-tree-001.json` was empty before the user completed moving Xtend to the PC; it is not the connected-device topology. `windows-hid-dev7-direct-wheel-001.json` again confirms live Zeus `3670:0804` and Sigma `0EB7:0E07`.

## Dev8 three-hub candidate

Dev8 adds two native 24-byte hubs at `20005604` and `2000561C` (slots 7/8), after the original six classes and Zeus slot 6. It uses 228/256 reserved bytes, with unchanged dev3 heap/stack bounds. Its added code still fits the same 94 application pages (192,512 bytes). The descriptor probe is reduced to return-status observation; hub-address telemetry replaces cached VID/PID in version-8 odd pages. The unused Init-attempt counter is removed; the length probe uses the callback's own object pointer, preserving its arguments and stack.

Twelve groups pass on the actual dev8 image, including native reset-complete processing through hubs `41/4A/53` then Zeus `19`, native paddle polling/merge at 23/64 bytes, correct hub-address telemetry, 125 unique control-prefix replays, original registrations, ABI/canaries and malformed input. `sigma118-xtend-three-hub-capacity-001.json` compares the actual dev7 and dev8 images with the same synthetic three-hub transport: dev7 binds `[41,4A,00]`, leaves Zeus unbound and reproduces the observed descriptor `0D`; dev8 binds `[41,4A,53]` and Zeus `19`, with no descriptor error. These are modeled control transfers, not a physical USB trace.

Dev8 is prepared and not installed. Its updater hash is `630e9a0af1fa7c1b20b2798e27503284eb9687b37bff648f0d9b00f31c7601d8`. Native updater code and all 749 other resource payloads remain unchanged. [Dev8 instructions](../work/sigma/zeus-dev8-diagnostic/README.md). Physical USB timing/polling, error recovery, detach/reconnect, coexistence and PS5 behavior remain unverified. No agent firmware write occurred.

## Dev8 hardware initialization succeeds

The user reports installation. `windows-sigma-dev8-installed-001.json` independently contains 529 dev8 reports over five seconds, with hubs `41/4A/53`, final-hub polling enabled, Zeus address `1A`, Zeus polling enabled and Init return `00`. Accepted input advances through all byte-counter values. Native input length is 23 in 503 even-page observations and 64 in one; the ignored counter advances by approximately one per second, consistent with the known management stream but its report IDs are not instrumented. The initial enumeration failure has been overcome. This does not yet prove mapped physical input or PS5 operation.

The last device-descriptor return remains `0D` despite successful Zeus polling. This field is global/cached and can represent a different request/device after Zeus binds. Do not use it alone to claim wheel enumeration failed. Actual Zeus address `1A` differs from the synthetic model's `19`, so at least the real address allocation order differs; another child may be allocated, but its identity has not been established.

All 529 initial frames have console button byte 6 = 0, hat nibble = 0, and Rx/Ry = 0; this was not a labeled input-action capture. Later control captures and the current candidate follow.

## Dev8 controls, coexistence regression and reconnect failure

`windows-sigma-dev8-controls-001.json` contains 2,231 reports with seven press/release cycles for each paddle, seven-way directions 0/2/4/6, and the left center alias. The user independently confirms paddle response in joy.cpl. Without a recognized base, the stock hat baseline is Up (0).

Connecting base/pedals after Xtend lost the base icon and checkmark; `windows-sigma-dev8-coexistence-001.json` has zero vendor axes. The user reports paddles still worked. Restarting with Xtend disconnected restored the base icon/checkmark. There is no separate pedal icon. `windows-sigma-dev8-base-pedals-first-001.json` has nonzero steering/pedal values and neutral hat 8; the separate brief motion capture did not record movements, so it alone does not prove working motion.

After attaching Xtend last, `windows-sigma-dev8-base-first-xtend-last-controls-001.json` contains 4,436 reports with steering 19,955–47,273, pedal channel 1 at offset 45 ranging 15–65,535 and channel 3 at offset 49 ranging 2,527–65,535. Channel 2 at offset 47 stayed 65,535. User confirms the base checkmark remains and wheel paddles work. This is an order-dependent workaround, not full coexistence validation. Finally, unplugging Xtend data for three seconds and reconnecting preserved the base but **paddles did not return**, per the user.

## Dev10 normal-report candidate

Native-code modeling identifies two mechanisms. The blind fallback enumeration pass allows an unrelated child to acquire the base driver, displacing later base/pedal instances. `sigma118-unmatched-child-claim-model-001.json` compares dev8 with the two-byte branch to existing address-only handling. The unrelated VID/PID in this model is synthetic, not a measured Xtend identity. Separately, native hub disconnect handling constructs a non-hub child address, which fails to release a nested hub's mapped address and leaves stale class state.

Dev10 keeps three native hubs, bypasses blind unmatched claiming, tracks parent/physical port only in its two owned hub objects, and releases the matching subtree plus orphaned class objects on the modeled disconnect event. Normal reports replace diagnostic fields/heartbeat. It uses 228 reserved bytes and 94 pages. Dev9 was an internal draft without subtree recovery; neither dev9 nor dev10 has been installed by the user at this point.

Actual-image offline results in `work/sigma/zeus-dev10/`: 18 emulator groups with 120 bit cases and 99 distinct captured frames; 56 exact non-neutral base-report comparisons; 52 connection-order cases; 30 repeated detach/rebind cycles across whole Xtend, inner hub and wheel-only levels, using two physical-port layouts. Native allocation/free, releases and reinitialization execute; base/pedal assignments and full baseline report survive, held paddle clears, and a new paddle report works after rebind. Synthetic descriptors, accepted USB control/OUT transactions and ordinary peripheral RAM remain model limits. Physical USB timing and PS5/force feedback are unverified.

Updater SHA-256: `df633e0b66b6aa236c94d4e075c547cc486c5c3cb10fbbd3dc90d579de883001`. [Instructions and test sequence](../work/sigma/zeus-dev10/README.md). Packaging verifies unchanged native EXE sections and 749 other resource payloads. No agent updater execution or firmware write occurred. After a user-chosen installation, test all-connected cold startup, concurrent Windows controls and Xtend reconnect before PS5.

## Dev10 PS5 success — user report

On November 2, 2026 (America/Los_Angeles), the user reports: “alright dev10 works perfectly on PS5”. This supersedes the pending-installation/PS5 status above and establishes successful PS5 use as reported by the hardware owner. It is not firmware readback or an itemized record of every control and reconnect case. No further firmware change is needed for the reported compatibility issue.

Preserve `work/sigma/zeus-dev10.zip` as the working package. ZIP SHA-256: `99a91fd2d7914650817c67a318b9926df9e4f8d1360a5a31450ffb3317b2a9ac`; updater SHA-256 remains `df633e0b66b6aa236c94d4e075c547cc486c5c3cb10fbbd3dc90d579de883001`. The ZIP, firmware, source snapshots and pre-installation verification manifests remain unchanged. No updater execution or device write was performed by the agent.
