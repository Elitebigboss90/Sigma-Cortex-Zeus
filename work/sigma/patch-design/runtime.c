
// FUNCTION FUN_080202ac @ 080202ac
// XREF 08020462

undefined8 FUN_080202ac(void)

{
  return CONCAT44(DAT_080202c4,DAT_080202c0);
}



// FUNCTION FUN_0802044a @ 0802044a
// XREF 0802026c

void FUN_0802044a(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_lr;
  uint *puVar3;
  
  uVar1 = FUN_0802058c();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = unaff_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_080202ac();
  puVar2 = (undefined4 *)*puVar3;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  return;
}



// FUNCTION FUN_08020666 @ 08020666
// XREF 0802069e
// XREF 0802075c

uint FUN_08020666(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 3U & 0xfffffffc;
  uVar1 = *param_1;
  if (param_1[1] - uVar1 < uVar2) {
    return 0;
  }
  *param_1 = uVar2 + uVar1 + 7 & 0xfffffff8;
  return uVar1;
}



// FUNCTION FUN_08022598 @ 08022598
// XREF 08025318

void FUN_08022598(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  byte local_15;
  byte local_14;
  undefined1 local_13;
  
  local_13 = 0;
  FUN_0802286c(&DAT_20000820);
  uVar1 = FUN_0802289c(&DAT_20000820);
  switch(uVar1) {
  case 0:
    if ((DAT_20000811 & 0xf0) != 0x10) {
      DAT_20000811 = 0x11;
    }
    local_13 = 0;
    break;
  case 1:
    DAT_20000811 = 0x13;
    local_13 = 0;
    break;
  case 3:
    local_13 = 1;
  case 2:
    if ((DAT_20000811 & 0xf0) == 0x10) {
      iVar5 = FUN_0802503c();
      DAT_20000814 = iVar5 + 200;
      DAT_20000811 = 0x20;
    }
  }
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    if (*(int *)(&DAT_20000898 + (uint)local_14 * 4) != 0) {
      (**(code **)(**(int **)(&DAT_20000898 + (uint)local_14 * 4) + 0xc))();
    }
  }
  if (DAT_20000811 == 0x11) {
    FUN_08021614(&DAT_20000820);
    for (local_15 = 0; local_15 < 0x10; local_15 = local_15 + 1) {
      if (*(int *)(&DAT_20000898 + (uint)local_15 * 4) != 0) {
        (**(code **)(**(int **)(&DAT_20000898 + (uint)local_15 * 4) + 8))();
      }
    }
    DAT_20000811 = 0x12;
  }
  else if ((DAT_20000811 != 0x12) && (DAT_20000811 != 0x13)) {
    if (DAT_20000811 == 0x20) {
      iVar5 = FUN_0802503c();
      if (iVar5 - DAT_20000814 < 0) {
        return;
      }
      DAT_20000811 = 0x30;
    }
    else if (DAT_20000811 != 0x30) {
      if (DAT_20000811 == 0x40) {
        uVar4 = FUN_08021c20(&DAT_20000820,0xe8);
        if ((uVar4 & 1) != 0) {
          return;
        }
        bVar2 = FUN_08021c20(&DAT_20000820,0xd8);
        FUN_08021be8(&DAT_20000820,0xd8,bVar2 | 8);
        DAT_20000811 = 0x50;
        return;
      }
      if (DAT_20000811 == 0x50) {
        iVar5 = FUN_08021c20(&DAT_20000820,200);
        if (-1 < iVar5 * 0x2000000) {
          return;
        }
        DAT_20000811 = 0x51;
        iVar5 = FUN_0802503c();
        DAT_20000814 = iVar5 + 0x14;
        return;
      }
      if (DAT_20000811 == 0x51) {
        iVar5 = FUN_0802503c();
        if (iVar5 - DAT_20000814 < 0) {
          return;
        }
        DAT_20000811 = 0x80;
      }
      else if (DAT_20000811 != 0x80) {
        return;
      }
      cVar3 = FUN_080228b0(&DAT_20000820,0,0,local_13);
      if (cVar3 != '\0') {
        if (cVar3 == -0x2e) {
          return;
        }
        DAT_20000811 = 0xa0;
        return;
      }
      DAT_20000811 = 0x90;
      return;
    }
    FUN_08021be8(&DAT_20000820,0xe8,1);
    DAT_20000811 = 0x40;
  }
  return;
}



// FUNCTION FUN_08022bb8 @ 08022bb8
// XREF 08022a24
// XREF 08022afc

