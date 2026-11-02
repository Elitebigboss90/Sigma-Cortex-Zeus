Program sigma-decoded.bin language=ARM:LE:32:Cortex

// FUNCTION FUN_080250b4 @ 080250b4

void FUN_080250b4(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = *(char *)(DAT_20003c68 + 8);
  if ((cVar1 == '\x02') || (cVar1 == '\x04')) {
    uVar2 = 8;
  }
  else if ((cVar1 == '\x03') || (cVar1 == '\x05')) {
    FUN_08021890();
    uVar2 = *(undefined1 *)(DAT_20003c68 + 8);
  }
  else {
    if (cVar1 == '\a') {
      (**(code **)(DAT_20003c6c + 0xc))();
    }
    uVar2 = 8;
  }
  *(undefined1 *)(DAT_20003c68 + 8) = uVar2;
  FUN_08025144();
  return;
}



// FUNCTION FUN_08025144 @ 08025144

bool FUN_08025144(void)

{
  FUN_0802534c(0,DAT_2000003c);
  if (*(char *)(DAT_20003c68 + 8) == '\b') {
    DAT_20000d74 = 0x1000;
    DAT_20000d76 = 0x10;
  }
  return *(char *)(DAT_20003c68 + 8) == '\t';
}



// FUNCTION FUN_0802519c @ 0802519c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802519c(void)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = (uint)*(ushort *)((_DAT_40005c50 & 0xffff) * 2 + 0x40006008) * 2;
  if (DAT_20003c68[8] != '\t') {
    *DAT_20003c68 = *(undefined1 *)(iVar1 + 0x40006000);
    DAT_20003c68[1] = *(undefined1 *)(iVar1 + 0x40006001);
    uVar2 = FUN_080248ac(*(undefined2 *)(iVar1 + 0x40006004));
    *(undefined2 *)(DAT_20003c68 + 2) = uVar2;
    uVar2 = FUN_080248ac(*(undefined2 *)(iVar1 + 0x40006008));
    *(undefined2 *)(DAT_20003c68 + 4) = uVar2;
    *(undefined2 *)(DAT_20003c68 + 6) = *(undefined2 *)(iVar1 + 0x4000600c);
  }
  DAT_20003c68[8] = 1;
  if (*(short *)(DAT_20003c68 + 6) == 0) {
    FUN_08022f70();
  }
  else {
    FUN_080219c8();
  }
  FUN_08025144();
  return;
}



// FUNCTION FUN_08025280 @ 08025280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08025280(ushort param_1)

{
  _DAT_40005c50 = param_1 & 0xfffffff8;
  return;
}



// FUNCTION FUN_080252a0 @ 080252a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080252a0(byte param_1)

{
  uint uVar1;
  uint local_8;
  
  uVar1 = (uint)DAT_20000040;
  for (local_8 = 0; local_8 < uVar1; local_8 = local_8 + 1) {
    *(uint *)(&DAT_40005c00 + (local_8 & 0xff) * 4) =
         *(uint *)(&DAT_40005c00 + (local_8 & 0xff) * 4) & 0xf0f | local_8 & 0xff | 0x8080;
  }
  _DAT_40005c4c = param_1 | 0x80;
  return;
}



// FUNCTION FUN_0802530c @ 0802530c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802530c(byte param_1,ushort param_2)

{
  *(uint *)(((uint)param_1 * 8 + (_DAT_40005c50 & 0xffff)) * 2 + 0x40006008) = param_2 & 0xfffffffe;
  return;
}



// FUNCTION FUN_0802534c @ 0802534c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802534c(byte param_1,ushort param_2)

{
  uint *puVar1;
  undefined2 local_a;
  
  puVar1 = (uint *)(((uint)param_1 * 8 + (_DAT_40005c50 & 0xffff)) * 2 + 0x4000600c);
  if (param_2 < 0x3f) {
    local_a = param_2 >> 1;
    if ((param_2 & 1) != 0) {
      local_a = local_a + 1;
    }
    *puVar1 = (uint)local_a << 10;
  }
  else {
    local_a = param_2 >> 5;
    if ((param_2 & 0x1f) == 0) {
      local_a = local_a - 1;
    }
    *puVar1 = (uint)local_a << 0xb | 0x8000;
  }
  return;
}



// FUNCTION FUN_080253f0 @ 080253f0

void FUN_080253f0(byte param_1)

{
  *(uint *)(&DAT_40005c00 + (uint)param_1 * 4) =
       (ushort)*(undefined4 *)(&DAT_40005c00 + (uint)param_1 * 4) & 0xbf8f ^ 0x3000 | 0x8080;
  return;
}



// FUNCTION FUN_08025444 @ 08025444

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08025444(byte param_1,ushort param_2)

{
  *(uint *)(((uint)param_1 * 8 + (_DAT_40005c50 & 0xffff)) * 2 + 0x40006000) = param_2 & 0xfffffffe;
  return;
}



// FUNCTION FUN_08025484 @ 08025484

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08025484(byte param_1,ushort param_2)

{
  *(uint *)(((uint)param_1 * 8 + (_DAT_40005c50 & 0xffff)) * 2 + 0x40006004) = (uint)param_2;
  return;
}



// FUNCTION FUN_080254c0 @ 080254c0

void FUN_080254c0(byte param_1)

{
  *(uint *)(&DAT_40005c00 + (uint)param_1 * 4) =
       (ushort)*(undefined4 *)(&DAT_40005c00 + (uint)param_1 * 4) & 0x8fbf ^ 0x30 | 0x8080;
  return;
}



// FUNCTION FUN_08025514 @ 08025514

void FUN_08025514(byte param_1,ushort param_2)

{
  *(uint *)(&DAT_40005c00 + (uint)param_1 * 4) =
       *(uint *)(&DAT_40005c00 + (uint)param_1 * 4) & 0x898f | (uint)param_2;
  return;
}



// FUNCTION FUN_08025554 @ 08025554

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_08025554(void)

{
  _DAT_40005c44 = 0;
  DAT_20004a74 = 0x8400;
  _DAT_40005c40 = 0x8400;
  return 0;
}



// FUNCTION FUN_08025580 @ 08025580

uint FUN_08025580(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_08024e6c(param_1 & 0x7f);
  uVar2 = FUN_08024e3c(param_1 & 0x7f);
  FUN_080249a4(param_2,uVar2,uVar1 & 0xffff);
  return uVar1;
}



// FUNCTION FUN_080255cc @ 080255cc

undefined4 FUN_080255cc(uint param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_08024ea0(param_1 & 0x7f);
  FUN_08024a1c(param_2,uVar1,param_3);
  FUN_08025484(param_1 & 0x7f,param_3);
  return 0;
}



// FUNCTION thunk_FUN_08025622 @ 08025620

void thunk_FUN_08025622(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_08025622 @ 08025622

void FUN_08025622(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_08025624 @ 08025624

void FUN_08025624(void)

{
  FUN_0802dc18();
  FUN_0802dc28();
  FUN_0802dc40();
  FUN_0802dc58();
  FUN_0802dc70();
  FUN_0802dc88();
  return;
}



// FUNCTION FUN_08025640 @ 08025640

void FUN_08025640(void)

{
  return;
}



// FUNCTION FUN_08025654 @ 08025654

undefined1 FUN_08025654(uint param_1)

{
  undefined1 local_5;
  
  if (param_1 < 0x41) {
    local_5 = (undefined1)param_1;
  }
  else {
    local_5 = 0x40;
  }
  return local_5;
}



// FUNCTION FUN_08025684 @ 08025684

void FUN_08025684(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0802dbf0_1_0804cfc0;
  return;
}



// FUNCTION FUN_080256a0 @ 080256a0

void FUN_080256a0(undefined4 *param_1,int param_2)

{
  *param_1 = *(undefined4 *)(param_2 + 1);
  *(undefined2 *)((int)param_1 + 6) = 0;
  return;
}



// FUNCTION FUN_080256c0 @ 080256c0

bool FUN_080256c0(int param_1,int *param_2,short *param_3,undefined2 param_4)

{
  bool bVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined2 *)(param_1 + 6) = param_4;
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  }
  else if (*(char *)(param_1 + 4) != '\x01') goto LAB_08025762;
  while( true ) {
    bVar1 = false;
    if (*(short *)(param_1 + 6) != 0) {
      bVar1 = *param_3 != 0;
    }
    if (!bVar1) break;
    *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + -1;
    *param_2 = *param_2 + 1;
    *param_3 = *param_3 + -1;
  }
  if (*(short *)(param_1 + 6) == 0) {
    *(undefined1 *)(param_1 + 4) = 0;
  }
LAB_08025762:
  return *(short *)(param_1 + 6) == 0;
}



