#!/usr/bin/env python3
"""Verify preserved inputs and hash extracted package members without modifying them."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def digest(path, offset=0, length=None):
    h = hashlib.sha256()
    with path.open('rb') as stream:
        stream.seek(offset)
        remaining = length
        while remaining is None or remaining:
            block = stream.read(1024 * 1024 if remaining is None else min(1024 * 1024, remaining))
            if not block:
                if remaining: raise ValueError(f'Truncated source range: {path}')
                break
            h.update(block)
            if remaining is not None: remaining -= len(block)
    return h.hexdigest()

def main():
    supplied = json.loads((ROOT/'reports/input-manifest.json').read_text())
    for manifest in ['reports/additional-input-manifest.json','reports/zeus-manual-input-manifest.json']:
        additional = ROOT/manifest
        if additional.exists(): supplied += json.loads(additional.read_text())
    for item in supplied:
        for key in ['source', 'original_copy']:
            if key not in item: continue
            p = ROOT/item[key]
            assert p.stat().st_size == item['size'] and digest(p) == item['sha256'], p
    download = json.loads((ROOT/'reports/simagic-download-manifest.json').read_text())
    package = ROOT/download['path']
    assert package.stat().st_size == download['size'] and digest(package) == download['sha256']

    resources = json.loads((ROOT/'work/sigma/1.1.5/resources/inventory.json').read_text())
    for item in resources['resources']:
        output = ROOT/item['output']
        assert output.stat().st_size == item['length'] and digest(output) == item['sha256'], output
        assert digest(ROOT/resources['source'], item['offset'], item['length']) == item['sha256'], output

    extracted = ROOT/'work/simagic/3.2.3.13713'
    members = []
    for p in sorted(extracted.rglob('*')):
        if p.is_symlink(): raise ValueError(f'Unexpected symlink: {p}')
        if not p.is_file(): continue
        members.append({'member': p.relative_to(extracted).as_posix(), 'path': p.relative_to(ROOT).as_posix(),
                        'size': p.stat().st_size, 'sha256': digest(p),
                        'source_byte_range': None,
                        'range_limit': 'Solid LZMA extraction: no one-to-one compressed input byte range established.'})
    result = {
        'source': download['path'], 'source_sha256': download['sha256'],
        'operation': '7-Zip 26.01 NSIS-3 Unicode / solid LZMA:26 extraction',
        'command_used': "7zz x 'originals/SimPro 3.2.3.13713/SimPro-V3.2.3.13713-072a9e42-Setup.exe' -owork/simagic/3.2.3.13713 -y",
        'archive_listing': 'work/simagic/installer-list.txt', 'extraction_log': 'work/simagic/extract.log',
        'container_range': {'offset': 294912, 'length': 432398846,
                            'sha256': digest(package, 294912, 432398846),
                            'evidence': '7-Zip PE child [0] Offset; NSIS Physical Size; excludes two trailing bytes'},
        'member_count': len(members), 'total_member_bytes': sum(m['size'] for m in members), 'members': members,
    }
    (ROOT/'reports/simagic-extraction-manifest.json').write_text(json.dumps(result, indent=2)+'\n')
    docs=[]
    for p in sorted((ROOT/'work/tools/rea-docs').glob('*.md')):
        docs.append({'path':p.relative_to(ROOT).as_posix(), 'size':p.stat().st_size,
                     'sha256':digest(p), 'source_url':'https://raw.githubusercontent.com/morluto/rea/main/docs/'+p.name})
    (ROOT/'reports/rea-documentation-manifest.json').write_text(json.dumps(docs, indent=2)+'\n')
    print(f'Originals verified; {len(resources["resources"])} Sigma resource slices verified; {len(members)} SimPro members, {result["total_member_bytes"]} bytes hashed.')
    print('Zeus Formula:', next(m for m in members if '/wheel/zf/' in m['member']))

if __name__ == '__main__': main()
