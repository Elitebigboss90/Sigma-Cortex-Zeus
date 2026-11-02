# Package inventory and byte provenance

Derived development artifacts are catalogued separately in [historical dev1](firmware-candidate.md), [historical 1.1.5 dev2](firmware-candidate-dev2.md), and [current 1.1.8 dev3](firmware-candidate-dev3.md), with full build/encoding/PE-resource manifests in their respective work directories. They are modified work products, not vendor originals or installation-verified releases.

Additional distributor-linked 1.0.10/1.0.11 ZIPs and a Sigma manual were preserved and inspected specifically for bootloader/recovery evidence. Their complete identities, extraction ranges and bounded findings are in [sigma-recovery-options.md](sigma-recovery-options.md) and [sigma-legacy-input-manifest.json](sigma-legacy-input-manifest.json). These remain historical comparison inputs.

Official Nations/NSING hardware documents are preserved under `originals/Nations-documentation/`, with [URL/hash manifest](nations-documentation-manifest.json). The official NSING N32G45x device pack and member inventory are retained under `work/tools/nations/packs/`; [source comparison](sigma-n32-code-match.md) identifies the exact package and files used. These are hardware/reference inputs, not Sigma bootloader binaries.

The user's two HEIC board photos are preserved byte-for-byte under `originals/hardware-photos/`. Their [input manifest](sigma-hardware-photo-manifest.json) and [visual findings](sigma-hardware-photos.md) record source hashes and inspection crops; the photos confirm the N32G455REL7 marking and locate unassigned P1/CN3 connector footprints.

Initial inventory: October 27; updated November 2, 2026 (America/Los_Angeles). The user explicitly changed the target to the newly supplied **Sigma 1.1.8 BETA**, with Simagic **Zeus Formula** through **MagLink Pro Xtend** and an Alpha Ultimate base. The 1.1.8 input and [rebase findings](sigma-1.1.8-analysis.md) are separate from the preserved 1.1.5 analysis.

## November 2 supplied 1.1.8 package

| File under `originals/` | Bytes | SHA-256 |
| --- | ---: | --- |
| `SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA.zip` | 2,035,961 | `bd176e95346349fa9352a05ba536e4f4447e61c24e26b4b54dfe2266cb98a9d4` |
| `SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA/SIGMA_Converter_V1.1.8.exe` | 3,630,592 | `233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a` |
| `SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA Patch Notes.txt` | 94 | `5667ad6d86a34836d587c02e8f6ee4e18e81befd5e5f1a8202b0d26c4497bc30` |

The two unpacked files match the ZIP members exactly; CRC checks passed. `scripts/inventory_sigma118.py` records source compressed ranges and hashes in `work/sigma/1.1.8/extraction-manifest.json`. Full PE resource inventory/extraction is under `work/sigma/1.1.8/resources/`, with decoded-image lineage in `sigma-decoded.bin.transform.json`. This is a user-supplied package with no established vendor signature. Original filenames/bytes are unchanged.

## Preserved originals

| File under `originals/` | Size (bytes) | SHA-256 | Version/provenance |
| --- | ---: | --- | --- |
| `SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe` | 3,628,544 | `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a` | Supplied in project `firmware/`; filename and accompanying notes identify 1.1.5 BETA |
| `SIGMA v1.1.5 BETA/SIGMA v1.1.5 BETA Patch Notes.txt` | 318 | `b5c58f64722db6073263552c02fdd9b2b3cac152f6f1195739b73e25b2b965ee` | Supplied notes; ASCII with original CRLF bytes preserved |
| `SIGMA v1.0.20/SIGMA_Converter_V1.0.20.exe` | 3,656,192 | `4e251340b80d4227049ef94bfff3ab520cc7c5053cb4b2bd778be870059c3f23` | Older comparison release from a retailer's firmware link; manufacturer authenticity not independently established |
| `SimPro 3.2.3.13713/SimPro-V3.2.3.13713-072a9e42-Setup.exe` | 432,704,192 | `e8d2fd8f27b008d009b0792b44cf26ce6f9ab8ca7efdb81d724633a6d500647d` | Official Simagic download, full original server-provided filename retained |
| `Simagic-documentation/Maglink_Pro_Xtend_User_Manual_EN.pdf` | 8,387,440 | `c39afe5e482d52cd10cc8dcfcc39875f6bb9d74e4c8baf5edb84daa8739a3ae3` | Official Simagic-linked Xtend manual; preserved PDF |
| `Simagic-documentation/Zeus_Formula_User_Manual_EN.pdf` | 10,705,703 | `4bdea752fba8197cbabae642d880180d8c7b38f204b947c5113d467459cee19a` | Official Simagic-linked Zeus Formula manual V1.0.1; preserved PDF |

