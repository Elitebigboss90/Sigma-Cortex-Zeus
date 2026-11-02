# Zeus USB observation on the Mac

Observed October 27, 2026, America/Los_Angeles. The user connected Zeus through a KVM. This report covers eight completed passive input recordings and the separate IORegistry descriptor observation. Capture 003 positively establishes ordinary USB shift and analog paddle inputs; captures 005, 007 and 008 identify both seven-way controls' directions and center clicks. No USB output/feature commands were sent by the capture program.

## Artifact identities

| Source | SHA-256 | Evidence scope |
| --- | --- | --- |
| `reports/zeus-live-hid-kvm.json` | `dae8cb7b86fbb294f22db4d8fc2b23fd4ab3387c49e1459ebd1f207340997776` | IORegistry metadata; observed at 2026-10-28 00:31:13 UTC, equivalent to October 27 17:31:13 PDT |
| `reports/zeus-live-input-001.jsonl` | `fedc9a978cbb7b4a5910f016f281fc90df203388fb85abed2bae0e8221364d65` | 4,658,684-byte completed recording, start/end records and 36,174 incoming callbacks |
| `reports/zeus-live-input-002.jsonl` | `e0cb0221a5ea6e1afb440f9b464e3a070e04c77f6aebe56605326a18ea274b11` | 15,576,970-byte completed recording, start/end records and 120,550 incoming callbacks |
| `reports/zeus-live-input-003.jsonl` | `2b5c448434f5cd68c39c5a15c564738f4e668cb8b51dd910dc4ca67e2705b981` | 3,397,454-byte completed recording, start/end records and 26,426 incoming callbacks |
| `reports/zeus-live-input-004.jsonl` | `86865e3d3eb5f2a6cefe9c5ae3c7ac4b54d79b4ef096baa2f69128dae8913879` | 7,603,940 bytes, 58,934 callbacks; excluded from mapping because the user said the sequence was performed incorrectly |
| `reports/zeus-live-input-005.jsonl` | `6c5d95ed41c909b750efc34004d071b0bf657942db3167757e8fd15638c277af` | 961,427 bytes, 7,503 callbacks; confirmed left seven-way sequence |
| `reports/zeus-live-input-006.jsonl` | `42cc3c3f4e034f050de74880b601ff13041489e7864a5c48213473295be1a5f7` | 590,105 bytes, 4,611 callbacks; no observed changes despite user confirmation; mapping deferred to successful capture008 |
| `reports/zeus-live-input-007.jsonl` | `01753493a346b8f168514b408337470e933b8c48028ca6279f5250ada567b900` | 1,396,787 bytes, 10,894 callbacks; confirmed left then right center clicks |
| `reports/zeus-live-input-008.jsonl` | `233b7cbda4c4d3e1d265cc343a4d309dbff8ec9a45b9e2f8069cb6ca588e5193` | 2,021,269 bytes, 15,758 callbacks; confirmed right seven-way directions |
| `work/simagic/zeus-hid_report.bin` | `1a50f848ae66c8b3f5d5841ba39ab34d84815b90d3d198c5d7e70dfb9b7f123d` | Report descriptor recovered from bundled Zeus A1.1.15 firmware |

The IORegistry observation identifies **Simagic Zeus Formula Steering Wheel**, USB, **VID/PID `3670:0804`**, and **bcdDevice `011A`**. Its 164-byte HID report descriptor is byte-identical to the recovered static descriptor. The bundled image declares bcdDevice `011F`; those raw version words differ. Their exact translation to the user's displayed firmware version has not been established. Matching descriptors do not imply byte-identical firmware.

## Completed capture 001

`scripts/analyze_zeus_capture.py` checks that the recording ends with a completed `end` event and that its count equals the number of parsed callbacks, then verifies lengths and calculates the following. Exact analysis and representative raw frames are in [zeus-live-input-001.analysis.json](zeus-live-input-001.analysis.json).

| Input report | Count | Actual callback length | Unique raw frames | Median interval | Min–max interval |
| --- | ---: | ---: | ---: | ---: | ---: |
| `01` | 35,998 | 23 bytes including ID | 1 | 4.999 ms | 0.041–10.669 ms |
| `02` | 176 | 64 bytes including ID | 1 | 1020.003 ms | 1018.927–1020.181 ms |

All callback results were success (`result=0`, input type 0). These are **host callback arrival intervals**, including OS/KVM scheduling effects. They are not direct USB bus transaction or endpoint polling measurements.

