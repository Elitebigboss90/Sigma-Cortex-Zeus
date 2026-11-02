from pathlib import Path
import hashlib,json,struct
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_THUMB,UC_MODE_MCLASS
from unicorn.arm_const import *
root=Path(__file__).resolve().parents[1]; b=(root/'work/sigma/1.1.8/sigma-decoded.bin').read_bytes(); init=(root/'work/sigma/1.1.8/memory/initial-data.bin').read_bytes()
assert hashlib.sha256(b).hexdigest()=='6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035'
assert hashlib.sha256(init).hexdigest()=='56df6503e19c10d9687591be7124de7c849f2a33b2c8cdc4225988b3d40c0ce9'
u=Uc(UC_ARCH_ARM,UC_MODE_THUMB|UC_MODE_MCLASS);u.ctl_set_cpu_model(UC_CPU_ARM_CORTEX_M4)
u.mem_map(0x08000000,0x80000);u.mem_write(0x08020000,b);u.mem_map(0x20000000,0x10000);u.mem_write(0x20000000,init);u.mem_map(0xe000e000,0x2000)
def call(a,*args):
 u.reg_write(UC_ARM_REG_SP,0x20006620);u.reg_write(UC_ARM_REG_LR,0x0807ff01);u.reg_write(UC_ARM_REG_XPSR,1<<24)
 for reg,arg in zip([UC_ARM_REG_R0,UC_ARM_REG_R1,UC_ARM_REG_R2,UC_ARM_REG_R3],list(args)+[0]*4):u.reg_write(reg,arg)
 u.emu_start(a|1,0x0807ff00,count=200000)
 assert u.reg_read(UC_ARM_REG_PC)==0x0807ff00 and u.reg_read(UC_ARM_REG_SP)==0x20006620
 return u.reg_read(UC_ARM_REG_R0)
def words(a,n):return struct.unpack('<'+str(n)+'I',u.mem_read(a,n*4))
call(0x08024720);before=words(0x20004488+0x78,16)
assert before[:6]==(0x20002734,0x200008e8,0x20003ab0,0x200025c0,0x2000267c,0x20004128) and not any(before[6:]),before
ret=call(0x0802910c,0x20005550,0x20004488);after=words(0x20004488+0x78,16)
assert ret==0x20005550 and after[:6]==before[:6] and after[6]==0x20005550 and not any(after[7:])
assert words(0x20005550,3)==(0x080471b0,0x080471fc,0x20004488)
checks=[]
for address,obj,pairs in [(0x080249a4,0x20003ab0,[(0x483,0x525),(0x3670,0x903),(0x483,0x524)]),(0x080281c0,0x200008e8,[(0x483,0x522)]),(0x080292a4,0x2000267c,[(0x483,0x531)]),(0x080294dc,0x20004128,[(0x483,0x526),(0x483,0x525),(0x3670,0xa06)]),(0x08029b44,0x200025c0,[(0x483,0x530),(0x3670,0xa04)])]:
 assert call(address,obj,0x3670,0x0804)==0
 for vid,pid in pairs:assert call(address,obj,vid,pid)==1
 checks.append({'predicate':hex(address),'object':hex(obj),'accepted_pairs':[[hex(vid),hex(pid)] for vid,pid in pairs],'zeus_3670_0804_rejected':True})
r={'status':'PASS','source_sha256':hashlib.sha256(b).hexdigest(),'initial_data_sha256':hashlib.sha256(init).hexdigest(),'registry_before':[hex(x) for x in before],'registry_after_generic_constructor':[hex(x) for x in after],'generic_constructor_return':hex(ret),'generic_object_prefix':[hex(x) for x in words(0x20005550,3)],'predicates':checks,'hardware_stubs':[],'hardware_access':False,'limits':'Finite original CPU/RAM execution; not real USB enumeration or fallback behavior.'}
p=root/'work/sigma/1.1.8/bindings118/constructor-emulation.json';p.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
