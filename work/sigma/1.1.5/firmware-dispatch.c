Program sigma-decoded.bin language=ARM:LE:32:Cortex

// FUNCTION FUN_0802b930 @ 0802b930

/* WARNING: Removing unreachable block (ram,0x0802b96a) */
/* WARNING: Removing unreachable block (ram,0x0802b986) */
/* WARNING: Removing unreachable block (ram,0x0802b958) */

void FUN_0802b930(void)

{
  bool bVar1;
  char cVar2;
  
  FUN_08021344();
  FUN_080213e4(0x7d);
  bVar1 = false;
  while( true ) {
    if (bVar1) {
      FUN_08021364();
      return;
    }
    cVar2 = FUN_08021378(0x8018000);
    if (cVar2 != '\x06') break;
    bVar1 = true;
  }
  FUN_08021364();
  return;
}



// FUNCTION FUN_0802b9f4 @ 0802b9f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802b9f4(void)

{
  FUN_0802b9f8();
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802b9f8 @ 0802b9f8

void FUN_0802b9f8(void)

{
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802ba20 @ 0802ba20

void FUN_0802ba20(void)

{
  FUN_0802b930();
  return;
}



// FUNCTION FUN_0802ba28 @ 0802ba28

bool FUN_0802ba28(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if ((param_2 != 0x483) || (bVar1 = true, param_3 != 0x530)) {
    bVar1 = param_2 == 0x3670 && param_3 == 0xa04;
  }
  return bVar1;
}



// FUNCTION FUN_0802ba7c @ 0802ba7c

undefined4 FUN_0802ba7c(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x72) == 0x530)) ||
     ((*(short *)(param_1 + 0x72) == 0x3670 && (*(short *)(param_1 + 0x72) == 0xa04)))) {
    if (*(int *)(param_1 + 0x74) != 0) {
      (**(code **)(param_1 + 0x74))();
    }
    FUN_0802053e(param_1 + 0x78,0x40);
  }
  return 0;
}



// FUNCTION FUN_0802bad8 @ 0802bad8

void FUN_0802bad8(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x530)) ||
      ((*(short *)(param_1 + 0x72) == 0x3670 && (*(short *)(param_1 + 0x70) == 0xa04)))) &&
     (((2 < param_4 && (param_4 < 0x41)) && (param_5 != 0)))) {
    FUN_080204b4(param_1 + 0x78,param_5,param_4);
  }
  return;
}



// FUNCTION FUN_0802bb50 @ 0802bb50

bool FUN_0802bb50(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if ((param_2 != 0x483) || (bVar1 = true, param_3 != 0x525)) {
    bVar1 = param_2 == 0x483 && param_3 == 0x524;
  }
  return bVar1;
}



// FUNCTION FUN_0802bba4 @ 0802bba4

undefined4 FUN_0802bba4(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x525)) ||
     ((*(short *)(param_1 + 0x72) == 0x483 && (*(short *)(param_1 + 0x70) == 0x524)))) {
    if (*(int *)(param_1 + 0x74) != 0) {
      (**(code **)(param_1 + 0x74))();
    }
    FUN_08045aa8(&DAT_20000edc,0x40);
    DAT_20000f1c = 1;
  }
  else {
    DAT_20000f1c = 0;
  }
  return 0;
}



// FUNCTION FUN_0802bc20 @ 0802bc20

void FUN_0802bc20(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x525)) ||
      ((*(short *)(param_1 + 0x72) == 0x483 && (*(short *)(param_1 + 0x70) == 0x524)))) &&
     (((2 < param_4 && (param_4 < 0x41)) && (param_5 != 0)))) {
    FUN_080204b4(&DAT_20000edc,param_5,param_4);
    DAT_20000f1c = 1;
    DAT_20000f20 = FUN_0802503c();
  }
  else {
    DAT_20000f1c = 0;
    FUN_08045aa8(&DAT_20000edc,0x40);
  }
  return;
}



// FUNCTION FUN_0802bcd8 @ 0802bcd8

bool FUN_0802bcd8(undefined4 param_1,short param_2,short param_3)

{
  return param_2 == 0x483 && param_3 == 0x531;
}



// FUNCTION FUN_0802bd0c @ 0802bd0c

undefined4 FUN_0802bd0c(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x72) == 0x531)) &&
     (*(int *)(param_1 + 0x74) != 0)) {
    (**(code **)(param_1 + 0x74))();
  }
  return 0;
}



// FUNCTION FUN_0802bd44 @ 0802bd44

void FUN_0802bd44(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x531)) &&
      (2 < param_4)) && ((param_4 < 0x41 && (param_5 != 0)))) {
    FUN_080204b4(param_1 + 0x78,param_5,param_4);
  }
  return;
}



