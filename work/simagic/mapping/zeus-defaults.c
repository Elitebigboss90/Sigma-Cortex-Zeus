
// FUNCTION FUN_08026bbc @ 08026bbc
// XREF 08024592
// XREF 08024acc
// XREF 08024d5e
// XREF 080251b0
// XREF 0802441e
// XREF 08024f20

undefined4 FUN_08026bbc(void)

{
  return DAT_08026bc0;
}



// FUNCTION FUN_08026bc4 @ 08026bc4
// XREF 08024ce8
// XREF 08024d58
// XREF 080251b6
// XREF 0802545c
// XREF 08024f26

undefined4 FUN_08026bc4(void)

{
  return DAT_08026bc8;
}



// FUNCTION FUN_08026c54 @ 08026c54

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



// FUNCTION FUN_08026e60 @ 08026e60
// XREF 08023568
// XREF 08026c14

void FUN_08026e60(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  iVar1 = FUN_080271d0(DAT_08026ed8,0,param_3,param_4,param_1);
  *DAT_08026edc = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_08027158(DAT_08026ee0,0);
    *DAT_08026ee4 = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_08027158(DAT_08026ee8,0);
      *DAT_08026eec = iVar1;
      if (iVar1 != 0) {
        iVar1 = FUN_08027158(DAT_08026ef0,0);
        *DAT_08026ef4 = iVar1;
        if (iVar1 != 0) {
          local_10 = param_1[4];
          local_14 = param_1[5];
          local_c = param_1[7];
          iVar1 = FUN_08027228(DAT_08026ef8,&local_14);
          *DAT_08026efc = iVar1;
          if (iVar1 != 0) {
            local_10 = *param_1;
            local_14 = param_1[1];
            local_c = param_1[3];
            uVar2 = FUN_08027228(DAT_08026f00,&local_14);
            *DAT_08026f04 = uVar2;
          }
        }
      }
    }
  }
  return;
}



// FUNCTION FUN_08026f08 @ 08026f08
// XREF 08026c2c

void FUN_08026f08(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = DAT_08026f7c;
  FUN_08035d8c(DAT_08026f7c,0,0xa8,param_4,param_1,param_2);
  FUN_08029124(iVar1 + 100,iVar1 + 0x60);
  FUN_08029418(iVar1 + 0x34,iVar1 + 0x30);
  FUN_080294cc(iVar1 + 0x14,iVar1 + 0x10);
  FUN_08029560(iVar1 + 0x1c,iVar1 + 0x18);
  FUN_0802960c(iVar1 + 0x54,iVar1 + 0x50);
  FUN_08029994(iVar1 + 0x5c,iVar1 + 0x58);
  FUN_08028a58(DAT_08026f8c,DAT_08026f88,0x20,iVar1,DAT_08026f84,DAT_08026f80);
  FUN_080265fc(DAT_08026f8c);
  return;
}



// FUNCTION FUN_08026f90 @ 08026f90
// XREF 08026c0e

undefined4 FUN_08026f90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_08026fc0;
  FUN_08035d8c(DAT_08026fc0,0,0x30);
  FUN_08028fd0(iVar1 + 0xc,iVar1 + 8,DAT_08026fc4);
  puVar3 = DAT_08029a50;
  uVar2 = DAT_08026fc8;
  if (((undefined4 *)(iVar1 + 0x2c) != (undefined4 *)0x0) &&
     ((undefined4 *)(iVar1 + 0x28) != (undefined4 *)0x0)) {
    *(undefined4 *)(iVar1 + 0x2c) = DAT_08029a50;
    *(undefined4 *)(iVar1 + 0x28) = 1;
    puVar3[2] = 1;
    *puVar3 = 1;
    puVar3[1] = 1;
    *(undefined4 *)(DAT_08029a54 + 8) = uVar2;
    return 0;
  }
  return 0xffffffff;
}



// FUNCTION FUN_08029290 @ 08029290
// XREF 08024dce
// XREF 08024e3a
// XREF 08023aca
// XREF 08023b7a

undefined4 FUN_08029290(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  
  bVar1 = -1 < param_2;
  if (bVar1) {
    param_2 = param_2 * 0x13c + DAT_080292ac;
    param_1 = 0;
  }
  if (bVar1) {
    *(undefined4 *)(param_2 + 0x10) = param_3;
  }
  else {
    param_1 = 0xffffffff;
  }
  return param_1;
}



// FUNCTION FUN_08029824 @ 08029824
// XREF 08026c1a

undefined4 FUN_08029824(void)

{
  (*(code *)*DAT_08029860)();
  FUN_0802aec4(0);
  (*(code *)*DAT_08029864)();
  (*(code *)*DAT_08029868)();
  FUN_0802b7ec();
  FUN_0802b9b0();
  FUN_0802cacc();
  FUN_08029b78();
  (*(code *)*DAT_0802986c)();
  (*(code *)*DAT_08029870)();
  return 0;
}



// FUNCTION FUN_0802aec4 @ 0802aec4
// XREF 08024282
// XREF 0802982e
// XREF 08023a02

void FUN_0802aec4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined2 local_178;
  undefined4 local_174 [8];
  undefined1 auStack_154 [80];
  undefined1 auStack_104 [80];
  undefined1 auStack_b4 [164];
  
  iVar1 = DAT_0802afcc;
  local_188 = 0;
  local_184 = 0;
  local_18c = 0;
  FUN_0802ad48(0,&local_18c);
  if ((local_18c != iVar1) || (param_1 == 1)) {
    local_18c = 0x32;
    FUN_0802ae2c(4,&local_18c);
    local_18c = 100;
    FUN_0802ae2c(5,&local_18c);
    local_188 = DAT_0802afd0;
    FUN_0802ae2c(6,&local_188,4);
    FUN_0802ae2c(8,&local_188,4);
    local_184 = DAT_0802afd4;
    FUN_0802ae2c(7,&local_184,4);
    iVar2 = DAT_0802afd8;
    FUN_0802ae2c(9,&local_184,4);
    FUN_0802238c(auStack_b4,DAT_0802afdc,0xa2);
    FUN_0802ae2c(10,auStack_b4,0xa2);
    FUN_0802238c(auStack_154,iVar2,0x4e);
    FUN_0802ae2c(0xb,auStack_154,0x4e);
    FUN_0802238c(auStack_104,iVar2 + 0x4e,0x4f);
    FUN_0802ae2c(0xc,auStack_104,0x4f);
    local_180 = *(undefined4 *)(iVar2 + 0x9d);
    uStack_17c = *(undefined4 *)(iVar2 + 0xa1);
    local_178 = *(undefined2 *)(iVar2 + 0xa5);
    FUN_0802ae2c(0xd,&local_180,10);
    puVar6 = local_174;
    puVar5 = (undefined4 *)(iVar2 + 0xa7);
    do {
      uVar3 = *puVar5;
      uVar4 = puVar5[1];
      puVar5 = puVar5 + 2;
      *puVar6 = uVar3;
      puVar6[1] = uVar4;
      puVar6 = puVar6 + 2;
    } while (puVar5 != (undefined4 *)(iVar2 + 199));
    FUN_0802ae2c(0xe,local_174,0x20);
    local_18c = iVar1;
    FUN_0802ae2c(0,&local_18c);
  }
  FUN_0802aeac();
  return;
}


