#!/usr/bin/env python3
"""Pinned static PE/resource comparison; never execute either updater."""
import hashlib
import json
from pathlib import Path

import pefile
import capstone

ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    '1.1.5': ('originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe',
              '585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a'),
    '1.1.8': ('work/sigma/1.1.8/package/SIGMA v1.1.8 BETA/SIGMA_Converter_V1.1.8.exe',
              '233658402f99fdb47cb35a498706af34acdde77574c56b315a158228d48eec1a'),
}


def sha(b):
    return hashlib.sha256(b).hexdigest()


def resources(pe):
    rows = {}
    for t in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for n in t.directory.entries:
            for language in n.directory.entries:
                key = (str(t.name or t.id), str(n.name or n.id), language.id)
                entry = language.data.struct
                data = pe.get_data(entry.OffsetToData, entry.Size)
                assert len(data) == entry.Size
                rows[key] = {'key': list(key), 'rva': hex(entry.OffsetToData),
                             'offset': pe.get_offset_from_rva(entry.OffsetToData),
                             'length': entry.Size, 'sha256': sha(data),
                             'data_entry_offset': entry.get_file_offset()}
    return rows


def main():
    records, pes, raw, inventories = {}, {}, {}, {}
    for version, (name, digest) in TARGETS.items():
        data = (ROOT / name).read_bytes()
        assert sha(data) == digest, name
        pe = pefile.PE(data=data)
        assert pe.FILE_HEADER.Machine == 0x14c
        assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].Size == 0
        assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[4].Size == 0
        assert pe.get_overlay_data_start_offset() is None
        rows = resources(pe)
        inventories[version], pes[version], raw[version] = rows, pe, data
        records[version] = {'path': name, 'sha256': digest, 'size': len(data),
                            'machine': hex(pe.FILE_HEADER.Machine), 'clr_directory_size': 0,
                            'pe_signature_directory_size': 0, 'overlay': None,
                            'resource_count': len(rows),
                            'firmware': rows[('TEXTFILE', 'IDR_APP_FILE', 1033)],
                            'sections': [
                                {'name': s.Name.rstrip(b'\0').decode(),
                                 'rva': hex(s.VirtualAddress), 'offset': s.PointerToRawData,
                                 'virtual_size': s.Misc_VirtualSize, 'raw_size': s.SizeOfRawData,
                                 'sha256': sha(s.get_data())} for s in pe.sections]}
    left, right = inventories['1.1.5'], inventories['1.1.8']
    assert left.keys() == right.keys() and len(left) == 750
    differences = [{'key': list(k), 'old': left[k], 'new': right[k]}
                   for k in left if left[k]['sha256'] != right[k]['sha256']]
    assert len(differences) == 1 and differences[0]['key'] == ['TEXTFILE', 'IDR_APP_FILE', 1033]
    pe, data = pes['1.1.8'], raw['1.1.8']
    slot = pe.sections[-1].get_file_offset() + 40
    first_raw = min(s.PointerToRawData for s in pe.sections if s.SizeOfRawData)
    assert slot + 40 <= first_raw and data[slot:slot + 40] == bytes(40)
    align = lambda n, a: (n + a - 1) // a * a
    next_rva = align(max(s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData)
                         for s in pe.sections), pe.OPTIONAL_HEADER.SectionAlignment)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    flow = []
    ranges = [
        ('GET F1 and API result check', 0x401e01, 0x401e1e),
        ('SET feature and unchecked API return', 0x401ee9, 0x401f06),
        ('target version 1.1.8', 0x40401d, 0x404031),
        ('update entry report03', 0x40427f, 0x404296),
        ('F1 preparation02', 0x4043a0, 0x4043b1),
        ('firmware resource lookup and pointer/length checks', 0x404435, 0x404497),
        ('at-most32-byte transfer selection', 0x4044a0, 0x4044c5),
        ('finalize F1/04', 0x4045a1, 0x4045b2),
        ('restart F1/01', 0x404612, 0x404623),
        ('completion dialog', 0x404657, 0x40466a),
        ('F2 output construction and transport completion', 0x404bc0, 0x404d60),
        ('USB VID/PID/usage gates', 0x404fd9, 0x405036),
    ]
    for meaning, lo, hi in ranges:
        start = pe.get_offset_from_rva(lo - pe.OPTIONAL_HEADER.ImageBase)
        end = pe.get_offset_from_rva(hi - 1 - pe.OPTIONAL_HEADER.ImageBase) + 1
        body = data[start:end]
        instructions = list(decoder.disasm(body, lo))
        assert sum(i.size for i in instructions) == len(body), meaning
        flow.append({'interpretation': meaning, 'va_start': hex(lo), 'va_end_exclusive': hex(hi),
                     'file_offset': start, 'length': len(body), 'bytes': body.hex(), 'sha256': sha(body),
                     'instructions': [{'va': hex(i.address), 'bytes': i.bytes.hex(),
                                       'mnemonic': i.mnemonic, 'operands': i.op_str} for i in instructions]})
    export = ROOT / 'work/sigma/1.1.8/updater-functions.c'
    assert export.read_text().startswith('Program SIGMA_Converter_V1.1.8.exe language=x86:LE:32:default')
    result = {
        'status': 'PE_RESOURCE_LAYOUT_COMPATIBLE_WITH_APPEND_SECTION_STRATEGY',
        'execution_performed': False,
        'sources': records, 'resource_differences': differences,
        'same_resource_keys': True, 'unchanged_nonfirmware_resource_payloads': 749,
        'new_section_parameters': {'header_offset': slot, 'header_bytes_before': data[slot:slot + 40].hex(),
                                   'rva': hex(next_rva), 'raw_offset': align(len(data), pe.OPTIONAL_HEADER.FileAlignment),
                                   'file_alignment': pe.OPTIONAL_HEADER.FileAlignment,
                                   'section_alignment': pe.OPTIONAL_HEADER.SectionAlignment},
        'native_semantic_review': {'source': str(export.relative_to(ROOT)), 'sha256': sha(export.read_bytes()),
                                  'flow_evidence': flow, 'status_helper': '0x00401d80',
                                  'set_feature_helper': '0x00401e50', 'update_routine': '0x004041b0',
                                  'transfer_helper': '0x00404bc0',
                                  'packet': 'F2 0A n offset_u32le payload; at most32payloadbytes, padded to output-report size',
                                  'external_bin_selector_found_in_update_path': False,
                                  'readback_or_boot_verification_found_in_completion_path': False},
        'limits': ['Native .text is rebuilt, not byte-identical; equivalence is limited to the reviewed update behavior.',
                   'PE/resource consistency does not establish target-side integrity rules or image acceptance.',
                   'This script does not build or execute an updater or perform device I/O.']}
    output = ROOT / 'work/sigma/1.1.8/sigma118-updater-comparison.json'
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': result['status'], 'unchanged_nonfirmware_resources': 749,
                      'firmware_size': right[('TEXTFILE', 'IDR_APP_FILE', 1033)]['length'],
                      'new_section': result['new_section_parameters']}))


if __name__ == '__main__':
    main()
