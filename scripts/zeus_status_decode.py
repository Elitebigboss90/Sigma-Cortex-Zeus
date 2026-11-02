#!/usr/bin/env python3
"""Decode recorded Zeus status 0x0401 frames using the pinned firmware schema.

Reads completed capture files only; no device access or requests. The static
schema belongs to the bundled A1.1.15 image, not a dump of the connected wheel.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct

from zeus_mapping_defaults import BASE, SHA, SOURCE, fields

ROOT = Path(__file__).resolve().parents[1]


def sha(data):
    return hashlib.sha256(data).hexdigest()


def schema():
    data = SOURCE.read_bytes()
    if sha(data) != SHA:
        raise ValueError('Static firmware hash mismatch')
    descriptor_va = struct.unpack_from('<I', data, 0x08030D48 - BASE)[0]
    table_va = struct.unpack_from('<I', data, descriptor_va - BASE)[0]
    count = struct.unpack_from('<H', data, descriptor_va + 16 - BASE)[0]
    at = table_va - BASE
    result = []
    # Field iterator 08030EE4; advance 08030FCE uses 1 << (word & 3).
    for _ in range(count):
        word = struct.unpack_from('<I', data, at)[0]
        kind = word & 3
        words = 1 << kind
        field = (word >> 2) & 63
        if kind == 0:
            offset = (word >> 16) & 255
            size = word >> 28
        elif kind == 1:
            second = struct.unpack_from('<I', data, at + 4)[0]
            field |= (second >> 28) << 6
            offset = second & 65535
            size = (second >> 16) & 4095
        else:
            raise ValueError('Unsupported descriptor width in pinned schema')
        result.append({'field': field, 'descriptor_va': f'0x{at+BASE:08X}',
                       'descriptor_file_offset': at, 'bytes': data[at:at+words*4].hex(),
                       'type_byte': (word >> 8) & 255,
                       'input_struct_offset': offset, 'size': size})
        at += 4 * words
    mode = [row for row in result if row['input_struct_offset'] == 0x1C]
    if len(mode) != 1 or mode[0]['field'] != 4 or mode[0]['size'] != 4:
        raise ValueError('Expected communication-mode field not established')
    return {'source': str(SOURCE.relative_to(ROOT)), 'source_sha256': SHA,
            'descriptor_va': f'0x{descriptor_va:08X}',
            'field_table_va': f'0x{table_va:08X}', 'field_count': count,
            'fields': result, 'mode_field': 4,
            'provenance': {'producer_va': '0x080273FC', 'encoder_va': '0x08030C7C',
                           'framer_va': '0x08028D98', 'field_iterator_va': '0x08030EE4',
                           'state_copy_va': '0x080270FC',
                           'mode_pack_instructions_va': ['0x08030CE6', '0x08030CEA'],
                           'device_ram': '0x2000B298', 'mode_mirror_offset': 124},
            'limit': 'Applying this static schema to live older firmware is a cross-version interpretation.'}


def decode(raw, mode_field=4):
    if len(raw) != 64 or raw[:3] != bytes.fromhex('021e88') or raw[4:6] != bytes.fromhex('0104'):
        return {'recognized': False, 'reason': 'Not a 64-byte status 0x0401 frame'}
    length = int.from_bytes(raw[6:8], 'big')
    if raw[8:10] != b'\x01\x01' or length > 54:
        return {'recognized': False, 'reason': 'Only complete single-frame payloads are supported'}
    end = 10 + length
    parsed = fields(raw[10:end], 10)
    values = [item for item in parsed if item['field'] == mode_field and item['wire'] == 0]
    if len(values) != 1:
        return {'recognized': False, 'reason': 'Missing or ambiguous mode field'}
    mode = values[0]
    names = {1: 'USB', 4: 'CAN FD', 9: 'USB and CAN FD'}
    return {'recognized': True, 'report_id': raw[0], 'header_hex': raw[:10].hex(),
            'destination_byte': raw[3], 'message_code_le': '0x0401',
            'payload_length': length, 'payload_offset': 10,
            'payload_sha256': sha(raw[10:end]),
            'frame_count': raw[8], 'frame_number': raw[9],
            'padding_length': len(raw)-end, 'padding_all_zero': not any(raw[end:]),
            'fields': parsed, 'communication_mode': mode['value'],
            'communication_mode_name_under_static_schema': names.get(mode['value'], 'Unassigned'),
            'mode_tag_report_offset': mode['file_offset'],
            'limit': 'Mode labels and field layout are traced in the pinned bundled image; the live image was not dumped.'}


def analyze(path, static_schema):
    before = path.stat()
    raw = path.read_bytes()
    after = path.stat()
    if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
        raise ValueError('Capture changed while reading')
    lines = raw.splitlines(keepends=True)
    if not lines or not lines[-1].endswith(b'\n'):
        raise ValueError('Incomplete capture')
    start, end = json.loads(lines[0]), json.loads(lines[-1])
    if start.get('event') != 'start' or end.get('event') != 'end':
        raise ValueError('Missing start/end record')
    if (start.get('vid'), start.get('pid')) != (0x3670, 0x0804):
        raise ValueError('Unexpected device VID/PID')
    counts = Counter()
    locations = {}
    offset = len(lines[0])
    for line_number, line in enumerate(lines[1:-1], 2):
        row = json.loads(line)
        if 'event' in row:
            raise ValueError('Unexpected intermediate event')
        value = bytes.fromhex(row['hex'])
        if len(value) != row['length']:
            raise ValueError('Inconsistent callback length')
        if row['report_id'] == 2 and row['type'] == 0 and row['result'] == 0:
            counts[row['hex']] += 1
            locations.setdefault(row['hex'], {'line': line_number, 'file_offset': offset,
                                              'elapsed_ns': row['elapsed_ns']})
        offset += len(line)
    if end.get('reports') != len(lines)-2:
        raise ValueError('Inconsistent callback count')
    return {'capture': str(path), 'capture_sha256': sha(raw), 'size': len(raw),
            'complete': True, 'source_schema': static_schema,
            'report_2_count': sum(counts.values()),
            'variants': [{'hex': value, 'count': count, 'first_occurrence': locations[value],
                          'decoded': decode(bytes.fromhex(value), static_schema['mode_field'])}
                         for value, count in counts.most_common()]}


def write_consistent(path, result):
    text = json.dumps(result, indent=2) + '\n'
    if path.exists() and path.read_text() != text:
        raise ValueError(f'Output differs: {path}')
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('captures', nargs='+', type=Path)
    args = parser.parse_args()
    try:
        static = schema()
        write_consistent(ROOT/'work/simagic/mapping/zeus-status-schema.json', static)
        for capture in args.captures:
            result = analyze(capture, static)
            output = capture.with_suffix('.status.json')
            write_consistent(output, result)
            print(json.dumps({'output': str(output), 'report_2_count': result['report_2_count'],
                              'modes': [v['decoded'].get('communication_mode') for v in result['variants']]}))
    except (ValueError, KeyError, OSError) as error:
        parser.exit(2, f'{error}\n')


if __name__ == '__main__':
    main()
