#!/usr/bin/env python3
"""Save bounded evidence for USB readback review; performs no USB operations."""
import hashlib
import json
import struct
from pathlib import Path
import capstone

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08020000
EXPECTED = '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'


def main():
    source = ROOT / 'work/sigma/1.1.5/sigma-decoded.bin'
    raw = source.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == EXPECTED
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB | capstone.CS_MODE_MCLASS)
    md.detail = True
    pairs = []
    for off in range(0, 0x26700, 2):
        low = next(md.disasm(raw[off:off + 4], BASE + off), None)
        if low is None or low.mnemonic != 'movw':
            continue
        high = next(md.disasm(raw[off + 4:off + 8], BASE + off + 4), None)
        if high is None or high.mnemonic != 'movt' or low.operands[0].reg != high.operands[0].reg:
            continue
        value = low.operands[1].imm | high.operands[1].imm << 16
        if 0x08000000 <= value < BASE:
            pairs.append({'offset': off, 'va': hex(BASE + off),
                          'bytes': raw[off:off + 8].hex(), 'constructed_address': hex(value)})
    out = {
        'source': str(source.relative_to(ROOT)), 'sha256': EXPECTED,
        'bounded_movw_movt_scan': {'file_range': [0, 0x26700], 'step': 2,
                                  'matching_pairs': pairs,
                                  'limits': 'Adjacent same-register MOVW/MOVT constructions only; not all possible pointer computations.'},
        'get_report_03_fixed_source': {'offset': 0x2d8f6, 'va': '0x0804d8f6', 'length': 48,
                                       'bytes': raw[0x2d8f6:0x2d926].hex()},
        'selected_assembly': {}, 'hardware_commands_executed': False,
    }
    for name, start, end in [('feature_dispatch', 0x24724, 0x24a00),
                             ('control_dispatch', 0xaf3c, 0xb138),
                             ('get_report_buffer', 0xb2cc, 0xb36c),
                             ('boot_erase_and_reset', 0xb930, 0xba28)]:
        out['selected_assembly'][name] = [
            {'va': hex(i.address), 'offset': i.address - BASE, 'bytes': i.bytes.hex(),
             'mnemonic': i.mnemonic, 'operands': i.op_str}
            for i in md.disasm(raw[start:end], BASE + start)
        ]
    target = ROOT / 'work/sigma/readback/readback-evidence.json'
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_text(json.dumps(out, indent=2) + '\n')
    print('Saved static readback evidence and', len(pairs), 'bounded below-application address constructions.')


if __name__ == '__main__':
    main()
