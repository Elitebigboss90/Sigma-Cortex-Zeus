#!/usr/bin/env python3
"""Build an OFFLINE experimental Sigma1.1.5 image. Does not create/run an updater.

Three hash/byte-pinned edits, append-only code, preserved original opaque tail.
Bootloader acceptance remains unknown; successful build does not permit flashing.
"""
import hashlib, io, json, struct, subprocess
from pathlib import Path
import capstone
from elftools.elf.elffile import ELFFile

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'work/sigma/1.1.5/sigma-decoded.bin'
EXPECTED='03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'
BASE=0x08020000
ORIGIN=0x0804e280
OUT=ROOT/'work/sigma/zeus-dev1'
CLANG='/opt/homebrew/opt/llvm/bin/clang'
LLD='/opt/homebrew/bin/ld.lld'
OPENSSL='/opt/homebrew/bin/openssl'

def sha(data):return hashlib.sha256(data).hexdigest()
def run(args,**kwargs):return subprocess.run(args,check=True,capture_output=True,**kwargs).stdout
def thumb_bl(at,target):
    target &= ~1
    delta=target-at-4
    assert delta%2==0 and -(1<<24)<=delta<(1<<24)
    s=(delta>>24)&1; i1=(delta>>23)&1; i2=(delta>>22)&1
    j1=1^i1^s;j2=1^i2^s
    code=struct.pack('<HH',0xf000|(s<<10)|((delta>>12)&0x3ff),0xd000|(j1<<13)|(j2<<11)|((delta>>1)&0x7ff))
    cs=capstone.Cs(capstone.CS_ARCH_ARM,capstone.CS_MODE_THUMB|capstone.CS_MODE_MCLASS)
    ins=list(cs.disasm(code,at))
    assert len(ins)==1 and ins[0].mnemonic=='bl' and int(ins[0].op_str.lstrip('#'),16)==target
    return code

