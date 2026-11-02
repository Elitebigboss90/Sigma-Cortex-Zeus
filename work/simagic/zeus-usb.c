
// FUNCTION FUN_080247ac @ 080247ac
// XREF 080248e4
// XREF 08026628

void FUN_080247ac(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  undefined4 local_68 [4];
  undefined4 local_58;
  undefined2 local_54;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  byte local_4b;
  byte local_4a [8];
  undefined4 local_42 [11];
  
  local_58 = 0;
  FUN_08035d8c(&local_54,0,0x3c);
  if ((*(char *)(DAT_080248b4 + 0xf8) != '\0') &&
     ((*(int *)(DAT_080248b4 + 4) == 4 || (*(int *)(DAT_080248b4 + 4) == 9)))) {
    uVar1 = *(undefined2 *)(DAT_080248b8 + 10);
    uVar2 = *(undefined2 *)(DAT_080248b8 + 8);
    uVar3 = *(undefined2 *)(DAT_080248b8 + 0xc);
    iVar8 = *(int *)(DAT_080248b4 + 0xf4);
    pbVar14 = &local_4b;
    uVar9 = *(uint *)(DAT_080248b4 + 0x88);
    uVar12 = *(uint *)(DAT_080248b4 + 0x8c);
    FUN_08035d8c(local_68,0,0x10);
    FUN_080246e8(local_68);
    FUN_08035d8c(&local_4c,0);
    local_4e = (undefined1)uVar3;
    local_4d = (undefined1)((ushort)uVar3 >> 8);
    local_4b = 0;
    uVar10 = 0;
    local_54 = *(undefined2 *)(DAT_080248bc + 1);
    local_58 = *DAT_080248bc;
    local_52 = (undefined1)uVar1;
    local_51 = (undefined1)((ushort)uVar1 >> 8);
    local_50 = (undefined1)uVar2;
    local_4f = (undefined1)((ushort)uVar2 >> 8);
    do {
      uVar5 = 0x20 - uVar10;
      uVar13 = uVar10 - 0x20;
      uVar4 = uVar10 & 0xff;
      uVar10 = uVar10 + 8;
      pbVar14 = pbVar14 + 1;
      *pbVar14 = (byte)(uVar9 >> uVar4) | (byte)(uVar12 << (uVar5 & 0xff)) |
                 (byte)(uVar12 >> (uVar13 & 0xff));
    } while (uVar10 != 0x40);
    puVar11 = local_68;
    puVar15 = local_42;
    do {
      uVar6 = *puVar11;
      uVar7 = puVar11[1];
      puVar11 = puVar11 + 2;
      *puVar15 = uVar6;
      puVar15[1] = uVar7;
      puVar15 = puVar15 + 2;
    } while (puVar11 != &local_58);
    local_4c = iVar8 == 2;
    FUN_08026fe0(4,0,*DAT_080248c0,&local_58,0x40);
  }
  return;
}



// FUNCTION FUN_080248c4 @ 080248c4
// XREF 08025672
// XREF 08025fc6
// XREF 08024922

void FUN_080248c4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_c;
  
  local_c = 0;
  FUN_080246e8(&local_c);
  puVar1 = DAT_080248ec;
  iVar2 = FUN_08035c34(DAT_080248ec,&local_c);
  if (iVar2 != 0) {
    *puVar1 = local_c;
    FUN_080247ac();
  }
  return;
}



// FUNCTION FUN_080248f0 @ 080248f0
// XREF 08024dea
// XREF 08024e8c

void FUN_080248f0(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    FUN_08026e04(0);
    iVar1 = DAT_08024958;
    uVar4 = *(uint *)(param_1 + 0x60);
    if (3 < (int)uVar4) {
      uVar4 = 4;
    }
    for (uVar5 = 0; (uVar5 & 0xff) < (uVar4 & 0xff); uVar5 = uVar5 + 1) {
      iVar3 = uVar5 * 0x13c + *(int *)(param_1 + 100);
      if (*(int *)(iVar3 + 0x10) == 0) {
        bVar2 = *(byte *)(iVar1 + uVar5) | 0x80;
      }
      else {
        bVar2 = *(byte *)(iVar1 + uVar5) & 0x7f;
      }
      *(byte *)(iVar1 + uVar5) = bVar2;
      *(byte *)(iVar1 + uVar5) =
           (byte)*(undefined4 *)(iVar3 + 0x138) & 0xf | *(byte *)(iVar1 + uVar5) & 0xc0;
    }
    FUN_08026e38(0);
    FUN_08024708();
    FUN_080248c4();
    return;
  }
  return;
}



