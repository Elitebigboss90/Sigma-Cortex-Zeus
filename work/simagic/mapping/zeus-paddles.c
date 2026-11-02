// FUNCTION 0802cf70

void FUN_0802cf70(uint param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  
  puVar2 = DAT_0802d298;
  *DAT_0802d298 = param_1;
  *(char *)(puVar2 + 1) = (char)param_2;
  uVar5 = DAT_0802d29c;
  *(undefined1 *)((int)puVar2 + 5) = 0;
  *(undefined1 *)((int)puVar2 + 6) = 0;
  *(undefined1 *)((int)puVar2 + 0xd) = 0xff;
  *(undefined1 *)((int)puVar2 + 0xe) = 0xff;
  *(undefined1 *)((int)puVar2 + 0x2f) = 0;
  *(undefined1 *)(puVar2 + 0xc) = 0;
  *(undefined1 *)((int)puVar2 + 0x31) = 0;
  *(undefined1 *)((int)puVar2 + 0x42) = 0;
  *(undefined1 *)((int)puVar2 + 0x43) = 0;
  *(undefined1 *)(puVar2 + 0x11) = 0;
  *(undefined1 *)((int)puVar2 + 0x45) = 0;
  *(undefined1 *)((int)puVar2 + 0x46) = 0;
  *(undefined1 *)((int)puVar2 + 0x47) = 0;
  *(undefined1 *)(puVar2 + 0x12) = 0;
  *(undefined1 *)((int)puVar2 + 0x49) = 0;
  *(undefined2 *)((int)puVar2 + 0x27) = 0;
  *(undefined2 *)((int)puVar2 + 0x29) = 0;
  *(undefined2 *)((int)puVar2 + 0x2b) = 0;
  *(undefined2 *)((int)puVar2 + 0x2d) = 0;
  FUN_08035d8c(uVar5,0,0x19,0xff,param_1,param_2,param_3);
  for (uVar8 = 0; uVar3 = uVar8 & 0xff, uVar3 < (byte)puVar2[1]; uVar8 = uVar8 + 1) {
    FUN_0802ce44(uVar3 * 0x90 + *puVar2,uVar3 + 1,uVar3 + 1,0xffffffff,0xffffffff);
  }
  FUN_0802ae20(6,DAT_0802d2a0,0);
  FUN_0802ae20(7,DAT_0802d2a4,0);
  FUN_0802ae20(8,DAT_0802d2a8,0);
  FUN_0802ae20(9,DAT_0802d2ac,0);
  uVar8 = FUN_08029b9c(2);
  if (uVar8 == 0) {
    iVar4 = FUN_08029b9c(1);
    if (iVar4 == 0) {
      *(undefined1 *)((int)puVar2 + 5) = 0;
    }
    else {
LAB_0802d014:
      *(undefined1 *)((int)puVar2 + 5) = 2;
LAB_0802d018:
      FUN_0802ce44(*puVar2,1,1,0,0);
      uVar5 = 2;
      uVar6 = 1;
      uVar11 = 1;
      iVar4 = *puVar2 + 0x90;
LAB_0802d034:
      FUN_0802ce44(iVar4,uVar5,uVar5,0,uVar11);
      *(undefined1 *)((int)puVar2 + 0xd) = uVar6;
    }
  }
  else {
    if (0x174 < uVar8 - 0xe8b) {
      if (uVar8 < 0x175) goto LAB_0802d014;
      if (uVar8 - 0x83e < 0x2e9) {
        *(undefined1 *)((int)puVar2 + 5) = 4;
        goto LAB_0802d018;
      }
      if (0x2e8 < uVar8 - 0x365) goto LAB_0802d058;
      uVar5 = 3;
      *(undefined1 *)((int)puVar2 + 5) = 3;
      FUN_0802ce44(*puVar2,1,1,0,0);
      uVar6 = 2;
      FUN_0802ce44(*puVar2 + 0x90,2,2,0,1);
      uVar11 = 2;
      iVar4 = *puVar2 + 0x120;
      goto LAB_0802d034;
    }
    *(undefined1 *)((int)puVar2 + 5) = 1;
    FUN_0802ce44(*puVar2,1,1,0,0);
  }
LAB_0802d058:
  uVar8 = FUN_08029b9c(6);
  if (uVar8 == 0) {
    iVar4 = FUN_08029b9c(5);
    if (iVar4 == 0) {
      *(undefined1 *)((int)puVar2 + 6) = 0;
      goto LAB_0802d086;
    }
LAB_0802d070:
    *(undefined1 *)((int)puVar2 + 6) = 1;
    FUN_0802ce44(*puVar2 + 0x1b0,4,4,1,0);
  }
  else {
    if (uVar8 < 0x175) goto LAB_0802d070;
    if (uVar8 - 0xe8b < 0x175) {
      *(undefined1 *)((int)puVar2 + 6) = 2;
      FUN_0802ce44(*puVar2 + 0x1b0,4,4,1,0);
      FUN_0802ce44(*puVar2 + 0x240,5,5,1,1);
      uVar6 = 4;
LAB_0802d1f6:
      *(undefined1 *)((int)puVar2 + 0xe) = uVar6;
    }
    else if (uVar8 - 0x365 < 0x2e9) {
      *(undefined1 *)((int)puVar2 + 6) = 4;
      FUN_0802ce44(*puVar2 + 0x1b0,4,4,1,0);
      FUN_0802ce44(*puVar2 + 0x240,5,5,1,1);
      *(undefined1 *)((int)puVar2 + 0xe) = 4;
    }
    else if (uVar8 - 0x83e < 0x2e9) {
      *(undefined1 *)((int)puVar2 + 6) = 3;
      FUN_0802ce44(*puVar2 + 0x1b0,4,4,1,0);
      FUN_0802ce44(*puVar2 + 0x240,5,5,1,1);
      FUN_0802ce44(*puVar2 + 0x2d0,6,6,1,2);
      uVar6 = 5;
      goto LAB_0802d1f6;
    }
  }
LAB_0802d086:
  FUN_0802ce68(DAT_0802d2b0 + -3);
  uVar5 = FUN_08029b9c(0);
  *(undefined4 *)((int)puVar2 + 0xf) = uVar5;
  uVar5 = FUN_08029b9c(1);
  *(undefined4 *)((int)puVar2 + 0x13) = uVar5;
  uVar5 = FUN_08029b9c(3);
  *(undefined4 *)((int)puVar2 + 0x17) = uVar5;
  uVar5 = FUN_08029b9c(4);
  *(undefined4 *)((int)puVar2 + 0x1b) = uVar5;
  uVar5 = FUN_08029b9c(5);
  *(undefined4 *)((int)puVar2 + 0x1f) = uVar5;
  uVar10 = FUN_08029b9c(7);
  uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar7 = (uint)*(byte *)((int)puVar2 + 5);
  *(int *)((int)puVar2 + 0x23) = (int)uVar10;
  uVar3 = uVar7 - 1;
  uVar8 = uVar3;
  if (uVar3 < 2) {
    uVar5 = 0xd;
    uVar8 = *puVar2;
  }
  if (uVar3 < 2) {
    *(undefined4 *)(uVar8 + 0x68) = uVar5;
  }
  uVar8 = (uint)*(byte *)((int)puVar2 + 6);
  if (uVar8 - 1 < 2) {
    *(undefined4 *)(*puVar2 + 0x218) = 0xe;
    if (uVar7 == 3) {
LAB_0802d0f0:
      uVar3 = *puVar2;
      *(undefined4 *)(uVar3 + 0x68) = 0x29;
      *(undefined4 *)(uVar3 + 0xf8) = 0xd;
      if (uVar8 == 3) goto LAB_0802d102;
    }
    else {
LAB_0802d290:
      if (uVar7 == 4) goto LAB_0802d118;
    }
LAB_0802d128:
    if (uVar8 != 4) goto LAB_0802d2d0;
    if ((char)puVar2[0xc] == '\0') goto LAB_0802d2c2;
    bVar9 = (char)puVar2[0xc] == '\x01';
LAB_0802d31c:
    if (!bVar9) goto LAB_0802d2d0;
    uVar3 = *puVar2;
    *(undefined4 *)(uVar3 + 0x218) = 0xe;
    uVar5 = 0xd;
  }
  else {
    if (uVar7 == 3) goto LAB_0802d0f0;
    if (uVar8 != 3) goto LAB_0802d290;
LAB_0802d102:
    uVar3 = *puVar2;
    *(undefined4 *)(uVar3 + 0x218) = 0x2a;
    *(undefined4 *)(uVar3 + 0x2a8) = 0xe;
    if (uVar7 != 4) goto LAB_0802d2d0;
LAB_0802d118:
    if ((char)puVar2[0xc] != '\0') {
      if ((char)puVar2[0xc] != '\x01') goto LAB_0802d128;
      uVar3 = *puVar2;
      bVar9 = uVar8 == 4;
      *(undefined4 *)(uVar3 + 0x68) = 0xd;
      *(undefined4 *)(uVar3 + 0x6c) = 0xe;
      goto LAB_0802d31c;
    }
    uVar3 = *puVar2;
    *(undefined4 *)(uVar3 + 0x68) = 0xd;
    *(undefined4 *)(uVar3 + 0x6c) = 0x29;
    if (uVar8 != 4) goto LAB_0802d2d0;
LAB_0802d2c2:
    uVar3 = *puVar2;
    *(undefined4 *)(uVar3 + 0x218) = 0xe;
    uVar5 = 0x2a;
  }
  *(undefined4 *)(uVar3 + 0x21c) = uVar5;
LAB_0802d2d0:
  if (uVar7 - 2 < 3) {
    bVar1 = *(byte *)((int)puVar2 + 0xd);
    uVar10 = FUN_0802cf50((uint)bVar1);
    uVar8 = (uint)((ulonglong)uVar10 >> 0x20);
    if ((int)uVar10 != 0) {
      *(undefined4 *)(*puVar2 + (uint)bVar1 * 0x90 + 0x68) = 0x1b;
    }
  }
  if (uVar8 - 2 < 3) {
    uVar10 = FUN_0802cf50(*(undefined1 *)((int)puVar2 + 0xe));
    if ((int)uVar10 != 0) {
      *(undefined4 *)(*puVar2 + (int)((ulonglong)uVar10 >> 0x20) * 0x90 + 0x68) = 0x18;
    }
  }
  return;
}


