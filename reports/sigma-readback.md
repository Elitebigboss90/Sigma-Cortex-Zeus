# Sigma application readback investigation

Analysis date: 2026-10-27, America/Los_Angeles.

Follow-up November 2: [OK-button Bootload entry, status read and normal return are now observed](sigma-bootload-observation.md). The single boot-mode GET_FEATURE F1 returned 16 status bytes. A physical flash dump or supported arbitrary flash-read command has not been obtained. The original analysis below concerns application-mode requests; boot-mode F1 has a different observed response.

**No supported read-only command for dumping Sigma flash or the bootloader was found in the traced application USB paths.** Several GET_REPORT requests return fixed data or RAM, but none accepts a flash address. Report IDs `F0/F1/F2` have different application and bootloader meanings; the updater's F1 status interpretation must not be applied to the running console application.

The user subsequently confirmed no revision marking and no ST-Link. The [stock-updater preflight audit](sigma-updater-preflight.md) and [public recovery-package search](sigma-recovery-options.md) did not supply an alternative read-only acceptance check. A vendor specification/matching bootloader image remains an alternative to hardware access; the exact unanswered questions are recorded there.

No USB commands, resets, update requests, or hardware reads were executed. This is bounded static analysis, not proof that no readout command exists anywhere in the missing bootloader.

## Artifact identity and evidence

| ID | Source | SHA-256 |
| --- | --- | --- |
| A | `work/sigma/1.1.5/sigma-decoded.bin` | `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622` |
| U | `originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe` | `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a` |

A VA = file offset + `08020000`. Relevant U `.text` VA = file offset + `00400C00`.

Existing code: `work/sigma/1.1.5/firmware-device-paths.c` and `updater-functions.c`. Added decompilation: `work/sigma/readback/feature-dispatch.c` and `output-dispatch.c`, exported from a private copy of the existing Ghidra project in read-only mode. The shared original project was untouched. Exact selected instructions and the bounded address scan are in `work/sigma/readback/readback-evidence.json`, reproduced by `scripts/integrity_readback.py`.

## Application control-transfer dispatch

A **`0802AF3C`**, file `0xAF3C`, handles HID-style requests after the USB stack has parsed the setup packet. It dispatches request 1 (GET_REPORT), request 3 (GET_PROTOCOL), and request 9 (SET_REPORT) for the relevant class request type. The internal report selector is stored in `20000D1D`, direction/request code in `20000D1E`, and requested byte count in `20000D1F`.

For ordinary GET_REPORT selectors it queues work by setting `20000D1C`, then the main loop calls **`08044724`**. The response helper **`0802B3D8`** selects **`0802B2CC`**, which returns one of fixed RAM addresses. The host supplies a report selector and transfer length; no flash-address parameter is interpreted here.

| Application request | Code/data evidence | Observed behavior | Readback relevance |
| --- | --- | --- | --- |
| GET report `03` | A `08044724`; fixed source `0804D8F6`, file `0x2D8F6` | Copies 48 constant flash bytes into response buffer `20000D20`; begins `03 21 27 04 18 06` | Fixed identity/configuration bytes, no selectable source address |
| GET report `31` | A `0802AF3C`, `0802B2CC` | Returns fixed RAM `20000094`; application sets mode fields before reply | Console input/mode data, not flash |
| GET report `32` | Same | Returns fixed RAM `200000D4` | Fixed RAM data, not flash |
| GET report `33` | Same | Returns fixed RAM `20000054`; refreshes control fields through `0802ACE4` | Fixed RAM data, not flash |
| GET report `F1` | A `08044724`, especially page-copy branches near `08044880..08044950` | Builds 64-byte reply with ID, exchange tag, current page, 56 data bytes (32 on final page), and CRC32 | Reads paginated RAM `20003FE8`, not arbitrary memory |
| GET report `F2` | A `08044724`, CRC call `080447EC` | Clears response buffer, writes status/tag, adds CRC32 over first 12 bytes | Small status reply; completion status resets the F1 page counter |
| GET report `F3` | A `08044724` | Writes `F3 00 38 38 00 00 00 00` to the start of response buffer | Fixed response; no flash source |
| GET_PROTOCOL request 3 | A `0802B298`, file `0xB298` | Returns one byte at RAM `20000D18` | HID protocol value only |

For F1, page counter `20004544` runs 0 through 18, incrementing after each reply and wrapping. The first 18 pages copy 56 bytes each; the last copies 32 and clears the remaining payload space. Total source extent is **1,040 bytes, `[20003FE8,200043F8)`**. A caller does not provide a base address. GET therefore changes transient pagination state even though this branch does not erase/program flash.

The F1 buffer is populated by a separate exchange state machine in `08044724`, involving helpers `08045940/08045970` and peripheral address `0x5A`. The code copies received blocks into the fixed RAM extent above. That bounded dataflow establishes it is not a direct read of the converter's bootloader. A complete interpretation of the exchange protocol was unnecessary for this readback question and is not claimed.

Unrecognized GET selectors do not expose a documented address-based reader; the generic response path can reuse the existing response buffer. Sending undocumented selectors or oversized requests was not attempted or treated as a legitimate flash-dump method.

