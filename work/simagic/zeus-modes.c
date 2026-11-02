// FUNCTION 08023438

undefined4 FUN_08023438(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  byte bVar11;
  int iVar12;
  code *pcVar13;
  short sVar14;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  uStack_30 = param_1;
  iStack_2c = param_2;
  uStack_28 = param_3;
  FUN_080306a0();
  sVar14 = 0xb;
  FUN_0802b7ec();
  uVar7 = DAT_08023724;
  puVar1 = DAT_08023720;
  uVar8 = DAT_0802371c;
  while (sVar14 = sVar14 + -1, sVar14 != 0) {
    iVar9 = FUN_0802b814(7);
    if ((iVar9 == 0) && (iVar9 = FUN_0802b814(8), iVar9 == 0)) {
      FUN_080273a8(uVar8);
      puVar3 = DAT_0802376c;
      *puVar1 = uVar7;
      (*(code *)*puVar3)();
      uVar2 = DAT_0802372c;
      *(undefined4 *)(DAT_08023770 + 8) = 0x5a;
      FUN_08026e60(uVar2);
      FUN_0802b9b0();
      FUN_0802cacc();
      FUN_08024190();
    }
    thunk_FUN_0802fec8(10);
  }
  FUN_0802b800();
  iVar9 = DAT_08023728;
  *DAT_08023720 = DAT_08023724;
  iStack_2c = FUN_08026bb4();
  FUN_0802333c();
  FUN_08026c08(0,0,iStack_2c,DAT_0802372c);
  *(undefined4 *)(iVar9 + 0xc) = DAT_08023730;
  FUN_0802cacc();
  iVar6 = FUN_0802b814(0xf);
  iVar5 = iStack_2c;
  if (iVar6 == 0) {
    FUN_080273a8(DAT_080238f0);
    uVar8 = FUN_080221e0();
    FUN_080273d8(DAT_080238f4);
    FUN_080275d8(DAT_080238f8);
    FUN_080221e8(uVar8);
    FUN_080273f0(DAT_080238f4);
    FUN_080275f0(DAT_080238f8);
    FUN_08023d30();
    return 0;
  }
  *(undefined4 *)(iStack_2c + 4) = 1;
  FUN_08035d8c(iStack_2c + 0xa4,0,0x4c);
  *(undefined4 *)(iVar5 + 0xa0) = 1;
  *(undefined1 *)(iVar5 + 0xa4) = 1;
  uVar7 = FUN_08028fac();
  FUN_080273a8(DAT_08023734,uVar7);
  iVar6 = DAT_0802373c;
  uVar8 = DAT_08023738;
  *(undefined4 *)(iVar5 + 0xd8) = DAT_08023738;
  *(int *)(iVar5 + 0xdc) = iVar6;
  *(undefined4 *)(iVar5 + 0xe0) = uVar8;
  *(int *)(iVar5 + 0xe4) = iVar6 + 3;
  uVar8 = DAT_08023740;
  *(undefined4 *)(iVar5 + 0xc0) = 1;
  *(undefined4 *)(iVar5 + 0xc4) = uVar7;
  *(undefined4 *)(iVar5 + 0xe8) = uVar8;
  uVar8 = DAT_08023744;
  *(undefined1 *)(iVar5 + 0xd4) = 1;
  *(undefined4 *)(iVar5 + 0xec) = uVar8;
  FUN_080270e6();
  uVar8 = FUN_080221e0();
  FUN_080273d8(DAT_08023748);
  FUN_08027598(DAT_0802374c);
  FUN_080275d8(DAT_08023750);
  FUN_08027ef0(DAT_08023754);
  FUN_08027f74(DAT_08023758);
  FUN_0802816c(DAT_0802375c);
  FUN_08028004(DAT_08023760);
  FUN_080281b0(DAT_08023764);
  FUN_080244d0(DAT_08023768);
  FUN_080221e8(uVar8);
  FUN_080275b0(DAT_0802374c);
  FUN_08027f8c(DAT_08023758);
  iVar5 = iStack_2c;
  uVar8 = DAT_08023774;
  uVar4 = (undefined2)uStack_30;
  uStack_30 = uStack_30 & 0xffff;
  switch(*(undefined2 *)(iVar9 + 0x14)) {
  case 1:
    *(undefined4 *)(iStack_2c + 4) = 1;
    uStack_30 = CONCAT22(1,uVar4);
    break;
  case 2:
    *(undefined4 *)(iStack_2c + 4) = 1;
    uStack_30 = CONCAT22(2,uVar4);
    uVar8 = DAT_08023788;
    break;
  case 3:
    *(undefined4 *)(iStack_2c + 4) = 1;
    uStack_30 = CONCAT22(3,uVar4);
    uVar8 = DAT_0802378c;
    break;
  case 4:
    sVar14 = 0x9c4;
    while (uVar8 = DAT_08023794, sVar14 = sVar14 + -1, sVar14 != 0) {
      if (*(char *)(*(int *)(iVar9 + 0x17) + 0xce) == '\x03') {
        thunk_FUN_0802fec8(1000);
        *(undefined4 *)(iVar5 + 4) = 1;
        uStack_30 = CONCAT22(2,(undefined2)uStack_30);
        uVar8 = DAT_08023790;
        goto LAB_08023588;
      }
      thunk_FUN_0802fec8(1);
    }
    *(undefined4 *)(iVar5 + 4) = 4;
    uStack_30 = CONCAT22(4,(undefined2)uStack_30);
    break;
  default:
    *(undefined4 *)(iStack_2c + 4) = 1;
    uStack_30 = CONCAT22(3,uVar4);
    uVar8 = DAT_08023798;
  }
LAB_08023588:
  FUN_080273a8(uVar8);
  uVar8 = DAT_08023778;
  if (*(int *)(iVar5 + 4) == 1) {
    if (*(char *)(iVar5 + 0xf8) != '\x01') goto LAB_080235a6;
    *(undefined4 *)(iVar5 + 4) = 9;
  }
  else {
    if ((*(int *)(iVar5 + 4) != 4) || (*(char *)(iVar5 + 0xf8) != '\0')) goto LAB_080235a6;
    FUN_0803453e(DAT_0802379c,2);
    FUN_0802fec8(100);
    *(undefined1 *)(iVar9 + 0x15) = 0;
    *(undefined1 *)(iVar9 + 0x14) = 1;
    uVar8 = DAT_08023774;
    *(undefined4 *)(iVar5 + 4) = 1;
    uStack_30 = CONCAT22(1,(undefined2)uStack_30);
  }
  FUN_080273a8(uVar8);
LAB_080235a6:
  iVar6 = DAT_0802377c;
  *(undefined4 *)(iVar5 + 0x7c) = *(undefined4 *)(iVar5 + 4);
  (**(code **)(iVar6 + 8))(3,(int)&uStack_30 + 2,1);
  FUN_080273f0(DAT_08023748);
  FUN_080275f0(DAT_08023750);
  FUN_08027f08(DAT_08023754);
  FUN_08028184(DAT_0802375c);
  FUN_0802801c(DAT_08023760);
  FUN_080281c8(DAT_08023764);
  FUN_0802456c(DAT_08023768);
  FUN_08026c50(0);
  FUN_08026c4c(&iStack_2c);
  thunk_FUN_0802fec8(5000);
  iVar5 = iStack_2c;
  uVar2 = DAT_080237a4;
  uVar7 = DAT_080237a0;
  uVar8 = DAT_08023780;
  uStack_30 = uStack_30 & 0xffff;
  do {
    uVar10 = DAT_08023784;
    iVar12 = *(int *)(iVar5 + 4);
    if (*(char *)(*(int *)(iVar9 + 0x17) + 0xce) == '\x03') {
      if (iVar12 == 1) {
        if (*(char *)(iVar5 + 0xf8) == '\x01') {
          *(undefined4 *)(iVar5 + 4) = 9;
          *(undefined4 *)(iVar5 + 0x7c) = 9;
          FUN_08023308(uVar10);
        }
      }
      else {
        if (iVar12 == 9) {
          iVar12 = FUN_0803454c(uVar7,0x40);
          if (iVar12 != 0) goto LAB_08023634;
          FUN_0802fb48();
          (**(code **)(iVar9 + 4))();
          sVar14 = 5000;
          FUN_0802fb64();
          while (sVar14 = sVar14 + -1, sVar14 != 0) {
            if (*(char *)(*(int *)(iVar9 + 0x17) + 0xce) == '\x03') {
              thunk_FUN_0802fec8(200);
              break;
            }
            thunk_FUN_0802fec8(1);
          }
          *(undefined1 *)(iVar5 + 0xf8) = 0;
          *(undefined4 *)(iVar5 + 4) = 1;
          *(undefined4 *)(iVar5 + 0x7c) = 1;
          FUN_080273a8(uVar2);
          pcVar13 = *(code **)(iVar6 + 8);
          *(undefined1 *)(iVar9 + 0x14) = 3;
          *(undefined1 *)(iVar9 + 0x15) = 0;
          uStack_30 = CONCAT22(3,(undefined2)uStack_30);
        }
        else {
          *(undefined4 *)(iVar5 + 4) = 1;
          uVar10 = DAT_080238e0;
          if (*(char *)(iVar5 + 0xf8) == '\x01') {
            *(undefined4 *)(iVar5 + 4) = 9;
          }
          *(undefined4 *)(iVar5 + 0x7c) = *(undefined4 *)(iVar5 + 4);
          FUN_080273a8(uVar10);
          iVar12 = FUN_0803454c(DAT_080238e4,1);
          uVar10 = DAT_080238e8;
          if (iVar12 != 1) {
            uVar10 = DAT_080238ec;
          }
          *(undefined1 *)(iVar9 + 0x14) = 3;
          *(undefined1 *)(iVar9 + 0x15) = 0;
          uStack_30 = CONCAT22(3,(undefined2)uStack_30);
          FUN_080273a8(uVar10);
          pcVar13 = *(code **)(iVar6 + 8);
        }
LAB_0802385e:
        (*pcVar13)(3,(int)&uStack_30 + 2,1);
      }
    }
    else if (iVar12 != 4) {
      *(undefined4 *)(iVar5 + 4) = 4;
      *(undefined4 *)(iVar5 + 0x7c) = 4;
      FUN_080273a8(uVar8);
      *(undefined4 *)(iVar5 + 0xf4) = 1;
      *(undefined1 *)(iVar9 + 0x15) = 0;
      *(undefined1 *)(iVar9 + 0x14) = 4;
      FUN_0802652c();
      pcVar13 = *(code **)(iVar6 + 8);
      uStack_30 = CONCAT22(4,(undefined2)uStack_30);
      goto LAB_0802385e;
    }
LAB_08023634:
    if ((*(char *)(*(int *)(iVar9 + 0x17) + 0xce) == '\x03') &&
       (bVar11 = *(char *)(iVar9 + 0x16) + 1, *(byte *)(iVar9 + 0x16) = bVar11, 1 < bVar11)) {
      FUN_0802fb48();
      (**(code **)(iVar9 + 4))();
      sVar14 = 5000;
      FUN_0802fb64();
      while (sVar14 = sVar14 + -1, sVar14 != 0) {
        if (*(char *)(*(int *)(iVar9 + 0x17) + 0xce) == '\x03') {
          thunk_FUN_0802fec8(200);
          break;
        }
        thunk_FUN_0802fec8(1);
      }
    }
    thunk_FUN_0802fec8(500);
  } while( true );
}


