// FUNCTION 08023a7c

void FUN_08023a7c(undefined4 param_1,uint3 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  undefined4 uStack_24;
  
  uStack_24 = (uint)param_2;
  FUN_08023308(DAT_08023be4);
  uVar3 = DAT_08023bf4;
  iVar1 = DAT_08023be8;
  do {
    puVar4 = DAT_08023bf8;
    uVar2 = DAT_08023bf0;
    if (*(int *)(*(int *)(iVar1 + 0x34) + 0x50) == 0) {
      return;
    }
    bVar7 = 0;
    while( true ) {
      uVar6 = (uint)bVar7;
      if (*(int *)(iVar1 + 0x60) <= (int)uVar6) break;
      iVar5 = uVar6 * 0x13c + *(int *)(iVar1 + 100);
      if (*(int *)(iVar5 + 0x120) == 1) {
        FUN_08023308(DAT_08023bec,uVar6,0x13c,iVar5,param_1);
        FUN_08026e04(0);
        FUN_08029290(0,uVar6,1);
        FUN_08026e38(0);
        FUN_08026e04(2);
        iVar5 = uVar6 + 8;
        FUN_08034d64(uVar2);
        FUN_0802c498(iVar5,0);
        FUN_0802c61c(iVar5,7);
        FUN_0802c41c(0,0xd3,0x20,0x29);
        FUN_0802c2a8(iVar5,9);
        FUN_0802c32c(iVar5);
        while( true ) {
          FUN_0802c3f4(iVar5,(int)&uStack_24 + 3);
          if (uStack_24._3_1_ == '\x01') break;
          thunk_FUN_0802fec8(0x32);
        }
LAB_08023b20:
        FUN_0802c3b8(uVar6 + 8);
        FUN_08034d6e(uVar2);
        FUN_08026e38(2);
        FUN_08027200(*puVar4,1);
        thunk_FUN_0802fec8(0x32);
      }
      else if (*(int *)(iVar5 + 0x130) == 1) {
        FUN_08023308(uVar3,uVar6,0x13c,iVar5,param_1);
        FUN_08026e04(0);
        FUN_08029290(0,uVar6);
        FUN_08026e38(0);
        FUN_08026e04(2);
        iVar5 = uVar6 + 8;
        FUN_08034d64(uVar2);
        FUN_0802c498(iVar5,1);
        FUN_0802c61c(iVar5,7);
        FUN_0802c41c(0,0xd3,0x20,0x29);
        FUN_0802c2a8(iVar5,9);
        FUN_0802c32c(iVar5);
        while( true ) {
          FUN_0802c3f4(iVar5,(int)&uStack_24 + 3);
          if (uStack_24._3_1_ == '\x01') break;
          thunk_FUN_0802fec8(0x32);
        }
        goto LAB_08023b20;
      }
      bVar7 = bVar7 + 1;
    }
    thunk_FUN_0802fec8(0x14);
  } while( true );
}


