
// FUNCTION FUN_080215b0 @ 080215b0
// XREF 08021586

undefined4 FUN_080215b0(undefined4 param_1)

{
  return param_1;
}



// FUNCTION FUN_080215bc @ 080215bc
// XREF 0802158c

undefined4 * FUN_080215bc(undefined4 *param_1)

{
  FUN_08021624(param_1);
  *param_1 = &PTR_FUN_080216c4_1_08046618;
  *(undefined1 *)((int)param_1 + 7) = 0;
  FUN_0802163c(param_1,0);
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[2] = param_1 + 1;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 8;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xfe;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xfd;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 3 | 0x3c;
  FUN_08021688(param_1);
  return param_1;
}



// FUNCTION FUN_08021614 @ 08021614
// XREF 080215a4
// XREF 080226e6

void FUN_08021614(int param_1)

{
  *(undefined1 *)(param_1 + 0xb8) = 0;
  return;
}



// FUNCTION FUN_08023494 @ 08023494
// XREF 08046644
// XREF 08046670
// XREF 0804669c
// XREF 08046708
// XREF 08046754
// XREF 080467fc
// XREF 080469f8
// XREF 08046a50
// XREF 08046aa8

undefined4 FUN_08023494(void)

{
  return 0;
}



// FUNCTION FUN_08023620 @ 08023620
// XREF 08046660
// XREF 0804668c
// XREF 080466b8
// XREF 08046724
// XREF 08046770
// XREF 08046818
// XREF 08046a14
// XREF 08046a6c
// XREF 08046ac4

undefined4 FUN_08023620(void)

{
  return 1;
}



// FUNCTION FUN_08023af0 @ 08023af0
// XREF 08023acc
// XREF 0802485e

void FUN_08023af0(int param_1,undefined4 param_2)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xf < local_d) {
      return;
    }
    if (*(int *)(param_1 + (uint)local_d * 4 + 0x78) == 0) break;
    local_d = local_d + 1;
  }
  *(undefined4 *)(param_1 + (uint)local_d * 4 + 0x78) = param_2;
  return;
}



// FUNCTION FUN_08023b84 @ 08023b84
// XREF 08046680
// XREF 080466ac
// XREF 08046718
// XREF 08046764
// XREF 0804680c
// XREF 08046a08
// XREF 08046a60
// XREF 08046ab8

void FUN_08023b84(void)

{
  return;
}



// FUNCTION FUN_08023b90 @ 08023b90
// XREF 08046688
// XREF 080466b4
// XREF 08046720
// XREF 0804676c
// XREF 08046814
// XREF 08046a10
// XREF 08046a68
// XREF 08046ac0

undefined4 FUN_08023b90(void)

{
  return 0;
}



// FUNCTION FUN_0802406c @ 0802406c
// XREF 080466a8
// XREF 08046760
// XREF 08046808
// XREF 08046a04
// XREF 08046a5c
// XREF 08046ab4

undefined1 FUN_0802406c(int param_1)

{
  return *(undefined1 *)(param_1 + 0xc);
}



// FUNCTION FUN_08024078 @ 08024078
// XREF 080466bc
// XREF 08046774
// XREF 0804681c
// XREF 08046a18
// XREF 08046a70
// XREF 08046ac8

undefined4 FUN_08024078(int param_1,char param_2)

{
  byte local_a;
  undefined4 local_4;
  
  if ((*(byte *)(param_1 + 0x6f) & 1) == 0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      local_4 = 0;
    }
    else {
      local_4 = *(undefined4 *)(param_1 + 0x14);
    }
  }
  else {
    for (local_a = 0; local_a < 2; local_a = local_a + 1) {
      if (*(char *)(param_1 + (uint)local_a * 8 + 0x10) == param_2) {
        return *(undefined4 *)(param_1 + (uint)local_a * 8 + 0x14);
      }
    }
    local_4 = 0;
  }
  return local_4;
}



// FUNCTION FUN_080240ec @ 080240ec
// XREF 080466c0
// XREF 08046778
// XREF 08046820
// XREF 08046a1c
// XREF 08046a74
// XREF 08046acc

