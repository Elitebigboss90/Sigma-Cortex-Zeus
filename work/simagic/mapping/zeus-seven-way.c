// FUNCTION 080292b0

void FUN_080292b0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  
  iVar2 = DAT_08029414;
  iVar12 = param_1 * 9 + DAT_08029414;
  cVar3 = FUN_0802b814(*(undefined1 *)(iVar12 + 1));
  cVar4 = FUN_0802b814(*(undefined1 *)(iVar12 + 2));
  cVar5 = FUN_0802b814(*(undefined1 *)(iVar12 + 3));
  bVar6 = FUN_0802b814(*(undefined1 *)(iVar12 + 4));
  cVar7 = FUN_0802b814(*(undefined1 *)(iVar12 + 5));
  cVar8 = FUN_0802b814(*(undefined1 *)(iVar12 + 6));
  cVar9 = FUN_0802b814(*(undefined1 *)(iVar12 + 7));
  iVar12 = DAT_08029408;
  if (cVar7 == '\0') {
    iVar11 = param_1 * 0x78 + DAT_08029408;
    *(undefined4 *)(iVar11 + 0x10) = 0;
    *(undefined4 *)(iVar11 + 0x20) = 0;
    *(undefined4 *)(iVar11 + 0x30) = 0;
    *(undefined4 *)(iVar11 + 0x40) = 0;
    *(undefined4 *)(iVar11 + 0x50) = 0;
    switch(bVar6 | cVar4 << 2 | cVar3 << 3 | cVar5 << 1) {
    case 7:
      *(undefined4 *)(param_1 * 0x78 + iVar12 + 0x10) = 1;
      break;
    case 0xb:
      *(undefined4 *)(param_1 * 0x78 + iVar12 + 0x20) = 1;
      break;
    case 0xd:
      *(undefined4 *)(param_1 * 0x78 + iVar12 + 0x30) = 1;
      break;
    case 0xe:
      *(undefined4 *)(param_1 * 0x78 + iVar12 + 0x40) = 1;
      break;
    case 0xf:
      uVar10 = 1;
      iVar11 = param_1 * 0x78 + iVar12;
      goto LAB_0802931a;
    }
  }
  else {
    uVar10 = 0;
    iVar11 = param_1 * 0x78 + DAT_08029408;
    *(undefined4 *)(iVar11 + 0x10) = 0;
    *(undefined4 *)(iVar11 + 0x20) = 0;
    *(undefined4 *)(iVar11 + 0x30) = 0;
    *(undefined4 *)(iVar11 + 0x40) = 0;
LAB_0802931a:
    *(undefined4 *)(iVar11 + 0x50) = uVar10;
  }
  iVar1 = DAT_08029410;
  iVar11 = DAT_0802940c;
  if (*(char *)(DAT_0802940c + param_1) == cVar8) {
    if ((*(char *)(DAT_08029410 + param_1) == cVar9) || (cVar8 == cVar9)) goto LAB_0802932c;
    *(undefined1 *)(iVar2 + param_1 * 9 + 8) = 10;
    iVar12 = param_1 * 0x78 + iVar12;
    *(undefined4 *)(iVar12 + 0x70) = 0;
    uVar10 = 1;
  }
  else {
    if ((cVar8 == cVar9) || (*(char *)(DAT_08029410 + param_1) != cVar9)) goto LAB_0802932c;
    *(undefined1 *)(iVar2 + param_1 * 9 + 8) = 10;
    iVar12 = param_1 * 0x78 + iVar12;
    *(undefined4 *)(iVar12 + 0x70) = 1;
    uVar10 = 0;
  }
  *(undefined4 *)(iVar12 + 0x60) = uVar10;
LAB_0802932c:
  *(char *)(iVar11 + param_1) = cVar8;
  *(char *)(iVar1 + param_1) = cVar9;
  return;
}


