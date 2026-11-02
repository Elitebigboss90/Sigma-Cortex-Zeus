// FUNCTION 08030c7c

undefined4 FUN_08030c7c(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_f4;
  undefined2 local_f0;
  undefined1 local_ee;
  undefined1 local_ed;
  undefined2 local_ec;
  undefined1 auStack_e4 [12];
  undefined2 local_d8;
  undefined2 local_d0 [4];
  int local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 auStack_8c [124];
  
  if ((param_1 != 0) && (param_3 != 0)) {
    local_f4 = 0x36;
    local_f0 = 0x1e02;
    local_ed = (undefined1)param_2;
    local_ee = 0x88;
    local_ec = 0x401;
    local_90 = 0;
    FUN_08035d8c(auStack_8c,0,0x7c);
    FUN_08035d8c(local_d0,0,0x40);
    if ((param_2 - 1U & 0xff) < 0xfe) {
      local_d0[0] = 1;
      local_c8 = param_2;
    }
    else {
      local_d0[0] = 2;
      local_c8 = *(int *)(param_1 + 8);
      uStack_c4 = *(undefined4 *)(param_1 + 0xc);
      local_c0 = *(undefined4 *)(param_1 + 0x10);
      uStack_bc = *(undefined4 *)(param_1 + 0x14);
    }
    local_b4 = *(undefined4 *)(param_1 + 0x1c);
    local_b0 = *(undefined4 *)(param_1 + 0x20);
    local_b8 = *(undefined4 *)(param_1 + 0x18);
    local_ac = *(undefined4 *)(param_1 + 0x24);
    local_a8 = *(undefined4 *)(param_1 + 0x28);
    uStack_a4 = *(undefined4 *)(param_1 + 0x2c);
    local_a0 = *(undefined4 *)(param_1 + 0x30);
    local_9c = *(undefined4 *)(param_1 + 0x34);
    local_98 = *(undefined4 *)(param_1 + 0x38);
    local_94 = *(undefined4 *)(param_1 + 0x3c);
    FUN_08031e2c(auStack_e4,&local_90,0x80);
    iVar1 = FUN_0803241c(auStack_e4,DAT_08030d48,local_d0);
    if (iVar1 != 0) {
      uVar2 = FUN_08028d98(&local_f4,&local_90,local_d8,param_3,local_f4 + 10U & 0xffff);
      return uVar2;
    }
  }
  return 0xffffffff;
}


