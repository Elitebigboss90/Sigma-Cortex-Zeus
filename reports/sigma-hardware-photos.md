# Sigma board photographs: chip marking and candidate headers

October 27, 2026, America/Los_Angeles. These are the user's photos of their opened Sigma, supplied as `IMG_0171.HEIC` and `IMG_0173.HEIC`. The user subsequently confirmed having no multimeter. No continuity, voltage, debug-port or protection-state measurement was performed.

## Evidence preserved

| Photo | Original copy | Size | SHA-256 |
| --- | --- | ---: | --- |
| Component side | `originals/hardware-photos/IMG_0171.HEIC` | 1,568,949 | `e1077adcd1b6787e0bd65593163c494b24a81ace1c7f2c73254642c7495497e9` |
| Rear side | `originals/hardware-photos/IMG_0173.HEIC` | 1,547,931 | `28df6991db93974fc69259dfa6e76b03379b55ff55e30ffd93eb0dee591f119f` |

[sigma-hardware-photo-manifest.json](sigma-hardware-photo-manifest.json) binds the supplied Downloads files to byte-identical original copies. Native macOS tools decoded HEIC and normalized orientation for inspection. `work/sigma/hardware-photos/view-transformations.json` records source/output hashes, operations and crop rectangles. No generative image processing was used.

Coordinates below refer to the upright 4,284 × 5,712 PNG, origin at top left. The [component-side detail](../work/sigma/hardware-photos/front-detail.png) is rectangle `(1200,1900,1700,1500)` from IMG_0171; the [rear detail](../work/sigma/hardware-photos/rear-detail.png) is `(1500,2150,1450,1250)` from IMG_0173. These pixel locations identify visual evidence, not firmware byte offsets.

## Observations

| Feature / location | Visible evidence | Interpretation and confidence |
| --- | --- | --- |
| U1, IMG_0171 approximately x1840–2250, y2450–2830 | Nations logo; markings `N32G455` and `REL7`; square package with 16 leads per side; pin-1 dot and adjacent silkscreen triangle | **The user's own board carries an N32G455REL7-marked LQFP64 device.** High confidence as visual part identification. This supersedes reliance on an unspecified teardown. Electronic chip-ID/protection reads remain unperformed. |
| Main-board P1, IMG_0171 approximately x1400–1515, y2260–2685 | Four unpopulated plated through-holes in one vertical row, boxed and labeled `P1`; top pad is square when USB-A sockets are at the top | Accessible connector footprint. Plausible programming/debug-header candidate, but the four signals and their order are unknown. High confidence for physical layout; function is a hypothesis. |
| CN3, immediately below that P1, approximately x1400–1510, y2710–2965 | Three unpopulated plated through-holes, boxed and labeled `CN3`; bottom pad is square | Separate connector footprint. No demonstrated UART, BOOT, reset or power assignment. High confidence for layout only. |
| Rear side opposite those headers, IMG_0173 approximately x2640–2730, y2360–2890 | Corresponding four-hole and three-hole groups; visible tracks/vias but incomplete end-to-end connectivity | Photographs do not establish the net names, internal-layer connections or continuity. No functional pin order is derived from pad shape. |
| Y2 beside U1, IMG_0171 detail | Component marked `8.000` | Consistent with the 8-MHz HSE assumption in the recovered ×18 clock configuration; medium confidence for nominal-frequency interpretation, no measured clock frequency. |
| Board edge beside P1/CN3 | Silkscreen `20250209` | Record as a board identifier/date-like marking. It does not establish a formally named hardware revision or manufacturing date. |

`P1` also appears on the separate button board. Here **main-board P1** always means the four empty holes immediately left of U1, above CN3.

## Effect on the firmware investigation

The physical marking corroborates the independently recovered [N32G45x SDK lineage](sigma-n32-code-match.md) and the part used for the [memory/protection analysis](sigma-n32-hardware.md). The existing dev2 image and RAM reservation fit the published REL7 memory geometry; stock and dev2 occupy the same 93 application flash pages. No firmware bytes need changing because of these photographs.

The earlier geometry record was created before these photos and correctly records that part identification was then conditional. The new photo-bound geometry record distinguishes visual identification from electronic identification. Neither resolves bootloader integrity, partition permissions, RDP status or recovery.

## Measurement needed before connecting a programmer

Keep all cables disconnected during continuity work. Using the official LQFP64 pinout, a person with suitable probes can determine whether P1 connects to **PA13/SWDIO (chip pin 46)**, **PA14/SWCLK (49)**, a verified **VSS/GND** net and a verified **VDD** net. These are comparison targets, not an assigned P1 pinout. Record each P1 hole by position, top to bottom, starting at the square pad. Record measured continuity rather than assuming a standard header order. CN3 likewise needs measurement before attributing any boot/reset/serial role.

The user currently has neither a multimeter nor a debug probe. The next hardware step is access to a continuity-capable meter with appropriate fine probes, or assistance from someone who can map the connector. If a debug connection later becomes available, identify protection without invoking unlock/erase: Nations documents that L1-to-L0 regression erases main flash. The vendor-information route remains available if physical readback cannot be established.

No pins were bridged, no programmer was connected and no device command was sent by the analysis tools. Photos are sufficient to identify the printed part and connector locations, not to establish electrical access.
