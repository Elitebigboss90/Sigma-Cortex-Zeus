#!/usr/bin/env python3
"""Extract the user-supplied Sigma 1.1.8 ZIP without modifying originals."""
import json
import stat
import struct
import zipfile
from pathlib import Path, PurePosixPath
from inventory_sigma_legacy import sha, write_same

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'originals/SIGMA v1.1.8 BETA/SIGMA v1.1.8 BETA.zip'
EXPECTED = 'bd176e95346349fa9352a05ba536e4f4447e61c24e26b4b54dfe2266cb98a9d4'
OUT = ROOT / 'work/sigma/1.1.8'


def main():
    raw = SOURCE.read_bytes()
    assert sha(raw) == EXPECTED and len(raw) == 2035961
    rows = []
    with zipfile.ZipFile(SOURCE) as archive:
        assert archive.testzip() is None
        for info in archive.infolist():
            path = PurePosixPath(info.filename)
            assert not path.is_absolute() and '..' not in path.parts
            assert '\\' not in info.filename and not stat.S_ISLNK(info.external_attr >> 16)
            if info.is_dir():
                continue
            assert info.compress_type == zipfile.ZIP_DEFLATED
            offset = info.header_offset
            assert raw[offset:offset + 4] == b'PK\x03\x04'
            n, x = struct.unpack_from('<HH', raw, offset + 26)
            start = offset + 30 + n + x
            compressed = raw[start:start + info.compress_size]
            data = archive.read(info)
            supplied_copy = SOURCE.parent.joinpath(*path.parts)
            assert supplied_copy.read_bytes() == data, supplied_copy
            output = OUT / 'package' / path
            write_same(output, data)
            rows.append({'member': info.filename, 'source_sha256': EXPECTED,
                         'range': {'offset': start, 'length': len(compressed)},
                         'range_sha256': sha(compressed),
                         'operation': 'ZIP method 8 DEFLATE; member CRC32 verified',
                         'output': str(output.relative_to(ROOT)), 'size': len(data),
                         'sha256': sha(data), 'zip_crc32': f'{info.CRC:08x}',
                         'matching_supplied_copy': str(supplied_copy.relative_to(ROOT))})
    manifest = {'source': str(SOURCE.relative_to(ROOT)), 'source_sha256': EXPECTED,
                'source_size': len(raw), 'provenance': 'User-supplied local package; vendor signature not established',
                'version_label': '1.1.8 BETA', 'members': rows, 'originals_modified': False}
    write_same(OUT / 'extraction-manifest.json', (json.dumps(manifest, indent=2) + '\n').encode())
    print(json.dumps({'members': len(rows), 'source_sha256': EXPECTED, 'supplied_copies_match_zip': True}))


if __name__ == '__main__':
    main()
