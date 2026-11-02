// FUNCTION 08029124

undefined4 FUN_08029124(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  
  piVar1 = DAT_080291dc;
  if ((param_1 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar3 = 0xffffffff;
  }
  else {
    *param_1 = (int)DAT_080291dc;
    *param_2 = 4;
    FUN_08035d8c(piVar1,0,0x4f0);
    iVar5 = 0;
    piVar7 = piVar1;
    iVar9 = DAT_080291e0;
    do {
      iVar4 = 0x43;
      iVar6 = iVar5 + 1;
      *piVar7 = iVar6;
      piVar7[1] = 10;
      piVar7[2] = 0xc;
      piVar7[3] = iVar9;
      piVar7[5] = 0xc;
      piVar2 = piVar1;
      piVar8 = piVar7;
      do {
        piVar8[6] = iVar6;
        piVar8[7] = 0x10;
        piVar8[8] = 0;
        if (iVar5 == 0) {
          piVar2[9] = iVar4;
        }
        else if (iVar5 == 1) {
          piVar2[0x58] = iVar4 + 0x18;
        }
        else if (iVar5 == 2) {
          piVar2[0xa7] = iVar4 + 0x24;
        }
        else {
          piVar2[0xf6] = iVar4 + 0xc;
        }
        iVar4 = iVar4 + 1;
        piVar8 = piVar8 + 4;
        piVar2 = piVar2 + 4;
      } while (iVar4 != 0x4f);
      piVar7[0x46] = iVar6;
      piVar7[0x47] = 0x10;
      piVar7[0x48] = 0;
      piVar7[0x49] = 0;
      piVar7[0x4a] = iVar6;
      piVar7[0x4b] = 0x10;
      piVar7[0x4c] = 0;
      piVar7[0x4d] = 0;
      iVar9 = iVar9 + 0x30;
      piVar7 = piVar7 + 0x4f;
      iVar5 = iVar6;
    } while (iVar6 != 4);
    uVar3 = 0;
  }
  return uVar3;
}


// 08029124 push {r4,r5,r6,r7,r8,r9,r10,lr}
// 08029128 cmp r0,#0x0
// 0802912a beq 0x080291d4
// 0802912c cmp r1,#0x0
// 0802912e beq 0x080291d4
// 08029130 movs r3,#0x4
// 08029132 ldr r6,[0x080291dc]
// 08029134 mov.w r2,#0x4f0
// 08029138 str r6,[r0,#0x0]
// 0802913a str r3,[r1,#0x0]
// 0802913c mov r0,r6
// 0802913e movs r1,#0x0
// 08029140 bl 0x08035d8c
// 08029144 movs r2,#0x0
// 08029146 mov r3,r6
// 08029148 mov.w r9,#0xa
// 0802914c mov.w r8,#0xc
// 08029150 mov.w r12,#0x10
// 08029154 mov r4,r2
// 08029156 ldr r7,[0x080291e0]
// 08029158 mov r0,r6
// 0802915a mov r5,r3
// 0802915c movs r1,#0x43
// 0802915e mov lr,r2
// 08029160 adds r2,#0x1
// 08029162 strd r2,r9,[r3,#0x0]
// 08029166 strd r8,r7,[r3,#0x8]
// 0802916a str.w r8,[r3,#0x14]
// 0802916e strd r2,r12,[r5,#0x18]
// 08029172 str r4,[r5,#0x20]
// 08029174 cmp.w lr,#0x0
// 08029178 bne 0x080291ac
// 0802917a str r1,[r0,#0x24]
// 0802917c adds r1,#0x1
// 0802917e cmp r1,#0x4f
// 08029180 add.w r5,r5,#0x10
// 08029184 add.w r0,r0,#0x10
// 08029188 bne 0x0802916e
// 0802918a cmp r2,#0x4
// 0802918c strd r2,r12,[r3,#0x118]
// 08029190 strd r4,r4,[r3,#0x120]
// 08029194 strd r2,r12,[r3,#0x128]
// 08029198 strd r4,r4,[r3,#0x130]
// 0802919c add.w r7,r7,#0x30
// 080291a0 add.w r3,r3,#0x13c
// 080291a4 bne 0x08029158
// 080291a6 movs r0,#0x0
// 080291a8 pop.w {r4,r5,r6,r7,r8,r9,r10,pc}
// 080291ac cmp.w lr,#0x1
// 080291b0 bne 0x080291bc
// 080291b2 add.w r10,r1,#0x18
// 080291b6 str.w r10,[r0,#0x160]
// 080291ba b 0x0802917c
// 080291bc cmp.w lr,#0x2
// 080291c0 itete eq
// 080291c2 add.eq.w r10,r1,#0x24
// 080291c6 add.ne.w r10,r1,#0xc
// 080291ca str.w.eq r10,[r0,#0x29c]
// 080291ce str.w.ne r10,[r0,#0x3d8]
// 080291d2 b 0x0802917c
// 080291d4 mov.w r0,#0xffffffff
// 080291d8 b 0x080291a8
// FUNCTION 08029418

undefined4 FUN_08029418(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = DAT_08029480;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    *param_1 = DAT_08029480;
    *param_2 = 2;
    FUN_08035d8c(puVar4 + 2,0,0xe8);
    iVar2 = 0;
    *puVar4 = 1;
    puVar4[1] = 9;
    puVar3 = puVar4;
    do {
      iVar2 = iVar2 + 1;
      puVar3[2] = 1;
      puVar3[3] = 0x10;
      puVar3[5] = 0;
      puVar3 = puVar3 + 4;
      *puVar3 = 0;
    } while (iVar2 != 7);
    puVar4[0x1e] = 2;
    puVar4[0x1f] = 9;
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      puVar4[0x20] = 2;
      puVar4[0x21] = 0x10;
      puVar4[0x22] = 0;
      puVar4[0x23] = 0;
      puVar4 = puVar4 + 4;
    } while (iVar2 != 7);
    uVar1 = 0;
  }
  return uVar1;
}


