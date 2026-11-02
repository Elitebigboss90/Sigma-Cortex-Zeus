#!/usr/bin/env python3
"""Supplement dev3 checks with non-neutral base inputs; never access USB."""
import hashlib
import json
import runpy
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'work/sigma/zeus-dev3'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    build = json.loads((OUT / 'build-manifest.json').read_text())
    package = json.loads((OUT / 'package-manifest.json').read_text())
    artifacts = [*build['artifacts'].values(), package['candidate']]
    for item in artifacts:
        assert sha(ROOT / item['path']) == item['sha256']
    # Reuse the pinned emulator and execute its original checks, without edits.
    sys.argv = ['verify_sigma118_patch.py', '--build-id', 'zeus-dev3']
    model = runpy.run_path(str(ROOT / 'scripts/verify_sigma118_patch.py'))
    Machine, state = model['Machine'], model['STATE']
    output = 0x20004608
    cases = []

    def frame(usages, rx, ry):
        bits = sum(1 << (usage - 1) for usage in usages)
        return bytes([1, rx, ry]) + bits.to_bytes(15, 'little') + bytes(5)

    for index in range(8):
        original, candidate = Machine(False), Machine()
        original.call(0x08024720)
        candidate.call(0x08024720)
        candidate.identity()
        # Explicit transaction-boundary stubs: this checks release/timeout
        # merging, not physical USB enumeration or address-pool cleanup.
        candidate.stubs[0x08028e50] = lambda m: 0
        candidate.stubs[0x08028fb0] = lambda m: 0
        axes = [(index * 8191 + n * 21845) & 0xffff for n in range(4)]
        hat = [8, 0, 2, 4, 6, 1, 3, 7][index]
        base_buttons = [(index * 5 & 15) << 4 | hat,
                        (index * 37) & 255, (index * 73) & 255]
        for machine in [original, candidate]:
            machine.put(0x20004548, bytes(base_buttons[:2]))
            machine.put(0x2000455c, bytes(base_buttons[2:]))
            machine.put(0x20004570, struct.pack('<4H', *axes))
            machine.put(0x20004578, bytes([index * 31, index & 1,
                                         (index >> 1) & 1, index]))
            machine.put(0x200020fc, b'\0')
            machine.put(0x20001fb6, bytes([(index >> 2) & 1]))
        original.call(0x080460c0)
        baseline = original.read(output, 64)
        assert baseline[43:51] == struct.pack('<4H', *axes)
        assert baseline[51:54] == bytes([index, 255-index*31, 255-index*31])
        checks = []

        def compare(label, expected):
            candidate.call('zeus_merge_hook')
            actual = candidate.read(output, 64)
            assert actual == bytes(expected), (index, label, actual.hex(), bytes(expected).hex())
            assert actual[:5] == baseline[:5] and actual[10:] == baseline[10:]
            assert actual[5] & baseline[5] & 0xf0 == baseline[5] & 0xf0
            assert actual[6] & baseline[6] == baseline[6]
            assert actual[7] & baseline[7] == baseline[7]
            checks.append(label)

        compare('inactive equals stock', baseline)
        held = frame([13, 43, 44], 127, 64)
        candidate.report(held, tick=100)
        expected = bytearray(baseline)
        expected[5] &= 0xf0
        expected[6] |= 0x42
        expected[8:10] = bytes([255, 129])
        compare('right shift, left center, up and analog coexist', expected)
        candidate.report(frame([13], 0, 127), tick=105)
        expected = bytearray(baseline)
        expected[6] |= 2
        expected[8:10] = bytes([0, 255])
        compare('Zeus direction release restores held base hat', expected)
        candidate.report(frame([], 0, 0), tick=110)
        compare('neutral Zeus restores full stock report', baseline)
        candidate.report(held, tick=200)
        candidate.put(0x20000040, b'\0')
        candidate.w32(0x20002104, 451)
        candidate.call('zeus_poll', state)
        assert candidate.read(0x20000040, 1) == b'\1'
        compare('timeout releases Zeus while preserving base', baseline)
        candidate.report(held, tick=500)
        candidate.put(0x20000040, b'\0')
        candidate.call('zeus_release', state)
        assert candidate.read(0x20000040, 1) == b'\1'
        compare('release wrapper preserves base', baseline)
        candidate.call('zeus_on_init', state)
        candidate.report(frame([14, 48, 66], 64, 0), tick=600)
        expected = bytearray(baseline)
        expected[5] = (expected[5] & 0xf0) | 2
        expected[6] |= 0x81
        expected[8:10] = bytes([129, 0])
        compare('fresh callback accepts inputs after release', expected)
        cases.append({'index': index, 'base_axes': axes,
                      'base_report_hex': baseline.hex(), 'checks': checks})

    for item in artifacts:
        assert sha(ROOT / item['path']) == item['sha256']
    result = {
        'status': 'PASS', 'build_id': 'zeus-dev3',
        'image_sha256': build['artifacts']['plaintext']['sha256'],
        'script_sha256': sha(Path(__file__)),
        'emulator_script_sha256': sha(ROOT / 'scripts/verify_sigma118_patch.py'),
        'base_patterns': len(cases), 'report_comparisons': sum(len(c['checks']) for c in cases),
        'cases': cases, 'candidate_artifacts_unchanged': True,
        'executed_addresses': {'stock_builder': '080460C0', 'constructor': '08024720',
                               'merge': build['symbols']['zeus_merge_hook'],
                               'input': build['symbols']['zeus_input']},
        'stubs': ['08028E50 original release boundary', '08028FB0 original poll boundary'],
        'limits': ['Synthetic non-neutral base RAM inputs; no physical USB transactions',
                   'Release and reinitialization callback behavior, not physical detach/reattach',
                   'No bootloader acceptance, concurrency, sustained heap or PS5 validation'],
    }
    (OUT / 'coexistence-verification.json').write_text(json.dumps(result, indent=2) + '\n')
    snapshot = OUT / 'source/scripts/verify_sigma118_coexistence.py'
    if snapshot.exists():
        assert snapshot.read_bytes() == Path(__file__).read_bytes()
    else:
        snapshot.write_bytes(Path(__file__).read_bytes())
    print(f"PASS: {len(cases)} base patterns, {result['report_comparisons']} exact report comparisons; artifacts unchanged")


if __name__ == '__main__':
    main()