// 0802cf70 push {r0,r1,r2,r4,r5,r6,r7,lr}
// 0802cf72 movs r5,#0x0
// 0802cf74 movs r3,#0xff
// 0802cf76 ldr r4,[0x0802d298]
// 0802cf78 movs r2,#0x19
// 0802cf7a str r0,[r4,#0x0]
// 0802cf7c strb r1,[r4,#0x4]
// 0802cf7e ldr r0,[0x0802d29c]
// 0802cf80 mov r1,r5
// 0802cf82 strb r5,[r4,#0x5]
// 0802cf84 strb r5,[r4,#0x6]
// 0802cf86 strb r3,[r4,#0xd]
// 0802cf88 strb r3,[r4,#0xe]
// 0802cf8a strb.w r5,[r4,#0x2f]
// 0802cf8e strb.w r5,[r4,#0x30]
// 0802cf92 strb.w r5,[r4,#0x31]
// 0802cf96 strb.w r5,[r4,#0x42]
// 0802cf9a strb.w r5,[r4,#0x43]
// 0802cf9e strb.w r5,[r4,#0x44]
// 0802cfa2 strb.w r5,[r4,#0x45]
// 0802cfa6 strb.w r5,[r4,#0x46]
// 0802cfaa strb.w r5,[r4,#0x47]
// 0802cfae strb.w r5,[r4,#0x48]
// 0802cfb2 strb.w r5,[r4,#0x49]
// 0802cfb6 strh.w r5,[r4,#0x27]
// 0802cfba strh.w r5,[r4,#0x29]
// 0802cfbe strh.w r5,[r4,#0x2b]
// 0802cfc2 strh.w r5,[r4,#0x2d]
// 0802cfc6 movs r6,#0x90
// 0802cfc8 bl 0x08035d8c
// 0802cfcc mov.w r7,#0xffffffff
// 0802cfd0 ldrb r3,[r4,#0x4]
// 0802cfd2 uxtb r0,r5
// 0802cfd4 cmp r3,r0
// 0802cfd6 bhi 0x0802d03c
// 0802cfd8 movs r2,#0x0
// 0802cfda movs r0,#0x6
// 0802cfdc ldr r1,[0x0802d2a0]
// 0802cfde bl 0x0802ae20
// 0802cfe2 movs r2,#0x0
// 0802cfe4 movs r0,#0x7
// 0802cfe6 ldr r1,[0x0802d2a4]
// 0802cfe8 bl 0x0802ae20
// 0802cfec movs r2,#0x0
// 0802cfee movs r0,#0x8
// 0802cff0 ldr r1,[0x0802d2a8]
// 0802cff2 bl 0x0802ae20
// 0802cff6 movs r0,#0x9
// 0802cff8 movs r2,#0x0
// 0802cffa ldr r1,[0x0802d2ac]
// 0802cffc bl 0x0802ae20
// 0802d000 movs r0,#0x2
// 0802d002 bl 0x08029b9c
// 0802d006 cmp r0,#0x0
// FUNCTION 0802d008

