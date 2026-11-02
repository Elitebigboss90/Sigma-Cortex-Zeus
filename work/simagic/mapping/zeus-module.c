// FUNCTION 180001cd0

undefined8 dev_create_device_parts(undefined8 param_1,void *param_2)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  __uint64 _Var4;
  void *pvVar5;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
                    /* 0x1cd0  1  dev_create_device_parts */
  memset(param_2,0,8);
  *(undefined4 *)((longlong)param_2 + 0x20) = 6;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = (longlong)*(int *)((longlong)param_2 + 0x20);
  _Var4 = SUB168(ZEXT816(0x10) * auVar1,0);
  if (SUB168(ZEXT816(0x10) * auVar1,8) != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  pvVar5 = operator_new(_Var4);
  *(void **)((longlong)param_2 + 0x28) = pvVar5;
  for (local_3c = 1; local_3c < *(int *)((longlong)param_2 + 0x20) + 1; local_3c = local_3c + 1) {
    *(int *)(*(longlong *)((longlong)param_2 + 0x28) + -0x10 + (longlong)local_3c * 0x10) = local_3c
    ;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 0x28) + -0xc + (longlong)local_3c * 0x10) = 2;
  }
  *(undefined4 *)((longlong)param_2 + 0x30) = 0x10;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = (longlong)*(int *)((longlong)param_2 + 0x30);
  _Var4 = SUB168(ZEXT816(0x28) * auVar2,0);
  if (SUB168(ZEXT816(0x28) * auVar2,8) != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  pvVar5 = operator_new(_Var4);
  *(void **)((longlong)param_2 + 0x38) = pvVar5;
  for (local_40 = 1; local_40 < *(int *)((longlong)param_2 + 0x30) + 1; local_40 = local_40 + 1) {
    *(int *)(*(longlong *)((longlong)param_2 + 0x38) + -0x28 + (longlong)local_40 * 0x28) = local_40
    ;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 0x38) + -0x24 + (longlong)local_40 * 0x28) = 3
    ;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 0x38) + -0x18 + (longlong)local_40 * 0x28) = 1
    ;
    *(int *)(*(longlong *)((longlong)param_2 + 0x38) + -0x20 + (longlong)local_40 * 0x28) = local_40
    ;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 0x38) + -0x1c + (longlong)local_40 * 0x28) = 3
    ;
  }
  *(undefined4 *)((longlong)param_2 + 0xc0) = 4;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = (longlong)*(int *)((longlong)param_2 + 0xc0);
  _Var4 = SUB168(ZEXT816(0x148) * auVar3,0);
  if (SUB168(ZEXT816(0x148) * auVar3,8) != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  pvVar5 = operator_new(_Var4);
  *(void **)((longlong)param_2 + 200) = pvVar5;
  for (local_48 = 1; local_48 <= *(int *)((longlong)param_2 + 0xc0); local_48 = local_48 + 1) {
    *(int *)(*(longlong *)((longlong)param_2 + 200) + -0x148 + (longlong)local_48 * 0x148) =
         local_48;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 200) + -0x144 + (longlong)local_48 * 0x148) =
         10;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 200) + -0x140 + (longlong)local_48 * 0x148) =
         0xc;
    *(undefined4 *)(*(longlong *)((longlong)param_2 + 200) + -300 + (longlong)local_48 * 0x148) =
         0xc;
    for (local_44 = 0; local_44 < 0xc; local_44 = local_44 + 1) {
      *(int *)((longlong)local_48 * 0x148 + *(longlong *)((longlong)param_2 + 200) + -0x128 +
              (longlong)local_44 * 0x10) = local_44 + 1;
      *(undefined4 *)
       ((longlong)local_48 * 0x148 + *(longlong *)((longlong)param_2 + 200) + -0x124 +
       (longlong)local_44 * 0x10) = 0x10;
      *(undefined4 *)
       ((longlong)local_48 * 0x148 + *(longlong *)((longlong)param_2 + 200) + -0x120 +
       (longlong)local_44 * 0x10) = 0;
      if (local_48 == 1) {
        *(int *)(*(longlong *)((longlong)param_2 + 200) + 0x2c + (longlong)local_44 * 0x10) =
             local_44 + 0x43;
      }
      else if (local_48 == 2) {
        *(int *)(*(longlong *)((longlong)param_2 + 200) + 0x174 + (longlong)local_44 * 0x10) =
             local_44 + 0x5b;
      }
      else if (local_48 == 3) {
        *(int *)(*(longlong *)((longlong)param_2 + 200) + 700 + (longlong)local_44 * 0x10) =
             local_44 + 0x67;
      }
      else if (local_48 == 4) {
        *(int *)(*(longlong *)((longlong)param_2 + 200) + 0x404 + (longlong)local_44 * 0x10) =
             local_44 + 0x4f;
      }
    }
  }
  return 0;
}


