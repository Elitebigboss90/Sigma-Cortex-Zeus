# Simagic Zeus Formula analysis

Subsequent live captures now confirm USB control delivery, shift paddles and both seven-way maps in the user's setup. See [live observations](zeus-live-observation.md), [physical mapping](zeus-mapping.md), and the [current Sigma candidate](firmware-candidate-dev2.md). Static-only limitations below describe their original evidence scope; the live report records which questions have since been resolved.

Analysis date: 2026-10-27 (America/Los_Angeles). Target specified by user: Zeus Formula connected through MagLink Pro Xtend; Sigma patch target remains 1.1.5. Windows executables/DLLs were inspected statically, never executed. All derived files live outside the extracted package directory.

## Evidence identities

| ID | Source | SHA-256 |
|---|---|---|
| S0 | `originals/SimPro 3.2.3.13713/SimPro-V3.2.3.13713-072a9e42-Setup.exe` | `e8d2fd8f27b008d009b0792b44cf26ce6f9ab8ca7efdb81d724633a6d500647d` |
| S1 | `work/simagic/3.2.3.13713/Simagic/Simpro3/bin/simpro3.exe` | `fa0505afc50f2f40311b8a2bff7c945ff32af39dea86f0d110ac4f49f4026192` |
| S2 | `work/simagic/3.2.3.13713/Simagic/Simpro3/modules/d9f16400-22a1-4f10-ac77-ffca4bce9e1c.dll` | `49946fee01349797b6e1e62d11ef8ad807526d283a4cf2bd8bcbc342c5845765` |
| S3 | `work/simagic/3.2.3.13713/$APPDATA/Local/Simagic/Simpro3/firmware/wheel/zf/ZeusFormula_App-A1.1.15.13445-eb889282.sfu` | `571535e07edc9efb8c7403eecf60caf861631ae9bf312a2755acc4d4e26b7e7f` |
| S4 | `work/simagic/zeus-formula-decoded.bin` | `85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a` |