void FUN_0802d008(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  uint uVar7;
  uint *unaff_r4;
  char in_ZR;
  bool bVar8;
  undefined8 uVar9;
  
  if (in_ZR == '\0') {
    if (0x174 < param_1 - 0xe8b) {
      if (param_1 < 0x175) goto LAB_0802d014;
      if (param_1 - 0x83e < 0x2e9) {
        *(undefined1 *)((int)unaff_r4 + 5) = 4;
        goto LAB_0802d018;
      }
      if (0x2e8 < param_1 - 0x365) goto LAB_0802d058;
      uVar4 = 3;
      *(undefined1 *)((int)unaff_r4 + 5) = 3;
      FUN_0802ce44(*unaff_r4,1);
      uVar6 = 2;
      FUN_0802ce44(*unaff_r4 + 0x90,2,2,0);
      iVar2 = *unaff_r4 + 0x120;
      goto LAB_0802d034;
    }
    *(undefined1 *)((int)unaff_r4 + 5) = 1;
    FUN_0802ce44(*unaff_r4,1);
  }
  else {
    iVar2 = FUN_08029b9c(1);
    if (iVar2 == 0) {
      *(undefined1 *)((int)unaff_r4 + 5) = 0;
    }
    else {
LAB_0802d014:
      *(undefined1 *)((int)unaff_r4 + 5) = 2;
LAB_0802d018:
      FUN_0802ce44(*unaff_r4,1);
      uVar4 = 2;
      uVar6 = 1;
      iVar2 = *unaff_r4 + 0x90;
LAB_0802d034:
      FUN_0802ce44(iVar2,uVar4,uVar4,0);
      *(undefined1 *)((int)unaff_r4 + 0xd) = uVar6;
    }
  }
LAB_0802d058:
  uVar3 = FUN_08029b9c(6);
  if (uVar3 == 0) {
    iVar2 = FUN_08029b9c(5);
    if (iVar2 == 0) {
      *(undefined1 *)((int)unaff_r4 + 6) = 0;
      goto LAB_0802d086;
    }
LAB_0802d070:
    *(undefined1 *)((int)unaff_r4 + 6) = 1;
    FUN_0802ce44(*unaff_r4 + 0x1b0,4);
  }
  else {
    if (uVar3 < 0x175) goto LAB_0802d070;
    if (uVar3 - 0xe8b < 0x175) {
      *(undefined1 *)((int)unaff_r4 + 6) = 2;
      FUN_0802ce44(*unaff_r4 + 0x1b0,4,4,1);
      FUN_0802ce44(*unaff_r4 + 0x240,5);
      uVar6 = 4;
LAB_0802d1f6:
      *(undefined1 *)((int)unaff_r4 + 0xe) = uVar6;
    }
    else if (uVar3 - 0x365 < 0x2e9) {
      *(undefined1 *)((int)unaff_r4 + 6) = 4;
      FUN_0802ce44(*unaff_r4 + 0x1b0,4,4,1);
      FUN_0802ce44(*unaff_r4 + 0x240,5);
      *(undefined1 *)((int)unaff_r4 + 0xe) = 4;
    }
    else if (uVar3 - 0x83e < 0x2e9) {
      *(undefined1 *)((int)unaff_r4 + 6) = 3;
      FUN_0802ce44(*unaff_r4 + 0x1b0,4,4,1);
      FUN_0802ce44(*unaff_r4 + 0x240,5);
      FUN_0802ce44(*unaff_r4 + 0x2d0,6,6,1);
      uVar6 = 5;
      goto LAB_0802d1f6;
    }
  }
LAB_0802d086:
  FUN_0802ce68(DAT_0802d2b0 + -3);
  uVar4 = FUN_08029b9c(0);
  *(undefined4 *)((int)unaff_r4 + 0xf) = uVar4;
  uVar4 = FUN_08029b9c(1);
  *(undefined4 *)((int)unaff_r4 + 0x13) = uVar4;
  uVar4 = FUN_08029b9c(3);
  *(undefined4 *)((int)unaff_r4 + 0x17) = uVar4;
  uVar4 = FUN_08029b9c(4);
  *(undefined4 *)((int)unaff_r4 + 0x1b) = uVar4;
  uVar4 = FUN_08029b9c(5);
  *(undefined4 *)((int)unaff_r4 + 0x1f) = uVar4;
  uVar9 = FUN_08029b9c(7);
  uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar7 = (uint)*(byte *)((int)unaff_r4 + 5);
  *(int *)((int)unaff_r4 + 0x23) = (int)uVar9;
  uVar5 = uVar7 - 1;
  uVar3 = uVar5;
  if (uVar5 < 2) {
    uVar4 = 0xd;
    uVar3 = *unaff_r4;
  }
  if (uVar5 < 2) {
    *(undefined4 *)(uVar3 + 0x68) = uVar4;
  }
  uVar3 = (uint)*(byte *)((int)unaff_r4 + 6);
  if (uVar3 - 1 < 2) {
    *(undefined4 *)(*unaff_r4 + 0x218) = 0xe;
    if (uVar7 == 3) {
LAB_0802d0f0:
      uVar5 = *unaff_r4;
      *(undefined4 *)(uVar5 + 0x68) = 0x29;
      *(undefined4 *)(uVar5 + 0xf8) = 0xd;
      if (uVar3 == 3) goto LAB_0802d102;
    }
    else {
LAB_0802d290:
      if (uVar7 == 4) goto LAB_0802d118;
    }
LAB_0802d128:
    if (uVar3 != 4) goto LAB_0802d2d0;
    if ((char)unaff_r4[0xc] == '\0') goto LAB_0802d2c2;
    bVar8 = (char)unaff_r4[0xc] == '\x01';
LAB_0802d31c:
    if (!bVar8) goto LAB_0802d2d0;
    uVar5 = *unaff_r4;
    *(undefined4 *)(uVar5 + 0x218) = 0xe;
    uVar4 = 0xd;
  }
  else {
    if (uVar7 == 3) goto LAB_0802d0f0;
    if (uVar3 != 3) goto LAB_0802d290;
LAB_0802d102:
    uVar5 = *unaff_r4;
    *(undefined4 *)(uVar5 + 0x218) = 0x2a;
    *(undefined4 *)(uVar5 + 0x2a8) = 0xe;
    if (uVar7 != 4) goto LAB_0802d2d0;
LAB_0802d118:
    if ((char)unaff_r4[0xc] != '\0') {
      if ((char)unaff_r4[0xc] != '\x01') goto LAB_0802d128;
      uVar5 = *unaff_r4;
      bVar8 = uVar3 == 4;
      *(undefined4 *)(uVar5 + 0x68) = 0xd;
      *(undefined4 *)(uVar5 + 0x6c) = 0xe;
      goto LAB_0802d31c;
    }
    uVar5 = *unaff_r4;
    *(undefined4 *)(uVar5 + 0x68) = 0xd;
    *(undefined4 *)(uVar5 + 0x6c) = 0x29;
    if (uVar3 != 4) goto LAB_0802d2d0;
LAB_0802d2c2:
    uVar5 = *unaff_r4;
    *(undefined4 *)(uVar5 + 0x218) = 0xe;
    uVar4 = 0x2a;
  }
  *(undefined4 *)(uVar5 + 0x21c) = uVar4;
LAB_0802d2d0:
  if (uVar7 - 2 < 3) {
    bVar1 = *(byte *)((int)unaff_r4 + 0xd);
    uVar9 = FUN_0802cf50((uint)bVar1);
    uVar3 = (uint)((ulonglong)uVar9 >> 0x20);
    if ((int)uVar9 != 0) {
      *(undefined4 *)(*unaff_r4 + (uint)bVar1 * 0x90 + 0x68) = 0x1b;
    }
  }
  if (uVar3 - 2 < 3) {
    uVar9 = FUN_0802cf50(*(undefined1 *)((int)unaff_r4 + 0xe));
    if ((int)uVar9 != 0) {
      *(undefined4 *)(*unaff_r4 + (int)((ulonglong)uVar9 >> 0x20) * 0x90 + 0x68) = 0x18;
    }
  }
  return;
}


