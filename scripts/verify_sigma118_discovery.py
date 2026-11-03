"""Finite ARM tests for the Windows diagnostic; does not access hardware."""
from pathlib import Path
import hashlib
import json
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import diagnose_sigma118_usb_init as model
from unicorn.arm_const import *

ROOT = model.ROOT
OUT = ROOT / 'work/sigma/zeus-dev6-diagnostic'
MANIFEST = json.loads((OUT / 'build-manifest.json').read_text())
IMAGE = (ROOT / MANIFEST['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(IMAGE).hexdigest() == MANIFEST['artifacts']['plaintext']['sha256']
PARENT = model.IMAGE
WRAPPERS = {k: v['address'] for k, v in MANIFEST['wrappers'].items()}
SYMBOLS = {k: int(v, 16) for k, v in MANIFEST['symbols'].items()}
STATE = model.STATE
OUTPUT = 0x20004608
checks = []


class DiagnosticMachine(model.Machine):
    def __init__(self, idle_status=0, fail_configuration=False, fail_device=False):
        model.IMAGE = IMAGE
        super().__init__(idle_status)
        self.fail_configuration = fail_configuration
        self.fail_device = fail_device
        self.host_task_calls = 0

    def code(self, u, at, size, unused):
        if at == 0x0802affc:
            self.host_task_calls += 1
            self.ret()
        elif at == 0x0802b2e0 and (self.fail_configuration or self.fail_device):
            sp = u.reg_read(UC_ARM_REG_SP)
            if self.word(sp) == 6 and ((self.fail_configuration and self.word(sp + 8) == 2) or
                                      (self.fail_device and self.word(sp + 8) == 1)):
                self.ret(4)
            else:
                super().code(u, at, size, unused)
        else:
            super().code(u, at, size, unused)


def setup(m):
    m.u.mem_write(STATE - 16, b'\xa5' * 16)
    m.u.mem_write(STATE + 180, b'\xb6' * 76)
    m.u.mem_write(STATE + 156, b'\xdd' * 24)
    m.call(0x08024720)
    assert bytes(m.u.mem_read(STATE + 156, 24)) == b'\xff' + bytes(15) + b'\xff' + bytes(7)


def canaries(m):
    assert bytes(m.u.mem_read(STATE - 16, 16)) == b'\xa5' * 16
    assert bytes(m.u.mem_read(STATE + 180, 76)) == b'\xb6' * 76


def init(m, host=True):
    return m.call(0x0802a400 if host else WRAPPERS['init'], model.HOST if host else STATE, 0, 1, 0)


def report(m, data):
    m.u.mem_write(0x20007000, data)
    m.u.mem_write(0x20006620, struct.pack('<I', 0x20007000))
    m.call(m.word(m.word(STATE) + 0x40), STATE, STATE, 1, len(data))


for idle in (0, 5):
    for host in (False, True):
        m = DiagnosticMachine(idle)
        setup(m)
        assert init(m, host) == 0
        assert bytes(m.u.mem_read(STATE + 156, 2)) == b'\x00\x01'
        assert m.word(STATE + 8) == model.HOST
        assert m.word(model.HOST + 0x78 + 6 * 4) == STATE
        assert bytes(m.u.mem_read(STATE + 168, 5)) == bytes.fromhex('7036040800')
        canaries(m)
checks.append('Four real Init/host enumeration cases record successful status, with SET_IDLE success and STALL models')

m = DiagnosticMachine(fail_configuration=True)
setup(m)
assert init(m, False) == 4
assert bytes(m.u.mem_read(STATE + 156, 2)) == b'\x04\x01'
assert bytes(m.u.mem_read(STATE + 12, 1)) == b'\x00'
canaries(m)
checks.append('Configuration-transfer failure records return code 4 and leaves no allocated wheel address')

for failed, length in [(False, 8), (False, 18), (True, 18)]:
    probe = DiagnosticMachine(fail_device=failed)
    setup(probe)
    preserved = [UC_ARM_REG_R4, UC_ARM_REG_R5, UC_ARM_REG_R6, UC_ARM_REG_R7,
                 UC_ARM_REG_R8, UC_ARM_REG_R9, UC_ARM_REG_R10, UC_ARM_REG_R11]
    for index, register in enumerate(preserved):
        probe.u.reg_write(register, 0x12340000 + index)
    result = probe.call(0x0802aa38, model.HOST, 0, length, 0x20007000)
    assert result == (4 if failed else 0)
    assert bytes(probe.u.mem_read(STATE + 172, 1)) == bytes([result])
    expected_identity = bytes.fromhex('70360408') if not failed and length >= 12 else bytes(4)
    assert bytes(probe.u.mem_read(STATE + 168, 4)) == expected_identity
    for index, register in enumerate(preserved):
        assert probe.u.reg_read(register) == 0x12340000 + index
    canaries(probe)
checks.append('Real descriptor-helper trampoline preserves ABI, logs success/failure, and never reads identity from an 8-byte response')

m = DiagnosticMachine()
setup(m)
for tick, dirty in [(99, 0), (100, 1), (199, 0), (200, 1), (0xfffffff0, 1), (0x53, 0), (0x54, 1)]:
    m.u.mem_write(0x20002104, struct.pack('<I', tick))
    m.u.mem_write(0x20000040, b'\x00')
    m.call(WRAPPERS['task'])
    assert bytes(m.u.mem_read(0x20000040, 1)) == bytes([dirty]), (tick, dirty)
assert m.host_task_calls == 7
canaries(m)
checks.append('Periodic wrapper calls original host task and marks reports dirty at 100 ticks, including wraparound')

assert init(m) == 0
m.u.mem_write(0x20004548, b'\x08')
m.u.mem_write(0x20004549, b'\x00')
model.IMAGE = PARENT
reference = model.Machine(0)
reference.call(0x08024720)
assert reference.call(0x0802a400, model.HOST, 0, 1, 0) == 0
reference.u.mem_write(0x20004548, b'\x08')
reference.u.mem_write(0x20004549, b'\x00')
model.IMAGE = IMAGE
capture_path = ROOT / 'reports/windows-zeus-input-002.json'
capture_raw = capture_path.read_bytes()
capture = json.loads(capture_raw)
frames = set()
for row in capture['frames']:
    raw = bytes.fromhex(row['Hex'])
    if raw[0] == 1:
        assert len(raw) == 64, 'Unexpected Windows HID buffer capacity'
        frames.add(raw[:23])
assert len(frames) > 2
prefix_matches = 0
for frame in sorted(frames):
    report(reference, frame)
    reference.call(SYMBOLS['zeus_merge_hook'])
    # Test both native lengths with nonzero data outside the control prefix.
    # The padding pattern is synthetic; only the first 23 bytes are mapped.
    report(m, frame)
    report(m, frame + bytes([0xa7]) * 41)
    m.call(WRAPPERS['merge'])
    expected = bytes(reference.u.mem_read(OUTPUT, 64))
    actual = bytes(m.u.mem_read(OUTPUT, 64))
    assert actual[:56] == expected[:56]
    assert actual[56] == 0x5a and actual[57] & 0xf0 == 0x60 and actual[57] & 1 == 0
    assert actual[58] == bytes(m.u.mem_read(STATE + 12, 1))[0]
    assert actual[59] == 1 and actual[60:62] == b'\x00\x40'
    assert actual[62] == m.word(STATE + 124) & 255
    assert actual[63] == m.word(STATE + 128) & 255
    prefix_matches += 1
canaries(m)
checks.append(f'{prefix_matches} distinct Windows control prefixes accepted as 23 and 64 bytes preserve dev3 output 0..55 and expose native length/counters')

before = m.word(STATE + 128)
report(m, bytes(64))
m.call(WRAPPERS['merge'])
assert m.word(STATE + 128) == before + 1
assert bytes(m.u.mem_read(OUTPUT + 61, 1)) == b'\x40'
assert bytes(m.u.mem_read(OUTPUT + 63, 1))[0] == (before + 1) & 255
m.u.mem_write(STATE + 124, struct.pack('<I', 255))
report(m, b'\x01' + bytes(22))
m.call(WRAPPERS['merge'])
assert m.word(STATE + 124) == 256 and bytes(m.u.mem_read(OUTPUT + 62, 1)) == b'\x00'
canaries(m)
checks.append('Rejected report ID and modulo-256 counters are reported without state-boundary damage')

accepted = m.word(STATE + 124)
for length in (22, 24, 63, 65):
    report(m, b'\x01' + bytes(length - 1))
    assert m.word(STATE + 124) == accepted
for report_id in (2, 0xf9):
    report(m, bytes([report_id]) + bytes(63))
    assert m.word(STATE + 124) == accepted
m.u.mem_write(0x20006620, bytes(4))
m.call(WRAPPERS['input'], STATE, STATE, 1, 64)
assert m.word(STATE + 124) == accepted
canaries(m)
checks.append('Other lengths, management report IDs and a null buffer remain rejected')

m.u.mem_write(STATE + 164, b'\x01')
slot = model.HOST + 0x78 + 6 * 4
vtable = m.word(STATE)
for present, valid, flags in [(True, True, 3), (False, True, 2), (True, False, 1), (False, False, 0)]:
    m.u.mem_write(slot, struct.pack('<I', STATE if present else 0))
    m.u.mem_write(STATE, struct.pack('<I', vtable if valid else 0))
    m.call(WRAPPERS['merge'])
    page = bytes(m.u.mem_read(OUTPUT + 56, 8))
    assert page[:2] == b'\x5a\x61'
    assert page[2:7] == bytes.fromhex('7036040800')
    assert page[7] == flags
m.u.mem_write(slot, struct.pack('<I', STATE))
m.u.mem_write(STATE, struct.pack('<I', vtable))
canaries(m)
checks.append('Discovery page reports descriptor identity/status and distinguishes all four registry/vtable states')

# Exercise the actual edited BL instructions, stopping at their return site.
for callsite, continuation in [(0x08043b1c, 0x08043b20), (0x08043b80, 0x08043b84)]:
    u = m.u
    u.reg_write(UC_ARM_REG_SP, 0x20006620)
    u.reg_write(UC_ARM_REG_LR, model.RETURN | 1)
    u.reg_write(UC_ARM_REG_XPSR, 1 << 24)
    u.emu_start(callsite | 1, continuation, count=200000)
    assert u.reg_read(UC_ARM_REG_PC) == continuation
    assert u.reg_read(UC_ARM_REG_SP) == 0x20006620
canaries(m)
checks.append('Edited main-loop and merge callsites execute and return with balanced stacks')

output = OUT / 'diagnostic-verification.json'
assert not output.exists(), 'Preserve prior result'
result = dict(status='PASS', checks=checks, distinct_windows_payloads=prefix_matches,
              image_sha256=hashlib.sha256(IMAGE).hexdigest(),
              capture_sha256=hashlib.sha256(capture_raw).hexdigest(),
              verification_script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
              initialization_model_sha256=hashlib.sha256(Path(model.__file__).read_bytes()).hexdigest(),
              stubs=['USB control transfer boundary', 'delay', 'debug logging', 'original host task for periodic-wrapper tests'],
              limitations=['No firmware installation or USB hardware model',
                           'Windows ID1 padding removed only for CPU replay; actual bus length remains unmeasured',
                           'Only bytes 0..55 preserve ordinary dev3 output; diagnostic vendor bytes differ'])
output.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(status='PASS', checks=len(checks), distinct_windows_payloads=prefix_matches)))