// 08023438 push {r0,r1,r2,r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 0802343c bl 0x080306a0
// 08023440 movs r6,#0xb
// 08023442 bl 0x0802b7ec
// 08023446 ldr r4,[0x0802371c]
// 08023448 ldr r5,[0x08023720]
// 0802344a ldr r7,[0x08023724]
// 0802344c subs r6,#0x1
// 0802344e uxth r6,r6
// 08023450 cmp r6,#0x0
// 08023452 bne 0x08023542
// 08023454 bl 0x0802b800
// 08023458 ldr r3,[0x08023720]
// 0802345a ldr r2,[0x08023724]
// 0802345c ldr r4,[0x08023728]
// 0802345e str r2,[r3,#0x0]
// 08023460 bl 0x08026bb4
// 08023464 str r0,[sp,#0x4]
// 08023466 bl 0x0802333c
// 0802346a mov r1,r6
// 0802346c ldr r3,[0x0802372c]
// 0802346e ldr r2,[sp,#0x4]
// 08023470 mov r0,r6
// 08023472 bl 0x08026c08
// 08023476 ldr r3,[0x08023730]
// 08023478 str r3,[r4,#0xc]
// 0802347a bl 0x0802cacc
// 0802347e movs r0,#0xf
// 08023480 bl 0x0802b814
// 08023484 cmp r0,#0x0
// 08023486 beq.w 0x080238a8
// 0802348a movs r7,#0x1
// 0802348c ldr r5,[sp,#0x4]
// 0802348e movs r2,#0x4c
// 08023490 mov r1,r6
// 08023492 str r7,[r5,#0x4]
// 08023494 add.w r0,r5,#0xa4
// 08023498 bl 0x08035d8c
// 0802349c str.w r7,[r5,#0xa0]
// 080234a0 strb.w r7,[r5,#0xa4]
// 080234a4 bl 0x08028fac
// 080234a8 mov r8,r0
// 080234aa mov r1,r0
// 080234ac ldr r0,[0x08023734]
// 080234ae bl 0x080273a8
// 080234b2 ldr r2,[0x08023738]
// 080234b4 ldr r3,[0x0802373c]
// 080234b6 str.w r2,[r5,#0xd8]
// 080234ba strd r3,r2,[r5,#0xdc]
// 080234be adds r3,#0x3
// 080234c0 str.w r3,[r5,#0xe4]
// 080234c4 ldr r3,[0x08023740]
// 080234c6 strd r7,r8,[r5,#0xc0]
// 080234ca str.w r3,[r5,#0xe8]
// 080234ce ldr r3,[0x08023744]
// 080234d0 strb.w r7,[r5,#0xd4]
// 080234d4 str.w r3,[r5,#0xec]
// 080234d8 bl 0x080270e6
// 080234dc bl 0x080221e0
// 080234e0 mov r5,r0
// 080234e2 ldr r0,[0x08023748]
// 080234e4 bl 0x080273d8
// 080234e8 ldr r0,[0x0802374c]
// 080234ea bl 0x08027598
// 080234ee ldr r0,[0x08023750]
// 080234f0 bl 0x080275d8
// 080234f4 ldr r0,[0x08023754]
// 080234f6 bl 0x08027ef0
// 080234fa ldr r0,[0x08023758]
// 080234fc bl 0x08027f74
// 08023500 ldr r0,[0x0802375c]
// 08023502 bl 0x0802816c
// 08023506 ldr r0,[0x08023760]
// 08023508 bl 0x08028004
// 0802350c ldr r0,[0x08023764]
// 0802350e bl 0x080281b0
// 08023512 ldr r0,[0x08023768]
// 08023514 bl 0x080244d0
// 08023518 mov r0,r5
// 0802351a bl 0x080221e8
// 0802351e ldr r0,[0x0802374c]
// 08023520 bl 0x080275b0
// 08023524 ldr r0,[0x08023758]
// 08023526 bl 0x08027f8c
// 0802352a strh.w r6,[sp,#0x2]
// 0802352e ldrh r3,[r4,#0x14]
// 08023530 ldr r5,[sp,#0x4]
// 08023532 subs r3,#0x1
// 08023534 cmp r3,#0x3
// 08023536 bhi.w 0x080236e2
// 0802353a tbb [pc,r3]
// 08023542 movs r0,#0x7
// 08023544 bl 0x0802b814
// 08023548 cbnz r0,0x08023578
// 0802354a movs r0,#0x8
// 0802354c bl 0x0802b814
// 08023550 cbnz r0,0x08023578
// 08023552 mov r0,r4
// 08023554 bl 0x080273a8
// 08023558 ldr r3,[0x0802376c]
// 0802355a str r7,[r5,#0x0]
// 0802355c ldr r3,[r3,#0x0]
// 0802355e blx r3
// 08023560 movs r2,#0x5a
// 08023562 ldr r3,[0x08023770]
// 08023564 ldr r0,[0x0802372c]
// 08023566 str r2,[r3,#0x8]
// 08023568 bl 0x08026e60
// 0802356c bl 0x0802b9b0
// 08023570 bl 0x0802cacc
// 08023574 bl 0x08024190
// 08023578 movs r0,#0xa
// 0802357a bl 0x080273a4
// 0802357e b 0x0802344c
// 08023580 ldr r0,[0x08023774]
// 08023582 str r7,[r5,#0x4]
// 08023584 strh.w r7,[sp,#0x2]
// 08023588 bl 0x080273a8
// 0802358c ldr r3,[r5,#0x4]
// 0802358e cmp r3,#0x1
// 08023590 bne.w 0x080236ee
// 08023594 ldrb.w r3,[r5,#0xf8]
// 08023598 cmp r3,#0x1
// 0802359a bne 0x080235a6
// 0802359c movs r3,#0x9
// 0802359e ldr r0,[0x08023778]
// 080235a0 str r3,[r5,#0x4]
// 080235a2 bl 0x080273a8
// 080235a6 ldr r3,[r5,#0x4]
// 080235a8 ldr r6,[0x0802377c]
// 080235aa movs r2,#0x1
// 080235ac add.w r1,sp,#0x2
// 080235b0 str r3,[r5,#0x7c]
// 080235b2 movs r0,#0x3
// 080235b4 ldr r3,[r6,#0x8]
// 080235b6 blx r3
// 080235b8 ldr r0,[0x08023748]
// 080235ba bl 0x080273f0
// 080235be ldr r0,[0x08023750]
// 080235c0 bl 0x080275f0
// 080235c4 ldr r0,[0x08023754]
// 080235c6 bl 0x08027f08
// 080235ca ldr r0,[0x0802375c]
// 080235cc bl 0x08028184
// 080235d0 ldr r0,[0x08023760]
// 080235d2 bl 0x0802801c
// 080235d6 ldr r0,[0x08023764]
// 080235d8 bl 0x080281c8
// 080235dc ldr r0,[0x08023768]
// 080235de bl 0x0802456c
// 080235e2 movs r1,#0x0
// 080235e4 mov r0,r1
// 080235e6 bl 0x08026c50
// 080235ea add r0,sp,#0x4
// 080235ec bl 0x08026c4c
// 080235f0 movw r0,#0x1388
// 080235f4 bl 0x080273a4
// 080235f8 movs r3,#0x0
// 080235fa ldr r5,[sp,#0x4]
// 080235fc ldr r7,[0x08023780]
// 080235fe ldr.w r8,[0x080237a0]
// 08023602 ldr.w r9,[0x080237a4]
// 08023606 strh.w r3,[sp,#0x2]
// 0802360a ldr.w r3,[r4,#0x17]
// 0802360e ldrb.w r2,[r3,#0xce]
// 08023612 ldr r3,[r5,#0x4]
// 08023614 cmp r2,#0x3
// 08023616 bne.w 0x0802386a
// 0802361a cmp r3,#0x1
// 0802361c bne.w 0x080237a8
// 08023620 ldrb.w r3,[r5,#0xf8]
// 08023624 cmp r3,#0x1
// 08023626 bne 0x08023634
// 08023628 movs r3,#0x9
// 0802362a ldr r0,[0x08023784]
// 0802362c str r3,[r5,#0x4]
// 0802362e str r3,[r5,#0x7c]
// 08023630 bl 0x08023308
// 08023634 ldr.w r3,[r4,#0x17]
// 08023638 ldrb.w r3,[r3,#0xce]
// 0802363c cmp r3,#0x3
// 0802363e bne 0x0802367e
// 08023640 ldrb r3,[r4,#0x16]
// 08023642 adds r3,#0x1
// 08023644 uxtb r3,r3
// 08023646 cmp r3,#0x1
// 08023648 strb r3,[r4,#0x16]
// 0802364a bls 0x0802367e
// 0802364c bl 0x0802fb48
// 08023650 ldr r3,[r4,#0x4]
// 08023652 blx r3
// 08023654 movw r10,#0x1388
// 08023658 bl 0x0802fb64
// 0802365c add.w r10,r10,#0xffffffff
// 08023660 uxth.w r10,r10
// 08023664 cmp.w r10,#0x0
// 08023668 beq 0x0802367e
// 0802366a ldr.w r3,[r4,#0x17]
// 0802366e ldrb.w r3,[r3,#0xce]
// 08023672 cmp r3,#0x3
// 08023674 bne.w 0x080238a0
// 08023678 movs r0,#0xc8
// 0802367a bl 0x080273a4
// 0802367e mov.w r0,#0x1f4
// 08023682 bl 0x080273a4
// 08023686 b 0x0802360a
// 08023688 movs r3,#0x2
// 0802368a str r7,[r5,#0x4]
// 0802368c ldr r0,[0x08023788]
// 0802368e strh.w r3,[sp,#0x2]
// 08023692 b 0x08023588
// 08023694 movs r3,#0x3
// 08023696 str r7,[r5,#0x4]
// 08023698 ldr r0,[0x0802378c]
// 0802369a strh.w r3,[sp,#0x2]
// 0802369e b 0x08023588
// 080236a0 ldr.w r3,[r4,#0x17]
// 080236a4 ldrb.w r3,[r3,#0xce]
// 080236a8 cmp r3,#0x3
// 080236aa bne 0x080236c2
// 080236ac mov.w r0,#0x3e8
// 080236b0 bl 0x080273a4
// 080236b4 movs r3,#0x1
// 080236b6 str r3,[r5,#0x4]
// 080236b8 movs r3,#0x2
// 080236ba ldr r0,[0x08023790]
// 080236bc strh.w r3,[sp,#0x2]
// 080236c0 b 0x08023588
// 080236c2 movs r0,#0x1
// 080236c4 bl 0x080273a4
// 080236c8 subs r6,#0x1
// 080236ca uxth r6,r6
// 080236cc cmp r6,#0x0
// 080236ce bne 0x080236a0
// 080236d0 movs r3,#0x4
// 080236d2 ldr r0,[0x08023794]
// 080236d4 str r3,[r5,#0x4]
// 080236d6 strh.w r3,[sp,#0x2]
// 080236da b 0x08023588
// 080236dc movw r6,#0x9c4
// 080236e0 b 0x080236c8
// 080236e2 movs r3,#0x3
// 080236e4 str r7,[r5,#0x4]
// 080236e6 ldr r0,[0x08023798]
// 080236e8 strh.w r3,[sp,#0x2]
// 080236ec b 0x08023588
// 080236ee cmp r3,#0x4
// 080236f0 bne.w 0x080235a6
// 080236f4 ldrb.w r6,[r5,#0xf8]
// 080236f8 cmp r6,#0x0
// 080236fa bne.w 0x080235a6
// 080236fe movs r1,#0x2
// 08023700 ldr r0,[0x0802379c]
// 08023702 bl 0x0803453e
// 08023706 movs r0,#0x64
// 08023708 bl 0x0802fec8
// 0802370c movs r3,#0x1
// 0802370e strb r6,[r4,#0x15]
// 08023710 strb r3,[r4,#0x14]
// 08023712 ldr r0,[0x08023774]
// 08023714 str r3,[r5,#0x4]
// 08023716 strh.w r3,[sp,#0x2]
// 0802371a b 0x080235a2
// 080237a8 cmp r3,#0x9
// 080237aa beq 0x080237f2
// 080237ac movs r3,#0x1
// 080237ae str r3,[r5,#0x4]
// 080237b0 ldrb.w r3,[r5,#0xf8]
// 080237b4 ldr r0,[0x080238e0]
// 080237b6 cmp r3,#0x1
// 080237b8 itt eq
// 080237ba mov.eq r3,#0x9
// 080237bc str.eq r3,[r5,#0x4]
// 080237be ldr r3,[r5,#0x4]
// 080237c0 str r3,[r5,#0x7c]
// 080237c2 bl 0x080273a8
// 080237c6 movs r1,#0x1
// 080237c8 ldr r0,[0x080238e4]
// 080237ca bl 0x0803454c
// 080237ce movs r3,#0x3
// 080237d0 movs r2,#0x0
// 080237d2 cmp r0,#0x1
// 080237d4 ite eq
// 080237d6 ldr.eq r0,[0x080238e8]
// 080237d8 ldr.ne r0,[0x080238ec]
// 080237da strb r3,[r4,#0x14]
// 080237dc strb r2,[r4,#0x15]
// 080237de strh.w r3,[sp,#0x2]
// 080237e2 bl 0x080273a8
// 080237e6 movs r2,#0x1
// 080237e8 ldr r3,[r6,#0x8]
// 080237ea movs r0,#0x3
// 080237ec add.w r1,sp,#0x2
// 080237f0 b 0x0802385e
// 080237f2 movs r1,#0x40
// 080237f4 mov r0,r8
// 080237f6 bl 0x0803454c
// 080237fa cmp r0,#0x0
// 080237fc bne.w 0x08023634
// 08023800 bl 0x0802fb48
// 08023804 ldr r3,[r4,#0x4]
// 08023806 blx r3
// 08023808 movw r10,#0x1388
// 0802380c bl 0x0802fb64
// 08023810 add.w r10,r10,#0xffffffff
// 08023814 uxth.w r10,r10
// 08023818 cmp.w r10,#0x0
// 0802381c beq 0x08023830
// 0802381e ldr.w r3,[r4,#0x17]
// 08023822 ldrb.w r3,[r3,#0xce]
// 08023826 cmp r3,#0x3
// 08023828 bne 0x08023862
// 0802382a movs r0,#0xc8
// 0802382c bl 0x080273a4
// 08023830 mov.w r10,#0x1
// 08023834 mov.w r11,#0x0
// 08023838 mov r0,r9
// 0802383a strb.w r11,[r5,#0xf8]
// 0802383e str.w r10,[r5,#0x4]
// 08023842 str.w r10,[r5,#0x7c]
// 08023846 bl 0x080273a8
// 0802384a movs r0,#0x3
// 0802384c mov r2,r10
// 0802384e ldr r3,[r6,#0x8]
// 08023850 strb r0,[r4,#0x14]
// 08023852 strb.w r11,[r4,#0x15]
// 08023856 strh.w r0,[sp,#0x2]
// 0802385a add.w r1,sp,#0x2
// 0802385e blx r3
// 08023860 b 0x08023634
// 08023862 movs r0,#0x1
// 08023864 bl 0x080273a4
// 08023868 b 0x08023810
// 0802386a cmp r3,#0x4
// 0802386c beq.w 0x08023634
// 08023870 mov.w r10,#0x4
// 08023874 mov r0,r7
// 08023876 mov.w r11,#0x1
// 0802387a str.w r10,[r5,#0x4]
// 0802387e str.w r10,[r5,#0x7c]
// 08023882 bl 0x080273a8
// 08023886 movs r3,#0x0
// 08023888 str.w r11,[r5,#0xf4]
// 0802388c strb r3,[r4,#0x15]
// 0802388e strb.w r10,[r4,#0x14]
// 08023892 bl 0x0802652c
// 08023896 mov r2,r11
// 08023898 ldr r3,[r6,#0x8]
// 0802389a strh.w r10,[sp,#0x2]
// 0802389e b 0x080237ea
// 080238a0 movs r0,#0x1
// 080238a2 bl 0x080273a4
// 080238a6 b 0x0802365c
// 080238a8 ldr r0,[0x080238f0]
// 080238aa bl 0x080273a8
// 080238ae bl 0x080221e0
// 080238b2 mov r4,r0
// 080238b4 ldr r0,[0x080238f4]
// 080238b6 bl 0x080273d8
// 080238ba ldr r0,[0x080238f8]
// 080238bc bl 0x080275d8
// 080238c0 mov r0,r4
// 080238c2 bl 0x080221e8
// 080238c6 ldr r0,[0x080238f4]
// 080238c8 bl 0x080273f0
// 080238cc ldr r0,[0x080238f8]
// 080238ce bl 0x080275f0
// 080238d2 bl 0x08023d30
// 080238d6 mov r0,r6
// 080238d8 add sp,#0xc
// 080238da pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
