#!/usr/bin/env python3
"""Reproduce byte-bound evidence for the reviewed Sigma release comparison.

Semantic labels are reviewed analysis annotations, not a claimed automatic diff.
"""
from pathlib import Path
import hashlib,json,struct

ROOT=Path(__file__).resolve().parents[1]
def sha(b):return hashlib.sha256(b).hexdigest()
versions={
 '1.0.20':{
  'original':'originals/SIGMA v1.0.20/SIGMA_Converter_V1.0.20.exe',
  'original_sha256':'4e251340b80d4227049ef94bfff3ab520cc7c5053cb4b2bd778be870059c3f23',
  'decoded':'work/sigma/1.0.20/sigma-decoded.bin',
  'decoded_sha256':'3fc925cb7d12f3179a27248b2d86868d0556d7f36be33092b39bcced254c9e20',
  'functions':{'base_gate':0x08028e28,'pedal_gate':0x08025900,'handbrake_gate':0x0802aa1c,
    'shifter_gate':0x0802a2fc,'base_callback':0x08025aac,'parser_32':0x08025b98,
    'parser_39':0x08026028,'console_report_builder':0x0804b70c}},
 '1.1.5':{
  'original':'originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe',
  'original_sha256':'585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a',
  'decoded':'work/sigma/1.1.5/sigma-decoded.bin',
  'functions':{'base_gate':0x08027108,'pedal_gate':0x0802bb50,'handbrake_gate':0x0802ba28,
    'shifter_gate':0x0802bcd8,'base_callback':0x08027280,'parser_32':0x08027810,
    'parser_39':0x080272e0,'console_report_builder':0x0802a8b4}},
}
for ver,v in versions.items():
 b=(ROOT/v['original']).read_bytes();assert sha(b)==v['original_sha256']
 v['original_size']=len(b)
 b=(ROOT/v['decoded']).read_bytes()
 if 'decoded_sha256' in v:assert sha(b)==v['decoded_sha256']
 v['decoded_sha256']=sha(b);v['decoded_size']=len(b)
 v['mapping']={'file_zero_va':'0x08020000','byte_order':'little','mode':'Thumb Cortex-M'}
 v['vectors']={'file_offset':0,'first_64_bytes':b[:64].hex(),'initial_sp':hex(struct.unpack_from('<I',b)[0]),
  'reset_vector':hex(struct.unpack_from('<I',b,4)[0]),'reset_code_va':hex(struct.unpack_from('<I',b,4)[0]&~1)}
 v['functions']={name:{'va':hex(va),'decoded_file_offset':hex(va-0x08020000),
   'first_32_bytes':b[va-0x08020000:va-0x08020000+32].hex()} for name,va in v['functions'].items()}
out={'method':'Manual semantic matching by accepted VID/PID predicates, report lengths, input field offsets and output data flow; not offset-delta matching.',
 'versions':versions,'download':{
 'landing_page':'https://www.egsimrigs.co.za/products/sigma-cortex-converter',
 'url':'https://cdn.shopify.com/s/files/1/0733/4782/5941/files/SIGMA_Converter_V1.0.20.exe?v=1704246254',
 'source_class':'retailer-hosted package linked by product page; manufacturer authenticity not independently established'}}
(ROOT/'work/sigma/release-comparison.json').write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({k:{f:v[f] for f in ['original_sha256','decoded_sha256','decoded_size']} for k,v in versions.items()},indent=2))
