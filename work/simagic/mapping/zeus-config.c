// FUNCTION 08025458

int FUN_08025458(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_08026bc4();
  iVar3 = FUN_080251a8(param_1);
  iVar1 = DAT_080254e4;
  if (iVar3 != -1) {
    FUN_0802841c(DAT_080254e4,DAT_080254f0,DAT_080254ec,DAT_080254f4,DAT_080254e8,param_2);
    FUN_0802846c(iVar1,param_1);
    FUN_08028544(iVar1,*(undefined4 *)(*(int *)(iVar2 + 4) + 0x1c),
                 *(undefined2 *)(*(int *)(iVar2 + 4) + 0x18),0);
    FUN_08024b54(*(undefined4 *)(iVar1 + 4));
    iVar1 = DAT_080254f8;
    FUN_0802841c(DAT_080254f8,DAT_08025504,DAT_08025500,DAT_08025508,DAT_080254fc);
    FUN_0802846c(iVar1,param_1);
    FUN_08028544(iVar1,*(undefined4 *)(*(int *)(iVar2 + 4) + 0x2c),
                 *(undefined2 *)(*(int *)(iVar2 + 4) + 0x28),0);
    FUN_08024b54(*(undefined4 *)(iVar1 + 4));
    FUN_08024ce4(param_1);
    FUN_08024d4c(param_1);
    FUN_08029726(0,DAT_0802550c);
    iVar3 = 0;
  }
  return iVar3;
}


// 08025458 push {r0,r1,r4,r5,r6,lr}
// 0802545a mov r4,r0
// 0802545c bl 0x08026bc4
// 08025460 mov r6,r0
// 08025462 mov r0,r4
// 08025464 bl 0x080251a8
// 08025468 adds r3,r0,#0x1
// 0802546a beq 0x080254de
// 0802546c ldr r5,[0x080254e4]
// 0802546e ldr r3,[0x080254e8]
// 08025470 mov r0,r5
// 08025472 ldr r2,[0x080254ec]
// 08025474 ldr r1,[0x080254f0]
// 08025476 str r3,[sp,#0x0]
// 08025478 ldr r3,[0x080254f4]
// 0802547a bl 0x0802841c
// 0802547e mov r0,r5
// 08025480 mov r1,r4
// 08025482 bl 0x0802846c
// 08025486 ldr r1,[r6,#0x4]
// 08025488 movs r3,#0x0
// 0802548a ldrh r2,[r1,#0x18]
// 0802548c mov r0,r5
// 0802548e ldr r1,[r1,#0x1c]
// 08025490 bl 0x08028544
// 08025494 ldr r0,[r5,#0x4]
// 08025496 bl 0x08024b54
// 0802549a ldr r5,[0x080254f8]
// 0802549c ldr r3,[0x080254fc]
// 0802549e ldr r2,[0x08025500]
// 080254a0 mov r0,r5
// 080254a2 ldr r1,[0x08025504]
// 080254a4 str r3,[sp,#0x0]
// 080254a6 ldr r3,[0x08025508]
// 080254a8 bl 0x0802841c
// 080254ac mov r1,r4
// 080254ae mov r0,r5
// 080254b0 bl 0x0802846c
// 080254b4 ldr r1,[r6,#0x4]
// 080254b6 movs r3,#0x0
// 080254b8 ldrh r2,[r1,#0x28]
// 080254ba mov r0,r5
// 080254bc ldr r1,[r1,#0x2c]
// 080254be bl 0x08028544
// 080254c2 ldr r0,[r5,#0x4]
// 080254c4 bl 0x08024b54
// 080254c8 mov r0,r4
// 080254ca bl 0x08024ce4
// 080254ce mov r0,r4
// 080254d0 bl 0x08024d4c
// 080254d4 movs r0,#0x0
// 080254d6 ldr r1,[0x0802550c]
// 080254d8 bl 0x08029726
// 080254dc movs r0,#0x0
// 080254de add sp,#0x8
// 080254e0 pop {r4,r5,r6,pc}
// FUNCTION 08024a18

undefined4 FUN_08024a18(int param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined4 uStack_14;
  
  iVar2 = param_1;
  puVar4 = param_3;
  uStack_14 = param_4;
  FUN_08026bb4();
  if (*(int *)(DAT_08024abc + 0xf4) == 2) {
    uVar3 = 100;
  }
  else {
    uVar3 = *(uint *)(DAT_08024abc + 8);
    if (uVar3 == 0) {
      *param_3 = 0;
      *(undefined1 *)(param_3 + 1) = 0;
      return 0;
    }
  }
  if (param_1 == 1) {
    FUN_0802850e(DAT_08024ac0,param_2,&uStack_14,DAT_08024abc,iVar2,param_2,puVar4);
    iVar2 = 0x37;
  }
  else if (param_1 == 2) {
    FUN_0802850e(DAT_08024ac4,param_2,&uStack_14,DAT_08024abc,iVar2,param_2,puVar4);
    iVar2 = 0xf;
  }
  else {
    iVar2 = 0;
  }
  if (99 < uVar3) {
    uVar3 = 100;
  }
  sVar1 = (short)((uVar3 * iVar2 * 0xff + 5000) / 10000);
  *(char *)param_3 = (char)((ushort)((ushort)(byte)uStack_14 * sVar1 + 0x80) / 0xff);
  *(char *)((int)param_3 + 1) = (char)((ushort)((ushort)uStack_14._1_1_ * sVar1 + 0x80) / 0xff);
  *(char *)(param_3 + 1) = (char)((ushort)((ushort)uStack_14._2_1_ * sVar1 + 0x80) / 0xff);
  return 0;
}


// 08024a18 push {r0,r1,r2,r3,r4,r5,r6,lr}
// 08024a1a mov r5,r2
// 08024a1c str r1,[sp,#0x4]
// 08024a1e mov r6,r0
// 08024a20 bl 0x08026bb4
// 08024a24 ldr r3,[0x08024abc]
// 08024a26 ldr r1,[sp,#0x4]
// 08024a28 ldr.w r2,[r3,#0xf4]
// 08024a2c cmp r2,#0x2
// 08024a2e beq 0x08024a3e
// 08024a30 ldr r4,[r3,#0x8]
// 08024a32 cbnz r4,0x08024a40
// 08024a34 strh r4,[r5,#0x0]
// 08024a36 strb r4,[r5,#0x2]
// 08024a38 movs r0,#0x0
// 08024a3a add sp,#0x10
// 08024a3c pop {r4,r5,r6,pc}
// 08024a3e movs r4,#0x64
// 08024a40 cmp r6,#0x1
// 08024a42 beq 0x08024aa2
// 08024a44 cmp r6,#0x2
// 08024a46 beq 0x08024aae
// 08024a48 movs r3,#0x0
// 08024a4a cmp r4,#0x64
// 08024a4c it cs
// 08024a4e mov.cs r4,#0x64
// 08024a50 movw r2,#0x2710
// 08024a54 muls r3,r4
// 08024a56 rsb r3,r3,r3, lsl #0x8
// 08024a5a add.w r3,r3,#0x1380
// 08024a5e adds r3,#0x8
// 08024a60 udiv r3,r3,r2
// 08024a64 movs r4,#0xff
// 08024a66 ldrb.w r1,[sp,#0xd]
// 08024a6a ldrb.w r2,[sp,#0xe]
// 08024a6e ldrb.w r0,[sp,#0xc]
// 08024a72 uxth r3,r3
// 08024a74 smulbb r1,r1,r3
// 08024a78 smulbb r0,r0,r3
// 08024a7c smulbb r2,r2,r3
// 08024a80 adds r0,#0x80
// 08024a82 adds r1,#0x80
// 08024a84 add.w r3,r2,#0x80
// 08024a88 uxth r0,r0
// 08024a8a uxth r1,r1
// 08024a8c uxth r3,r3
// 08024a8e udiv r0,r0,r4
// 08024a92 udiv r1,r1,r4
// 08024a96 udiv r3,r3,r4
// 08024a9a strb r0,[r5,#0x0]
// 08024a9c strb r1,[r5,#0x1]
// 08024a9e strb r3,[r5,#0x2]
// 08024aa0 b 0x08024a38
// 08024aa2 ldr r0,[0x08024ac0]
// 08024aa4 add r2,sp,#0xc
// 08024aa6 bl 0x0802850e
// 08024aaa movs r3,#0x37
// 08024aac b 0x08024a4a
// 08024aae ldr r0,[0x08024ac4]
// 08024ab0 add r2,sp,#0xc
// 08024ab2 bl 0x0802850e
// 08024ab6 movs r3,#0xf
// 08024ab8 b 0x08024a4a
// FUNCTION 08024ac8

undefined4 FUN_08024ac8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = FUN_08026bbc();
  iVar6 = DAT_08024b4c;
  if ((param_1 == 1) || (iVar6 = DAT_08024b50, param_1 == 2)) {
    uVar2 = *(undefined4 *)(iVar6 + 8);
  }
  else {
    uVar2 = 0;
  }
  iVar6 = *(int *)(iVar1 + 0x18);
  bVar3 = 0;
  while( true ) {
    if (iVar6 <= (int)(uint)bVar3) break;
    *(undefined4 *)((uint)bVar3 * 0x28 + *(int *)(iVar1 + 0x1c) + 0x14) = uVar2;
    bVar3 = bVar3 + 1;
  }
  iVar6 = *(int *)(iVar1 + 0x60);
  for (bVar3 = 0; (int)(uint)bVar3 < iVar6; bVar3 = bVar3 + 1) {
    iVar5 = *(int *)(iVar1 + 100);
    iVar7 = *(int *)(iVar5 + 0x14);
    bVar4 = 0;
    while( true ) {
      if (iVar7 <= (int)(uint)bVar4) break;
      *(undefined4 *)(*(int *)((uint)bVar3 * 0x13c + iVar5 + 0xc) + (uint)bVar4 * 4) = uVar2;
      bVar4 = bVar4 + 1;
    }
  }
  iVar6 = *(int *)(iVar1 + 0x10);
  bVar3 = 0;
  while( true ) {
    if (iVar6 <= (int)(uint)bVar3) break;
    *(undefined4 *)(*(int *)(iVar1 + 0x14) + (uint)bVar3 * 0x10 + 0xc) = uVar2;
    bVar3 = bVar3 + 1;
  }
  return 0;
}


