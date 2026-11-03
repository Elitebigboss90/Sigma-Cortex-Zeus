"""Model unrelated USB children before the real base/pedals, using dev8.

The comparison changes only the initial instruction of the blind fallback
pass to branch to existing DefaultAddressing. No hardware access or flash.
"""
import hashlib
import json
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import diagnose_sigma118_nested_hubs as nested
from keystone import Ks, KS_ARCH_ARM, KS_MODE_THUMB
from unicorn import UcError
from unicorn.arm_const import UC_ARM_REG_PC

ROOT = nested.ROOT
folder = ROOT / 'work/sigma/zeus-dev8-diagnostic'
manifest = json.loads((folder / 'build-manifest.json').read_text())
original = (ROOT / manifest['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(original).hexdigest() == '0974908edf447b210076429401240852b86f2697b7efe63d7ba977c0f4eca5fe'
assert original[0xa5b0:0xa5b2] == bytes.fromhex('0020')
replacement, _ = Ks(KS_ARCH_ARM, KS_MODE_THUMB).asm('b 0x0802a682', 0x0802a5b0)
assert len(replacement) == 2
STATE = nested.model.STATE
DRIVERS = dict(base=0x200008e8, pedals=0x20003ab0, additional=0x20004128)


class Machine(nested.Machine):
    def __init__(self):
        super().__init__()
        # Native successful base/pedal initialization toggles GPIO indicators.
        # Model register storage only, without electrical/peripheral behavior.
        self.u.mem_map(0x40000000, 0x30000)

    def code(self, u, at, size, unused):
        if at == 0x0802aa88:
            # Public USB OUT transaction boundary, used by original Init.
            self.ret()
        else:
            super().code(u, at, size, unused)


def select_device(machine, name, vid, pid, vendor=False):
    machine.select(name)
    descriptor = bytearray(nested.ZEUS_DESCRIPTORS[1])
    struct.pack_into('<HH', descriptor, 8, vid, pid)
    configuration = bytearray(nested.HUB_CONFIGURATION) if vendor else bytearray(nested.ZEUS_DESCRIPTORS[2])
    if vendor:
        configuration[14] = 0xff
    nested.model.DESCRIPTORS[1] = bytes(descriptor)
    nested.model.DESCRIPTORS[2] = bytes(configuration)


def event(machine, parent, port):
    machine.u.mem_write(0x20007000, bytes.fromhex('03011000'))
    try:
        assert machine.call(0x0802baf0, parent, port, 0x20007000) == 0
    except UcError:
        print('Model fault', machine.phase, hex(machine.u.reg_read(UC_ARM_REG_PC)), flush=True)
        raise


def state(machine, address):
    raw = bytes(machine.u.mem_read(address, 0x78))
    return dict(address=raw[12], polling=raw[57],
                identity='%04x:%04x' % (struct.unpack_from('<H', raw, 114)[0], struct.unpack_from('<H', raw, 112)[0]))


def run(skip, vendor):
    image = bytearray(original)
    if skip:
        image[0xa5b0:0xa5b2] = bytes(replacement)
    nested.model.IMAGE = bytes(image)
    machine = Machine()
    machine.call(0x08024720)
    machine.select('sigma_hub', (0x1a40, 0x0101))
    assert machine.call(0x0802a400, nested.model.HOST, 0, 0, 0) == 0
    for parent in (nested.ORIGINAL_HUB, STATE + 180):
        machine.select('xtend_hub', (0x05e3, 0x0610))
        event(machine, parent, 1)
    select_device(machine, 'synthetic_unmatched_child', 0x1234, 0x5678, vendor)
    event(machine, STATE + 204, 1)
    before = {name: state(machine, obj) for name, obj in DRIVERS.items()}
    machine.select('zeus')
    event(machine, STATE + 204, 2)
    select_device(machine, 'actual_base_identity', 0x0483, 0x0522)
    event(machine, nested.ORIGINAL_HUB, 2)
    select_device(machine, 'actual_pedal_identity', 0x0483, 0x0525)
    event(machine, nested.ORIGINAL_HUB, 3)
    after = {name: state(machine, obj) for name, obj in DRIVERS.items()}
    if skip:
        assert before['base']['address'] == 0 and before['pedals']['address'] == 0
        assert after['base']['identity'] == '0483:0522' and after['base']['polling'] == 1
        assert after['pedals']['identity'] == '0483:0525' and after['pedals']['polling'] == 1
    else:
        assert before['base']['identity'] == '1234:5678' and before['base']['address'] != 0
        assert after['base']['identity'] != '0483:0522'
    assert bytes(machine.u.mem_read(STATE + 12, 1))[0] == 0x1a
    return dict(skip_blind_fallback=skip, unrelated_interface='vendor' if vendor else 'HID',
                after_unrelated_child=before, final_drivers=after, zeus=state(machine, STATE),
                native_init_entries=machine.entries)


rows = [run(skip, vendor) for vendor in (False, True) for skip in (False, True)]
output = ROOT / 'reports/sigma118-unmatched-child-claim-model-001.json'
assert not output.exists()
output.write_text(json.dumps(dict(status='PASS', cases=rows,
    base_image_sha256=hashlib.sha256(original).hexdigest(),
    model_edit=dict(offset='0xa5b0', old_hex='0020', new_hex=bytes(replacement).hex(), target='0x0802a682'),
    script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
    limitations=['Unrelated identity and interface are synthetic, not an identification of the actual Xtend child',
                 'Real constructors, native reset-complete events, Init and dispatch; controller transfers are modeled',
                 'GPIO peripheral addresses are ordinary emulated RAM, not a hardware model',
                 'Public USB OUT 0802AA88 is mocked as accepted for vendor Init commands',
                 'Does not test base/pedal report decoding or physical USB timing']), indent=2) + '\n')
print(json.dumps(dict(status='PASS', cases=[{key: row[key] for key in ('skip_blind_fallback', 'unrelated_interface', 'final_drivers')} for row in rows])))