// 180001cd0 MOV qword ptr [RSP + 0x10],RDX
// 180001cd5 MOV qword ptr [RSP + 0x8],RCX
// 180001cda SUB RSP,0x68
// 180001cde MOV R8D,0x8
// 180001ce4 XOR EDX,EDX
// 180001ce6 MOV RCX,qword ptr [RSP + 0x78]
// 180001ceb CALL 0x180004eac
// 180001cf0 MOV RAX,qword ptr [RSP + 0x78]
// 180001cf5 MOV dword ptr [RAX + 0x20],0x6
// 180001cfc MOV RAX,qword ptr [RSP + 0x78]
// 180001d01 MOVSXD RAX,dword ptr [RAX + 0x20]
// 180001d05 MOV qword ptr [RSP + 0x30],RAX
// 180001d0a MOV EAX,0x10
// 180001d0f MOV RCX,qword ptr [RSP + 0x30]
// 180001d14 MUL RCX
// 180001d17 MOV RCX,-0x1
// 180001d1e CMOVC RAX,RCX
// 180001d22 MOV RCX,RAX
// 180001d25 CALL 0x180003f34
// 180001d2a MOV qword ptr [RSP + 0x38],RAX
// 180001d2f MOV RAX,qword ptr [RSP + 0x78]
// 180001d34 MOV RCX,qword ptr [RSP + 0x38]
// 180001d39 MOV qword ptr [RAX + 0x28],RCX
// 180001d3d MOV dword ptr [RSP + 0x2c],0x1
// 180001d45 JMP 0x180001d51
// 180001d47 MOV EAX,dword ptr [RSP + 0x2c]
// 180001d4b INC EAX
// 180001d4d MOV dword ptr [RSP + 0x2c],EAX
// 180001d51 MOV RAX,qword ptr [RSP + 0x78]
// 180001d56 MOV EAX,dword ptr [RAX + 0x20]
// 180001d59 INC EAX
// 180001d5b CMP dword ptr [RSP + 0x2c],EAX
// 180001d5f JGE 0x180001d97
// 180001d61 MOVSXD RAX,dword ptr [RSP + 0x2c]
// 180001d66 IMUL RAX,RAX,0x10
// 180001d6a MOV RCX,qword ptr [RSP + 0x78]
// 180001d6f MOV RCX,qword ptr [RCX + 0x28]
// 180001d73 MOV EDX,dword ptr [RSP + 0x2c]
// 180001d77 MOV dword ptr [RCX + RAX*0x1 + -0x10],EDX
// 180001d7b MOVSXD RAX,dword ptr [RSP + 0x2c]
// 180001d80 IMUL RAX,RAX,0x10
// 180001d84 MOV RCX,qword ptr [RSP + 0x78]
// 180001d89 MOV RCX,qword ptr [RCX + 0x28]
// 180001d8d MOV dword ptr [RCX + RAX*0x1 + -0xc],0x2
// 180001d95 JMP 0x180001d47
// 180001d97 MOV RAX,qword ptr [RSP + 0x78]
// 180001d9c MOV dword ptr [RAX + 0x30],0x10
// 180001da3 MOV RAX,qword ptr [RSP + 0x78]
// 180001da8 MOVSXD RAX,dword ptr [RAX + 0x30]
// 180001dac MOV qword ptr [RSP + 0x40],RAX
// 180001db1 MOV EAX,0x28
// 180001db6 MOV RCX,qword ptr [RSP + 0x40]
// 180001dbb MUL RCX
// 180001dbe MOV RCX,-0x1
// 180001dc5 CMOVC RAX,RCX
// 180001dc9 MOV RCX,RAX
// 180001dcc CALL 0x180003f34
// 180001dd1 MOV qword ptr [RSP + 0x48],RAX
// 180001dd6 MOV RAX,qword ptr [RSP + 0x78]
// 180001ddb MOV RCX,qword ptr [RSP + 0x48]
// 180001de0 MOV qword ptr [RAX + 0x38],RCX
// 180001de4 MOV dword ptr [RSP + 0x28],0x1
// 180001dec JMP 0x180001df8
// 180001dee MOV EAX,dword ptr [RSP + 0x28]
// 180001df2 INC EAX
// 180001df4 MOV dword ptr [RSP + 0x28],EAX
// 180001df8 MOV RAX,qword ptr [RSP + 0x78]
// 180001dfd MOV EAX,dword ptr [RAX + 0x30]
// 180001e00 INC EAX
// 180001e02 CMP dword ptr [RSP + 0x28],EAX
// 180001e06 JGE 0x180001e93
// 180001e0c MOVSXD RAX,dword ptr [RSP + 0x28]
// 180001e11 IMUL RAX,RAX,0x28
// 180001e15 MOV RCX,qword ptr [RSP + 0x78]
// 180001e1a MOV RCX,qword ptr [RCX + 0x38]
// 180001e1e MOV EDX,dword ptr [RSP + 0x28]
// 180001e22 MOV dword ptr [RCX + RAX*0x1 + -0x28],EDX
// 180001e26 MOVSXD RAX,dword ptr [RSP + 0x28]
// 180001e2b IMUL RAX,RAX,0x28
// 180001e2f MOV RCX,qword ptr [RSP + 0x78]
// 180001e34 MOV RCX,qword ptr [RCX + 0x38]
// 180001e38 MOV dword ptr [RCX + RAX*0x1 + -0x24],0x3
// 180001e40 MOVSXD RAX,dword ptr [RSP + 0x28]
// 180001e45 IMUL RAX,RAX,0x28
// 180001e49 MOV RCX,qword ptr [RSP + 0x78]
// 180001e4e MOV RCX,qword ptr [RCX + 0x38]
// 180001e52 MOV dword ptr [RCX + RAX*0x1 + -0x18],0x1
// 180001e5a MOVSXD RAX,dword ptr [RSP + 0x28]
// 180001e5f IMUL RAX,RAX,0x28
// 180001e63 MOV RCX,qword ptr [RSP + 0x78]
// 180001e68 MOV RCX,qword ptr [RCX + 0x38]
// 180001e6c MOV EDX,dword ptr [RSP + 0x28]
// 180001e70 MOV dword ptr [RCX + RAX*0x1 + -0x20],EDX
// 180001e74 MOVSXD RAX,dword ptr [RSP + 0x28]
// 180001e79 IMUL RAX,RAX,0x28
// 180001e7d MOV RCX,qword ptr [RSP + 0x78]
// 180001e82 MOV RCX,qword ptr [RCX + 0x38]
// 180001e86 MOV dword ptr [RCX + RAX*0x1 + -0x1c],0x3
// 180001e8e JMP 0x180001dee
// 180001e93 MOV RAX,qword ptr [RSP + 0x78]
// 180001e98 MOV dword ptr [RAX + 0xc0],0x4
// 180001ea2 MOV RAX,qword ptr [RSP + 0x78]
// 180001ea7 MOVSXD RAX,dword ptr [RAX + 0xc0]
// 180001eae MOV qword ptr [RSP + 0x50],RAX
// 180001eb3 MOV EAX,0x148
// 180001eb8 MOV RCX,qword ptr [RSP + 0x50]
// 180001ebd MUL RCX
// 180001ec0 MOV RCX,-0x1
// 180001ec7 CMOVC RAX,RCX
// 180001ecb MOV RCX,RAX
// 180001ece CALL 0x180003f34
// 180001ed3 MOV qword ptr [RSP + 0x58],RAX
// 180001ed8 MOV RAX,qword ptr [RSP + 0x78]
// 180001edd MOV RCX,qword ptr [RSP + 0x58]
// 180001ee2 MOV qword ptr [RAX + 0xc8],RCX
// 180001ee9 MOV dword ptr [RSP + 0x20],0x1
// 180001ef1 JMP 0x180001efd
// 180001ef3 MOV EAX,dword ptr [RSP + 0x20]
// 180001ef7 INC EAX
// 180001ef9 MOV dword ptr [RSP + 0x20],EAX
// 180001efd MOV RAX,qword ptr [RSP + 0x78]
// 180001f02 MOV EAX,dword ptr [RAX + 0xc0]
// 180001f08 CMP dword ptr [RSP + 0x20],EAX
// 180001f0c JG 0x18000212e
// 180001f12 MOVSXD RAX,dword ptr [RSP + 0x20]
// 180001f17 IMUL RAX,RAX,0x148
// 180001f1e MOV RCX,qword ptr [RSP + 0x78]
// 180001f23 MOV RCX,qword ptr [RCX + 0xc8]
// 180001f2a MOV EDX,dword ptr [RSP + 0x20]
// 180001f2e MOV dword ptr [RCX + RAX*0x1 + -0x148],EDX
// 180001f35 MOVSXD RAX,dword ptr [RSP + 0x20]
// 180001f3a IMUL RAX,RAX,0x148
// 180001f41 MOV RCX,qword ptr [RSP + 0x78]
// 180001f46 MOV RCX,qword ptr [RCX + 0xc8]
// 180001f4d MOV dword ptr [RCX + RAX*0x1 + -0x144],0xa
// 180001f58 MOVSXD RAX,dword ptr [RSP + 0x20]
// 180001f5d IMUL RAX,RAX,0x148
// 180001f64 MOV RCX,qword ptr [RSP + 0x78]
// 180001f69 MOV RCX,qword ptr [RCX + 0xc8]
// 180001f70 MOV dword ptr [RCX + RAX*0x1 + -0x140],0xc
// 180001f7b MOVSXD RAX,dword ptr [RSP + 0x20]
// 180001f80 IMUL RAX,RAX,0x148
// 180001f87 MOV RCX,qword ptr [RSP + 0x78]
// 180001f8c MOV RCX,qword ptr [RCX + 0xc8]
// 180001f93 MOV dword ptr [RCX + RAX*0x1 + -0x12c],0xc
// 180001f9e MOV dword ptr [RSP + 0x24],0x0
// 180001fa6 JMP 0x180001fb2
// 180001fa8 MOV EAX,dword ptr [RSP + 0x24]
// 180001fac INC EAX
// 180001fae MOV dword ptr [RSP + 0x24],EAX
// 180001fb2 CMP dword ptr [RSP + 0x24],0xc
// 180001fb7 JGE 0x180002129
// 180001fbd MOV EAX,dword ptr [RSP + 0x24]
// 180001fc1 INC EAX
// 180001fc3 MOVSXD RCX,dword ptr [RSP + 0x20]
// 180001fc8 IMUL RCX,RCX,0x148
// 180001fcf MOV RDX,qword ptr [RSP + 0x78]
// 180001fd4 ADD RCX,qword ptr [RDX + 0xc8]
// 180001fdb MOVSXD RDX,dword ptr [RSP + 0x24]
// 180001fe0 IMUL RDX,RDX,0x10
// 180001fe4 MOV dword ptr [RCX + RDX*0x1 + -0x128],EAX
// 180001feb MOVSXD RAX,dword ptr [RSP + 0x20]
// 180001ff0 IMUL RAX,RAX,0x148
// 180001ff7 MOV RCX,qword ptr [RSP + 0x78]
// 180001ffc ADD RAX,qword ptr [RCX + 0xc8]
// 180002003 MOVSXD RCX,dword ptr [RSP + 0x24]
// 180002008 IMUL RCX,RCX,0x10
// 18000200c MOV dword ptr [RAX + RCX*0x1 + -0x124],0x10
// 180002017 MOVSXD RAX,dword ptr [RSP + 0x20]
// 18000201c IMUL RAX,RAX,0x148
// 180002023 MOV RCX,qword ptr [RSP + 0x78]
// 180002028 ADD RAX,qword ptr [RCX + 0xc8]
// 18000202f MOVSXD RCX,dword ptr [RSP + 0x24]
// 180002034 IMUL RCX,RCX,0x10
// 180002038 MOV dword ptr [RAX + RCX*0x1 + -0x120],0x0
// 180002043 CMP dword ptr [RSP + 0x20],0x1
// 180002048 JNZ 0x18000207e
// 18000204a MOV EAX,dword ptr [RSP + 0x24]
// 18000204e ADD EAX,0x43
// 180002051 MOVSXD RCX,dword ptr [RSP + 0x20]
// 180002056 IMUL RCX,RCX,0x148
// 18000205d MOV RDX,qword ptr [RSP + 0x78]
// 180002062 ADD RCX,qword ptr [RDX + 0xc8]
// 180002069 MOVSXD RDX,dword ptr [RSP + 0x24]
// 18000206e IMUL RDX,RDX,0x10
// 180002072 MOV dword ptr [RCX + RDX*0x1 + -0x11c],EAX
// 180002079 JMP 0x180002124
// 18000207e CMP dword ptr [RSP + 0x20],0x2
// 180002083 JNZ 0x1800020b6
// 180002085 MOV EAX,dword ptr [RSP + 0x24]
// 180002089 ADD EAX,0x5b
// 18000208c MOVSXD RCX,dword ptr [RSP + 0x20]
// 180002091 IMUL RCX,RCX,0x148
// 180002098 MOV RDX,qword ptr [RSP + 0x78]
// 18000209d ADD RCX,qword ptr [RDX + 0xc8]
// 1800020a4 MOVSXD RDX,dword ptr [RSP + 0x24]
// 1800020a9 IMUL RDX,RDX,0x10
// 1800020ad MOV dword ptr [RCX + RDX*0x1 + -0x11c],EAX
// 1800020b4 JMP 0x180002124
// 1800020b6 CMP dword ptr [RSP + 0x20],0x3
// 1800020bb JNZ 0x1800020ee
// 1800020bd MOV EAX,dword ptr [RSP + 0x24]
// 1800020c1 ADD EAX,0x67
// 1800020c4 MOVSXD RCX,dword ptr [RSP + 0x20]
// 1800020c9 IMUL RCX,RCX,0x148
// 1800020d0 MOV RDX,qword ptr [RSP + 0x78]
// 1800020d5 ADD RCX,qword ptr [RDX + 0xc8]
// 1800020dc MOVSXD RDX,dword ptr [RSP + 0x24]
// 1800020e1 IMUL RDX,RDX,0x10
// 1800020e5 MOV dword ptr [RCX + RDX*0x1 + -0x11c],EAX
// 1800020ec JMP 0x180002124
// 1800020ee CMP dword ptr [RSP + 0x20],0x4
// 1800020f3 JNZ 0x180002124
// 1800020f5 MOV EAX,dword ptr [RSP + 0x24]
// 1800020f9 ADD EAX,0x4f
// 1800020fc MOVSXD RCX,dword ptr [RSP + 0x20]
// 180002101 IMUL RCX,RCX,0x148
// 180002108 MOV RDX,qword ptr [RSP + 0x78]
// 18000210d ADD RCX,qword ptr [RDX + 0xc8]
// 180002114 MOVSXD RDX,dword ptr [RSP + 0x24]
// 180002119 IMUL RDX,RDX,0x10
// 18000211d MOV dword ptr [RCX + RDX*0x1 + -0x11c],EAX
// 180002124 JMP 0x180001fa8
// 180002129 JMP 0x180001ef3
// 18000212e XOR EAX,EAX
// 180002130 ADD RSP,0x68
// 180002134 RET
// FUNCTION 180001930

