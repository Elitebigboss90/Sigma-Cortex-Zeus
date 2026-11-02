#!/usr/bin/env python3
"""Extract the code-referenced Zeus factory mapping; does not touch hardware."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'work/simagic/zeus-formula-decoded.bin'
SHA = '85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a'
BASE = 0x08021e00

def varint(data, offset):
    value = 0
    for shift in range(0, 70, 7):
        if offset >= len(data): raise ValueError('Truncated varint')
        byte = data[offset]; offset += 1
        value |= (byte & 127) << shift
        if byte < 128: return value, offset
    raise ValueError('Overlong varint')

def fields(data, source_offset):
    result = []; offset = 0
    while offset < len(data):
        start = offset
        tag, offset = varint(data, offset)
        field, wire = tag >> 3, tag & 7
        if not field: raise ValueError('Zero field number')
        if wire == 0:
            value, offset = varint(data, offset)
            result.append({'file_offset':source_offset+start,'field':field,'wire':wire,'value':value})
        elif wire == 2:
            length, offset = varint(data, offset)
            end = offset+length
            if end > len(data): raise ValueError('Truncated length-delimited field')
            result.append({'file_offset':source_offset+start,'field':field,'wire':wire,
                           'payload_offset':source_offset+offset,'payload_hex':data[offset:end].hex(),
                           'length':length})
            offset = end
        else: raise ValueError(f'Unexpected wire type {wire}')
    return result

def main():
    source = SOURCE.read_bytes()
    assert hashlib.sha256(source).hexdigest() == SHA
    start = 0x0803cd8f-BASE
    payload = source[start:start+0xa2]
    groups = []; metadata = []
    for row in fields(payload,start):
        if row['field'] != 3:
            metadata.append(row)
            continue
        assert row['wire'] == 2
        items = fields(bytes.fromhex(row['payload_hex']),row['payload_offset'])
        group = {'file_offset':row['file_offset'],'encoded_length':row['length'],'fields':items}
        for item in items:
            if item['field'] == 1: group['group_id'] = item['value']
            elif item['field'] == 2: group['part_type'] = item['value']
            elif item['field'] == 3:
                packed = bytes.fromhex(item['payload_hex']); values=[]; at=0
                while at<len(packed):
                    value,at=varint(packed,at);values.append(value)
                group['usage_indices'] = values
        groups.append(group)
    types = {3:'16 ordinary button records',9:'2 seven-way controls, 7 records each',
             4:'4 paired-direction encoders, 2 records each',10:'4 rotary encoders, 2 relative-direction records each',
             2:'6 LED records; no input usages in this factory group'}
    for group in groups: group['interpretation']=types[group['part_type']]
    output = ROOT/'work/simagic/mapping/zeus-factory-mapping.bin'
    output.parent.mkdir(parents=True,exist_ok=True)
    if output.exists(): assert output.read_bytes()==payload
    else: output.write_bytes(payload)
    result={'source':str(SOURCE.relative_to(ROOT)),'source_sha256':SHA,
            'range':{'offset':start,'length':len(payload),'virtual_address':hex(BASE+start)},
            'operation':'Identity slice; protobuf wire decoding, group semantics from callers',
            'output':str(output.relative_to(ROOT)),'output_sha256':hashlib.sha256(payload).hexdigest(),
            'factory_copy_function':'0x0802AEC4','factory_pointer_literal':'0x0802AFDC',
            'application_function':'0x080251A8','groups':groups,'other_fields':metadata,
            'limits':['Factory defaults can be overridden by saved user presets.',
                      'Record order is not yet a measured physical-position map.',
                      'The live wheel firmware revision may differ from this bundled image.']}
    (output.parent/'zeus-factory-mapping.json').write_text(json.dumps(result,indent=2)+'\n')
    for group in groups: print(group['part_type'],group['interpretation'],group.get('usage_indices',[]))

if __name__ == '__main__': main()