// 08023a7c movs r3,#0x0
// 08023a7e push {r0,r1,r4,r5,r6,r7,r8,r9,r10,lr}
// 08023a82 ldr r0,[0x08023be4]
// 08023a84 strb.w r3,[sp,#0x7]
// 08023a88 bl 0x08023308
// 08023a8c ldr r6,[0x08023be8]
// 08023a8e ldr.w r9,[0x08023bf4]
// 08023a92 ldr r3,[r6,#0x34]
// 08023a94 ldr r3,[r3,#0x50]
// 08023a96 cmp r3,#0x0
// 08023a98 bne.w 0x08023bd8
// 08023a9c add sp,#0x8
// 08023a9e pop.w {r4,r5,r6,r7,r8,r9,r10,pc}
// 08023aa2 mov.w r2,#0x13c
// 08023aa6 ldr r3,[r6,#0x64]
// 08023aa8 mla r3,r2,r4,r3
// 08023aac ldr.w r10,[r3,#0x120]
// 08023ab0 cmp.w r10,#0x1
// 08023ab4 bne 0x08023b5c
// 08023ab6 mov r1,r4
// 08023ab8 ldr r0,[0x08023bec]
// 08023aba bl 0x08023308
// 08023abe movs r0,#0x0
// 08023ac0 bl 0x08026e04
// 08023ac4 mov r2,r10
// 08023ac6 mov r1,r4
// 08023ac8 movs r0,#0x0
// 08023aca bl 0x08029290
// 08023ace movs r0,#0x0
// 08023ad0 bl 0x08026e38
// 08023ad4 movs r0,#0x2
// 08023ad6 bl 0x08026e04
// 08023ada adds r4,#0x8
// 08023adc mov r0,r5
// 08023ade bl 0x08034d64
// 08023ae2 movs r1,#0x0
// 08023ae4 mov r0,r4
// 08023ae6 bl 0x0802c498
// 08023aea movs r1,#0x7
// 08023aec mov r0,r4
// 08023aee bl 0x0802c61c
// 08023af2 movs r3,#0x29
// 08023af4 movs r2,#0x20
// 08023af6 movs r1,#0xd3
// 08023af8 movs r0,#0x0
// 08023afa bl 0x0802c41c
// 08023afe movs r1,#0x9
// 08023b00 mov r0,r4
// 08023b02 bl 0x0802c2a8
// 08023b06 mov r0,r4
// 08023b08 bl 0x0802c32c
// 08023b0c mov r0,r4
// 08023b0e add.w r1,sp,#0x7
// 08023b12 bl 0x0802c3f4
// 08023b16 ldrb.w r10,[sp,#0x7]
// 08023b1a cmp.w r10,#0x1
// 08023b1e bne 0x08023b54
// 08023b20 mov r0,r4
// 08023b22 bl 0x0802c3b8
// 08023b26 mov r0,r5
// 08023b28 bl 0x08034d6e
// 08023b2c movs r0,#0x2
// 08023b2e bl 0x08026e38
// 08023b32 mov r1,r10
// 08023b34 ldr.w r0,[r8,#0x0]
// 08023b38 bl 0x08027200
// 08023b3c movs r0,#0x32
// 08023b3e bl 0x080273a4
// 08023b42 adds r7,#0x1
// 08023b44 ldr r3,[r6,#0x60]
// 08023b46 uxtb r4,r7
// 08023b48 cmp r4,r3
// 08023b4a blt 0x08023aa2
// 08023b4c movs r0,#0x14
// 08023b4e bl 0x080273a4
// 08023b52 b 0x08023a92
// 08023b54 movs r0,#0x32
// 08023b56 bl 0x080273a4
// 08023b5a b 0x08023b0c
// 08023b5c ldr.w r10,[r3,#0x130]
// 08023b60 cmp.w r10,#0x1
// 08023b64 bne 0x08023b42
// 08023b66 mov r1,r4
// 08023b68 mov r0,r9
// 08023b6a bl 0x08023308
// 08023b6e movs r0,#0x0
// 08023b70 bl 0x08026e04
// 08023b74 movs r2,#0x0
// 08023b76 mov r1,r4
// 08023b78 mov r0,r2
// 08023b7a bl 0x08029290
// 08023b7e movs r0,#0x0
// 08023b80 bl 0x08026e38
// 08023b84 movs r0,#0x2
// 08023b86 bl 0x08026e04
// 08023b8a adds r4,#0x8
// 08023b8c mov r0,r5
// 08023b8e bl 0x08034d64
// 08023b92 mov r1,r10
// 08023b94 mov r0,r4
// 08023b96 bl 0x0802c498
// 08023b9a movs r1,#0x7
// 08023b9c mov r0,r4
// 08023b9e bl 0x0802c61c
// 08023ba2 movs r3,#0x29
// 08023ba4 movs r2,#0x20
// 08023ba6 movs r1,#0xd3
// 08023ba8 movs r0,#0x0
// 08023baa bl 0x0802c41c
// 08023bae movs r1,#0x9
// 08023bb0 mov r0,r4
// 08023bb2 bl 0x0802c2a8
// 08023bb6 mov r0,r4
// 08023bb8 bl 0x0802c32c
// 08023bbc mov r0,r4
// 08023bbe add.w r1,sp,#0x7
// 08023bc2 bl 0x0802c3f4
// 08023bc6 ldrb.w r10,[sp,#0x7]
// 08023bca cmp.w r10,#0x1
// 08023bce beq 0x08023b20
// 08023bd0 movs r0,#0x32
// 08023bd2 bl 0x080273a4
// 08023bd6 b 0x08023bbc
// 08023bd8 movs r7,#0x0
// 08023bda ldr r5,[0x08023bf0]
// 08023bdc ldr.w r8,[0x08023bf8]
// 08023be0 b 0x08023b44
// FUNCTION 08023bfc