// 08024ac8 push {r3,r4,r5,r6,r7,lr}
// 08024aca mov r4,r0
// 08024acc bl 0x08026bbc
// 08024ad0 cmp r4,#0x1
// 08024ad2 beq 0x08024b02
// 08024ad4 cmp r4,#0x2
// 08024ad6 beq 0x08024b08
// 08024ad8 movs r2,#0x0
// 08024ada movs r3,#0x0
// 08024adc movs r6,#0x28
// 08024ade ldr r4,[r0,#0x18]
// 08024ae0 adds r5,r3,#0x1
// 08024ae2 uxtb r3,r3
// 08024ae4 cmp r3,r4
// 08024ae6 blt 0x08024b0c
// 08024ae8 movs r4,#0x0
// 08024aea mov.w r12,#0x13c
// 08024aee ldr r7,[r0,#0x60]
// 08024af0 uxtb r1,r4
// 08024af2 cmp r1,r7
// 08024af4 bge 0x08024b2e
// 08024af6 ldr r3,[r0,#0x64]
// 08024af8 mla r1,r12,r1,r3
// 08024afc ldr r6,[r3,#0x14]
// 08024afe movs r3,#0x0
// 08024b00 b 0x08024b20
// 08024b02 ldr r3,[0x08024b4c]
// 08024b04 ldr r2,[r3,#0x8]
// 08024b06 b 0x08024ada
// 08024b08 ldr r3,[0x08024b50]
// 08024b0a b 0x08024b04
// 08024b0c ldr r1,[r0,#0x1c]
// 08024b0e mla r3,r6,r3,r1
// 08024b12 str r2,[r3,#0x14]
// 08024b14 mov r3,r5
// 08024b16 b 0x08024ae0
// 08024b18 ldr r5,[r1,#0xc]
// 08024b1a str.w r2,[r5,r3,lsl #0x2]
// 08024b1e mov r3,lr
// 08024b20 add.w lr,r3,#0x1
// 08024b24 uxtb r3,r3
// 08024b26 cmp r3,r6
// 08024b28 blt 0x08024b18
// 08024b2a adds r4,#0x1
// 08024b2c b 0x08024af0
// 08024b2e movs r3,#0x0
// 08024b30 ldr r4,[r0,#0x10]
// 08024b32 adds r5,r3,#0x1
// 08024b34 uxtb r3,r3
// 08024b36 cmp r3,r4
// 08024b38 blt 0x08024b3e
// 08024b3a movs r0,#0x0
// 08024b3c pop {r3,r4,r5,r6,r7,pc}
// 08024b3e ldr r1,[r0,#0x14]
// 08024b40 add.w r3,r1,r3, lsl #0x4
// 08024b44 str r2,[r3,#0xc]
// 08024b46 mov r3,r5
// 08024b48 b 0x08024b32
// FUNCTION 08024b54

undefined4 FUN_08024b54(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = DAT_08024c70;
  if ((param_1 == 1) || (iVar6 = DAT_08024c74, param_1 == 2)) {
    uVar2 = *(int *)(iVar6 + 0xc) * 4 + 7U & 0xfffffff8;
    uVar3 = *(int *)(iVar6 + 0x118) * 4 + 7U & 0xfffffff8;
    uVar4 = *(int *)(iVar6 + 0x224) * 4 + 7U & 0xfffffff8;
    uVar5 = *(int *)(iVar6 + 0x330) * 4 + 7U & 0xfffffff8;
    FUN_08024788(*(undefined4 *)(iVar6 + 0x14),*(int *)(iVar6 + 0xc),&stack0xffffffc8 + -uVar2,
                 &stack0xffffffc8 + uVar2 * -2);
    FUN_08024788(*(undefined4 *)(iVar6 + 0x120),*(undefined4 *)(iVar6 + 0x118),
                 &stack0xffffffc8 + -uVar3 + uVar2 * -2,&stack0xffffffc8 + uVar3 * -2 + uVar2 * -2);
    FUN_08024788(*(undefined4 *)(iVar6 + 0x22c),*(undefined4 *)(iVar6 + 0x224),
                 &stack0xffffffc8 + -uVar4 + uVar3 * -2 + uVar2 * -2,
                 &stack0xffffffc8 + uVar4 * -2 + uVar3 * -2 + uVar2 * -2);
    FUN_08024788(*(undefined4 *)(iVar6 + 0x338),*(undefined4 *)(iVar6 + 0x330),
                 &stack0xffffffc8 + -uVar5 + uVar4 * -2 + uVar3 * -2 + uVar2 * -2,
                 &stack0xffffffc8 + uVar5 * -2 + uVar4 * -2 + uVar3 * -2 + uVar2 * -2);
    FUN_080284f0(iVar6,&stack0xffffffc8 + -uVar2,&stack0xffffffc8 + uVar2 * -2,
                 *(undefined4 *)(iVar6 + 0xc));
    FUN_080284f6(iVar6,&stack0xffffffc8 + -uVar3 + uVar2 * -2,
                 &stack0xffffffc8 + uVar3 * -2 + uVar2 * -2,*(undefined4 *)(iVar6 + 0x118));
    FUN_080284fe(iVar6,&stack0xffffffc8 + -uVar4 + uVar3 * -2 + uVar2 * -2,
                 &stack0xffffffc8 + uVar4 * -2 + uVar3 * -2 + uVar2 * -2,
                 *(undefined4 *)(iVar6 + 0x224));
    FUN_08028506(iVar6,&stack0xffffffc8 + -uVar5 + uVar4 * -2 + uVar3 * -2 + uVar2 * -2,
                 &stack0xffffffc8 + uVar5 * -2 + uVar4 * -2 + uVar3 * -2 + uVar2 * -2,
                 *(undefined4 *)(iVar6 + 0x330));
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// 08024b54 push {r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 08024b58 vpush {d8,d9}
// 08024b5c cmp r0,#0x1
// 08024b5e add r7,sp,#0x0
// 08024b60 beq 0x08024b74
// 08024b62 cmp r0,#0x2
// 08024b64 beq 0x08024c64
// 08024b66 mov.w r0,#0xffffffff
// 08024b6a mov sp,r7
// 08024b6c vpop {d8,d9}
// 08024b70 pop.w {r3,r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 08024b74 mov r3,sp
// 08024b76 vmov s18,r3
// 08024b7a ldr r4,[0x08024c70]
// 08024b7c ldr r1,[r4,#0xc]
// 08024b7e ldr r0,[r4,#0x14]
// 08024b80 lsls r3,r1,#0x2
// 08024b82 adds r3,#0x7
// 08024b84 bic r3,r3,#0x7
// 08024b88 sub.w sp,sp,r3
// 08024b8c mov r10,sp
// 08024b8e sub.w sp,sp,r3
// 08024b92 ldr.w r3,[r4,#0x118]
// 08024b96 mov r11,sp
// 08024b98 lsls r3,r3,#0x2
// 08024b9a adds r3,#0x7
// 08024b9c bic r3,r3,#0x7
// 08024ba0 sub.w sp,sp,r3
// 08024ba4 mov r8,sp
// 08024ba6 sub.w sp,sp,r3
// 08024baa ldr.w r3,[r4,#0x224]
// 08024bae mov r9,sp
// 08024bb0 lsls r3,r3,#0x2
// 08024bb2 adds r3,#0x7
// 08024bb4 bic r3,r3,#0x7
// 08024bb8 sub.w sp,sp,r3
// 08024bbc mov r5,sp
// 08024bbe sub.w sp,sp,r3
// 08024bc2 ldr.w r3,[r4,#0x330]
// 08024bc6 mov r6,sp
// 08024bc8 lsls r3,r3,#0x2
// 08024bca adds r3,#0x7
// 08024bcc bic r3,r3,#0x7
// 08024bd0 sub.w sp,sp,r3
// 08024bd4 mov r2,sp
// 08024bd6 sub.w sp,sp,r3
// 08024bda mov r3,sp
// 08024bdc vmov s16,r2
// 08024be0 vmov s17,r3
// 08024be4 mov r2,r10
// 08024be6 mov r3,r11
// 08024be8 bl 0x08024788
// 08024bec mov r3,r9
// 08024bee mov r2,r8
// 08024bf0 ldr.w r1,[r4,#0x118]
// 08024bf4 ldr.w r0,[r4,#0x120]
// 08024bf8 bl 0x08024788
// 08024bfc mov r3,r6
// 08024bfe mov r2,r5
// 08024c00 ldr.w r1,[r4,#0x224]
// 08024c04 ldr.w r0,[r4,#0x22c]
// 08024c08 bl 0x08024788
// 08024c0c vmov r3,s17
// 08024c10 vmov r2,s16
// 08024c14 ldr.w r1,[r4,#0x330]
// 08024c18 ldr.w r0,[r4,#0x338]
// 08024c1c bl 0x08024788
// 08024c20 mov r2,r11
// 08024c22 mov r1,r10
// 08024c24 mov r0,r4
// 08024c26 ldr r3,[r4,#0xc]
// 08024c28 bl 0x080284f0
// 08024c2c mov r2,r9
// 08024c2e mov r1,r8
// 08024c30 mov r0,r4
// 08024c32 ldr.w r3,[r4,#0x118]
// 08024c36 bl 0x080284f6
// 08024c3a mov r2,r6
// 08024c3c mov r1,r5
// 08024c3e mov r0,r4
// 08024c40 ldr.w r3,[r4,#0x224]
// 08024c44 bl 0x080284fe
// 08024c48 mov r0,r4
// 08024c4a ldr.w r3,[r4,#0x330]
// 08024c4e vmov r2,s17
// 08024c52 vmov r1,s16
// 08024c56 bl 0x08028506
// 08024c5a vmov r3,s18
// 08024c5e movs r0,#0x0
// 08024c60 mov sp,r3
// 08024c62 b 0x08024b6a
// 08024c64 mov r3,sp
// 08024c66 ldr r4,[0x08024c74]
// 08024c68 vmov s18,r3
// 08024c6c b 0x08024b7c
// FUNCTION 08024c78

undefined4 FUN_08024c78(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_08024c94;
  if ((param_1 != 1) && (uVar1 = DAT_08024c98, param_1 != 2)) {
    return 0;
  }
  uVar1 = FUN_08028544(uVar1,param_2,param_3,0);
  return uVar1;
}


// 08024c78 cmp r0,#0x1
// 08024c7a beq 0x08024c84
// 08024c7c cmp r0,#0x2
// 08024c7e beq 0x08024c8c
// 08024c80 movs r0,#0x0
// 08024c82 bx lr
// 08024c84 movs r3,#0x0
// 08024c86 ldr r0,[0x08024c94]
// 08024c88 b.w 0x08028544
// 08024c8c movs r3,#0x0
// 08024c8e ldr r0,[0x08024c98]
// 08024c90 b 0x08024c88
// FUNCTION 08024ce4

undefined4 FUN_08024ce4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = param_1;
  iVar2 = FUN_08026bc4();
  iVar1 = DAT_08024d48;
  FUN_08028c28(DAT_08024d48);
  FUN_08028c38(iVar1,uVar3);
  iVar2 = *(int *)(iVar2 + 4);
  iVar2 = FUN_08028c3c(iVar1,*(undefined4 *)(iVar2 + 0x3c),*(undefined2 *)(iVar2 + 0x38),iVar2,
                       param_1,uVar3,param_3);
  if ((((iVar2 == 0) || (1 < *(uint *)(iVar1 + 8))) || (2 < *(uint *)(iVar1 + 0xc))) ||
     (100 < *(uint *)(iVar1 + 0x10))) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_08026e04(0);
    FUN_0802d5d4(*(undefined4 *)(iVar1 + 8));
    FUN_0802d5a0(*(undefined4 *)(iVar1 + 0xc));
    FUN_0802d5c0(*(undefined4 *)(iVar1 + 0x10));
    FUN_08026e38(0);
    uVar3 = 0;
  }
  return uVar3;
}


