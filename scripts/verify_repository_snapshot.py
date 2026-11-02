#!/usr/bin/env python3
"""Verify staged file bytes, LFS pointers and inclusion of every project ZIP."""
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def git(*args, data=None):
    return subprocess.check_output(['git', *args], cwd=ROOT, input=data)


def main():
    entries = []
    for row in git('ls-files', '--stage', '-z').split(b'\0'):
        if not row:
            continue
        meta, name = row.split(b'\t', 1)
        mode, oid, stage = meta.decode().split()
        assert stage == '0' and mode in ('100644', '100755'), (name, mode, stage)
        entries.append((name.decode(), oid))
    names = {name for name, _ in entries}
    attributes = git('check-attr', '-z', '--stdin', 'filter',
                     data=b'\0'.join(name.encode() for name, _ in entries) + b'\0').split(b'\0')
    lfs_names = {attributes[i].decode() for i in range(0, len(attributes)-1, 3)
                 if attributes[i+2] == b'lfs'}
    lfs_rows, zip_rows = [], []
    total = 0
    for name, oid in entries:
        path = ROOT / name
        size = path.stat().st_size
        h1 = hashlib.sha1(f'blob {size}\0'.encode())
        h256 = hashlib.sha256()
        with path.open('rb') as source:
            while chunk := source.read(1024*1024):
                h1.update(chunk)
                h256.update(chunk)
        digest = h256.hexdigest()
        if name in lfs_names:
            expected = ('version https://git-lfs.github.com/spec/v1\n'
                        f'oid sha256:{digest}\nsize {size}\n').encode()
            assert git('cat-file', 'blob', oid) == expected, name
            lfs_rows.append({'path': name, 'size': size, 'sha256': digest})
        else:
            assert h1.hexdigest() == oid, f'Staged/local content mismatch: {name}'
            assert size <= 100*1024*1024, f'File exceeds ordinary Git size limit: {name}'
        if name.lower().endswith('.zip'):
            zip_rows.append({'path': name, 'size': size, 'sha256': digest,
                             'storage': 'lfs' if name in lfs_names else 'git'})
        total += size
    disk_zips = {str(p.relative_to(ROOT)) for p in ROOT.rglob('*')
                 if '.git' not in p.parts and p.is_file() and p.suffix.lower() == '.zip'}
    assert disk_zips <= names, f'ZIPs omitted: {disk_zips - names}'
    assert not git('ls-files', '--others', '--exclude-standard'), 'Untracked project files'
    result = {'status': 'PASS', 'tracked_files': len(entries), 'total_content_bytes': total,
              'lfs_files': len(lfs_rows), 'lfs_bytes': sum(x['size'] for x in lfs_rows),
              'zip_files': len(zip_rows), 'all_project_zips_included': True,
              'staged_bytes_or_lfs_sha256_match_local_files': True,
              'lfs_objects': lfs_rows, 'zips': zip_rows}
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