// 0802d008 bne.w 0x0802d13c
// 0802d00c movs r0,#0x1
// 0802d00e bl 0x08029b9c
// 0802d012 cbz r0,0x0802d056
// 0802d014 movs r6,#0x2
// 0802d016 strb r6,[r4,#0x5]
// 0802d018 movs r3,#0x0
// 0802d01a movs r2,#0x1
// 0802d01c ldr r0,[r4,#0x0]
// 0802d01e mov r1,r2
// 0802d020 str r3,[sp,#0x0]
// 0802d022 bl 0x0802ce44
// 0802d026 movs r2,#0x2
// 0802d028 movs r5,#0x1
// 0802d02a movs r3,#0x0
// 0802d02c mov r1,r2
// 0802d02e ldr r0,[r4,#0x0]
// 0802d030 str r5,[sp,#0x0]
// 0802d032 adds r0,#0x90
// 0802d034 bl 0x0802ce44
// 0802d038 strb r5,[r4,#0xd]
// 0802d03a b 0x0802d058
// 0802d056 strb r0,[r4,#0x5]
// 0802d058 movs r0,#0x6
// 0802d05a bl 0x08029b9c
// 0802d05e cmp r0,#0x0
// 0802d060 bne.w 0x0802d1b8
// 0802d064 movs r0,#0x5
// 0802d066 bl 0x08029b9c
// 0802d06a cmp r0,#0x0
// 0802d06c beq.w 0x0802d1b4
// 0802d070 movs r2,#0x0
// 0802d072 str r2,[sp,#0x0]
// 0802d074 movs r2,#0x4
// 0802d076 movs r3,#0x1
// 0802d078 ldr r0,[r4,#0x0]
// 0802d07a mov r1,r2
// 0802d07c add.w r0,r0,#0x1b0
// 0802d080 strb r3,[r4,#0x6]
// 0802d082 bl 0x0802ce44
// 0802d086 ldr r1,[0x0802d2b0]
// 0802d088 subs r0,r1,#0x3
// 0802d08a bl 0x0802ce68
// 0802d08e movs r0,#0x0
// 0802d090 bl 0x08029b9c
// 0802d094 str.w r0,[r4,#0xf]
// 0802d098 movs r0,#0x1
// 0802d09a bl 0x08029b9c
// 0802d09e str.w r0,[r4,#0x13]
// 0802d0a2 movs r0,#0x3
// 0802d0a4 bl 0x08029b9c
// 0802d0a8 str.w r0,[r4,#0x17]
// 0802d0ac movs r0,#0x4
// 0802d0ae bl 0x08029b9c
// 0802d0b2 str.w r0,[r4,#0x1b]
// 0802d0b6 movs r0,#0x5
// 0802d0b8 bl 0x08029b9c
// 0802d0bc str.w r0,[r4,#0x1f]
// 0802d0c0 movs r0,#0x7
// 0802d0c2 bl 0x08029b9c
// 0802d0c6 ldrb r3,[r4,#0x5]
// 0802d0c8 str.w r0,[r4,#0x23]
// FUNCTION 0802d0cc