// 08029418 push {r4,r5,r6,lr}
// 0802941a cbz r0,0x08029478
// 0802941c cbz r1,0x08029478
// 0802941e movs r3,#0x2
// 08029420 ldr r4,[0x08029480]
// 08029422 movs r2,#0xe8
// 08029424 str r4,[r0,#0x0]
// 08029426 str r3,[r1,#0x0]
// 08029428 add.w r0,r4,#0x8
// 0802942c movs r1,#0x0
// 0802942e bl 0x08035d8c
// 08029432 movs r5,#0x1
// 08029434 movs r3,#0x9
// 08029436 movs r1,#0x0
// 08029438 strd r5,r3,[r4,#0x0]
// 0802943c mov r2,r4
// 0802943e mov r3,r4
// 08029440 movs r6,#0x10
// 08029442 mov r0,r1
// 08029444 adds r1,#0x1
// 08029446 cmp r1,#0x7
// 08029448 strd r5,r6,[r2,#0x8]
// 0802944c str r0,[r2,#0x14]
// 0802944e str.w r0,[r2,#0x10]!
// 08029452 bne 0x08029444
// 08029454 movs r2,#0x9
// 08029456 movs r0,#0x2
// 08029458 strd r0,r2,[r4,#0x78]
// 0802945c movs r2,#0x0
// 0802945e movs r4,#0x10
// 08029460 mov r1,r2
// 08029462 adds r2,#0x1
// 08029464 cmp r2,#0x7
// 08029466 strd r0,r4,[r3,#0x80]
// 0802946a strd r1,r1,[r3,#0x88]
// 0802946e add.w r3,r3,#0x10
// 08029472 bne 0x08029462
// 08029474 movs r0,#0x0
// 08029476 pop {r4,r5,r6,pc}
// 08029478 mov.w r0,#0xffffffff
// 0802947c b 0x08029476
// FUNCTION 080294cc

undefined4
FUN_080294cc(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = DAT_08029510;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar4 = 0xffffffff;
  }
  else {
    *param_1 = DAT_08029510;
    *param_2 = 6;
    piVar3 = (int *)FUN_08035d8c(uVar4,0,0x60,uVar4,param_4);
    iVar2 = DAT_08029514;
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      bVar1 = *(byte *)(iVar2 + iVar5 * 4 + -3);
      *piVar3 = iVar5;
      piVar3[1] = 2;
      piVar3[3] = 0;
      piVar3[2] = (uint)bVar1;
      piVar3 = piVar3 + 4;
    } while (iVar5 != 6);
    uVar4 = 0;
  }
  return uVar4;
}


