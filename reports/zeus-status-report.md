# Zeus periodic USB status report

**Report 02 contains a communication-mode field. Its value is 1 in all three completed recordings, matching USB mode in the bundled Zeus firmware.** Capture 003 independently proves that ordinary shift and analog inputs reach USB in the user's current KVM topology. No USB enable request is needed to explain those observations, and none was sent.

The schema was recovered from a newer bundled image, not dumped from the connected wheel. Its application to the live status frames is a strong, code-backed cross-version interpretation. The positive control observations do not depend on that interpretation.

## Sources and scope

| Source | SHA-256 | Scope |
| --- | --- | --- |
| Z: `work/simagic/zeus-formula-decoded.bin` | `85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a` | Decoded bundled Zeus A1.1.15 image; file offset = VA − `0x08021E00` |
| `reports/zeus-live-input-001.jsonl` | `fedc9a978cbb7b4a5910f016f281fc90df203388fb85abed2bae0e8221364d65` | 176 successful report-2 callbacks |
| `reports/zeus-live-input-002.jsonl` | `e0cb0221a5ea6e1afb440f9b464e3a070e04c77f6aebe56605326a18ea274b11` | 588 successful report-2 callbacks |
| `reports/zeus-live-input-003.jsonl` | `2b5c448434f5cd68c39c5a15c564738f4e668cb8b51dd910dc4ca67e2705b981` | 129 successful report-2 callbacks and labeled positive control observations |

Every report-2 frame in these captures is byte-identical. The live IORegistry observation identifies bcdDevice `011A`; Z declares `011F`. Their 164-byte report descriptors match byte-for-byte, hash `1a50f848ae66c8b3f5d5841ba39ab34d84815b90d3d198c5d7e70dfb9b7f123d`. Neither descriptor equality nor compatible status fields proves identical firmware. See [zeus-live-observation.md](zeus-live-observation.md) for the IORegistry artifact hash and control results.

## Producer and framing

In Z, **`0x080273FC` / file `0x55FC`** builds a status message from the device state at RAM `0x2000B298`. Except for the distinct legacy state-3 path, it passes **device+`0x60`** to encoder **`0x08030C7C` / file `0xEE7C`**, or alternates with encoder `0x08030DAC` when device+`0xF0` is nonzero. The captured `0x0401` message matches the first encoder. Delivery uses `0x08026FE0`, whose state-1 and state-9 paths both permit USB. Receipt of report 02 alone therefore does not identify the mode; its decoded field does.

The encoder initializes the ten-byte framing header, protobuf-encodes its structure using descriptor VA **`0x0803DD84`**, then invokes framer **`0x08028D98` / file `0x6F98`**. The latter zero-fills the destination, writes total payload length in big-endian order, and divides the payload into at most 54 bytes per 64-byte frame, with total-frame and one-based frame-number bytes. Confidence: high from producer and framer instructions.

| Offset within captured 64-byte report | Bytes | Code-backed interpretation |
| --- | --- | --- |
| 0–2 | `02 1E 88` | Fixed header bytes initialized by `0x08030C7C`; byte0 is HID report ID 2 |
| 3 | `FF` | Encoder's second argument; initialized from device+`0x20` by producer |
| 4–5 | `01 04` | Little-endian message code `0x0401` |
| 6–7 | `00 2D` | 45-byte total protobuf payload |
| 8–9 | `01 01` | One frame, sequence number 1 |
| 10–54 | 45 bytes | Protobuf fields; payload SHA-256 `e2f0f6d66c8698f9e5a97fdcd9f48a5cae83762265165c99e3944f2c3936a10d` |
| 55–63 | Nine zero bytes | Framer's zero-filled unused capacity |

The periodic worker **`0x08027498` / file `0x5698`** calls the producer every second invocation, with a 500-unit delay per invocation and an optional 500-argument callback. The captures show approximately 1020 ms between report-2 callbacks. Exact callback timing is measured at the Mac, including its scheduling and KVM effects; it does not prove a particular bus-level polling period.

Exports: `work/simagic/mapping/zeus-status-producer.c`, `zeus-status-pack.c`, and `zeus-status-schema.c`. Ghidra was run read-only against the existing Cortex-M/Thumb project.

## Proof that protobuf field 4 is the communication mode

The evidence chain is explicit; field meaning is not inferred from the observed value alone.

