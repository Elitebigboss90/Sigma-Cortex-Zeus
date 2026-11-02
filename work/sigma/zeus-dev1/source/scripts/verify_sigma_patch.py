#!/usr/bin/env python3
"""Execute the compiled Thumb patch and original Sigma helpers in Unicorn.

This validates finite CPU/RAM behavior, not USB hardware, flash, or bootloader.
Only init/poll/release hardware boundaries are stubbed where explicitly noted.
"""
import hashlib,json,struct
from pathlib import Path
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_THUMB,UC_MODE_MCLASS,UC_HOOK_CODE,UC_HOOK_MEM_WRITE
from unicorn.arm_const import *

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'work/sigma/zeus-dev1'
M=json.loads((OUT/'build-manifest.json').read_text())
IMAGE=(ROOT/M['artifacts']['plaintext']['path']).read_bytes()
assert hashlib.sha256(IMAGE).hexdigest()==M['artifacts']['plaintext']['sha256']
SYM={k:int(v,16) for k,v in M['symbols'].items()}
STATE=0x20005490;HOST=0x20000820;RETURN=0x0807ff00
INITIAL=(ROOT/'work/sigma/patch-design/initial-data.bin').read_bytes()
CHECKS=[]

class Machine:
    def __init__(self,patched=True):
        self.u=Uc(UC_ARCH_ARM,UC_MODE_THUMB|UC_MODE_MCLASS)
        # Explicit ISA test model; this does not identify Sigma's exact MCU.
        self.u.ctl_set_cpu_model(UC_CPU_ARM_CORTEX_M4)
        self.u.mem_map(0x08000000,0x80000)
        self.u.mem_write(0x08020000,IMAGE if patched else (ROOT/'work/sigma/1.1.5/sigma-decoded.bin').read_bytes())
        self.u.mem_map(0x20000000,0x10000)
        self.u.mem_write(0x20000000,INITIAL)
        self.u.mem_map(0xe000e000,0x2000)
        self.stubs={};self.calls=[];self.writes=[]
        self.u.hook_add(UC_HOOK_CODE,self._code)
        # Memory-write instrumentation changes Thumb conditional execution in
        # the installed engine; use post-execution canaries/comparisons instead.
    def _code(self,uc,at,size,unused):
        if at==RETURN:uc.emu_stop()
        elif at in self.stubs:
            self.calls.append(at);result=self.stubs[at](self)
            uc.reg_write(UC_ARM_REG_R0,result)
            uc.reg_write(UC_ARM_REG_PC,uc.reg_read(UC_ARM_REG_LR))
    def _write(self,uc,access,at,size,value,unused):self.writes.append((at,size))
    def read(self,at,n):return bytes(self.u.mem_read(at,n))
    def put(self,at,data):self.u.mem_write(at,bytes(data))
    def word(self,at):return struct.unpack('<I',self.read(at,4))[0]
    def w32(self,at,value):self.put(at,struct.pack('<I',value&0xffffffff))
    def call(self,at,*args,check_abi=True,stop=RETURN):
        if isinstance(at,str):at=SYM[at]
        sp=0x20006560
        self.u.reg_write(UC_ARM_REG_SP,sp)
        for r,value in zip([UC_ARM_REG_R0,UC_ARM_REG_R1,UC_ARM_REG_R2,UC_ARM_REG_R3],list(args)+[0]*4):self.u.reg_write(r,value)
        for i,value in enumerate(args[4:]):self.w32(sp+4*i,value)
        preserved=[UC_ARM_REG_R4,UC_ARM_REG_R5,UC_ARM_REG_R6,UC_ARM_REG_R7,UC_ARM_REG_R8,UC_ARM_REG_R9,UC_ARM_REG_R10,UC_ARM_REG_R11]
        for i,r in enumerate(preserved):self.u.reg_write(r,0x12340000+i)
        self.u.reg_write(UC_ARM_REG_LR,RETURN|1)
        self.u.reg_write(UC_ARM_REG_XPSR,0x01000000)
        self.u.emu_start(at|1,stop,count=200000)
        assert self.u.reg_read(UC_ARM_REG_PC)==stop,hex(self.u.reg_read(UC_ARM_REG_PC))
        assert self.u.reg_read(UC_ARM_REG_SP)==sp,'unbalanced stack'
        if check_abi:
            for i,r in enumerate(preserved):assert self.u.reg_read(r)==0x12340000+i,('clobbered register',r)
        return self.u.reg_read(UC_ARM_REG_R0)
    def identity(self,vid=0x3670,pid=0x0804):self.put(STATE+0x70,struct.pack('<HH',pid,vid))
    def report(self,data,tick=100):
        self.w32(0x2000081c,tick);self.put(0x20007000,data)
        self.call('zeus_input',STATE,STATE,1,len(data),0x20007000)