// 08030c7c push {r4,r5,r6,lr}
// 08030c7e mov r5,r1
// 08030c80 mov r6,r2
// 08030c82 mov r4,r0
// 08030c84 sub sp,#0xf0
// 08030c86 cbnz r0,0x08030c90
// 08030c88 mov.w r0,#0xffffffff
// 08030c8c add sp,#0xf0
// 08030c8e pop {r4,r5,r6,pc}
// 08030c90 cmp r2,#0x0
// 08030c92 beq 0x08030c88
// 08030c94 movs r3,#0x36
// 08030c96 str r3,[sp,#0xc]
// 08030c98 movw r3,#0x1e02
// 08030c9c strh.w r3,[sp,#0x10]
// 08030ca0 movs r3,#0x88
// 08030ca2 strb.w r1,[sp,#0x13]
// 08030ca6 strb.w r3,[sp,#0x12]
// 08030caa movs r1,#0x0
// 08030cac movw r3,#0x401
// 08030cb0 movs r2,#0x7c
// 08030cb2 add r0,sp,#0x74
// 08030cb4 strh.w r3,[sp,#0x14]
// 08030cb8 str r1,[sp,#0x70]
// 08030cba bl 0x08035d8c
// 08030cbe movs r2,#0x40
// 08030cc0 movs r1,#0x0
// 08030cc2 add r0,sp,#0x30
// 08030cc4 bl 0x08035d8c
// 08030cc8 subs r3,r5,#0x1
// 08030cca uxtb r3,r3
// 08030ccc cmp r3,#0xfd
// 08030cce bls 0x08030d3e
// 08030cd0 movs r3,#0x2
// 08030cd2 strh.w r3,[sp,#0x30]
// 08030cd6 ldrd r2,r3,[r4,#0x8]
// 08030cda strd r2,r3,[sp,#0x38]
// 08030cde ldrd r2,r3,[r4,#0x10]
// 08030ce2 strd r2,r3,[sp,#0x40]
// 08030ce6 ldr r3,[r4,#0x1c]
// 08030ce8 add r1,sp,#0x70
// 08030cea str r3,[sp,#0x4c]
// 08030cec ldr r3,[r4,#0x20]
// 08030cee add r0,sp,#0x1c
// 08030cf0 str r3,[sp,#0x50]
// 08030cf2 ldr r3,[r4,#0x18]
// 08030cf4 str r3,[sp,#0x48]
// 08030cf6 ldr r3,[r4,#0x24]
// 08030cf8 str r3,[sp,#0x54]
// 08030cfa ldrd r2,r3,[r4,#0x28]
// 08030cfe strd r2,r3,[sp,#0x58]
// 08030d02 ldr r3,[r4,#0x30]
// 08030d04 movs r2,#0x80
// 08030d06 str r3,[sp,#0x60]
// 08030d08 ldr r3,[r4,#0x34]
// 08030d0a str r3,[sp,#0x64]
// 08030d0c ldr r3,[r4,#0x38]
// 08030d0e str r3,[sp,#0x68]
// 08030d10 ldr r3,[r4,#0x3c]
// 08030d12 str r3,[sp,#0x6c]
// 08030d14 bl 0x08031e2c
// 08030d18 ldr r1,[0x08030d48]
// 08030d1a add r2,sp,#0x30
// 08030d1c add r0,sp,#0x1c
// 08030d1e bl 0x0803241c
// 08030d22 cmp r0,#0x0
// 08030d24 beq 0x08030c88
// 08030d26 ldr r1,[sp,#0xc]
// 08030d28 mov r3,r6
// 08030d2a adds r1,#0xa
// 08030d2c uxth r1,r1
// 08030d2e str r1,[sp,#0x0]
// 08030d30 ldrh.w r2,[sp,#0x28]
// 08030d34 add r1,sp,#0x70
// 08030d36 add r0,sp,#0xc
// 08030d38 bl 0x08028d98
// 08030d3c b 0x08030c8c
// 08030d3e movs r3,#0x1
// 08030d40 str r5,[sp,#0x38]
// 08030d42 strh.w r3,[sp,#0x30]
// 08030d46 b 0x08030ce6
// FUNCTION 08030dac

