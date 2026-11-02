# Unmodified Sigma 1.1.5 updater: preflight limits

Analysis date: 2026-10-27, America/Los_Angeles. Static review only; no Windows executable or device command ran.

**The unmodified updater provides no demonstrated way to establish dev2 acceptance before erase/reset/write operations.** It loads only its embedded original 1.1.5 image, and it sends the update-entry command before even loading that resource. Its displayed success does not include a verified image readback or boot result.

Source: `originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe`, SHA-256 **`585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a`**. Function VAs below map to file offset `VA − 00400C00`. Existing decompilation is `work/sigma/1.1.5/updater-functions.c`; selected raw instruction evidence is `work/sigma/readback/updater-preflight-evidence.json`.

## Order of operations proves this is not a harmless image test

| Host VA | Supporting bytes/code | Established effect |
| --- | --- | --- |
| `004042A7` / `004042AD` | `C7 00 55 FF AB AD`; `66 C7 40 04 BA BE` | Builds the update-entry payload |
| `004042B7` / `004042B9` | `6A 03`; `E8 D2 DD FF FF` | Calls feature-send helper `00402090` with report `03`; the decoded application erases `08018000` and resets on this command |
| `004043D2` / `004043D9` / `004043DE` | `C6 00 02`; `68 F1 00 00 00`; `E8 AD DC FF FF` | After re-enumeration, sends SET_FEATURE `F1`, payload `02` followed by zeros |
| `00404458` | `E8 53 FA FF FF` | Calls status/version display helper `00403EB0` after the operations above |
| `00404471` | `FF 15 28 F4 56 00` → `FindResourceW` | Only now looks up `TEXTFILE / IDR_APP_FILE` |
| `00404481` / `00404492` / `00404499` | `SizeofResource` / `LoadResource` / `LockResource` | Obtains the embedded image length and pointer |
| `004044B3` / `004044BB` | `85 C0`; `39 97 F4 01 00 00` | Checks for a nonzero resource length and pointer; no digest/signature comparison in these checks |
| `004044D0` onward | Calls `00404C00` for successive resource-relative offsets | Sends the complete embedded carrier in at-most-32-byte pieces |

The update-entry erase/reset behavior is independently established from application code in [sigma-integrity.md](sigma-integrity.md). Stopping the updater before its transfer loop would still be **after** that destructive state transition. The F1 preparation command is also a SET operation with unverified bootloader-side effects.

The inspected path offers no external BIN-selection input. An unmodified executable contains and sends its original resource; it cannot validate the separate dev2 file without receiving it. Replacing its resource would create a modified updater, and would not add a preflight-validation protocol.

## Status and completion do not prove candidate acceptance

`00401FC0` sets a zeroed feature buffer's first byte to `F1` and calls `HidD_GetFeature` at **`0040204D`**. `00403EB0` calls that helper at **`00403F36`** (`E8 85 E0 FF FF`) and interprets returned u32 at byte 8 as a version number. At **`00403FF9`** (`F7 C2 00 00 00 FF`) it tests the high byte to select a display format with a `BL` suffix. This is a version/mode display, not an image-hash or acceptance query. Application-mode F1 has different semantics, as established in [sigma-readback.md](sigma-readback.md).

The transfer helper calls `WriteFile` at **`00404D09`**, then `GetOverlappedResult` at **`00404D33`**. It checks Windows transport completion; there is no device image-validation response parsed by this function.

After the final data transfer, the success path is:

1. **`004045D3`**, `C6 00 04`, followed by call **`004045DF`**, `E8 AC DA FF FF`: SET_FEATURE F1 payload `04`.
2. **`00404644`**, `C6 00 01`, followed by call **`00404650`**, `E8 3B DA FF FF`: SET_FEATURE F1 payload `01`.
3. **`00404690`**, `68 28 2F 5A 00`, then **`00404697`**, `E8 83 A2 01 00`: displays the embedded “Update Complete!” message.

There is no intervening GET_FEATURE, readback/hash comparison, or re-enumerated application check in that path. The common SET_FEATURE helper invokes `HidD_SetFeature` at **`00402133`**, `FF 15 CC F1 56 00`, then frees its buffer without testing that API's return value. Exception handling can still report other failures; the narrower point is that this success message is not evidence of bootloader acceptance or successful boot.

## Backup and recovery boundary

The reviewed update routine, its feature/transfer helpers, and the updater's own dialog strings expose no firmware backup, readback, dry-run, or rollback operation. The only direct `ReadFile` import reference recorded by the existing Ghidra export is `004B4B97`, outside the traced update path. Presence of a general file-reading API does not establish device readback.

The package's recovery-related strings are Windows/MFC application-recovery support (`RegisterApplicationRecoveryCallback`, `CDataRecoveryHandler`, and recovery of autosaved documents). They do not document converter boot recovery. The updater dialog at file `0x1E79DE` presents current/target firmware versions and an Update control; no separate backup or verify action was found there.

This is a bounded conclusion about the supplied updater, not a claim that no hardware recovery or vendor procedure exists. A distributor manual or separate vendor recovery package would be independent evidence. The user's lack of a revision label or ST-Link does not change the updater's observed sequence, and no substitute device command was invented.

**Result:** retain dev2 as an offline candidate. The unmodified updater cannot resolve the missing integrity/acceptance evidence without entering the erase/write workflow, and attempting the stock update solely as a preflight test would not satisfy the read-only constraint.
