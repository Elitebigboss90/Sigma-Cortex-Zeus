#!/usr/bin/env python3
"""Record Zeus SFU, vector, USB descriptor and HID item evidence offline."""
import hashlib,json,struct
from pathlib import Path

def sha(b):return hashlib.sha256(b).hexdigest()

def main():
    sf=Path('work/simagic/3.2.3.13713/$APPDATA/Local/Simagic/Simpro3/firmware/wheel/zf/ZeusFormula_App-A1.1.15.13445-eb889282.sfu')
    plain=Path('work/simagic/zeus-formula-decoded.bin');s=sf.read_bytes();b=plain.read_bytes()
    assert sha(s)=='571535e07edc9efb8c7403eecf60caf861631ae9bf312a2755acc4d4e26b7e7f'
    assert sha(b)=='85961f88feba079fa9a9c5e72e6c329b880c98082a305da60c3c851b04b7756a'
    base=0x08021e00
    result={'sfu':{'source':str(sf),'sha256':sha(s),'size':len(s),'header_bytes':s[:64].hex(),
      'magic':s[:13].decode('ascii').rstrip('\0'),'format_u16_at_0x0e':struct.unpack_from('<H',s,14)[0],
      'target':s[16:32].split(b'\0')[0].decode(),'version':s[32:48].split(b'\0')[0].decode(),
      'declared_length_at_0x30':struct.unpack_from('<I',s,48)[0],
      'product_code_0x34':hex(struct.unpack_from('<I',s,52)[0]),'product_code_0x38':hex(struct.unpack_from('<I',s,56)[0]),
      'pid_0x3c':hex(struct.unpack_from('<H',s,60)[0]),'vid_0x3e':hex(struct.unpack_from('<H',s,62)[0])},
      'decoded':{'path':str(plain),'sha256':sha(b),'size':len(b),'mapped_start':hex(base),
      'vector_offset':512,'vector_va':hex(base+512),'initial_sp':hex(struct.unpack_from('<I',b,512)[0]),
      'reset_vector':hex(struct.unpack_from('<I',b,516)[0]),'reset_file_offset':hex((struct.unpack_from('<I',b,516)[0]&~1)-base),
      'processor_profile':'ARM:LE:32:Cortex','caveat':'Specific MCU model not established.'},'descriptors':[]}
    for name,off,n in [('configuration',0x1ade8,41),('device',0x1ae14,18),('hid_report',0x1ae28,164)]:
        data=b[off:off+n];p=Path('work/simagic')/('zeus-'+name+'.bin');p.write_bytes(data)
        result['descriptors'].append({'kind':name,'source_sha256':sha(b),'offset':off,'va':hex(base+off),'length':n,
            'operation':'identity slice','bytes':data.hex(),'output':str(p),'output_sha256':sha(data)})
    r=b[0x1ae28:0x1ae28+164];pos=0;globals_={};locals_={};items=[];counts={};fields=[]
    while pos<len(r):
        start=pos;tag=r[pos];pos+=1
        if tag==254:raise ValueError('Unexpected long HID item')
        n=[0,1,2,4][tag&3];val=int.from_bytes(r[pos:pos+n],'little');pos+=n
        kind=(tag>>2)&3;item=tag>>4
        items.append({'descriptor_offset':start,'decoded_offset':0x1ae28+start,'bytes':r[start:pos].hex(),'kind':kind,'tag':item,'value':val})
        if kind==1:globals_[item]=val
        elif kind==2:locals_.setdefault(item,[]).append(val)
        elif kind==0:
            if item in [8,9,11]:
                report=globals_.get(8,0);size=globals_.get(7,0);count=globals_.get(9,0);typ={8:'input',9:'output',11:'feature'}[item]
                k=f'{typ}:{report:#04x}';bitstart=counts.get(k,0);counts[k]=bitstart+size*count
                fields.append({'report_id':report,'type':typ,'payload_bit_offset':bitstart,'report_size':size,'report_count':count,
                  'usage_page':globals_.get(0),'usages':locals_,'flags':val,'descriptor_item_offset':start})
            locals_={}
    result['hid_items']=items;result['hid_fields']=fields
    result['hid_reports']={k:{'payload_bits':v,'payload_bytes':(v+7)//8,'bytes_including_report_id':(v+7)//8+1} for k,v in counts.items()}
    result['integrity_unknowns']={'decoded_header_hex':b[:32].hex(),
      'u32_at_0x08':struct.unpack_from('<I',b,8)[0],'u32_at_0x0c':hex(struct.unpack_from('<I',b,12)[0]),
      'bytes_at_0x10_0x20':b[16:32].hex(),'interpretation':'Unresolved metadata; no signature/checksum identity asserted.'}
    Path('work/simagic/zeus-evidence.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result['hid_reports'],indent=2))

if __name__=='__main__':main()
