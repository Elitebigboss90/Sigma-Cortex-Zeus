// FUNCTION 140b7fc80

void FUN_140b7fc80(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_140b806d0(param_1,param_2);
  func_0x00014107e1af(param_1 + 0xf0,param_3,0x10);
  return;
}


// 140b7fc80 MOV qword ptr [RSP + 0x18],R8
// FUNCTION 140b7fd10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140b7fd10(longlong param_1,longlong param_2,uint param_3)

{
  undefined1 auStack_48 [32];
  int iStack_28;
  uint uStack_24;
  byte abStack_20 [16];
  ulonglong uStack_10;
  
  uStack_10 = _DAT_1417011c0 ^ (ulonglong)auStack_48;
  uStack_24 = 0;
  iStack_28 = 0x10;
  do {
    if (param_3 <= uStack_24) {
      FUN_14107c400(uStack_10 ^ (ulonglong)auStack_48);
      return;
    }
    if (iStack_28 == 0x10) {
      func_0x00014107e1af(abStack_20,param_1 + 0xf0,0x10);
      FUN_140b80620(abStack_20,param_1);
      for (iStack_28 = 0xf; -1 < iStack_28; iStack_28 = iStack_28 + -1) {
        if (*(char *)(param_1 + 0xf0 + (longlong)iStack_28) != -1) {
          *(char *)(param_1 + 0xf0 + (longlong)iStack_28) =
               *(char *)(param_1 + 0xf0 + (longlong)iStack_28) + '\x01';
          break;
        }
        *(undefined1 *)(param_1 + 0xf0 + (longlong)iStack_28) = 0;
      }
      iStack_28 = 0;
    }
    *(byte *)(param_2 + (ulonglong)uStack_24) =
         *(byte *)(param_2 + (ulonglong)uStack_24) ^ abStack_20[iStack_28];
    uStack_24 = uStack_24 + 1;
    iStack_28 = iStack_28 + 1;
  } while( true );
}


// 140b7fd10 MOV dword ptr [RSP + 0x18],R8D
// FUNCTION 140b80620

void FUN_140b80620(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  
  FUN_140b7fe60(0,param_1,param_2,param_4,0);
  for (bVar1 = 1; bVar1 < 0xe; bVar1 = bVar1 + 1) {
    FUN_140b7ff10(param_1);
    FUN_140b7ffa0(param_1);
    FUN_140b80320(param_1);
    FUN_140b7fe60(bVar1,param_1,param_2);
  }
  FUN_140b7ff10(param_1);
  FUN_140b7ffa0(param_1);
  FUN_140b7fe60(0xe,param_1,param_2);
  return;
}


// 140b80620 MOV qword ptr [RSP + 0x10],RDX
// FUNCTION 140b806d0

void FUN_140b806d0(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  uint uStack_20;
  
  for (uStack_20 = 0; uStack_20 < 8; uStack_20 = uStack_20 + 1) {
    *(undefined1 *)(param_1 + (ulonglong)(uStack_20 << 2)) =
         *(undefined1 *)(param_2 + (ulonglong)(uStack_20 << 2));
    *(undefined1 *)(param_1 + (ulonglong)(uStack_20 * 4 + 1)) =
         *(undefined1 *)(param_2 + (ulonglong)(uStack_20 * 4 + 1));
    *(undefined1 *)(param_1 + (ulonglong)(uStack_20 * 4 + 2)) =
         *(undefined1 *)(param_2 + (ulonglong)(uStack_20 * 4 + 2));
    *(undefined1 *)(param_1 + (ulonglong)(uStack_20 * 4 + 3)) =
         *(undefined1 *)(param_2 + (ulonglong)(uStack_20 * 4 + 3));
  }
  for (uStack_20 = 8; uStack_20 < 0x3c; uStack_20 = uStack_20 + 1) {
    iVar1 = uStack_20 * 4;
    bStack_24 = *(byte *)(param_1 + (ulonglong)(iVar1 - 4));
    bStack_23 = *(byte *)(param_1 + (ulonglong)(iVar1 - 3));
    bStack_22 = *(byte *)(param_1 + (ulonglong)(iVar1 - 2));
    bStack_21 = *(byte *)(param_1 + (ulonglong)(iVar1 - 1));
    if (uStack_20 % 8 == 0) {
      uVar3 = (ulonglong)bStack_23;
      bStack_23 = (&UNK_1414a0dc0)[bStack_22];
      bStack_22 = (&UNK_1414a0dc0)[bStack_21];
      bStack_21 = (&UNK_1414a0dc0)[bStack_24];
      bStack_24 = (&UNK_1414a0dc0)[uVar3] ^ (&UNK_1414a0fc0)[(ulonglong)uStack_20 / 8];
    }
    if (uStack_20 % 8 == 4) {
      bStack_24 = (&UNK_1414a0dc0)[bStack_24];
      bStack_23 = (&UNK_1414a0dc0)[bStack_23];
      bStack_22 = (&UNK_1414a0dc0)[bStack_22];
      bStack_21 = (&UNK_1414a0dc0)[bStack_21];
    }
    uVar2 = uStack_20 * 4;
    iVar1 = uStack_20 * 4;
    *(byte *)(param_1 + (ulonglong)uVar2) =
         *(byte *)(param_1 + (ulonglong)(iVar1 - 0x20)) ^ bStack_24;
    *(byte *)(param_1 + (ulonglong)(uVar2 + 1)) =
         *(byte *)(param_1 + (ulonglong)(iVar1 - 0x1f)) ^ bStack_23;
    *(byte *)(param_1 + (ulonglong)(uVar2 + 2)) =
         *(byte *)(param_1 + (ulonglong)(iVar1 - 0x1e)) ^ bStack_22;
    *(byte *)(param_1 + (ulonglong)(uVar2 + 3)) =
         *(byte *)(param_1 + (ulonglong)(iVar1 - 0x1d)) ^ bStack_21;
  }
  return;
}