undefined1 FUN_080240ec(int param_1,undefined1 param_2,undefined4 param_3)

{
  byte local_11;
  
  local_11 = 0;
  while( true ) {
    if (1 < local_11) {
      return 0;
    }
    if ((*(char *)(param_1 + (uint)local_11 * 8 + 0x10) == '\0') &&
       (*(int *)(param_1 + (uint)local_11 * 8 + 0x14) == 0)) break;
    local_11 = local_11 + 1;
  }
  *(undefined1 *)(param_1 + 0x10 + (uint)local_11 * 8) = param_2;
  *(undefined4 *)(param_1 + 0x10 + (uint)local_11 * 8 + 4) = param_3;
  return 1;
}



// FUNCTION FUN_080248a0 @ 080248a0
// XREF 08024850

void FUN_080248a0(int param_1)

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



// FUNCTION FUN_08024a8c @ 08024a8c
// XREF 0804675c
// XREF 08046804
// XREF 08046a00
// XREF 08046a58
// XREF 08046ab0

char FUN_08024a8c(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort local_5e;
  byte local_5b;
  byte local_5a;
  undefined1 local_59 [64];
  char local_19;
  int *local_18;
  char local_11;
  
  local_19 = '\0';
  if ((*(byte *)((int)param_1 + 0x39) & 1) == 0) {
    local_11 = '\0';
  }
  else {
    local_18 = param_1;
    iVar3 = FUN_0802503c();
    if (-1 < iVar3 - param_1[0xd]) {
      iVar3 = FUN_0802503c();
      param_1[0xd] = iVar3 + (uint)*(byte *)(param_1 + 0xe);
      for (local_5a = 0; local_5a < *(byte *)(param_1 + 0xc); local_5a = local_5a + 1) {
        local_5b = *(byte *)((int)param_1 + (uint)local_5a * 4 + 0x5d);
        local_5e = (ushort)*(byte *)((int)param_1 + (uint)local_5b * 3 + 0x3b);
        FUN_08024430(param_1,local_59);
        cVar1 = FUN_08022490(param_1[2],(char)param_1[3],
                             *(undefined1 *)((int)param_1 + (uint)local_5b * 3 + 0x3a),&local_5e,
                             local_59);
        if (cVar1 != '\0') {
          if (cVar1 == '\x04') {
            return '\x04';
          }
          FUN_08022524(cVar1,0x81);
          return cVar1;
        }
        if (0x40 < local_5e) {
          local_5e = 0x40;
        }
        (**(code **)(*param_1 + 0x40))
                  (param_1,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_5e,local_59)
        ;
        uVar2 = local_59[0];
        if ((*(byte *)((int)param_1 + 0x6f) & 1) == 0) {
          uVar2 = 0;
        }
        puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x24))(param_1,uVar2);
        if (puVar4 != (undefined4 *)0x0) {
          (**(code **)*puVar4)
                    (puVar4,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_5e,local_59
                    );
        }
      }
    }
    local_11 = local_19;
  }
  return local_11;
}



// FUNCTION FUN_08025150 @ 08025150
// XREF 0802514a

void FUN_08025150(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_20000bc4,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_08046aa4;
  puVar1[1] = &PTR_FUN_08024cb0_1_08046af0;
  return;
}



// FUNCTION FUN_080251b0 @ 080251b0
// XREF 08025142

void FUN_080251b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_20000b0c,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_080469f4;
  puVar1[1] = &DAT_08046a40;
  return;
}



// FUNCTION FUN_080251e8 @ 080251e8
// XREF 0802513a

void FUN_080251e8(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_20000a94,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_08046a4c;
  puVar1[1] = &DAT_08046a98;
  return;
}



// FUNCTION FUN_08025220 @ 08025220
// XREF 08025132

void FUN_08025220(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_200008f4,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_080467f8;
  puVar1[1] = &DAT_08046844;
  *(undefined1 *)((int)puVar1 + 0x157) = 1;
  return;
}