char FUN_08022bb8(int param_1,byte param_2,byte param_3,undefined1 param_4,byte param_5)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte local_1d;
  
  local_1d = 0;
  do {
    piVar2 = *(int **)(param_1 + (uint)param_2 * 4 + 0x78);
    cVar1 = (**(code **)(*piVar2 + 4))(piVar2,param_3,param_4,param_5 & 1);
    if (cVar1 == -0x20) {
      if (param_3 == 0) {
        FUN_08021be8(param_1,0xe8,1);
        FUN_08025048(0x66);
      }
      else {
        piVar2 = *(int **)(param_1 + (uint)param_3 * 4 + 0x78);
        (**(code **)(*piVar2 + 0x14))(piVar2,param_4);
      }
LAB_08022c78:
      puVar3 = *(undefined4 **)(param_1 + (uint)param_2 * 4 + 0x78);
      cVar1 = (**(code **)*puVar3)(puVar3,param_3,param_4,param_5 & 1);
      if ((cVar1 != '\r') || (2 < local_1d)) {
        if (cVar1 != '\0') {
          if (param_3 == 0) {
            FUN_08021be8(param_1,0xe8,1);
            FUN_08025048(0x66);
          }
          else {
            piVar2 = *(int **)(param_1 + (uint)param_3 * 4 + 0x78);
            (**(code **)(*piVar2 + 0x14))(piVar2,param_4);
          }
        }
        return cVar1;
      }
      FUN_08025048(100);
    }
    else {
      if ((cVar1 != '\r') || (2 < local_1d)) {
        if (cVar1 != '\0') {
          return cVar1;
        }
        goto LAB_08022c78;
      }
      FUN_08025048(100);
    }
    local_1d = local_1d + 1;
  } while( true );
}



// FUNCTION FUN_08022d10 @ 08022d10
// XREF 08022b42

char FUN_08022d10(undefined4 param_1,undefined1 param_2,undefined1 param_3,byte param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_9;
  
  piVar2 = (int *)FUN_080216c4(param_1,0);
  if (piVar2 == (int *)0x0) {
    local_9 = -0x2a;
  }
  else if (*piVar2 == 0) {
    local_9 = -0x29;
  }
  else {
    *(byte *)((int)piVar2 + 6) = param_4 & 1;
    cVar1 = FUN_08021714(param_1,param_2,0,param_3);
    if (cVar1 == '\0') {
      local_9 = -0x2c;
    }
    else {
      iVar3 = FUN_080216c4(param_1,cVar1);
      if (iVar3 == 0) {
        local_9 = -0x2a;
      }
      else {
        *(byte *)(iVar3 + 6) = param_4 & 1;
        local_9 = FUN_08022de8(param_1,cVar1);
        if (local_9 == '\0') {
          local_9 = '\0';
        }
        else {
          FUN_08021870(param_1,cVar1);
        }
      }
    }
  }
  return local_9;
}



// FUNCTION FUN_08024334 @ 08024334
// XREF 080466e0

void FUN_08024334(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined4 param_6)

{
  FUN_080241a8(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// FUNCTION FUN_08024430 @ 08024430
// XREF 08023f7e
// XREF 08024b0a

void FUN_08024430(undefined4 param_1,int param_2)

{
  undefined1 local_d;
  
  for (local_d = 0; local_d < 0x40; local_d = local_d + 1) {
    *(undefined1 *)(param_2 + (uint)local_d) = 0;
  }
  return;
}



// FUNCTION FUN_08024470 @ 08024470
// XREF 08023d88

undefined4 * FUN_08024470(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  FUN_080244e0(param_1);
  *param_1 = &DAT_080466ec;
  param_1[1] = param_2;
  puVar1 = param_1 + 2;
  FUN_080244f8(puVar1);
  FUN_0802450c(param_1 + 4);
  FUN_08024520(param_1 + 6);
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 0;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined4 **)((int)param_1 + 9) = param_1 + 8;
  FUN_08024534(param_1 + 4,puVar1);
  FUN_08024550(param_1 + 6,puVar1);
  return param_1;
}



// FUNCTION FUN_08024a34 @ 08024a34
// XREF 0802487e

void FUN_08024a34(undefined4 *param_1)

{
  *param_1 = &DAT_08046744;
  return;
}



// FUNCTION FUN_0802a608 @ 0802a608
// XREF 0802531c

void FUN_0802a608(void)

{
  uint uVar1;
  
  FUN_0802bf34();
  if (DAT_20004538 == '\x01') {
    uVar1 = FUN_080250d8(DAT_20000a3c);
    if (4999 < uVar1) {
      FUN_0802a528(&DAT_200008f4);
      DAT_20000a3c = FUN_0802503c();
    }
  }
  else {
    DAT_20000a3c = FUN_0802503c();
  }
  if (DAT_2000453a == '\x01') {
    uVar1 = FUN_080250d8(DAT_20000a44);
    if (4999 < uVar1) {
      FUN_0802a57c(&DAT_200008f4);
      DAT_20000a44 = FUN_0802503c();
    }
  }
  else {
    DAT_20000a44 = FUN_0802503c();
  }
  if ((DAT_200009f7 & 1) != 0) {
    DAT_200009f7 = 0;
    FUN_0802b8b4();
    FUN_080444e8(DAT_200009f6);
  }
  return;
}



// FUNCTION FUN_0802a7dc @ 0802a7dc
// XREF 08025388

void FUN_0802a7dc(void)

{
  FUN_0802def0();
  FUN_0802db7c(4);
  return;
}



// FUNCTION FUN_0802a7ec @ 0802a7ec
// XREF 08025380

bool FUN_0802a7ec(void)

{
  int iVar1;
  
  iVar1 = FUN_080202d2(&DAT_20000c88,&DAT_20000cc8,0x40);
  return iVar1 != 0;
}


