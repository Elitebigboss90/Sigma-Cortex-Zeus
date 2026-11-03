"""Model observed nested hubs with real Sigma constructors/Init/dispatch.

USB descriptors and transfer results are synthetic. No hardware access.
"""
import hashlib
import json
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import diagnose_sigma118_usb_init as model
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_SP

ROOT = model.ROOT
BUILD = ROOT / 'work/sigma/zeus-dev6-diagnostic'
MANIFEST = json.loads((BUILD / 'build-manifest.json').read_text())
model.IMAGE = (ROOT / MANIFEST['artifacts']['plaintext']['path']).read_bytes()
ZEUS_DESCRIPTORS = dict(model.DESCRIPTORS)
HUB_CONFIGURATION = bytes.fromhex('09021900010100e0320904000001090000000705810301000c')
HUB_DESCRIPTOR = bytes.fromhex('0929040900320000ff')
EXTRA_HUB = model.STATE + 180
ORIGINAL_HUB = 0x20002734


def hub_device(vid, pid):
    # Synthetic USB2 hub descriptor; only VID/PID come from hardware reports.
    return bytes.fromhex('1201000209000140') + struct.pack('<HH', vid, pid) + bytes.fromhex('000100000001')


class Machine(model.Machine):
    def __init__(self):
        super().__init__(0)
        self.phase = None
        self.entries = []
        self.current_address = 0

    def select(self, phase, identity=None):
        self.phase = phase
        self.current_address = 0
        if identity:
            model.DESCRIPTORS.update({1: hub_device(*identity), 2: HUB_CONFIGURATION, 0x29: HUB_DESCRIPTOR})
        else:
            model.DESCRIPTORS.update(ZEUS_DESCRIPTORS)

    def code(self, u, at, size, unused):
        if at in (0x0802bc64, int(MANIFEST['symbols']['zeus_init'], 16) & ~1, 0x080289ac):
            self.entries.append(dict(phase=self.phase, routine=hex(at), object=hex(u.reg_read(UC_ARM_REG_R0))))
        if at == 0x0802b2e0:
            sp = u.reg_read(UC_ARM_REG_SP)
            request = self.word(sp)
            if request == 6 and self.word(sp + 8) == 1:
                address = u.reg_read(UC_ARM_REG_R1)
                if address == 0 and self.current_address != 0:
                    # A device moved by SET_ADDRESS does not answer at zero.
                    self.ret(13)
                    return
            if request == 5:
                self.current_address = self.word(sp + 4)
            if request in (0, 1, 3):
                if request == 0:
                    count = min(self.word(sp + 16), self.word(sp + 20))
                    pointer = self.word(sp + 24)
                    if count and pointer:
                        u.mem_write(pointer, bytes(count))
                self.ret()
                return
        super().code(u, at, size, unused)


def run(extra):
    m = Machine()
    m.call(0x08024720)
    if extra:
        m.u.mem_write(EXTRA_HUB, bytes(24))
        assert m.call(0x0802bf94, EXTRA_HUB, model.HOST) == EXTRA_HUB
    m.select('sigma_hub', (0x1a40, 0x0101))
    root_result = m.call(0x0802a400, model.HOST, 0, 0, 0)
    original_address = bytes(m.u.mem_read(ORIGINAL_HUB + 14, 1))[0]
    print('root', extra, root_result, hex(original_address), flush=True)
    assert root_result == 0 and original_address
    m.select('xtend_hub', (0x05e3, 0x0610))
    # Execute the real reset-complete event path. It masks hub addresses to
    # their three-bit parent ID before calling host enumeration (0802BC3E).
    event_pointer = 0x20007000
    m.u.mem_write(event_pointer, bytes.fromhex('03011000'))
    xtend_result = m.call(0x0802baf0, ORIGINAL_HUB, 1, event_pointer)
    extra_address = bytes(m.u.mem_read(EXTRA_HUB + 14, 1))[0] if extra else 0
    print('xtend', extra, xtend_result, hex(extra_address), flush=True)
    row = dict(extra_hub=extra, root_result=root_result, root_address=original_address,
               xtend_event_return=xtend_result, xtend_hub_address=extra_address, entries=m.entries,
               last_descriptor_return=bytes(m.u.mem_read(model.STATE + 172, 1))[0])
    if extra_address:
        m.select('zeus')
        m.u.mem_write(event_pointer, bytes.fromhex('03011000'))
        zeus_result = m.call(0x0802baf0, EXTRA_HUB, 1, event_pointer)
        row.update(zeus_event_return=zeus_result,
                   zeus_address=bytes(m.u.mem_read(model.STATE + 12, 1))[0],
                   zeus_polling=bytes(m.u.mem_read(model.STATE + 57, 1))[0])
    return row


def main():
    rows = [run(False), run(True)]
    print(json.dumps(rows, indent=2))
    assert rows[0]['xtend_hub_address'] == 0
    assert rows[0]['last_descriptor_return'] == 13
    assert rows[1]['xtend_event_return'] == 0 and rows[1]['xtend_hub_address']
    assert rows[1]['zeus_event_return'] == 0 and rows[1]['zeus_address'] and rows[1]['zeus_polling'] == 1
    output = ROOT / 'reports/sigma118-nested-hub-model-002.json'
    assert not output.exists()
    output.write_text(json.dumps(dict(status='PASS', cases=rows,
        image_sha256=hashlib.sha256(model.IMAGE).hexdigest(),
        script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        limitations=['Synthetic hub descriptors with observed VID/PID; not a physical bus capture',
                     'GET_DEVICE_DESCRIPTOR at address zero returns JERR after SET_ADDRESS, a modeled transport behavior',
                     'Real reset-complete event processing runs; hub interrupt polling and physical reset timing are not modeled',
                     'Supersedes 001, whose manual child calls used an unmasked parent unlike native 0802BC3E']), indent=2) + '\n')


if __name__ == '__main__':
    main()