// FUNCTION FUN_08025770 @ 08025770

void FUN_08025770(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined2 *)((int)param_1 + 6) = 0;
  return;
}



// FUNCTION FUN_08025788 @ 08025788

void FUN_08025788(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x525)) ||
      ((*(short *)(param_1 + 0x72) == 0x483 && (*(short *)(param_1 + 0x70) == 0x524)))) &&
     (((2 < param_4 && (param_4 < 0x41)) && (param_5 != 0)))) {
    FUN_08020496(&DAT_20003cf0,param_5,param_4);
    DAT_20003d30 = 1;
    DAT_20003d34 = FUN_08048e5c();
  }
  else {
    DAT_20003d30 = 0;
    FUN_08020520(&DAT_20003cf0,0x40);
  }
  return;
}



// FUNCTION FUN_08025860 @ 08025860

undefined4 FUN_08025860(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x525)) ||
     ((*(short *)(param_1 + 0x72) == 0x483 && (*(short *)(param_1 + 0x70) == 0x524)))) {
    FUN_08049078(s_Init_succesfull_PedalDevice_0805424a);
    if (*(int *)(param_1 + 0x74) != 0) {
      (**(code **)(param_1 + 0x74))();
    }
    FUN_08020520(&DAT_20003cf0,0x40);
    DAT_20003d30 = 1;
  }
  else {
    DAT_20003d30 = 0;
  }
  return 0;
}



// FUNCTION FUN_08025900 @ 08025900

bool FUN_08025900(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if ((param_2 != 0x483) || (bVar1 = true, param_3 != 0x525)) {
    bVar1 = param_2 == 0x483 && param_3 == 0x524;
  }
  return bVar1;
}



// FUNCTION FUN_08025974 @ 08025974

undefined4 * FUN_08025974(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802a11c(param_1,param_2);
  *param_1 = &PTR_FUN_08029798_1_0804cfd4;
  param_1[1] = &DAT_0804d020;
  return param_1;
}



// FUNCTION FUN_080259a8 @ 080259a8

void FUN_080259a8(int param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0xd0);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined1 *)puVar1 = 0x80;
  *(undefined1 *)(param_1 + 0xd1) = 5;
  *(undefined2 *)(param_1 + 0xd2) = 0x9999;
  *(undefined1 *)(param_1 + 0xd4) = param_2;
  FUN_0802c684(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,puVar1,0);
  return;
}



// FUNCTION FUN_08025a28 @ 08025a28

undefined4 FUN_08025a28(int param_1,int param_2,short param_3)

{
  if ((*(byte *)(param_1 + 0x157) & 1) == 0) {
    FUN_0802bc88(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
                 *(undefined1 *)(param_1 + 0x40),param_3 + -1,param_2 + 1);
  }
  else {
    FUN_0802bc88(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
                 *(undefined1 *)(param_1 + 0x40),param_3,param_2);
  }
  return 1;
}



// FUNCTION FUN_08025aac @ 08025aac

void FUN_08025aac(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5)

{
  *(undefined1 *)(param_1 + 0x38) = 6;
  if ((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x522)) {
    if ((*(byte *)(param_1 + 0x157) & 1) == 0) {
      FUN_08025b98(param_1,param_5,param_4);
    }
    else {
      FUN_08026028(param_1,param_5,param_4);
    }
  }
  return;
}



// FUNCTION FUN_08025b30 @ 08025b30

void FUN_08025b30(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_1c = 0x5501f180;
  local_18 = 0xffaa;
  local_c = param_1;
  FUN_0802cb00(param_1,*(undefined1 *)(param_1 + 0x3a),0,3,0x80,0x10,&local_1c);
  return;
}