1. Initial status setup at **`0x080270E6` / file `0x52E6`** copies current device state+`0x04` to status mirror+`0x7C`. The load at `0x080270F6` and store at `0x080270FC` are in source bytes `63 68 04 F1 88 01 E3 67`.
2. The mode manager updates both fields on changes. At **`0x08023628` / file `0x1828`**, bytes `09 23 56 48 6B 60 EB 67` write **9** to both +4 and +`0x7C`, followed by the log identifying a change from USB to USB-and-CAN-FD mode. Its literal at `0x08023784` points to that string at `0x0803BCBD`. The return to USB writes **1** to both offsets at **`0x0802383E` / file `0x1A3E`**, bytes `C5 F8 04 A0 C5 F8 7C A0`, after setting r10=1 at `0x08023830`. Mode 4 is the CAN-FD path. See `work/simagic/zeus-modes.c` and [simagic-analysis.md](simagic-analysis.md).
3. Encoder argument1 is device+`0x60`. At **`0x08030CE6` / file `0xEEE6`**, `ldr r3,[r4,#0x1c]` reads device+`0x7C`; at **`0x08030CEA`**, `str r3,[sp,#0x4c]` copies it to **protobuf input structure+`0x1C`**, because the input structure begins at sp+`0x30`. Supporting bytes are `E3 69 1C A9 13 93`.
4. Descriptor word **`0x0803DD60` / file `0x1BF60`**, bytes **`10 11 1C 40`**, decodes under field iterator `0x08030EE4` to **field number 4**, input offset **`0x1C`**, size **4**. The iterator extracts tag bits2–7, offset bits16–23, and size bits28–31 for this single-word descriptor. The type byte is `0x11`. The full field table and reproducible extraction are in `work/simagic/mapping/zeus-status-schema.json` and `scripts/zeus_status_decode.py`.
5. Every captured status frame has bytes **`20 01` at report offsets33–34**: protobuf varint field4, value1. Thus the captured value matches the firmware's USB state, not its state9 hybrid value. Confidence: high for the static mapping; high but cross-version-qualified for the live interpretation.

The decoder records the first source JSONL line, source file offset, exact frame bytes and capture hash for each variant. For example, capture003's first status frame is at **line8 / file offset913**, elapsed31.420ms. These are source text-file offsets; offsets33–34 above are inside the hex-decoded 64-byte report.

## Other fields and remaining limits

| Protobuf field | Captured report offset | Value or representation | Traced source / interpretation |
| --- | --- | --- | --- |
| 2 | 10 | Nested 16-byte payload | Identity branch when destination is `FF`; device+`0x68` through +`0x74`. Contents retained without assigning serial-number semantics. |
| 3 | 28 | `0x0A010141` | device+`0x78`, copied from +`0x4C`; this is the field initialized to `0x0F010141` in bundled A1.1.15. The latter constant is at Z file`0x1634` / VA`0x08023434`, bytes `41 01 01 0F`, loaded by `0x0802333C`. **A1.1.10 is a plausible packed-version interpretation for the live value**, but the displayed software version was not read. |
| 4 | 33 | 1 | Communication mode, proven above |
| 6 | 35 | `0x02070000` | device+`0x84`, initialized from +`0x44`; avoid assigning product/profile semantics without its consumers |
| 7 | 40 | 64-bit varint | device+`0x88`; produced through `0x080296FC`, not decoded semantically here |
| 8 | 50 | `0x02070000` | device+`0x90`, initialized from +`0x48` |

No captured field has been proven to identify the active control preset, clutch mode, paddle-module type or physical MagLink Xtend topology. The existence of an alternate status encoder does not prove those meanings either. No guessed GetFeature, output-report, initialization or mode-change transaction was issued.

All observed report-2 values are consistent with USB mode across captures001–003. The earlier unchanged report-1 streams still lack reliable action timing; they must not be called evidence of broken controls or hybrid routing. Capture003 supplies the decisive positive ordinary-control observation.

## Reproduce

```sh
work/tools/python/bin/python scripts/zeus_status_decode.py \
  reports/zeus-live-input-001.jsonl \
  reports/zeus-live-input-002.jsonl \
  reports/zeus-live-input-003.jsonl
```

This writes `*.status.json` beside each capture and the extracted field-table JSON. It pins Z's hash, verifies complete unchanged captures and callback lengths/counts, and supports only complete one-frame `0x0401` payloads. Existing different output is refused. Tests checked the real mode1 frame, a synthetic mode9 field substitution, rejection of a truncated frame, and rejection of multipart framing. Synthetic checks validate the local decoder, not the wheel's response to commands.
