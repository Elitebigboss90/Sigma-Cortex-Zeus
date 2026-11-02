#!/usr/bin/env python3
"""Recover Sigma 1.1.5 startup/ABI evidence without modifying firmware."""
from pathlib import Path
import hashlib, json, struct
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_LITTLE_ENDIAN

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'work/sigma/1.1.5/sigma-decoded.bin'
EXPECTED = '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'
BASE = 0x08020000

def main():
    data = SOURCE.read_bytes()
    assert hashlib.sha256(data).hexdigest() == EXPECTED
    destination = ROOT / 'work/sigma/patch-design'
    destination.mkdir(parents=True, exist_ok=True)
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_LITTLE_ENDIAN)
    result = {'source': str(SOURCE.relative_to(ROOT)), 'sha256': EXPECTED,
              'base': hex(BASE), 'ranges': [], 'vtables': [], 'scatterload': []}
    for start, end, label in [
        (0x1a0, 0x1cc, 'scatterload_dispatch'),
        (0x1d4, 0x22e, 'scatterload_decompress'),
        (0x230, 0x24c, 'scatterload_zero'),
        (0x2ac, 0x2b6, 'user_initial_stackheap'),
        (0x44a, 0x494, 'runtime_heap_stack_initialization'),
        (0x666, 0x688, 'bounded_bump_allocator'),
        (0x50ec, 0x5108, 'constructor_call_hook'),
        (0x5168, 0x51b0, 'generic_constructor'),
        (0x536e, 0x53a8, 'report_build_hook'),
    ]:
        result['ranges'].append({'label': label, 'offset': start, 'length': end-start,
            'bytes': data[start:end].hex(),
            'instructions': [{'va':hex(i.address), 'bytes':i.bytes.hex(),
                              'asm':i.mnemonic+' '+i.op_str}
                             for i in md.disasm(data[start:end], BASE+start)]})
    result['heap_stack_literals'] = [
        {'offset':o, 'role':role, 'bytes':data[o:o+4].hex(),
         'value':hex(struct.unpack_from('<I',data,o)[0])}
        for o,role in [(0x2c0,'heap_base'),(0x2c4,'stack_top'),
                       (0x2c8,'heap_limit'),(0x2cc,'stack_base')]]
    for o in [0x2dff0,0x2e000]:
        src,dst,size,fn = struct.unpack_from('<4I',data,o)
        result['scatterload'].append({'offset':o,'bytes':data[o:o+16].hex(),
            'source_va':hex(src),'destination_va':hex(dst),'size':size,'function_va':hex(fn)})
    for va in [0x08046750, 0x080467f8, 0x080469f4, 0x08046a4c, 0x08046aa4]:
        result['vtables'].append({'va':hex(va),'offset':va-BASE,
            'bytes':data[va-BASE:va-BASE+0x50].hex(),
            'slots':[{'offset':i,'value':hex(struct.unpack_from('<I',data,va-BASE+i)[0])}
                     for i in range(0,0x50,4)]})
    # Translate the observed instructions at 080201D4, not a guessed archive codec.
    p=0x2e018
    initialized=bytearray()
    while len(initialized)<0x7b0:
        token=data[p]; p+=1
        literals=token&7
        if not literals: literals=data[p]; p+=1
        repeats=token>>4
        if not repeats: repeats=data[p]; p+=1
        initialized+=data[p:p+literals-1]; p+=literals-1
        if token&8:
            distance=data[p]; p+=1; repeats+=2
            assert 0<distance<=len(initialized)
            for _ in range(repeats): initialized.append(initialized[-distance])
        else:
            initialized+=bytes(repeats)
        assert len(initialized)<=0x7b0
    out=destination/'initial-data.bin'
    if out.exists(): assert out.read_bytes()==initialized
    else: out.write_bytes(initialized)
    result['initial_data_transform']={'source_range':[0x2e018,p],
        'operation':'Instruction-equivalent scatterload decompression at 0x080201D4',
        'output':str(out.relative_to(ROOT)),'destination_va':'0x20000000',
        'size':len(initialized),'sha256':hashlib.sha256(initialized).hexdigest()}
    (destination/'hook-evidence.json').write_text(json.dumps(result,indent=2)+'\n')
    print('Verified source; saved startup, vtable, hook bytes and initialized RAM evidence.')

if __name__=='__main__': main()