def check(name):CHECKS.append(name);print('PASS:',name)

# Run the original scatter decompressor as independent validation of the fixture.
sc=Machine();sc.put(0x20000000,bytes(0x7b0))
sc.call(0x080201d4,0x0804e018,0x20000000,0x7b0,check_abi=False)
assert sc.read(0x20000000,0x7b0)==INITIAL
assert sc.u.reg_read(UC_ARM_REG_R0)==0x0804e26a
check('original scatter routine independently reconstructs exact initialized RAM')

old=Machine(False);old.call(0x080250ec)
new=Machine();new.put(STATE-16,b'\xa5'*16);new.put(STATE+156,b'\xb6'*100);new.call(0x080250ec)
assert new.read(HOST+0x78,20)==old.read(HOST+0x78,20)
assert new.word(HOST+0x78+20)==STATE
assert new.word(STATE)==SYM['zeus_vtable']
assert new.word(STATE+4)==SYM['zeus_vtable']+0x4c
assert new.word(STATE+8)==HOST
check('patched original constructor chain preserves five classes and adds Zeus as sixth')

new.call(0x080202ac)
assert new.u.reg_read(UC_ARM_REG_R0)==0x20004590
assert new.u.reg_read(UC_ARM_REG_R1)==0x20006590
assert new.u.reg_read(UC_ARM_REG_R2)==STATE
assert new.u.reg_read(UC_ARM_REG_R3)==0x20005590
check('heap reservation changes limit only and preserves original stack bounds')

new.identity()
for vid,pid,want in [(0x3670,0x0804,1),(0x3670,0x0a04,0),(0x0483,0x0522,0),(0,0,0)]:
    assert new.call('zeus_match',STATE,vid,pid)==want
    new.identity(vid,pid)
    assert new.call('zeus_endpoint',STATE,0,0)==want
new.identity();assert new.call('zeus_endpoint',STATE,1,0)==0
check('VID/PID and interface gate rejects unrelated devices including existing handbrake/base')

# Generic Init's hardware transaction boundary is stubbed. Wrapper executes.
def init_failure(m):m.put(STATE+0x0c,b'\x03');return 0xd1
def release_stub(m):m.put(STATE+0x0c,b'\0');return 0
new.stubs[0x08023ba0]=init_failure;new.stubs[0x08023ec8]=release_stub
assert new.call('zeus_init',STATE,0,1,0)==0xd1
assert new.read(STATE+0x0c,1)==b'\0' and 0x08023ec8 in new.calls
new.put(STATE+0x0c,b'\x04');new.stubs[0x08023ba0]=lambda m:0xd9
new.calls=[];assert new.call('zeus_init',STATE,0,2,0)==0xd9
assert new.read(STATE+0x0c,1)==b'\x04' and 0x08023ec8 not in new.calls
check('failed first initialization releases allocated address; busy existing binding is preserved')

# Compare unchanged original builder output with inactive patch using original code.
new.put(0x20004578,b'\x08');new.put(0x20004580,b'\0')
new.call(0x0802a8b4);baseline=new.read(0x20000c88,64)
new.call('zeus_merge_hook');assert new.read(0x20000c88,64)==baseline
check('without Zeus controls, original console report remains byte identical')

