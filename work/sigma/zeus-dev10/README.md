# Zeus dev10: normal reports, controller coexistence and Xtend reconnect

This experimental Sigma 1.1.8 candidate retains the three hub instances that restored Zeus paddles on dev8. It also addresses two remaining dev8 failures: an unrelated USB child can consume the base/pedal driver, and unplugging a nested hub leaves stale wheel assignments. Dev10 has passed offline checks; it has not yet been installed or tested on hardware. PS5 and force feedback remain unverified.

The candidate sends the original report layout plus mapped Zeus controls. Diagnostic bytes and the periodic heartbeat are removed. Existing base steering, pedal and vendor fields are retained. There is no new wheel-icon implementation.

## Files and installation choice

Updater: `NOT_FOR_FLASHING-SIGMA_Converter_V1.1.8-zeus-dev10.exe.disabled`

Updater SHA-256: `df633e0b66b6aa236c94d4e075c547cc486c5c3cb10fbbd3dc90d579de883001`

The `.disabled` suffix prevents accidental execution. No agent firmware write or updater execution occurred. A new installation requires the user's choice. If choosing this hardware test, extract the ZIP, remove only `.disabled` from that updater's filename, and use the same manual update process that completed for dev8. Preserve the stock updater and earlier candidates. A completion message alone does not prove a successful boot or this build's behavior.

First test on Windows with base, pedals and powered Xtend attached before Sigma starts. Check the base icon/checkmark, steering, each connected pedal, both paddles and seven-way directions/releases. There is no separate pedal icon on the user's unit. Then unplug only Xtend data for three seconds and reconnect: paddles should return and the base checkmark should remain. Confirm these physically before PS5 testing.

The bundled input-only capture helper is optional:

```powershell
.\inspect_windows_hid.ps1 -CaptureDevice Sigma -CaptureSeconds 25 -SnapshotPath .\sigma-dev10-controls.json
```

Move controls during the capture. It refuses to overwrite an existing file and sends no output/feature reports. Dev10 has no diagnostic marker; do not decode it with the diagnostic-page decoder.

## Changes and evidence

- Keep all six original class registrations, Zeus at slot 6, and two additional native hub objects at slots 7/8. State use is 228/256 reserved bytes; original dev3 heap/stack bounds remain.
- Unmatched devices take the existing address-only path instead of the blind fallback that assigns a known-device class to an unrelated identity. Existing identity/class matching remains.
- Track parent hub ID and physical port in padding bytes 21/22 of the two owned extra-hub objects. On the observed disconnect event, release the correctly mapped hub address, then release class objects whose address-pool entries have been freed. Continue original event processing. The root hub and valid base/pedal assignments remain intact in the model.
- Keep the 23-byte ID1 parser and normalize 64-byte callbacks to its known prefix; identity/interface/report-ID checks remain.

Actual-image offline results: 18 CPU/RAM groups (including 120 single-bit cases and 99 distinct recorded frames); 56 exact report comparisons across eight non-neutral base patterns; 52 USB connection-order cases; 30 detach/rebind cycles at three subtree levels and two physical-port layouts. Reconnect checks execute native pool freeing, class release and reinitialization, and verify held-button release and exact base-report preservation. Synthetic descriptors and successful transport boundaries are assumptions; no physical bus timing is modeled.

Application: 192,480 bytes, 94 update pages. Plaintext SHA-256: `56eeec661beacfdf48b3ff009ed2d44d72b97661951edc6de8a409be449d85a0`. The packaged updater preserves native executable sections and all 749 other resource payloads. PE consistency checks do not establish bootloader acceptance.

The manifests and verification JSON files record hashes and test limitations. The `source` directory contains snapshots; reproduction also requires the full repository, preserved dev3 inputs and analysis dependencies. Dev9 was an internal normal-report draft without the reconnect fix and was not delivered for installation.