// FUNCTION FUN_08025b98 @ 08025b98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08025b98(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 == ' ') {
    FUN_08020496(param_1 + 0xe1,param_2,0x20);
    if (*(char *)(param_1 + 0xf6) == '\a') {
      *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_1 + 0xf7);
    }
    DAT_20004a90 = *(undefined2 *)(param_1 + 0xe2);
    uVar2 = *(uint *)(param_1 + 0xed) >> 4;
    DAT_20004a84 = (*(uint *)(param_1 + 0xf1) & 0xfff) >> 4;
    DAT_20004a80 = uVar2 | *(uint *)(param_1 + 0xf1) << 0x1c;
    if ((((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) &&
        ((*(ushort *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)(((uVar2 & 0xff0000) >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    if ((*(ushort *)(param_1 + 0x158) & 0xff) >> 6 != (uint)DAT_200000bc) {
      DAT_200000bc = (ushort)(((uint)*(ushort *)(param_1 + 0x158) << 0x18) >> 0x1e);
      if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) == 0) {
        FUN_0804a81c(2);
      }
      else {
        FUN_0804a73c(2);
      }
    }
    if ((*(ushort *)(param_1 + 0x158) >> 0xc & 3) == 0) {
      iVar1 = FUN_0802aa8c(&DAT_20002774);
      if (iVar1 == 0) {
        DAT_20004a98 = 0;
      }
      else {
        DAT_20004a98 = FUN_0802aa00(&DAT_20002774);
      }
    }
    else {
      DAT_20004a98 = (ushort)((uint3)*(undefined3 *)(param_1 + 0xfe) >> 0xc);
    }
    if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) {
      switch(*(ushort *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08027730(param_1);
        }
        else {
          FUN_08027a4c(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004a94 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
            DAT_20004a92 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
            DAT_20004a96 = -1;
          }
        }
        break;
      case 2:
        FUN_08026c24(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
        break;
      case 3:
        FUN_0802863c(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
        break;
      case 4:
        FUN_08027fe4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
        break;
      case 5:
        FUN_080271bc(param_1);
        break;
      case 6:
        FUN_08026580(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe5) >> 0xc) & 0xfff0);
      DAT_20004a94 = -1 - ((ushort)*(undefined4 *)(param_1 + 0xe5) & 0xfff0);
      DAT_20004a96 = -1 - (short)(*(int *)(param_1 + 0xe4) << 4);
    }
    if (DAT_20003d30 == '\x01') {
      DAT_20004a92 = _DAT_20003cf5 * -0x10 + -1;
      DAT_20004a94 = _DAT_20003cf3 * -0x10 + -1;
      DAT_20004a96 = _DAT_20003cf1 * -0x10 + -1;
    }
    if (*(ushort *)(param_1 + 0x158) >> 0xe == 0) {
      iVar1 = FUN_0802a348(&DAT_20002830);
      if (iVar1 == 0) {
        DAT_20004a9c = 0;
        DAT_20004a9a = 0;
        DAT_20004a9b = 0;
      }
      else {
        DAT_20004a9c = FUN_0802a27c();
        iVar1 = FUN_0802a2e0(&DAT_20002830);
        if (iVar1 == 0) {
          DAT_20004a9a = FUN_0802a16c();
          DAT_20004a9b = FUN_0802a208(&DAT_20002830);
        }
      }
    }
    else {
      DAT_20004a9c = FUN_08025654((*(uint *)(param_1 + 0xf1) & 0x1fffffff) >> 0x14);
    }
    DAT_20004a8c = DAT_20004a84;
    DAT_20004a88 = DAT_20004a80;
  }
  return;
}



// FUNCTION FUN_08026028 @ 08026028

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08026028(int param_1,int param_2,char param_3)

{
  int iVar1;
  
  if (param_3 == '\'') {
    DAT_20004a90 = *(undefined2 *)(param_2 + 1);
    DAT_20004a80 = (uint)(*(byte *)(param_2 + 0xc) >> 4) | (uint)*(byte *)(param_2 + 0xd) << 4 |
                   (uint)*(byte *)(param_2 + 0xe) << 0xc | (uint)*(byte *)(param_2 + 0xf) << 0x14 |
                   (uint)*(byte *)(param_2 + 0x10) << 0x1c;
    DAT_20004a84 = (uint)(*(byte *)(param_2 + 0x10) >> 4) | (uint)*(byte *)(param_2 + 0x11) << 4 |
                   (uint)*(byte *)(param_2 + 0x12) << 0xc | (uint)*(byte *)(param_2 + 0x13) << 0x14
                   | (uint)*(byte *)(param_2 + 0x14) << 0x1c;
    *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_2 + 0x1c);
    if ((((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) &&
        ((*(ushort *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)((DAT_20004a80 >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    DAT_20000d80 = (ushort)*(byte *)(param_2 + 9) | (*(byte *)(param_2 + 10) & 0xf) << 8;
    DAT_20000d7e = (ushort)(*(byte *)(param_2 + 10) >> 4) | (ushort)*(byte *)(param_2 + 0xb) << 4;
    if ((*(ushort *)(param_1 + 0x158) & 0xff) >> 6 != (uint)DAT_200000be) {
      DAT_200000be = (ushort)(((uint)*(ushort *)(param_1 + 0x158) << 0x18) >> 0x1e);
      if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) == 0) {
        FUN_0804a81c(2);
      }
      else {
        FUN_0804a73c(2);
      }
    }
    if ((*(ushort *)(param_1 + 0x158) >> 0xc & 3) == 0) {
      iVar1 = FUN_0802aa8c(&DAT_20002774);
      if (iVar1 == 0) {
        DAT_20004a98 = 0;
      }
      else {
        DAT_20004a98 = FUN_0802aa00(&DAT_20002774);
      }
    }
    else {
      DAT_20004a98 = (ushort)(*(byte *)(param_2 + 7) >> 4) | (ushort)*(byte *)(param_2 + 8) << 4;
    }
    if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) {
      switch(*(ushort *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08027730(param_1);
        }
        else {
          FUN_08027a4c(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
            DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
            DAT_20004a96 = -1;
          }
        }
        break;
      case 2:
        FUN_08026c24(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
        break;
      case 3:
        FUN_0802863c(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
        break;
      case 4:
        FUN_08027fe4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
        break;
      case 5:
        FUN_080271bc(param_1);
        break;
      case 6:
        FUN_08026580(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004a92 = *(short *)(param_2 + 3) * -0x10 + -1;
      DAT_20004a94 = ((ushort)(*(byte *)(param_2 + 4) >> 4) | (ushort)*(byte *)(param_2 + 5) << 4) *
                     -0x10 + -1;
      DAT_20004a96 = *(short *)(param_2 + 6) * -0x10 + -1;
    }
    if (DAT_20003d30 == '\x01') {
      DAT_20004a92 = _DAT_20003cf5 * -0x10 + -1;
      DAT_20004a94 = _DAT_20003cf3 * -0x10 + -1;
      DAT_20004a96 = _DAT_20003cf1 * -0x10 + -1;
    }
    if (*(ushort *)(param_1 + 0x158) >> 0xe == 0) {
      iVar1 = FUN_0802a348(&DAT_20002830);
      if (iVar1 == 0) {
        DAT_20004a9c = 0;
        DAT_20004a9a = 0;
        DAT_20004a9b = 0;
      }
      else {
        DAT_20004a9c = FUN_0802a27c();
        iVar1 = FUN_0802a2e0(&DAT_20002830);
        if (iVar1 == 0) {
          DAT_20004a9a = FUN_0802a16c();
          DAT_20004a9b = FUN_0802a208(&DAT_20002830);
        }
      }
    }
    else {
      if ((int)((uint)*(byte *)(param_2 + 0x1b) * 0x1000000) < 0) {
        DAT_20004a9c = 0;
      }
      else if ((int)((uint)*(byte *)(param_2 + 0x13) * 0x8000000) < 0) {
        DAT_20004a9c = 0x80;
      }
      else {
        DAT_20004a9c = FUN_08025654(*(byte *)(param_2 + 0x12) >> 4 | *(char *)(param_2 + 0x13) << 4)
        ;
      }
      DAT_20004a9b = 0;
      DAT_20004a9a = 0;
    }
    DAT_20004a8c = DAT_20004a84;
    DAT_20004a88 = DAT_20004a80;
  }
  return;
}



// FUNCTION FUN_08026564 @ 08026564

void FUN_08026564(undefined4 param_1)

{
  FUN_080306e4();
  FUN_08028f18(param_1);
  return;
}



// FUNCTION FUN_08026580 @ 08026580

void FUN_08026580(void)

{
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._2_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  else {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  else {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  return;
}



// FUNCTION FUN_08026a88 @ 08026a88

undefined4 FUN_08026a88(int param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x522)) {
    FUN_08049078(s_Init_succesfull_SimagicBase_08053edc);
    FUN_08025b30(param_1);
    FUN_08030dbc(0x32);
    *(undefined1 *)(param_1 + 0x101) = 0;
    *(undefined1 *)(param_1 + 0x103) = 0;
    *(undefined1 *)(param_1 + 0x156) = 0;
    FUN_08028e74(param_1);
    uVar1 = *(ushort *)(param_1 + 0xae) % 1000;
    if ((uVar1 < 0x96) || (0xaa < uVar1)) {
      *(undefined1 *)(param_1 + 0x157) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x157) = 0;
    }
    FUN_08028f18(param_1);
    FUN_0804b6bc();
    uVar3 = FUN_08048e5c();
    *(undefined4 *)(param_1 + 0x148) = uVar3;
    iVar4 = param_1 + 0x104;
    uVar2 = FUN_0804b440();
    *(undefined1 *)(param_1 + 0x144) = uVar2;
    FUN_0804b648(iVar4,*(undefined1 *)(param_1 + 0x144));
    uVar2 = FUN_0804b5c4(iVar4);
    *(undefined1 *)(param_1 + 0x144) = uVar2;
    FUN_0804b648(iVar4,*(undefined1 *)(param_1 + 0x144));
    uVar2 = FUN_0804b534(iVar4,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar2;
    FUN_0804b648(iVar4,*(undefined1 *)(param_1 + 0x144));
    uVar2 = FUN_0804b470(iVar4,1,0xffff,0xffff,0,0xff,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar2;
    FUN_0804b648(iVar4,*(undefined1 *)(param_1 + 0x144));
    uVar2 = FUN_0804b3e8(iVar4,1,0);
    *(undefined1 *)(param_1 + 0x144) = uVar2;
    FUN_0804b648(iVar4,*(undefined1 *)(param_1 + 0x144));
    uVar2 = FUN_0804b570(iVar4,1,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar2;
    FUN_0804b648(iVar4,*(undefined1 *)(param_1 + 0x144));
    FUN_08028bd4(param_1);
    FUN_080285b0(param_1,9);
  }
  return 0;
}



// FUNCTION FUN_08026c24 @ 08026c24

void FUN_08026c24(void)

{
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._3_1_ * 0x4000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x4000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x2000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x1000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) &&
     ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_080271bc @ 080271bc

void FUN_080271bc(void)

{
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._2_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  DAT_20004a9d = (int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0;
  DAT_20004a9e = (int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0;
  return;
}



// FUNCTION FUN_08027730 @ 08027730

void FUN_08027730(void)

{
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._1_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_08027a4c @ 08027a4c

void FUN_08027a4c(void)

{
  if ((int)((uint)DAT_20004a80._3_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._3_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  if ((DAT_20004a80._2_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  DAT_20004a7b = (int)((uint)DAT_20004a80._2_1_ * 0x40000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) && (((byte)DAT_20004a80 & 1) != 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_08027fe4 @ 08027fe4

void FUN_08027fe4(void)

{
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._2_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  DAT_20004a7b = (int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_08028544 @ 08028544

void FUN_08028544(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0x2d2d0580;
  local_c = param_1;
  FUN_0802c684(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,&local_1c,0);
  return;
}



// FUNCTION FUN_080285b0 @ 080285b0

void FUN_080285b0(int param_1,char param_2)

{
  undefined1 local_41;
  undefined1 local_40;
  char local_3c;
  char local_d;
  int local_c;
  
  local_d = param_2;
  local_c = param_1;
  FUN_08020520(&local_41,0x34);
  local_41 = 0x91;
  local_40 = 4;
  local_3c = local_d << 4;
  FUN_0802c684(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x3e,0x3e,&local_41,0);
  return;
}



// FUNCTION FUN_0802863c @ 0802863c

void FUN_0802863c(void)

{
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._3_1_ * 0x4000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x4000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x2000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x1000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) &&
     ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_08028bd4 @ 08028bd4

void FUN_08028bd4(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xb9) == '\0') {
    uVar1 = FUN_0804b5f4(param_1 + 0x104,6);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(param_1 + 0x104,*(undefined1 *)(param_1 + 0x144));
  }
  else {
    iVar2 = param_1 + 0x104;
    uVar1 = FUN_0804b470(iVar2,5,0xffff,0xffff,0,0xff,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(iVar2,*(undefined1 *)(param_1 + 0x144));
    uVar1 = FUN_0804b314(iVar2,5,0,0,0,0,0,0);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(iVar2,*(undefined1 *)(param_1 + 0x144));
    uVar1 = FUN_0804b570(iVar2,5,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(iVar2,*(undefined1 *)(param_1 + 0x144));
  }
  if (*(char *)(param_1 + 0xb8) == '\0') {
    uVar1 = FUN_0804b5f4(param_1 + 0x104,6);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(param_1 + 0x104,*(undefined1 *)(param_1 + 0x144));
  }
  else {
    iVar2 = param_1 + 0x104;
    uVar1 = FUN_0804b470(iVar2,6,0xffff,0xffff,0,0xff,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(iVar2,*(undefined1 *)(param_1 + 0x144));
    uVar1 = FUN_0804b314(iVar2,6,0,0,0,0,0,0);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(iVar2,*(undefined1 *)(param_1 + 0x144));
    uVar1 = FUN_0804b570(iVar2,6,0xff);
    *(undefined1 *)(param_1 + 0x144) = uVar1;
    FUN_0804b648(iVar2,*(undefined1 *)(param_1 + 0x144));
  }
  return;
}



// FUNCTION FUN_08028d50 @ 08028d50

void FUN_08028d50(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_080319a8();
  if ((DAT_20004a9d & 1) == 0) {
    uVar2 = FUN_08048e5c();
    *(undefined4 *)(param_1 + 0x148) = uVar2;
  }
  else {
    uVar1 = FUN_080324d0(*(undefined4 *)(param_1 + 0x148));
    if (4999 < uVar1) {
      FUN_08028544(param_1);
      uVar2 = FUN_08048e5c();
      *(undefined4 *)(param_1 + 0x148) = uVar2;
    }
  }
  if ((DAT_20004a9e & 1) == 0) {
    uVar2 = FUN_08048e5c();
    *(undefined4 *)(param_1 + 0x150) = uVar2;
  }
  else {
    uVar1 = FUN_080324d0(*(undefined4 *)(param_1 + 0x150));
    if (4999 < uVar1) {
      FUN_08026564(param_1);
      uVar2 = FUN_08048e5c();
      *(undefined4 *)(param_1 + 0x150) = uVar2;
    }
  }
  if ((*(byte *)(param_1 + 0x103) & 1) != 0) {
    *(undefined1 *)(param_1 + 0x103) = 0;
    FUN_080308b0();
    FUN_0804b0b8(*(undefined1 *)(param_1 + 0x102));
  }
  return;
}



// FUNCTION FUN_08028e28 @ 08028e28

bool FUN_08028e28(undefined4 param_1,short param_2,short param_3)

{
  return param_2 == 0x483 && param_3 == 0x522;
}



// FUNCTION FUN_08028e74 @ 08028e74

void FUN_08028e74(int param_1)

{
  FUN_08020564(param_1 + 0x74,0x3c);
  FUN_0802c684(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0xa1,1,0x81,3,0,0x10,0x40,param_1 + 0x74,0);
  if ((*(char *)(param_1 + 0x74) == -0x7f) && (*(char *)(param_1 + 0x75) == '\x06')) {
    FUN_0804a848(*(undefined1 *)(param_1 + 0xab));
    *(undefined1 *)(param_1 + 0x101) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x101) = 0;
  }
  return;
}



// FUNCTION FUN_08028f18 @ 08028f18

void FUN_08028f18(int param_1)

{
  undefined4 *puVar1;
  
  *(undefined1 *)(param_1 + 0xb0) = 0x80;
  *(undefined1 *)(param_1 + 0xb1) = 1;
  *(undefined2 *)(param_1 + 0xb2) = (&DAT_20002494)[DAT_200025e0 * 0x11];
  *(undefined2 *)(param_1 + 0xb4) = (&DAT_2000248c)[DAT_200025e0 * 0x11];
  *(undefined1 *)(param_1 + 0xb6) = *(undefined1 *)(&DAT_20002492 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xb7) = *(undefined1 *)(&DAT_2000248e + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xb8) = *(undefined1 *)(&DAT_20002496 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xb9) = *(undefined1 *)(&DAT_20002498 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xbb) = *(undefined1 *)(&DAT_2000249a + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xba) = *(undefined1 *)(&DAT_2000249e + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xbc) = *(undefined1 *)(&DAT_200024a0 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xbd) = *(undefined1 *)(&DAT_200024a6 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xbe) = *(undefined1 *)(&DAT_200024a2 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xbf) = *(undefined1 *)(&DAT_200024a4 + DAT_200025e0 * 0x11);
  FUN_0802c684(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,
               (undefined1 *)(param_1 + 0xb0),0);
  puVar1 = (undefined4 *)(param_1 + 0xc0);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined1 *)puVar1 = 0x80;
  *(undefined1 *)(param_1 + 0xc1) = 2;
  *(undefined2 *)(param_1 + 0xc2) = (&DAT_20002494)[DAT_200025e0 * 0x11];
  *(undefined1 *)(param_1 + 0xc4) = *(undefined1 *)(&DAT_200024a8 + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xc5) = *(undefined1 *)(&DAT_200024aa + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xc6) = *(undefined1 *)(&DAT_200024ac + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 199) = 1;
  *(undefined1 *)(param_1 + 200) = *(undefined1 *)(&DAT_2000249c + DAT_200025e0 * 0x11);
  *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(&DAT_20002490 + DAT_200025e0 * 0x11);
  FUN_0802c684(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,puVar1,0);
  return;
}



// FUNCTION FUN_0802914c @ 0802914c

undefined4 * FUN_0802914c(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802a11c(param_1,param_2);
  *param_1 = &PTR_FUN_08029798_1_0804d02c;
  param_1[1] = &DAT_0804d078;
  *(undefined1 *)((int)param_1 + 0x157) = 1;
  return param_1;
}



// FUNCTION FUN_08029198 @ 08029198

void FUN_08029198(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  for (local_5 = 0; local_5 < 2; local_5 = local_5 + 1) {
    *(undefined1 *)(param_1 + 0x10 + (uint)local_5 * 8) = 0;
    *(undefined4 *)(param_1 + 0x10 + (uint)local_5 * 8 + 4) = 0;
  }
  for (local_6 = 0; local_6 < 5; local_6 = local_6 + 1) {
    *(undefined1 *)(param_1 + 0x20 + (uint)local_6 * 3) = 0;
    *(undefined2 *)(param_1 + 0x20 + (uint)local_6 * 3 + 1) = 0;
  }
  for (local_7 = 0; local_7 < 5; local_7 = local_7 + 1) {
    iVar1 = param_1 + 0x5b;
    *(byte *)(iVar1 + (uint)local_7 * 4) = *(byte *)(iVar1 + (uint)local_7 * 4) & 0xf8;
    *(byte *)(iVar1 + (uint)local_7 * 4) = *(byte *)(iVar1 + (uint)local_7 * 4) & 0x3f;
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      *(undefined1 *)(param_1 + (uint)local_7 * 4 + (uint)local_8 + 0x5c) = 0;
    }
  }
  for (local_9 = 0; local_9 < 0xb; local_9 = local_9 + 1) {
    iVar1 = param_1 + 0x3a;
    *(undefined1 *)(iVar1 + (uint)local_9 * 3) = 0;
    uVar3 = 8;
    if (local_9 != 0) {
      uVar3 = 0;
    }
    *(undefined1 *)((uint)local_9 * 3 + iVar1 + 1) = uVar3;
    iVar2 = (uint)local_9 * 3 + iVar1;
    *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) & 0xfe;
    iVar2 = (uint)local_9 * 3 + iVar1;
    *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) & 0xfd;
    cVar4 = '\x0f';
    if (local_9 != 0) {
      cVar4 = '\x01';
    }
    iVar1 = iVar1 + (uint)local_9 * 3;
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 3 | cVar4 << 2;
  }
  *(undefined1 *)(param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  *(undefined1 *)(param_1 + 0x38) = 0;
  return;
}



// FUNCTION FUN_08029340 @ 08029340

void FUN_08029340(undefined4 param_1,byte param_2,int param_3)

{
  undefined1 local_15;
  
  for (local_15 = 0; local_15 < param_2; local_15 = local_15 + 1) {
    *(undefined1 *)(param_3 + (uint)local_15) = 0;
  }
  return;
}



// FUNCTION FUN_08029390 @ 08029390

void FUN_08029390(void)

{
  return;
}



// FUNCTION FUN_080293c4 @ 080293c4

int FUN_080293c4(int param_1,byte param_2,byte param_3,byte param_4)

{
  byte local_1c;
  
  local_1c = 0;
  while( true ) {
    if (*(byte *)(param_1 + 0x30) <= local_1c || 4 < local_1c) {
      return 0;
    }
    if ((((*(byte *)(param_1 + (uint)local_1c * 4 + 0x5b) & 7) == param_2) &&
        ((*(byte *)(param_1 + (uint)local_1c * 4 + 0x5b) & 0x3f) >> 3 == (uint)param_3)) &&
       (param_4 == *(byte *)(param_1 + (uint)local_1c * 4 + 0x5b) >> 6)) break;
    local_1c = local_1c + 1;
  }
  return param_1 + (uint)local_1c * 4 + 0x5b;
}



// FUNCTION FUN_080294a0 @ 080294a0

void FUN_080294a0(int *param_1,undefined4 param_2,uint param_3,uint param_4,char param_5,int param_6
                 )

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  byte *local_24;
  byte local_1d;
  
  bVar1 = (byte)param_4;
  *(char *)((int)param_1 + 0x2f) = (char)param_2;
  local_1d = 0;
  iVar2 = param_6;
  piVar4 = param_1;
  uVar5 = param_3;
  local_24 = (byte *)FUN_080293c4(param_1,param_3 & 0xff,param_4 & 0xff,param_5);
  if (local_24 == (byte *)0x0) {
    if (4 < *(byte *)(param_1 + 0xc)) {
      return;
    }
    local_24 = (byte *)((int)param_1 + (uint)*(byte *)(param_1 + 0xc) * 4 + 0x5b);
    *local_24 = (byte)param_3 & 7 | *local_24 & 0xf8;
    *local_24 = *local_24 & 199 | (bVar1 & 7) << 3;
    *local_24 = *local_24 & 0x3f | param_5 << 6;
    *(char *)(param_1 + 0xc) = (char)param_1[0xc] + '\x01';
  }
  if (((*(byte *)(param_6 + 3) & 3) == 3) && (local_1d = 2, (*(byte *)(param_6 + 2) & 0x80) != 0)) {
    local_1d = 1;
  }
  pcVar3 = *(code **)(*param_1 + 0x3c);
  iVar2 = (*pcVar3)(param_1,param_3 & 0xff,param_5,pcVar3,pcVar3,iVar2,piVar4,param_2,uVar5,param_4)
  ;
  if (iVar2 == 0) {
    local_1d = 0;
  }
  if ((local_1d != 0) && (*(byte *)((int)param_1 + 0x31) < 0xb)) {
    *(byte *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x31) * 3 + 0x3a) =
         *(byte *)(param_6 + 2) & 0xf;
    *(undefined1 *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x31) * 3 + 0x3b) =
         *(undefined1 *)(param_6 + 4);
    iVar2 = (uint)*(byte *)((int)param_1 + 0x31) * 3;
    *(byte *)((int)param_1 + iVar2 + 0x3c) = *(byte *)((int)param_1 + iVar2 + 0x3c) & 0xfe;
    iVar2 = (uint)*(byte *)((int)param_1 + 0x31) * 3;
    *(byte *)((int)param_1 + iVar2 + 0x3c) = *(byte *)((int)param_1 + iVar2 + 0x3c) & 0xfd;
    iVar2 = (uint)*(byte *)((int)param_1 + 0x31) * 3;
    *(byte *)((int)param_1 + iVar2 + 0x3c) = *(byte *)((int)param_1 + iVar2 + 0x3c) & 3 | 4;
    local_24[local_1d + 1] = *(byte *)((int)param_1 + 0x31);
    if (*(byte *)(param_1 + 0xe) < *(byte *)(param_6 + 6)) {
      *(undefined1 *)(param_1 + 0xe) = *(undefined1 *)(param_6 + 6);
    }
    *(char *)((int)param_1 + 0x31) = *(char *)((int)param_1 + 0x31) + '\x01';
  }
  return;
}



// FUNCTION FUN_080296ec @ 080296ec

undefined1 FUN_080296ec(int param_1,undefined1 param_2,undefined4 param_3)

{
  byte local_19;
  
  local_19 = 0;
  while( true ) {
    if (1 < local_19) {
      return 0;
    }
    if ((*(char *)(param_1 + (uint)local_19 * 8 + 0x10) == '\0') &&
       (*(int *)(param_1 + (uint)local_19 * 8 + 0x14) == 0)) break;
    local_19 = local_19 + 1;
  }
  *(undefined1 *)(param_1 + 0x10 + (uint)local_19 * 8) = param_2;
  *(undefined4 *)(param_1 + 0x10 + (uint)local_19 * 8 + 4) = param_3;
  return 1;
}



// FUNCTION FUN_08029798 @ 08029798

char FUN_08029798(int *param_1,undefined1 param_2,undefined1 param_3,byte param_4)

{
  undefined1 uVar1;
  byte local_89;
  undefined1 auStack_88 [63];
  byte local_49;
  int *local_48;
  byte local_42;
  byte local_41;
  int local_40;
  int *local_3c;
  char local_35;
  byte *local_34;
  byte local_2e [18];
  undefined1 local_1c;
  byte local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  int *local_18;
  char local_11;
  
  local_1c = 0x12;
  local_34 = local_2e;
  local_3c = (int *)0x0;
  local_40 = 0;
  local_41 = 0;
  local_1b = param_4;
  local_1a = param_3;
  local_19 = param_2;
  local_18 = param_1;
  local_48 = (int *)FUN_0802c0c4(param_1[2]);
  if ((char)param_1[3] == '\0') {
    local_3c = (int *)(**(code **)*local_48)(local_48,0);
    if (local_3c == (int *)0x0) {
      local_11 = -0x2a;
    }
    else if (*local_3c == 0) {
      local_11 = -0x29;
    }
    else {
      local_40 = *local_3c;
      *local_3c = (int)param_1 + 0x3a;
      *(byte *)((int)local_3c + 6) = local_1b & 1;
      local_35 = FUN_0802bc0c(param_1[2],0,0,8,local_2e);
      if ((local_35 == '\0') && (local_41 = local_2e[0], 0x12 < local_2e[0])) {
        local_41 = 0x12;
      }
      if (local_35 == '\0') {
        *local_3c = local_40;
        uVar1 = (**(code **)(*local_48 + 4))(local_48,local_19,0,local_1a);
        *(undefined1 *)(param_1 + 3) = uVar1;
        if ((char)param_1[3] == '\0') {
          return -0x2c;
        }
        *(byte *)((int)param_1 + 0x3b) = local_34[7];
        local_35 = FUN_0802c91c(param_1[2],0,0,(char)param_1[3]);
        if (local_35 != '\0') {
          *(undefined1 *)((int)local_3c + 6) = 0;
          (**(code **)(*local_48 + 8))(local_48,(char)param_1[3]);
          *(undefined1 *)(param_1 + 3) = 0;
          FUN_08025640(local_35,0x80);
          return local_35;
        }
        FUN_08025640((char)param_1[3],0x80);
        *(undefined1 *)((int)local_3c + 6) = 0;
        local_3c = (int *)(**(code **)*local_48)(local_48,(char)param_1[3]);
        if (local_3c == (int *)0x0) {
          return -0x2a;
        }
        *(byte *)((int)local_3c + 6) = local_1b & 1;
        if (local_41 != 0) {
          local_35 = FUN_0802bc0c(param_1[2],(char)param_1[3],0,local_41,local_2e);
        }
        if (local_35 == '\0') {
          *(undefined2 *)((int)param_1 + 0x72) = *(undefined2 *)(local_34 + 8);
          *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(local_34 + 10);
          local_42 = local_34[0x11];
          local_35 = FUN_0802c168(param_1[2],(char)param_1[3],1,(int)param_1 + 0x3a);
          if (local_35 == '\0') {
            FUN_08025640(local_42,0x80);
            for (local_49 = 0; local_49 < local_42; local_49 = local_49 + 1) {
              FUN_0802af00(auStack_88,param_1 + 1);
              local_35 = FUN_0802bd14(param_1[2],(char)param_1[3],0,local_49,auStack_88);
              if (local_35 != '\0') goto LAB_08029b6c;
              local_35 = '\0';
              if (1 < *(byte *)((int)param_1 + 0x31)) break;
            }
            if (*(byte *)((int)param_1 + 0x31) < 2) {
              return -0x2f;
            }
            local_35 = FUN_0802c168(param_1[2],(char)param_1[3],*(undefined1 *)((int)param_1 + 0x31)
                                    ,(int)param_1 + 0x3a);
            FUN_08025640(*(undefined1 *)((int)param_1 + 0x2f),0x80);
            local_35 = FUN_0802c980(param_1[2],(char)param_1[3],0,
                                    *(undefined1 *)((int)param_1 + 0x2f));
            if (local_35 == '\0') {
              FUN_08025640((char)param_1[0xc],0x80);
              local_89 = 0;
              do {
                if (*(byte *)(param_1 + 0xc) <= local_89) {
                  (**(code **)(*param_1 + 0x2c))();
                  *(undefined1 *)((int)param_1 + 0x39) = 1;
                  return '\0';
                }
                if (*(char *)((int)param_1 + (uint)local_89 * 4 + 0x5d) != '\0') {
                  FUN_08025640(*(byte *)((int)param_1 + (uint)local_89 * 4 + 0x5b) & 7,0x80);
                  local_35 = FUN_0802ca90(param_1,*(byte *)((int)param_1 + (uint)local_89 * 4 + 0x5b
                                                           ) & 7,0,0);
                  if ((local_35 != '\0') && (local_35 != '\x05')) break;
                }
                local_89 = local_89 + 1;
              } while( true );
            }
          }
        }
      }
      else {
        *local_3c = local_40;
      }
LAB_08029b6c:
      (**(code **)(*param_1 + 8))();
      local_11 = local_35;
    }
  }
  else {
    local_11 = -0x27;
  }
  return local_11;
}



// FUNCTION FUN_08029b88 @ 08029b88

undefined1 FUN_08029b88(int *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort local_56;
  byte local_53;
  byte local_52;
  undefined1 local_51 [64];
  undefined1 local_11;
  int *local_10;
  undefined1 local_9;
  
  local_11 = 0;
  if ((*(byte *)((int)param_1 + 0x39) & 1) == 0) {
    local_9 = 0;
  }
  else {
    local_10 = param_1;
    iVar3 = FUN_08048e5c();
    if (-1 < iVar3 - param_1[0xd]) {
      iVar3 = FUN_08048e5c();
      param_1[0xd] = iVar3 + (uint)*(byte *)(param_1 + 0xe);
      for (local_52 = 0; local_52 < *(byte *)(param_1 + 0xc); local_52 = local_52 + 1) {
        local_53 = *(byte *)((int)param_1 + (uint)local_52 * 4 + 0x5d);
        if (local_53 != 0) {
          local_56 = (ushort)*(byte *)((int)param_1 + (uint)local_53 * 3 + 0x3b);
          FUN_08029340(param_1,0x40,local_51);
          cVar2 = FUN_0802b434(param_1[2],(char)param_1[3],
                               *(undefined1 *)((int)param_1 + (uint)local_53 * 3 + 0x3a),&local_56,
                               local_51,0);
          if (cVar2 == '\0') {
            if (local_56 != 0) {
              if (0x40 < local_56) {
                local_56 = 0x40;
              }
              (**(code **)(*param_1 + 0x30))
                        (param_1,param_1,*(undefined1 *)((int)param_1 + (uint)local_53 * 3 + 0x3a),
                         *(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_56,local_51);
              uVar1 = local_51[0];
              if ((*(byte *)((int)param_1 + 0x6f) & 1) == 0) {
                uVar1 = 0;
              }
              puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x24))(param_1,uVar1);
              if (puVar4 != (undefined4 *)0x0) {
                (**(code **)*puVar4)
                          (puVar4,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_56,
                           local_51);
              }
            }
          }
          else if (cVar2 != '\x04') {
            FUN_08025640(cVar2,0x81);
          }
        }
      }
    }
    local_9 = local_11;
  }
  return local_9;
}



// FUNCTION FUN_08029d70 @ 08029d70

void FUN_08029d70(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0802c0c4(*(undefined4 *)(param_1 + 8));
  (**(code **)(*piVar1 + 8))(piVar1,*(undefined1 *)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x39) = 0;
  return;
}



// FUNCTION FUN_08029db0 @ 08029db0

byte FUN_08029db0(int param_1)

{
  return *(byte *)(param_1 + 0x39) & 1;
}



// FUNCTION FUN_08029dc8 @ 08029dc8

undefined4 * FUN_08029dc8(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802cb94(param_1,param_2);
  *param_1 = &PTR_FUN_08029798_1_0804d084;
  param_1[1] = &DAT_0804d0cc;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  *(undefined1 *)((int)param_1 + 0x6f) = 0;
  FUN_08029198(param_1);
  if (param_1[2] != 0) {
    FUN_0802c2e4(param_1[2],param_1);
  }
  return param_1;
}



// FUNCTION FUN_08029e2c @ 08029e2c

void FUN_08029e2c(void)

{
  return;
}



// FUNCTION FUN_08029e5c @ 08029e5c

void FUN_08029e5c(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined1 param_5
                 ,undefined4 param_6)

{
  (**(code **)(*param_1 + 0x40))
            (param_1,param_2,param_4 & 1,param_5,param_6,param_6,param_1,param_2,param_3,param_4);
  return;
}



// FUNCTION FUN_08029eb8 @ 08029eb8

void FUN_08029eb8(int param_1,char param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5,
                 undefined4 param_6)

{
  if ((*(byte *)(param_1 + 0x31) < 2) || (param_2 == *(char *)(param_1 + 0x2f))) {
    FUN_080294a0(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}



// FUNCTION FUN_08029f34 @ 08029f34

undefined4 FUN_08029f34(void)

{
  return 1;
}



// FUNCTION FUN_08029f58 @ 08029f58

char FUN_08029f58(int *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort local_56;
  byte local_53;
  byte local_52;
  undefined1 local_51 [64];
  char local_11;
  int *local_10;
  char local_9;
  
  local_11 = '\0';
  if ((*(byte *)((int)param_1 + 0x39) & 1) == 0) {
    local_9 = '\0';
  }
  else {
    local_10 = param_1;
    iVar3 = FUN_08048e5c();
    if (-1 < iVar3 - param_1[0xd]) {
      iVar3 = FUN_08048e5c();
      param_1[0xd] = iVar3 + (uint)*(byte *)(param_1 + 0xe);
      for (local_52 = 0; local_52 < *(byte *)(param_1 + 0xc); local_52 = local_52 + 1) {
        local_53 = *(byte *)((int)param_1 + (uint)local_52 * 4 + 0x5d);
        local_56 = (ushort)*(byte *)((int)param_1 + (uint)local_53 * 3 + 0x3b);
        FUN_08029340(param_1,0x40);
        cVar2 = FUN_0802b434(param_1[2],(char)param_1[3],
                             *(undefined1 *)((int)param_1 + (uint)local_53 * 3 + 0x3a),&local_56,
                             local_51,0);
        if (cVar2 != '\0') {
          if (cVar2 == '\x04') {
            return '\x04';
          }
          FUN_08025640(cVar2,0x81);
          return cVar2;
        }
        if (0x40 < local_56) {
          local_56 = 0x40;
        }
        (**(code **)(*param_1 + 0x40))
                  (param_1,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_56,local_51)
        ;
        uVar1 = local_51[0];
        if ((*(byte *)((int)param_1 + 0x6f) & 1) == 0) {
          uVar1 = 0;
        }
        puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x24))(param_1,uVar1);
        if (puVar4 != (undefined4 *)0x0) {
          (**(code **)*puVar4)
                    (puVar4,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_56,local_51
                    );
        }
      }
    }
    local_9 = local_11;
  }
  return local_9;
}



// FUNCTION FUN_0802a11c @ 0802a11c

undefined4 * FUN_0802a11c(undefined4 *param_1,undefined4 param_2)

{
  FUN_08029dc8(param_1,param_2);
  *param_1 = &PTR_FUN_08029798_1_0804d0d8;
  param_1[1] = &DAT_0804d124;
  return param_1;
}



// FUNCTION FUN_0802a150 @ 0802a150

void FUN_0802a150(undefined4 *param_1)

{
  *param_1 = &DAT_0804d130;
  return;
}



// FUNCTION FUN_0802a16c @ 0802a16c

bool FUN_0802a16c(int param_1)

{
  return *(char *)(param_1 + 0x7a) == '\f';
}



// FUNCTION FUN_0802a188 @ 0802a188

void FUN_0802a188(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x531)) &&
      (2 < param_4)) && ((param_4 < 0x41 && (param_5 != 0)))) {
    FUN_08020496(param_1 + 0x78,param_5,param_4);
  }
  return;
}



// FUNCTION FUN_0802a208 @ 0802a208

bool FUN_0802a208(int param_1)

{
  return *(char *)(param_1 + 0x7a) == '\n';
}



// FUNCTION FUN_0802a224 @ 0802a224

undefined4 FUN_0802a224(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x72) == 0x531)) &&
     (FUN_08049078(s_Init_succesfull_handAuthDevice_08054229), *(int *)(param_1 + 0x74) != 0)) {
    (**(code **)(param_1 + 0x74))();
  }
  return 0;
}



// FUNCTION FUN_0802a27c @ 0802a27c

undefined1 FUN_0802a27c(int param_1)

{
  undefined1 local_5;
  
  if (*(char *)(param_1 + 0x7a) == '\0') {
    if (*(byte *)(param_1 + 0x79) < 0x41) {
      local_5 = *(undefined1 *)(param_1 + 0x79);
    }
    else {
      local_5 = 0x40;
    }
  }
  else if (*(char *)(param_1 + 0x7a) == '\x01') {
    local_5 = 0x80;
  }
  else {
    local_5 = 0;
  }
  return local_5;
}



// FUNCTION FUN_0802a2e0 @ 0802a2e0

uint FUN_0802a2e0(int param_1)

{
  return (*(byte *)(param_1 + 0x7a) & 8) >> 3 ^ 1;
}



// FUNCTION FUN_0802a2fc @ 0802a2fc

bool FUN_0802a2fc(undefined4 param_1,short param_2,short param_3)

{
  return param_2 == 0x483 && param_3 == 0x531;
}



// FUNCTION FUN_0802a348 @ 0802a348

bool FUN_0802a348(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_08029db0();
  bVar1 = false;
  if ((iVar2 != 0) && (bVar1 = false, *(short *)(param_1 + 0x72) == 0x483)) {
    bVar1 = *(short *)(param_1 + 0x70) == 0x531;
  }
  return bVar1;
}



// FUNCTION FUN_0802a39c @ 0802a39c

undefined4 * FUN_0802a39c(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802a11c(param_1,param_2);
  *param_1 = &PTR_FUN_08029798_1_0804d13c;
  param_1[1] = &DAT_0804d188;
  return param_1;
}



// FUNCTION FUN_0802a3d0 @ 0802a3d0

void FUN_0802a3d0(undefined4 param_1,char param_2)

{
  undefined1 uVar1;
  
  if (param_2 == 'A') {
    FUN_0802a714(param_1);
  }
  else {
    uVar1 = FUN_0802a6ac(param_1,param_2);
    FUN_0802a758(param_1,uVar1);
  }
  return;
}



// FUNCTION FUN_0802a418 @ 0802a418

undefined1 FUN_0802a418(int param_1,byte param_2,uint param_3,byte param_4)

{
  byte bVar1;
  byte bVar2;
  byte local_20;
  undefined1 local_11;
  
  if (((char)param_2 < '\0') || (7 < param_4)) {
    local_11 = 0;
  }
  else if (((param_3 & 1) == 0) || (*(char *)(param_1 + 7) != '\a')) {
    bVar1 = FUN_0802a6ac(param_1,0);
    if (bVar1 == 0) {
      local_11 = 0;
    }
    else if (param_2 == 0) {
      if ((param_3 & 1) == 0) {
        *(undefined1 *)((uint)bVar1 * 7 + param_1 + 0xc) = 1;
      }
      else {
        *(undefined1 *)((uint)bVar1 * 7 + param_1 + 0xc) = 0x41;
        *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
      }
      local_11 = *(undefined1 *)((uint)bVar1 * 7 + param_1 + 0xc);
    }
    else {
      local_20 = (param_2 & 7) << 3;
      if ((param_3 & 1) == 0) {
        local_20 = param_4 & 7 | local_20;
      }
      else {
        bVar2 = *(char *)(param_1 + 7) + 1;
        *(byte *)(param_1 + 7) = bVar2;
        local_20 = bVar2 & 7 | local_20 | 0x40;
      }
      *(byte *)((uint)bVar1 * 7 + param_1 + 8 + 4) = local_20;
      local_11 = *(undefined1 *)(param_1 + 8 + (uint)bVar1 * 7 + 4);
    }
  }
  else {
    local_11 = 0;
  }
  return local_11;
}



// FUNCTION FUN_0802a5a0 @ 0802a5a0

byte FUN_0802a5a0(int param_1,byte param_2,byte param_3)

{
  byte local_2c;
  byte local_16;
  
  if ((param_3 == 0) || (local_2c = param_3, 0xf < param_3)) {
    local_2c = 1;
  }
  local_16 = local_2c;
  while( true ) {
    if (0xf < local_16) {
      return 0;
    }
    if ((*(byte *)((uint)local_16 * 7 + param_1 + 0xc) & 0x3f) >> 3 == (param_2 & 7)) break;
    local_16 = local_16 + 1;
  }
  return local_16;
}



// FUNCTION FUN_0802a644 @ 0802a644

int FUN_0802a644(int param_1,char param_2)

{
  byte bVar1;
  undefined4 local_24;
  undefined4 local_c;
  
  if (param_2 == '\0') {
    local_c = param_1 + 8;
  }
  else {
    bVar1 = FUN_0802a6ac(param_1,param_2);
    if (bVar1 == 0) {
      local_24 = 0;
    }
    else {
      local_24 = (uint)bVar1 * 7 + param_1 + 8;
    }
    local_c = local_24;
  }
  return local_c;
}



// FUNCTION FUN_0802a6ac @ 0802a6ac

byte FUN_0802a6ac(int param_1,char param_2)

{
  byte local_a;
  
  local_a = 1;
  while( true ) {
    if (0xf < local_a) {
      return 0;
    }
    if (*(char *)((uint)local_a * 7 + param_1 + 0xc) == param_2) break;
    local_a = local_a + 1;
  }
  return local_a;
}



// FUNCTION FUN_0802a714 @ 0802a714

void FUN_0802a714(int param_1)

{
  undefined1 local_d;
  
  for (local_d = 1; local_d < 0x10; local_d = local_d + 1) {
    FUN_0802a804(param_1,local_d);
  }
  *(undefined1 *)(param_1 + 7) = 0;
  return;
}



// FUNCTION FUN_0802a758 @ 0802a758

void FUN_0802a758(int param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  undefined1 local_11;
  
  if (param_2 != 0) {
    bVar1 = *(byte *)((uint)param_2 * 7 + param_1 + 0xc);
    if ((bVar1 >> 6 & 1) != 0) {
      local_11 = 1;
      while( true ) {
        uVar2 = FUN_0802a5a0(param_1,bVar1,local_11);
        local_11 = (undefined1)uVar2;
        if (uVar2 == 0) break;
        FUN_0802a758(param_1,uVar2 & 0xff);
      }
      if (*(byte *)(param_1 + 7) == (bVar1 & 7)) {
        *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + -1;
      }
    }
    FUN_0802a804(param_1,param_2);
  }
  return;
}



// FUNCTION FUN_0802a804 @ 0802a804

void FUN_0802a804(int param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 8;
  *(undefined1 *)((uint)param_2 * 7 + iVar1 + 4) = 0;
  *(undefined1 *)((uint)param_2 * 7 + iVar1 + 5) = 1;
  *(undefined1 *)((uint)param_2 * 7 + iVar1 + 6) = 0;
  *(int *)(iVar1 + (uint)param_2 * 7) = param_1 + 4;
  return;
}



// FUNCTION FUN_0802a860 @ 0802a860

undefined4 * FUN_0802a860(undefined4 *param_1)

{
  FUN_08025684();
  *param_1 = &PTR_FUN_0802a644_1_0804d194;
  *(undefined1 *)((int)param_1 + 7) = 0;
  FUN_0802a804(param_1,0);
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[2] = param_1 + 1;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 8;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xfe;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xfd;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 3 | 0x3c;
  FUN_0802a714(param_1);
  return param_1;
}



// FUNCTION FUN_0802a8e4 @ 0802a8e4

void FUN_0802a8e4(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x530)) ||
      ((*(short *)(param_1 + 0x72) == 0x3670 && (*(short *)(param_1 + 0x70) == 0xa04)))) &&
     (((2 < param_4 && (param_4 < 0x41)) && (param_5 != 0)))) {
    FUN_08020496(param_1 + 0x78,param_5,param_4);
  }
  return;
}



// FUNCTION FUN_0802a980 @ 0802a980

undefined4 FUN_0802a980(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x72) == 0x530)) ||
     ((*(short *)(param_1 + 0x72) == 0x3670 && (*(short *)(param_1 + 0x72) == 0xa04)))) {
    FUN_08049078(s_Init_succesfull_handAuthDevice_08054229);
    if (*(int *)(param_1 + 0x74) != 0) {
      (**(code **)(param_1 + 0x74))();
    }
    FUN_08020564(param_1 + 0x78,0x40);
  }
  return 0;
}