void FUN_0802d0cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *unaff_r4;
  bool bVar5;
  undefined8 uVar6;
  
  uVar3 = param_4 - 1;
  uVar4 = uVar3;
  if (uVar3 < 2) {
    param_2 = 0xd;
    uVar4 = *unaff_r4;
  }
  if (uVar3 < 2) {
    *(undefined4 *)(uVar4 + 0x68) = param_2;
  }
  uVar4 = (uint)*(byte *)((int)unaff_r4 + 6);
  if (uVar4 - 1 < 2) {
    *(undefined4 *)(*unaff_r4 + 0x218) = 0xe;
    if (param_4 == 3) {
LAB_0802d0f0:
      uVar3 = *unaff_r4;
      *(undefined4 *)(uVar3 + 0x68) = 0x29;
      *(undefined4 *)(uVar3 + 0xf8) = 0xd;
      if (uVar4 == 3) goto LAB_0802d102;
    }
    else {
LAB_0802d290:
      if (param_4 == 4) goto LAB_0802d118;
    }
LAB_0802d128:
    if (uVar4 != 4) goto LAB_0802d2d0;
    if ((char)unaff_r4[0xc] == '\0') goto LAB_0802d2c2;
    bVar5 = (char)unaff_r4[0xc] == '\x01';
LAB_0802d31c:
    if (!bVar5) goto LAB_0802d2d0;
    uVar3 = *unaff_r4;
    *(undefined4 *)(uVar3 + 0x218) = 0xe;
    uVar2 = 0xd;
  }
  else {
    if (param_4 == 3) goto LAB_0802d0f0;
    if (uVar4 != 3) goto LAB_0802d290;
LAB_0802d102:
    uVar3 = *unaff_r4;
    *(undefined4 *)(uVar3 + 0x218) = 0x2a;
    *(undefined4 *)(uVar3 + 0x2a8) = 0xe;
    if (param_4 != 4) goto LAB_0802d2d0;
LAB_0802d118:
    if ((char)unaff_r4[0xc] != '\0') {
      if ((char)unaff_r4[0xc] != '\x01') goto LAB_0802d128;
      uVar3 = *unaff_r4;
      bVar5 = uVar4 == 4;
      *(undefined4 *)(uVar3 + 0x68) = 0xd;
      *(undefined4 *)(uVar3 + 0x6c) = 0xe;
      goto LAB_0802d31c;
    }
    uVar3 = *unaff_r4;
    *(undefined4 *)(uVar3 + 0x68) = 0xd;
    *(undefined4 *)(uVar3 + 0x6c) = 0x29;
    if (uVar4 != 4) goto LAB_0802d2d0;
LAB_0802d2c2:
    uVar3 = *unaff_r4;
    *(undefined4 *)(uVar3 + 0x218) = 0xe;
    uVar2 = 0x2a;
  }
  *(undefined4 *)(uVar3 + 0x21c) = uVar2;
