# Sigma recovery audit — November 2, 2026

## Current result

**No firmware has been read from the physical Sigma in this audit.** The application extracted from the original 1.1.5 updater is available, but it does not contain the preceding bootloader region. The subsequent [live Bootload observation](sigma-bootload-observation.md) now confirms OK-button entry, a successful F1 status read through the KVM, and return to normal operation after a power cycle without OK. The exact bootloader implementation remains unavailable.

The initial static/passive phase documented below sent no device commands. The subsequent live phase used exactly one GET_FEATURE status request, and no SET/output, erase, protection-change or firmware-installation operation. The user used the KVM because direct connection did not appear to work; the cause is unknown.

## User-supplied recovery procedure

Source: reply pasted into the conversation on November 2. Author and original URL were not supplied; it is not independently authenticated vendor documentation.

Reported sequence: disconnect all accessories and power, hold the Cortex's OK button, connect its console/PC USB port directly to the computer, keep OK held for approximately five seconds, then release. The expected display is “Bootload mode”. The reply subsequently recommends the original `SIGMA_Converter_V1.1.8.exe` updater.

Only the entry sequence is being investigated. The 1.1.8 executable was not present in the inspected project paths, has not been verified, and has not been run. The Zeus candidate remains based on 1.1.5.

The now-observed cold-start entry establishes that the button sequence reaches update mode with the currently installed application. It supports, but does not alone prove, the claim that the check runs in the bootloader before application startup. It does not establish arbitrary flash readback, successful restoration after a corrupt application, or acceptance of the patched carrier.

## Application fault handlers do not themselves enter recovery

Source: `work/sigma/1.1.5/sigma-decoded.bin`, 189,056 bytes, SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`. File offset zero maps to `08020000`.

| Exception | Vector file offset / bytes | Handler VA / file offset | Handler bytes |
| --- | --- | --- | --- |
| HardFault | `0x0C` / `3D 55 02 08` | `0802553C` / `0x553C` | `FF E7 FE E7` |
| MemManage | `0x10` / `41 55 02 08` | `08025540` / `0x5540` | `FF E7 FE E7` |
| BusFault | `0x14` / `45 55 02 08` | `08025544` / `0x5544` | `FF E7 FE E7` |
| UsageFault | `0x18` / `49 55 02 08` | `08025548` / `0x5548` | `FF E7 FE E7` |

For each handler, the first Thumb instruction branches to the second; the second branches to itself. These handlers contain no update-entry operation or reset request. Ghidra independently decompiles each as an infinite loop. Confidence: high for the byte/control-flow facts. This does not determine whether a separately configured watchdog resets the processor, nor what the missing bootloader does after a reset or power cycle.

All four vectors and handler bodies are unchanged in dev2, whose plaintext SHA-256 is `0152f4f17e23f47f452d2290fe782afb7b70d65b7a854be5e357da36910ab4a8`. The new button-recovery lead is compatible with these findings: boot-time button handling and application fault handling are separate paths.

## Known update-entry path

The read-only Ghidra export reports the following incoming references:

- `0802AE8C`, application report handler: reference from `0802D38E`.
- `0802BA20`, update-entry wrapper: call from `0802AF10` in that handler.
- `0802B930`, page-erase wrapper: call from `0802BA22`.
- `0802B9F4`, reset wrapper: call from `0802AF14` in the report handler.

The report handler checks `03 55 FF AB AD BA BE` before invoking the erase/reset path. As established in [sigma-integrity.md](sigma-integrity.md), that path erases page `08018000` and requests reset. These references provide no second button-entry route to this particular application routine. They do not exclude computed references, independent implementations, or any code in the absent bootloader.

The raw reset routine at `0802B9F8` constructs `E000ED0C` and writes the AIRCR reset value at `0802BA12` (`01 60`). Ghidra's simplified pseudocode omits that store; the raw instruction evidence remains authoritative for this effect. No such command was sent.

## Physical readback boundary

At `2026-11-02T19:04:16Z` the filtered macOS HID registry observation contained zero matching Sigma/Simagic devices. File: `work/sigma/recovery-audit-2026-11-02/hid-registry.json`, SHA-256 `80c3175099588c049d9f898f2e49de83d1bc9c769d66aa8caef839a1ffed393c`.

The separate `ioreg -a -r -c IOUSBHostDevice` query exited successfully with zero output bytes, causing the existing plist parser to fail. It did not produce a valid complete USB inventory. Neither result is evidence of a damaged device. No firmware bytes were acquired from hardware.

The reviewed normal-mode USB paths return fixed flash constants, status, or bounded RAM, with no demonstrated arbitrary flash-read command; see [sigma-readback.md](sigma-readback.md). Entering Bootload mode might expose a different interface, which must be inspected before choosing any read operation. Update support alone does not imply upload/readback support.

The missing region needed to analyze Sigma's boot decision is `[08000000,08020000)`, including the page at `[08018000,08018800)`. A compatible, permitted SWD read or a matching bootloader image from the vendor could supply it. The user has no probe or multimeter, the P1 pinout is unverified, and readout protection is unknown. No unlock procedure is proposed: protection removal may erase the bytes being sought.

## Reproducible evidence

`scripts/audit_sigma_recovery.py` verifies the pinned original/candidate hashes, vector targets, four handler bodies, and retained Ghidra references. It performs no USB I/O. Run:

```sh
work/tools/python/bin/python scripts/audit_sigma_recovery.py
```

Output: `work/sigma/recovery-audit-2026-11-02/recovery-evidence.json`, SHA-256 `ebea8f885be03b6515c9e6eb157dc5de3ec3882a25d2dcd82778873a5c499939`.

Ghidra export: `work/sigma/recovery-audit-2026-11-02/recovery-paths.c`, SHA-256 `9efb5a3fbef56e00bb830774dacf180e9dd830989bb2fe4819239be06ef48059`. `export-native.log` records read-only processing of the existing private Cortex-M project. The first sandboxed launcher attempt failed on Ghidra's Java/cache file access; the subsequent authorized native run completed. This was not a device-access or approval-review rejection.