// 080292b0 push {r0,r1,r2,r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 080292b4 ldr.w r9,[0x08029414]
// 080292b8 add.w r7,r0,r0, lsl #0x3
// 080292bc add r7,r9
// 080292be mov r4,r0
// 080292c0 lsls r6,r0,#0x3
// 080292c2 ldrb r0,[r7,#0x1]
// 080292c4 bl 0x0802b814
// 080292c8 mov r5,r0
// 080292ca ldrb r0,[r7,#0x2]
// 080292cc bl 0x0802b814
// 080292d0 mov r10,r0
// 080292d2 ldrb r0,[r7,#0x3]
// 080292d4 bl 0x0802b814
// 080292d8 mov r11,r0
// 080292da ldrb r0,[r7,#0x4]
// 080292dc bl 0x0802b814
// 080292e0 str r0,[sp,#0x4]
// 080292e2 ldrb r0,[r7,#0x5]
// 080292e4 bl 0x0802b814
// 080292e8 str r0,[sp,#0x0]
// 080292ea ldrb r0,[r7,#0x6]
// 080292ec bl 0x0802b814
// 080292f0 uxtb.w r8,r0
// 080292f4 ldrb r0,[r7,#0x7]
// 080292f6 bl 0x0802b814
// 080292fa ldr r3,[sp,#0x0]
// 080292fc uxtb r7,r0
// 080292fe ands r0,r3,#0xff
// 08029302 ldr r1,[0x08029408]
// 08029304 mov.w r3,#0x78
// 08029308 ldr r2,[sp,#0x4]
// 0802930a beq 0x08029338
// 0802930c movs r2,#0x0
// 0802930e mla r3,r3,r4,r1
// 08029312 str r2,[r3,#0x10]
// 08029314 str r2,[r3,#0x20]
// 08029316 str r2,[r3,#0x30]
// 08029318 str r2,[r3,#0x40]
// 0802931a str r2,[r3,#0x50]
// 0802931c ldr r0,[0x0802940c]
// 0802931e ldr r2,[0x08029410]
// 08029320 ldrb r3,[r0,r4]
// 08029322 cmp r3,r8
// 08029324 bne 0x080293c8
// 08029326 ldrb r3,[r2,r4]
// 08029328 cmp r3,r7
// 0802932a bne 0x080293ec
// 0802932c strb.w r8,[r0,r4]
// 08029330 strb r7,[r2,r4]
// 08029332 add sp,#0xc
// 08029334 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 08029338 mla r12,r3,r4,r1
// 0802933c lsls r5,r5,#0x3
// 0802933e str.w r0,[r12,#0x10]
// 08029342 str.w r0,[r12,#0x20]
// 08029346 str.w r0,[r12,#0x30]
// 0802934a str.w r0,[r12,#0x40]
// 0802934e str.w r0,[r12,#0x50]
// 08029352 lsl.w r0,r10,#0x2
// 08029356 and r5,r5,#0x7f8
// 0802935a and r0,r0,#0x3fc
// 0802935e orrs r0,r5
// 08029360 orrs r2,r0
// 08029362 orr.w r2,r2,r11, lsl #0x1
// 08029366 sxtb r2,r2
// 08029368 subs r2,#0x7
// 0802936a cmp r2,#0x8
// 0802936c bhi 0x0802931c
// 0802936e adr r0,[0x8029374]
// 08029370 ldr.w pc,[r0,r2,lsl #0x2]
// 08029398 movs r2,#0x1
// 0802939a mla r3,r3,r4,r1
// 0802939e b 0x0802931a
// 080293a0 movs r2,#0x1
// 080293a2 mla r3,r3,r4,r1
// 080293a6 str r2,[r3,#0x10]
// 080293a8 b 0x0802931c
// 080293aa movs r2,#0x1
// 080293ac mla r3,r3,r4,r1
// 080293b0 str r2,[r3,#0x20]
// 080293b2 b 0x0802931c
// 080293b4 movs r2,#0x1
// 080293b6 mla r3,r3,r4,r1
// 080293ba str r2,[r3,#0x30]
// 080293bc b 0x0802931c
// 080293be movs r2,#0x1
// 080293c0 mla r3,r3,r4,r1
// 080293c4 str r2,[r3,#0x40]
// 080293c6 b 0x0802931c
// 080293c8 cmp r8,r7
// 080293ca beq 0x0802932c
// 080293cc ldrb r3,[r2,r4]
// 080293ce cmp r3,r7
// 080293d0 bne 0x0802932c
// 080293d2 movs r3,#0xa
// 080293d4 add r6,r4
// 080293d6 add r9,r6
// 080293d8 strb.w r3,[r9,#0x8]
// 080293dc movs r3,#0x78
// 080293de mla r1,r3,r4,r1
// 080293e2 movs r3,#0x1
// 080293e4 str r3,[r1,#0x70]
// 080293e6 movs r3,#0x0
// 080293e8 str r3,[r1,#0x60]
// 080293ea b 0x0802932c
// 080293ec cmp r8,r7
// 080293ee beq 0x0802932c
// 080293f0 movs r3,#0xa
// 080293f2 add r6,r4
// 080293f4 add r9,r6
// 080293f6 strb.w r3,[r9,#0x8]
// 080293fa movs r3,#0x78
// 080293fc mla r1,r3,r4,r1
// 08029400 movs r3,#0x0
// 08029402 str r3,[r1,#0x70]
// 08029404 movs r3,#0x1
// 08029406 b 0x080293e8
// FUNCTION 080294b8

undefined4 FUN_080294b8(void)

{
  FUN_080292b0(0);
  FUN_080292b0(1);
  return 0;
}


// 080294b8 push {r3,lr}
// 080294ba movs r0,#0x0
// 080294bc bl 0x080292b0
// 080294c0 movs r0,#0x1
// 080294c2 bl 0x080292b0
// 080294c6 movs r0,#0x0
// 080294c8 pop {r3,pc}
// FUNCTION 080295ac