// FUNCTION FUN_0802aa00 @ 0802aa00

undefined2 FUN_0802aa00(int param_1)

{
  return *(undefined2 *)(param_1 + 0x79);
}



// FUNCTION FUN_0802aa1c @ 0802aa1c

bool FUN_0802aa1c(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if ((param_2 != 0x483) || (bVar1 = true, param_3 != 0x530)) {
    bVar1 = param_2 == 0x3670 && param_3 == 0xa04;
  }
  return bVar1;
}



// FUNCTION FUN_0802aa8c @ 0802aa8c

bool FUN_0802aa8c(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_08029db0();
  bVar1 = false;
  if ((iVar2 != 0) &&
     (((*(short *)(param_1 + 0x72) != 0x483 || (bVar1 = true, *(short *)(param_1 + 0x70) != 0x530))
      && (bVar1 = false, *(short *)(param_1 + 0x72) == 0x3670)))) {
    bVar1 = *(short *)(param_1 + 0x70) == 0xa04;
  }
  return bVar1;
}



// FUNCTION FUN_0802ab08 @ 0802ab08

undefined4 * FUN_0802ab08(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802a11c(param_1,param_2);
  *param_1 = &PTR_FUN_08029798_1_0804d1a8;
  param_1[1] = &DAT_0804d1f4;
  return param_1;
}