undefined8 dev_get_next_config(undefined8 param_1,longlong param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  
                    /* 0x1930  7  dev_get_next_config */
  param_3[1] = *(undefined1 *)(param_2 + 1);
  *param_3 = 1;
  *(undefined4 *)(param_3 + 0x10) = 1;
  *(undefined8 *)(param_3 + 0x18) = 1;
  *(undefined4 *)(param_3 + 0x24) = 2;
  *(undefined4 *)(param_3 + 0x20) = 500;
  if ((*(ulonglong *)(param_2 + 0x28) & 0x1000) == 0) {
    *(undefined8 *)(param_3 + 0x18) = 0x1000;
    DAT_180008000 = DAT_180008000 + -1;
    *(int *)(param_3 + 0x24) = DAT_180008000;
    if (*(int *)(param_3 + 0x24) == 0) {
      DAT_180008000 = 4;
    }
    uVar1 = 0;
  }
  else if ((*(ulonglong *)(param_2 + 0x28) & 0x800) == 0) {
    *(undefined8 *)(param_3 + 0x18) = 0x800;
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// 180001930 MOV qword ptr [RSP + 0x18],R8
// 180001935 MOV qword ptr [RSP + 0x10],RDX
// 18000193a MOV qword ptr [RSP + 0x8],RCX
// 18000193f MOV RAX,qword ptr [RSP + 0x18]
// 180001944 MOV RCX,qword ptr [RSP + 0x10]
// 180001949 MOVZX ECX,byte ptr [RCX + 0x1]
// 18000194d MOV byte ptr [RAX + 0x1],CL
// 180001950 MOV RAX,qword ptr [RSP + 0x18]
// 180001955 MOV byte ptr [RAX],0x1
// 180001958 MOV RAX,qword ptr [RSP + 0x18]
// 18000195d MOV dword ptr [RAX + 0x10],0x1
// 180001964 MOV RAX,qword ptr [RSP + 0x18]
// 180001969 MOV qword ptr [RAX + 0x18],0x1
// 180001971 MOV RAX,qword ptr [RSP + 0x18]
// 180001976 MOV dword ptr [RAX + 0x24],0x2
// 18000197d MOV RAX,qword ptr [RSP + 0x18]
// 180001982 MOV dword ptr [RAX + 0x20],0x1f4
// 180001989 MOV RAX,qword ptr [RSP + 0x10]
// 18000198e MOV RAX,qword ptr [RAX + 0x28]
// 180001992 AND RAX,0x1000
// 180001998 TEST RAX,RAX
// 18000199b JNZ 0x1800019df
// 18000199d MOV RAX,qword ptr [RSP + 0x18]
// 1800019a2 MOV qword ptr [RAX + 0x18],0x1000
// 1800019aa MOV EAX,dword ptr [0x180008000]
// 1800019b0 DEC EAX
// 1800019b2 MOV dword ptr [0x180008000],EAX
// 1800019b8 MOV RAX,qword ptr [RSP + 0x18]
// 1800019bd MOV ECX,dword ptr [0x180008000]
// 1800019c3 MOV dword ptr [RAX + 0x24],ECX
// 1800019c6 MOV RAX,qword ptr [RSP + 0x18]
// 1800019cb CMP dword ptr [RAX + 0x24],0x0
// 1800019cf JNZ 0x1800019db
// 1800019d1 MOV dword ptr [0x180008000],0x4
// 1800019db XOR EAX,EAX
// 1800019dd JMP 0x180001a09
// 1800019df MOV RAX,qword ptr [RSP + 0x10]
// 1800019e4 MOV RAX,qword ptr [RAX + 0x28]
// 1800019e8 AND RAX,0x800
// 1800019ee TEST RAX,RAX
// 1800019f1 JNZ 0x180001a04
// 1800019f3 MOV RAX,qword ptr [RSP + 0x18]
// 1800019f8 MOV qword ptr [RAX + 0x18],0x800
// 180001a00 XOR EAX,EAX
// 180001a02 JMP 0x180001a09
// 180001a04 MOV EAX,0x1
// 180001a09 RET
// FUNCTION 180001a10

undefined8 dev_get_next_preset(undefined8 param_1,longlong param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  
                    /* 0x1a10  8  dev_get_next_preset */
  param_3[1] = *(undefined1 *)(param_2 + 1);
  *param_3 = 1;
  *(undefined4 *)(param_3 + 0x10) = 1;
  *(undefined8 *)(param_3 + 0x18) = 1;
  *(undefined4 *)(param_3 + 0x24) = 2;
  *(undefined4 *)(param_3 + 0x20) = 500;
  if ((*(ulonglong *)(param_2 + 0x28) & 0x200000) == 0) {
    if ((*(ulonglong *)(param_2 + 0x28) & 0x400000) == 0) {
      if ((*(ulonglong *)(param_2 + 0x28) & 0x800000) == 0) {
        if ((*(ulonglong *)(param_2 + 0x28) & 0x40) == 0) {
          if ((*(ulonglong *)(param_2 + 0x28) & 0x1000000) == 0) {
            if ((*(ulonglong *)(param_2 + 0x28) & 4) == 0) {
              if ((*(ulonglong *)(param_2 + 0x28) & 0x2000) == 0) {
                if ((*(ulonglong *)(param_2 + 0x28) & 0x80) == 0) {
                  if ((*(ulonglong *)(param_2 + 0x28) & 0x100) == 0) {
                    if ((*(ulonglong *)(param_2 + 0x28) & 0x100000) == 0) {
                      if ((*(ulonglong *)(param_2 + 0x28) & 0x10) == 0) {
                        if ((*(ulonglong *)(param_2 + 0x28) & 0x40000000) == 0) {
                          if ((*(ulonglong *)(param_2 + 0x28) & 0x8000000) == 0) {
                            if ((*(ulonglong *)(param_2 + 0x28) & 0x10000000) == 0) {
                              uVar1 = 1;
                            }
                            else {
                              *(undefined8 *)(param_3 + 0x18) = 0x10000000;
                              uVar1 = 0;
                            }
                          }
                          else {
                            *(undefined8 *)(param_3 + 0x18) = 0x8000000;
                            uVar1 = 0;
                          }
                        }
                        else {
                          *(undefined8 *)(param_3 + 0x18) = 0x40000000;
                          uVar1 = 0;
                        }
                      }
                      else {
                        *(undefined8 *)(param_3 + 0x18) = 0x10;
                        uVar1 = 0;
                      }
                    }
                    else {
                      *(undefined8 *)(param_3 + 0x18) = 0x100000;
                      uVar1 = 0;
                    }
                  }
                  else {
                    *(undefined8 *)(param_3 + 0x18) = 0x100;
                    uVar1 = 0;
                  }
                }
                else {
                  *(undefined8 *)(param_3 + 0x18) = 0x80;
                  uVar1 = 0;
                }
              }
              else {
                *(undefined8 *)(param_3 + 0x18) = 0x2000;
                uVar1 = 0;
              }
            }
            else {
              *(undefined8 *)(param_3 + 0x18) = 4;
              uVar1 = 0;
            }
          }
          else {
            *(undefined8 *)(param_3 + 0x18) = 0x1000000;
            uVar1 = 0;
          }
        }
        else {
          *(undefined8 *)(param_3 + 0x18) = 0x40;
          uVar1 = 0;
        }
      }
      else {
        *(undefined8 *)(param_3 + 0x18) = 0x800000;
        uVar1 = 0;
      }
    }
    else {
      *(undefined8 *)(param_3 + 0x18) = 0x400000;
      uVar1 = 0;
    }
  }
  else {
    *(undefined8 *)(param_3 + 0x18) = 0x200000;
    uVar1 = 0;
  }
  return uVar1;
}


// 180001a10 MOV qword ptr [RSP + 0x18],R8
// 180001a15 MOV qword ptr [RSP + 0x10],RDX
// 180001a1a MOV qword ptr [RSP + 0x8],RCX
// 180001a1f MOV RAX,qword ptr [RSP + 0x18]
// 180001a24 MOV RCX,qword ptr [RSP + 0x10]
// 180001a29 MOVZX ECX,byte ptr [RCX + 0x1]
// 180001a2d MOV byte ptr [RAX + 0x1],CL
// 180001a30 MOV RAX,qword ptr [RSP + 0x18]
// 180001a35 MOV byte ptr [RAX],0x1
// 180001a38 MOV RAX,qword ptr [RSP + 0x18]
// 180001a3d MOV dword ptr [RAX + 0x10],0x1
// 180001a44 MOV RAX,qword ptr [RSP + 0x18]
// 180001a49 MOV qword ptr [RAX + 0x18],0x1
// 180001a51 MOV RAX,qword ptr [RSP + 0x18]
// 180001a56 MOV dword ptr [RAX + 0x24],0x2
// 180001a5d MOV RAX,qword ptr [RSP + 0x18]
// 180001a62 MOV dword ptr [RAX + 0x20],0x1f4
// 180001a69 MOV RAX,qword ptr [RSP + 0x10]
// 180001a6e MOV RAX,qword ptr [RAX + 0x28]
// 180001a72 AND RAX,0x200000
// 180001a78 TEST RAX,RAX
// 180001a7b JZ 0x180001a91
// 180001a7d MOV RAX,qword ptr [RSP + 0x18]
// 180001a82 MOV qword ptr [RAX + 0x18],0x200000
// 180001a8a XOR EAX,EAX
// 180001a8c JMP 0x180001c8c
// 180001a91 MOV RAX,qword ptr [RSP + 0x10]
// 180001a96 MOV RAX,qword ptr [RAX + 0x28]
// 180001a9a AND RAX,0x400000
// 180001aa0 TEST RAX,RAX
// 180001aa3 JZ 0x180001ab9
// 180001aa5 MOV RAX,qword ptr [RSP + 0x18]
// 180001aaa MOV qword ptr [RAX + 0x18],0x400000
// 180001ab2 XOR EAX,EAX
// 180001ab4 JMP 0x180001c8c
// 180001ab9 MOV RAX,qword ptr [RSP + 0x10]
// 180001abe MOV RAX,qword ptr [RAX + 0x28]
// 180001ac2 AND RAX,0x800000
// 180001ac8 TEST RAX,RAX
// 180001acb JZ 0x180001ae1
// 180001acd MOV RAX,qword ptr [RSP + 0x18]
// 180001ad2 MOV qword ptr [RAX + 0x18],0x800000
// 180001ada XOR EAX,EAX
// 180001adc JMP 0x180001c8c
// 180001ae1 MOV RAX,qword ptr [RSP + 0x10]
// 180001ae6 MOV RAX,qword ptr [RAX + 0x28]
// 180001aea AND RAX,0x40
// 180001aee TEST RAX,RAX
// 180001af1 JZ 0x180001b07
// 180001af3 MOV RAX,qword ptr [RSP + 0x18]
// 180001af8 MOV qword ptr [RAX + 0x18],0x40
// 180001b00 XOR EAX,EAX
// 180001b02 JMP 0x180001c8c
// 180001b07 MOV RAX,qword ptr [RSP + 0x10]
// 180001b0c MOV RAX,qword ptr [RAX + 0x28]
// 180001b10 AND RAX,0x1000000
// 180001b16 TEST RAX,RAX
// 180001b19 JZ 0x180001b2f
// 180001b1b MOV RAX,qword ptr [RSP + 0x18]
// 180001b20 MOV qword ptr [RAX + 0x18],0x1000000
// 180001b28 XOR EAX,EAX
// 180001b2a JMP 0x180001c8c
// 180001b2f MOV RAX,qword ptr [RSP + 0x10]
// 180001b34 MOV RAX,qword ptr [RAX + 0x28]
// 180001b38 AND RAX,0x4
// 180001b3c TEST RAX,RAX
// 180001b3f JZ 0x180001b55
// 180001b41 MOV RAX,qword ptr [RSP + 0x18]
// 180001b46 MOV qword ptr [RAX + 0x18],0x4
// 180001b4e XOR EAX,EAX
// 180001b50 JMP 0x180001c8c
// 180001b55 MOV RAX,qword ptr [RSP + 0x10]
// 180001b5a MOV RAX,qword ptr [RAX + 0x28]
// 180001b5e AND RAX,0x2000
// 180001b64 TEST RAX,RAX
// 180001b67 JZ 0x180001b7d
// 180001b69 MOV RAX,qword ptr [RSP + 0x18]
// 180001b6e MOV qword ptr [RAX + 0x18],0x2000
// 180001b76 XOR EAX,EAX
// 180001b78 JMP 0x180001c8c
// 180001b7d MOV RAX,qword ptr [RSP + 0x10]
// 180001b82 MOV RAX,qword ptr [RAX + 0x28]
// 180001b86 AND RAX,0x80
// 180001b8c TEST RAX,RAX
// 180001b8f JZ 0x180001ba5
// 180001b91 MOV RAX,qword ptr [RSP + 0x18]
// 180001b96 MOV qword ptr [RAX + 0x18],0x80
// 180001b9e XOR EAX,EAX
// 180001ba0 JMP 0x180001c8c
// 180001ba5 MOV RAX,qword ptr [RSP + 0x10]
// 180001baa MOV RAX,qword ptr [RAX + 0x28]
// 180001bae AND RAX,0x100
// 180001bb4 TEST RAX,RAX
// 180001bb7 JZ 0x180001bcd
// 180001bb9 MOV RAX,qword ptr [RSP + 0x18]
// 180001bbe MOV qword ptr [RAX + 0x18],0x100
// 180001bc6 XOR EAX,EAX
// 180001bc8 JMP 0x180001c8c
// 180001bcd MOV RAX,qword ptr [RSP + 0x10]
// 180001bd2 MOV RAX,qword ptr [RAX + 0x28]
// 180001bd6 AND RAX,0x100000
// 180001bdc TEST RAX,RAX
// 180001bdf JZ 0x180001bf5
// 180001be1 MOV RAX,qword ptr [RSP + 0x18]
// 180001be6 MOV qword ptr [RAX + 0x18],0x100000
// 180001bee XOR EAX,EAX
// 180001bf0 JMP 0x180001c8c
// 180001bf5 MOV RAX,qword ptr [RSP + 0x10]
// 180001bfa MOV RAX,qword ptr [RAX + 0x28]
// 180001bfe AND RAX,0x10
// 180001c02 TEST RAX,RAX
// 180001c05 JZ 0x180001c18
// 180001c07 MOV RAX,qword ptr [RSP + 0x18]
// 180001c0c MOV qword ptr [RAX + 0x18],0x10
// 180001c14 XOR EAX,EAX
// 180001c16 JMP 0x180001c8c
// 180001c18 MOV RAX,qword ptr [RSP + 0x10]
// 180001c1d MOV RAX,qword ptr [RAX + 0x28]
// 180001c21 AND RAX,0x40000000
// 180001c27 TEST RAX,RAX
// 180001c2a JZ 0x180001c3d
// 180001c2c MOV RAX,qword ptr [RSP + 0x18]
// 180001c31 MOV qword ptr [RAX + 0x18],0x40000000
// 180001c39 XOR EAX,EAX
// 180001c3b JMP 0x180001c8c
// 180001c3d MOV RAX,qword ptr [RSP + 0x10]
// 180001c42 MOV RAX,qword ptr [RAX + 0x28]
// 180001c46 AND RAX,0x8000000
// 180001c4c TEST RAX,RAX
// 180001c4f JZ 0x180001c62
// 180001c51 MOV RAX,qword ptr [RSP + 0x18]
// 180001c56 MOV qword ptr [RAX + 0x18],0x8000000
// 180001c5e XOR EAX,EAX
// 180001c60 JMP 0x180001c8c
// 180001c62 MOV RAX,qword ptr [RSP + 0x10]
// 180001c67 MOV RAX,qword ptr [RAX + 0x28]
// 180001c6b AND RAX,0x10000000
// 180001c71 TEST RAX,RAX
// 180001c74 JZ 0x180001c87
// 180001c76 MOV RAX,qword ptr [RSP + 0x18]
// 180001c7b MOV qword ptr [RAX + 0x18],0x10000000
// 180001c83 XOR EAX,EAX
// 180001c85 JMP 0x180001c8c
// 180001c87 MOV EAX,0x1
// 180001c8c RET
// FUNCTION 180001830

undefined8 dev_create_instance(undefined8 *param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 *local_20;
  
                    /* 0x1830  2  dev_create_instance */
  local_20 = operator_new(0x1c0);
  if (local_20 == (undefined1 *)0x0) {
    local_20 = (undefined1 *)0x0;
  }
  else {
    puVar2 = local_20;
    for (lVar1 = 0x1c0; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  *param_1 = local_20;
  return 0;
}


// 180001830 MOV qword ptr [RSP + 0x8],RCX
// 180001835 PUSH RDI
// 180001836 SUB RSP,0x40
// 18000183a MOV ECX,0x1c0
// 18000183f CALL 0x180003ef0
// 180001844 MOV qword ptr [RSP + 0x20],RAX
// 180001849 CMP qword ptr [RSP + 0x20],0x0
// 18000184f JZ 0x18000186b
// 180001851 MOV RDI,qword ptr [RSP + 0x20]
// 180001856 XOR EAX,EAX
// 180001858 MOV ECX,0x1c0
// 18000185d STOSB.REP RDI
// 18000185f MOV RAX,qword ptr [RSP + 0x20]
// 180001864 MOV qword ptr [RSP + 0x28],RAX
// 180001869 JMP 0x180001874
// 18000186b MOV qword ptr [RSP + 0x28],0x0
// 180001874 MOV RAX,qword ptr [RSP + 0x28]
// 180001879 MOV qword ptr [RSP + 0x30],RAX
// 18000187e MOV RAX,qword ptr [RSP + 0x50]
// 180001883 MOV RCX,qword ptr [RSP + 0x30]
// 180001888 MOV qword ptr [RAX],RCX
// 18000188b XOR EAX,EAX
// 18000188d ADD RSP,0x40
// 180001891 POP RDI
// 180001892 RET