def main():
    original=SOURCE.read_bytes();assert sha(original)==EXPECTED
    assert BASE+len(original)==ORIGIN
    OUT.mkdir(parents=True,exist_ok=True)
    compile_args=[CLANG,'--target=arm-none-eabi','-march=armv7-m','-mthumb','-mfloat-abi=soft','-mno-unaligned-access',
      '-Os','-g','-ffreestanding','-fno-builtin','-fno-stack-protector','-fno-unwind-tables','-fno-asynchronous-unwind-tables',
      '-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Werror','-c',str(ROOT/'patch/sigma_zeus.c'),'-o',str(OUT/'patch.o')]
    run(compile_args)
    link_args=[LLD,'-T',str(ROOT/'patch/sigma_zeus.ld'),'-Map='+str(OUT/'patch.map'),'-o',str(OUT/'patch.elf'),str(OUT/'patch.o')]
    run(link_args)
    elf_bytes=(OUT/'patch.elf').read_bytes();elf=ELFFile(io.BytesIO(elf_bytes))
    assert elf['e_machine']=='EM_ARM' and elf.little_endian
    symbols={s.name:s['st_value'] for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name}
    unresolved=[s.name for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name and s['st_shndx']=='SHN_UNDEF']
    assert not unresolved,unresolved
    text=elf.get_section_by_name('.text');assert text['sh_addr']==ORIGIN
    for sec in elf.iter_sections():
        if sec['sh_flags']&2 and sec['sh_size']:assert sec.name=='.text',sec.name
    extension=text.data();padding=(-len(extension))%32
    patched=bytearray(original+extension+b'\xff'*padding)
    assert len(patched)<=216800,'Exceeds even the separately observed oldrelease size'
    edits=[]
    for off,old,new,reason in [
      (0x2c8,bytes.fromhex('90550020'),struct.pack('<I',0x20005490),'Reserve final256bytes of declared heap; preserve stackbounds'),
      (0x5102,bytes.fromhex('00f021f8'),thumb_bl(BASE+0x5102,symbols['zeus_construct_hook']),'Preserve originalconstructor thenregister additionalZeusdriver'),
      (0x537c,bytes.fromhex('05f09afa'),thumb_bl(BASE+0x537c,symbols['zeus_merge_hook']),'Preserve originalconsolebuilder thenmerge independentZeuscontrols')]:
        assert patched[off:off+len(old)]==old
        patched[off:off+len(old)]=new
        edits.append({'offset':off,'va':hex(BASE+off),'original_hex':old.hex(),'replacement_hex':new.hex(),'reason':reason})
    allowed={i for x in edits for i in range(x['offset'],x['offset']+len(bytes.fromhex(x['original_hex'])))}
    changed=[i for i in range(len(original)) if patched[i]!=original[i]]
    assert set(changed)<=allowed
    assert patched[len(original)-16:len(original)]==original[-16:]
    baseline=json.loads((SOURCE.with_suffix('.bin.transform.json')).read_text())
    kb=(ROOT/baseline['key_source']).read_bytes();assert sha(kb)==baseline['key_source_sha256']
    for e in baseline['key_instruction_evidence']+baseline['iv_instruction_evidence']:
        off=e['file_offset'];assert kb[off:off+8].hex()==e['instruction_bytes']
    key=bytes(e['value'] for e in baseline['key_instruction_evidence'])
    iv=bytes(e['value'] for e in baseline['iv_instruction_evidence'])
    def ctr(data):return run([OPENSSL,'enc','-aes-256-ctr','-K',key.hex(),'-iv',iv.hex()],input=data)
    original_carrier=(ROOT/baseline['source']).read_bytes()
    assert ctr(original)==original_carrier,'Recovered transform no longer matches original'
    carrier=ctr(patched);assert ctr(carrier)==patched
    assert all(carrier[i]==original_carrier[i] for i in range(len(original)) if i not in allowed)
    names={'plaintext':'NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev1.plaintext.bin',
           'encoded':'NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev1.encoded.bin'}
    artifacts={}
    for kind,data in [('plaintext',patched),('encoded',carrier)]:
        path=OUT/names[kind];path.write_bytes(data)
        artifacts[kind]={'path':str(path.relative_to(ROOT)),'size':len(data),'sha256':sha(data)}
    manifest={'status':'OFFLINE_EXPERIMENTAL_NOT_FOR_FLASHING','installable_verified':False,
      'original':{'path':str(SOURCE.relative_to(ROOT)),'sha256':EXPECTED,'size':len(original)},
      'edits':edits,'changed_original_bytes':len(changed),'original_tail_preserved':True,
      'appended':{'offset':len(original),'va':hex(ORIGIN),'code_and_rodata_length':len(extension),'alignment_padding':padding,'sha256':sha(extension)},
      'ram_reservation':{'start':'0x20005490','size':256,'original_heap_limit':'0x20005590','new_heap_limit':'0x20005490','stack_unchanged':True},
      'artifacts':artifacts,'symbols':{k:hex(v) for k,v in symbols.items() if k.startswith('zeus_')},
      'source_files':{str(p.relative_to(ROOT)):sha(p.read_bytes()) for p in [ROOT/'patch/sigma_zeus.c',ROOT/'patch/zeus_profile.h',ROOT/'patch/sigma_zeus.ld',Path(__file__).resolve()]},
      'encoding':{'algorithm':'AES-256-CTR','counter':'128-bit big-endian, continuous from originaloffset0','key_source_sha256':baseline['key_source_sha256'],
                  'original_roundtrip':True,'candidate_roundtrip':True,'unchanged_plaintext_preserves_original_ciphertext':True},
      'tools':{'clang':run([CLANG,'--version']).decode().splitlines()[0],'lld':run([LLD,'--version']).decode().strip(),'openssl':run([OPENSSL,'version']).decode().strip()},
      'commands':[compile_args,link_args],
      'unresolved':['Bootloader validation/checksum/signature andacceptanceofextendedimage',
                    'Actualflashprogram/erasebounds andhardwarevariant',
                    'Livephysicalcontrolmapping andPS5regressiontesting']}
    (OUT/'build-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({'status':manifest['status'],'extension_bytes':len(extension),'total_bytes':len(patched),'changed_original_bytes':len(changed),'artifacts':artifacts},indent=2))

if __name__=='__main__':main()