// 080294cc push {r3,r4,r5,lr}
// 080294ce cbz r0,0x0802950a
// 080294d0 cbz r1,0x0802950a
// 080294d2 movs r2,#0x6
// 080294d4 ldr r3,[0x08029510]
// 080294d6 movs r5,#0x2
// 080294d8 str r3,[r0,#0x0]
// 080294da str r2,[r1,#0x0]
// 080294dc mov r0,r3
// 080294de movs r1,#0x0
// 080294e0 movs r2,#0x60
// 080294e2 bl 0x08035d8c
// 080294e6 movs r3,#0x0
// 080294e8 mov r4,r3
// 080294ea ldr r1,[0x08029514]
// 080294ec adds r3,#0x1
// 080294ee add.w r2,r1,r3, lsl #0x2
// 080294f2 ldrb.w r2,[r2,#-0x3]
// 080294f6 cmp r3,#0x6
// 080294f8 strd r3,r5,[r0,#0x0]
// 080294fc str r4,[r0,#0xc]
// 080294fe str r2,[r0,#0x8]
// 08029500 add.w r0,r0,#0x10
// 08029504 bne 0x080294ec
// 08029506 movs r0,#0x0
// 08029508 pop {r3,r4,r5,pc}
// 0802950a mov.w r0,#0xffffffff
// 0802950e b 0x08029508
// FUNCTION 08029560

undefined4
FUN_08029560(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_080295a8;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    *param_1 = DAT_080295a8;
    *param_2 = 0x10;
    piVar1 = (int *)FUN_08035d8c(uVar2,0,0x280,uVar2,param_4);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      *piVar1 = iVar3;
      piVar1[1] = 3;
      piVar1[6] = iVar3;
      piVar1[7] = 0x10;
      piVar1[8] = 0;
      piVar1[9] = 0;
      piVar1[2] = iVar3;
      piVar1[3] = 2;
      piVar1[5] = 0;
      piVar1 = piVar1 + 10;
    } while (iVar3 != 0x10);
    uVar2 = 0;
  }
  return uVar2;
}


// 08029560 push {r3,r4,r5,lr}
// 08029562 cbz r0,0x080295a2
// 08029564 cbz r1,0x080295a2
// 08029566 movs r4,#0x10
// 08029568 ldr r3,[0x080295a8]
// 0802956a mov.w r2,#0x280
// 0802956e str r3,[r0,#0x0]
// 08029570 mov r0,r3
// 08029572 str r4,[r1,#0x0]
// 08029574 movs r1,#0x0
// 08029576 bl 0x08035d8c
// 0802957a movs r3,#0x0
// 0802957c movs r5,#0x3
// 0802957e mov r2,r3
// 08029580 movs r1,#0x2
// 08029582 adds r3,#0x1
// 08029584 cmp r3,#0x10
// 08029586 strd r3,r5,[r0,#0x0]
// 0802958a strd r3,r4,[r0,#0x18]
// 0802958e strd r2,r2,[r0,#0x20]
// 08029592 strd r3,r1,[r0,#0x8]
// 08029596 str r2,[r0,#0x14]
// 08029598 add.w r0,r0,#0x28
// 0802959c bne 0x08029582
// 0802959e movs r0,#0x0
// 080295a0 pop {r3,r4,r5,pc}
// 080295a2 mov.w r0,#0xffffffff
// 080295a6 b 0x080295a0
// FUNCTION 0802960c

undefined4 FUN_0802960c(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_08029638;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    *param_1 = DAT_08029638;
    *param_2 = 6;
    uVar1 = FUN_08035d8c(uVar1,0,0x360);
    FUN_0802cf70(uVar1,6);
    uVar1 = 0;
  }
  return uVar1;
}


// 0802960c push {r4,lr}
// 0802960e cbz r0,0x08029630
// 08029610 cbz r1,0x08029630
// 08029612 movs r4,#0x6
// 08029614 ldr r3,[0x08029638]
// 08029616 mov.w r2,#0x360
// 0802961a str r3,[r0,#0x0]
// 0802961c mov r0,r3
// 0802961e str r4,[r1,#0x0]
// 08029620 movs r1,#0x0
// 08029622 bl 0x08035d8c
// 08029626 mov r1,r4
// 08029628 bl 0x0802cf70
// 0802962c movs r0,#0x0
// 0802962e pop {r4,pc}
// 08029630 mov.w r0,#0xffffffff
// 08029634 b 0x0802962e
// FUNCTION 08029994