// FUNCTION FUN_0802bda4 @ 0802bda4

byte FUN_0802bda4(void)

{
  undefined1 local_5;
  
  if (DAT_20000c3e == '\0') {
    if (DAT_20000c3d < 0x41) {
      local_5 = DAT_20000c3d;
    }
    else {
      local_5 = 0x40;
    }
  }
  else if (DAT_20000c3e == '\x01') {
    local_5 = 0x80;
  }
  else {
    local_5 = 0;
  }
  return local_5;
}



// FUNCTION FUN_0802be04 @ 0802be04

undefined1 FUN_0802be04(char param_1)

{
  undefined1 local_1;
  
  if (param_1 == '\x06') {
    local_1 = 1;
  }
  else if (param_1 == '\a') {
    local_1 = 7;
  }
  else if (param_1 == '?') {
    local_1 = 0;
  }
  else if (param_1 == 'O') {
    local_1 = 3;
  }
  else if (param_1 == '[') {
    local_1 = 2;
  }
  else if (param_1 == 'f') {
    local_1 = 4;
  }
  else if (param_1 == 'm') {
    local_1 = 5;
  }
  else if (param_1 == 'o') {
    local_1 = 9;
  }
  else if (param_1 == '}') {
    local_1 = 6;
  }
  else if (param_1 == '\x7f') {
    local_1 = 8;
  }
  else {
    local_1 = 0;
  }
  return local_1;
}



// FUNCTION FUN_0802beac @ 0802beac

undefined1 FUN_0802beac(char param_1)

{
  undefined1 local_1;
  
  if (param_1 == '\0') {
    local_1 = 10;
  }
  else if (param_1 == -0x40) {
    local_1 = 6;
  }
  else if (param_1 == -0x20) {
    local_1 = 5;
  }
  else if (param_1 == -0x10) {
    local_1 = 4;
  }
  else if (param_1 == -8) {
    local_1 = 3;
  }
  else if (param_1 == -4) {
    local_1 = 2;
  }
  else if (param_1 == -2) {
    local_1 = 1;
  }
  else if (param_1 == -1) {
    local_1 = 0;
  }
  else {
    local_1 = 10;
  }
  return local_1;
}



// FUNCTION FUN_0802bf34 @ 0802bf34

void FUN_0802bf34(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  short local_a0;
  undefined1 auStack_9a [65];
  char local_59;
  char local_58;
  char local_57;
  ushort local_56;
  char local_54;
  undefined1 local_53;
  char local_52;
  uint local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = 0;
  iVar4 = FUN_0802c15c(&local_59);
  if (iVar4 != 0) {
    if (((local_59 == '0') && (local_58 == '\x01')) && (local_57 == '\b')) {
      local_18 = (uint)local_56;
      iVar4 = local_18 * 10000 + -0x13880000;
      local_14 = (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x11)) >> 0xf;
      local_a0 = (short)local_14;
      FUN_0802c1b8(auStack_9a,(int)local_a0);
      FUN_0802c1fc(auStack_9a,5);
      DAT_20001336 = '\0';
    }
    else if (((local_59 == '0') && (local_58 == '\x03')) && (local_57 == '\b')) {
      FUN_0802c1b8(auStack_9a,0);
      FUN_0802c1fc(auStack_9a,5);
      FUN_0802c214(auStack_9a,1);
      FUN_0802c1fc(auStack_9a,5);
    }
    else if (((local_59 == '0') && (local_58 == '\x13')) && (local_57 == '\v')) {
      FUN_0802c250(auStack_9a);
      FUN_0802c1fc(auStack_9a,3);
      FUN_0802a778();
      FUN_0802a7cc();
      DAT_20001336 = '\x01';
    }
    else if (((local_59 == '0') && (local_58 == -8)) && (local_57 == '\t')) {
      if ((char)local_56 == '\x01') {
        if ((local_52 == '\0') && (local_54 == '\0')) {
          FUN_0802be04(local_53);
          FUN_0802a79c();
        }
        else {
          cVar1 = FUN_0802be04(local_52);
          cVar2 = FUN_0802be04(local_53);
          cVar3 = FUN_0802be04(local_54);
          FUN_0802a788(cVar3 * 'd' + cVar1 + cVar2 * '\n');
        }
      }
      else if ((char)local_56 == '\b') {
        if (DAT_20001336 == '\x01') {
          iVar4 = FUN_0802beac(local_54);
          if (iVar4 != 0) {
            FUN_0802beac(local_54);
            FUN_0802a7b0();
          }
        }
        else {
          FUN_0802beac(local_54);
          FUN_0802a7b0();
        }
      }
      FUN_0802a7cc();
    }
  }
  return;
}


