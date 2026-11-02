# Zeus default mapping and transport selection

Continuation evidence for the Sigma 1.1.5 candidate. Analysis is static unless a separate live-capture report says otherwise. These defaults belong to the bundled Zeus A1.1.15 image; they do not establish the user's stored profile or installed version.

## Source identities

| Key | Source | SHA-256 |
| --- | --- | --- |
| Z | `work/simagic/zeus-formula-decoded.bin` | `85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a` |
| D | `work/simagic/3.2.3.13713/Simagic/Simpro3/modules/d9f16400-22a1-4f10-ac77-ffca4bce9e1c.dll` | `49946fee01349797b6e1e62d11ef8ad807526d283a4cf2bd8bcbc342c5845765` |
| M | `originals/Simagic-documentation/Zeus_Formula_User_Manual_EN.pdf` | `4bdea752fba8197cbabae642d880180d8c7b38f204b947c5113d467459cee19a` |

Z file offset = VA minus `0x08021E00`. Saved exports are under `work/simagic/mapping/`; Ghidra processed the existing Zeus project read-only and imported D into a separate project there. No Windows targets or firmware were executed.

## Factory input map recovered

Z factory initialization **`0x0802AEC4`** copies **162 (`0xA2`) bytes** from the pointer at `0x0802AFDC`, whose value is **`0x0803CD8F`**. The exact source range is **file `[0x1AF8F,0x1B031)`**. It writes that blob to configuration key 10 only when the stored factory-version marker differs or the factory-reset argument is 1. Source: `zeus-defaults.c`. Its nested length-delimited/varint encoding contains five input/lighting groups. The matching parser `0x08028330` invokes the firmware's protobuf decoder and `0x080251A8` applies each group's usage indices to runtime records. Confidence: high for bytes, record assignments, and the factory/default boundary.

`scripts/zeus_mapping_defaults.py` verifies Z's full hash, extracts the exact slice, and emits the complete byte-offset/field evidence in `work/simagic/mapping/zeus-factory-mapping.json`. It does not infer physical labels from record order.

| Record group | Default HID button usages, decimal | Code evidence |
| --- | --- | --- |
| Ordinary buttons, records 1–16 | **7, 6, 5, 4, 3, 2, 1, 9, 10, 11, 12, 15, 16, 17, 18, 8** | Type 3; `0x08029560` constructs 16 records; `0x080251A8` writes their `+0x24` usage fields |
| Seven-way 1, records 1–7 | **44, 45, 46, 47, 43, 31, 32** | Type 9; `0x08029418` constructs two groups of seven; assignments in `0x080251A8`; live capture identifies this group as left |
| Seven-way 2, records 1–7 | **63, 64, 65, 66, 48, 23, 30** | Same; live capture identifies this group as right |
| Four paired-direction/thumb encoders | **34/33, 38/37, 40/39, 35/36** | Type 4; four two-state records constructed by `0x08029994`; usage assignment in `0x080251A8` |
| Four face rotary encoders, incremental pairs | **19/20, 25/26, 28/29, 21/22** | Type 10; initializer `0x08029124`; preset list order is assigned first to `+0x134`, second to `+0x124` |
| Four face rotary encoders, absolute positions 1–12 | **67–78, 91–102, 103–114, 79–90**, respectively | Hardcoded in `0x08029124`, independently duplicated in D `dev_create_device_parts`, VA `0x180001CD0` |