// FUNCTION FUN_08026634 @ 08026634

uint FUN_08026634(uint param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint extraout_r2;
  short sVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined1 uStack_174;
  byte local_173;
  
  iVar2 = DAT_0802672c;
  if (((param_2 == (short *)0x0) || (-1 < (int)(param_1 << 0x19))) || ((param_1 & 0x30) != 0x10)) {
    return param_1;
  }
  param_1 = param_1 & 0xf;
  if (param_1 == 8) {
    if (*(short *)(DAT_08026730 + 10) != *param_2) {
      return 8;
    }
    if (*(short *)(DAT_08026730 + 8) != param_2[1]) {
      return 8;
    }
    bVar3 = *(byte *)(param_2 + 2);
    FUN_08035d8c(&uStack_174,0,0x163);
    iVar2 = DAT_080246e4;
    if (bVar3 < 2) {
      if (*(byte *)(DAT_080246e4 + 0x161) == bVar3) {
        return 0;
      }
      local_173 = bVar3;
      iVar4 = FUN_08024670(&uStack_174);
      if (iVar4 == 0) {
        *(byte *)(iVar2 + 0x161) = bVar3;
        FUN_0802464c();
        return 0;
      }
    }
    return 0xffffffff;
  }
  if (1 < param_1 - 4) {
    return param_1;
  }
  if (*(char *)(DAT_0802672c + 0x161) != '\x01') {
    return param_1;
  }
  if (param_1 == 4) {
    param_1 = FUN_0802464c();
    uVar5 = 0;
    *(undefined1 *)(iVar2 + 0x160) = 1;
  }
  else {
    if (*(char *)(DAT_0802672c + 0x160) == '\0') {
      return param_1;
    }
    uVar5 = 0x29;
  }
  sVar6 = 0;
  pcVar8 = (char *)(iVar2 + uVar5 + 0x118);
  puVar7 = (undefined1 *)(iVar2 + uVar5 * 4);
  do {
    if (uVar5 < 0x46) {
      sVar1 = *(short *)(iVar2 + 0x15e);
      *puVar7 = (char)uVar5;
      bVar3 = FUN_08024578(param_2,sVar6);
      puVar7[1] = bVar3 & 0xf | bVar3 << 4;
      bVar3 = FUN_08024578(param_2,sVar6 + 1);
      puVar7[2] = bVar3 & 0xf | bVar3 << 4;
      uVar5 = FUN_08024578(param_2,sVar6 + 2);
      param_1 = uVar5 & 0xf | (uVar5 & 0xf) << 4;
      puVar7[3] = (char)param_1;
      uVar5 = extraout_r2;
      if (*pcVar8 == '\0') {
        *pcVar8 = '\x01';
        *(short *)(iVar2 + 0x15e) = sVar1 + 1;
      }
    }
    sVar6 = sVar6 + 3;
    uVar5 = uVar5 + 1 & 0xffff;
    pcVar8 = pcVar8 + 1;
    puVar7 = puVar7 + 4;
  } while (sVar6 != 0x7b);
  if (*(short *)(iVar2 + 0x15e) != 0x46) {
    return param_1;
  }
  FUN_08024754();
  uVar5 = FUN_0802464c();
  return uVar5;
}



// FUNCTION FUN_0802a458 @ 0802a458

void FUN_0802a458(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  
  FUN_080349b4();
  uVar1 = param_3 + param_1;
  puVar2 = (undefined2 *)(param_2 + -2);
  for (; param_1 != (uVar1 & 0xff); param_1 = param_1 + 1 & 0xff) {
    puVar2 = puVar2 + 1;
    FUN_08033b48(param_1,*puVar2);
  }
  *DAT_080349d0 = *DAT_080349d0 & 0xfffffeff;
  return;
}



// FUNCTION FUN_0802a486 @ 0802a486

