// FUNCTION 0803241c

undefined4 FUN_0803241c(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_60 [22];
  byte local_4a;
  undefined4 *local_44;
  undefined1 auStack_38 [44];
  
  iVar1 = thunk_FUN_0803101e(auStack_60);
  do {
    if (iVar1 == 0) {
      return 1;
    }
    if ((local_4a & 0xf) == 10) {
      for (piVar2 = (int *)*local_44; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
        if (*(code **)(*piVar2 + 4) == (code *)0x0) {
          iVar1 = thunk_FUN_0803103e(auStack_38,piVar2);
          if (iVar1 == 0) {
            iVar1 = *(int *)(param_1 + 0x10);
            if (*(int *)(param_1 + 0x10) == 0) {
              iVar1 = DAT_08032490;
            }
            *(int *)(param_1 + 0x10) = iVar1;
            return 0;
          }
          iVar1 = FUN_08032234(param_1,auStack_38);
        }
        else {
          iVar1 = (**(code **)(*piVar2 + 4))(param_1);
        }
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar1 = FUN_08032234(param_1,auStack_60);
      if (iVar1 == 0) {
        return 0;
      }
    }
    iVar1 = FUN_08031064(auStack_60);
  } while( true );
}


// 0803241c push {r4,r5,lr}
// 0803241e sub sp,#0x54
// 08032420 mov r4,r0
// 08032422 mov r0,sp
// 08032424 bl 0x0803111e
// 08032428 cbz r0,0x0803248a
// 0803242a ldrb.w r3,[sp,#0x16]
// 0803242e and r3,r3,#0xf
// 08032432 cmp r3,#0xa
// 08032434 bne 0x0803247c
// 08032436 ldr r3,[sp,#0x1c]
// 08032438 ldr r5,[r3,#0x0]
// 0803243a cbnz r5,0x08032444
// 0803243c mov r0,sp
// 0803243e bl 0x08031064
// 08032442 b 0x08032428
// 08032444 ldr r3,[r5,#0x0]
// 08032446 mov r1,r5
// 08032448 ldr r3,[r3,#0x4]
// 0803244a cbz r3,0x08032456
// 0803244c mov r0,r4
// 0803244e blx r3
// 08032450 cbnz r0,0x08032478
// 08032452 movs r0,#0x0
// 08032454 b 0x0803246a
// 08032456 add r0,sp,#0x28
// 08032458 bl 0x08031122
// 0803245c cbnz r0,0x0803246e
// 0803245e ldr r3,[r4,#0x10]
// 08032460 ldr r2,[0x08032490]
// 08032462 cmp r3,#0x0
// 08032464 it eq
// 08032466 mov.eq r3,r2
// 08032468 str r3,[r4,#0x10]
// 0803246a add sp,#0x54
// 0803246c pop {r4,r5,pc}
// 0803246e mov r0,r4
// 08032470 add r1,sp,#0x28
// 08032472 bl 0x08032234
// 08032476 b 0x08032450
// 08032478 ldr r5,[r5,#0x8]
// 0803247a b 0x0803243a
// 0803247c mov r1,sp
// 0803247e mov r0,r4
// 08032480 bl 0x08032234
// 08032484 cmp r0,#0x0
// 08032486 bne 0x0803243c
// 08032488 b 0x08032452
// 0803248a movs r0,#0x1
// 0803248c b 0x0803246a
// FUNCTION 08028d98

uint FUN_08028d98(uint *param_1,int param_2,uint param_3,uint *param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  
  if ((param_1 == (uint *)0x0) || (param_4 == (uint *)0x0)) {
LAB_08028daa:
    uVar2 = 0xffffffff;
  }
  else {
    FUN_08035d8c(param_4,0,(uint)param_5,param_4,param_1,param_2,param_3);
    if ((param_2 == 0) || (param_3 == 0)) {
      *(undefined2 *)(param_1 + 3) = 0x101;
      *param_4 = param_1[1];
      param_4[1] = param_1[2];
      *(short *)(param_4 + 2) = (short)param_1[3];
    }
    else {
      uVar4 = *param_1;
      uVar7 = param_3 / uVar4;
      iVar8 = param_3 - uVar4 * uVar7;
      uVar2 = uVar7;
      if (iVar8 != 0) {
        uVar2 = uVar7 + 1;
      }
      iVar5 = uVar4 + 10;
      uVar4 = uVar2 & 0xff;
      *(ushort *)((int)param_1 + 10) =
           (ushort)((param_3 & 0xff) << 8) | (ushort)(param_3 >> 8) & 0xff;
      *(char *)(param_1 + 3) = (char)uVar2;
      if ((uint)param_5 < iVar5 * uVar2) goto LAB_08028daa;
      uVar2 = 0;
      puVar6 = param_4;
      while (uVar2 != uVar7) {
        *(char *)((int)param_1 + 0xd) = (char)(uVar2 + 1);
        iVar3 = (int)puVar6 + 10;
        *puVar6 = param_1[1];
        puVar6[1] = param_1[2];
        *(short *)(puVar6 + 2) = (short)param_1[3];
        puVar6 = (uint *)((int)puVar6 + iVar5);
        iVar1 = uVar2 * *param_1;
        uVar2 = uVar2 + 1;
        FUN_0802238c(iVar3,iVar1 + param_2);
      }
      if (iVar8 != 0) {
        iVar5 = uVar2 * iVar5;
        *(char *)((int)param_1 + 0xd) = (char)uVar4;
        *(uint *)((int)param_4 + iVar5) = param_1[1];
        *(uint *)((int)param_4 + iVar5 + 4) = param_1[2];
        *(short *)((int)param_4 + iVar5 + 8) = (short)param_1[3];
        FUN_0802238c((int)param_4 + iVar5 + 10,*param_1 * uVar2 + param_2,iVar8);
      }
    }
    uVar2 = (uint)(byte)param_1[3];
  }
  return uVar2;
}


// 08028d98 push {r0,r1,r2,r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 08028d9c mov r8,r1
// 08028d9e mov r7,r2
// 08028da0 mov r6,r3
// 08028da2 mov r4,r0
// 08028da4 ldrh.w r11,[sp,#0x30]
// 08028da8 cbnz r0,0x08028db4
// 08028daa mov.w r0,#0xffffffff
// 08028dae add sp,#0xc
// 08028db0 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 08028db4 cmp r3,#0x0
// 08028db6 beq 0x08028daa
// 08028db8 mov r2,r11
// 08028dba movs r1,#0x0
// 08028dbc mov r0,r3
// 08028dbe bl 0x08035d8c
// 08028dc2 cmp.w r8,#0x0
// 08028dc6 beq 0x08028dca
// 08028dc8 cbnz r7,0x08028de0
// 08028dca movw r3,#0x101
// 08028dce strh r3,[r4,#0xc]
// 08028dd0 ldr r3,[r4,#0x4]
// 08028dd2 str r3,[r6,#0x0]
// 08028dd4 ldr r3,[r4,#0x8]
// 08028dd6 str r3,[r6,#0x4]
// 08028dd8 ldrh r3,[r4,#0xc]
// 08028dda strh r3,[r6,#0x8]
// 08028ddc ldrb r0,[r4,#0xc]
// 08028dde b 0x08028dae
// 08028de0 ldr r5,[r4,#0x0]
// 08028de2 udiv r9,r7,r5
// 08028de6 mls r10,r5,r9,r7
// 08028dea cmp.w r10,#0x0
// 08028dee beq 0x08028e3e
// 08028df0 add.w r3,r9,#0x1
// 08028df4 adds r5,#0xa
// 08028df6 uxtb r2,r3
// 08028df8 muls r3,r5
// 08028dfa rev16 r7,r7
// 08028dfc cmp r11,r3
// 08028dfe strh r7,[r4,#0xa]
// 08028e00 str r2,[sp,#0x0]
// 08028e02 strb r2,[r4,#0xc]
// 08028e04 bcc 0x08028daa
// 08028e06 mov r7,r6
// 08028e08 movs r1,#0x0
// 08028e0a add.w r11,r4,#0x4
// 08028e0e cmp r1,r9
// 08028e10 bne 0x08028e42
// 08028e12 cmp.w r10,#0x0
// 08028e16 beq 0x08028ddc
// 08028e18 muls r5,r1
// 08028e1a ldr r3,[sp,#0x0]
// 08028e1c adds r2,r6,r5
// 08028e1e strb r3,[r4,#0xd]
// 08028e20 ldr r3,[r4,#0x4]
// 08028e22 str r3,[r6,r5]
// 08028e24 ldr r3,[r4,#0x8]
// 08028e26 adds r5,#0xa
// 08028e28 str r3,[r2,#0x4]
// 08028e2a ldrh r3,[r4,#0xc]
// 08028e2c adds r0,r6,r5
// 08028e2e strh r3,[r2,#0x8]
// 08028e30 ldr r3,[r4,#0x0]
// 08028e32 mov r2,r10
// 08028e34 mla r1,r3,r1,r8
// 08028e38 bl 0x0802238c
// 08028e3c b 0x08028ddc
// 08028e3e mov r3,r9
// 08028e40 b 0x08028df4
// 08028e42 adds r3,r1,#0x1
// 08028e44 strb r3,[r4,#0xd]
// 08028e46 ldr.w r2,[r11,#0x0]
// 08028e4a add.w r0,r7,#0xa
// 08028e4e str r2,[r7,#0x0]
// 08028e50 ldr.w r2,[r11,#0x4]
// 08028e54 str r3,[sp,#0x4]
// 08028e56 str r2,[r7,#0x4]
// 08028e58 ldrh.w r2,[r11,#0x8]
// 08028e5c strh r2,[r7,#0x8]
// 08028e5e ldr r2,[r4,#0x0]
// 08028e60 add r7,r5
// 08028e62 mla r1,r1,r2,r8
// 08028e66 bl 0x0802238c
// 08028e6a ldr r3,[sp,#0x4]
// 08028e6c mov r1,r3
// 08028e6e b 0x08028e0e
// FUNCTION 08027498

void FUN_08027498(void)

{
  undefined4 uStack_48;
  undefined1 auStack_44 [60];
  
  uStack_48 = 0;
  FUN_08035d8c(auStack_44,0,0x3c);
  if (*(int *)PTR_DAT_080274dc + 1 < 2) {
    *(int *)PTR_DAT_080274dc = *(int *)PTR_DAT_080274dc + 1;
  }
  else {
    *(undefined4 *)PTR_DAT_080274dc = 0;
    FUN_080273fc(&uStack_48,0x40);
  }
  if (*(code **)(PTR_DAT_080274e0 + 0x130) != (code *)0x0) {
    (**(code **)(PTR_DAT_080274e0 + 0x130))(500);
  }
  thunk_FUN_0802fec8(500);
  return;
}


// 08027498 push {r4,lr}
// 0802749a movs r4,#0x0
// 0802749c sub sp,#0x40
// 0802749e movs r2,#0x3c
// 080274a0 mov r1,r4
// 080274a2 add r0,sp,#0x4
// 080274a4 str r4,[sp,#0x0]
// 080274a6 bl 0x08035d8c
// 080274aa ldr r2,[0x080274dc]
// 080274ac ldr r3,[r2,#0x0]
// 080274ae adds r3,#0x1
// 080274b0 cmp r3,#0x1
// 080274b2 bgt 0x080274d0
// 080274b4 str r3,[r2,#0x0]
// 080274b6 ldr r3,[0x080274e0]
// 080274b8 ldr.w r3,[r3,#0x130]
// 080274bc cbz r3,0x080274c4
// 080274be mov.w r0,#0x1f4
// 080274c2 blx r3
// 080274c4 mov.w r0,#0x1f4
// 080274c8 bl 0x080273a4
// 080274cc add sp,#0x40
// 080274ce pop {r4,pc}
// 080274d0 movs r1,#0x40
// 080274d2 mov r0,sp
// 080274d4 str r4,[r2,#0x0]
// 080274d6 bl 0x080273fc
// 080274da b 0x080274b6