undefined4 FUN_08030dac(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_104;
  undefined2 local_100;
  undefined1 local_fe;
  undefined1 local_fd;
  undefined2 local_fc;
  undefined1 auStack_f4 [12];
  undefined2 local_e8;
  undefined4 local_e0;
  undefined1 local_dc [4];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined1 auStack_8c [124];
  
  if ((param_1 != 0) && (param_3 != 0)) {
    local_104 = 0x36;
    local_100 = 0x1e02;
    local_fd = (undefined1)param_2;
    local_fe = 0x88;
    local_fc = 0x403;
    local_90 = 0;
    FUN_08035d8c(auStack_8c,0,0x7c);
    FUN_08035d8c(local_dc,0,0x4c);
    if (*(char *)(param_1 + 4) != '\0') {
      local_dc[0] = 1;
      local_d8 = *(undefined4 *)(param_1 + 8);
      local_d4 = *(undefined4 *)(param_1 + 0xc);
      local_d0 = *(undefined4 *)(param_1 + 0x10);
      local_cc = *(undefined4 *)(param_1 + 0x14);
      local_c8 = *(undefined4 *)(param_1 + 0x18);
      local_c4 = *(undefined4 *)(param_1 + 0x1c);
      local_c0 = *(undefined4 *)(param_1 + 0x20);
      local_bc = *(undefined4 *)(param_1 + 0x24);
    }
    if (*(char *)(param_1 + 0x28) != '\0') {
      local_b8 = 1;
      local_b4 = *(undefined4 *)(param_1 + 0x2c);
      local_b0 = *(undefined4 *)(param_1 + 0x30);
    }
    if (*(char *)(param_1 + 0x34) != '\0') {
      local_ac = 1;
      if (*(int *)(param_1 + 0x38) != 0) {
        local_a8 = *(undefined4 *)(param_1 + 0x38);
        uStack_a4 = *(undefined4 *)(param_1 + 0x3c);
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        local_a0 = *(undefined4 *)(param_1 + 0x40);
        uStack_9c = *(undefined4 *)(param_1 + 0x44);
      }
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      local_98 = *(undefined4 *)(param_1 + 0x48);
      uStack_94 = *(undefined4 *)(param_1 + 0x4c);
    }
    local_e0 = param_2;
    FUN_08031e2c(auStack_f4,&local_90);
    iVar1 = FUN_0803241c(auStack_f4,DAT_08030ea0,&local_e0);
    if (iVar1 != 0) {
      uVar2 = FUN_08028d98(&local_104,&local_90,local_e8,param_3,local_104 + 10U & 0xffff);
      return uVar2;
    }
  }
  return 0xffffffff;
}


// 08030dac push {r4,r5,r6,lr}
// 08030dae mov r6,r1
// 08030db0 mov r5,r2
// 08030db2 mov r4,r0
// 08030db4 sub sp,#0x100
// 08030db6 cbnz r0,0x08030dc0
// 08030db8 mov.w r0,#0xffffffff
// 08030dbc add sp,#0x100
// 08030dbe pop {r4,r5,r6,pc}
// 08030dc0 cmp r2,#0x0
// 08030dc2 beq 0x08030db8
// 08030dc4 movs r3,#0x36
// 08030dc6 str r3,[sp,#0xc]
// 08030dc8 movw r3,#0x1e02
// 08030dcc strh.w r3,[sp,#0x10]
// 08030dd0 movs r3,#0x88
// 08030dd2 strb.w r1,[sp,#0x13]
// 08030dd6 strb.w r3,[sp,#0x12]
// 08030dda movs r1,#0x0
// 08030ddc movw r3,#0x403
// 08030de0 movs r2,#0x7c
// 08030de2 add r0,sp,#0x84
// 08030de4 strh.w r3,[sp,#0x14]
// 08030de8 str r1,[sp,#0x80]
// 08030dea bl 0x08035d8c
// 08030dee movs r2,#0x4c
// 08030df0 movs r1,#0x0
// 08030df2 add r0,sp,#0x34
// 08030df4 bl 0x08035d8c
// 08030df8 ldrb r3,[r4,#0x4]
// 08030dfa str r6,[sp,#0x30]
// 08030dfc cbz r3,0x08030e24
// 08030dfe movs r3,#0x1
// 08030e00 strb.w r3,[sp,#0x34]
// 08030e04 ldr r3,[r4,#0x8]
// 08030e06 str r3,[sp,#0x38]
// 08030e08 ldr r3,[r4,#0xc]
// 08030e0a str r3,[sp,#0x3c]
// 08030e0c ldr r3,[r4,#0x10]
// 08030e0e str r3,[sp,#0x40]
// 08030e10 ldr r3,[r4,#0x14]
// 08030e12 str r3,[sp,#0x44]
// 08030e14 ldr r3,[r4,#0x18]
// 08030e16 str r3,[sp,#0x48]
// 08030e18 ldr r3,[r4,#0x1c]
// 08030e1a str r3,[sp,#0x4c]
// 08030e1c ldr r3,[r4,#0x20]
// 08030e1e str r3,[sp,#0x50]
// 08030e20 ldr r3,[r4,#0x24]
// 08030e22 str r3,[sp,#0x54]
// 08030e24 ldrb.w r3,[r4,#0x28]
// 08030e28 cbz r3,0x08030e38
// 08030e2a movs r3,#0x1
// 08030e2c strb.w r3,[sp,#0x58]
// 08030e30 ldr r3,[r4,#0x2c]
// 08030e32 str r3,[sp,#0x5c]
// 08030e34 ldr r3,[r4,#0x30]
// 08030e36 str r3,[sp,#0x60]
// 08030e38 ldrb.w r3,[r4,#0x34]
// 08030e3c cbz r3,0x08030e60
// 08030e3e movs r3,#0x1
// 08030e40 strb.w r3,[sp,#0x64]
// 08030e44 ldr r3,[r4,#0x38]
// 08030e46 cbz r3,0x08030e52
// 08030e48 ldrd r0,r1,[r4,#0x38]
// 08030e4c add r3,sp,#0x68
// 08030e4e stm r3,{r0,r1}
// 08030e52 ldr r3,[r4,#0x40]
// 08030e54 cbz r3,0x08030e60
// 08030e56 ldrd r0,r1,[r4,#0x40]
// 08030e5a add r3,sp,#0x70
// 08030e5c stm r3,{r0,r1}
// 08030e60 ldr r3,[r4,#0x48]
// 08030e62 cbz r3,0x08030e6e
// 08030e64 ldrd r0,r1,[r4,#0x48]
// 08030e68 add r3,sp,#0x78
// 08030e6a stm r3,{r0,r1}
// 08030e6e movs r2,#0x80
// 08030e70 add r0,sp,#0x1c
// 08030e72 add.w r1,sp,r2
// 08030e76 bl 0x08031e2c
// 08030e7a ldr r1,[0x08030ea0]
// 08030e7c add r2,sp,#0x30
// 08030e7e add r0,sp,#0x1c
// 08030e80 bl 0x0803241c
// 08030e84 cmp r0,#0x0
// 08030e86 beq 0x08030db8
// 08030e88 ldr r1,[sp,#0xc]
// 08030e8a mov r3,r5
// 08030e8c adds r1,#0xa
// 08030e8e uxth r1,r1
// 08030e90 str r1,[sp,#0x0]
// 08030e92 ldrh.w r2,[sp,#0x28]
// 08030e96 add r1,sp,#0x80
// 08030e98 add r0,sp,#0xc
// 08030e9a bl 0x08028d98
// 08030e9e b 0x08030dbc
// FUNCTION 08028cb4

