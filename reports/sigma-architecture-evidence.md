# Sigma 1.1.5 architecture and USB descriptor evidence

All file offsets in this report refer to `work/sigma/1.1.5/sigma-decoded.bin`, size **189,056 (`0x2E280`) bytes**, SHA-256 **`03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`**. Virtual addresses use the evidence-backed application mapping **`VA = 0x08020000 + file offset`**. This image is decoded from resource SHA-256 `4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282` of Sigma EXE SHA-256 `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a`; derivation is recorded in `work/sigma/1.1.5/sigma-decoded.bin.transform.json`.

This is static evidence, not observed device execution. Reproduce with:

```sh
work/tools/python/bin/python scripts/sigma_architecture.py \
  work/sigma/1.1.5/sigma-decoded.bin
```

The complete selected instruction bytes, vector entries, descriptor fields and report lengths are in [sigma-architecture-evidence.json](sigma-architecture-evidence.json). Capstone 5.0.9 is used for independent Thumb instruction decoding of selected ranges. No generic REA ARM profile is used.

## Vector table, code mode and application address

| File offset / VA | Supporting bytes or decoded code | Interpretation | Confidence |
| --- | --- | --- | --- |
| `0x0000` / `0x08020000` | `90 65 00 20` | Initial stack pointer `0x20006590` in the conventional Cortex-M SRAM region | High with the following vector/code evidence |
| `0x0004` / `0x08020004` | `91 02 02 08` | Reset pointer `0x08020291`; bit 0 selects Thumb, code address is `0x08020290` | High |
| `[0,0x198)` | 102 little-endian words; all nonzero handler pointers are odd and fall in this image under the selected mapping | Coherent vector table: 16 system entries plus space for 86 external vectors; table capacity alone does not identify the MCU | High for table structure |
| `0x0290` / `0x08020290` | `09 48 80 47 09 48 00 47` → `ldr r0,[pc,#0x24]; blx r0; ldr r0,[pc,#0x24]; bx r0` | Reset calls an initialization routine then branches to runtime startup | High |
| `0x02B8`, `0x02BC` | `f9 07 02 08`, `99 01 02 08` | Reset's PC-relative literals resolve to `0x080207F9` and `0x08020199`; both point to valid Thumb routines at matching file offsets | High |
| `0x07FA`–`0x080A` | Constructs `0xE000ED88`, loads it, ORs `0x00F00000`, stores it | CPACR enables CP10/CP11 full access, consistent with a Cortex-M FPU-enabled build | High for register writes; this alone does not distinguish M4 from all other M-profile CPUs |
| `0x08BA`–`0x08C8` | Constructs VTOR `0xE000ED08`; writes `0x08000000` | Early system initialization uses the default flash vector address | High |
| `0x5264`–`0x5274` / `0x08025264`–`0x08025274` | `4ef60851 cef20001 0022 c0f60202 0a60` | Later initialization explicitly writes **`0x08020000` to VTOR**, independently corroborating the application mapping | High |
| `0x5276`–`0x527C` | `0398 80f31088`, with local zero initialized just above | Clears PRIMASK after relocating VTOR | High for static dataflow |

Exception slots provide additional structure: NMI points to `0x08025539` (`bx lr` at offset `0x5538`); HardFault, MemManage, BusFault and UsageFault point to short looping stubs; PendSV points to the loop at `0x02A6`; SysTick points to `0x08024FC1`, whose handler increments a RAM counter at `0x2000081C`. Most external slots share the default loop at `0x080202AA`; external slot 20 points to `0x08025554`, which calls the routine at `0x0802AD3C`.

**Established:** little-endian Cortex-M/Thumb-2 application, FPU enabled, mapping start `0x08020000`, vector table at file offset zero, initial SP and reset address as above. The observed application extent is `[0x08020000,0x0804E280)`. This does not establish the device's complete flash size, SRAM size, bootloader extent, or exact silicon part. Initial SP is not a measurement of maximum RAM capacity.

## Peripheral-family clues, with a bounded conclusion

**Updated identification:** [comparison with official Nations N32G45x support code](sigma-n32-code-match.md) now matches the distinctive `1FFFF298/49524B42` check, voltage-trim arithmetic, ordered clock defaults and flash routines. This supersedes the tentative Artery hypothesis below. The user's subsequent [board photos](sigma-hardware-photos.md) show N32G455REL7 markings on their own U1; electrical ID/protection reads remain unperformed. [Hardware documentation and geometry checks](sigma-n32-hardware.md) preserve that distinction.

