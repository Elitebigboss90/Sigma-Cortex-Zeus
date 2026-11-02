#!/usr/bin/env python3
"""Verify dev3 provenance and preserve auxiliary sources; never access devices."""
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'work/sigma/zeus-dev3'


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    build = json.loads((OUT / 'build-manifest.json').read_text())
    tests = json.loads((OUT / 'emulator-verification.json').read_text())
    package = json.loads((OUT / 'package-manifest.json').read_text())
    assert build['base_version'] == '1.1.8'
    assert tests['status'] == 'PASS' and len(tests['checks']) == 16
    assert tests['image_sha256'] == build['artifacts']['plaintext']['sha256']
    assert tests['capture_replay']['unique_frames'] == 99
    for item in [build['original'], *build['artifacts'].values(), package['original'], package['candidate']]:
        p = ROOT / item['path']
        assert p.stat().st_size == item['size'] and digest(p) == item['sha256']
    for name, sha in build['source_files'].items():
        assert digest(ROOT / name) == sha
    for item in build['source_snapshots']:
        assert digest(ROOT / item['path']) == item['sha256']
    for item in tests['capture_replay']['sources']:
        assert digest(ROOT / item['path']) == item['sha256']
    assert digest(ROOT / 'scripts/verify_sigma118_patch.py') == tests['verification_script_sha256']
    assert digest(ROOT / 'scripts/package_sigma118_candidate.py') == package['script_sha256']
    assert package['native_executable_sections_unchanged']
    assert package['original_prefix_unchanged_outside_declared_edits']
    assert package['unchanged_other_resources'] == 749

    original = (ROOT / build['original']['path']).read_bytes()
    candidate = (ROOT / build['artifacts']['plaintext']['path']).read_bytes()
    allowed = set()
    for edit in build['edits']:
        off = edit['offset']
        old, new = bytes.fromhex(edit['original_hex']), bytes.fromhex(edit['replacement_hex'])
        assert original[off:off + len(old)] == old
        assert candidate[off:off + len(new)] == new
        allowed.update(range(off, off + len(old)))
    actual = [i for i in range(len(original)) if candidate[i] != original[i]]
    assert len(actual) == 7 and set(actual) <= allowed
    assert candidate[len(original) - 8:len(original)] == original[-8:]
    assert (len(original) + 2047) // 2048 == (len(candidate) + 2047) // 2048 == 94
    assert 0x08020000 + len(candidate) == 0x0804eec0

    previous = ROOT / 'work/sigma/zeus-dev2'
    previous_build = json.loads((previous / 'build-manifest.json').read_text())
    previous_package = json.loads((previous / 'package-manifest.json').read_text())
    for item in [*previous_build['artifacts'].values(), previous_package['candidate']]:
        assert digest(ROOT / item['path']) == item['sha256']
    for name, sha in previous_build['source_files'].items():
        assert digest(ROOT / name) == sha

    snapshots = []
    for name in ['scripts/verify_sigma118_patch.py', 'scripts/package_sigma118_candidate.py',
                 'scripts/sigma118_memory.py', 'scripts/bindings118_evidence.py',
                 'scripts/bindings118_emulate.py', 'scripts/finalize_sigma118_candidate.py']:
        src, dst = ROOT / name, OUT / 'source' / name
        dst.parent.mkdir(parents=True, exist_ok=True)
        if dst.exists():
            assert dst.read_bytes() == src.read_bytes(), name
        else:
            dst.write_bytes(src.read_bytes())
        snapshots.append({'path': str(dst.relative_to(ROOT)), 'sha256': digest(dst)})
    for name in ['reports/firmware-candidate-dev3.md', 'reports/sigma-1.1.8-analysis.md',
                 'reports/sigma-1.1.8-memory.md', 'reports/sigma-1.1.8-usb-bindings.md',
                 'reports/sigma-1.1.8-updater.md']:
        p = ROOT / name
        for link in re.findall(r'\]\(([^)]+)\)', p.read_text()):
            if '://' not in link:
                assert (p.parent / link.split('#')[0]).exists(), (name, link)
    result = {'status': 'PASS', 'build_id': 'zeus-dev3', 'base_version': '1.1.8',
              'plaintext_sha256': build['artifacts']['plaintext']['sha256'],
              'encoded_sha256': build['artifacts']['encoded']['sha256'],
              'updater_sha256': package['candidate']['sha256'],
              'emulator_checks_passed': 16, 'measured_frames_replayed': 99,
              'original_bytes_changed': 7, 'application_pages': 94,
              'final_page_unused_bytes': 320, 'other_updater_resources_unchanged': 749,
              'native_updater_code_unchanged': True,
              'prior_1_1_5_candidate_and_sources_preserved': True,
              'sources_and_artifacts_verified': True, 'local_report_links_valid': True,
              'auxiliary_source_snapshots': snapshots,
              'hardware_flashed': False, 'bootloader_acceptance_verified': False,
              'limits': 'Offline image/CPU/package consistency; USB/PS5 and failed-image restoration untested'}
    (OUT / 'final-verification.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ['status', 'base_version', 'emulator_checks_passed',
                                             'measured_frames_replayed', 'prior_1_1_5_candidate_and_sources_preserved']}))


if __name__ == '__main__':
    main()