undefined4 FUN_080295ac(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_080295d8;
  iVar4 = 0;
  iVar5 = DAT_080295d4;
  do {
    iVar3 = FUN_0802b814(*(undefined1 *)(iVar5 + 1));
    iVar1 = iVar4 * 4;
    iVar4 = iVar4 + 10;
    *(int *)(iVar2 + iVar1 + 0x20) = 1 - iVar3;
    iVar5 = iVar5 + 3;
  } while (iVar4 != 0xa0);
  return 0;
}


// 080295ac push {r4,r5,r6,lr}
// 080295ae movs r4,#0x0
// 080295b0 ldr r5,[0x080295d4]
// 080295b2 ldr r6,[0x080295d8]
// 080295b4 ldrb r0,[r5,#0x1]
// 080295b6 bl 0x0802b814
// 080295ba add.w r3,r6,r4, lsl #0x2
// 080295be adds r4,#0xa
// 080295c0 rsb.w r0,r0,#0x1
// 080295c4 cmp r4,#0xa0
// 080295c6 str r0,[r3,#0x20]
// 080295c8 add.w r5,r5,#0x3
// 080295cc bne 0x080295b4
// 080295ce movs r0,#0x0
// 080295d0 pop {r4,r5,r6,pc}
// FUNCTION 08029908

void FUN_08029908(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_08029984;
  iVar5 = DAT_08029984 + param_1 * 4;
  cVar2 = FUN_0802b814(*(undefined1 *)(iVar5 + 1));
  cVar3 = FUN_0802b814(*(undefined1 *)(iVar5 + 2));
  iVar1 = DAT_0802998c;
  iVar5 = DAT_08029988;
  if ((((*(char *)(DAT_08029988 + param_1) != cVar2) || (*(char *)(DAT_0802998c + param_1) != cVar3)
       ) && (*(char *)(DAT_08029988 + param_1) == '\x01')) &&
     (*(char *)(DAT_0802998c + param_1) == '\x01')) {
    if (cVar2 == '\x01') {
      if (cVar3 != '\x01') {
        *(undefined1 *)(iVar4 + param_1 * 4 + 3) = 10;
        iVar4 = param_1 * 0x28 + DAT_08029990;
        *(undefined4 *)(iVar4 + 0x20) = 1;
        *(undefined4 *)(iVar4 + 0x10) = 0;
      }
    }
    else if (cVar3 == '\x01') {
      *(undefined1 *)(iVar4 + param_1 * 4 + 3) = 10;
      iVar4 = param_1 * 0x28 + DAT_08029990;
      *(undefined4 *)(iVar4 + 0x10) = 1;
      *(undefined4 *)(iVar4 + 0x20) = 0;
    }
  }
  *(char *)(iVar5 + param_1) = cVar2;
  *(char *)(iVar1 + param_1) = cVar3;
  return;
}


// 08029908 push {r4,r5,r6,r7,r8,lr}
// 0802990c ldr r6,[0x08029984]
// 0802990e mov r4,r0
// 08029910 add.w r8,r6,r0, lsl #0x2
// 08029914 lsls r7,r0,#0x2
// 08029916 ldrb.w r0,[r8,#0x1]
// 0802991a bl 0x0802b814
// 0802991e uxtb r5,r0
// 08029920 ldrb.w r0,[r8,#0x2]
// 08029924 bl 0x0802b814
// 08029928 ldr r1,[0x08029988]
// 0802992a ldr r2,[0x0802998c]
// 0802992c ldrb r3,[r1,r4]
// 0802992e uxtb r0,r0
// 08029930 cmp r3,r5
// 08029932 bne 0x0802993c
// 08029934 ldrb.w r12,[r2,r4]
// 08029938 cmp r12,r0
// 0802993a beq 0x08029962
// 0802993c cmp r3,#0x1
// 0802993e bne 0x08029962
// 08029940 ldrb r3,[r2,r4]
// 08029942 cmp r3,#0x1
// 08029944 bne 0x08029962
// 08029946 cmp r5,#0x1
// 08029948 beq 0x0802996a
// 0802994a cmp r0,#0x1
// 0802994c bne 0x08029962
// 0802994e movs r3,#0xa
// 08029950 add r6,r7
// 08029952 strb r3,[r6,#0x3]
// 08029954 movs r6,#0x28
// 08029956 ldr r3,[0x08029990]
// 08029958 mla r3,r6,r4,r3
// 0802995c movs r6,#0x0
// 0802995e str r0,[r3,#0x10]
// 08029960 str r6,[r3,#0x20]
// 08029962 strb r5,[r1,r4]
// 08029964 strb r0,[r2,r4]
// 08029966 pop.w {r4,r5,r6,r7,r8,pc}
// 0802996a cmp r0,#0x1
// 0802996c beq 0x08029962
// 0802996e movs r3,#0xa
// 08029970 add r6,r7
// 08029972 strb r3,[r6,#0x3]
// 08029974 movs r6,#0x28
// 08029976 ldr r3,[0x08029990]
// 08029978 mla r3,r6,r4,r3
// 0802997c movs r6,#0x0
// 0802997e str r5,[r3,#0x20]
// 08029980 str r6,[r3,#0x10]
// 08029982 b 0x08029962