// FUNCTION FUN_0802ab90 @ 0802ab90

undefined4 FUN_0802ab90(void)

{
  return 0;
}



// FUNCTION FUN_0802abbc @ 0802abbc

undefined4 FUN_0802abbc(void)

{
  return 0;
}



// FUNCTION FUN_0802ac08 @ 0802ac08

undefined4 FUN_0802ac08(void)

{
  return 0;
}



// FUNCTION FUN_0802ac2c @ 0802ac2c

void FUN_0802ac2c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0802abbc_1_0804d200;
  return;
}



// FUNCTION FUN_0802ac48 @ 0802ac48

undefined1 FUN_0802ac48(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined1 local_11;
  
  switch(*(undefined1 *)(param_1 + 0x30)) {
  case 0:
    *(undefined1 *)(param_1 + 8) = 2;
    FUN_0802aff0(param_1 + 0x10);
    *(undefined1 *)(param_1 + 0x30) = 1;
  case 1:
    iVar2 = FUN_0802b014(param_1 + 0x10,param_2,param_3);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 0x31) = **(undefined1 **)(param_1 + 9);
      *(undefined1 *)(param_1 + 0x32) = *(undefined1 *)(*(int *)(param_1 + 9) + 1);
      *(undefined1 *)(param_1 + 0x30) = 2;
switchD_0802ac7e_caseD_2:
      *(int *)(param_1 + 9) = param_1 + 0x22;
      *(undefined1 *)(param_1 + 0x30) = 3;
      goto switchD_0802ac7e_caseD_3;
    }
    local_11 = 0;
    break;
  case 2:
    goto switchD_0802ac7e_caseD_2;
  case 3:
