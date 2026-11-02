// FUNCTION 080264a4

undefined4 FUN_080264a4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_08026e04(0);
  iVar2 = *(int *)(DAT_080264e0 + 4);
  if (iVar2 == 4) {
    FUN_08025f54();
  }
  else {
    if (iVar2 == 9) {
      uVar1 = 1;
    }
    else {
      if (iVar2 != 1) {
        thunk_FUN_0802fec8(1000);
        goto LAB_080264c2;
      }
      uVar1 = 0;
    }
    FUN_08025514(uVar1);
  }
LAB_080264c2:
  FUN_08026e38(0);
  return 0;
}


// 080264a4 push {r3,lr}
// 080264a6 movs r0,#0x0
// 080264a8 bl 0x08026e04
// 080264ac ldr r3,[0x080264e0]
// 080264ae ldr r3,[r3,#0x4]
// 080264b0 cmp r3,#0x4
// 080264b2 beq 0x080264d0
// 080264b4 cmp r3,#0x9
// 080264b6 beq 0x080264cc
// 080264b8 cmp r3,#0x1
// 080264ba bne 0x080264d6
// 080264bc movs r0,#0x0
// 080264be bl 0x08025514
// 080264c2 movs r0,#0x0
// 080264c4 bl 0x08026e38
// 080264c8 movs r0,#0x0
// 080264ca pop {r3,pc}
// 080264cc movs r0,#0x1
// 080264ce b 0x080264be
// 080264d0 bl 0x08025f54
// 080264d4 b 0x080264c2
// 080264d6 mov.w r0,#0x3e8
// 080264da bl 0x080273a4
// 080264de b 0x080264c2
