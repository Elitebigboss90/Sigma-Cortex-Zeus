#!/usr/bin/env python3
"""Copy the unchanged supplied 1.1.8 updater into a Windows detection handoff."""
import hashlib
import json
from pathlib import Path
import zipfile

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'originals/SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA/SIGMA_Converter_V1.1.8.exe'
EXPECTED = '233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a'
OUT = ROOT / 'work/sigma/windows-detection-check-1.1.8'


def digest(data):
    return hashlib.sha256(data).hexdigest()


def save(path, data):
    assert path != SOURCE
    path.write_bytes(data)


def main():
    data = SOURCE.read_bytes()
    assert len(data) == 3630592 and digest(data) == EXPECTED
    OUT.mkdir(parents=True, exist_ok=True)
    save(OUT / SOURCE.name, data)
    instructions = '''SIGMA 1.1.8 WINDOWS DETECTION CHECK

This folder contains an unchanged copy of the supplied stock 1.1.8 BETA updater.
It contains no Zeus-modified firmware. Its purpose here is detection only.
Do not click Update during this check: that begins the write workflow.

1. Extract this ZIP on the Windows PC. Disconnect Sigma's wheelbase, pedals,
   wheel and console. Connect only its console/PC USB port to the Windows PC,
   without holding a button. Prefer a known working direct USB data connection.
   If using the KVM, record that fact and do not switch hosts during detection.
2. Open SIGMA_Converter_V1.1.8.exe. Note the exact connected/device status and
   CURRENT/DEVICE firmware version. A target/update version of 1.1.8 identifies
   the package; it does not establish the version installed on the device.
   Do not click Update. Close the updater after recording the display.
3. Unplug Sigma. Hold OK while reconnecting the same console/PC USB port to
   the same Windows connection; keep holding for approximately five seconds,
   then release. Confirm Sigma's display says Bootload mode.
4. Reopen the same stock updater. Record its exact status and version text,
   including any BL suffix. A different version in Bootload mode may describe
   the bootloader; record it without treating it as the installed app version.
   Do not click Update. Close the updater.
5. Unplug Sigma, then reconnect without holding a button. Confirm the normal
   screen returns. Record any detection failure or USB disconnection.

Report back:
- Normal mode: exact updater device/status and current-version text.
- Bootload mode: exact updater device/status and version text.
- Normal screen returned after the final power cycle: yes/no.
- Connection: direct USB or KVM; any intermittent disconnects.

Optional copy-integrity check in PowerShell, from this extracted folder:
Get-FileHash -Algorithm SHA256 .\\SIGMA_Converter_V1.1.8.exe
Expected SHA-256:
233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a

This hash establishes identity with the supplied project file, not independent
vendor authentication. Detection does not test stock restoration, modified-image
acceptance or recovery from a failed application. No installation is requested.
'''
    save(OUT / 'READ-ME-FIRST.txt', instructions.replace('\n', '\r\n').encode())
    manifest = {
        'purpose': 'Windows stock-updater detection only; no Update action',
        'source': str(SOURCE.relative_to(ROOT)), 'source_sha256': EXPECTED,
        'source_size': len(data), 'operation': 'byte-identical copy',
        'source_byte_range': [0, len(data)], 'output': SOURCE.name,
        'output_sha256': EXPECTED, 'original_filename_preserved': True,
        'script_sha256': digest(Path(__file__).read_bytes()),
        'modified_firmware_included': False,
    }
    save(OUT / 'manifest.json', (json.dumps(manifest, indent=2) + '\n').encode())
    members = sorted(p for p in OUT.iterdir() if p.name != 'SHA256SUMS.txt')
    sums = ''.join(f'{digest(p.read_bytes())}  {p.name}\n' for p in members)
    save(OUT / 'SHA256SUMS.txt', sums.encode())
    archive = OUT.with_name(OUT.name + '.zip')
    # Fixed ZIP metadata allows a byte-reproducible handoff on this environment.
    import io
    buffer = io.BytesIO()
    with zipfile.ZipFile(buffer, 'w') as z:
        for path in sorted(OUT.iterdir()):
            info = zipfile.ZipInfo(OUT.name + '/' + path.name, (2026, 11, 2, 0, 0, 0))
            info.compress_type = zipfile.ZIP_DEFLATED
            info.external_attr = 0o100644 << 16
            z.writestr(info, path.read_bytes())
    save(archive, buffer.getvalue())
    with zipfile.ZipFile(archive) as z:
        assert z.testzip() is None
        assert digest(z.read(OUT.name + '/' + SOURCE.name)) == EXPECTED
    save(archive.with_suffix('.zip.sha256'),
         f'{digest(archive.read_bytes())}  {archive.name}\n'.encode())
    assert digest(SOURCE.read_bytes()) == EXPECTED
    print(json.dumps({'archive': str(archive.relative_to(ROOT)),
                      'sha256': digest(archive.read_bytes()),
                      'updater_unchanged': True, 'device_accessed': False}))


if __name__ == '__main__':
    main()