switchD_0802ac7e_caseD_3:
    switch(*(undefined1 *)(param_1 + 0x32)) {
    case 2:
    case 5:
    case 0x21:
      break;
    case 4:
      *(undefined1 *)(param_1 + 0x33) = 0;
    }
    *(char *)(param_1 + 8) = *(char *)(param_1 + 0x31) + -2;
    FUN_0802aff0(param_1 + 0x10,param_1 + 8);
    *(undefined1 *)(param_1 + 0x30) = 4;
  case 4:
    cVar1 = *(char *)(param_1 + 0x32);
    if (cVar1 == '\x02') {
      iVar2 = FUN_0802b014(param_1 + 0x10,param_2,param_3);
      if (iVar2 == 0) {
        return 0;
      }
      *(undefined1 *)(param_1 + 0x34) = *(undefined1 *)(param_1 + 0x25);
    }
    else if (cVar1 == '\x04') {
      iVar2 = FUN_0802b014(param_1 + 0x10,param_2,param_3);
      if (iVar2 == 0) {
        return 0;
      }
      if ((*(char *)(param_1 + 0x25) == '\x03') && ((*(byte *)(param_1 + 0x38) & 1) == 0)) {
        *(undefined1 *)(param_1 + 0x33) = 1;
        *(undefined1 *)(param_1 + 0x36) = *(undefined1 *)(param_1 + 0x22);
        *(undefined1 *)(param_1 + 0x37) = *(undefined1 *)(param_1 + 0x23);
        *(undefined1 *)(param_1 + 0x35) = *(undefined1 *)(param_1 + 0x27);
      }
    }
    else if (cVar1 == '\x05') {
      iVar2 = FUN_0802b014(param_1 + 0x10,param_2,param_3);
      if (iVar2 == 0) {
        return 0;
      }
      if (((*(byte *)(param_1 + 0x33) & 1) != 0) && (*(int *)(param_1 + 4) != 0)) {
        (**(code **)**(undefined4 **)(param_1 + 4))
                  (*(undefined4 **)(param_1 + 4),*(undefined1 *)(param_1 + 0x34),
                   *(undefined1 *)(param_1 + 0x36),*(undefined1 *)(param_1 + 0x37),
                   *(undefined1 *)(param_1 + 0x35),param_1 + 0x20);
      }
    }
    else {
      iVar2 = FUN_080256c0(param_1 + 0x18,param_2,param_3,*(byte *)(param_1 + 0x31) - 2);
      if (iVar2 == 0) {
        return 0;
      }
    }
    *(int *)(param_1 + 9) = param_1 + 0x20;
    *(undefined1 *)(param_1 + 0x30) = 0;
  default:
    local_11 = 1;
  }
  return local_11;
}



