// FUNCTION 080273fc

void FUN_080273fc(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = DAT_0802748c;
  if (*(int *)(DAT_0802748c + 4) == 3) {
    *param_1 = 1;
    param_1[1] = (char)*(undefined4 *)(iVar3 + 0xd0);
    param_1[2] = (char)*(undefined4 *)(iVar3 + 0xcc);
    param_1[3] = (char)*(undefined4 *)(iVar3 + 0xf4);
    param_2 = 8;
    uVar5 = 0x700;
    iVar3 = *(int *)(iVar3 + 4);
  }
  else {
    uVar2 = *(undefined1 *)(DAT_0802748c + 0x20);
    if ((*(char *)(DAT_0802748c + 0xf0) == '\0') ||
       (cVar1 = *DAT_08027490, *DAT_08027490 = cVar1 == '\0', cVar1 != '\0')) {
      iVar4 = FUN_08030c7c(iVar3 + 0x60,uVar2,param_1);
    }
    else {
      *(undefined4 *)(iVar3 + 0xbc) = *(undefined4 *)(iVar3 + 0xf4);
      iVar4 = FUN_08030dac(iVar3 + 0xa0,uVar2,param_1);
    }
    if (iVar4 == -1) {
      return;
    }
    iVar3 = *(int *)(iVar3 + 4);
    if (iVar3 == 4) {
      uVar5 = *DAT_08027494;
    }
    else {
      uVar5 = 0;
    }
  }
  FUN_08026fe0(iVar3,0,uVar5,param_1,param_2);
  return;
}


// 080273fc push {r4,r5,lr}
// 080273fe ldr r4,[0x0802748c]
// 08027400 mov r3,r0
// 08027402 ldr r2,[r4,#0x4]
// 08027404 mov r5,r1
// 08027406 cmp r2,#0x3
// 08027408 sub sp,#0x14
// 0802740a bne 0x08027436
// 0802740c movs r2,#0x1
// 0802740e strb r2,[r0,#0x0]
// 08027410 ldr.w r2,[r4,#0xd0]
// 08027414 movs r1,#0x0
// 08027416 strb r2,[r0,#0x1]
// 08027418 ldr.w r2,[r4,#0xcc]
// 0802741c strb r2,[r0,#0x2]
// 0802741e ldr.w r2,[r4,#0xf4]
// 08027422 strb r2,[r0,#0x3]
// 08027424 movs r2,#0x8
// 08027426 str r2,[sp,#0x0]
// 08027428 mov.w r2,#0x700
// 0802742c ldr r0,[r4,#0x4]
// 0802742e bl 0x08026fe0
// 08027432 add sp,#0x14
// 08027434 pop {r4,r5,pc}
// 08027436 ldrb.w r2,[r4,#0xf0]
// 0802743a ldrb.w r1,[r4,#0x20]
// 0802743e cbz r2,0x0802747c
// 08027440 ldr r2,[0x08027490]
// 08027442 ldrb r0,[r2,#0x0]
// 08027444 cmp r0,#0x0
// 08027446 ite eq
// 08027448 mov.eq r0,#0x1
// 0802744a mov.ne r0,#0x0
// 0802744c strb r0,[r2,#0x0]
// 0802744e bne 0x0802747c
// 08027450 ldr.w r2,[r4,#0xf4]
// 08027454 add.w r0,r4,#0xa0
// 08027458 str.w r2,[r4,#0xbc]
// 0802745c mov r2,r3
// 0802745e str r3,[sp,#0xc]
// 08027460 bl 0x08030dac
// 08027464 adds r0,#0x1
// 08027466 ldr r3,[sp,#0xc]
// 08027468 beq 0x08027432
// 0802746a ldr r0,[r4,#0x4]
// 0802746c movs r1,#0x0
// 0802746e cmp r0,#0x4
// 08027470 itet eq
// 08027472 ldr.eq r2,[0x08027494]
// 08027474 mov.ne r2,#0x0
// 08027476 ldr.eq r2,[r2,#0x0]
// 08027478 str r5,[sp,#0x0]
// 0802747a b 0x0802742e
// 0802747c mov r2,r3
// 0802747e add.w r0,r4,#0x60
// 08027482 str r3,[sp,#0xc]
// 08027484 bl 0x08030c7c
// 08027488 b 0x08027464
// FUNCTION 08027614