void FUN_0802a486(uint param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  uVar2 = param_3 + param_1;
  puVar3 = (undefined2 *)(param_2 + -2);
  for (; param_1 != (uVar2 & 0xff); param_1 = param_1 + 1 & 0xff) {
    uVar1 = FUN_08033b74(param_1);
    puVar3 = puVar3 + 1;
    *puVar3 = uVar1;
  }
  return;
}



// FUNCTION FUN_0802a4bc @ 0802a4bc

void FUN_0802a4bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar1 = PTR_DAT_0802a510;
  FUN_08033bf4(3,PTR_DAT_0802a510);
  if (param_1 == 0) {
    *(undefined4 *)puVar1 = param_2;
    puVar1[8] = 0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = param_2;
    puVar1[8] = 4;
  }
  puVar2 = PTR_DAT_0802a514;
  puVar1[9] = 0;
  puVar1[10] = (char)param_4;
  FUN_0802238c(puVar2,param_3,param_4);
  uVar3 = DAT_0802a518;
  puVar2 = PTR_DAT_0802a510;
  puVar1[0x4b] = 1;
  *(undefined2 *)(puVar1 + 0x4c) = 0;
  uVar3 = FUN_08033f54(uVar3,puVar2);
  FUN_08034068(DAT_0802a518,uVar3);
  return;
}



// FUNCTION FUN_0802a684 @ 0802a684
// XREF 0802217c

void FUN_0802a684(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar2 = DAT_0802a6c8;
  FUN_0802f00c();
  FUN_080340c0(DAT_0802a6cc,0,puVar2);
  if (*(char *)(puVar2 + 2) == '\0') {
    pcVar4 = *(code **)(DAT_0802a6d0 + 0xc);
    if (pcVar4 == (code *)0x0) goto LAB_0802a6aa;
    uVar1 = *(undefined1 *)((int)puVar2 + 10);
    uVar3 = *puVar2;
  }
  else {
    if ((*(char *)(puVar2 + 2) != '\x04') ||
       (pcVar4 = *(code **)(DAT_0802a6d0 + 0xc), pcVar4 == (code *)0x0)) goto LAB_0802a6aa;
    uVar1 = *(undefined1 *)((int)puVar2 + 10);
    uVar3 = puVar2[1];
  }
  (*pcVar4)(uVar3,(int)puVar2 + 0xb,uVar1);
LAB_0802a6aa:
  FUN_080221e0();
  *DAT_0802f040 = *DAT_0802f040 + -1;
  FUN_080221e8();
  return;
}



// FUNCTION FUN_0802a784 @ 0802a784

undefined4 FUN_0802a784(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = DAT_0802a7c4;
  uVar1 = DAT_0802a7c0;
  FUN_08035d8c(DAT_0802a7c0,0,0x44);
  FUN_08032494(param_1,iVar2 + 0x1b);
  FUN_08032494(param_1,iVar2 + 0x22);
  FUN_08032526(param_1,1,uVar1,0x40);
  *(undefined4 *)(param_1 + 0x438) = uVar1;
  return 0;
}



// FUNCTION FUN_0802a938 @ 0802a938
// XREF 0802a9ee
// XREF 0802aa1e
// XREF 0802abfc
// XREF 0802ac68
// XREF 0802ac98
// XREF 0802aa76

void FUN_0802a938(int param_1,int param_2)

{
  int *piVar1;
  undefined4 local_20;
  undefined2 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  undefined1 local_12;
  
  piVar1 = DAT_0802a9a4;
  *DAT_0802a9a4 = param_1;
  FUN_08034d6e(DAT_0802a9a8);
  FUN_08034d8a(DAT_0802a9a8,1);
  local_18 = 6999;
  if (param_2 == 2) {
    local_18 = 6;
  }
  local_20 = 5;
  local_1c = 0;
  local_14 = 0;
  local_12 = 0;
  FUN_08034cdc(DAT_0802a9a8,&local_20);
  FUN_08034da6(DAT_0802a9a8,1);
  FUN_08034d78(DAT_0802a9a8);
  FUN_08034d82(DAT_0802a9a8,1);
  FUN_08034d64(DAT_0802a9a8);
  do {
  } while (*piVar1 != 0);
  FUN_08034d6e(DAT_0802a9a8);
  return;
}


