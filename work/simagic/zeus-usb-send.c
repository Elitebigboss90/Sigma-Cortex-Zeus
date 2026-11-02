// FUNCTION 0802aa58

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0802aa58(undefined4 param_1,undefined4 param_2)

{
  if (*(char *)(_DAT_0802aa70 + 0xce) == '\x03') {
    FUN_08032556(_DAT_0802aa70,0x81,param_1,param_2,_DAT_0802aa70);
    return 0;
  }
  return param_1;
}


// 0802a928 push {r3,lr}
// 0802a92a mov r3,r2
// 0802a92c mov r2,r1
// 0802a92e movs r1,#0x81
// 0802a930 bl 0x08032556
// 0802a934 movs r0,#0x0
// 0802a936 pop {r3,pc}
// 0802aa58 ldr r3,[0x0802aa70]
// 0802aa5a mov r2,r1
// 0802aa5c ldrb.w r1,[r3,#0xce]
// 0802aa60 cmp r1,#0x3
// 0802aa62 bne 0x0802aa6c
// 0802aa64 mov r1,r0
// 0802aa66 mov r0,r3
// 0802aa68 b.w 0x0802a928
// 0802aa6c bx lr