void FUN_08027614(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 - 3U < 2) {
    uVar2 = *DAT_0802766c;
  }
  else {
    uVar2 = 0;
  }
  if (param_4 < (uint)(param_2 << 6)) {
    FUN_080273a8(DAT_08027670,param_2 * 0x40,param_4);
    return;
  }
  iVar1 = param_3 + param_2 * 0x40;
  for (; param_3 != iVar1; param_3 = param_3 + 0x40) {
    FUN_08026fe0(param_1,0,uVar2,param_3,0x40,param_2);
    thunk_FUN_0802fec8(10);
  }
  return;
}


// 08027614 push {r0,r1,r4,r5,r6,r7,r8,lr}
// 08027618 mov r6,r0
// 0802761a mov r0,r1
// 0802761c mov r4,r2
// 0802761e subs r2,r6,#0x3
// 08027620 cmp r2,#0x1
// 08027622 itet ls
// 08027624 ldr.ls r2,[0x0802766c]
// 08027626 mov.hi r7,#0x0
// 08027628 ldr.ls r7,[r2,#0x0]
// 0802762a cmp.w r3,r0, lsl #0x6
// 0802762e lsl.w r1,r1,#0x6
// 08027632 bcc 0x08027644
// 08027634 mov.w r8,#0x40
// 08027638 adds r5,r4,r1
// 0802763a cmp r4,r5
// 0802763c bne 0x08027652
// 0802763e add sp,#0x8
// 08027640 pop.w {r4,r5,r6,r7,r8,pc}
// 08027644 mov r2,r3
// 08027646 ldr r0,[0x08027670]
// 08027648 add sp,#0x8
// 0802764a pop.w {r4,r5,r6,r7,r8,lr}
// 0802764e b.w 0x080273a8
// 08027652 mov r3,r4
// 08027654 mov r2,r7
// 08027656 movs r1,#0x0
// 08027658 mov r0,r6
// 0802765a str.w r8,[sp,#0x0]
// 0802765e bl 0x08026fe0
// 08027662 movs r0,#0xa
// 08027664 bl 0x080273a4
// 08027668 adds r4,#0x40
// 0802766a b 0x0802763a
// FUNCTION 08027674

undefined4
FUN_08027674(undefined4 *param_1,int param_2,undefined2 param_3,int param_4,int *param_5,
            undefined2 param_6)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint local_824;
  int local_820;
  undefined1 auStack_81c [1020];
  int local_420;
  undefined1 auStack_41c [1020];
  
  bVar1 = *(byte *)(param_2 + 2);
  if (bVar1 == 0x88) {
    local_824 = 0;
    local_820 = 0;
    FUN_08035d8c(auStack_81c,0,0x3fc);
    local_420 = 0;
    FUN_08035d8c(auStack_41c,0,0x3fc);
    uVar3 = *(undefined1 *)(param_2 + 10);
    FUN_080273a8(DAT_08027790,uVar3);
    FUN_08029794(0,5,uVar3,&local_820,&local_824);
    FUN_080273a8(DAT_08027794,local_824);
    uVar3 = FUN_08028cb4(0x88,*(undefined1 *)(DAT_08027798 + 0x20),&local_820,local_824 & 0xffff,
                         &local_420,0x400);
    FUN_08027614(*param_1,uVar3,&local_420,0x400);
  }
  else if ((((bVar1 & 0xef) == 0x89) || (bVar1 == 0xa9)) && (param_4 == 0x241)) {
    local_820 = FUN_08030b58(param_2,param_3,DAT_080277a0,DAT_0802779c,0x400);
    iVar2 = DAT_08027798;
    if (local_820 == 0) {
      local_420 = local_820;
      iVar4 = FUN_0802860c(DAT_080277a4,param_6,*(undefined4 *)(DAT_08027798 + 0x20),&local_820,
                           &local_420);
      if (iVar4 != 0) {
        (**(code **)(iVar2 + 0xfc))(local_820,DAT_080277a4,param_6);
        (**(code **)(iVar2 + 0x10c))(local_820);
        (**(code **)(iVar2 + 0x108))(local_820);
        FUN_08027200(*DAT_080277a8,1);
      }
    }
    else if (local_820 < 0) {
      FUN_080273a8(DAT_080277ac);
    }
  }
  *param_5 = param_4;
  return 0;
}