The supplied Sigma files remain in `firmware/` and have byte-identical copies in `originals/`. Their initial identities are in [input-manifest.json](input-manifest.json). [simagic-download-manifest.json](simagic-download-manifest.json) records the downloaded installer identity. [additional-input-manifest.json](additional-input-manifest.json) records the older Sigma comparison release and Xtend manual. `scripts/inventory_packages.py` rechecks these originals and the supplied-file copies, refusing a mismatch.

The Xtend manual was retrieved from the [vendor-linked PDF](https://cdn.shopify.com/s/files/1/0764/6756/8943/files/Maglink_Pro_Xtend_User_Manual_EN.pdf?v=1779688626). Its file size and SHA-256 above were independently rechecked. It is documentary evidence for connection topology, not evidence of USB enumeration or runtime input reports.

The Zeus manual was subsequently retrieved from the [vendor-linked PDF](https://cdn.shopify.com/s/files/1/0764/6756/8943/files/Zeus_Formula_User_Manual_EN.pdf?v=1779442382), linked from the [official Zeus Formula page](https://simagic.com/pages/detail-simagic-zeus-formula-steering-wheel). [zeus-manual-input-manifest.json](zeus-manual-input-manifest.json) records its original bytes and provenance. It corroborates control types, clutch-calibration hotkeys and Xtend connection topology; its diagrams do not replace live input mapping.

Simagic provenance chain: [official download center](https://simagic.com/pages/download-center) → [`https://service.simagic.com/software/websiteDownLoad`](https://service.simagic.com/software/websiteDownLoad). The request used `Referer: https://simagic.com/` and `Origin: https://simagic.com`. The response redirect, retained in `work/simagic/download-headers.txt`, identifies `https://update.simagic.com/simpro/latest/SimPro-V3.2.3.13713-072a9e42-Setup.exe` through Simagic's download service. Its expiring query authorization is not a permanent release URL. The file's SHA-256 identifies the exact bytes used here. Vendor hosting/provenance does not itself establish a valid executable signature.

## Sigma package

Established by static PE parsing with `scripts/inspect_pe.py` and independent 7-Zip inventory:

- At file offset `0x110`, the PE header declares machine `0x014c` (i386). It is a native Windows PE32 GUI executable, not evidence of the converter's CPU.
- PE image base is `0x00400000`. The COM descriptor data-directory entry and PE security directory are both zero. The executable has no CLR header and no embedded Authenticode certificate directory. This does **not** decide whether its embedded firmware has a separate signature or checksum.
- The PE version resource reports generic updater version `1.0.0.1`; do not confuse this with the package's firmware version `1.1.5`.
- There is no appended overlay according to the PE parser. The relevant embedded payload is a resource, rather than a separate `.bin` beside the updater.
- The 318-byte notes say this release adds DS-8X support, analog handbrake input, and a sequential-lever inversion menu. The notes alone are release metadata. The subsequent [semantic comparison](sigma-release-comparison.md) corroborates analog handbrake and inversion changes in code and identifies related shifter-mode changes; it does not claim complete DS-8X runtime verification.

Section map (offsets refer to the original EXE):

| Section | RVA | File offset | Raw size |
| --- | --- | --- | --- |
| `.text` | `0x1000` | `0x400` | `0x16DC00` |
| `.rdata` | `0x16F000` | `0x16E000` | `0x4F400` |
| `.data` | `0x1BF000` | `0x1BD400` | `0x5600` |
| `.rsrc` | `0x1C9000` | `0x1C2A00` | `0x191C00` |
| `.reloc` | `0x35B000` | `0x354600` | `0x21800` |

The parser extracted **750 resources**, with each input range, original SHA-256, operation, output size, output SHA-256 and resource identifier in `work/sigma/1.1.5/resources/inventory.json`. The output strings inventory includes ASCII/UTF-16LE file offsets; it does not execute the EXE.

The embedded firmware resource is `TEXTFILE / IDR_APP_FILE / 1033`:

| Field | Value |
| --- | --- |
| Source EXE SHA-256 | `585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a` |
| File range | `[0x1E7EF8, 0x216178)`; offset 1,998,584, length 189,056 (`0x2E280`) |
| Resource RVA / VA | `0x1EE4F8` / `0x5EE4F8` |
| Operation | Identity slice; no decompression or decoding |
| Output | `work/sigma/1.1.5/resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin` |
| Output SHA-256 | `4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282` |
| First 32 bytes | `8e dc 5c af 07 34 04 d1 2e 85 b7 9f 5f 04 a9 05 1e 74 fa e2 7a bb 16 25 90 3a 3f 13 5e 2c 10 ac` |
| Byte entropy | Approximately 7.99917 bits/byte; a measurement only, not proof of encryption |

The range and identity slice are high-confidence byte facts. Subsequent code analysis establishes AES-256-CTR and a Cortex-M application mapped at `0x08020000`; [sigma-analysis.md](sigma-analysis.md) records those findings and the remaining integrity-policy unknowns. Neither the resource name nor entropy was used as proof of encryption.

Subsequent analysis recovered an AES-256-CTR transform from the SimPro parser. `scripts/simagic_decode.py` produces `work/sigma/1.1.5/sigma-decoded.bin`, still 189,056 bytes, SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`. Its `.transform.json` sidecar records the full source resource range, key/IV instruction evidence, operation, output hash and byte-exact reverse transformation check. The decoded image is a work product; the original resource remains unchanged. See [sigma-architecture-evidence.md](sigma-architecture-evidence.md) for the independently checked vector table and descriptors.

The transform's recorded input spelling is `work/sigma/1.1.5/SIGMA_Converter_V1.1.5.payload.bin`, a byte-identical extraction of the same resource hash above. This filename change is not another encoding step.

## Older Sigma comparison release

Sigma 1.0.20 was retrieved from the [EG Sim Rigs product page](https://www.egsimrigs.co.za/products/sigma-cortex-converter) through its [firmware download link](https://cdn.shopify.com/s/files/1/0733/4782/5941/files/SIGMA_Converter_V1.0.20.exe?v=1704246254). This is an explicitly labeled **retailer** source, distinct from the official Simagic download. Its release is kept under `originals/SIGMA v1.0.20/` and `work/sigma/1.0.20/`, separate from the target.

The matching resource `TEXTFILE / IDR_APP_FILE / 1033` begins at EXE file offset `0x1E7EF8`, length **216,800 (`0x34EE0`) bytes**, SHA-256 `42be51e42e118ddee75ae16c288a153ef075bf85757edd6237c6920e55ba95b2`. Its 750 resource slices are recorded in `work/sigma/1.0.20/resources/inventory.json`, with source hash, byte ranges and output hashes. Applying the same recovered AES-256-CTR operation to the complete resource produces `work/sigma/1.0.20/sigma-decoded.bin`, 216,800 bytes, SHA-256 `3fc925cb7d12f3179a27248b2d86868d0556d7f36be33092b39bcced254c9e20`. The matching `.transform.json` records the operation and successful reverse transformation.

[sigma-release-comparison.md](sigma-release-comparison.md) records semantic matches and changes, including unchanged base VID/PID acceptance and 32-/39-byte input parsing, plus handbrake and shifter changes. Matching resource offsets do not establish matching code or behavior; the comparison uses decoded predicates and field use.

## Simagic installer and relevant firmware

7-Zip identifies an x86 PE installer carrying **NSIS-3 Unicode**, solid **LZMA:26** data. `work/simagic/installer-list.txt` is the complete listing; `work/simagic/extract.log` reports successful extraction of **2,847 files**, totaling **1,072,364,103 bytes**. The package includes executable/DLL applications, Chromium resources, device configuration, and multiple `.sfu` firmware releases.

The compressed NSIS container begins at EXE offset **294,912 (`0x48000`)** and has physical size **432,398,846 bytes**, excluding the two reported trailing bytes. SHA-256 of precisely that range is `ac7c083188a696eedd5c86658b338045cada7f868332b722b148ab4175d1b83b`. The EXE also declares a PE security directory at file offset `0x19CA6200`, length `0x28C0`. Presence of that certificate table is not a successful signature verification.

Extraction used:

```sh
7zz l 'originals/SimPro 3.2.3.13713/SimPro-V3.2.3.13713-072a9e42-Setup.exe'
7zz x 'originals/SimPro 3.2.3.13713/SimPro-V3.2.3.13713-072a9e42-Setup.exe' \
  -owork/simagic/3.2.3.13713 -y
```

This parses compressed bytes on macOS; it does not run the installer or its scripts. Each member's original archive path and filename is preserved, including literal `$APPDATA` directories. Derived files belong outside this extraction directory.

[simagic-extraction-manifest.json](simagic-extraction-manifest.json) records the source hash, operation, compressed container range/hash, command, and every extracted member's size and SHA-256. Individual compressed input ranges are explicitly `null`: solid compression does not provide a one-to-one range for each decompressed file. The source container plus member identity establishes reproducible lineage without inventing a byte mapping.

The exact wheel payload relevant to this investigation is:

- Member: `$APPDATA/Local/Simagic/Simpro3/firmware/wheel/zf/ZeusFormula_App-A1.1.15.13445-eb889282.sfu`.
- File size: **123,936 bytes**.
- SHA-256: `571535e07edc9efb8c7403eecf60caf861631ae9bf312a2755acc4d4e26b7e7f`.
- Firmware version string from filename: **A1.1.15.13445**, build identifier `eb889282`. This is the shipped comparison version, not a claim about the user's installed wheel firmware.

The SFU header is **64 bytes** and begins with `SIMPROSFU100`. Its declared content length is **123,872**. The complete encoded payload range is **`[0x40,0x1E420)`**. The recovered AES-256-CTR transform of precisely that range produces `work/simagic/zeus-formula-decoded.bin`, 123,872 bytes, SHA-256 `85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a`. `work/simagic/zeus-formula-decoded.bin.transform.json` records the input hash/range, operation, key/IV source instructions, output hash and successful byte-exact reverse transformation. No prefix or suffix was silently trimmed. Interpretation of its 512-byte pre-vector region and integrity fields remains separate from the established decoding operation.

See [simagic-analysis.md](simagic-analysis.md) for interpretation of its bytes and the related host application. The package also includes Zeus GT/Sport, GT Neo, Neo X and Alpha firmware; these are available as comparison artifacts, but filenames alone do not establish cross-device protocol compatibility.

## Reproduction and verification

```sh
source scripts/env.sh
work/tools/python/bin/python scripts/inspect_pe.py \
  'originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe' \
  work/sigma/1.1.5/resources
work/tools/python/bin/python scripts/inventory_packages.py
```

The PE script refuses a differing pre-existing resource output. The inventory script verified original bytes, all **750** exact Sigma resource slices, and all **2,847** Simagic extraction members. Hashes identify bytes and detect changes; they do not by themselves verify vendor signatures or device acceptance.
