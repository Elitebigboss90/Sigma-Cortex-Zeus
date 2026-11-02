#!/usr/bin/env python3
"""Static PE inventory and byte-exact resource extraction; never executes input."""
import argparse, hashlib, json, math, re
from collections import Counter
from pathlib import Path
import pefile

def sha(b): return hashlib.sha256(b).hexdigest()
def entropy(b):
    return -sum((n/len(b))*math.log2(n/len(b)) for n in Counter(b).values()) if b else 0

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('source',type=Path); ap.add_argument('destination',type=Path)
    a=ap.parse_args(); a.destination.mkdir(parents=True,exist_ok=True)
    raw=a.source.read_bytes(); pe=pefile.PE(data=raw)
    result={'source':str(a.source),'sha256':sha(raw),'size':len(raw),'machine':hex(pe.FILE_HEADER.Machine),
            'image_base':hex(pe.OPTIONAL_HEADER.ImageBase),'entry_rva':hex(pe.OPTIONAL_HEADER.AddressOfEntryPoint),
            'timestamp_raw':pe.FILE_HEADER.TimeDateStamp,'sections':[],'directories':[], 'imports':[], 'resources':[]}
    for s in pe.sections:
        result['sections'].append({'name':s.Name.rstrip(b'\0').decode(),'rva':hex(s.VirtualAddress),
          'virtual_size':s.Misc_VirtualSize,'offset':s.PointerToRawData,'size':s.SizeOfRawData,'entropy':entropy(s.get_data())})
    for d in pe.OPTIONAL_HEADER.DATA_DIRECTORY:
        result['directories'].append({'name':d.name,'address':hex(d.VirtualAddress),'size':d.Size})
    for lib in getattr(pe,'DIRECTORY_ENTRY_IMPORT',[]):
        result['imports'].append({'dll':lib.dll.decode(),'symbols':[{'name':i.name.decode() if i.name else None,
          'ordinal':i.ordinal,'iat_va':hex(i.address)} for i in lib.imports]})
    def walk(d, names=()):
        for e in d.entries:
            key=str(e.name) if e.name else str(e.id); path=names+(key,)
            if hasattr(e,'directory'): walk(e.directory,path)
            else:
                s=e.data.struct; off=pe.get_offset_from_rva(s.OffsetToData); data=raw[off:off+s.Size]
                assert len(data)==s.Size
                fn='resource_'+'_'.join(re.sub(r'[^A-Za-z0-9_.-]','_',x) for x in path)+'.bin'
                out=a.destination/fn
                if out.exists(): assert out.read_bytes()==data, f'Refusing overwrite: {out}'
                else: out.write_bytes(data)
                result['resources'].append({'resource_path':list(path),'rva':hex(s.OffsetToData),'offset':off,
                  'length':s.Size,'operation':'identity slice','source_sha256':sha(raw),
                  'output':str(out),'sha256':sha(data),'entropy':entropy(data),'first_32_bytes':data[:32].hex()})
    if hasattr(pe,'DIRECTORY_ENTRY_RESOURCE'): walk(pe.DIRECTORY_ENTRY_RESOURCE)
    result['overlay_offset']=pe.get_overlay_data_start_offset()
    result['version_strings']=[]
    for group in getattr(pe,'FileInfo',[]):
        for item in group:
            for table in getattr(item,'StringTable',[]):
                result['version_strings'].append({k.decode(errors='replace'):v.decode(errors='replace') for k,v in table.entries.items()})
    (a.destination/'inventory.json').write_text(json.dumps(result,indent=2)+'\n')
    strings=[]
    for enc,pat in [('ascii',rb'[ -~]{5,}'),('utf-16le',rb'(?:[ -~]\x00){5,}')]:
        for m in re.finditer(pat,raw): strings.append((m.start(),enc,m.group().decode(enc)))
    (a.destination/'strings.txt').write_text('\n'.join(f'{o:08x} {e} {s}' for o,e,s in sorted(strings))+'\n')
    print(json.dumps({k:result[k] for k in ['source','sha256','size','machine','image_base','entry_rva','resources','version_strings']},indent=2))

if __name__=='__main__': main()
