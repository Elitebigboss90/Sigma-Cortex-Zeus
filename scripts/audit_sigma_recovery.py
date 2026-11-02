#!/usr/bin/env python3
"""Offline recovery evidence; never opens USB, launches an updater, or reads hardware."""
import hashlib
import json
import re
import struct
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'work/sigma/recovery-audit-2026-11-02'
SOURCE = ROOT / 'work/sigma/1.1.5/sigma-decoded.bin'
SOURCE_SHA = '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'
CANDIDATE = ROOT / 'work/sigma/zeus-dev2/NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev2.plaintext.bin'
CANDIDATE_SHA = '0152f4f17e23f47f452d2290fe782afb7b70d65b7a854be5e357da36910ab4a8'
BASE = 0x08020000


def identity(path):
    data = path.read_bytes()
    return {'path': str(path.relative_to(ROOT)), 'size': len(data),
            'sha256': hashlib.sha256(data).hexdigest()}


def main():
    source = SOURCE.read_bytes()
    candidate = CANDIDATE.read_bytes()
    assert hashlib.sha256(source).hexdigest() == SOURCE_SHA
    assert hashlib.sha256(candidate).hexdigest() == CANDIDATE_SHA
    decoder = capstone.Cs(capstone.CS_ARCH_ARM,
                          capstone.CS_MODE_THUMB | capstone.CS_MODE_MCLASS)

    def span(start, end):
        raw = source[start - BASE:end - BASE]
        return {'va_start': hex(start), 'va_end_exclusive': hex(end),
                'file_offset': hex(start - BASE), 'bytes': raw.hex(),
                'sha256': hashlib.sha256(raw).hexdigest(),
                'instructions': [
                    {'va': hex(i.address), 'bytes': i.bytes.hex(),
                     'mnemonic': i.mnemonic, 'operands': i.op_str}
                    for i in decoder.disasm(raw, start)]}

    faults = []
    for index, name, address in [(3, 'HardFault', 0x0802553c),
                                 (4, 'MemManage', 0x08025540),
                                 (5, 'BusFault', 0x08025544),
                                 (6, 'UsageFault', 0x08025548)]:
        vector = struct.unpack_from('<I', source, index * 4)[0]
        assert vector == address | 1
        body = span(address, address + 4)
        assert body['bytes'] == 'ffe7fee7'
        assert [int(i['operands'].removeprefix('#'), 16) for i in body['instructions']] == [address + 2] * 2
        assert candidate[index * 4:index * 4 + 4] == source[index * 4:index * 4 + 4]
        assert candidate[address - BASE:address - BASE + 4] == source[address - BASE:address - BASE + 4]
        faults.append({'exception': name, 'vector_file_offset': hex(index * 4),
                       'vector_bytes': source[index * 4:index * 4 + 4].hex(),
                       'thumb_vector': hex(vector), 'handler': body,
                       'interpretation': 'Branch to a branch-to-self loop; no reset or update-entry operation in handler',
                       'unchanged_in_dev2': True})

    export_path = OUT / 'recovery-paths.c'
    export = export_path.read_text()
    refs = {}
    for match in re.finditer(r'// FUNCTION (\S+) @ ([0-9a-f]+)\n((?:// XREF [^\n]+\n)*)', export):
        refs['0x' + match[2]] = {'name': match[1],
                               'ghidra_incoming_references': re.findall(r'// XREF ([^\n]+)', match[3])}
    for address in ['0x0802ae8c', '0x0802ba20', '0x0802b930', '0x0802b9f4']:
        assert address in refs

    hid = OUT / 'hid-registry.json'
    report = {
        'status': 'STATIC_RECOVERY_PATHS_CHECKED_NO_DEVICE_DUMP',
        'source': identity(SOURCE), 'candidate': identity(CANDIDATE),
        'source_kind': 'Application extracted from vendor updater, not a physical-device flash read',
        'mapping': {'file_zero_va': hex(BASE), 'end_exclusive': hex(BASE + len(source)),
                    'unavailable_flash_prefix': ['0x08000000', '0x08020000']},
        'fault_handlers': faults,
        'update_path_spans': [span(0x0802af10, 0x0802af18),
                              span(0x0802ba20, 0x0802ba28),
                              span(0x0802b930, 0x0802b958),
                              span(0x0802b9f4, 0x0802ba20)],
        'selected_ghidra_references': refs,
        'ghidra_export': identity(export_path),
        'ghidra_execution_log': identity(OUT / 'export-native.log'),
        'hid_registry_observation': identity(hid),
        'matching_hid_devices_in_observation': len(json.loads(hid.read_text())['devices']),
        'hardware_firmware_bytes_read': 0,
        'device_commands_sent': 0,
        'limitations': [
            'Known routine references do not exclude computed calls or independent recovery implementations.',
            'Fault-handler loops do not establish watchdog configuration or behavior of the missing bootloader after reset.',
            'No forced recovery sequence or bootloader flash-read command is established.',
            'An empty USB class query returned no plist; it is not a complete USB inventory.',
            'HID absence describes the recorded instant, not device health or permanent connectivity.'
        ]}
    output = OUT / 'recovery-evidence.json'
    output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({'status': report['status'], 'fault_handlers_checked': len(faults),
                      'hardware_firmware_bytes_read': 0, 'output': str(output.relative_to(ROOT))}))


if __name__ == '__main__':
    main()