The official [Zeus product page](https://simagic.com/pages/detail-simagic-zeus-formula-steering-wheel) lists 16 buttons, two seven-way controls, four rotary and four thumb encoders, consistent with those record counts. Counts alone do not identify which physical control is record 1, or which direction is the first field.

The separate type-2 group contains lighting values, not button usage indices. The factory blob also has a top-level field 4 with value 3; its exact semantic name is not established. Saved presets can replace the factory usage assignments. A candidate must therefore either document the default-profile dependency or expose a remapping table.

For face rotary encoders, a second code/manual inference identifies the incremental pair orientation: **19/20, 25/26, 28/29, 21/22 = counterclockwise/clockwise**. Hotkey handler `0x08023A7C`, while the seven-way center is held, changes rotary mode to 1 on state `+0x120` and to 0 on state `+0x130` (explicit `movs r2,#0` at `0x08023B74`). Mode 1 emits absolute-position usages in the report builder; mode 0 emits the relative usage at `+0x124` or `+0x134`. M page 10 documents clockwise selecting absolute mode and counterclockwise selecting incremental mode. Because `0x080251A8` assigns each factory pair's second value to `+0x124` and first to `+0x134`, that establishes the direction interpretation for the default relative pairs. Confidence: high inference; live physical encoder order and the user's profile still require observation.

### Seven-way semantics

Z `0x080292B0` maps four switch bit patterns `7`, `B`, `D`, `E` to the first four input records, pattern `F` to the fifth (center press), and quadrature transitions to the last two records. Thus **43/48 are center presses**, **31/32 and 23/30 are rotary directions**, and **44–47 / 63–66 are the four directional usages**. The rotary records get a counter value of 10; `0x08029484` decrements that counter once per report task and clears the two rotary bits after expiry. These are pulses stretched across report cycles, not persistent absolute encoder positions. Exact time is not inferred from a counter alone. Source: `zeus-seven-way.c` and previously retained `zeus-report-build.c`.

There is a code/manual anchor for **Up = 44 and 63** under factory defaults. Predicate `0x08023C18` checks direction fields `+0x10` and `+0x88`, the first direction of each seven-way control. The callback table at Z file `0x1C8A8` contains bytes `19 3c 02 08 41 3c 02 08 00 fa 00 00`, pairing that predicate with `0x08023C40`. The action logs `Paddle calibrate key action triggered.` via literal `0x08023D1C` and starts paddle calibration. M PDF page 9 describes pushing the seven-way controls upward for calibration and its illustration points to both controls. This was initially a high-confidence code/manual inference and is now confirmed by the labeled live captures below. Ascending usage number is **not** clockwise directional order. Export: `zeus-clutch-hotkey.c`; rendered documentary page: `work/simagic/mapping/zeus-manual-page9.png`.

### Observed physical seven-way mapping

The user confirmed left Up/Right/Down/Left/Center in capture 005, right Up/Right/Down/Left in capture 008, and left then right center clicks in capture 007. All ten physical meanings below are now based on live events in the user's current configuration, rather than numeric-order assumptions.

| Direction or press | Left usage | Right usage | Candidate interpretation |
| --- | ---: | ---: | --- |
| Up | **44** | **63** | Either usage can assert console hat Up |
| Right | **47** | **66** | Either usage can assert console hat Right |
| Down | **46** | **65** | Either usage can assert console hat Down |
| Left | **45** | **64** | Either usage can assert console hat Left |
| Center | **43** | **48** | Distinct center button usages; console aliases are a patch design choice |

Raw report offsets/masks: left Up/Right/Down/Left/Center are byte 8 masks `08/40/20/10/04`; right Up/Left are byte 10 masks `40/80`, right Right/Down are byte 11 masks `02/01`, and right Center is byte 8 mask `80`. Offsets include report ID at byte 0. These observations support mapping both switches to the same console hat; behavior for simultaneous opposing directions must be chosen explicitly by the patch, because the captures tested individual directions only.

| Capture source | SHA-256 | First-event source locations |
| --- | --- | --- |
| `reports/zeus-live-input-005.jsonl` | `6c5d95ed41c909b750efc34004d071b0bf657942db3167757e8fd15638c277af` | Left Up/Right/Down/Left/Center: offsets 396986/435806/465072/501378/597962 |
| `reports/zeus-live-input-008.jsonl` | `233b7cbda4c4d3e1d265cc343a4d309dbff8ec9a45b9e2f8069cb6ca588e5193` | Right Up/Right/Down/Left: offsets 1608185/1649355/1702255/1751059 |
| `reports/zeus-live-input-007.jsonl` | `01753493a346b8f168514b408337470e933b8c48028ca6279f5250ada567b900` | Right Center: offset 1020393; additional brief left direction transitions are not used to assign directions |

Exact raw frames, event times, releases and confirmations are in the corresponding `.correlation.json` files and [zeus-physical-control-map.json](zeus-physical-control-map.json). Confidence is high for this current configuration. Capture 004 was explicitly performed incorrectly and is excluded; capture 006 contains no changes despite action confirmation and contributes no mapping or hardware-failure conclusion. Seven-way rotation directions 31/32 and 23/30 still lack labeled live observations.

## Paddle defaults and axes

Z **`0x0802CF70`** initializes six potential paddle records, detects module variants through analog reads, then assigns their button usages. Source: `zeus-paddles.c`; high confidence for assignments. The later labeled live capture003 establishes usage13=right shift and usage14=left shift in the user's current configuration, as detailed below.

| Module behavior | Assigned usages | Relevant runtime record fields |
| --- | --- | --- |
| Standard single/dual module, group 1 | **13** | First record `+0x68` |
| Standard single/dual module, group 2 | **14** | Record at `+0x1B0`, usage field `+0x218` |
| Triple module, group 1 | **41**, **13** | Fields `+0x68`, `+0xF8` |
| Triple module, group 2 | **42**, **14** | Fields `+0x218`, `+0x2A8` |
| Push-pull variants | 13/14 and/or 41/42 depending on module and mode | Branches in `0x0802CF70`; do not flatten to one physical map |
| Clutch paddles in button mode | **27**, **24**, conditional on active module/index | Later assignments in `0x0802CF70`; selected module indices determine records |

USB builder `0x08025514(0)` takes report byte 1 from paddle-state field `+0x46`, and byte 2 from `+0x42`, when mode byte `+0x2F` is 0 or 2. When that mode is 1, corresponding digital activations set configured usage bits instead. These are the two Rx/Ry axes in the HID descriptor. Scaling, orientation, bite-point behavior and the installed module must be checked on the live wheel before overriding console clutch/axes. The build should not assume an inactive axis represents a calibrated full-range clutch.

**Live correlation:** `reports/zeus-live-input-003.jsonl`, SHA-256 `2b5c448434f5cd68c39c5a15c564738f4e668cb8b51dd910dc4ca67e2705b981`, contains the confirmed sequence right shift ×3, left shift ×3, then each analog paddle. Right shift sets report byte4 mask`0x10` (usage13); left shift sets mask`0x20` (usage14). Both Rx and Ry traverse0–127. The first analog was Ry and the second Rx, but the prompt did not specify analog sides, so their left/right physical assignment remains unknown. Exact pulse times, source offsets, raw frames and user confirmation are in [zeus-live-observation.md](zeus-live-observation.md) and `reports/zeus-live-input-003.correlation.json`.

## USB routing and initialization boundary

The previously recovered report task emits complete USB controls automatically when software state is 1. No additional vendor enable transaction appears in the traced state-1 builder or USB delivery path. This is not proof that every live firmware version and connection topology reaches state 1 unaided.

Z mode manager **`0x08023438`** initially chooses USB state 1 for power/topology modes 1, 2 and 3. Mode 4 first waits for USB configured state `+0xCE == 3`; successful USB enumeration selects USB state 1, otherwise state 4 (CAN FD). It then changes 1 to 9 when device-state `+0xF8 == 1`. Its loop performs the same transition and returns 9 to 1 after a GPIO condition, USB reinitialization and clearing `+0xF8`. Exact GPIO pin-to-connector semantics remain unproven; physical Xtend behavior must be observed.

The additional setter is Z **`0x08026C54`**, at instruction **`0x08026D84`**: dispatcher identifier **`0x80`** sets device-state `+0xF8` to 1. Other identifiers (`0x160`, `0x701`, `0x123`, `0x1F0`) are routed or handled differently. This routine builds transport-4 queue messages. Do not confuse this dispatch identifier with USB HID output report ID `0x80`, or send a guessed USB command. The traced code does not establish a supported host request that forces full USB controls while the base-present condition remains asserted.

Official manual **V1.0.1**, PDF page 12, explicitly shows MagLink Pro Xtend connected to the host PC and separately powered. PDF page 18 describes configurable button codes, paddle mode, presets, and viewing USB/CAN FD connection type. The file is preserved at `originals/Simagic-documentation/Zeus_Formula_User_Manual_EN.pdf`; its exact hash, size and vendor provenance are in `work/simagic/mapping/zeus-manual-manifest.json`. The [vendor-linked PDF](https://cdn.shopify.com/s/files/1/0764/6756/8943/files/Zeus_Formula_User_Manual_EN.pdf?v=1779442382) was obtained from the product page above. Neither source establishes the live mode of this particular setup.

## Implementable candidate boundary

Use the existing strict 23-byte report-ID-1 decoder and a separate Zeus state. The default map above now supports concrete, configurable usage assignments; it does not justify silently equating button record number with HID usage. Main shift candidates 13/14 are supported by initialization code. Map the verified live seven-way directions into the console hat, and use a table for selected console button usages. Preserve base steering, pedal data and force-feedback paths.

An all-zero axes/button region alone cannot distinguish an idle USB wheel from hybrid routing. Do not infer failure from one idle report or attempt an undocumented mode command. The subsequent live capture003 proves ordinary controls reach USB in the current KVM topology. The periodic vendor status independently matches USB state1 under the traced bundled schema; see [zeus-status-report.md](zeus-status-report.md) for the cross-version qualification. These artifacts establish defaults and implementation constraints; they are not a Sigma flashability or PS5-validation claim.