// 08024ce4 push {r0,r1,r2,r4,r5,lr}
// 08024ce6 str r0,[sp,#0x4]
// 08024ce8 bl 0x08026bc4
// 08024cec mov r5,r0
// 08024cee ldr r4,[0x08024d48]
// 08024cf0 mov r0,r4
// 08024cf2 bl 0x08028c28
// 08024cf6 mov r0,r4
// 08024cf8 ldr r1,[sp,#0x4]
// 08024cfa bl 0x08028c38
// 08024cfe ldr r3,[r5,#0x4]
// 08024d00 mov r0,r4
// 08024d02 ldrh r2,[r3,#0x38]
// 08024d04 ldr r1,[r3,#0x3c]
// 08024d06 bl 0x08028c3c
// 08024d0a cbz r0,0x08024d42
// 08024d0c ldr r3,[r4,#0x8]
// 08024d0e cmp r3,#0x1
// 08024d10 bhi 0x08024d42
// 08024d12 ldr r3,[r4,#0xc]
// 08024d14 cmp r3,#0x2
// 08024d16 bhi 0x08024d42
// 08024d18 ldr r3,[r4,#0x10]
// 08024d1a cmp r3,#0x64
// 08024d1c bhi 0x08024d42
// 08024d1e movs r0,#0x0
// 08024d20 bl 0x08026e04
// 08024d24 ldr r0,[r4,#0x8]
// 08024d26 bl 0x0802d5d4
// 08024d2a ldr r0,[r4,#0xc]
// 08024d2c bl 0x0802d5a0
// 08024d30 ldr r0,[r4,#0x10]
// 08024d32 bl 0x0802d5c0
// 08024d36 movs r0,#0x0
// 08024d38 bl 0x08026e38
// 08024d3c movs r0,#0x0
// 08024d3e add sp,#0xc
// 08024d40 pop {r4,r5,pc}
// 08024d42 mov.w r0,#0xffffffff
// 08024d46 b 0x08024d3e
// FUNCTION 08024d4c

undefined4 FUN_08024d4c(undefined4 param_1,uint3 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  bVar7 = 0;
  uStack_2c = (uint)param_2;
  uVar5 = param_1;
  uStack_28 = param_3;
  iVar2 = FUN_08026bc4();
  iVar3 = FUN_08026bbc();
  iVar1 = DAT_08024eec;
  FUN_08028b58(DAT_08024eec,4,DAT_08024ef0);
  FUN_08028b7c(iVar1,param_1);
  iVar2 = *(int *)(iVar2 + 4);
  FUN_08028b84(iVar1,*(undefined4 *)(iVar2 + 0x4c),*(undefined2 *)(iVar2 + 0x48),iVar2,uVar5);
  if (*DAT_08024ef4 == '\0') {
    *DAT_08024ef4 = '\x01';
    if (**(int **)(iVar1 + 4) == 1) {
      bVar4 = false;
      bVar7 = 0;
      while( true ) {
        uVar6 = (uint)bVar7;
        if (*(int *)(iVar1 + 8) <= (int)uVar6) break;
        if (*(int *)(*(int *)(iVar1 + 4) + uVar6 * 0xc + 8) !=
            *(int *)(uVar6 * 0x13c + *(int *)(iVar3 + 100) + 0x10)) {
          FUN_08026e04(0);
          iVar2 = *(int *)(iVar1 + 4) + uVar6 * 0xc;
          FUN_08029290(0,*(int *)(iVar2 + 4) + -1,*(undefined4 *)(iVar2 + 8));
          FUN_08026e38(0);
          bVar4 = true;
        }
        bVar7 = bVar7 + 1;
      }
      if (bVar4) {
        FUN_080248f0(iVar3);
      }
    }
  }
  else if (**(int **)(iVar1 + 4) == 1) {
    bVar4 = false;
    iVar2 = -1;
    while( true ) {
      uVar6 = (uint)bVar7;
      if (*(int *)(iVar1 + 8) <= (int)uVar6) break;
      iVar9 = uVar6 * 0xc;
      if (*(int *)(*(int *)(iVar1 + 4) + iVar9 + 8) !=
          *(int *)(uVar6 * 0x13c + *(int *)(iVar3 + 100) + 0x10)) {
        FUN_08026e04(0);
        iVar2 = *(int *)(iVar1 + 4) + iVar9;
        FUN_08029290(0,*(int *)(iVar2 + 4) + -1,*(undefined4 *)(iVar2 + 8));
        FUN_08026e38(0);
        iVar8 = uVar6 + 8;
        iVar2 = *(int *)(*(int *)(iVar1 + 4) + iVar9 + 8);
        if (iVar2 == 1) {
          uVar5 = 0;
LAB_08024e52:
          FUN_0802c498(iVar8,uVar5);
        }
        else if (iVar2 == 0) {
          uVar5 = 1;
          goto LAB_08024e52;
        }
        FUN_0802c61c(iVar8,7);
        FUN_0802c41c(0,0xd3,0x20,0x29);
        FUN_0802c2a8(iVar8,9);
        FUN_0802c32c(iVar8);
        bVar4 = true;
        iVar2 = (int)(char)bVar7;
      }
      bVar7 = bVar7 + 1;
    }
    if (bVar4) {
      FUN_080248f0(iVar3);
    }
    if (iVar2 != -1) {
      FUN_08026e04(2);
      FUN_08034d64(DAT_08024ef8);
      while( true ) {
        FUN_0802c3f4(iVar2 + 8U & 0xffff,(int)&uStack_2c + 3);
        if (uStack_2c._3_1_ == '\x01') break;
        thunk_FUN_0802fec8(0x32);
      }
      FUN_0802c3b8(8);
      FUN_0802c3b8(9);
      FUN_0802c3b8(10);
      FUN_0802c3b8(0xb);
      FUN_08034d6e(DAT_08024ef8);
      FUN_08026e38(2);
    }
  }
  return 0;
}


// 08024d4c push {r0,r1,r2,r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 08024d50 movs r7,#0x0
// 08024d52 mov r6,r0
// 08024d54 strb.w r7,[sp,#0x7]
// 08024d58 bl 0x08026bc4
// 08024d5c mov r5,r0
// 08024d5e bl 0x08026bbc
// 08024d62 ldr r4,[0x08024eec]
// 08024d64 ldr r2,[0x08024ef0]
// 08024d66 movs r1,#0x4
// 08024d68 mov r8,r0
// 08024d6a mov r0,r4
// 08024d6c bl 0x08028b58
// 08024d70 mov r1,r6
// 08024d72 mov r0,r4
// 08024d74 bl 0x08028b7c
// 08024d78 ldr r3,[r5,#0x4]
// 08024d7a mov r0,r4
// 08024d7c ldrh.w r2,[r3,#0x48]
// 08024d80 ldr r1,[r3,#0x4c]
// 08024d82 bl 0x08028b84
// 08024d86 ldr r2,[0x08024ef4]
// 08024d88 ldrb r3,[r2,#0x0]
// 08024d8a cbnz r3,0x08024df6
// 08024d8c movs r1,#0x1
// 08024d8e strb r1,[r2,#0x0]
// 08024d90 ldr r2,[r4,#0x4]
// 08024d92 ldr r2,[r2,#0x0]
// 08024d94 cmp r2,r1
// 08024d96 bne 0x08024dee
// 08024d98 mov r5,r3
// 08024d9a movs r6,#0xc
// 08024d9c mov.w r7,#0x13c
// 08024da0 b 0x08024ddc
// 08024da2 mul r9,r6,r2
// 08024da6 ldr r1,[r4,#0x4]
// 08024da8 add.w r0,r1,r9
// 08024dac ldr.w r1,[r8,#0x64]
// 08024db0 mla r2,r7,r2,r1
// 08024db4 ldr r1,[r0,#0x8]
// 08024db6 ldr r2,[r2,#0x10]
// 08024db8 cmp r1,r2
// 08024dba beq 0x08024dda
// 08024dbc movs r0,#0x0
// 08024dbe bl 0x08026e04
// 08024dc2 ldr r3,[r4,#0x4]
// 08024dc4 movs r0,#0x0
// 08024dc6 add r3,r9
// 08024dc8 ldrd r1,r2,[r3,#0x4]
// 08024dcc subs r1,#0x1
// 08024dce bl 0x08029290
// 08024dd2 movs r0,#0x0
// 08024dd4 bl 0x08026e38
// 08024dd8 movs r3,#0x1
// 08024dda adds r5,#0x1
// 08024ddc ldr r1,[r4,#0x8]
// 08024dde uxtb r2,r5
// 08024de0 cmp r2,r1
// 08024de2 blt 0x08024da2
// 08024de4 cmp r3,#0x1
// 08024de6 bne 0x08024dee
// 08024de8 mov r0,r8
// 08024dea bl 0x080248f0
// 08024dee movs r0,#0x0
// 08024df0 add sp,#0xc
// 08024df2 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 08024df6 ldr r3,[r4,#0x4]
// 08024df8 ldr r3,[r3,#0x0]
// 08024dfa cmp r3,#0x1
// 08024dfc bne 0x08024dee
// 08024dfe mov r1,r7
// 08024e00 mov.w r5,#0xffffffff
// 08024e04 mov.w r9,#0xc
// 08024e08 mov.w r10,#0x13c
// 08024e0c b 0x08024e80
// 08024e0e mul r11,r9,r6
// 08024e12 ldr r3,[r4,#0x4]
// 08024e14 add.w r2,r3,r11
// 08024e18 ldr.w r3,[r8,#0x64]
// 08024e1c ldr r2,[r2,#0x8]
// 08024e1e mla r3,r10,r6,r3
// 08024e22 ldr r3,[r3,#0x10]
// 08024e24 cmp r2,r3
// 08024e26 beq 0x08024e7e
// 08024e28 movs r0,#0x0
// 08024e2a bl 0x08026e04
// 08024e2e ldr r3,[r4,#0x4]
// 08024e30 movs r0,#0x0
// 08024e32 add r3,r11
// 08024e34 ldrd r1,r2,[r3,#0x4]
// 08024e38 subs r1,#0x1
// 08024e3a bl 0x08029290
// 08024e3e movs r0,#0x0
// 08024e40 bl 0x08026e38
// 08024e44 ldr r3,[r4,#0x4]
// 08024e46 adds r6,#0x8
// 08024e48 add r3,r11
// 08024e4a ldr r3,[r3,#0x8]
// 08024e4c cmp r3,#0x1
// 08024e4e bne 0x08024edc
// 08024e50 movs r1,#0x0
// 08024e52 mov r0,r6
// 08024e54 bl 0x0802c498
// 08024e58 movs r1,#0x7
// 08024e5a mov r0,r6
// 08024e5c bl 0x0802c61c
// 08024e60 movs r3,#0x29
// 08024e62 movs r2,#0x20
// 08024e64 movs r1,#0xd3
// 08024e66 movs r0,#0x0
// 08024e68 bl 0x0802c41c
// 08024e6c movs r1,#0x9
// 08024e6e mov r0,r6
// 08024e70 bl 0x0802c2a8
// 08024e74 mov r0,r6
// 08024e76 bl 0x0802c32c
// 08024e7a movs r1,#0x1
// 08024e7c sxtb r5,r7
// 08024e7e adds r7,#0x1
// 08024e80 ldr r3,[r4,#0x8]
// 08024e82 uxtb r6,r7
// 08024e84 cmp r6,r3
// 08024e86 blt 0x08024e0e
// 08024e88 cbz r1,0x08024e90
// 08024e8a mov r0,r8
// 08024e8c bl 0x080248f0
// 08024e90 adds r3,r5,#0x1
// 08024e92 beq 0x08024dee
// 08024e94 movs r0,#0x2
// 08024e96 bl 0x08026e04
// 08024e9a ldr r0,[0x08024ef8]
// 08024e9c bl 0x08034d64
// 08024ea0 adds r5,#0x8
// 08024ea2 uxth r5,r5
// 08024ea4 mov r0,r5
// 08024ea6 add.w r1,sp,#0x7
// 08024eaa bl 0x0802c3f4
// 08024eae ldrb.w r3,[sp,#0x7]
// 08024eb2 cmp r3,#0x1
// 08024eb4 bne 0x08024ee4
// 08024eb6 movs r0,#0x8
// 08024eb8 bl 0x0802c3b8
// 08024ebc movs r0,#0x9
// 08024ebe bl 0x0802c3b8
// 08024ec2 movs r0,#0xa
// 08024ec4 bl 0x0802c3b8
// 08024ec8 movs r0,#0xb
// 08024eca bl 0x0802c3b8
// 08024ece ldr r0,[0x08024ef8]
// 08024ed0 bl 0x08034d6e
// 08024ed4 movs r0,#0x2
// 08024ed6 bl 0x08026e38
// 08024eda b 0x08024dee
// 08024edc cmp r3,#0x0
// 08024ede bne 0x08024e58
// 08024ee0 movs r1,#0x1
// 08024ee2 b 0x08024e52
// 08024ee4 movs r0,#0x32
// 08024ee6 bl 0x080273a4
// 08024eea b 0x08024ea4
// FUNCTION 08024f24