Confidence: high for fixed address/copy behavior and page bounds; no live response capture was made.

## Requests with state-changing effects

These must not be confused with readback:

- **SET report `F0`**, A `08044724`: copies input pieces into RAM `200043F8` (four 56-byte pieces and one 32-byte piece), changes an exchange tag, and the last piece selects state 2 for a subsequent peripheral exchange. This is not a flash-read command.
- **SET report `F3`**, same routine: sets exchange state 1 and records the current timer counter. It is not a read operation.
- **SET report `03` with payload `55 FF AB AD BA BE`**, A `0802AE8C`: calls the erase/reset chain documented in [sigma-integrity.md](sigma-integrity.md). It erases the 2-KiB page at **`08018000`**, then requests a system reset. Do not send it as a harmless discovery/status request.
- GET `F1/F2` uses and can change pagination state. This is transient report state, not a demonstrated persistent-flash write, but these requests still cannot obtain arbitrary bootloader bytes.

The SET_REPORT buffer callback at A `0802B36C` returns fixed RAM `20000D20`. No host-selected source/destination pointer is parsed by this callback.

## Interrupt OUT and updater F2 are separate paths

Application interrupt OUT handling **`0802A824`** reads an endpoint packet and queues it through **`0802C27C`**. Queue consumer **`0802BF34`** recognizes records beginning with byte `30`, with specific following control values such as `01 08`, `03 08`, `13 0B`, and `F8 09`. The traced branches translate steering-force/control/display operations toward the base. They do not interpret a flash address or emit firmware bytes back to the host.

The PC updater U **`00404C00`** sends `F2 0A length offset_le32 payload` only in its update sequence after the mode-transition request. That is an **output/write** transfer; the offset indexes the embedded firmware resource. It is not evidence of a paired F2 read operation. The corresponding bootloader handler is absent from A.

Confidence: high for the traced application consumer and updater transfer direction; coverage does not include the missing bootloader or every possible peripheral response.

## PC updater F1 status interpretation

U **`00401FC0`** allocates a zeroed buffer using the device's FeatureReportByteLength, sets byte 0 to `F1`, and calls `HidD_GetFeature`. It passes no flash address. U **`00403EB0`** interprets returned u32 at byte 8 as firmware version for display.

U **`004041D0`** first sends report `03` with the boot-entry payload, waits for re-enumeration, sends SET_FEATURE `F1` beginning with `02`, then performs status/version and data-transfer operations. Later F1 payloads begin with `04` and `01`. Those are distinct **SET** operations around update completion/restart, not readback commands. Their complete device-side effects remain unverified without bootloader code.

The updater's generic F1 helper may also be called while displaying an attached device. Its host-side interpretation of byte 8 does not prove that every accepted VID/PID and operating mode supplies that layout. In the analyzed application, GET F1 has the RAM-page layout above. A legitimate live status reader would first need to establish the actual mode and response format; it would still not provide a bootloader dump merely by reading F1.

## Boot-page references and flash limits

A bounded scan for adjacent same-register MOVW/MOVT address constructions in file `[0,0x26700)` found:

| Constructing VA | Address | Established use |
| --- | --- | --- |
| `0802B4BE` | `08019000` | Fixed settings read into RAM `20000D64`, length `0x170`, in `0802B4B0` |
| `0802B4E4`, `0802B51A`, `0802B54A` | `08019000` | Settings write/erase path in `0802B4E0` |
| `0802B934` | `08018000` | Fixed update-entry page erase in `0802B930` |
| `0802B94C` | `08017FFF` | Lower-bound comparison for that erase path |

`0802B930` also checks that the requested last byte remains below `08080000` and that the address is aligned to `0x800`. These are bounds in an application flash helper path, **not** proof of the bootloader's accepted firmware extent or the exact physical flash size.

The matching constants `08018000`, `08018004`, and `08018008` do not occur as literal words in the recovered initialized RAM image. This is only a bounded literal check. No parsed metadata structure or read from that page was recovered in the reviewed application paths. The scan does not cover all arithmetic ways to construct addresses, and it cannot inspect code that was not supplied.

The settings read at `08019000` provides no bootloader/validation-page readback: it is fixed to the settings region and its data is used internally. It is not a host-selectable dump primitive.

## Consequence for the candidate firmware

The missing acceptance evidence cannot currently be obtained through a justified application HID command from these files. Sending the known boot-entry request would already erase metadata and reset, violating a read-only investigation. No unknown bootloader opcode should be guessed or brute-forced.

The next evidence capable of resolving acceptance is a vendor bootloader/format specification, a matching bootloader image, or a permitted read-only hardware dump after the exact chip, board revision and readout protection are identified. The relevant range remains `[08000000,08020000)`, especially `[08018000,08018800)`. No specific probe command or recovery method is asserted without that hardware evidence.

An offline candidate can remain available for review and emulation while its installability is unresolved. Passing the patch's emulator tests does not change the missing bootloader evidence.

Reproduce the static evidence with:

```sh
work/tools/python/bin/python scripts/integrity_readback.py
```

This script reads the pinned firmware bytes and writes `work/sigma/readback/readback-evidence.json`; it contains no HID or USB I/O.
