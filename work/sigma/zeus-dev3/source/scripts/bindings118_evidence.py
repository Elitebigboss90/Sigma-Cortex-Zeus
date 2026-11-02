#!/usr/bin/env python3
"""Pin the manually reviewed 1.1.8 USB binding evidence; offline only."""
from pathlib import Path
import hashlib,json,struct
import capstone

ROOT=Path(__file__).resolve().parents[1]
BASE=0x08020000
SOURCE=ROOT/'work/sigma/1.1.8/sigma-decoded.bin'
SHA='6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035'

def identity(p):
    raw=p.read_bytes()
    return {'path':str(p.relative_to(ROOT)),'size':len(raw),'sha256':hashlib.sha256(raw).hexdigest()}

def main():
    raw=SOURCE.read_bytes();assert hashlib.sha256(raw).hexdigest()==SHA
    destination=ROOT/'work/sigma/1.1.8/bindings118'
    md=capstone.Cs(capstone.CS_ARCH_ARM,capstone.CS_MODE_THUMB|capstone.CS_MODE_MCLASS)
    mappings=[
      ('generic_init',0x08023ba0,0x080289ac),('preconfiguration',0x08023494,0x08029c6c),
      ('release',0x08023ec8,0x08028e50),('poll',0x08024a8c,0x08028fb0),
      ('get_address',0x0802406c,0x08028470),('noop',0x08023b84,0x08029c50),
      ('vid_pid_false',0x080235f4,0x08029cb4),('class_false',0x08023b90,0x08029c34),
      ('constant_true',0x08023620,0x08029c5c),('parser_lookup',0x08024078,0x080288b0),
      ('parser_register',0x080240ec,0x08028924),('on_init',0x08024168,0x080289a0),
      ('callback_adapter',0x08024be8,0x08028efc),('poll_enabled',0x08024194,0x08028e7c),
      ('endpoint_wrapper',0x08024c24,0x08028f3c),('endpoint_eligibility',0x08024c84,0x08028f9c),
      ('input_callback',0x08024c98,0x08028ee4),('secondary_thunk',0x08024cb0,0x0802c3e0),
      ('generic_constructor',0x08025188,0x0802910c),('register_class',0x08023af0,0x0802afa4),
      ('usb_in',0x08022490,0x0802a36c),('constructor_chain',0x080250ec,0x08024720)]
    vtable=list(struct.unpack_from('<20I',raw,0x271b0))
    assert vtable[:17]==[new|1 for _,_,new in mappings[:17]]
    assert vtable[17:]==[0xfffffffc,0,0x0802c3e1]
    ranges=[]
    for label,lo,hi in [
        ('runtime_initializer_loop',0x758,0x784),('constructor_chain',0x4720,0x4742),
        ('constructor_thunks',0xc4c0,0xc4f4),('generic_ctor',0x910c,0x9132),
        ('register_class',0xafa4,0xaffa),('release_fields',0x8e50,0x8e7c),
        ('generic_init',0x89ac,0x8cd8),('endpoint_extractor',0x8724,0x88b0),
        ('poll',0x8fb0,0x910a),('secondary_thunk',0xc3e0,0xc426),
        ('type_11_case_32',0x4d6e,0x4d8a),('type_11_call_32',0x4ec4,0x4ed0),
        ('type_11_case_39',0x5290,0x52ae),('type_11_call_39',0x5418,0x5424)]:
        b=raw[lo:hi]
        ranges.append({'label':label,'file_offset':hex(lo),'va':hex(BASE+lo),'length':len(b),
                       'bytes':b.hex(),'sha256':hashlib.sha256(b).hexdigest(),
                       'instructions':[{'va':hex(i.address),'bytes':i.bytes.hex(),
                                        'asm':i.mnemonic+' '+i.op_str} for i in md.disasm(b,BASE+lo)]})
    assert raw[0x473e:0x4742].hex()=='07f0d7be'
    slot=0x2e81c;entry=BASE+slot+struct.unpack_from('<i',raw,slot)[0]
    assert entry==0x08024721
    result={'source':identity(SOURCE),'mapping':'VA = file offset + 08020000; little-endian Thumb Cortex-M',
      'methods':[{'role':role,'old_va':hex(old),'new_va':hex(new),'new_thumb':hex(new|1)} for role,old,new in mappings],
      'generic_vtable':{'va':'0x080471b0','offset':'0x271b0','bytes':raw[0x271b0:0x27200].hex(),'words':[hex(v) for v in vtable]},
      'constructor_hook':{'va':'0x0802473e','file_offset':'0x473e','original_bytes':'07f0d7be',
          'original_instruction':'b.w 0x0802c4f0','preserved_original_thumb':'0x0802c4f1',
          'replacement_kind':'Tail B.W, not BL; incoming LR is already restored by POP at 0802473A'},
      'initializer_table':{'file_offset':hex(slot),'bytes':raw[slot:slot+4].hex(),'operation':'Signed relative word added to its own VA','target_thumb':hex(entry)},
      'host_address':'0x20004488','registry_offset':'0x78','registry_slots':16,'original_registered_objects':6,
      'object_fields':{'host_pointer':'0x08','usb_address':'0x0c','interface_count':'0x30','endpoint_count':'0x31',
                       'deadline':'0x34','interval':'0x38','poll_enabled':'0x39','report_id_flag':'0x6f','pid':'0x70','vid':'0x72'},
      'callback_abi':'void(self, same_self, u8 has_report_ids, u8 bounded_length, raw_buffer_on_stack); raw report ID retained',
      'ranges':ranges,
      'exports':[identity(destination/name) for name in ['usb.c','methods.c','claims.c','base-parsers.c','constructor-emulation.json']],
      'semantic_delta':{'base_report_lengths_unchanged':[32,39],'new_wheel_type':'0x0b','new_handler':'0x0802754c',
                        'interpretation':'New low-six-bit wheel-type dispatch case is consistent with supplied NeoX support notes; physical product assignment remains inferred.'},
      'limits':['Static/emulated application evidence; no bootloader or device effects tested.',
                'No new Zeus predicate in the five existing application class gates; fallback enumeration still requires identity-aware endpoint rejection.',
                'Additional class product identity is not assigned solely from PID; its original constructor and reports must remain intact.']}
    out=destination/'bindings-evidence.json';out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'status':'VERIFIED_STATIC_BINDINGS','mappings':len(mappings),'output':str(out.relative_to(ROOT))}))

if __name__=='__main__':main()