// 08027674 push {r4,r5,r6,r7,r8,r9,r10,lr}
// 08027678 mov r5,r1
// 0802767a ldrb r7,[r5,#0x2]
// 0802767c mov r9,r0
// 0802767e cmp r7,#0x88
// 08027680 mov r1,r2
// 08027682 mov r6,r3
// 08027684 subw sp,sp,#0x818
// 08027688 bne 0x08027712
// 0802768a movs r4,#0x0
// 0802768c mov.w r2,#0x3fc
// 08027690 mov r1,r4
// 08027692 add r0,sp,#0x1c
// 08027694 strd r4,r4,[sp,#0x14]
// 08027698 bl 0x08035d8c
// 0802769c mov r1,r4
// 0802769e mov.w r2,#0x3fc
// 080276a2 addw r0,sp,#0x41c
// 080276a6 str.w r4,[sp,#0x418]
// 080276aa bl 0x08035d8c
// 080276ae ldrb r2,[r5,#0xa]
// 080276b0 ldr r0,[0x08027790]
// 080276b2 mov r1,r2
// 080276b4 str r2,[sp,#0xc]
// 080276b6 bl 0x080273a8
// 080276ba mov r0,r4
// 080276bc mov.w r4,#0x400
// 080276c0 add.w r8,sp,#0x14
// 080276c4 ldr r2,[sp,#0xc]
// 080276c6 add r3,sp,#0x18
// 080276c8 movs r1,#0x5
// 080276ca str.w r8,[sp,#0x0]
// 080276ce bl 0x08029794
// 080276d2 add.w r10,sp,#0x418
// 080276d6 ldr r1,[sp,#0x14]
// 080276d8 ldr r0,[0x08027794]
// 080276da bl 0x080273a8
// 080276de strd r10,r4,[sp,#0x0]
// 080276e2 ldr r1,[0x08027798]
// 080276e4 ldrh.w r3,[sp,#0x14]
// 080276e8 ldrb.w r1,[r1,#0x20]
// 080276ec add r2,sp,#0x18
// 080276ee mov r0,r7
// 080276f0 bl 0x08028cb4
// 080276f4 mov r3,r4
// 080276f6 uxtb r1,r0
// 080276f8 mov r2,r10
// 080276fa ldr.w r0,[r9,#0x0]
// 080276fe bl 0x08027614
// 08027702 movs r0,#0x0
// 08027704 ldr.w r3,[sp,#0x838]
// 08027708 str r6,[r3,#0x0]
// 0802770a addw sp,sp,#0x818
// 0802770e pop.w {r4,r5,r6,r7,r8,r9,r10,pc}
// 08027712 and r3,r7,#0xef
// 08027716 cmp r3,#0x89
// 08027718 beq 0x0802771e
// 0802771a cmp r7,#0xa9
// 0802771c bne 0x08027702
// 0802771e movw r3,#0x241
// 08027722 cmp r6,r3
// 08027724 bne 0x08027702
// 08027726 mov.w r3,#0x400
// 0802772a uxth r1,r1
// 0802772c str r3,[sp,#0x0]
// 0802772e mov r0,r5
// 08027730 ldr r3,[0x0802779c]
// 08027732 ldr r2,[0x080277a0]
// 08027734 bl 0x08030b58
// 08027738 subs r1,r0,#0x0
// 0802773a bne 0x08027786
// 0802773c add.w r3,sp,#0x418
// 08027740 ldrh.w r5,[sp,#0x83c]
// 08027744 ldr r4,[0x08027798]
// 08027746 str r3,[sp,#0x0]
// 08027748 str r1,[sp,#0x18]
// 0802774a str.w r1,[sp,#0x418]
// 0802774e ldr r2,[r4,#0x20]
// 08027750 mov r1,r5
// 08027752 ldr r0,[0x080277a4]
// 08027754 add r3,sp,#0x18
// 08027756 bl 0x0802860c
// 0802775a cmp r0,#0x0
// 0802775c beq 0x08027702
// 0802775e mov r2,r5
// 08027760 ldr r1,[0x080277a4]
// 08027762 ldr.w r3,[r4,#0xfc]
// 08027766 ldr r0,[sp,#0x18]
// 08027768 blx r3
// 0802776a ldr.w r3,[r4,#0x10c]
// 0802776e ldr r0,[sp,#0x18]
// 08027770 blx r3
// 08027772 ldr.w r3,[r4,#0x108]
// 08027776 ldr r0,[sp,#0x18]
// 08027778 blx r3
// 0802777a ldr r3,[0x080277a8]
// 0802777c movs r1,#0x1
// 0802777e ldr r0,[r3,#0x0]
// 08027780 bl 0x08027200
// 08027784 b 0x08027702
// 08027786 bge 0x08027702
// 08027788 ldr r0,[0x080277ac]
// 0802778a bl 0x080273a8
// 0802778e b 0x08027702