Every ID-1 frame had bytes 1–17 zero: Rx=0, Ry=0 and no pressed button usages. The vendor tail at bytes 18–22 was consistently `80 80 80 80 00`. Thus this capture contains **no observed control-state changes**. Its first valid callback arrived at 3.848 ms and its last at 180057.248 ms after the capture timer began. No matching physical action sequence has been confirmed for this first capture, so it does **not** distinguish an untouched wheel in USB mode from hybrid control routing, nor establish that paddles/buttons are broken or ignored.

All 176 ID-2 frames were identical. They were initially inventoried as opaque vendor payloads. The subsequent code-backed decoding in [zeus-status-report.md](zeus-status-report.md) identifies their communication-mode field as 1 (USB) under the bundled firmware schema. The exact bytes remain in the source and analysis JSON.

## Completed capture 002

The 600-second second recording was analyzed only after its final `end` event appeared. [zeus-live-input-002.analysis.json](zeus-live-input-002.analysis.json) records:

| Input report | Count | Actual callback length | Unique raw frames | Median interval | Min–max interval |
| --- | ---: | ---: | ---: | ---: | ---: |
| `01` | 119,962 | 23 bytes including ID | 1 | 5.000 ms | 0.010–20.084 ms |
| `02` | 588 | 64 bytes including ID | 1 | 1020.006 ms | 1017.926–1022.193 ms |

All callbacks succeeded. Report 1 again has Rx=Ry=0, no pressed usages, and vendor tail `80 80 80 80 00`; no control changes or nonbaseline segments appear. Its first report-1 callback was at 0.852 ms and last at 600022.777 ms. The user subsequently confirmed performing an earlier paddle sequence, but its timing relative to recordings 001/002 was ambiguous. More samples of the same uncorrelated state do not by themselves resolve the USB versus hybrid-routing question. The separately decoded vendor status is documented in [zeus-status-report.md](zeus-status-report.md), including its cross-version limitation.

## Completed capture 003: confirmed paddle actions

The capture was deliberately stopped after the user confirmed the fresh sequence; its final `end` record marks it complete (`stopped_early=true`, duration 131.527 seconds). [zeus-live-input-003.analysis.json](zeus-live-input-003.analysis.json) records 26,297 report-1 inputs, 83 distinct control states and 99 state changes. All callbacks succeeded. The report-1 callback interval was median 4.999 ms, range 0.020–13.566 ms. There were also 129 identical 64-byte report-2 inputs, median 1019.999 ms apart.

The exact capture prompt was: “The fresh capture is running now. Please repeat right shift three times, left shift three times, then each analog paddle separately, with gaps between groups, and reply when finished.” The user answered: “Finished the fresh sequence”. The confirmation, hashes and event locations are retained in [zeus-live-input-003.correlation.json](zeus-live-input-003.correlation.json). This is a labeled sequence correlation, not an automated identification of a paddle's physical side.

| Confirmed action | Observed report-1 field | First press times after capture start | Evidence |
| --- | --- | --- | --- |
| Right shift paddle, three times | HID Button usage **13**, report byte 4 mask `0x10` | 90.723, 91.683, 92.643 s | First press at JSONL line 18228 / file offset 2338161; raw frame `0100000010000000000000000000000000008080808000` |
| Left shift paddle, three times | HID Button usage **14**, report byte 4 mask `0x20` | 95.428, 96.398, 97.433 s | First press at line 19174 / offset 2459659; raw frame `0100000020000000000000000000000000008080808000` |
| First analog paddle | **Ry**, report byte 2, range 0–127 | First change 103.013 s | Remaining axes/buttons zero during this first axis sequence |
| Second analog paddle | **Rx**, report byte 1, range 0–127 | First change 104.198 s | First change at line 20937 / offset 2686904 |

Each shift press returned to the released state. The vendor tail remained `80 80 80 80 00` throughout. **Analog left/right sides remain unassigned**, because the confirmed prompt did not specify which analog side to operate first. No simultaneous clutch behavior, clutch bite-point processing, additional paddle modules or other controls were exercised.

Confidence is high for usage13=right shift and usage14=left shift in this wheel's current configuration, and for both analog inputs reaching USB. The live descriptor and positive changes establish that Sigma can receive these controls through the documented ordinary report format without a guessed vendor enable command in this observed topology. This does not demonstrate that Sigma recognizes the device, merges the reports correctly, or works on PS5; those are separate firmware and hardware checks.

## Confirmed seven-way controls: captures 005, 007 and 008

