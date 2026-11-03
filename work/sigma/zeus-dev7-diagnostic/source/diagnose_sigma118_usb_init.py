"""Run dev3's real Init/config parser, mocking control transfers only.

Uses bundled wheel descriptors, not a capture of Sigma's physical USB bus.
Preserves all existing candidates and their original verification records.
"""
from pathlib import Path
import hashlib
import json
import struct
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB, UC_MODE_MCLASS, UC_HOOK_CODE
from unicorn.arm_const import *

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / 'work/sigma/zeus-dev3'
MANIFEST = json.loads((BUILD / 'build-manifest.json').read_text())
IMAGE = (ROOT / MANIFEST['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(IMAGE).hexdigest() == '236fdf7580f553352ada033468654ebf3bff1ec70898184e988149d15f34c77c'
INITIAL = (ROOT / 'work/sigma/1.1.8/memory/initial-data.bin').read_bytes()
assert hashlib.sha256(INITIAL).hexdigest() == '56df6503e19c10d9687591be7124de7c849f2a33b2c8cdc4225988b3d40c0ce9'
DESCRIPTORS = {1: (ROOT / 'work/simagic/zeus-device.bin').read_bytes(),
               2: (ROOT / 'work/simagic/zeus-configuration.bin').read_bytes(),
               0x22: (ROOT / 'work/simagic/zeus-hid_report.bin').read_bytes()}
STATE = 0x20005550
HOST = 0x20004488
RETURN = 0x0807ff00
PARSER_RETURN = 0x0807fe00


class Machine:
    def __init__(self, idle_status):
        self.u = Uc(UC_ARCH_ARM, UC_MODE_THUMB | UC_MODE_MCLASS)
        self.u.ctl_set_cpu_model(UC_CPU_ARM_CORTEX_M4)
        self.u.mem_map(0x08000000, 0x80000)
        self.u.mem_write(0x08020000, IMAGE)
        self.u.mem_map(0x20000000, 0x10000)
        self.u.mem_write(0x20000000, INITIAL)
        self.u.mem_map(0xe000e000, 0x2000)
        self.idle_status = idle_status
        self.transfers = []
        self.parser_return = None
        self.u.hook_add(UC_HOOK_CODE, self.code)

    def word(self, at):
        return struct.unpack('<I', self.u.mem_read(at, 4))[0]

    def ret(self, value=0):
        self.u.reg_write(UC_ARM_REG_R0, value)
        self.u.reg_write(UC_ARM_REG_PC, self.u.reg_read(UC_ARM_REG_LR))

    def code(self, u, at, size, unused):
        if at == RETURN:
            u.emu_stop()
        elif at == PARSER_RETURN:
            u.reg_write(UC_ARM_REG_R0, 0)
            u.reg_write(UC_ARM_REG_PC, self.parser_return)
            self.parser_return = None
        elif at in (0x0802eecc, 0x08024744):
            self.ret()  # delay and debug logging, no physical controller model
        elif at == 0x0802b2e0:
            sp = u.reg_read(UC_ARM_REG_SP)
            request, low, high, index, total, capacity, buffer, parser = (
                self.word(sp + i * 4) for i in range(8))
            self.transfers.append(dict(request=request, descriptor_type=high,
                                       index=index, total=total, capacity=capacity,
                                       streaming_parser=bool(parser)))
            if request == 6:
                assert high in DESCRIPTORS, self.transfers[-1]
                data = DESCRIPTORS[high][:min(total, capacity)]
                u.mem_write(buffer, data)
                if parser:
                    assert self.parser_return is None
                    self.parser_return = u.reg_read(UC_ARM_REG_LR)
                    # Real stream-parser virtual call used by original control
                    # helper at 0802B48C, preserving the surrounding Init stack.
                    offset = 0x2000f000
                    u.mem_write(offset, bytes(2))
                    for register, value in zip(
                            [UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3],
                            [parser, len(data), buffer, offset]):
                        u.reg_write(register, value)
                    u.reg_write(UC_ARM_REG_LR, PARSER_RETURN | 1)
                    u.reg_write(UC_ARM_REG_PC, self.word(self.word(parser)))
                else:
                    self.ret()
            elif request in (5, 9):
                self.ret()  # SET_ADDRESS / SET_CONFIGURATION accepted
            elif request == 10:
                self.ret(self.idle_status)  # SET_IDLE success or STALL model
            else:
                raise AssertionError(self.transfers[-1])

    def call(self, address, *args):
        self.u.reg_write(UC_ARM_REG_SP, 0x20006620)
        self.u.reg_write(UC_ARM_REG_LR, RETURN | 1)
        self.u.reg_write(UC_ARM_REG_XPSR, 1 << 24)
        for register, value in zip(
                [UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3], list(args) + [0] * 4):
            self.u.reg_write(register, value)
        self.u.emu_start(address | 1, RETURN, count=1000000)
        assert self.u.reg_read(UC_ARM_REG_PC) == RETURN, hex(self.u.reg_read(UC_ARM_REG_PC))
        assert self.u.reg_read(UC_ARM_REG_SP) == 0x20006620
        return self.u.reg_read(UC_ARM_REG_R0)


def main():
    results = []
    for idle_status in (0, 5):
        for entry in ('direct_init', 'host_enumeration'):
            m = Machine(idle_status)
            m.call(0x08024720)
            address = int(MANIFEST['symbols']['zeus_init'], 16) if entry == 'direct_init' else 0x0802a400
            result = m.call(address, STATE if entry == 'direct_init' else HOST, 0, 1, 0)
            state = bytes(m.u.mem_read(STATE, 0x78))
            row = dict(entry=entry, idle_status=idle_status, return_code=result,
                       address=state[0x0c], interface_count=state[0x30], endpoint_count=state[0x31],
                       polling_enabled=state[0x39], transfers=m.transfers,
                       endpoint_and_interface_bytes=state[0x2f:0x6f].hex())
            results.append(row)
            assert result == 0 and state[0x0c] and state[0x39] == 1, row
    output = ROOT / 'reports/windows-usb-init-emulation-001.json'
    assert not output.exists(), 'Preserve prior diagnostic results'
    output.write_text(json.dumps(dict(status='PASS', cases=results,
        image_sha256=hashlib.sha256(IMAGE).hexdigest(),
        descriptor_sha256={str(k): hashlib.sha256(v).hexdigest() for k, v in DESCRIPTORS.items()},
        stubs=['USB control transfer boundary 0802B2E0', 'delay 0802EECC', 'debug logging 08024744'],
        limitations=['Bundled descriptors, not current live full USB descriptors',
                     'Assumes successful descriptor, address and configuration transfers',
                     'No USB controller, bus timing, firmware installation or wheel routing model']), indent=2) + '\n')
    print(json.dumps(dict(status='PASS', cases=len(results), output=str(output.relative_to(ROOT)))))


if __name__ == '__main__':
    main()
