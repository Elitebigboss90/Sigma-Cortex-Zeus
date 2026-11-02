// FUNCTION 0803101e

void FUN_0803101e(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_08035d8c(param_1 + 2,0,0x20);
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_08030ee4(param_1);
  return;
}


// 0803101e push {r4,r5,r6,lr}
// 08031020 mov r4,r0
// 08031022 mov r6,r1
// 08031024 mov r5,r2
// 08031026 movs r1,#0x0
// 08031028 movs r2,#0x20
// 0803102a adds r0,#0x8
// 0803102c bl 0x08035d8c
// 08031030 mov r0,r4
// 08031032 strd r6,r5,[r4,#0x0]
// 08031036 pop.w {r4,r5,r6,lr}
// 0803103a b.w 0x08030ee4
// FUNCTION 08031064

bool FUN_08031064(int param_1)

{
  FUN_08030fce();
  FUN_08030ee4();
  return *(short *)(param_1 + 8) != 0;
}


// 08031064 push {r4,lr}
// 08031066 mov r4,r0
// 08031068 bl 0x08030fce
// 0803106c bl 0x08030ee4
// 08031070 ldrh r0,[r4,#0x8]
// 08031072 subs r0,#0x0
// 08031074 it ne
// 08031076 mov.ne r0,#0x1
// 08031078 pop {r4,pc}
// FUNCTION 080270e6

void FUN_080270e6(void)

{
  int iVar1;
  
  iVar1 = FUN_08026bb4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x20) = 0xff;
    *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(iVar1 + 0x4c);
    *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(iVar1 + 0x44);
    *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(iVar1 + 0x48);
    FUN_080296fc(0,iVar1 + 0x88);
    FUN_08027048(iVar1 + 0x28,iVar1 + 0x30);
    *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(iVar1 + 0x28);
    *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(iVar1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(iVar1 + 0x30);
    *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar1 + 0x34);
  }
  return;
}


// 080270e6 push {r4,lr}
// 080270e8 bl 0x08026bb4
// 080270ec mov r4,r0
// 080270ee cbz r0,0x08027132
// 080270f0 movs r3,#0xff
// 080270f2 str r3,[r0,#0x20]
// 080270f4 movs r0,#0x0
// 080270f6 ldr r3,[r4,#0x4]
// 080270f8 add.w r1,r4,#0x88
// 080270fc str r3,[r4,#0x7c]
// 080270fe ldr r3,[r4,#0x4c]
// 08027100 str.w r0,[r4,#0x80]
// 08027104 str r3,[r4,#0x78]
// 08027106 ldr r3,[r4,#0x44]
// 08027108 str.w r3,[r4,#0x84]
// 0802710c ldr r3,[r4,#0x48]
// 0802710e str.w r3,[r4,#0x90]
// 08027112 bl 0x080296fc
// 08027116 add.w r1,r4,#0x30
// 0802711a add.w r0,r4,#0x28
// 0802711e bl 0x08027048
// 08027122 ldrd r2,r3,[r4,#0x28]
// 08027126 strd r2,r3,[r4,#0x70]
// 0802712a ldrd r2,r3,[r4,#0x30]
// 0802712e strd r2,r3,[r4,#0x68]
// 08027132 pop {r4,pc}