// FUNCTION FUN_0802aea8 @ 0802aea8

void FUN_0802aea8(undefined4 param_1,short param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_28;
  short local_22;
  undefined4 local_20;
  undefined4 local_1c;
  short local_16;
  undefined4 local_14;
  
  local_28 = param_3;
  local_22 = param_2;
  local_20 = param_4;
  local_1c = param_3;
  local_16 = param_2;
  local_14 = param_1;
  do {
    if (local_22 == 0) {
      return;
    }
    iVar1 = FUN_0802ac48(param_1,&local_28,&local_22);
  } while (iVar1 != 0);
  return;
}



// FUNCTION FUN_0802af00 @ 0802af00

undefined4 * FUN_0802af00(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802a150();
  *param_1 = &DAT_0804d22c;
  param_1[1] = param_2;
  FUN_0802af84();
  FUN_0802b0c4(param_1 + 4);
  FUN_08025770(param_1 + 6);
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 0;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined4 **)((int)param_1 + 9) = param_1 + 8;
  FUN_0802aff0(param_1 + 4,param_1 + 2);
  FUN_080256a0(param_1 + 6,param_1 + 2);
  return param_1;
}



// FUNCTION FUN_0802af84 @ 0802af84

void FUN_0802af84(undefined1 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return;
}



// FUNCTION FUN_0802af9c @ 0802af9c

void FUN_0802af9c(void)

{
  return;
}



// FUNCTION FUN_0802afd4 @ 0802afd4

void FUN_0802afd4(undefined4 *param_1)

{
  *param_1 = &DAT_0804d238;
  return;
}



// FUNCTION FUN_0802aff0 @ 0802aff0

void FUN_0802aff0(undefined4 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  *param_1 = *(undefined4 *)(param_2 + 1);
  uVar1 = *param_2;
  *(undefined1 *)((int)param_1 + 5) = uVar1;
  *(undefined1 *)(param_1 + 1) = uVar1;
  return;
}


