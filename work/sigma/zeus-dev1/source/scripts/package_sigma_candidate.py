#!/usr/bin/env python3
"""Create a quarantined updater copy for offline review; never execute it.

The output ends in .exe.disabled because bootloader acceptance is not verified.
The original PE/resources remain at their offsets. Only the selected resource
entry is redirected to a new read-only section containing the candidate carrier.
"""
import hashlib,json,struct
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'work/sigma/zeus-dev1'
SOURCE=ROOT/'originals/SIGMA v1.1.5 BETA/SIGMA_Converter_V1.1.5.exe'
SHA='585a72f0fc40b33e374f67bdf8df4c537b0f0d879e9d2f7b65a598253196fc7a'
def sha(b):return hashlib.sha256(b).hexdigest()
def align(n,a):return (n+a-1)//a*a
def resources(pe):
    return {(str(t.name or t.id),str(n.name or n.id),lang.id):lang.data.struct
            for t in pe.DIRECTORY_ENTRY_RESOURCE.entries for n in t.directory.entries for lang in n.directory.entries}

def main():
    m=json.loads((OUT/'build-manifest.json').read_text());v=json.loads((OUT/'emulator-verification.json').read_text())
    assert v['status']=='PASS' and v['image_sha256']==m['artifacts']['plaintext']['sha256']
    carrier=(ROOT/m['artifacts']['encoded']['path']).read_bytes();assert sha(carrier)==m['artifacts']['encoded']['sha256']
    original=SOURCE.read_bytes();assert sha(original)==SHA
    pe=pefile.PE(data=original);data=bytearray(original)
    assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[4].Size==0,'Unexpected signature table; re-evaluate packaging'
    assert pe.get_overlay_data_start_offset() is None
    key=('TEXTFILE','IDR_APP_FILE',1033);entries=resources(pe);entry=entries[key]
    assert entry.Size==189056
    old_carrier=pe.get_data(entry.OffsetToData,entry.Size)
    assert sha(old_carrier)=='4336870decb070816e16a3d8843ac2f2f4ef7f66bdd451897f56820865216282'
    file_align=pe.OPTIONAL_HEADER.FileAlignment;section_align=pe.OPTIONAL_HEADER.SectionAlignment
    section_offset=pe.sections[-1].get_file_offset()+40
    assert section_offset+40<=min(s.PointerToRawData for s in pe.sections if s.SizeOfRawData)
    assert not any(data[section_offset:section_offset+40]),'New section header would overwrite existing nonzero bytes'
    va=align(max(s.VirtualAddress+max(s.Misc_VirtualSize,s.SizeOfRawData) for s in pe.sections),section_align)
    raw=align(len(data),file_align);size=align(len(carrier),file_align)
    data.extend(bytes(raw-len(data)));data.extend(carrier);data.extend(bytes(size-len(carrier)))
    section=struct.pack('<8sIIIIIIHHI',b'.zeus\0\0\0',len(carrier),va,size,raw,0,0,0,0,0x40000040)
    data[section_offset:section_offset+40]=section
    changes=[]
    def edit(offset,fmt,value,reason):
        new=struct.pack(fmt,value);old=bytes(data[offset:offset+len(new)]);data[offset:offset+len(new)]=new
        changes.append({'offset':offset,'old_hex':old.hex(),'new_hex':new.hex(),'reason':reason})
    edit(pe.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),'<H',pe.FILE_HEADER.NumberOfSections+1,'Add read-only initialized-data section')
    edit(pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),'<I',align(va+len(carrier),section_align),'Extend PE image mapping')
    edit(pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfInitializedData'),'<I',pe.OPTIONAL_HEADER.SizeOfInitializedData+size,'Account for appended initialized data')
    edit(entry.get_field_absolute_offset('OffsetToData'),'<I',va,'Redirect only firmware resource to candidate carrier')
    edit(entry.get_field_absolute_offset('Size'),'<I',len(carrier),'Use candidate resource length')
    candidate=pefile.PE(data=data)
    edit(pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),'<I',candidate.generate_checksum(),'Recompute PE checksum; this is NOT firmware integrity/authentication')
    candidate=pefile.PE(data=data);new_entries=resources(candidate)
    assert set(new_entries)==set(entries)
    for k,old in entries.items():
        after=new_entries[k];payload=candidate.get_data(after.OffsetToData,after.Size)
        assert payload==(carrier if k==key else pe.get_data(old.OffsetToData,old.Size)),k
    assert candidate.verify_checksum()
    assert candidate.get_overlay_data_start_offset() is None
    name='NOT_FOR_FLASHING-SIGMA_Converter_V1.1.5-Zeus-dev1.exe.disabled'
    path=OUT/name;path.write_bytes(data)
    result={'status':'OFFLINE_QUARANTINED_UPDATER_COPY','execution_performed':False,'bootloader_acceptance_verified':False,
      'original':{'path':str(SOURCE.relative_to(ROOT)),'sha256':SHA,'size':len(original)},
      'candidate':{'path':str(path.relative_to(ROOT)),'sha256':sha(data),'size':len(data)},
      'firmware_carrier':m['artifacts']['encoded'],
      'new_section':{'name':'.zeus','header_offset':section_offset,'rva':va,'raw_offset':raw,'raw_size':size,'virtual_size':len(carrier),'characteristics':'0x40000040'},
      'header_and_resource_edits':changes,'unchanged_other_resources':len(entries)-1,'candidate_resource_matches':True,'PE_checksum_verified':True,
      'limitations':['PE/resource consistency does not establish device acceptance','Do not rename/run/flash until integrity and recovery questions resolved'],
      'script_sha256':sha(Path(__file__).read_bytes())}
    (OUT/'package-manifest.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'status':result['status'],'candidate':result['candidate'],'unchanged_other_resources':len(entries)-1,'candidate_resource_matches':True},indent=2))

if __name__=='__main__':main()
