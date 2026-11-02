#!/usr/bin/env python3
"""Check boundary/layout claims against the extracted descriptor, not hardware."""
from pathlib import Path
import hashlib,json,sys
from zeus_report_decode import decode

root=Path(__file__).resolve().parents[1]
ev=json.loads((root/'work/simagic/zeus-evidence.json').read_text())
assert ev['hid_reports']['input:0x01']['bytes_including_report_id']==23
fields=[x for x in ev['hid_fields'] if x['report_id']==1 and x['type']=='input']
assert [(x['payload_bit_offset'],x['report_size'],x['report_count']) for x in fields]==[(0,8,2),(16,1,120),(136,1,32),(168,8,1)]
descriptor=(root/'work/simagic/zeus-hid_report.bin').read_bytes()
row=next(x for x in ev['descriptors'] if x['kind']=='hid_report')
assert hashlib.sha256(descriptor).hexdigest()==row['output_sha256']
for i in range(120):
    frame=b'\x01\x12\x34'+(1<<i).to_bytes(15,'little')+bytes.fromhex('aa55ff00fe')
    got=decode(frame)
    assert got['rx']==18 and got['ry']==52
    assert got['pressed_button_usages']==[i+1]
    assert got['vendor_bits_hex']=='aa55ff00' and got['vendor_byte']==254
for frame in [b'',b'\x01'+bytes(21),b'\x01'+bytes(23),b'\x02'+bytes(22)]:
    try: decode(frame)
    except ValueError: pass
    else: raise AssertionError('Invalid frame accepted')
print('PASS: descriptor layout, 120 independent bit positions, field boundaries, invalid lengths and report ID. Synthetic only; no hardware validation.')