The initialization routine constructs and accesses clock registers around `0x40021000`, flash control at `0x40022000`, and power control `0x4000700C`. USB-related code constructs registers at `0x40005C00` and packet memory near `0x40006000`. These addresses are instruction operands assembled by `MOVW/MOVT`, not merely coincidental four-byte patterns in instruction data.

Examples retained in the JSON instruction evidence:

- Offset `0x080A`: `movw r0,#0x1000`; offset `0x080E`: `movt r0,#0x4002`; access through `r0` follows. Address: `0x40021000`.
- Offset `0x08A6`: `movw r0,#0x2000`; offset `0x08AA`: `movt r0,#0x4002`; read/modify/write follows. Address: `0x40022000`.
- Offset `0x08C8`: constructs `0x1FFFF298`, reads a word, compares against `0x49524B42`; its exact hardware meaning remains unresolved.

The [official Artery AT32F403A/407 CMSIS header](https://github.com/ArteryTek/AT32F403A_407_CMSIS_Driver/blob/main/at32f403a_407.h) declares a Cortex-M4 with FPU and compatible flash/SRAM/clock/USB register regions. Its [SystemInit source](https://github.com/ArteryTek/AT32F403A_407_CMSIS_Driver/blob/main/system_at32f403a_407.c) also enables CP10/CP11 and initializes clock/vector registers. Local reference copies:

| Source | SHA-256 |
| --- | --- |
| `work/tools/artery/at32f403a_407.h` | `3a6c4abcc256db323f66a5fa46ee65b23e3fa3d71fbfd50487b5c179cbe8cdc5` |
| `work/tools/artery/system_at32f403a_407.c` | `9bff558f0e18455d274f37aec1c5e6ad900cdf0e5d462d192bc3498f2d877130` |

**Hypothesis only:** an AT32F403-related M4 implementation is compatible with part of this evidence. Register layouts overlap other vendor families, and the downloaded current startup source does not exactly match the Sigma startup sequence. No exact Artery, ST, GD32, or other MCU part is established. A chip marking or documented device-ID read could settle the specific silicon identity; it is unnecessary to invent that identity to import the established Cortex-M instruction set and application map.

## Console-facing USB identity and report structure

At offset **`0x26888`**, the 18-byte device descriptor is:

```text
12 01 00 02 00 00 00 40 b7 0e 07 0e 25 06 01 02 00 01
```

It declares **VID `0x0EB7`, PID `0x0E07`**, `bcdUSB=0x0200`, `bcdDevice=0x0625`, EP0 maximum packet size 64, manufacturer index 1 and product index 2. UTF-16LE string descriptors contain **`Fanatec`** at `0x26967` and **`FANATEC WHEEL(PS5 / PS4 MODE)`** at `0x26977`; the language descriptor at `0x26963` declares `0x0409`.

The 41-byte configuration at **`0x2689A`** contains one HID interface, a 160-byte HID report descriptor declaration, an interrupt OUT endpoint **`0x03`**, and interrupt IN endpoint **`0x84`**, each with maximum packet size **64**. Their `bInterval` fields are **3** and **2**, respectively. Actual bus speed and observed polling intervals were not captured.

The report descriptor occupies **`[0x268C3,0x26963)`**. Parsing the descriptor's Report Size, Report Count and Report ID items gives:

| Report ID | Direction/type | Payload bytes | Total including Report ID |
| --- | --- | ---: | ---: |
| `0x01` | Input | 63 | 64 |
| `0x05` | Output | 31 | 32 |
| `0x03` | Feature | 47 | 48 |
| `0xF0` | Feature | 63 | 64 |
| `0xF1` | Feature | 63 | 64 |
| `0xF2` | Feature | 15 | 16 |
| `0xF3` | Feature | 7 | 8 |

Input report `0x01` advertises four initial 8-bit axes (X/Y/Z/Rz), a four-bit hat, fourteen button bits, a six-bit vendor field, two further 8-bit axes (Rx/Ry), and 54 bytes of vendor-defined data. The JSON records every field's bit offset and usage item. These are descriptor declarations; the application still determines which physical inputs populate them.

The Fanatec product string and surrounding descriptor structure identify the converter's **console-facing emulation identity** with high confidence. These values must **not** be treated as the allowlist of Simagic devices accepted by Sigma's USB host side. No Zeus input mapping is established by this descriptor.

## Decoded release corroboration

Offset **`0x2DDF5`** contains ASCII ` FW: 1.1.5`; offset **`0x2DE03`** contains ` HW: Rev.B`. Offset **`0x2DEFD`** contains `Shifter Direction`, consistent with the supplied release notes. These exact decoded strings further corroborate the recovered byte stream but do not verify device acceptance, checksums, or signatures. `HW: Rev.B` is an embedded UI label, not a physical inspection of the user's board revision.