LAB_0802d2d0:
  if (param_4 - 2U < 3) {
    bVar1 = *(byte *)((int)unaff_r4 + 0xd);
    uVar6 = FUN_0802cf50((uint)bVar1);
    uVar4 = (uint)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar6 != 0) {
      *(undefined4 *)(*unaff_r4 + (uint)bVar1 * 0x90 + 0x68) = 0x1b;
    }
  }
  if (uVar4 - 2 < 3) {
    uVar6 = FUN_0802cf50(*(undefined1 *)((int)unaff_r4 + 0xe));
    if ((int)uVar6 != 0) {
      *(undefined4 *)(*unaff_r4 + (int)((ulonglong)uVar6 >> 0x20) * 0x90 + 0x68) = 0x18;
    }
  }
  return;
}


// 0802d0cc subs r2,r3,#0x1
// 0802d0ce cmp r2,#0x1
// 0802d0d0 ittt ls
// 0802d0d2 mov.ls r1,#0xd
// 0802d0d4 ldr.ls r2,[r4,#0x0]
// 0802d0d6 str.ls r1,[r2,#0x68]
// 0802d0d8 ldrb r1,[r4,#0x6]
// 0802d0da subs r2,r1,#0x1
// 0802d0dc cmp r2,#0x1
// 0802d0de bhi.w 0x0802d284
// 0802d0e2 movs r0,#0xe
// 0802d0e4 ldr r2,[r4,#0x0]
// 0802d0e6 cmp r3,#0x3
// 0802d0e8 str.w r0,[r2,#0x218]
// 0802d0ec bne.w 0x0802d290
// 0802d0f0 movs r0,#0x29
// 0802d0f2 ldr r2,[r4,#0x0]
// 0802d0f4 cmp r1,#0x3
// 0802d0f6 str r0,[r2,#0x68]
// 0802d0f8 mov.w r0,#0xd
// 0802d0fc str.w r0,[r2,#0xf8]
// 0802d100 bne 0x0802d128
// 0802d102 movs r0,#0x2a
// 0802d104 ldr r2,[r4,#0x0]
// 0802d106 cmp r3,#0x4
// 0802d108 str.w r0,[r2,#0x218]
// 0802d10c mov.w r0,#0xe
// 0802d110 str.w r0,[r2,#0x2a8]
// 0802d114 bne.w 0x0802d2d0
// 0802d118 ldrb.w r2,[r4,#0x30]
// 0802d11c cmp r2,#0x0
// 0802d11e beq.w 0x0802d2b4
// 0802d122 cmp r2,#0x1
// 0802d124 beq.w 0x0802d310
// 0802d128 cmp r1,#0x4
// 0802d12a bne.w 0x0802d2d0
// 0802d12e ldrb.w r2,[r4,#0x30]
// 0802d132 cmp r2,#0x0
// 0802d134 beq.w 0x0802d2c2
// 0802d138 cmp r2,#0x1
// 0802d13a b 0x0802d31c
// 0802d284 cmp r3,#0x3
// 0802d286 beq.w 0x0802d0f0
// 0802d28a cmp r1,#0x3
// 0802d28c beq.w 0x0802d102
// 0802d290 cmp r3,#0x4
// 0802d292 beq.w 0x0802d118
// 0802d296 b 0x0802d128
// 0802d2b4 movs r6,#0xd
// 0802d2b6 movs r0,#0x29
// 0802d2b8 ldr r2,[r4,#0x0]
// 0802d2ba cmp r1,#0x4
// 0802d2bc strd r6,r0,[r2,#0x68]
// 0802d2c0 bne 0x0802d2d0
// 0802d2c2 movs r0,#0xe
// 0802d2c4 ldr r2,[r4,#0x0]
// 0802d2c6 str.w r0,[r2,#0x218]
// 0802d2ca movs r0,#0x2a
// 0802d2cc str.w r0,[r2,#0x21c]
// 0802d2d0 subs r3,#0x2
// 0802d2d2 cmp r3,#0x2
// 0802d2d4 bhi 0x0802d2ee
// 0802d2d6 ldrb r5,[r4,#0xd]
// 0802d2d8 mov r0,r5
// 0802d2da bl 0x0802cf50
// 0802d2de cbz r0,0x0802d2ee
// 0802d2e0 ldr r3,[r4,#0x0]
// 0802d2e2 add.w r5,r5,r5, lsl #0x3
// 0802d2e6 add.w r5,r3,r5, lsl #0x4
// 0802d2ea movs r3,#0x1b
// 0802d2ec str r3,[r5,#0x68]
// 0802d2ee subs r1,#0x2
// 0802d2f0 cmp r1,#0x2
// 0802d2f2 bhi 0x0802d30c
// 0802d2f4 ldrb r1,[r4,#0xe]
// 0802d2f6 mov r0,r1
// 0802d2f8 bl 0x0802cf50
// 0802d2fc cbz r0,0x0802d30c
// 0802d2fe ldr r3,[r4,#0x0]
// 0802d300 add.w r1,r1,r1, lsl #0x3
// 0802d304 add.w r1,r3,r1, lsl #0x4
// 0802d308 movs r3,#0x18
// 0802d30a str r3,[r1,#0x68]
// 0802d30c add sp,#0xc
// 0802d30e pop {r4,r5,r6,r7,pc}
// 0802d310 movs r5,#0xd
// 0802d312 movs r0,#0xe
// 0802d314 ldr r2,[r4,#0x0]
// 0802d316 cmp r1,#0x4
// 0802d318 strd r5,r0,[r2,#0x68]
// 0802d31c bne 0x0802d2d0
// 0802d31e movs r0,#0xe
// 0802d320 ldr r2,[r4,#0x0]
// 0802d322 str.w r0,[r2,#0x218]
// 0802d326 movs r0,#0xd
// 0802d328 b 0x0802d2cc
// FUNCTION 08026bb4

undefined4 FUN_08026bb4(void)

{
  return DAT_08026bb8;
}


// 08026bb4 ldr r0,[0x08026bb8]
// 08026bb6 bx lr
