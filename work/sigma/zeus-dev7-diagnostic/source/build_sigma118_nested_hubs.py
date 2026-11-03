"""Build a separate Windows diagnostic image; never execute an updater."""
from pathlib import Path
import hashlib
import json
import re
import struct
import subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
from keystone import Ks, KS_ARCH_ARM, KS_MODE_THUMB

ROOT = Path(__file__).resolve().parents[1]
BUILD_ID = 'zeus-dev7-diagnostic'
OUT = ROOT / 'work/sigma' / BUILD_ID
SOURCE = ROOT / 'patch/sigma118/diagnostic_dev7.s'
DEV3 = ROOT / 'work/sigma/zeus-dev3'
M = json.loads((DEV3 / 'build-manifest.json').read_text())
symbols = {key: int(value, 16) for key, value in M['symbols'].items()}
base = (ROOT / M['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(base).hexdigest() == '236fdf7580f553352ada033468654ebf3bff1ec70898184e988149d15f34c77c'
assert not OUT.exists(), 'Preserve existing diagnostic build; use a new build ID for revisions'
image = bytearray(base)
assembler = Ks(KS_ARCH_ARM, KS_MODE_THUMB)
disassembler = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
wrappers = {}
assembly = SOURCE.read_text()
for name, source in re.findall(r'// ROUTINE (\w+)\n(.*?)(?=// ROUTINE|\Z)', assembly, re.S):
    source = source.replace('ORIGINAL_CONSTRUCT', hex(symbols['zeus_construct_hook'] & ~1))
    source = source.replace('ORIGINAL_INIT', hex(symbols['zeus_init'] & ~1))
    source = source.replace('ORIGINAL_MERGE', hex(symbols['zeus_merge_hook'] & ~1))
    source = source.replace('ORIGINAL_INPUT', hex(symbols['zeus_input'] & ~1))
    source = source.replace('ORIGINAL_VTABLE', hex(symbols['zeus_vtable']))
    address = 0x08020000 + len(image)
    code, count = assembler.asm(source, address)
    assert code and len(code) % 4 == 0
    wrappers[name] = dict(address=address, size=len(code), source=source, hex=bytes(code).hex())
    image.extend(code)
assert set(wrappers) == {'construct', 'task', 'init', 'merge', 'input', 'descriptor'}
assert len(image) <= 0x2f000, 'Diagnostic crosses the stock last application page'
image.extend(bytes([255]) * (-len(image) % 32))
assert len(image) <= 0x2f000
edits = []


def edit(offset, replacement, reason):
    before = bytes(image[offset:offset + len(replacement)])
    image[offset:offset + len(replacement)] = replacement
    edits.append(dict(offset=offset, old_hex=before.hex(), new_hex=replacement.hex(), reason=reason))


def branch(offset, target, mnemonic):
    original = next(disassembler.disasm(base[offset:offset + 4], 0x08020000 + offset))
    assert original.mnemonic == mnemonic
    code, _ = assembler.asm(f'{mnemonic} {target}', 0x08020000 + offset)
    assert len(code) == 4
    decoded = next(disassembler.disasm(bytes(code), 0x08020000 + offset))
    assert decoded.mnemonic == mnemonic and int(decoded.op_str.lstrip('#'), 16) == target
    edit(offset, bytes(code), f'{mnemonic} to diagnostic wrapper')


branch(0x473e, wrappers['construct']['address'], 'b.w')
assert next(disassembler.disasm(base[0x23b1c:0x23b20], 0x08043b1c)).op_str == '#0x802affc'
branch(0x23b1c, wrappers['task']['address'], 'bl')
branch(0x23b80, wrappers['merge']['address'], 'bl')
table_offset = symbols['zeus_vtable'] - 0x08020000
assert struct.unpack_from('<I', base, table_offset)[0] == symbols['zeus_init']
edit(table_offset, struct.pack('<I', wrappers['init']['address'] | 1), 'Diagnostic Init return/attempt recording')
assert struct.unpack_from('<I', base, table_offset + 0x40)[0] == symbols['zeus_input']
edit(table_offset + 0x40, struct.pack('<I', wrappers['input']['address'] | 1),
     'Record native input length/ID; allow 23- or 64-byte ID1 control buffers')
assert base[0xaa38:0xaa3c] == bytes.fromhex('80b58cb0'), 'Descriptor trampoline prologue changed'
descriptor_branch, _ = assembler.asm('b.w ' + str(wrappers['descriptor']['address']), 0x0802aa38)
assert len(descriptor_branch) == 4
decoded = next(disassembler.disasm(bytes(descriptor_branch), 0x0802aa38))
assert decoded.mnemonic == 'b.w' and int(decoded.op_str.lstrip('#'), 16) == wrappers['descriptor']['address']
edit(0xaa38, bytes(descriptor_branch), 'Observe original device-descriptor helper return/identity through a prologue trampoline')
allowed = {i for change in edits for i in range(change['offset'], change['offset'] + len(bytes.fromhex(change['new_hex'])))}
assert all(image[i] == base[i] for i in range(len(base)) if i not in allowed)
assert image[0x2ea78:0x2ea80] == base[0x2ea78:0x2ea80]
OUT.mkdir()
plain = OUT / f'NOT_FOR_FLASHING-sigma-1.1.8-{BUILD_ID}.plaintext.bin'
plain.write_bytes(image)
transform = json.loads((ROOT / 'work/sigma/1.1.8/sigma-decoded.bin.transform.json').read_text())
key_source = (ROOT / transform['key_source']).read_bytes()
assert hashlib.sha256(key_source).hexdigest() == transform['key_source_sha256']
for row in transform['key_instruction_evidence'] + transform['iv_instruction_evidence']:
    assert key_source[row['file_offset']:row['file_offset'] + 8].hex() == row['instruction_bytes']
key = bytes(row['value'] for row in transform['key_instruction_evidence']).hex()
iv = bytes(row['value'] for row in transform['iv_instruction_evidence']).hex()
openssl = Path('C:/Program Files/Git/usr/bin/openssl.exe')


def ctr(data):
    return subprocess.run([str(openssl), 'enc', '-aes-256-ctr', '-K', key, '-iv', iv],
                          input=data, capture_output=True, check=True).stdout


assert ctr(base) == (ROOT / M['artifacts']['encoded']['path']).read_bytes()
carrier = ctr(image)
assert ctr(carrier) == image
encoded = OUT / f'NOT_FOR_FLASHING-sigma-1.1.8-{BUILD_ID}.encoded.bin'
encoded.write_bytes(carrier)
artifacts = {name: dict(path=path.relative_to(ROOT).as_posix(), size=path.stat().st_size,
                       sha256=hashlib.sha256(path.read_bytes()).hexdigest())
             for name, path in [('plaintext', plain), ('encoded', encoded)]}
result = dict(status='OFFLINE_WINDOWS_DIAGNOSTIC_NOT_FOR_FLASHING', build_id=BUILD_ID,
              base_version='1.1.8', original=M['original'], parent_build='zeus-dev3',
              parent_sha256=hashlib.sha256(base).hexdigest(), wrappers=wrappers, edits=edits,
              artifacts=artifacts, reserved_state_bytes=204, flash_pages=(len(image) + 2047) // 2048,
              extra_hub=dict(address='0x20005604', size=24, constructor='0x0802bf95', registry_slot=7),
              source_sha256=hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
              builder_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
              symbols=M['symbols'],
              diagnostics=dict(offset=56, length=8, version=7,
                  pages={'even_heartbeat': ['5a marker', '7x version and heartbeat', 'USB address',
                      'poll-enabled', 'last Init return (ff = never attempted)', 'last native input length',
                      'accepted ID1 reports modulo 256', 'ignored reports modulo 256'],
                      'odd_heartbeat': ['5a marker', '7x version and heartbeat',
                      'last successful full device-descriptor VID little-endian (2 bytes)',
                      'last successful full device-descriptor PID little-endian (2 bytes)',
                      'last device-descriptor request return (ff = never called)',
                      'bit0: Zeus in expected registry slot 6; bit1: extra hub in expected registry slot 7']}),
              limitations=['Windows diagnostic only; vendor input bytes 56..63 are overwritten',
                           '23/64-byte handling is a compatibility hypothesis; no hardware fix claimed',
                           'Second hub is validated in a synthetic nested-hub model, not on physical USB hardware',
                           'No wheel-icon update; additional bytes in 64-byte ID1 buffers are ignored',
                           'Device-side firmware acceptance and failed-image recovery remain unproven'])
(OUT / 'build-manifest.json').write_text(json.dumps(result, indent=2) + '\n')
(OUT / 'diagnostic_dev7.s').write_bytes(SOURCE.read_bytes())
print(json.dumps(dict(status=result['status'], artifacts=artifacts, flash_pages=result['flash_pages'])))
