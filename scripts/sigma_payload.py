#!/usr/bin/env python3
"""Extract Sigma 1.1.5 payload and reconstruct logical update frames OFFLINE.

No USB access, target execution, firmware modification, or flashing.
Frame bytes exclude padding: actual report length comes from HID capabilities.
The resource range is corroborated by the PE directory and updater call graph.
"""
from pathlib import Path
import hashlib, json, struct, math
from collections import Counter

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT/'originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe'
EXPECTED = '585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a'
OFFSET, LENGTH = 0x1e7ef8, 0x2e280

def digest(b): return hashlib.sha256(b).hexdigest()

def main():
    source=SOURCE.read_bytes()
    assert digest(source)==EXPECTED, 'Unrecognized updater; do not reuse fixed offsets'
    payload=source[OFFSET:OFFSET+LENGTH]
    assert len(payload)==LENGTH
    dst=ROOT/'work/sigma/1.1.5/SIGMA_Converter_V1.1.5.payload.bin'
    if dst.exists(): assert dst.read_bytes()==payload
    else: dst.write_bytes(payload)
    frames=[]
    for off in range(0,len(payload),32):
        chunk=payload[off:off+32]
        frame=bytes([0xf2,0x0a,len(chunk)])+struct.pack('<I',off)+chunk
        frames.append(frame)
    # Independent reassembly validates ranges/lengths, not hardware acceptance.
    restored=bytearray()
    for f in frames:
        assert f[:2]==bytes([0xf2,0x0a])
        assert struct.unpack_from('<I',f,3)[0]==len(restored)
        assert len(f[7:])==f[2]
        restored.extend(f[7:])
    assert bytes(restored)==payload
    candidates=[]
    for off in range(0,len(payload)-8,4):
        sp,reset=struct.unpack_from('<II',payload,off)
        if 0x20000000<=sp<0x20100000 and sp%8==0 and reset&1 and (0x08000000<=reset<0x08200000 or reset<0x100000):
            candidates.append({'offset':off,'sp':hex(sp),'reset':hex(reset)})
    result={
      'source':str(SOURCE.relative_to(ROOT)),'source_sha256':EXPECTED,
      'operation':'identity slice; PE TEXTFILE/IDR_APP_FILE/1033',
      'range':{'offset':OFFSET,'length':LENGTH,'end_exclusive':OFFSET+LENGTH},
      'output':str(dst.relative_to(ROOT)),'output_sha256':digest(payload),
      'entropy_bits_per_byte':-sum(n/LENGTH*math.log2(n/LENGTH) for n in Counter(payload).values()),
      'first_64_bytes':payload[:64].hex(),'last_64_bytes':payload[-64:].hex(),
      'bounded_vector_scan':{'step':4,'sp_range':'[0x20000000,0x20100000), aligned8',
        'reset_range':'odd, [0,0x100000) or [0x08000000,0x08200000)',
        'candidates':candidates,'limitation':'Heuristic only; empty does not exclude ARM or other mappings.'},
      'logical_update_frames':{'source_function_va':'0x404c00','count':len(frames),
        'data_bytes_per_full_frame':32,'header':'F2 0A length u32le(resource_offset)',
        'first_frame_hex':frames[0].hex(),'last_frame_hex':frames[-1].hex(),
        'reassembled_sha256':digest(restored),'reassembly_equals_resource':True,
        'padding':'Not synthesized; full report length comes from HidP_GetCaps.OutputReportByteLength.',
        'interpretation':'Resource-relative transfer offset, not a proven flash/load address.'}
    }
    (ROOT/'work/sigma/1.1.5/payload-manifest.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'payload_sha256':digest(payload),'logical_frames':len(frames),'reassembly':True}))

if __name__=='__main__': main()