bool FUN_08023bfc(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_0802b814(7);
  if (iVar2 == 0) {
    iVar2 = FUN_0802b814(8);
    bVar1 = iVar2 == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// 08023bfc push {r3,lr}
// 08023bfe movs r0,#0x7
// 08023c00 bl 0x0802b814
// 08023c04 cbnz r0,0x08023c14
// 08023c06 movs r0,#0x8
// 08023c08 bl 0x0802b814
// 08023c0c clz r0,r0
// 08023c10 lsrs r0,r0,#0x5
// 08023c12 pop {r3,pc}
// 08023c14 movs r0,#0x0
// 08023c16 b 0x08023c12
// FUNCTION 08023c18

bool FUN_08023c18(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_0802cef0();
  bVar2 = false;
  if (iVar1 != 0) {
    if (*(int *)(*(int *)(DAT_08023c3c + 0x34) + 0x10) == 1) {
      bVar2 = *(int *)(*(int *)(DAT_08023c3c + 0x34) + 0x88) == 1;
    }
    else {
      bVar2 = false;
    }
  }
  return bVar2;
}


// 08023c18 push {r3,lr}
// 08023c1a bl 0x0802cef0
// 08023c1e cbz r0,0x08023c34
// 08023c20 ldr r3,[0x08023c3c]
// 08023c22 ldr r3,[r3,#0x34]
// 08023c24 ldr r2,[r3,#0x10]
// 08023c26 cmp r2,#0x1
// 08023c28 bne 0x08023c36
// 08023c2a ldr.w r0,[r3,#0x88]
// 08023c2e subs r3,r0,#0x1
// 08023c30 rsbs r0,r3
// 08023c32 adcs r0,r3
// 08023c34 pop {r3,pc}
// 08023c36 movs r0,#0x0
// 08023c38 b 0x08023c34
// FUNCTION 08023c40

void FUN_08023c40(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_0802cef0();
  if (iVar1 == 0) {
    return;
  }
  FUN_08026bcc(0x243);
  FUN_08023308(DAT_08023d1c);
  FUN_08026e04(2);
  FUN_08034d64(DAT_08023d20);
  uVar3 = 0;
  FUN_0802ca7c();
  do {
    uVar4 = uVar3 & 0xffff;
    FUN_0802c61c(uVar4,1);
    FUN_0802c41c(0,0xff,0xff);
    uVar3 = uVar3 + 1;
    FUN_0802c2a8(uVar4,1);
  } while (uVar3 != 0xe);
  uVar3 = 0;
  do {
    uVar4 = uVar3 & 0xffff;
    uVar3 = uVar3 + 1;
    FUN_0802c32c(uVar4);
  } while (uVar3 != 0xe);
  FUN_0802d32c(1);
  thunk_FUN_0802fec8(1000);
  iVar1 = DAT_08023d24;
  do {
    FUN_0802d32c(2);
    uVar3 = 0;
    do {
      iVar2 = FUN_0802b814(uVar3 & 0xff);
      if ((iVar2 == 0) || (*(char *)(iVar1 + 0xb) == '\x01')) {
        FUN_08023308(DAT_08023d28);
        FUN_08026e04(0);
        FUN_0802d32c(3);
        FUN_08026e38(0);
        uVar3 = 0;
        do {
          uVar4 = uVar3 & 0xffff;
          uVar3 = uVar3 + 1;
          FUN_0802c3b8(uVar4);
        } while (uVar3 != 0xe);
        FUN_08034d6e(DAT_08023d20);
        FUN_08026e38(2);
        FUN_08026bcc(0x240);
        FUN_08027200(*DAT_08023d2c,1);
        return;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x10);
    thunk_FUN_0802fec8(5);
  } while( true );
}


// 08023c40 push {r3,r4,r5,lr}
// 08023c42 bl 0x0802cef0
// 08023c46 cmp r0,#0x0
// 08023c48 beq 0x08023d18
// 08023c4a movw r0,#0x243
// 08023c4e bl 0x08026bcc
// 08023c52 ldr r0,[0x08023d1c]
// 08023c54 bl 0x08023308
// 08023c58 movs r0,#0x2
// 08023c5a bl 0x08026e04
// 08023c5e ldr r0,[0x08023d20]
// 08023c60 bl 0x08034d64
// 08023c64 movs r4,#0x0
// 08023c66 bl 0x0802ca7c
// 08023c6a uxth r5,r4
// 08023c6c movs r1,#0x1
// 08023c6e mov r0,r5
// 08023c70 bl 0x0802c61c
// 08023c74 movs r3,#0xff
// 08023c76 movs r0,#0x0
// 08023c78 mov r1,r3
// 08023c7a mov r2,r3
// 08023c7c bl 0x0802c41c
// 08023c80 adds r4,#0x1
// 08023c82 movs r1,#0x1
// 08023c84 mov r0,r5
// 08023c86 bl 0x0802c2a8
// 08023c8a cmp r4,#0xe
// 08023c8c bne 0x08023c6a
// 08023c8e movs r4,#0x0
// 08023c90 uxth r0,r4
// 08023c92 adds r4,#0x1
// 08023c94 bl 0x0802c32c
// 08023c98 cmp r4,#0xe
// 08023c9a bne 0x08023c90
// 08023c9c movs r0,#0x1
// 08023c9e bl 0x0802d32c
// 08023ca2 mov.w r0,#0x3e8
// 08023ca6 bl 0x080273a4
// 08023caa ldr r5,[0x08023d24]
// 08023cac movs r0,#0x2
// 08023cae bl 0x0802d32c
// 08023cb2 movs r4,#0x0
// 08023cb4 uxtb r0,r4
// 08023cb6 bl 0x0802b814
// 08023cba cbz r0,0x08023cc2
// 08023cbc ldrb r3,[r5,#0xb]
// 08023cbe cmp r3,#0x1
// 08023cc0 bne 0x08023d0a
// 08023cc2 ldr r0,[0x08023d28]
// 08023cc4 bl 0x08023308
// 08023cc8 movs r0,#0x0
// 08023cca bl 0x08026e04
// 08023cce movs r0,#0x3
// 08023cd0 bl 0x0802d32c
// 08023cd4 movs r0,#0x0
// 08023cd6 bl 0x08026e38
// 08023cda movs r4,#0x0
// 08023cdc uxth r0,r4
// 08023cde adds r4,#0x1
// 08023ce0 bl 0x0802c3b8
// 08023ce4 cmp r4,#0xe
// 08023ce6 bne 0x08023cdc
// 08023ce8 ldr r0,[0x08023d20]
// 08023cea bl 0x08034d6e
// 08023cee movs r0,#0x2
// 08023cf0 bl 0x08026e38
// 08023cf4 mov.w r0,#0x240
// 08023cf8 bl 0x08026bcc
// 08023cfc ldr r3,[0x08023d2c]
// 08023cfe movs r1,#0x1
// 08023d00 ldr r0,[r3,#0x0]
// 08023d02 pop.w {r3,r4,r5,lr}
// 08023d06 b.w 0x08027200
// 08023d0a adds r4,#0x1
// 08023d0c cmp r4,#0x10
// 08023d0e bne 0x08023cb4
// 08023d10 movs r0,#0x5
// 08023d12 bl 0x080273a4
// 08023d16 b 0x08023cac
// 08023d18 pop {r3,r4,r5,pc}
