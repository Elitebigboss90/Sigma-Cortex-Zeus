#!/usr/bin/env python3
"""Inventory/extract the two pinned distributor-linked ZIPs; never execute members."""
import hashlib
import json
import stat
import struct
import zipfile
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[1]


def sha(data):
    return hashlib.sha256(data).hexdigest()


def write_same(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        if path.read_bytes() != data:
            raise ValueError(f"Refusing differing existing output: {path}")
    else:
        with path.open("xb") as stream:
            stream.write(data)


def main():
    manifest = json.loads((ROOT / "reports/sigma-legacy-input-manifest.json").read_text())
    results = []
    for item in manifest:
        source = ROOT / item["path"]
        raw = source.read_bytes()
        assert len(raw) == item["size"] and sha(raw) == item["sha256"], source
        if source.suffix.lower() != ".zip":
            continue
        destination = ROOT / "work/sigma" / item["version"] / "package"
        members = []
        with zipfile.ZipFile(source) as archive:
            assert sum(i.file_size for i in archive.infolist()) < 100_000_000
            for info in archive.infolist():
                name = PurePosixPath(info.filename)
                assert not name.is_absolute() and ".." not in name.parts
                assert "\\" not in info.filename and not stat.S_ISLNK(info.external_attr >> 16)
                if info.is_dir():
                    continue
                header = info.header_offset
                assert raw[header:header+4] == b"PK\x03\x04"
                name_length, extra_length = struct.unpack_from("<HH", raw, header + 26)
                start = header + 30 + name_length + extra_length
                encoded = raw[start:start+info.compress_size]
                assert len(encoded) == info.compress_size and info.compress_type == zipfile.ZIP_DEFLATED
                data = archive.read(info)  # Also verifies the member's ZIP CRC32.
                output = destination.joinpath(*name.parts)
                write_same(output, data)
                members.append({"member": info.filename, "output": str(output.relative_to(ROOT)),
                                "operation": "ZIP method 8 raw DEFLATE decompression; ZIP CRC32 checked",
                                "source_sha256": sha(raw), "source_offset": start,
                                "source_length": info.compress_size, "source_range_sha256": sha(encoded),
                                "size": len(data), "sha256": sha(data), "zip_crc32": f"{info.CRC:08x}"})
        results.append({"source": item["path"], "source_sha256": sha(raw), "members": members})
    output = ROOT / "work/sigma/public-recovery-research/extraction-manifest.json"
    write_same(output, (json.dumps(results, indent=2) + "\n").encode())
    print(f"Verified originals and extracted {sum(len(r['members']) for r in results)} members from {len(results)} ZIPs.")


if __name__ == "__main__":
    main()