Capture005 requested the **left** seven-way Up, Right, Down, Left, then Center. The user answered: “Finished left switch in that order”. Five isolated press/release groups occurred in precisely that order. Capture008 requested the **right** seven-way Up, Right, Down, Left; the answer was: “Finished right directions in that order”. Its four isolated groups establish the right directions. The source hashes are in the table above; offsets below refer to the JSONL files, while report-byte offsets include the report-ID byte.

| Physical action | HID usage | Report byte / mask | Capture and first press time | Source line / file offset |
| --- | ---: | --- | --- | --- |
| Left Up | **44** | 8 / `08` | 005, 15.470 s | 3110 / 396986 |
| Left Right | **47** | 8 / `40` | 005, 16.974 s | 3412 / 435806 |
| Left Down | **46** | 8 / `20` | 005, 18.109 s | 3640 / 465072 |
| Left Left | **45** | 8 / `10` | 005, 19.519 s | 3923 / 501378 |
| Left Center | **43** | 8 / `04` | 005, 23.259 s | 4675 / 597962 |
| Right Up | **63** | 10 / `40` | 008, 62.426 s | 12543 / 1608185 |
| Right Right | **66** | 11 / `02` | 008, 64.026 s | 12864 / 1649355 |
| Right Down | **65** | 11 / `01` | 008, 66.076 s | 13276 / 1702255 |
| Right Left | **64** | 10 / `80` | 008, 67.966 s | 13656 / 1751059 |
| Right Center | **48** | 8 / `80` | 007, 39.634 s | 7965 / 1020393 |

Capture007 requested a **left center click followed by a right center click**; the user answered: “Finished both center clicks”. It records left usage43 beginning 36.219 s, brief additional usage46/47 transitions during the left interaction, another usage43 interval, then right usage48 at 39.634 s. The additional direction transitions are retained as observed but excluded from physical direction assignment. Left center43 is independently cleanly established by capture005. Confidence is high for the table in the current saved wheel configuration.

The three positive captures contain respectively 7,466, 10,841 and 15,682 report-1 callbacks, with median arrival interval 4.999 ms. Capture005 has 6 control states / 10 changes; capture007 has 5 states / 8 changes; capture008 has 5 states / 8 changes. All callbacks succeeded. Full raw frames, release/change times, per-event source offsets and user-confirmation provenance are retained in `zeus-live-input-005.correlation.json`, `zeus-live-input-007.correlation.json` and `zeus-live-input-008.correlation.json`. [zeus-physical-control-map.json](zeus-physical-control-map.json) consolidates the observed mapping with hashes and source locations. These recordings identify the physical controls, not their eventual console button assignments.

Capture004 is excluded because the user explicitly stated that the sequence was performed incorrectly. Capture006 contains 4,588 report-1 callbacks with one unchanged state and zero changes, although the user confirmed performing the right-control sequence. This action/capture discrepancy is preserved; its cause is unresolved. The successful labeled right sequence in capture008 supplies the mapping evidence. Neither capture004 nor capture006 is used to claim a broken switch, alternate routing, or a parser defect.

## Reproduction and next evidence

```sh
work/tools/python/bin/python scripts/analyze_zeus_capture.py \
  reports/zeus-live-input-001.jsonl
work/tools/python/bin/python scripts/analyze_zeus_capture.py \
  reports/zeus-live-input-002.jsonl
work/tools/python/bin/python scripts/analyze_zeus_capture.py \
  reports/zeus-live-input-003.jsonl
work/tools/python/bin/python scripts/analyze_zeus_capture.py \
  reports/zeus-live-input-005.jsonl
work/tools/python/bin/python scripts/analyze_zeus_capture.py \
  reports/zeus-live-input-007.jsonl
work/tools/python/bin/python scripts/analyze_zeus_capture.py \
  reports/zeus-live-input-008.jsonl
```

The analyzer reads files only. It refuses a missing final end record, a capture changing during its read, inconsistent lengths/counts, or an output file that differs from the new result. It records source hashes, descriptor comparison, per-ID length/timing/variant counts, raw axis ranges, all observed button usages, chronological control changes and segments departing from the initial numerical control state. It does not infer physical labels from usage numbers. A synthetic button-13 press/release recording verified segmentation and release handling; separate checks confirmed rejection of incomplete and count-mismatched recordings. These script checks are not hardware validation.

Remaining control evidence: seven-way rotary directions, other encoders, additional button labels and analog paddle sides/combined-clutch behavior. Both switches' four directions and centers are now observed. Factory defaults and the code/manual Up inference are documented separately in [zeus-mapping.md](zeus-mapping.md).
