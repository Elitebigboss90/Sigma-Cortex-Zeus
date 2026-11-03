"""Exercise native hub detach/rebind and output preservation without hardware."""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build-id', default='zeus-dev10')
args = parser.parse_args()
sys.argv = [__file__, '--build-id', args.build_id]
fixture = ROOT / 'scripts/verify_sigma118_normal_enumeration.py'
ns = {'__file__': str(fixture)}
exec(compile(fixture.read_text().split('for vendor in (False, True):')[0], str(fixture), 'exec'), ns)
IMAGE, build, OUT = (ns[k] for k in ('IMAGE', 'build', 'OUT'))
nested, Machine, select, event, state, STATE = (ns[k] for k in ('nested', 'Machine', 'select', 'event', 'state', 'STATE'))
symbols = {k: int(v, 16) for k, v in build['symbols'].items()}
H0, H1, H2 = nested.ORIGINAL_HUB, STATE + 180, STATE + 204
rows = []

for root_port, inner_port in ((1, 1), (4, 3)):
    nested.model.IMAGE = IMAGE
    m = Machine()
    read = lambda p, n: bytes(m.u.mem_read(p, n))
    m.u.mem_write(STATE - 16, b'\xa5' * 16)
    m.u.mem_write(STATE + 228, b'\xb6' * 28)
    m.call(0x08024720)
    m.select('sigma_hub', (0x1a40, 0x0101))
    assert m.call(0x0802a400, nested.model.HOST, 0, 0, 0) == 0
    for name, pid, port in (('base', 0x0522, 2), ('pedals', 0x0525, 3)):
        select(m, name, 0x0483, pid)
        event(m, H0, port)
    known = {p: state(m, p) for p in (0x200008e8, 0x20003ab0)}
    assert all(v['address'] and v['polling'] for v in known.values())
    m.u.mem_write(0x20004548, bytes([8, 0x10]))
    m.u.mem_write(0x20004570, struct.pack('<4H', 24000, 1234, 4567, 65432))
    m.call(0x080460c0)
    baseline = read(0x20004608, 64)

    def bind_hub(parent, port):
        m.select('xtend_hub', (0x05e3, 0x0610))
        event(m, parent, port)

    def bind_wheel():
        select(m, 'unrelated_child', 0x1234, 0x5678)
        event(m, H2, 1)
        m.select('zeus')
        event(m, H2, 2)
        assert state(m, STATE)['polling'] == 1

    def paddle(usage):
        frame = bytes([1, 0, 0]) + (1 << (usage - 1)).to_bytes(15, 'little') + bytes(5)
        m.u.mem_write(0x20007200, frame)
        m.u.mem_write(0x20006620, struct.pack('<I', 0x20007200))
        m.call(symbols['zeus_input'], STATE, STATE, 1, 23)
        m.call(symbols['zeus_merge_hook'])
        expected = bytearray(baseline)
        expected[6] |= 2 if usage == 13 else 1
        assert read(0x20004608, 64) == expected

    bind_hub(H0, root_port)
    bind_hub(H1, inner_port)
    bind_wheel()
    assert read(H1 + 21, 2) == bytes([1, root_port])
    assert read(H2 + 21, 2) == bytes([2, inner_port])
    for level in ('whole_xtend', 'inner_hub', 'wheel_only'):
        for cycle in range(5):
            paddle(13)
            parent, port = {'whole_xtend': (H0, root_port), 'inner_hub': (H1, inner_port), 'wheel_only': (H2, 2)}[level]
            m.u.mem_write(0x20007000, bytes.fromhex('00010100'))
            assert m.call(0x0802baf0, parent, port, 0x20007000) == 0
            assert state(m, STATE)['address'] == 0 and state(m, STATE)['polling'] == 0
            assert read(STATE + 155, 1) == b'\0'
            assert all(state(m, p) == value for p, value in known.items())
            assert read(H0 + 14, 1) == b'\x41'
            assert bool(read(H1 + 14, 1)[0]) == (level != 'whole_xtend')
            assert bool(read(H2 + 14, 1)[0]) == (level == 'wheel_only')
            m.call(symbols['zeus_merge_hook'])
            assert read(0x20004608, 64) == baseline, 'held paddle must clear; base report must survive'
            if level == 'whole_xtend':
                bind_hub(H0, root_port)
            if level != 'wheel_only':
                bind_hub(H1, inner_port)
                bind_wheel()
            else:
                m.select('zeus')
                event(m, H2, 2)
            assert [read(p + 14, 1)[0] for p in (H0, H1, H2)] == [0x41, 0x4a, 0x53]
            paddle(14)
            assert all(state(m, p) == value for p, value in known.items())
            assert read(STATE - 16, 16) == b'\xa5' * 16
            assert read(STATE + 228, 28) == b'\xb6' * 28
            rows.append(dict(root_port=root_port, inner_port=inner_port, level=level, cycle=cycle + 1))

output = OUT / 'reconnect-verification.json'
assert not output.exists()
output.write_text(json.dumps(dict(status='PASS', build_id=build['build_id'],
    image_sha256=hashlib.sha256(IMAGE).hexdigest(), cycle_count=len(rows), cases=rows,
    script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
    fixture_sha256=hashlib.sha256(fixture.read_bytes()).hexdigest(),
    limitations=['Native hub events, pool allocation/free, class releases and reinitialization execute',
                 'Synthetic descriptors and successful USB control/OUT transport; no physical timing model',
                 'GPIO is emulated RAM; base/pedal report inputs are seeded, not physical inputs',
                 'Physical reconnection, cold startup, force feedback and PS5 remain unverified']), indent=2) + '\n')
print(json.dumps(dict(status='PASS', reconnect_cycles=len(rows), base_pedals_preserved=True, held_paddle_cleared=True)))
