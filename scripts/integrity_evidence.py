#!/usr/bin/env python3
"""Bounded static integrity evidence from decoded Sigma; no target execution."""
from pathlib import Path
import hashlib
import json
import struct
import capstone

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'work/sigma/1.1.5/sigma-decoded.bin'
EXPECTED = '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'
BASE = 0x08020000


def main():
    b = SOURCE.read_bytes()
    assert hashlib.sha256(b).hexdigest() == EXPECTED
    table = []
    for index in range(256):
        value = index
        for _ in range(8):
            value = value >> 1 ^ (0xedb88320 if value & 1 else 0)
        table.append(value)
    assert b[0x2d928:0x2dd28] == struct.pack('<256I', *table)
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB | capstone.CS_MODE_MCLASS)
    ranges = {
        'application_update_request': (0xae8c, 0xaf38),
        'boot_transition_page_erase': (0xb930, 0xb9f4),
        'system_reset': (0xb9f4, 0xba28),
        'crc32_fixed_ram': (0x2505c, 0x250b8),
        'crc32_caller_12_bytes': (0x247ea, 0x24820),
        'crc32_caller_60_bytes': (0x248fc, 0x24930),
    }
    out = {
        'source': str(SOURCE.relative_to(ROOT)), 'source_sha256': EXPECTED,
        'crc32_table': {'offset': 0x2d928, 'length': 1024,
                        'matches_all_256_entries': True, 'polynomial_reflected': '0xedb88320',
                        'sha256': hashlib.sha256(b[0x2d928:0x2dd28]).hexdigest()},
        'selected_instructions': {},
        'limits': ['Selected ranges establish bounded code facts, not a complete integrity audit.',
                   'Literal table matching does not identify firmware authentication.',
                   'Bootloader code is outside the application payload.'],
    }
    for name, (start, end) in ranges.items():
        out['selected_instructions'][name] = [
            {'offset': ins.address - BASE, 'va': hex(ins.address),
             'bytes': ins.bytes.hex(), 'mnemonic': ins.mnemonic, 'operands': ins.op_str}
            for ins in md.disasm(b[start:end], BASE + start)
        ]
    firmware_root = ROOT / 'work/simagic/3.2.3.13713'
    files = [p for p in firmware_root.rglob('*') if p.is_file()]
    out['simpro_filename_search'] = {
        'root': str(firmware_root.relative_to(ROOT)), 'file_count': len(files),
        'matching_names': [str(p.relative_to(firmware_root)) for p in files
                           if any(term in p.name.lower() for term in ['sigma', 'cortex', 'bootloader'])],
        'boundary': 'Member filenames only; absence does not exclude unidentified embedded bytes.',
    }
    out['sigma_vector_candidate_scan'] = []
    for off in range(0, len(b) - 16, 4):
        sp, reset, handler1, handler2 = struct.unpack_from('<4I', b, off)
        if (0x20000000 <= sp <= 0x20080000 and sp % 8 == 0
                and 0x08000001 <= reset < 0x08100000 and reset & 1
                and all(x == 0 or 0x08000001 <= x < 0x08100000 and x & 1
                        for x in [handler1, handler2])):
            out['sigma_vector_candidate_scan'].append({'offset': off, 'words': [sp, reset, handler1, handler2]})
    folder = ROOT / 'work/sigma/integrity'
    folder.mkdir(parents=True, exist_ok=True)
    (folder / 'integrity-evidence.json').write_text(json.dumps(out, indent=2) + '\n')
    print('Verified CRC32 table; saved bounded instruction, filename and vector evidence.')


if __name__ == '__main__':
    main()