undefined4 FUN_08029994(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_080299dc;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    *param_1 = DAT_080299dc;
    *param_2 = 4;
    piVar1 = (int *)FUN_08035d8c(uVar2,0,0xa0);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      *piVar1 = iVar3;
      piVar1[1] = 4;
      piVar1[2] = iVar3;
      piVar1[3] = 0x10;
      piVar1[4] = 0;
      piVar1[5] = 0;
      piVar1[6] = iVar3;
      piVar1[7] = 0x10;
      piVar1[8] = 0;
      piVar1[9] = 0;
      piVar1 = piVar1 + 10;
    } while (iVar3 != 4);
    uVar2 = 0;
  }
  return uVar2;
}


// 08029994 push {r4,lr}
// 08029996 cbz r0,0x080299d4
// 08029998 cbz r1,0x080299d4
// 0802999a movs r4,#0x4
// 0802999c ldr r3,[0x080299dc]
// 0802999e movs r2,#0xa0
// 080299a0 str r3,[r0,#0x0]
// 080299a2 mov r0,r3
// 080299a4 str r4,[r1,#0x0]
// 080299a6 movs r1,#0x0
// 080299a8 bl 0x08035d8c
// 080299ac movs r3,#0x0
// 080299ae movs r1,#0x10
// 080299b0 mov r2,r3
// 080299b2 adds r3,#0x1
// 080299b4 cmp r3,#0x4
// 080299b6 strd r3,r4,[r0,#0x0]
// 080299ba strd r3,r1,[r0,#0x8]
// 080299be strd r2,r2,[r0,#0x10]
// 080299c2 strd r3,r1,[r0,#0x18]
// 080299c6 strd r2,r2,[r0,#0x20]
// 080299ca add.w r0,r0,#0x28
// 080299ce bne 0x080299b2
// 080299d0 movs r0,#0x0
// 080299d2 pop {r4,pc}
// 080299d4 mov.w r0,#0xffffffff
// 080299d8 b 0x080299d2
// FUNCTION 08028330

