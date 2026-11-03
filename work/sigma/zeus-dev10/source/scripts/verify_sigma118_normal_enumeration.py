"""Verify normal-build USB claiming across device connection orders."""
import argparse
import hashlib
import itertools
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build-id', default='zeus-dev9')
args = parser.parse_args()
OUT = ROOT / 'work/sigma' / args.build_id
build = json.loads((OUT / 'build-manifest.json').read_text())
assert build['normal_reports'] and not build['diagnostic_fields']
IMAGE = (ROOT / build['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(IMAGE).hexdigest() == build['artifacts']['plaintext']['sha256']
assert IMAGE[0xa5b0:0xa5b2] == bytes.fromhex('67e0')

# Load the modeled transport/fixture definitions without running its dev8
# comparison or rewriting its historical verification record.
source = ROOT / 'scripts/diagnose_sigma118_unmatched_claims.py'
namespace = {'__file__': str(source)}
exec(compile(source.read_text().split('rows = [run(skip, vendor)')[0], str(source), 'exec'), namespace)
nested = namespace['nested']
Machine = namespace['Machine']
select = namespace['select_device']
event = namespace['event']
state = namespace['state']
STATE = nested.model.STATE
rows = []


def run(order, vendor, controllers_first=False):
    nested.model.IMAGE = IMAGE
    machine = Machine()
    machine.u.mem_write(STATE - 16, b'\xa5' * 16)
    machine.u.mem_write(STATE + 228, b'\xb6' * 28)
    machine.call(0x08024720)
    machine.select('sigma_hub', (0x1a40, 0x0101))
    assert machine.call(0x0802a400, nested.model.HOST, 0, 0, 0) == 0

    def attach(device):
        if device == 'unknown':
            select(machine, 'unrelated_child', 0x1234, 0x5678, vendor)
            event(machine, STATE + 204, 1)
        elif device == 'zeus':
            machine.select('zeus')
            event(machine, STATE + 204, 2)
        elif device == 'base':
            select(machine, 'base', 0x0483, 0x0522)
            event(machine, nested.ORIGINAL_HUB, 2)
        elif device == 'pedals':
            select(machine, 'pedals', 0x0483, 0x0525)
            event(machine, nested.ORIGINAL_HUB, 3)

    if controllers_first:
        for device in ('base', 'pedals'):
            attach(device)
    for parent in (nested.ORIGINAL_HUB, STATE + 180):
        machine.select('xtend_hub', (0x05e3, 0x0610))
        event(machine, parent, 1)
    for device in order:
        attach(device)
        # No existing class may have acquired the unrelated VID/PID.
        for pointer in (0x200008e8, 0x20003ab0, 0x200025c0, 0x2000267c, 0x20004128, STATE):
            assert state(machine, pointer)['identity'] != '1234:5678'
    base = state(machine, 0x200008e8)
    pedals = state(machine, 0x20003ab0)
    zeus = state(machine, STATE)
    assert base['identity'] == '0483:0522' and base['polling'] == 1
    assert pedals['identity'] == '0483:0525' and pedals['polling'] == 1
    assert zeus['identity'] == '3670:0804' and zeus['polling'] == 1
    assert [bytes(machine.u.mem_read(p + 14, 1))[0] for p in
            (nested.ORIGINAL_HUB, STATE + 180, STATE + 204)] == [0x41, 0x4a, 0x53]
    assert bytes(machine.u.mem_read(STATE - 16, 16)) == b'\xa5' * 16
    assert bytes(machine.u.mem_read(STATE + 228, 28)) == b'\xb6' * 28
    rows.append(dict(order=list(order), unrelated_interface='vendor' if vendor else 'HID',
                     controllers_before_xtend=controllers_first, base=base, pedals=pedals, zeus=zeus))


for vendor in (False, True):
    for order in itertools.permutations(('unknown', 'zeus', 'base', 'pedals')):
        run(order, vendor)
    for order in (('unknown', 'zeus'), ('zeus', 'unknown')):
        run(order, vendor, controllers_first=True)
output = OUT / 'enumeration-verification.json'
assert not output.exists()
output.write_text(json.dumps(dict(status='PASS', image_sha256=hashlib.sha256(IMAGE).hexdigest(),
    cases=rows, case_count=len(rows),
    script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
    transport_model_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
    limitations=['Synthetic device/configuration descriptors and transport, not physical USB',
                 'Native constructor/driver Init/port events execute; USB control/OUT accepted in the model',
                 'GPIO registers are ordinary emulated RAM; base/pedal data parsing and PS5 are separate checks']), indent=2) + '\n')
print(json.dumps(dict(status='PASS', connection_orders=len(rows), known_driver_assignments_preserved=True)))