S0 was retrieved from the official [Simagic download page](https://simagic.com/pages/download-center), through `https://service.simagic.com/software/websiteDownLoad` with the vendor-page Referer/Origin. The redirect supplied the retained filename. See `reports/simagic-download-manifest.json`, `work/simagic/download-headers.txt`, and the complete package inventory. The installer is an NSIS package containing native programs, configuration, and `.sfu` firmware. S1 and S2 are native x64 PE files with no CLR directory.

## SFU packaging and product identity

S3 is 123,936 bytes. These are established header fields or explicitly marked interpretations:

| Offset | Bytes/value | Interpretation and confidence |
|---|---|---|
| `0x00` | `SIMPROSFU100` plus zero terminators | Magic; high. S1 `0x1405786A2` compares 13 bytes. |
| `0x0E` | `40 00` | Format selector `0x40`; high. S1 `0x14057877D..0x1405787CB` branches between 0 and `0x40` header handling. |
| `0x10` | `ZeusFormula_App\0` | Target name; high. |
| `0x20` | `1.1.15\0` | Package version string; high. It does not establish the user's installed wheel version. |
| `0x30` | `E0 E3 01 00` | Declared content length 123,872; high. Equals this file's size minus 64. S1 `0x140578736..0x14057874D` bounds it against remaining file bytes. Other SFUs can contain up to 31 further padding bytes. |
| `0x34`, `0x38` | `00 00 07 02` twice | Product code `0x02070000`; high correspondence with S2 metadata; the distinction between these two fields is unresolved. |
| `0x3C`, `0x3E` | `04 08`, `70 36` | PID `0x0804`, VID `0x3670`; high, corroborated by S4's USB descriptor. |
| `0x40` onward | Encoded payload | AES-256-CTR transformation established below; high. |

REA function Evidence `ev_7e4f0c970e986f7a65b344faaa83345a703615d40c50dd326b4486d2f9168336`, saved in `work/simagic/zeus-module-info.json`, decompiles S2 `dev_get_module_info` at VA `0x1800016E0`, file offset `0xAE0`. It writes product code `0x02070000` at returned-structure offset `0x18`, then copies the exact module UUID, `wheel`, `Zeus Formula`, and `ZF`. The product-code write is VA `0x18000172D`, bytes `48 C7 40 18 00 00 07 02`. This code is a product-family identifier, separate from USB VID/PID.

## Recovered transformation: AES-256-CTR

This identification comes from executable code, not entropy:

- S1 `0x140578A22..0x140578B1A` initializes a 32-byte key with byte MOV immediates: `2037df2888ab45f7841178e25d25998c99aa34774383ee922234129833833284`.
- S1 `0x140578B22..0x140578B9A` initializes the 16 bytes actually used as the counter: `343413991235ddf3393899a1aa843299`. More initialized bytes follow, but the initializer copies only 16 bytes to context offset `0xF0`.
- Initializer `0x140B7FC80` calls key expansion `0x140B806D0`; the latter expands 8 words to 60 words. Cipher `0x140B80620` performs 14 rounds with the last round omitting the intermediate mix step. S-box at VA `0x1414A0DC0` / file `0x149FBC0` starts `63 7C 77 7B F2 6B 6F C5 30 01 67 2B FE D7 AB 76`; round constants at VA `0x1414A0FC0` / file `0x149FDC0` are `8D 01 02 04 08 10 20 40 80 1B 36`.
- CTR routine `0x140B7FD10` encrypts the 16-byte counter, increments from byte 15 backward with carry, and XORs the resulting stream into the buffer. This is standard big-endian AES-256-CTR.

`work/simagic/crypto-focused.c`, `sfu-parser.asm`, and `main-focused.c` preserve the code evidence. The focused native import had no global analysis; inferred C types and signatures are provisional, while instruction bytes/control flow and constants are the primary evidence.

Reproduce with:

```sh
work/tools/python/bin/python scripts/simagic_decode.py \
  'work/simagic/3.2.3.13713/$APPDATA/Local/Simagic/Simpro3/firmware/wheel/zf/ZeusFormula_App-A1.1.15.13445-eb889282.sfu' \
  work/simagic/zeus-formula-decoded.bin --offset 64
work/tools/python/bin/python scripts/simagic_inspect_zeus.py
```

The script derives the key and counter directly from the pinned S1 instruction bytes, records each source offset, transforms S3 byte range `[0x40,0x1E420)`, and verifies a byte-exact CTR round trip. Output S4 is 123,872 bytes. The same recovered transform decodes Sigma's `IDR_APP_FILE`; its separate transformation manifest is beside `work/sigma/1.1.5/sigma-decoded.bin`.

The inspected SFU loader validates minimum size, magic, declared length, format, and recognized product type. It decrypts some legacy device types on the host; many newer type enums bypass that host-decryption branch. Applying the transform for analysis does **not** establish that the official updater sends Zeus plaintext. No signature or checksum verification appears in this bounded loader function. Device-side verification is unresolved.

S4 starts with a 512-byte region preceding the vector table. At `0x08` is `0x0001E1D0`; at `0x0C` is `0x4C0761BE`; bytes `[0x10,0x20)` are `6e63c0d6fcc19582d037feaeda81e295`. Their integrity semantics are unknown. Neither standard zlib CRC32 nor MD5 of the candidate image `[0x200,0x1E3D0)` matches these fields. Sixteen bytes of `FF` follow that candidate image. These observations do not identify a signature or a checksum algorithm. CTR round-trip success proves reversibility, not authenticity.

## Processor and memory mapping

High-confidence Cortex-M family, little endian, Thumb code. Exact MCU part and physical memory capacity remain unknown.

- S4 vector table at file `0x200` starts `00 00 02 20 1D 69 02 08 65 69 02 08 23 23 02 08 ...`: initial stack `0x20020000`, reset vector `0x0802691D`, Thumb reset entry `0x0802691C`.
- The mapping is **S4 offset 0 → VA `0x08021E00`**, hence vectors at `0x08022000`. At file `0x4B1C` / VA `0x0802691C`, a coherent reset routine copies `.data`, clears `.bss`, calls initialization and main, then loops. The common default handler at file `0x4B64` / VA `0x08026964` is `FE E7` (branch to self).
- Independent pointer corroboration: file `0x8F30` contains `6C CD 03 08`, pointing to `Simagic Zeus Formula Steering Wheel` at file `0x1AF6C` / VA `0x0803CD6C`. File `0x1934` points to the boot-version string at VA `0x0803BBC8`; multiple pointers reference the USB device descriptor VA `0x0803CC14`.
- Reset literals at VA `0x08026950..0x08026960` name `.data` source `0x0803E548`, destination `0x20000000..0x20001C88`, and `.bss` ending at `0x20010ABC`. These are observed application ranges, not complete physical-memory proof.

Saved Ghidra project: `ghidra/zeus-firmware.gpr`, language `ARM:LE:32:Cortex`, explicit Thumb context and reset/vector seeds from `scripts/SimagicSeed.java`. A 128-KiB uninitialized SRAM block is an analyst coverage model. REA's unsupported generic raw ARM profile was not used. See `work/simagic/zeus-initial.c` and `zeus-ghidra.log`.

## USB identity and input reports

Established static USB descriptor, S4 file `0x1AE14` / VA `0x0803CC14`:

```text
12 01 00 02 00 00 00 40 70 36 04 08 1F 01 01 02 03 01
```

This declares USB 2.0, control endpoint size 64, VID `3670`, PID `0804`, `bcdDevice=011F`, and one configuration. It is distinct from the older base VID/PID and from product code `02070000`.

Configuration at file `0x1ADE8` / VA `0x0803CBE8` has total length 41, one HID interface, interrupt IN endpoint `0x81` and OUT endpoint `0x01`, each max packet 64 and interval 1. HID report descriptor length is `0xA4` (164), stored at file `0x1AE28` / VA `0x0803CC28`.

The control handler at VA `0x0802A7E0` handles descriptor type `0x22` and bounds the returned length to `0xA4`; descriptor type `0x21` is bounded to 9. This links the recovered report descriptor to executable USB handling. `work/simagic/zeus-initial.c` preserves the handler.

| Report ID | Kind | Declared total bytes, including ID | Declared contents |
|---|---|---:|---|
| `01` | Input | 23 | 2 × 8-bit Rx/Ry axes; 120 button bits; 32 vendor bits; 1 × 8-bit vendor field |
| `02` | Input | 64 | 63 vendor bytes |
| `F9` | Input | 64 | 63 vendor bytes |
| `80` | Feature and Output | 64 each | 63 vendor bytes |
| `F1`, `F0` | Feature | 64 each | 63 vendor bytes |

For ID `01`, byte 0 is the ID, bytes 1–2 are Rx/Ry (declared logical range 0–127), bytes 3–17 are buttons 1–120, bytes 18–21 are vendor bitfields, and byte 22 is a vendor byte. This is a descriptor interpretation, not a measured on-wire trace or a physical-button map. It does not by itself assign the two axes to specific paddles. Report IDs `02`/`F9` must not be interpreted as ordinary button data merely because they share the endpoint.

`scripts/simagic_inspect_zeus.py` reproduces the field interpretation and exact descriptor slices; `work/simagic/zeus-evidence.json` records per-item offsets/bytes, hashes, and bit positions.

### Executable report construction and delivery

S4 initialization `0x0802333C` installs callback `0x080264A5` (Thumb) at device-state offset `0x134`; literal `0x08023430` is `01 00 05 00`, initializing queue/report delay halfwords to 1 and 5. The report task at VA `0x08027F98` invokes that callback, calls `0x080298E6` to age control counters, and delays by the value at device-state offset `0x3A`, default 10 when zero. The time unit is not established. The separate transport queue task at `0x08028028` uses offset `0x38`, default 1. See `zeus-dispatch.c`, `zeus-report.c`, and `zeus-report-build.c` under `work/simagic/`.

The callback at VA `0x080264A4` / file `0x46A4` branches on state offset `+4`: state 1 calls `0x08025514(0)`, state 9 calls `0x08025514(1)`, and state 4 calls `0x08025F54()`. The following behavior is high-confidence code evidence, not a hardware observation:

| Software state | Control packing | USB ID `01` behavior |
|---|---|---|
| 1 | `0x08025514(0)` zeroes 23 bytes, sets byte 0 to 1, and packs configured axes/buttons | Full 23-byte control report |
| 9 | `0x08025514(1)` packs axes/buttons into a separate 20-byte transport-4 message with identifier `0x200` | Sends 23 bytes with axes/button bytes 1–17 still zero; vendor tail bytes 18–22 remain populated |
| 4 | `0x08025F54()` constructs the 20-byte transport-4 message | This callback does not queue the 23-byte USB control report |

The 23-byte queue call is VA `0x080256F4` / file `0x38F4`, bytes `00 22 17 23 11 46 00 93 01 20 0A AB 01 F0 6E FC`: `0x08026FE0(1,0,0,packet,0x17)`. The builder uses configuration-derived usage indices, packs `(usage-1)` LSB first, and writes axes from state fields `+0x46` and `+0x42` when their selected mode is analog. Alternate settings map those controls to button usages. Thus descriptor usage numbers alone cannot determine the user's physical mapping. Bytes 18–21 copy four control-state bytes, including a low nibble and direction/mode flags; byte 22 tests device-state `+0xF4 == 2`. Their complete physical semantics remain unresolved. See `work/simagic/zeus-report-packing.c`.

Transport-1 delivery is traced through queue builder `0x08026FE0`, worker `0x08028028`, and `0x08029A58`. The latter invokes a callback initialized at RAM `0x20000884`: its flash initializer at file `0x1CFCC` is `59 AA 02 08`, pointing to `0x0802AA58`. That routine checks USB state `+0xCE == 3`, then calls `0x08032556` with endpoint `0x81`, payload and actual length. This ties the 23-byte builder to USB IN. See `zeus-queue-send.c` and `zeus-usb-send.c`.

### Communication modes

The mode names are now tied to executable branches in S4 `0x08023438`, not inferred solely from strings:

- At VA `0x0802359C` / file `0x179C`, bytes `09 23 76 48 6B 60 03 F0 01 FF` set state `+4` to 9 and log the string `on base, COMM_TYPE_USB_AND_CANFD` through literal `0x08023778` → file `0x19E94`.
- At VA `0x08023628` / file `0x1828`, bytes `09 23 56 48 6B 60 EB 67 FF F7 6A FE` change state 1 to 9 and log `Switch COMM_TYPE_USB -> COMM_TYPE_USB_AND_CANFD when base plugged in` through literal `0x08023784` → file `0x19EBD`.
- The reverse transition stores 1 and logs `Switch to COMM_TYPE_USB` through literal `0x080237A4` → file `0x19F55`. State-4 branches log `POWER_BASE_CANFD` through literals `0x08023780` and `0x08023794` → files `0x19F7A` and `0x19FA2`.

These establish software labels 1 = USB, 9 = USB+CANFD, and 4 = CANFD with high confidence. They do **not** establish which state the user's Xtend selects. Base-presence state at device offset `+0xF8` affects the transitions, so a live USB endpoint can exist while ordinary axes/buttons travel through the other transport. See `work/simagic/zeus-modes.c`. Full CAN-FD wire framing and initialization requirements remain unresolved.

## Wheel/base/USB topology and remaining work

The official [MagLink Pro Xtend page](https://simagic.com/pages/detail-simagic-maglink-pro-xtend) links its [English manual](https://cdn.shopify.com/s/files/1/0764/6756/8943/files/Maglink_Pro_Xtend_User_Manual_EN.pdf?v=1779688626). PDF page index 8 labels a PC interface; page index 10 directs the cable to the PC, separately from power. This is vendor documentation, not an observation of the user's current wiring. The wheel's USB endpoint can therefore be separate from the Alpha Ultimate's steering/FFB endpoint.

S4 also contains mode strings at file offsets `0x19DF6` (`BL3_BASE_USB`), `0x19E0F` (`BR3_WHEEL_USB`), and `0x19E29` (`POWER_WHEEL_USB`). The executable mode/report paths above show why USB identity alone is insufficient: the selected mode affects where ordinary controls are sent. The physical Xtend mode and what Sigma currently sees still require capture.

Offline files establish Zeus USB recognition constants and descriptor layout. They do not establish which physical buttons map to each bit under the user's saved wheel configuration, whether Sigma can enumerate the Xtend/Zeus path, or whether Sigma's existing downstream aggregation can merge the separate wheel and base devices. Obtain:

1. The actual cable destination, and full USB device/configuration/interface/endpoint/HID-report descriptors with Zeus attached through Xtend, including any intermediary hub topology.
2. Passive or explicitly authorized PC-side traces from connection through stable operation, both with SimPro closed and open, preserving control transfers and report IDs/lengths. Repeat with the actual base connection/power arrangement and, where supported, the wheel's standalone USB arrangement. Check whether input ID `01` bytes 1–17 change for controls or remain zero while bytes 18–22 change; this resolves the USB versus USB+CANFD control-routing question without guessing from enumeration.
3. One-control-at-a-time inputs: each button, each encoder direction and mode, both sides of each paddle/axis, plus idle/reconnect. Record wheel firmware and configuration with the capture.
4. A simultaneous Alpha Ultimate descriptor/input trace if Sigma is to merge base steering/FFB and wheel controls. No base firmware patch follows merely from Zeus's independent USB path.

No binary patch, flashing, or device write was performed. The smallest Sigma proposal should match VID/PID and interface first, validate report ID/length, and map verified control fields into existing aggregation. New-device acceptance alone cannot establish functional PS5 support.
