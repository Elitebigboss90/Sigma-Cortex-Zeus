#!/usr/bin/env python3
"""Reproduce recovered AES-256-CTR; records lineage and never overwrites input.

Key/IV derive from byte MOV immediates in SimPro's SFU parser, not guessed keys.
Use --offset 64 for SFU; zero for extracted Sigma IDR_APP_FILE resources.
Requires project pefile and the macOS OpenSSL command.
"""
import argparse, hashlib, json, subprocess
from pathlib import Path
import pefile

KEY_SOURCE_SHA = 'fa0505afc50f2f40311b8a2bff7c945ff32af39dea86f0d110ac4f49f4026192'

def sha(b): return hashlib.sha256(b).hexdigest()

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('source',type=Path);ap.add_argument('output',type=Path)
    ap.add_argument('--offset',type=lambda x:int(x,0),default=0)
    ap.add_argument('--key-source',type=Path,default=Path('work/simagic/3.2.3.13713/Simagic/Simpro3/bin/simpro3.exe'))
    a=ap.parse_args()
    kb=a.key_source.read_bytes();assert sha(kb)==KEY_SOURCE_SHA,'Different SimPro build: re-establish constants first'
    pe=pefile.PE(data=kb);base=pe.OPTIONAL_HEADER.ImageBase
    entries=[];vals={}
    for i in range(64):
        va=0x140578a22+i*8;off=pe.get_offset_from_rva(va-base);ins=kb[off:off+8]
        assert ins[:3]==bytes.fromhex('c68424')
        stack=int.from_bytes(ins[3:7],'little');vals[stack]=ins[7]
        entries.append({'va':hex(va),'file_offset':off,'instruction_bytes':ins.hex(),'stack_offset':hex(stack),'value':ins[7]})
    key=bytes(vals[i] for i in range(0x3f0,0x410))
    iv=bytes(vals[i] for i in range(0x3d0,0x3e0))
    src=a.source.read_bytes();assert 0<=a.offset<=len(src)
    assert a.output.resolve()!=a.source.resolve()
    args=['openssl','enc','-aes-256-ctr','-d','-K',key.hex(),'-iv',iv.hex()]
    data=subprocess.run(args,input=src[a.offset:],capture_output=True,check=True).stdout
    check=subprocess.run(args,input=data,capture_output=True,check=True).stdout
    assert check==src[a.offset:],'CTR round-trip mismatch'
    a.output.parent.mkdir(parents=True,exist_ok=True)
    if a.output.exists():assert a.output.read_bytes()==data,'Refusing overwrite of different result'
    else:a.output.write_bytes(data)
    manifest={'source':str(a.source),'source_sha256':sha(src),'range':{'offset':a.offset,'length':len(src)-a.offset},
      'operation':'AES-256-CTR XOR, 128-bit big-endian counter; no padding removed',
      'key_source':str(a.key_source),'key_source_sha256':sha(kb),'key':key.hex(),'initial_counter':iv.hex(),
      'key_instruction_evidence':entries[:32],'iv_instruction_evidence':entries[32:48],
      'implementation_evidence':{'init_va':'0x140b7fc80','key_expansion_va':'0x140b806d0','cipher_va':'0x140b80620','ctr_va':'0x140b7fd10'},
      'output':str(a.output),'output_size':len(data),'output_sha256':sha(data),'round_trip_matches_source_range':True,
      'tool':subprocess.run(['openssl','version'],capture_output=True,text=True,check=True).stdout.strip()}
    a.output.with_suffix(a.output.suffix+'.transform.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({k:manifest[k] for k in ['source','source_sha256','range','output','output_size','output_sha256','round_trip_matches_source_range']},indent=2))

if __name__=='__main__':main()