# Verify all120 on-wire usagebits, mapping and unchanged unrelated console fields.
mapping=[1,2,3,4,13,14,5,6,7,8,9,10,11,12]
for usage in range(1,121):
    frame=b'\x01\0\0'+(1<<(usage-1)).to_bytes(15,'little')+bytes(5)
    new.report(frame)
    new.call('zeus_merge_hook');actual=new.read(0x20000c88,64)
    expected=bytearray(baseline)
    if usage in mapping:
        bit=4+mapping.index(usage);expected[5+bit//8]|=1<<(bit%8)
    assert actual==expected,(usage,actual.hex(),expected.hex())
check('120 single-bit input cases map only declared controls and preserve other report fields')

frame=b'\x01\x7f\x40'+bytes(20)
new.report(frame);new.call('zeus_merge_hook')
assert new.read(0x20000c88+8,2)==bytes([255,129])
state=new.read(STATE+0x78,40)
for bad in [b'',b'\x01'+bytes(21),b'\x01'+bytes(23),b'\x02'+bytes(22),b'\xf9'+bytes(63)]:
    new.report(bad)
    assert new.read(STATE+0x84,24)==state[12:36]
check('axes scale at boundaries; invalid lengths and management report IDs do not alter controls')

# Exercise the real generic poll, its vtable dispatch and fifth stack argument.
# Only the low-level USB IN transaction is supplied by the capture fixture.
poll_frame=b'\x01\0\0'+(1<<12).to_bytes(15,'little')+bytes(5)
def usb_in(m):
    length_ptr=m.u.reg_read(UC_ARM_REG_R3)
    buffer=m.word(m.u.reg_read(UC_ARM_REG_SP))
    m.put(length_ptr,struct.pack('<H',len(poll_frame)));m.put(buffer,poll_frame)
    return 0
new.stubs[0x08022490]=usb_in
new.put(STATE+0x30,b'\x01');new.put(STATE+0x38,b'\x01\x01')
new.put(STATE+0x5d,b'\x01');new.put(STATE+0x3d,b'\x01\x40\0')
new.w32(STATE+0x34,0);new.w32(0x2000081c,500)
before=new.word(STATE+0x7c)
assert new.call('zeus_poll',STATE)==0
assert new.word(STATE+0x7c)==before+1 and new.read(STATE+0x84,23)==poll_frame
check('original generic poll delivers USB buffer through new vtable and actual fifth-argument ABI')

# Poll boundary is stubbed: verify timeout arithmetic and request for release report.
new.stubs[0x08024a8c]=lambda m:0
new.report(b'\x01\0\0'+(1<<12).to_bytes(15,'little')+bytes(5),tick=0xfffffff0)
new.put(0x20000000,b'\0');new.w32(0x2000081c,0xea)
new.call('zeus_poll',STATE);assert new.read(STATE+0x9b,1)==b'\x01'
new.w32(0x2000081c,0xeb);new.call('zeus_poll',STATE)
assert new.read(STATE+0x9b,1)==b'\0' and new.read(0x20000000,1)==b'\x01'
new.call('zeus_merge_hook');assert new.read(0x20000c88,64)==baseline
check('timeout remains correct across counter wrap and sends button releases')

new.report(b'\x01\0\0'+(1<<13).to_bytes(15,'little')+bytes(5));new.put(0x20000000,b'\0')
new.call('zeus_release',STATE)
assert new.read(STATE+0x9b,1)==b'\0' and new.read(0x20000000,1)==b'\x01'
new.call('zeus_merge_hook');assert new.read(0x20000c88,64)==baseline
check('detach clears independent controls and requests a fresh original report')

# Verify actual original callsite reaches patched builder and returns to original code.
new.call(0x0802537c,stop=0x08025380)
check('patched BL instruction reaches appended merge code')
assert new.read(STATE-16,16)==b'\xa5'*16 and new.read(STATE+156,100)==b'\xb6'*100
check('state boundary canaries remain intact across constructor and all callback cases')

result={'status':'PASS','image_sha256':hashlib.sha256(IMAGE).hexdigest(),'checks':CHECKS,
  'emulation':'Unicorn ARM Thumb M-class Cortex-M4 instruction model; not identification of actual MCU; actual compiled patch and selected original helpers',
  'stubs':['Original USB Init transaction boundary 08023BA0 for wrapper tests',
           'Original USB Release08023EC8 for wrapper tests','Original USB Poll08024A8C for timeout tests',
           'Low-level USB IN08022490 for real generic-poll callback integration'],
  'limitations':['No bootloader orflashvalidation','No emulatedUSBcontroller orPS5','No proof of all targettiming/interleavings','Physicalusage map remainscapturedependent']}
(OUT/'emulator-verification.json').write_text(json.dumps(result,indent=2)+'\n')
print('All offline checks passed; this does not make the candidate flashable.')
