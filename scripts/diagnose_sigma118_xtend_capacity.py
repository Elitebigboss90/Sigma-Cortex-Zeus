"""Compare actual dev7/dev8 images against the measured three-hub path.

Runs original hub reset-complete events with synthetic descriptors and the
same modeled SET_ADDRESS behavior as the earlier nested-hub investigation.
"""
import hashlib
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import diagnose_sigma118_nested_hubs as nested

ROOT = nested.ROOT
STATE = nested.model.STATE
rows = []
for build in ('zeus-dev7-diagnostic', 'zeus-dev8-diagnostic'):
    folder = ROOT / 'work/sigma' / build
    manifest = json.loads((folder / 'build-manifest.json').read_text())
    image = (ROOT / manifest['artifacts']['plaintext']['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == manifest['artifacts']['plaintext']['sha256']
    nested.model.IMAGE = image
    machine = nested.Machine()
    machine.call(0x08024720)
    machine.select('sigma_hub', (0x1a40, 0x0101))
    assert machine.call(0x0802a400, nested.model.HOST, 0, 0, 0) == 0
    hubs = [nested.ORIGINAL_HUB, STATE + 180, STATE + 204]
    all_bound = True
    for index in range(2):
        machine.select('xtend_hub_' + str(index + 1), (0x05e3, 0x0610))
        machine.u.mem_write(0x20007000, bytes.fromhex('03011000'))
        assert machine.call(0x0802baf0, hubs[index], 1, 0x20007000) == 0
        if not bytes(machine.u.mem_read(hubs[index + 1] + 14, 1))[0]:
            all_bound = False
            break
    if all_bound:
        machine.select('zeus')
        machine.u.mem_write(0x20007000, bytes.fromhex('03011000'))
        assert machine.call(0x0802baf0, hubs[-1], 1, 0x20007000) == 0
    machine.u.mem_write(STATE + 164, b'\x01')
    machine.call(manifest['wrappers']['merge']['address'])
    row = dict(build=build, image_sha256=hashlib.sha256(image).hexdigest(),
               hub_addresses=[bytes(machine.u.mem_read(h + 14, 1))[0] for h in hubs],
               zeus_address=bytes(machine.u.mem_read(STATE + 12, 1))[0],
               zeus_polling=bytes(machine.u.mem_read(STATE + 57, 1))[0],
               last_descriptor_return=bytes(machine.u.mem_read(STATE + 172, 1))[0],
               discovery_page=bytes(machine.u.mem_read(0x20004608 + 56, 8)).hex(),
               native_init_entries=machine.entries)
    rows.append(row)
assert rows[0]['hub_addresses'] == [0x41, 0x4a, 0]
assert rows[0]['zeus_address'] == 0 and rows[0]['last_descriptor_return'] == 13
assert rows[1]['hub_addresses'] == [0x41, 0x4a, 0x53]
assert rows[1]['zeus_address'] == 0x19 and rows[1]['zeus_polling'] == 1
assert rows[1]['last_descriptor_return'] == 0
capture_path = ROOT / 'reports/windows-sigma-dev7-installed-001.json'
capture_raw = capture_path.read_bytes()
capture = json.loads(capture_raw)
observed = next(bytes.fromhex(r['Hex']) for r in capture['frames']
                if int(r['Hex'][114:116], 16) & 1)
assert bytes.fromhex(rows[0]['discovery_page'])[2:] == observed[58:64]
output = ROOT / 'reports/sigma118-xtend-three-hub-capacity-001.json'
assert not output.exists()
output.write_text(json.dumps(dict(status='PASS', cases=rows,
    dev7_capture_sha256=hashlib.sha256(capture_raw).hexdigest(),
    script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
    model_sha256=hashlib.sha256(Path(nested.__file__).read_bytes()).hexdigest(),
    limitations=['Synthetic descriptors and modeled transport; not physical USB',
                 'Native reset-complete processing runs; physical hub interrupt polling/reset timing and error recovery are unverified']), indent=2) + '\n')
print(json.dumps(dict(status='PASS', cases=[{k: row[k] for k in ('build', 'hub_addresses', 'zeus_address', 'last_descriptor_return')} for row in rows])))
