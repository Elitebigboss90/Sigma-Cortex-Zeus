#!/usr/bin/env python3
"""Evidence export for the decoded Sigma application; no mutation or execution."""
import argparse, hashlib, json, re, struct
from pathlib import Path
import capstone

def hid_fields(data, source_offset):
    at=0; state={'size':0,'count':0,'id':0,'usage_page':0}; stack=[]; usages=[]; fields=[]; totals={}
    while at<len(data):
        start=at; prefix=data[at];at+=1
        if prefix==0xfe:
            size=data[at];at+=2+size;continue
        size=(0,1,2,4)[prefix&3]; kind=(prefix>>2)&3;tag=prefix>>4
        raw=data[at:at+size];at+=size;value=int.from_bytes(raw,'little')
        if kind==1:
            if tag in (0,7,8,9):state[{0:'usage_page',7:'size',8:'id',9:'count'}[tag]]=value
            elif tag==10:stack.append(state.copy())
            elif tag==11:state=stack.pop()
        elif kind==2:usages.append({'tag':tag,'value':value})
        elif kind==0:
            if tag in (8,9,11):
                direction={8:'input',9:'output',11:'feature'}[tag];key=(state['id'],direction)
                bit_offset=totals.get(key,0);bits=state['size']*state['count'];totals[key]=bit_offset+bits
                fields.append({'file_offset':hex(source_offset+start),'main_item_bytes':data[start:at].hex(),
                               'report_id':state['id'],'direction':direction,'report_bit_offset':bit_offset,
                               'report_size':state['size'],'report_count':state['count'],'usage_page':hex(state['usage_page']),
                               'usage_items':usages,'flags':hex(value)})
            usages=[]
    return {'fields':fields,'report_lengths':[{'report_id':rid,'direction':direction,'bits':bits,
              'payload_bytes':(bits+7)//8,'bytes_including_id':(bits+7)//8+(1 if rid else 0)}
              for (rid,direction),bits in sorted(totals.items())]}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('source',type=Path)
    ap.add_argument('--output',type=Path,default=Path('reports/sigma-architecture-evidence.json'))
    a=ap.parse_args();b=a.source.read_bytes();base=0x08020000
    def region(off,length):return {'offset':hex(off),'va':hex(base+off),'length':length,'bytes':b[off:off+length].hex()}
    def word(off):return struct.unpack_from('<I',b,off)[0]
    c=capstone.Cs(capstone.CS_ARCH_ARM,capstone.CS_MODE_THUMB|capstone.CS_MODE_MCLASS)
    def disasm(off,length):
        return [{'offset':hex(i.address-base),'va':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}
                for i in c.disasm(b[off:off+length],base+off)]
    vector_end=4
    while vector_end+4<=len(b):
        w=word(vector_end)
        if w and not (w&1 and base<=(w&~1)<base+len(b)):break
        vector_end+=4
    vectors=[{**region(o,4),'word':hex(word(o)),'target_offset':hex((word(o)&~1)-base) if o and word(o) else None}
             for o in range(0,vector_end,4)]
    descriptors=[]
    for o in range(len(b)-18):
        if b[o:o+2]!=b'\x12\x01' or b[o+7] not in (8,16,32,64) or b[o+17] not in (1,2,3):continue
        vid,pid=struct.unpack_from('<HH',b,o+8)
        entry={**region(o,18),'vendor_id':hex(vid),'product_id':hex(pid),'bcd_usb':hex(word(o+2)&0xffff),
               'bcd_device':hex(word(o+12)&0xffff),'max_packet_size_ep0':b[o+7]}
        conf=o+18
        if b[conf:conf+2]==b'\x09\x02':
            total=struct.unpack_from('<H',b,conf+2)[0];entry['configuration']=region(conf,total)
            sections=[];sub=conf;hid_length=None
            while sub<conf+total:
                size=b[sub]
                if size<2 or sub+size>conf+total:break
                sections.append({**region(sub,size),'type':hex(b[sub+1])})
                if b[sub+1]==0x21 and size>=9:hid_length=struct.unpack_from('<H',b,sub+7)[0]
                sub+=size
            entry['configuration_parts']=sections
            if hid_length:
                h=conf+total;entry['hid_report_descriptor']=region(h,hid_length)
                entry['hid_report_summary']=hid_fields(b[h:h+hid_length],h)
                s=h+hid_length;strings=[]
                while s+2<len(b) and b[s+1]==3 and b[s]>=2 and b[s]%2==0:
                    size=b[s];raw=b[s+2:s+size]
                    entry_string=region(s,size)
                    if not strings: entry_string['language_ids']=[hex(struct.unpack_from('<H',raw,i)[0]) for i in range(0,len(raw),2)]
                    else: entry_string['utf16le']=raw.decode('utf-16le',errors='replace')
                    strings.append(entry_string);s+=size
                entry['string_descriptors']=strings
        descriptors.append(entry)
    result={'source':str(a.source),'sha256':hashlib.sha256(b).hexdigest(),'size':len(b),
            'candidate_base':hex(base),'base_evidence':'VTOR write at file 0x5264..0x5274; reset/vector pointers agree',
            'vector_table':{'offset':0,'length':vector_end,'word_count':len(vectors),'initial_sp':hex(word(0)),
                            'reset_thumb_pointer':hex(word(4)),'reset_code_address':hex(word(4)&~1),'entries':vectors},
            'selected_disassembly':{name:disasm(o,n) for name,o,n in [
                ('reset',0x290,8),('default_handler',0x2aa,2),('system_init',0x7f8,0xf0),
                ('application_init_vtor',0x525c,0x30),('exceptions',0x5538,0x24),('systick_handler',0x4fc0,0x16)]},
            'reset_literals':[region(0x2b8,4),region(0x2bc,4)],
            'usb_descriptors':descriptors,
            'selected_strings':[{**region(m.start(),len(m.group())),'ascii':m.group().decode()} for m in re.finditer(rb'[ -~]{5,}',b)
                              if any(k in m.group() for k in [b'FW:',b'HW:',b'Wheel',b'Shifter',b'Channel'])],
            'limits':['This script selects evidence-backed ranges; it does not prove all decoded instructions are reachable.',
                      'Specific MCU package, total flash/RAM capacity, and hardware identity require further evidence.',
                      'USB descriptor describes converter output identity, not its accepted input-device set.']}
    a.output.write_text(json.dumps(result,indent=2)+'\n')
    print('SHA-256',result['sha256'],'vectors',len(vectors),'USB candidates',len(descriptors))
    for d in descriptors: print(d['offset'],d['vendor_id'],d['product_id'],d.get('hid_report_summary',{}).get('report_lengths'))

if __name__=='__main__':main()
