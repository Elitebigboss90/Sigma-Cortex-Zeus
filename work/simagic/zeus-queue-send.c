// FUNCTION 08026fe0

/* WARNING: Type propagation algorithm not settling */

undefined4
FUN_08026fe0(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 local_80;
  int local_78 [4];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [68];
  
  if (param_1 != 0) {
    FUN_08035d8c(local_78 + 1,0,0x54);
    local_80 = CONCAT31(local_80._1_3_,param_2);
    local_78[1] = 0;
    local_78[2] = 0x58;
    local_78[3] = param_5;
    uStack_64 = local_80;
    local_78[0] = param_1;
    local_68 = param_3;
    FUN_0802238c(auStack_60,param_4,param_5);
    FUN_08027278(*DAT_08027044,local_78,0x58);
  }
  return 0;
}


// 08026fe0 push {r4,r5,r6,r7,r8,r9,lr}
// 08026fe4 sub sp,#0x7c
// 08026fe6 mov r5,r1
// 08026fe8 mov r7,r2
// 08026fea mov r6,r3
// 08026fec mov r4,r0
// 08026fee ldr.w r8,[sp,#0x98]
// 08026ff2 cbz r0,0x0802703a
// 08026ff4 mov.w r9,#0x0
// 08026ff8 movs r2,#0x54
// 08026ffa mov r1,r9
// 08026ffc add r0,sp,#0x24
// 08026ffe bl 0x08035d8c
// 08027002 strd r4,r9,[sp,#0x4]
// 08027006 mov.w r9,#0x58
// 0802700a strd r9,r8,[sp,#0xc]
// 0802700e strb.w r5,[sp,#0x18]
// 08027012 str r7,[sp,#0x14]
// 08027014 add r4,sp,#0x20
// 08027016 add r5,sp,#0x4
// 08027018 ldmia r5!,{r0,r1,r2,r3}
// 0802701a stmia r4!,{r0,r1,r2,r3}
// 0802701c ldm.w r5,{r0,r1}
// 08027020 mov r2,r8
// 08027022 stm r4,{r0,r1}
// 08027026 mov r1,r6
// 08027028 add r0,sp,#0x38
// 0802702a bl 0x0802238c
// 0802702e ldr r3,[0x08027044]
// 08027030 mov r2,r9
// 08027032 ldr r0,[r3,#0x0]
// 08027034 add r1,sp,#0x20
// 08027036 bl 0x08027278
// 0802703a movs r0,#0x0
// 0802703c add sp,#0x7c
// 0802703e pop.w {r4,r5,r6,r7,r8,r9,pc}
// FUNCTION 08029a58

undefined4 FUN_08029a58(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == 0) || (param_4 < 1)) {
    uVar1 = 0xffffffff;
  }
  else {
    (**(code **)(DAT_08029a74 + 0x10))(param_3,param_4);
    uVar1 = 0;
  }
  return uVar1;
}


// 08029a58 mov r0,r2
// 08029a5a push {r4,lr}
// 08029a5c cbz r2,0x08029a6e
// 08029a5e cmp r3,#0x0
// 08029a60 ble 0x08029a6e
// 08029a62 ldr r1,[0x08029a74]
// 08029a64 ldr r4,[r1,#0x10]
// 08029a66 mov r1,r3
// 08029a68 blx r4
// 08029a6a movs r0,#0x0
// 08029a6c pop {r4,pc}
// 08029a6e mov.w r0,#0xffffffff
// 08029a72 b 0x08029a6c
