"""Verify, snapshot and ZIP dev10 without opening devices or running an updater."""
import hashlib
import json
from pathlib import Path
import zipfile

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'work/sigma/zeus-dev10'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
load = lambda name: json.loads((OUT / name).read_text())
build = load('build-manifest.json')
package = load('package-manifest.json')
assert build['normal_reports'] and build['reconnect_cleanup'] and not build['diagnostic_fields']
for item in [build['original'], *build['artifacts'].values(), package['original'], package['candidate']]:
    p = ROOT / item['path']
    assert sha(p) == item['sha256'] and p.stat().st_size == item['size']
assert sha(ROOT / 'patch/sigma118/normal_dev10.s') == build['source_sha256']
assert sha(ROOT / 'scripts/build_sigma118_normal_recovery.py') == build['builder_sha256']
assert sha(ROOT / 'scripts/package_sigma118_candidate.py') == package['script_sha256']
for name, digest in build['source_files'].items():
    assert sha(ROOT / name) == digest
proofs = {}
for name, script in [('emulator-verification.json', 'verify_sigma118_normal_recovery.py'),
                     ('coexistence-verification.json', 'verify_sigma118_normal_recovery_coexistence.py'),
                     ('enumeration-verification.json', 'verify_sigma118_normal_enumeration.py'),
                     ('reconnect-verification.json', 'verify_sigma118_reconnect.py')]:
    proof = load(name)
    assert proof['status'] == 'PASS' and proof['image_sha256'] == build['artifacts']['plaintext']['sha256']
    assert sha(ROOT / 'scripts' / script) == proof.get('verification_script_sha256', proof.get('script_sha256'))
    proofs[name] = sha(OUT / name)
assert package['native_executable_sections_unchanged'] and package['unchanged_other_resources'] == 749
sources = ['patch/sigma118/normal_dev10.s', *build['source_files'],
    'scripts/build_sigma118_normal_recovery.py', 'scripts/package_sigma118_candidate.py',
    'scripts/verify_sigma118_normal_recovery.py', 'scripts/verify_sigma118_normal_recovery_coexistence.py',
    'scripts/verify_sigma118_normal_enumeration.py', 'scripts/verify_sigma118_reconnect.py',
    'scripts/diagnose_sigma118_unmatched_claims.py', 'scripts/diagnose_sigma118_nested_hubs.py',
    'scripts/diagnose_sigma118_usb_init.py', 'scripts/finalize_sigma118_normal_recovery.py']
snapshots = []
for name in sources:
    src, dst = ROOT / name, OUT / 'source' / name
    dst.parent.mkdir(parents=True, exist_ok=True)
    if dst.exists():
        assert dst.read_bytes() == src.read_bytes()
    else:
        dst.write_bytes(src.read_bytes())
    snapshots.append(dict(path=dst.relative_to(OUT).as_posix(), sha256=sha(dst)))
helper = OUT / 'inspect_windows_hid.ps1'
assert not helper.exists()
helper.write_bytes((ROOT / 'scripts/inspect_windows_hid.ps1').read_bytes())
result = dict(status='PASS', build_id=build['build_id'], updater_sha256=package['candidate']['sha256'],
    image_sha256=build['artifacts']['plaintext']['sha256'], proofs=proofs, sources=snapshots,
    native_updater_code_unchanged=True, unchanged_other_resources=749,
    hardware_installed=False, physical_reconnect_verified=False, ps5_verified=False)
final = OUT / 'final-verification.json'
assert not final.exists()
final.write_text(json.dumps(result, indent=2) + '\n')
zip_path = OUT.with_suffix('.zip')
assert not zip_path.exists()
paths = sorted(p for p in OUT.rglob('*') if p.is_file())
with zipfile.ZipFile(zip_path, 'x', zipfile.ZIP_DEFLATED) as archive:
    for p in paths:
        archive.write(p, (Path(OUT.name) / p.relative_to(OUT)).as_posix())
with zipfile.ZipFile(zip_path) as archive:
    assert archive.testzip() is None
    for p in paths:
        assert archive.read((Path(OUT.name) / p.relative_to(OUT)).as_posix()) == p.read_bytes()
zip_proof = dict(status='PASS', archive=zip_path.relative_to(ROOT).as_posix(), sha256=sha(zip_path),
    entries=len(paths), extracted_bytes_verified=True, updater_sha256=package['candidate']['sha256'])
sidecar = zip_path.with_suffix('.zip.manifest.json')
assert not sidecar.exists()
sidecar.write_text(json.dumps(zip_proof, indent=2) + '\n')
print(json.dumps(zip_proof))