void FUN_08028cb4(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined2 param_6)

{
  undefined4 local_18;
  undefined2 local_14;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10 = 0x303;
  local_18 = 0x36;
  local_14 = 0x1e02;
  local_12 = param_1;
  local_11 = param_2;
  FUN_08028d98(&local_18,param_3,param_4,param_5,param_6);
  return;
}


// 08028cb4 push {r4,lr}
// 08028cb6 mov r4,r1
// 08028cb8 mov r1,r2
// 08028cba mov r2,r3
// 08028cbc movs r3,#0x0
// 08028cbe sub sp,#0x18
// 08028cc0 strd r3,r3,[sp,#0x10]
// 08028cc4 movw r3,#0x303
// 08028cc8 strh.w r3,[sp,#0x10]
// 08028ccc movs r3,#0x36
// 08028cce str r3,[sp,#0x8]
// 08028cd0 movw r3,#0x1e02
// 08028cd4 strh.w r3,[sp,#0xc]
// 08028cd8 ldrh.w r3,[sp,#0x24]
// 08028cdc strb.w r0,[sp,#0xe]
// 08028ce0 str r3,[sp,#0x0]
// 08028ce2 add r0,sp,#0x8
// 08028ce4 ldr r3,[sp,#0x20]
// 08028ce6 strb.w r4,[sp,#0xf]
// 08028cea bl 0x08028d98
// 08028cee add sp,#0x18
// 08028cf0 pop {r4,pc}