undefined4 FUN_08024f24(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  byte bVar14;
  byte bVar15;
  int iVar16;
  
  iVar2 = FUN_08026bc4();
  iVar6 = DAT_08025190;
  iVar10 = *(int *)(DAT_0802518c + 0xc);
  FUN_08028308(DAT_08025190,DAT_08025198,6,DAT_0802519c);
  FUN_0802832a(iVar6);
  FUN_08028330(iVar6,*(undefined4 *)(*(int *)(iVar2 + 4) + 0xc),
               *(undefined2 *)(*(int *)(iVar2 + 4) + 8),0);
  uVar3 = DAT_080251a4;
  if (*(int *)(iVar6 + 8) < 7) {
    FUN_08026e04(0);
    iVar2 = *(int *)(iVar6 + 8);
    iVar6 = *(int *)(iVar6 + 4);
    for (bVar14 = 0; (int)(uint)bVar14 < iVar2; bVar14 = bVar14 + 1) {
      iVar7 = (uint)bVar14 * 0x18 + iVar6;
      iVar4 = *(int *)(iVar7 + 4);
      if (iVar4 == 3) {
        iVar4 = *(int *)(param_1 + 0x18);
        if (0 < iVar4) {
          uVar9 = 0;
          iVar16 = *(int *)(iVar7 + 8);
          iVar12 = *(int *)(param_1 + 0x1c);
          do {
            sVar1 = (short)uVar9;
            iVar13 = uVar9 * 4;
            uVar9 = uVar9 + 1 & 0xff;
            *(undefined4 *)(iVar12 + (sVar1 + iVar13) * 8 + 0x24) =
                 *(undefined4 *)(iVar16 + sVar1 * 4);
          } while ((int)uVar9 < iVar4);
          uVar9 = 0;
          iVar7 = *(int *)(iVar7 + 0x10);
          do {
            sVar1 = (short)uVar9;
            uVar11 = *(uint *)(iVar7 + sVar1 * 4);
            iVar16 = uVar9 * 4;
            if (uVar11 < 0x21) {
              uVar3 = *(undefined4 *)(iVar10 + uVar11 * 4);
            }
            else {
              uVar3 = *(undefined4 *)(iVar10 + 0x80);
            }
            uVar9 = uVar9 + 1 & 0xff;
            *(undefined4 *)(iVar12 + (sVar1 + iVar16) * 8 + 0x14) = uVar3;
          } while ((int)uVar9 < iVar4);
        }
      }
      else if (iVar4 == 9) {
        iVar4 = *(int *)(param_1 + 0x30);
        if (0 < iVar4) {
          uVar9 = 0;
          iVar7 = *(int *)(iVar7 + 8);
          uVar11 = 0;
          uVar8 = 0;
          iVar12 = *(int *)(param_1 + 0x34);
          do {
            uVar5 = uVar11 + 1;
            uVar11 = uVar5 & 0xff;
            *(undefined4 *)(iVar12 + uVar8 * 0x78 + uVar5 * 0x10 + 4) =
                 *(undefined4 *)(iVar7 + (uVar9 & 0xff) * 4);
            if (uVar11 == 7) {
              uVar8 = uVar8 + 1 & 0xff;
              if (iVar4 <= (int)uVar8) break;
              uVar11 = 0;
            }
            uVar9 = uVar9 + 1;
          } while( true );
        }
      }
      else if (iVar4 == 4) {
        iVar4 = *(int *)(param_1 + 0x58);
        if (0 < iVar4) {
          uVar9 = 0;
          iVar7 = *(int *)(iVar7 + 8);
          iVar12 = *(int *)(param_1 + 0x5c);
          do {
            uVar11 = uVar9 * 2;
            iVar16 = iVar12 + uVar9 * 0x28;
            *(undefined4 *)(iVar16 + 0x14) = *(undefined4 *)(iVar7 + (uVar11 & 0xfe) * 4);
            uVar9 = uVar9 + 1 & 0xff;
            *(undefined4 *)(iVar16 + 0x24) = *(undefined4 *)(iVar7 + (uVar11 + 1 & 0xff) * 4);
          } while ((int)uVar9 < iVar4);
        }
      }
      else if (iVar4 == 10) {
        iVar4 = *(int *)(param_1 + 0x60);
        if (0 < iVar4) {
          uVar9 = 0;
          while( true ) {
            uVar11 = uVar9 & 0xff;
            if (iVar4 <= (int)uVar11) break;
            iVar16 = *(int *)(iVar7 + 8);
            iVar12 = uVar11 * 0x13c + *(int *)(param_1 + 100);
            iVar13 = *(int *)(iVar12 + 0x14);
            *(undefined4 *)(iVar12 + 0x134) = *(undefined4 *)(iVar16 + (uVar9 & 0x7f) * 8);
            *(undefined4 *)(iVar12 + 0x124) = *(undefined4 *)(iVar16 + ((uVar9 & 0x7f) * 2 + 1) * 4)
            ;
            for (bVar15 = 0; uVar8 = (uint)bVar15, (int)uVar8 < iVar13; bVar15 = bVar15 + 1) {
              uVar5 = *(uint *)(*(int *)(iVar7 + 0x10) + (uVar11 * iVar13 + uVar8) * 4);
              if (uVar5 < 0x21) {
                uVar3 = *(undefined4 *)(iVar10 + uVar5 * 4);
              }
              else {
                uVar3 = *(undefined4 *)(iVar10 + 0x80);
              }
              *(undefined4 *)(*(int *)(iVar12 + 0xc) + uVar8 * 4) = uVar3;
            }
            uVar9 = uVar9 + 1;
          }
        }
      }
      else if ((iVar4 == 2) && (iVar4 = *(int *)(param_1 + 0x10), 0 < iVar4)) {
        uVar9 = 0;
        iVar7 = *(int *)(iVar7 + 0x10);
        iVar12 = *(int *)(param_1 + 0x14);
        do {
          sVar1 = (short)uVar9;
          uVar11 = *(uint *)(iVar7 + sVar1 * 4);
          if (uVar11 < 0x21) {
            uVar3 = *(undefined4 *)(iVar10 + uVar11 * 4);
          }
          else {
            uVar3 = *(undefined4 *)(iVar10 + 0x80);
          }
          uVar9 = uVar9 + 1 & 0xff;
          *(undefined4 *)(iVar12 + sVar1 * 0x10 + 0xc) = uVar3;
        } while ((int)uVar9 < iVar4);
      }
    }
    FUN_08026e38(0);
    uVar3 = 0;
  }
  else {
    *(undefined4 *)(DAT_080251a0 + 8) = 0x50;
    uVar9 = 0;
    FUN_08034d64(uVar3);
    FUN_0802ca7c();
    do {
      uVar11 = uVar9 & 0xffff;
      FUN_0802c61c(uVar11,1);
      FUN_0802c41c(0,0xec,0x2b,0x24);
      uVar9 = uVar9 + 1;
      FUN_0802c2a8(uVar11,1);
    } while (uVar9 != 0xe);
    uVar9 = 0;
    do {
      uVar11 = uVar9 & 0xffff;
      uVar9 = uVar9 + 1;
      FUN_0802c32c(uVar11);
    } while (uVar9 != 0xe);
    thunk_FUN_0802fec8(2000);
    uVar9 = 0;
    do {
      uVar11 = uVar9 & 0xffff;
      uVar9 = uVar9 + 1;
      FUN_0802c3b8(uVar11);
    } while (uVar9 != 0xe);
    FUN_08034d6e(DAT_080251a4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// 08024f24 mov r4,r0
// 08024f26 bl 0x08026bc4
// 08024f2a movs r2,#0x6
// 08024f2c mov r7,r0
// 08024f2e ldr r3,[0x0802518c]
// 08024f30 ldr r6,[0x08025190]
// 08024f32 ldr r5,[r3,#0xc]
// 08024f34 ldr r3,[0x08025194]
// 08024f36 str r2,[sp,#0x0]
// 08024f38 mov r0,r6
// 08024f3a ldr r1,[0x08025198]
// 08024f3c str r3,[sp,#0x4]
// 08024f3e ldr r3,[0x0802519c]
// 08024f40 bl 0x08028308
// 08024f44 mov r1,r8
// 08024f46 mov r0,r6
// 08024f48 bl 0x0802832a
// 08024f4c ldr r1,[r7,#0x4]
// 08024f4e movs r3,#0x0
// 08024f50 ldrh r2,[r1,#0x8]
// 08024f52 mov r0,r6
// 08024f54 ldr r1,[r1,#0xc]
// 08024f56 bl 0x08028330
// 08024f5a ldr r3,[r6,#0x8]
// 08024f5c cmp r3,#0x6
// 08024f5e ble 0x08024fca
// 08024f60 movs r2,#0x50
// 08024f62 ldr r3,[0x080251a0]
// 08024f64 ldr r0,[0x080251a4]
// 08024f66 str r2,[r3,#0x8]
// 08024f68 movs r4,#0x0
// 08024f6a bl 0x08034d64
// 08024f6e bl 0x0802ca7c
// 08024f72 uxth r5,r4
// 08024f74 movs r1,#0x1
// 08024f76 mov r0,r5
// 08024f78 bl 0x0802c61c
// 08024f7c movs r3,#0x24
// 08024f7e movs r2,#0x2b
// 08024f80 movs r1,#0xec
// 08024f82 movs r0,#0x0
// 08024f84 bl 0x0802c41c
// 08024f88 adds r4,#0x1
// 08024f8a movs r1,#0x1
// 08024f8c mov r0,r5
// 08024f8e bl 0x0802c2a8
// 08024f92 cmp r4,#0xe
// 08024f94 bne 0x08024f72
// 08024f96 movs r4,#0x0
// 08024f98 uxth r0,r4
// 08024f9a adds r4,#0x1
// 08024f9c bl 0x0802c32c
// 08024fa0 cmp r4,#0xe
// 08024fa2 bne 0x08024f98
// 08024fa4 mov.w r0,#0x7d0
// 08024fa8 bl 0x080273a4
// 08024fac movs r4,#0x0
// 08024fae uxth r0,r4
// 08024fb0 adds r4,#0x1
// 08024fb2 bl 0x0802c3b8
// 08024fb6 cmp r4,#0xe
// 08024fb8 bne 0x08024fae
// 08024fba ldr r0,[0x080251a4]
// 08024fbc bl 0x08034d6e
// 08024fc0 mov.w r0,#0xffffffff
// 08024fc4 add sp,#0x1c
// 08024fc6 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 08024fca movs r0,#0x0
// 08024fcc bl 0x08026e04
// 08024fd0 mov.w r11,#0x13c
// 08024fd4 mov.w r12,#0x0
// 08024fd8 ldr r3,[r6,#0x8]
// 08024fda str r3,[sp,#0x14]
// 08024fdc ldr r3,[r6,#0x4]
// 08024fde str r3,[sp,#0x10]
// 08024fe0 ldr r2,[sp,#0x14]
// 08024fe2 uxtb.w r3,r12
// 08024fe6 cmp r3,r2
// 08024fe8 blt 0x08024ff4
// 08024fea movs r0,#0x0
// 08024fec bl 0x08026e38
// 08024ff0 movs r0,#0x0
// 08024ff2 b 0x08024fc4
// 08024ff4 movs r1,#0x18
// 08024ff6 ldr r2,[sp,#0x10]
// 08024ff8 mla r3,r1,r3,r2
// 08024ffc ldr r2,[r3,#0x4]
// 08024ffe cmp r2,#0x3
// 08025000 bne 0x0802505a
// 08025002 ldr r0,[r4,#0x18]
// 08025004 cmp r0,#0x0
// 08025006 bgt 0x0802500e
// 08025008 add.w r12,r12,#0x1
// 0802500c b 0x08024fe0
// 0802500e movs r2,#0x0
// 08025010 ldr.w lr,[r3,#0x8]
// 08025014 ldr r6,[r4,#0x1c]
// 08025016 sxth r1,r2
// 08025018 ldr.w r7,[lr,r1,lsl #0x2]
// 0802501c add.w r1,r1,r2, lsl #0x2
// 08025020 adds r2,#0x1
// 08025022 uxtb r2,r2
// 08025024 add.w r1,r6,r1, lsl #0x3
// 08025028 cmp r0,r2
// 0802502a str r7,[r1,#0x24]
// 0802502c bgt 0x08025016
// 0802502e movs r2,#0x0
// 08025030 ldr r7,[r3,#0x10]
// 08025032 sxth r1,r2
// 08025034 ldr.w r3,[r7,r1,lsl #0x2]
// 08025038 add.w r1,r1,r2, lsl #0x2
// 0802503c cmp r3,#0x20
// 0802503e add.w r2,r2,#0x1
// 08025042 ite hi
// 08025044 ldr.hi.w r3,[r5,#0x80]
// 08025048 ldr.ls.w r3,[r5,r3,lsl #0x2]
// 0802504c uxtb r2,r2
// 0802504e add.w r1,r6,r1, lsl #0x3
// 08025052 cmp r0,r2
// 08025054 str r3,[r1,#0x14]
// 08025056 bgt 0x08025032
// 08025058 b 0x08025008
// 0802505a cmp r2,#0x9
// 0802505c bne 0x0802509c
// 0802505e ldr r6,[r4,#0x30]
// 08025060 cmp r6,#0x0
// 08025062 ble 0x08025008
// 08025064 movs r0,#0x0
// 08025066 ldr r7,[r3,#0x8]
// 08025068 mov r2,r0
// 0802506a mov r3,r0
// 0802506c ldr.w lr,[r4,#0x34]
// 08025070 uxtb r1,r0
// 08025072 ldr.w r8,[r7,r1,lsl #0x2]
// 08025076 rsb r1,r3,r3, lsl #0x4
// 0802507a adds r2,#0x1
// 0802507c add.w r1,lr,r1, lsl #0x3
// 08025080 add.w r1,r1,r2, lsl #0x4
// 08025084 uxtb r2,r2
// 08025086 cmp r2,#0x7
// 08025088 str.w r8,[r1,#0x4]
// 0802508c bne 0x08025098
// 0802508e adds r3,#0x1
// 08025090 uxtb r3,r3
// 08025092 cmp r6,r3
// 08025094 ble 0x08025008
// 08025096 movs r2,#0x0
// 08025098 adds r0,#0x1
// 0802509a b 0x08025070
// 0802509c cmp r2,#0x4
// 0802509e bne 0x080250da
// 080250a0 ldr r0,[r4,#0x58]
// 080250a2 cmp r0,#0x0
// 080250a4 ble 0x08025008
// 080250a6 movs r2,#0x0
// 080250a8 ldr r6,[r3,#0x8]
// 080250aa ldr r7,[r4,#0x5c]
// 080250ac lsl.w lr,r2,#0x1
// 080250b0 and r3,lr,#0xfe
// 080250b4 ldr.w r3,[r6,r3,lsl #0x2]
// 080250b8 add.w r1,r2,r2, lsl #0x2
// 080250bc add.w r1,r7,r1, lsl #0x3
// 080250c0 add.w lr,lr,#0x1
// 080250c4 str r3,[r1,#0x14]
// 080250c6 uxtb.w lr,lr
// 080250ca adds r2,#0x1
// 080250cc ldr.w r3,[r6,lr,lsl #0x2]
// 080250d0 uxtb r2,r2
// 080250d2 cmp r0,r2
// 080250d4 str r3,[r1,#0x24]
// 080250d6 bgt 0x080250ac
// 080250d8 b 0x08025008
// 080250da cmp r2,#0xa
// 080250dc bne 0x08025156
// 080250de ldr.w r9,[r4,#0x60]
// 080250e2 cmp.w r9,#0x0
// 080250e6 ble 0x08025008
// 080250e8 movs r2,#0x0
// 080250ea b 0x08025120
// 080250ec mov.w lr,#0x0
// 080250f0 ldr r2,[r4,#0x64]
// 080250f2 ldr r7,[r3,#0x8]
// 080250f4 mla r2,r11,r1,r2
// 080250f8 ldr.w r0,[r7,r6,lsl #0x2]
// 080250fc ldr.w r10,[r2,#0x14]
// 08025100 adds r6,#0x1
// 08025102 str.w r0,[r2,#0x134]
// 08025106 uxtb r6,r6
// 08025108 mul r1,r1,r10
// 0802510c ldr.w r6,[r7,r6,lsl #0x2]
// 08025110 str.w r6,[r2,#0x124]
// 08025114 uxtb.w r6,lr
// 08025118 cmp r6,r10
// 0802511a blt 0x08025132
// 0802511c ldr r2,[sp,#0xc]
// 0802511e adds r2,#0x1
// 08025120 str r2,[sp,#0xc]
// 08025122 ldr r2,[sp,#0xc]
// 08025124 ldrb.w r1,[sp,#0xc]
// 08025128 lsls r6,r2,#0x1
// 0802512a cmp r9,r1
// 0802512c uxtb r6,r6
// 0802512e bgt 0x080250ec
// 08025130 b 0x08025008
// 08025132 ldr r7,[r3,#0x10]
// 08025134 add.w r8,r1,r6
// 08025138 ldr.w r8,[r7,r8,lsl #0x2]
// 0802513c ldr r7,[r2,#0xc]
// 0802513e cmp.w r8,#0x20
// 08025142 ite hi
// 08025144 ldr.hi.w r0,[r5,#0x80]
// 08025148 ldr.ls.w r0,[r5,r8,lsl #0x2]
// 0802514c add.w lr,lr,#0x1
// 08025150 str.w r0,[r7,r6,lsl #0x2]
// 08025154 b 0x08025114
// 08025156 cmp r2,#0x2
// 08025158 bne.w 0x08025008
// 0802515c ldr r0,[r4,#0x10]
// 0802515e cmp r0,#0x0
// 08025160 ble.w 0x08025008
// 08025164 movs r2,#0x0
// 08025166 ldr r6,[r3,#0x10]
// 08025168 ldr r7,[r4,#0x14]
// 0802516a sxth r1,r2
// 0802516c ldr.w r3,[r6,r1,lsl #0x2]
// 08025170 adds r2,#0x1
// 08025172 cmp r3,#0x20
// 08025174 ite hi
// 08025176 ldr.hi.w r3,[r5,#0x80]
// 0802517a ldr.ls.w r3,[r5,r3,lsl #0x2]
// 0802517e uxtb r2,r2
// 08025180 add.w r1,r7,r1, lsl #0x4
// 08025184 cmp r0,r2
// 08025186 str r3,[r1,#0xc]
// 08025188 bgt 0x0802516a
// 0802518a b 0x08025008
// FUNCTION 080251a8

undefined4 FUN_080251a8(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  byte bVar18;
  
  iVar4 = FUN_08026bbc();
  iVar5 = FUN_08026bc4();
  iVar9 = DAT_0802543c;
  iVar12 = *(int *)(DAT_08025438 + 0xc);
  FUN_08028308(DAT_0802543c,DAT_08025444,6,DAT_08025448,6,DAT_08025440);
  FUN_0802832a(iVar9,param_1);
  FUN_08028330(iVar9,*(undefined4 *)(*(int *)(iVar5 + 4) + 0xc),
               *(undefined2 *)(*(int *)(iVar5 + 4) + 8),0);
  uVar6 = DAT_08025450;
  if (*(int *)(iVar9 + 8) < 7) {
    FUN_08026e04(0);
    iVar5 = *(int *)(iVar9 + 8);
    iVar9 = *(int *)(iVar9 + 4);
    cVar2 = *DAT_08025454;
    for (bVar18 = 0; (int)(uint)bVar18 < iVar5; bVar18 = bVar18 + 1) {
      iVar10 = (uint)bVar18 * 0x18 + iVar9;
      iVar7 = *(int *)(iVar10 + 4);
      if (iVar7 == 3) {
        iVar7 = *(int *)(iVar4 + 0x18);
        if (0 < iVar7) {
          uVar11 = 0;
          iVar17 = *(int *)(iVar10 + 8);
          iVar16 = *(int *)(iVar4 + 0x1c);
          do {
            sVar3 = (short)uVar11;
            iVar1 = uVar11 * 4;
            uVar11 = uVar11 + 1 & 0xff;
            *(undefined4 *)(iVar16 + (sVar3 + iVar1) * 8 + 0x24) =
                 *(undefined4 *)(iVar17 + sVar3 * 4);
          } while ((int)uVar11 < iVar7);
          if (cVar2 == '\0') {
            iVar10 = *(int *)(iVar10 + 0x10);
            uVar11 = 0;
            do {
              sVar3 = (short)uVar11;
              uVar13 = *(uint *)(iVar10 + sVar3 * 4);
              iVar17 = uVar11 * 4;
              if (uVar13 < 0x21) {
                uVar6 = *(undefined4 *)(iVar12 + uVar13 * 4);
              }
              else {
                uVar6 = *(undefined4 *)(iVar12 + 0x80);
              }
              uVar11 = uVar11 + 1 & 0xff;
              *(undefined4 *)(iVar16 + (sVar3 + iVar17) * 8 + 0x14) = uVar6;
            } while ((int)uVar11 < iVar7);
          }
        }
      }
      else if (iVar7 == 9) {
        iVar7 = *(int *)(iVar4 + 0x30);
        if (0 < iVar7) {
          uVar15 = 0;
          iVar16 = *(int *)(iVar10 + 8);
          uVar11 = 0;
          uVar13 = 0;
          iVar10 = *(int *)(iVar4 + 0x34);
          do {
            uVar8 = uVar11 + 1;
            uVar11 = uVar8 & 0xff;
            *(undefined4 *)(iVar10 + uVar13 * 0x78 + uVar8 * 0x10 + 4) =
                 *(undefined4 *)(iVar16 + (uVar15 & 0xff) * 4);
            if (uVar11 == 7) {
              uVar13 = uVar13 + 1 & 0xff;
              if (iVar7 <= (int)uVar13) break;
              uVar11 = 0;
            }
            uVar15 = uVar15 + 1;
          } while( true );
        }
      }
      else if (iVar7 == 4) {
        iVar7 = *(int *)(iVar4 + 0x58);
        if (0 < iVar7) {
          iVar10 = *(int *)(iVar10 + 8);
          uVar11 = 0;
          iVar16 = *(int *)(iVar4 + 0x5c);
          do {
            uVar13 = uVar11 * 2;
            iVar17 = iVar16 + uVar11 * 0x28;
            *(undefined4 *)(iVar17 + 0x14) = *(undefined4 *)(iVar10 + (uVar13 & 0xfe) * 4);
            uVar11 = uVar11 + 1 & 0xff;
            *(undefined4 *)(iVar17 + 0x24) = *(undefined4 *)(iVar10 + (uVar13 + 1 & 0xff) * 4);
          } while ((int)uVar11 < iVar7);
        }
      }
      else if (iVar7 == 10) {
        iVar7 = *(int *)(iVar4 + 0x60);
        if (0 < iVar7) {
          bVar14 = 0;
          while( true ) {
            uVar11 = (uint)bVar14;
            if (iVar7 <= (int)uVar11) break;
            iVar17 = *(int *)(iVar10 + 8);
            iVar16 = uVar11 * 0x13c + *(int *)(iVar4 + 100);
            *(undefined4 *)(iVar16 + 0x134) =
                 *(undefined4 *)(iVar17 + (uint)(byte)(bVar14 << 1) * 4);
            *(undefined4 *)(iVar16 + 0x124) =
                 *(undefined4 *)(iVar17 + ((byte)(bVar14 << 1) + 1) * 4);
            if (cVar2 == '\0') {
              iVar17 = *(int *)(iVar16 + 0x14);
              for (uVar13 = 0; uVar15 = uVar13 & 0xff, (int)uVar15 < iVar17; uVar13 = uVar13 + 1) {
                uVar8 = *(uint *)(*(int *)(iVar10 + 0x10) + (uVar11 * iVar17 + uVar15) * 4);
                if (uVar8 < 0x21) {
                  uVar6 = *(undefined4 *)(iVar12 + uVar8 * 4);
                }
                else {
                  uVar6 = *(undefined4 *)(iVar12 + 0x80);
                }
                *(undefined4 *)(*(int *)(iVar16 + 0xc) + uVar15 * 4) = uVar6;
              }
            }
            bVar14 = bVar14 + 1;
          }
        }
      }
      else if (((iVar7 == 2) && (iVar7 = *(int *)(iVar4 + 0x10), 0 < iVar7)) && (cVar2 == '\0')) {
        iVar10 = *(int *)(iVar10 + 0x10);
        iVar16 = *(int *)(iVar4 + 0x14);
        uVar11 = 0;
        do {
          sVar3 = (short)uVar11;
          uVar13 = *(uint *)(iVar10 + sVar3 * 4);
          if (uVar13 < 0x21) {
            uVar6 = *(undefined4 *)(iVar12 + uVar13 * 4);
          }
          else {
            uVar6 = *(undefined4 *)(iVar12 + 0x80);
          }
          uVar11 = uVar11 + 1 & 0xff;
          *(undefined4 *)(iVar16 + sVar3 * 0x10 + 0xc) = uVar6;
        } while ((int)uVar11 < iVar7);
      }
    }
    *DAT_08025454 = '\x01';
    FUN_08026e38(0);
    uVar6 = 0;
  }
  else {
    *(undefined4 *)(DAT_0802544c + 8) = 0x50;
    uVar11 = 0;
    FUN_08034d64(uVar6);
    FUN_0802ca7c();
    do {
      uVar13 = uVar11 & 0xffff;
      FUN_0802c61c(uVar13,1);
      FUN_0802c41c(0,0xec,0x2b,0x24);
      uVar11 = uVar11 + 1;
      FUN_0802c2a8(uVar13,1);
    } while (uVar11 != 0xe);
    uVar11 = 0;
    do {
      uVar13 = uVar11 & 0xffff;
      uVar11 = uVar11 + 1;
      FUN_0802c32c(uVar13);
    } while (uVar11 != 0xe);
    thunk_FUN_0802fec8(2000);
    uVar11 = 0;
    do {
      uVar13 = uVar11 & 0xffff;
      uVar11 = uVar11 + 1;
      FUN_0802c3b8(uVar13);
    } while (uVar11 != 0xe);
    FUN_08034d6e(DAT_08025450);
    uVar6 = 0xffffffff;
  }
  return uVar6;
}


// 080251a8 push {r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 080251ac sub sp,#0x1c
// 080251ae mov r8,r0
// 080251b0 bl 0x08026bbc
// 080251b4 mov r4,r0
// 080251b6 bl 0x08026bc4
// 080251ba movs r2,#0x6
// 080251bc mov r7,r0
// 080251be ldr r3,[0x08025438]
// 080251c0 ldr r6,[0x0802543c]
// 080251c2 ldr r5,[r3,#0xc]
// 080251c4 ldr r3,[0x08025440]
// 080251c6 str r2,[sp,#0x0]
// 080251c8 mov r0,r6
// 080251ca ldr r1,[0x08025444]
// 080251cc str r3,[sp,#0x4]
// 080251ce ldr r3,[0x08025448]
// 080251d0 bl 0x08028308
// 080251d4 mov r1,r8
// 080251d6 mov r0,r6
// 080251d8 bl 0x0802832a
// 080251dc ldr r1,[r7,#0x4]
// 080251de movs r3,#0x0
// 080251e0 ldrh r2,[r1,#0x8]
// 080251e2 mov r0,r6
// 080251e4 ldr r1,[r1,#0xc]
// 080251e6 bl 0x08028330
// 080251ea ldr r3,[r6,#0x8]
// 080251ec cmp r3,#0x6
// 080251ee ble 0x0802525a
// 080251f0 movs r2,#0x50
// 080251f2 ldr r3,[0x0802544c]
// 080251f4 ldr r0,[0x08025450]
// 080251f6 str r2,[r3,#0x8]
// 080251f8 movs r4,#0x0
// 080251fa bl 0x08034d64
// 080251fe bl 0x0802ca7c
// 08025202 uxth r5,r4
// 08025204 movs r1,#0x1
// 08025206 mov r0,r5
// 08025208 bl 0x0802c61c
// 0802520c movs r3,#0x24
// 0802520e movs r2,#0x2b
// 08025210 movs r1,#0xec
// 08025212 movs r0,#0x0
// 08025214 bl 0x0802c41c
// 08025218 adds r4,#0x1
// 0802521a movs r1,#0x1
// 0802521c mov r0,r5
// 0802521e bl 0x0802c2a8
// 08025222 cmp r4,#0xe
// 08025224 bne 0x08025202
// 08025226 movs r4,#0x0
// 08025228 uxth r0,r4
// 0802522a adds r4,#0x1
// 0802522c bl 0x0802c32c
// 08025230 cmp r4,#0xe
// 08025232 bne 0x08025228
// 08025234 mov.w r0,#0x7d0
// 08025238 bl 0x080273a4
// 0802523c movs r4,#0x0
// 0802523e uxth r0,r4
// 08025240 adds r4,#0x1
// 08025242 bl 0x0802c3b8
// 08025246 cmp r4,#0xe
// 08025248 bne 0x0802523e
// 0802524a ldr r0,[0x08025450]
// 0802524c bl 0x08034d6e
// 08025250 mov.w r0,#0xffffffff
// 08025254 add sp,#0x1c
// 08025256 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 0802525a movs r0,#0x0
// 0802525c bl 0x08026e04
// 08025260 mov.w lr,#0x0
// 08025264 ldr r3,[r6,#0x8]
// 08025266 str r3,[sp,#0x14]
// 08025268 ldr r3,[r6,#0x4]
// 0802526a str r3,[sp,#0x10]
// 0802526c ldr r3,[0x08025454]
// 0802526e ldrb r3,[r3,#0x0]
// 08025270 str r3,[sp,#0xc]
// 08025272 ldr r2,[sp,#0x14]
// 08025274 uxtb.w r3,lr
// 08025278 cmp r3,r2
// 0802527a blt 0x0802528c
// 0802527c movs r2,#0x1
// 0802527e ldr r3,[0x08025454]
// 08025280 movs r0,#0x0
// 08025282 strb r2,[r3,#0x0]
// 08025284 bl 0x08026e38
// 08025288 movs r0,#0x0
// 0802528a b 0x08025254
// 0802528c movs r2,#0x18
// 0802528e ldr r1,[sp,#0x10]
// 08025290 mla r3,r2,r3,r1
// 08025294 ldr r1,[r3,#0x4]
// 08025296 cmp r1,#0x3
// 08025298 bne 0x080252fc
// 0802529a ldr r6,[r4,#0x18]
// 0802529c cmp r6,#0x0
// 0802529e bgt 0x080252a6
// 080252a0 add.w lr,lr,#0x1
// 080252a4 b 0x08025272
// 080252a6 movs r1,#0x0
// 080252a8 ldr.w r8,[r3,#0x8]
// 080252ac ldr r7,[r4,#0x1c]
// 080252ae sxth r0,r1
// 080252b0 ldr.w r12,[r8,r0,lsl #0x2]
// 080252b4 add.w r0,r0,r1, lsl #0x2
// 080252b8 adds r1,#0x1
// 080252ba uxtb r1,r1
// 080252bc add.w r0,r7,r0, lsl #0x3
// 080252c0 cmp r6,r1
// 080252c2 str.w r12,[r0,#0x24]
// 080252c6 bgt 0x080252ae
// 080252c8 ldr r2,[sp,#0xc]
// 080252ca cmp r2,#0x0
// 080252cc bne 0x080252a0
// 080252ce mov r1,r2
// 080252d0 ldr.w r12,[r3,#0x10]
// 080252d4 sxth r0,r1
// 080252d6 ldr.w r3,[r12,r0,lsl #0x2]
// 080252da add.w r0,r0,r1, lsl #0x2
// 080252de cmp r3,#0x20
// 080252e0 add.w r1,r1,#0x1
// 080252e4 ite hi
// 080252e6 ldr.hi.w r3,[r5,#0x80]
// 080252ea ldr.ls.w r3,[r5,r3,lsl #0x2]
// 080252ee uxtb r1,r1
// 080252f0 add.w r0,r7,r0, lsl #0x3
// 080252f4 cmp r6,r1
// 080252f6 str r3,[r0,#0x14]
// 080252f8 bgt 0x080252d4
// 080252fa b 0x080252a0
// 080252fc cmp r1,#0x9
// 080252fe bne 0x08025340
// 08025300 ldr r7,[r4,#0x30]
// 08025302 cmp r7,#0x0
// 08025304 ble 0x080252a0
// 08025306 movs r6,#0x0
// 08025308 ldr.w r12,[r3,#0x8]
// 0802530c mov r1,r6
// 0802530e mov r3,r6
// 08025310 ldr.w r8,[r4,#0x34]
// 08025314 uxtb r0,r6
// 08025316 ldr.w r9,[r12,r0,lsl #0x2]
// 0802531a rsb r0,r3,r3, lsl #0x4
// 0802531e adds r1,#0x1
// 08025320 add.w r0,r8,r0, lsl #0x3
// 08025324 add.w r0,r0,r1, lsl #0x4
// 08025328 uxtb r1,r1
// 0802532a cmp r1,#0x7
// 0802532c str.w r9,[r0,#0x4]
// 08025330 bne 0x0802533c
// 08025332 adds r3,#0x1
// 08025334 uxtb r3,r3
// 08025336 cmp r7,r3
// 08025338 ble 0x080252a0
// 0802533a movs r1,#0x0
// 0802533c adds r6,#0x1
// 0802533e b 0x08025314
// 08025340 cmp r1,#0x4
// 08025342 bne 0x0802537a
// 08025344 ldr r6,[r4,#0x58]
// 08025346 cmp r6,#0x0
// 08025348 ble 0x080252a0
// 0802534a ldr r7,[r3,#0x8]
// 0802534c movs r3,#0x0
// 0802534e ldr.w r8,[r4,#0x5c]
// 08025352 lsls r1,r3,#0x1
// 08025354 and r12,r1,#0xfe
// 08025358 ldr.w r2,[r7,r12,lsl #0x2]
// 0802535c add.w r0,r3,r3, lsl #0x2
// 08025360 add.w r0,r8,r0, lsl #0x3
// 08025364 adds r1,#0x1
// 08025366 str r2,[r0,#0x14]
// 08025368 uxtb r1,r1
// 0802536a adds r3,#0x1
// 0802536c ldr.w r1,[r7,r1,lsl #0x2]
// 08025370 uxtb r3,r3
// 08025372 cmp r6,r3
// 08025374 str r1,[r0,#0x24]
// 08025376 bgt 0x08025352
// 08025378 b 0x080252a0
// 0802537a cmp r1,#0xa
// 0802537c bne 0x080253f8
// 0802537e ldr.w r10,[r4,#0x60]
// 08025382 cmp.w r10,#0x0
// 08025386 ble 0x080252a0
// 08025388 movs r6,#0x0
// 0802538a b 0x080253b4
// 0802538c mov.w r2,#0x13c
// 08025390 ldr r1,[r4,#0x64]
// 08025392 ldr.w r12,[r3,#0x8]
// 08025396 mla r1,r2,r0,r1
// 0802539a ldr.w r2,[r12,r7,lsl #0x2]
// 0802539e adds r7,#0x1
// 080253a0 str.w r2,[r1,#0x134]
// 080253a4 uxtb r7,r7
// 080253a6 ldr.w r7,[r12,r7,lsl #0x2]
// 080253aa ldr r2,[sp,#0xc]
// 080253ac str.w r7,[r1,#0x124]
// 080253b0 cbz r2,0x080253c0
// 080253b2 adds r6,#0x1
// 080253b4 uxtb r0,r6
// 080253b6 lsls r7,r6,#0x1
// 080253b8 cmp r10,r0
// 080253ba uxtb r7,r7
// 080253bc bgt 0x0802538c
// 080253be b 0x080252a0
// 080253c0 ldr.w r11,[r1,#0x14]
// 080253c4 ldr.w r8,[sp,#0xc]
// 080253c8 mul r0,r0,r11
// 080253cc uxtb.w r12,r8
// 080253d0 cmp r12,r11
// 080253d2 bge 0x080253b2
// 080253d4 ldr r7,[r3,#0x10]
// 080253d6 add.w r9,r0,r12
// 080253da ldr.w r9,[r7,r9,lsl #0x2]
// 080253de ldr r7,[r1,#0xc]
// 080253e0 cmp.w r9,#0x20
// 080253e4 ite hi
// 080253e6 ldr.hi.w r2,[r5,#0x80]
// 080253ea ldr.ls.w r2,[r5,r9,lsl #0x2]
// 080253ee add.w r8,r8,#0x1
// 080253f2 str.w r2,[r7,r12,lsl #0x2]
// 080253f6 b 0x080253cc
// 080253f8 cmp r1,#0x2
// 080253fa bne.w 0x080252a0
// 080253fe ldr r6,[r4,#0x10]
// 08025400 cmp r6,#0x0
// 08025402 ble.w 0x080252a0
// 08025406 ldr r2,[sp,#0xc]
// 08025408 cmp r2,#0x0
// 0802540a bne.w 0x080252a0
// 0802540e mov r1,r2
// 08025410 ldr r7,[r3,#0x10]
// 08025412 ldr.w r12,[r4,#0x14]
// 08025416 sxth r0,r1
// 08025418 ldr.w r3,[r7,r0,lsl #0x2]
// 0802541c adds r1,#0x1
// 0802541e cmp r3,#0x20
// 08025420 ite hi
// 08025422 ldr.hi.w r3,[r5,#0x80]
// 08025426 ldr.ls.w r3,[r5,r3,lsl #0x2]
// 0802542a uxtb r1,r1
// 0802542c add.w r0,r12,r0, lsl #0x4
// 08025430 cmp r6,r1
// 08025432 str r3,[r0,#0xc]
// 08025434 bgt 0x08025416
// 08025436 b 0x080252a0
// FUNCTION 080242fc

void FUN_080242fc(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_08024358;
  iVar5 = 0;
  iVar4 = DAT_08024358;
  do {
    iVar6 = iVar2 + iVar5 * 0xc;
    iVar3 = (**(code **)(iVar2 + iVar5 * 0xc))();
    if (iVar3 == 1) {
      bVar1 = *(byte *)(iVar4 + 8);
      if (bVar1 < *(byte *)(iVar4 + 9)) {
        *(byte *)(iVar4 + 8) = bVar1 + 1;
      }
      else if (bVar1 == *(byte *)(iVar4 + 9)) {
        (**(code **)(iVar6 + 4))(iVar5);
        goto LAB_08024340;
      }
    }
    else {
      if (*(char *)(iVar4 + 10) == '\x01') {
        (**(code **)(iVar6 + 4))(iVar5);
        *(undefined1 *)(iVar4 + 10) = 0;
        *(undefined1 *)(iVar4 + 0xb) = 0;
      }
LAB_08024340:
      *(undefined1 *)(iVar4 + 8) = 0;
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0xc;
    if (iVar5 == 3) {
      return;
    }
  } while( true );
}


// 080242fc push {r3,r4,r5,r6,r7,r8,r9,lr}
// 08024300 movs r5,#0x0
// 08024302 ldr r4,[0x08024358]
// 08024304 mov.w r9,#0xc
// 08024308 mov r7,r4
// 0802430a mov r6,r5
// 0802430c mul r3,r9,r5
// 08024310 add.w r8,r7,r3
// 08024314 ldr r3,[r7,r3]
// 08024316 blx r3
// 08024318 cmp r0,#0x1
// 0802431a bne 0x08024344
// 0802431c ldrb r3,[r4,#0x8]
// 0802431e ldrb r2,[r4,#0x9]
// 08024320 cmp r3,r2
// 08024322 bcs 0x08024336
// 08024324 adds r3,#0x1
// 08024326 strb r3,[r4,#0x8]
// 08024328 adds r5,#0x1
// 0802432a cmp r5,#0x3
// 0802432c add.w r4,r4,#0xc
// 08024330 bne 0x0802430c
// 08024332 pop.w {r3,r4,r5,r6,r7,r8,r9,pc}
// 08024336 bne 0x08024328
// 08024338 mov r0,r5
// 0802433a ldr.w r3,[r8,#0x4]
// 0802433e blx r3
// 08024340 strb r6,[r4,#0x8]
// 08024342 b 0x08024328
// 08024344 ldrb r3,[r4,#0xa]
// 08024346 cmp r3,#0x1
// 08024348 bne 0x08024340
// 0802434a mov r0,r5
// 0802434c ldr.w r3,[r8,#0x4]
// 08024350 blx r3
// 08024352 strb r6,[r4,#0xa]
// 08024354 strb r6,[r4,#0xb]
// 08024356 b 0x08024340
// FUNCTION 08024190

void FUN_08024190(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  
  FUN_08026e04(2);
  FUN_08034d64(DAT_080242f0);
  FUN_0802ca7c();
  sVar6 = 8;
  do {
    FUN_0802c61c(sVar6,1);
    FUN_0802c41c(0,0xec,0x2b,0x24);
    sVar7 = sVar6 + 1;
    FUN_0802c2a8(sVar6,1);
    sVar6 = sVar7;
  } while (sVar7 != 0xc);
  FUN_0802c32c(8);
  FUN_0802c32c(9);
  FUN_0802c32c(10);
  FUN_0802c32c(0xb);
  uVar3 = DAT_080242f8;
  puVar2 = DAT_080242f4;
  uVar1 = DAT_080242f0;
  uVar9 = 0;
  uVar11 = 7;
  do {
    iVar4 = FUN_0802b814(7);
    if ((iVar4 == 0) && (iVar4 = FUN_0802b814(8), iVar4 == 0)) {
      uVar9 = uVar9 + 1 & 0xff;
      if (uVar9 < 0x3c) {
        uVar8 = uVar9 / 10;
        if (uVar11 == uVar8) goto LAB_080242d8;
      }
      else {
        if (uVar11 == 6) {
LAB_0802423c:
          FUN_08034d6e(DAT_080242f0);
          FUN_0802c61c(0xc,10);
          FUN_0802c61c(0xd,10);
          FUN_0802c41c(0,0xec,0x2b,0x24);
          FUN_0802c2a8(0xc,3);
          FUN_0802c2a8(0xd,3);
          FUN_0802c32c(0xc);
          FUN_0802c32c(0xd);
          FUN_08034d64(DAT_080242f0);
          FUN_0802aec4(1);
          thunk_FUN_0802fec8(3000);
          FUN_08034d6e(DAT_080242f0);
          FUN_0802ca7c();
          thunk_FUN_0802fec8(2000);
          FUN_08029894(0);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uVar8 = 6;
        uVar9 = 0x3c;
      }
      FUN_08034d6e(uVar1);
      FUN_0802bf7c(puVar2[uVar8],uVar3);
      FUN_0802bf7c(puVar2[uVar8 + 7],uVar3);
      FUN_08034d64(uVar1);
      if (uVar9 == 0x3c) goto LAB_0802423c;
    }
    else {
      uVar8 = uVar11;
      if (uVar11 != 7) {
        FUN_08034d6e(uVar1);
        cVar5 = '\0';
        puVar10 = DAT_080242f4;
        do {
          cVar5 = cVar5 + '\x01';
          FUN_0802bf7c(*puVar10,0);
          FUN_0802bf7c(puVar10[7],0);
          puVar10 = puVar10 + 1;
        } while (cVar5 != '\a');
        FUN_08034d64(uVar1);
        uVar8 = 7;
      }
      uVar9 = 0;
    }
LAB_080242d8:
    thunk_FUN_0802fec8(0x32);
    uVar11 = uVar8;
  } while( true );
}


// 08024190 push {r3,r4,r5,r6,r7,r8,r9,lr}
// 08024194 movs r0,#0x2
// 08024196 bl 0x08026e04
// 0802419a ldr r0,[0x080242f0]
// 0802419c bl 0x08034d64
// 080241a0 movs r4,#0x8
// 080241a2 bl 0x0802ca7c
// 080241a6 movs r1,#0x1
// 080241a8 mov r0,r4
// 080241aa bl 0x0802c61c
// 080241ae movs r3,#0x24
// 080241b0 movs r2,#0x2b
// 080241b2 movs r1,#0xec
// 080241b4 movs r0,#0x0
// 080241b6 bl 0x0802c41c
// 080241ba mov r0,r4
// 080241bc adds r4,#0x1
// 080241be movs r1,#0x1
// 080241c0 uxth r4,r4
// 080241c2 bl 0x0802c2a8
// 080241c6 cmp r4,#0xc
// 080241c8 bne 0x080241a6
// 080241ca movs r0,#0x8
// 080241cc bl 0x0802c32c
// 080241d0 movs r0,#0x9
// 080241d2 bl 0x0802c32c
// 080241d6 movs r0,#0xa
// 080241d8 bl 0x0802c32c
// 080241dc movs r0,#0xb
// 080241de bl 0x0802c32c
// 080241e2 movs r6,#0x7
// 080241e4 movs r5,#0x0
// 080241e6 ldr r7,[0x080242f0]
// 080241e8 ldr.w r8,[0x080242f4]
// 080241ec ldr.w r9,[0x080242f8]
// 080241f0 movs r0,#0x7
// 080241f2 bl 0x0802b814
// 080241f6 cmp r0,#0x0
// 080241f8 bne 0x080242a8
// 080241fa movs r0,#0x8
// 080241fc bl 0x0802b814
// 08024200 cmp r0,#0x0
// 08024202 bne 0x080242a8
// 08024204 adds r5,#0x1
// 08024206 uxtb r5,r5
// 08024208 cmp r5,#0x3b
// 0802420a bhi 0x080242e6
// 0802420c movs r4,#0xa
// 0802420e udiv r4,r5,r4
// 08024212 cmp r6,r4
// 08024214 beq 0x080242d8
// 08024216 mov r0,r7
// 08024218 bl 0x08034d6e
// 0802421c mov r1,r9
// 0802421e ldrb.w r0,[r8,r4]
// 08024222 bl 0x0802bf7c
// 08024226 add.w r3,r8,r4
// 0802422a ldrb r0,[r3,#0x7]
// 0802422c mov r1,r9
// 0802422e bl 0x0802bf7c
// 08024232 mov r0,r7
// 08024234 bl 0x08034d64
// 08024238 cmp r5,#0x3c
// 0802423a bne 0x080242d8
// 0802423c ldr r0,[0x080242f0]
// 0802423e bl 0x08034d6e
// 08024242 movs r1,#0xa
// 08024244 movs r0,#0xc
// 08024246 bl 0x0802c61c
// 0802424a movs r1,#0xa
// 0802424c movs r0,#0xd
// 0802424e bl 0x0802c61c
// 08024252 movs r3,#0x24
// 08024254 movs r2,#0x2b
// 08024256 movs r1,#0xec
// 08024258 movs r0,#0x0
// 0802425a bl 0x0802c41c
// 0802425e movs r1,#0x3
// 08024260 movs r0,#0xc
// 08024262 bl 0x0802c2a8
// 08024266 movs r1,#0x3
// 08024268 movs r0,#0xd
// 0802426a bl 0x0802c2a8
// 0802426e movs r0,#0xc
// 08024270 bl 0x0802c32c
// 08024274 movs r0,#0xd
// 08024276 bl 0x0802c32c
// 0802427a ldr r0,[0x080242f0]
// 0802427c bl 0x08034d64
// 08024280 movs r0,#0x1
// 08024282 bl 0x0802aec4
// 08024286 movw r0,#0xbb8
// 0802428a bl 0x080273a4
// 0802428e ldr r0,[0x080242f0]
// 08024290 bl 0x08034d6e
// 08024294 bl 0x0802ca7c
// 08024298 mov.w r0,#0x7d0
// 0802429c bl 0x080273a4
// 080242a0 movs r0,#0x0
// 080242a2 bl 0x08029894
// 080242a6 b 0x080242a6
// 080242a8 cmp r6,#0x7
// 080242aa beq 0x080242e2
// 080242ac mov r0,r7
// 080242ae bl 0x08034d6e
// 080242b2 movs r4,#0x0
// 080242b4 ldr r5,[0x080242f4]
// 080242b6 ldrb.w r0,[r5],#0x1
// 080242ba movs r1,#0x0
// 080242bc adds r4,#0x1
// 080242be bl 0x0802bf7c
// 080242c2 uxtb r4,r4
// 080242c4 movs r1,#0x0
// 080242c6 ldrb r0,[r5,#0x6]
// 080242c8 bl 0x0802bf7c
// 080242cc cmp r4,#0x7
// 080242ce bne 0x080242b6
// 080242d0 mov r0,r7
// 080242d2 bl 0x08034d64
// 080242d6 movs r5,#0x0
// 080242d8 movs r0,#0x32
// 080242da bl 0x080273a4
// 080242de mov r6,r4
// 080242e0 b 0x080241f0
// 080242e2 mov r4,r6
// 080242e4 b 0x080242d6
// 080242e6 cmp r6,#0x6
// 080242e8 beq 0x0802423c
// 080242ea movs r4,#0x6
// 080242ec movs r5,#0x3c
// 080242ee b 0x08024216
// FUNCTION 0802652c

void FUN_0802652c(void)

{
  int iVar1;
  
  iVar1 = DAT_08026544;
  FUN_0802f1d0(DAT_08026544,0,0x162);
  *(undefined1 *)(iVar1 + 0x161) = 0;
  return;
}


// 0802652c push {r4,lr}
// 0802652e ldr r4,[0x08026544]
// 08026530 mov.w r2,#0x162
// 08026534 movs r1,#0x0
// 08026536 mov r0,r4
// 08026538 bl 0x0802f1d0
// 0802653c movs r3,#0x0
// 0802653e strb.w r3,[r4,#0x161]
// 08026542 pop {r4,pc}
// FUNCTION 08026c08

undefined4 FUN_08026c08(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  FUN_08026f90();
  FUN_08026e60(param_4);
  FUN_08029824(0);
  FUN_080298fe(0,*(undefined4 *)(param_3 + 0x104));
  FUN_08026fcc();
  FUN_08026f08();
  FUN_080270e6();
  if (*(code **)(param_3 + 0x100) != (code *)0x0) {
    (**(code **)(param_3 + 0x100))(*(undefined4 *)(DAT_08026c48 + 0x20));
  }
  return 0;
}


// 08026c08 push {r0,r1,r4,lr}
// 08026c0a mov r4,r2
// 08026c0c str r3,[sp,#0x4]
// 08026c0e bl 0x08026f90
// 08026c12 ldr r0,[sp,#0x4]
// 08026c14 bl 0x08026e60
// 08026c18 movs r0,#0x0
// 08026c1a bl 0x08029824
// 08026c1e ldr.w r1,[r4,#0x104]
// 08026c22 movs r0,#0x0
// 08026c24 bl 0x080298fe
// 08026c28 bl 0x08026fcc
// 08026c2c bl 0x08026f08
// 08026c30 bl 0x080270e6
// 08026c34 ldr.w r3,[r4,#0x100]
// 08026c38 cbz r3,0x08026c40
// 08026c3a ldr r2,[0x08026c48]
// 08026c3c ldr r0,[r2,#0x20]
// 08026c3e blx r3
// 08026c40 movs r0,#0x0
// 08026c42 add sp,#0x8
// 08026c44 pop {r4,pc}
