"""Build dev9 normal reports and protect known drivers from unmatched USB."""
from pathlib import Path
import hashlib
import json
import re
import struct
import subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS
from keystone import Ks, KS_ARCH_ARM, KS_MODE_THUMB

ROOT = Path(__file__).resolve().parents[1]
BUILD_ID = 'zeus-dev9'
OUT = ROOT / 'work/sigma' / BUILD_ID
SOURCE = ROOT / 'patch/sigma118/normal_dev9.s'
PARENT = json.loads((ROOT / 'work/sigma/zeus-dev3/build-manifest.json').read_text())
symbols = {name: int(value, 16) for name, value in PARENT['symbols'].items()}
base = (ROOT / PARENT['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(base).hexdigest() == '236fdf7580f553352ada033468654ebf3bff1ec70898184e988149d15f34c77c'
assert not OUT.exists(), 'Preserve earlier candidates; choose a new build ID'
assembler = Ks(KS_ARCH_ARM, KS_MODE_THUMB)
disassembler = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
image = bytearray(base)
wrappers = {}
for name, text in re.findall(r'// ROUTINE (\w+)\n(.*?)(?=// ROUTINE|\Z)', SOURCE.read_text(), re.S):
    text = text.replace('ORIGINAL_CONSTRUCT', hex(symbols['zeus_construct_hook'] & ~1))
    text = text.replace('ORIGINAL_INPUT', hex(symbols['zeus_input'] & ~1))
    address = 0x08020000 + len(image)
    code, count = assembler.asm(text, address)
    assert code and len(code) % 4 == 0
    wrappers[name] = dict(address=address, size=len(code), source=text, hex=bytes(code).hex())
    image.extend(code)
assert set(wrappers) == {'construct', 'input'}
image.extend(bytes([255]) * (-len(image) % 32))
assert len(image) <= 0x2f000
edits = []


def edit(offset, data, reason):
    before = bytes(image[offset:offset + len(data)])
    image[offset:offset + len(data)] = data
    edits.append(dict(offset=offset, old_hex=before.hex(), new_hex=data.hex(), reason=reason))


old = next(disassembler.disasm(base[0x473e:0x4742], 0x0802473e))
assert old.mnemonic == 'b.w' and int(old.op_str.lstrip('#'), 16) == symbols['zeus_construct_hook'] & ~1
code, _ = assembler.asm('b.w ' + str(wrappers['construct']['address']), 0x0802473e)
assert len(code) == 4
edit(0x473e, bytes(code), 'Preserve original six classes/Zeus then construct two additional hubs')
table = symbols['zeus_vtable'] - 0x08020000
assert struct.unpack_from('<I', base, table + 0x40)[0] == symbols['zeus_input']
edit(table + 0x40, struct.pack('<I', wrappers['input']['address'] | 1), 'Normalize 64-byte buffers to the known 23-byte ID1 prefix')
assert base[0xa5b0:0xa5b2] == bytes.fromhex('0020')
code, _ = assembler.asm('b 0x0802a682', 0x0802a5b0)
assert len(code) == 2 and bytes(code) == bytes.fromhex('67e0')
edit(0xa5b0, bytes(code), 'Unmatched devices use existing DefaultAddressing instead of consuming a known-device driver')
allowed = {i for e in edits for i in range(e['offset'], e['offset'] + len(bytes.fromhex(e['new_hex'])))}
assert all(image[i] == base[i] for i in range(len(base)) if i not in allowed)
for offset, count in [(0x23b1c, 4), (0x23b80, 4), (0xaa38, 4), (0x2ea78, 8)]:
    assert image[offset:offset + count] == base[offset:offset + count]
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


def ctr(data):
    return subprocess.run(['C:/Program Files/Git/usr/bin/openssl.exe', 'enc', '-aes-256-ctr', '-K', key, '-iv', iv],
                          input=data, capture_output=True, check=True).stdout


assert ctr(base) == (ROOT / PARENT['artifacts']['encoded']['path']).read_bytes()
encoded = OUT / f'NOT_FOR_FLASHING-sigma-1.1.8-{BUILD_ID}.encoded.bin'
carrier = ctr(image)
assert ctr(carrier) == image
encoded.write_bytes(carrier)
artifacts = {name: dict(path=path.relative_to(ROOT).as_posix(), size=path.stat().st_size,
                       sha256=hashlib.sha256(path.read_bytes()).hexdigest())
             for name, path in [('plaintext', plain), ('encoded', encoded)]}
manifest = dict(status='OFFLINE_NORMAL_REPORT_CANDIDATE', build_id=BUILD_ID, base_version='1.1.8',
                original=PARENT['original'], parent_build='zeus-dev3', parent_sha256=hashlib.sha256(base).hexdigest(),
                artifacts=artifacts, symbols=PARENT['symbols'], profile=PARENT['profile'],
                source_files=PARENT['source_files'], wrappers=wrappers, edits=edits,
                source_sha256=hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
                builder_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                reserved_state_bytes=228, flash_pages=(len(image) + 2047) // 2048,
                extra_hubs=[dict(address='0x20005604', size=24, registry_slot=7),
                            dict(address='0x2000561c', size=24, registry_slot=8)],
                normal_reports=True, diagnostic_fields=False, periodic_heartbeat=False,
                limitations=['Normal report layout restored; physical PS5 behavior is not verified',
                             'Unmatched devices receive an address without acquiring an input driver',
                             'Nested disconnect/error recovery remains unverified'])
(OUT / 'build-manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
(OUT / SOURCE.name).write_bytes(SOURCE.read_bytes())
print(json.dumps(dict(status=manifest['status'], artifacts=artifacts, flash_pages=manifest['flash_pages'])))
