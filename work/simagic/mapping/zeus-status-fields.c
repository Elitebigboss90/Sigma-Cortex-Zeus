// FUNCTION 08030ee4

undefined4 FUN_08030ee4(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  
  piVar10 = (int *)*param_1;
  if (*(ushort *)(param_1 + 2) < *(ushort *)(piVar10 + 4)) {
    iVar6 = *piVar10;
    iVar4 = (uint)*(ushort *)((int)param_1 + 10) * 4;
    uVar3 = *(uint *)(iVar6 + (uint)*(ushort *)((int)param_1 + 10) * 4);
    uVar11 = uVar3 & 3;
    uVar9 = (uVar3 & 0xffff) >> 8;
    *(char *)((int)param_1 + 0x16) = (char)(uVar3 >> 8);
    uVar1 = (ushort)((uVar3 << 0x18) >> 0x10);
    if (uVar11 == 1) {
      uVar11 = *(uint *)(iVar6 + iVar4 + 4);
      *(ushort *)(param_1 + 5) = (ushort)((uVar3 << 4) >> 0x14);
      uVar12 = uVar11 & 0xffff;
      *(ushort *)(param_1 + 4) = uVar1 >> 10 | (ushort)((uVar11 >> 0x1c) << 6);
      uVar3 = uVar3 >> 0x1c;
      *(ushort *)((int)param_1 + 0x12) = (ushort)((uVar11 << 4) >> 0x14);
    }
    else {
      uVar2 = (ushort)(uVar3 >> 0x10);
      if (uVar11 == 2) {
        iVar6 = iVar6 + iVar4;
        uVar3 = *(uint *)(iVar6 + 4);
        uVar12 = *(uint *)(iVar6 + 8);
        uVar7 = *(undefined4 *)(iVar6 + 0xc);
        *(ushort *)(param_1 + 5) = uVar2;
        *(ushort *)(param_1 + 4) = uVar1 >> 10 | (ushort)((uVar3 >> 8) << 6);
        uVar3 = (uint)(char)uVar3;
        *(short *)((int)param_1 + 0x12) = (short)uVar7;
      }
      else {
        if (uVar11 == 0) {
          uVar12 = (uVar3 & 0xffffff) >> 0x10;
          *(undefined2 *)(param_1 + 5) = 1;
          *(ushort *)(param_1 + 4) = uVar1 >> 10;
          uVar3 = (uVar3 & 0xfffffff) >> 0x18;
          uVar2 = uVar2 >> 0xc;
        }
        else {
          iVar6 = iVar6 + iVar4;
          uVar3 = *(uint *)(iVar6 + 4);
          uVar12 = *(uint *)(iVar6 + 8);
          uVar2 = (ushort)*(undefined4 *)(iVar6 + 0xc);
          *(short *)(param_1 + 5) = (short)*(undefined4 *)(iVar6 + 0x10);
          *(ushort *)(param_1 + 4) = uVar1 >> 10 | (ushort)((uVar3 >> 8) << 6);
          uVar3 = (uint)(char)uVar3;
        }
        *(ushort *)((int)param_1 + 0x12) = uVar2;
      }
    }
    if (param_1[1] == 0) {
      param_1[6] = 0;
      param_1[8] = 0;
    }
    else {
      puVar5 = (undefined4 *)(param_1[1] + uVar12);
      param_1[6] = puVar5;
      if (uVar3 == 0) {
        if (((uVar9 & 0x30) == 0x20) && (-1 < (int)(uVar9 << 0x19))) {
          puVar8 = param_1 + 5;
        }
        else {
          puVar8 = (undefined4 *)0x0;
        }
      }
      else {
        puVar8 = (undefined4 *)((int)puVar5 - uVar3);
      }
      param_1[8] = puVar8;
      if ((uVar9 & 0xc0) == 0x80) {
        param_1[7] = *puVar5;
      }
      else {
        param_1[7] = puVar5;
      }
    }
    if ((uVar9 & 0xe) == 8) {
      uVar7 = *(undefined4 *)(piVar10[1] + (uint)*(ushort *)((int)param_1 + 0xe) * 4);
    }
    else {
      uVar7 = 0;
    }
    param_1[9] = uVar7;
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


// 08030ee4 push {r4,r5,r6,r7,lr}
// 08030ee6 ldr r5,[r0,#0x0]
// 08030ee8 ldrh r2,[r0,#0x8]
// 08030eea ldrh r3,[r5,#0x10]
// 08030eec cmp r2,r3
// 08030eee bcs 0x08030fca
// 08030ef0 ldr r3,[r5,#0x0]
// 08030ef2 ldrh r1,[r0,#0xa]
// 08030ef4 lsls r2,r1,#0x2
// 08030ef6 ldr.w r1,[r3,r1,lsl #0x2]
// 08030efa and r7,r1,#0x3
// 08030efe ubfx r4,r1,#0x8,#0x8
// 08030f02 cmp r7,#0x1
// 08030f04 strb r4,[r0,#0x16]
// 08030f06 ubfx r6,r1,#0x2,#0x6
// 08030f0a beq 0x08030f28
// 08030f0c cmp r7,#0x2
// 08030f0e beq 0x08030f64
// 08030f10 cmp r7,#0x0
// 08030f12 bne 0x08030f82
// 08030f14 movs r3,#0x1
// 08030f16 ubfx r7,r1,#0x10,#0x8
// 08030f1a strh r3,[r0,#0x14]
// 08030f1c strh r6,[r0,#0x10]
// 08030f1e ubfx r3,r1,#0x18,#0x4
// 08030f22 lsrs r1,r1,#0x1c
// 08030f24 strh r1,[r0,#0x12]
// 08030f26 b 0x08030f44
// 08030f28 add r3,r2
// 08030f2a ldr r2,[r3,#0x4]
// 08030f2c ubfx r3,r1,#0x10,#0xc
// 08030f30 strh r3,[r0,#0x14]
// 08030f32 lsrs r3,r2,#0x1c
// 08030f34 orr.w r6,r6,r3, lsl #0x6
// 08030f38 uxth r7,r2
// 08030f3a ubfx r2,r2,#0x10,#0xc
// 08030f3e strh r6,[r0,#0x10]
// 08030f40 lsrs r3,r1,#0x1c
// 08030f42 strh r2,[r0,#0x12]
// 08030f44 ldr r2,[r0,#0x4]
// 08030f46 cbnz r2,0x08030f9a
// 08030f48 str r2,[r0,#0x18]
// 08030f4a str r2,[r0,#0x20]
// 08030f4c and r4,r4,#0xe
// 08030f50 cmp r4,#0x8
// 08030f52 iteee ne
// 08030f54 mov.ne r3,#0x0
// 08030f56 ldrh.eq r2,[r0,#0xe]
// 08030f58 ldr.eq r3,[r5,#0x4]
// 08030f5a ldr.eq.w r3,[r3,r2,lsl #0x2]
// 08030f5e str r3,[r0,#0x24]
// 08030f60 movs r0,#0x1
// 08030f62 pop {r4,r5,r6,r7,pc}
// 08030f64 add r3,r2
// 08030f66 ldrd r2,r7,[r3,#0x4]
// 08030f6a ldr.w r12,[r3,#0xc]
// 08030f6e lsrs r3,r2,#0x8
// 08030f70 orr.w r6,r6,r3, lsl #0x6
// 08030f74 lsrs r1,r1,#0x10
// 08030f76 strh r1,[r0,#0x14]
// 08030f78 strh r6,[r0,#0x10]
// 08030f7a sxtb r3,r2
// 08030f7c strh.w r12,[r0,#0x12]
// 08030f80 b 0x08030f44
// 08030f82 add r3,r2
// 08030f84 ldrd r2,r7,[r3,#0x4]
// 08030f88 ldrd r1,r3,[r3,#0xc]
// 08030f8c strh r3,[r0,#0x14]
// 08030f8e lsrs r3,r2,#0x8
// 08030f90 orr.w r6,r6,r3, lsl #0x6
// 08030f94 strh r6,[r0,#0x10]
// 08030f96 sxtb r3,r2
// 08030f98 b 0x08030f24
// 08030f9a add r2,r7
// 08030f9c str r2,[r0,#0x18]
// 08030f9e cbz r3,0x08030fb4
// 08030fa0 subs r3,r2,r3
// 08030fa2 str r3,[r0,#0x20]
// 08030fa4 and r3,r4,#0xc0
// 08030fa8 cmp r3,#0x80
// 08030faa itet eq
// 08030fac ldr.eq r3,[r2,#0x0]
// 08030fae str.ne r2,[r0,#0x1c]
// 08030fb0 str.eq r3,[r0,#0x1c]
// 08030fb2 b 0x08030f4c
// 08030fb4 and r3,r4,#0x30
// 08030fb8 cmp r3,#0x20
// 08030fba bne 0x08030fc6
// 08030fbc lsls r3,r4,#0x19
// 08030fbe bmi 0x08030fc6
// 08030fc0 add.w r3,r0,#0x14
// 08030fc4 b 0x08030fa2
// 08030fc6 movs r3,#0x0
// 08030fc8 b 0x08030fa2
// 08030fca movs r0,#0x0
// 08030fcc b 0x08030f62
// FUNCTION 08030fce

void FUN_08030fce(int *param_1)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar4 = (short)param_1[2] + 1;
  uVar1 = *(ushort *)((int *)*param_1 + 4);
  *(ushort *)(param_1 + 2) = uVar4;
  if (uVar4 < uVar1) {
    uVar2 = *(uint *)(*(int *)*param_1 + (uint)*(ushort *)((int)param_1 + 10) * 4);
    uVar5 = uVar2 >> 8;
    *(ushort *)((int)param_1 + 10) = *(ushort *)((int)param_1 + 10) + (short)(1 << (uVar2 & 3));
    sVar3 = (short)param_1[3];
    if ((uVar5 & 0x30) == 0) {
      sVar3 = sVar3 + 1;
    }
    *(short *)(param_1 + 3) = sVar3;
    sVar3 = *(short *)((int)param_1 + 0xe);
    if ((uVar5 & 0xe) == 8) {
      sVar3 = sVar3 + 1;
    }
    *(short *)((int)param_1 + 0xe) = sVar3;
  }
  else {
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}


// 08030fce ldrh r3,[r0,#0x8]
// 08030fd0 ldr r1,[r0,#0x0]
// 08030fd2 adds r3,#0x1
// 08030fd4 ldrh r2,[r1,#0x10]
// 08030fd6 uxth r3,r3
// 08030fd8 cmp r2,r3
// 08030fda push {r4,lr}
// 08030fdc strh r3,[r0,#0x8]
// 08030fde bhi 0x08030fe8
// 08030fe0 movs r3,#0x0
// 08030fe2 strd r3,r3,[r0,#0x8]
// 08030fe6 pop {r4,pc}
// 08030fe8 movs r4,#0x1
// 08030fea ldr r3,[r1,#0x0]
// 08030fec ldrh r2,[r0,#0xa]
// 08030fee ldr.w r1,[r3,r2,lsl #0x2]
// 08030ff2 lsrs r3,r1,#0x8
// 08030ff4 and r1,r1,#0x3
// 08030ff8 lsl.w r1,r4,r1
// 08030ffc add r2,r1
// 08030ffe strh r2,[r0,#0xa]
// 08031000 ldrh r2,[r0,#0xc]
// 08031002 and r1,r3,#0x30
// 08031006 cmp r1,#0x0
// 08031008 it eq
// 0803100a add.eq r2,#0x1
// 0803100c strh r2,[r0,#0xc]
// 0803100e ldrh r2,[r0,#0xe]
// 08031010 and r3,r3,#0xe
// 08031014 cmp r3,#0x8
// 08031016 it eq
// 08031018 add.eq r2,#0x1
// 0803101a strh r2,[r0,#0xe]
// 0803101c b 0x08030fe6