// 140b806d0 MOV qword ptr [RSP + 0x10],RDX
// FUNCTION 14057a0e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_14057a0e0(longlong param_1,longlong param_2)

{
  undefined1 auStack_178 [32];
  undefined1 uStack_158;
  undefined1 uStack_157;
  uint uStack_154;
  uint uStack_150;
  longlong lStack_148;
  undefined1 *puStack_140;
  undefined1 *puStack_138;
  undefined1 *puStack_130;
  undefined1 *puStack_128;
  undefined1 *puStack_120;
  undefined1 *puStack_118;
  undefined1 *puStack_110;
  longlong lStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong lStack_e0;
  longlong lStack_d8;
  longlong *plStack_d0;
  longlong lStack_c8;
  longlong lStack_c0;
  longlong lStack_b8;
  longlong lStack_b0;
  longlong lStack_a8;
  undefined1 auStack_98 [32];
  undefined1 auStack_78 [32];
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  ulonglong uStack_18;
  
  uStack_18 = _DAT_1417011c0 ^ (ulonglong)auStack_178;
  FUN_14057a3f0(*(undefined4 *)(param_2 + 0x34),auStack_58,0x10);
  FUN_14057a3a0(*(undefined2 *)(param_2 + 0x3e),auStack_38,0x10);
  FUN_14057a3a0(*(undefined2 *)(param_2 + 0x3c),auStack_28,0x10);
  FUN_14057a3f0(*(undefined4 *)(param_2 + 0x38),auStack_48,0x10);
  lStack_108 = param_1 + 0x78;
  puStack_138 = auStack_98;
  puStack_140 = auStack_58;
  FUN_1400d2110(puStack_138,puStack_140);
  puStack_128 = auStack_78;
  puStack_130 = auStack_48;
  FUN_1400d2110(puStack_128,puStack_130);
  puStack_120 = auStack_98;
  puStack_118 = puStack_120;
  puStack_110 = puStack_120;
  FUN_14057b680(lStack_108,&lStack_148,puStack_120);
  FUN_1400d6510(auStack_78);
  FUN_1400d6510(auStack_98);
  plStack_100 = (longlong *)(param_1 + 0x78);
  lStack_e0 = *plStack_100;
  plStack_d0 = &lStack_d8;
  uStack_158 = lStack_148 == lStack_e0;
  uStack_154 = (uint)(byte)uStack_158;
  uStack_157 = !(bool)uStack_158;
  uStack_150 = (uint)(byte)uStack_157;
  if ((bool)uStack_157) {
    lStack_c8 = lStack_148 + 0x20;
    lStack_c0 = lStack_c8;
    lStack_b8 = lStack_c8;
    lStack_b0 = lStack_c8;
    lStack_a8 = lStack_c8;
  }
  plStack_f8 = plStack_100;
  plStack_f0 = plStack_100;
  plStack_e8 = plStack_100;
  lStack_d8 = lStack_e0;
  FUN_14107c400(uStack_18 ^ (ulonglong)auStack_178);
  return;
}


// 14057a0e0 MOV qword ptr [RSP + 0x10],RDX