undefined4 FUN_08028330(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int *local_28;
  int local_24;
  int iStack_20;
  int local_1c;
  
  FUN_08035d8c(&local_2c,0,0x14);
  FUN_080312f8(&local_3c,param_2,param_3);
  FUN_08031d48(&local_3c,DAT_080283b0,&local_2c);
  if ((*param_1 == 0xff) || (*param_1 == local_24)) {
    if (param_4 == 0) {
      local_44 = param_1[1];
      local_2c = DAT_080283b4;
      local_28 = &local_44;
      local_40 = param_4;
      local_24 = param_4;
      iStack_20 = param_4;
      local_1c = param_4;
      FUN_080312f8(&local_58,param_2,param_3);
      local_3c = local_58;
      uStack_38 = uStack_54;
      uStack_34 = uStack_50;
      uStack_30 = uStack_4c;
      FUN_08031d48(&local_3c,DAT_080283b0,&local_2c);
      param_1[2] = local_40;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// 08028330 push {r4,r5,r6,r7,r8,lr}
// 08028334 mov r7,r1
// 08028336 mov r8,r2
// 08028338 mov r6,r0
// 0802833a sub sp,#0x40
// 0802833c movs r2,#0x14
// 0802833e movs r1,#0x0
// 08028340 add r4,sp,#0x1c
// 08028342 add r0,sp,#0x2c
// 08028344 mov r5,r3
// 08028346 bl 0x08035d8c
// 0802834a mov r2,r8
// 0802834c mov r1,r7
// 0802834e mov r0,r4
// 08028350 bl 0x080312f8
// 08028354 mov r0,r4
// 08028356 ldr r1,[0x080283b0]
// 08028358 add r2,sp,#0x2c
// 0802835a bl 0x08031d48
// 0802835e ldr r3,[r6,#0x0]
// 08028360 cmp r3,#0xff
// 08028362 beq 0x0802836a
// 08028364 ldr r2,[sp,#0x34]
// 08028366 cmp r3,r2
// 08028368 bne 0x080283a6
// 0802836a cbnz r5,0x080283a2
// 0802836c strd r5,r5,[sp,#0x34]
// 08028370 str r5,[sp,#0x3c]
// 08028372 str r5,[sp,#0x18]
// 08028374 mov r5,sp
// 08028376 ldr r3,[r6,#0x4]
// 08028378 mov r2,r8
// 0802837a str r3,[sp,#0x14]
// 0802837c ldr r3,[0x080283b4]
// 0802837e mov r1,r7
// 08028380 mov r0,r5
// 08028382 str r3,[sp,#0x2c]
// 08028384 add r3,sp,#0x14
// 08028386 str r3,[sp,#0x30]
// 08028388 bl 0x080312f8
// 0802838c ldm.w r5,{r0,r1,r2,r3}
// 08028390 stm r4,{r0,r1,r2,r3}
// 08028394 mov r0,r4
// 08028396 ldr r1,[0x080283b0]
// 08028398 add r2,sp,#0x2c
// 0802839a bl 0x08031d48
// 0802839e ldr r3,[sp,#0x18]
// 080283a0 str r3,[r6,#0x8]
// 080283a2 movs r0,#0x1
// 080283a4 b 0x080283a8
// 080283a6 movs r0,#0x0
// 080283a8 add sp,#0x40
// 080283aa pop.w {r4,r5,r6,r7,r8,pc}
// FUNCTION 08028b84

undefined4 FUN_08028b84(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  int *local_24;
  undefined1 auStack_20 [20];
  
  local_34 = param_1[1];
  local_28 = DAT_08028bc8;
  local_24 = &local_34;
  local_30 = 0;
  local_2c = 0;
  FUN_080312f8(auStack_20);
  iVar1 = FUN_08031d48(auStack_20,DAT_08028bcc,&local_2c);
  uVar2 = 0;
  if ((iVar1 != 0) && ((*param_1 == 0xff || (uVar2 = 0, *param_1 == local_2c)))) {
    param_1[2] = local_30;
    uVar2 = 1;
  }
  return uVar2;
}


// 08028b84 push {r4,r5,lr}
// 08028b86 movs r4,#0x0
// 08028b88 ldr r3,[r0,#0x4]
// 08028b8a sub sp,#0x2c
// 08028b8c str r3,[sp,#0x4]
// 08028b8e ldr r3,[0x08028bc8]
// 08028b90 mov r5,r0
// 08028b92 str r3,[sp,#0x10]
// 08028b94 add r0,sp,#0x18
// 08028b96 add r3,sp,#0x4
// 08028b98 strd r4,r4,[sp,#0x8]
// 08028b9c str r3,[sp,#0x14]
// 08028b9e bl 0x080312f8
// 08028ba2 ldr r1,[0x08028bcc]
// 08028ba4 add r2,sp,#0xc
// 08028ba6 add r0,sp,#0x18
// 08028ba8 bl 0x08031d48
// 08028bac cbz r0,0x08028bc0
// 08028bae ldr r3,[r5,#0x0]
// 08028bb0 cmp r3,#0xff
// 08028bb2 beq 0x08028bba
// 08028bb4 ldr r2,[sp,#0xc]
// 08028bb6 cmp r3,r2
// 08028bb8 bne 0x08028bc4
// 08028bba movs r0,#0x1
// 08028bbc ldr r3,[sp,#0x8]
// 08028bbe str r3,[r5,#0x8]
// 08028bc0 add sp,#0x2c
// 08028bc2 pop {r4,r5,pc}
// 08028bc4 mov r0,r4
// 08028bc6 b 0x08028bc0
// FUNCTION 08026c54

undefined4 FUN_08026c54(uint param_1,char *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint in_stack_ffffff0c;
  uint local_d8;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  uint local_c0;
  uint uStack_bc;
  undefined1 auStack_b8 [64];
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined1 auStack_60 [68];
  
  if ((((param_1 != 0x160) && (param_1 != 0x701)) && (param_1 != 0x123)) &&
     ((param_1 != 0x80 && (param_1 != 0x1f0)))) {
    return 0;
  }
  local_d0 = 0;
  FUN_08035d8c(&uStack_cc,0,0x54);
  puVar1 = DAT_08026da4;
  puVar2 = &local_d0;
  if (param_1 != 0x160) {
    if (param_1 < 0x161) {
      if (param_1 == 0x80) {
        *(undefined1 *)(DAT_08026d98 + 0xf8) = 1;
        return 0;
      }
      if (param_1 != 0x123) {
        return 0;
      }
      local_78 = 0;
      FUN_08035d8c(&uStack_74,0,0x54,0x123,4,0,0x58,param_3,0x123,in_stack_ffffff0c & 0xffffff00,
                   puVar2);
      FUN_08035d8c(puVar1,0,0x40);
      *puVar1 = 0xf9;
      FUN_0802238c(puVar1 + 1,param_2,param_3);
      local_d8 = local_d8 & 0xffffff00;
      local_78 = 1;
      uStack_74 = 0;
      uStack_70 = 0x58;
      uStack_6c = 0x40;
      local_68 = 0;
      uStack_64 = local_d8;
      FUN_0802238c(auStack_60,puVar1,param_3);
      puVar2 = &local_78;
      puVar3 = DAT_08026da0;
      goto LAB_08026d78;
    }
    if (param_1 == 0x1f0) {
      *(char *)(DAT_08026d98 + 0xf9) = *(char *)(DAT_08026d98 + 0xf9) + '\x01';
      return 0;
    }
    if (param_1 != 0x701) {
      return 0;
    }
    if (((param_2[4] != '\x02') || (param_2[5] != '\x04')) &&
       (((byte)param_2[3] != 0xff && ((uint)(byte)param_2[3] != *(uint *)(DAT_08026d98 + 0x20))))) {
      if (*param_2 != -0x80) {
        return 0;
      }
      if (-1 < (int)((uint)(byte)param_2[1] << 0x19)) {
        return 0;
      }
    }
  }
  local_d0 = 4;
  uStack_cc = 0;
  uStack_c8 = 0x58;
  uStack_c4 = param_3;
  local_c0 = param_1;
  uStack_bc = in_stack_ffffff0c & 0xffffff00;
  FUN_0802238c(auStack_b8,param_2,param_3);
  puVar3 = DAT_08026d9c;
LAB_08026d78:
  FUN_08027278(*puVar3,puVar2,0x58);
  return 0;
}


// 08026c54 push {r4,r5,r6,r7,r8,r9,lr}
// 08026c58 cmp.w r0,#0x160
// 08026c5c mov r4,r0
// 08026c5e mov r6,r1
// 08026c60 mov r7,r2
// 08026c62 sub sp,#0xec
// 08026c64 beq 0x08026c80
// 08026c66 movw r3,#0x701
// 08026c6a cmp r0,r3
// 08026c6c beq 0x08026c80
// 08026c6e movw r3,#0x123
// 08026c72 cmp r0,r3
// 08026c74 beq 0x08026c80
// 08026c76 cmp r0,#0x80
// 08026c78 beq 0x08026c80
// 08026c7a cmp.w r0,#0x1f0
// 08026c7e bne 0x08026cbe
// 08026c80 movs r5,#0x0
// 08026c82 movs r2,#0x54
// 08026c84 mov r1,r5
// 08026c86 add r0,sp,#0x3c
// 08026c88 mov.w r9,#0x58
// 08026c8c str r5,[sp,#0x38]
// 08026c8e bl 0x08035d8c
// 08026c92 movs r3,#0x4
// 08026c94 add.w r8,sp,#0x38
// 08026c98 cmp.w r4,#0x160
// 08026c9c strd r3,r5,[sp,#0x0]
// 08026ca0 strd r9,r7,[sp,#0x8]
// 08026ca4 str r4,[sp,#0x10]
// 08026ca6 strb.w r5,[sp,#0x14]
// 08026caa str.w r8,[sp,#0x18]
// 08026cae beq 0x08026cfa
// 08026cb0 bhi 0x08026cc6
// 08026cb2 cmp r4,#0x80
// 08026cb4 beq 0x08026d80
// 08026cb6 movw r3,#0x123
// 08026cba cmp r4,r3
// 08026cbc beq 0x08026d1c
// 08026cbe movs r0,#0x0
// 08026cc0 add sp,#0xec
// 08026cc2 pop.w {r4,r5,r6,r7,r8,r9,pc}
// 08026cc6 cmp.w r4,#0x1f0
// 08026cca beq 0x08026d8a
// 08026ccc movw r3,#0x701
// 08026cd0 cmp r4,r3
// 08026cd2 bne 0x08026cbe
// 08026cd4 ldrb r3,[r6,#0x4]
// 08026cd6 cmp r3,#0x2
// 08026cd8 bne 0x08026ce0
// 08026cda ldrb r3,[r6,#0x5]
// 08026cdc cmp r3,#0x4
// 08026cde beq 0x08026cfa
// 08026ce0 ldrb r3,[r6,#0x3]
// 08026ce2 cmp r3,#0xff
// 08026ce4 beq 0x08026cfa
// 08026ce6 ldr r2,[0x08026d98]
// 08026ce8 ldr r2,[r2,#0x20]
// 08026cea cmp r3,r2
// 08026cec beq 0x08026cfa
// 08026cee ldrb r3,[r6,#0x0]
// 08026cf0 cmp r3,#0x80
// 08026cf2 bne 0x08026cbe
// 08026cf4 ldrb r3,[r6,#0x1]
// 08026cf6 lsls r3,r3,#0x19
// 08026cf8 bpl 0x08026cbe
// 08026cfa mov r4,r8
// 08026cfc mov r5,sp
// 08026cfe ldmia r5!,{r0,r1,r2,r3}
// 08026d00 stmia r4!,{r0,r1,r2,r3}
// 08026d02 ldm.w r5,{r0,r1}
// 08026d06 mov r2,r7
// 08026d08 stm r4,{r0,r1}
// 08026d0c mov r1,r6
// 08026d0e add r0,sp,#0x50
// 08026d10 bl 0x0802238c
// 08026d14 movs r2,#0x58
// 08026d16 mov r1,r8
// 08026d18 ldr r3,[0x08026d9c]
// 08026d1a b 0x08026d78
// 08026d1c movs r4,#0x40
// 08026d1e ldr.w r8,[0x08026da4]
// 08026d22 mov r1,r5
// 08026d24 movs r2,#0x54
// 08026d26 add r0,sp,#0x94
// 08026d28 str r5,[sp,#0x90]
// 08026d2a bl 0x08035d8c
// 08026d2e mov r2,r4
// 08026d30 mov r1,r5
// 08026d32 mov r0,r8
// 08026d34 bl 0x08035d8c
// 08026d38 movs r3,#0xf9
// 08026d3a mov r0,r8
// 08026d3c mov r2,r7
// 08026d3e mov r1,r6
// 08026d40 strb.w r3,[r0],#0x1
// 08026d44 bl 0x0802238c
// 08026d48 movs r3,#0x1
// 08026d4a strd r9,r4,[sp,#0x24]
// 08026d4e strd r3,r5,[sp,#0x1c]
// 08026d52 str r5,[sp,#0x2c]
// 08026d54 strb.w r5,[sp,#0x30]
// 08026d58 add r4,sp,#0x90
// 08026d5a add r5,sp,#0x1c
// 08026d5c ldmia r5!,{r0,r1,r2,r3}
// 08026d5e stmia r4!,{r0,r1,r2,r3}
// 08026d60 ldm.w r5,{r0,r1}
// 08026d64 mov r2,r7
// 08026d66 stm r4,{r0,r1}
// 08026d6a mov r1,r8
// 08026d6c add r0,sp,#0xa8
// 08026d6e bl 0x0802238c
// 08026d72 mov r2,r9
// 08026d74 ldr r3,[0x08026da0]
// 08026d76 add r1,sp,#0x90
// 08026d78 ldr r0,[r3,#0x0]
// 08026d7a bl 0x08027278
// 08026d7e b 0x08026cbe
// 08026d80 movs r2,#0x1
// 08026d82 ldr r3,[0x08026d98]
// 08026d84 strb.w r2,[r3,#0xf8]
// 08026d88 b 0x08026cbe
// 08026d8a ldr r2,[0x08026d98]
// 08026d8c ldrb.w r3,[r2,#0xf9]
// 08026d90 adds r3,#0x1
// 08026d92 strb.w r3,[r2,#0xf9]
// 08026d96 b 0x08026cbe
