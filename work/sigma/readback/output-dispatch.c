Program sigma-decoded.bin language=ARM:LE:32:Cortex

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



// FUNCTION FUN_0802c15c @ 0802c15c

bool FUN_0802c15c(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_20001334 != DAT_20001335;
  if (bVar1) {
    FUN_080204b4(param_1,&DAT_20000f24 + (uint)DAT_20001334 * 0x41,0x41);
    DAT_20001334 = DAT_20001334 + 1 & 0xf;
  }
  return bVar1;
}



// FUNCTION FUN_0802c1b8 @ 0802c1b8

void FUN_0802c1b8(undefined4 *param_1,undefined2 param_2)

{
  undefined1 uStack_7;
  
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 5;
  *(undefined1 *)((int)param_1 + 2) = 1;
  *(char *)((int)param_1 + 3) = (char)param_2;
  uStack_7 = (undefined1)((ushort)param_2 >> 8);
  *(undefined1 *)(param_1 + 1) = uStack_7;
  return;
}



// FUNCTION FUN_0802c1fc @ 0802c1fc

void FUN_0802c1fc(undefined4 param_1,undefined1 param_2)

{
  FUN_0802a760(param_1,param_2);
  return;
}



// FUNCTION FUN_0802c214 @ 0802c214

void FUN_0802c214(undefined4 *param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 10;
  *(undefined1 *)((int)param_1 + 2) = param_2;
  *(undefined1 *)((int)param_1 + 3) = 3;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// FUNCTION FUN_0802c250 @ 0802c250

void FUN_0802c250(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 0xb;
  *(undefined1 *)((int)param_1 + 2) = 4;
  return;
}



// FUNCTION FUN_0802c27c @ 0802c27c

void FUN_0802c27c(undefined4 param_1)

{
  byte bVar1;
  
  bVar1 = DAT_20001335 + 1 & 0xf;
  if (bVar1 != DAT_20001334) {
    FUN_080204b4(&DAT_20000f24 + (uint)DAT_20001335 * 0x41,param_1,0x41);
    DAT_20001335 = bVar1;
  }
  return;
}



// FUNCTION FUN_0802c2dc @ 0802c2dc

void FUN_0802c2dc(void)

{
  FUN_08045aa8(&DAT_20000f24,0x410);
  DAT_20001334 = 0;
  DAT_20001335 = 0;
  return;
}



// FUNCTION FUN_0802c2fc @ 0802c2fc

void FUN_0802c2fc(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 0xb;
  *(undefined1 *)((int)param_1 + 2) = 3;
  return;
}



// FUNCTION FUN_0802c328 @ 0802c328

void FUN_0802c328(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 0x40;
  *(undefined1 *)((int)param_1 + 2) = 0xff;
  return;
}



// FUNCTION FUN_0802c35c @ 0802c35c

void FUN_0802c35c(undefined4 *param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 10;
  *(undefined1 *)((int)param_1 + 2) = param_2;
  *(undefined1 *)((int)param_1 + 3) = 1;
  *(undefined1 *)(param_1 + 1) = 0xff;
  return;
}



// FUNCTION FUN_0802c3a0 @ 0802c3a0

void FUN_0802c3a0(undefined4 *param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 1;
  *(undefined1 *)((int)param_1 + 2) = param_2;
  *(undefined1 *)((int)param_1 + 3) = 1;
  *(undefined1 *)(param_1 + 1) = 0xff;
  *(undefined1 *)((int)param_1 + 5) = 0xff;
  *(undefined1 *)((int)param_1 + 6) = 0xff;
  *(undefined1 *)((int)param_1 + 7) = 0xff;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0xff;
  *(undefined1 *)((int)param_1 + 0xb) = 0xff;
  *(undefined1 *)(param_1 + 3) = 4;
  *(undefined1 *)((int)param_1 + 0xd) = 0x3f;
  *(undefined1 *)((int)param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0xf) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}



// FUNCTION FUN_0802c444 @ 0802c444

void FUN_0802c444(undefined4 *param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 3;
  *(undefined1 *)((int)param_1 + 2) = param_2;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0xf) = 0;
  return;
}



// FUNCTION FUN_0802c4f0 @ 0802c4f0

int FUN_0802c4f0(short param_1)

{
  undefined4 local_c;
  
  if (param_1 == 0) {
    DAT_2000134c = 1;
    local_c = 0;
  }
  else {
    FUN_0802d5a8();
    local_c = DAT_20001358 + 10;
  }
  return local_c;
}



// FUNCTION FUN_0802c52c @ 0802c52c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0802c52c(void)

{
  undefined1 local_9;
  
  if (((DAT_20000021 < DAT_2000133e._1_1_) || ((char)DAT_2000133e != '\0')) || (_DAT_20001340 != 0))
  {
    local_9 = 2;
  }
  else {
    DAT_20001346 = DAT_2000133e._1_1_;
    FUN_0802b3a8();
    local_9 = 0;
  }
  return local_9;
}



// FUNCTION FUN_0802c590 @ 0802c590

int FUN_0802c590(short param_1)

{
  undefined4 local_c;
  
  if (param_1 == 0) {
    DAT_2000134c = 1;
    local_c = 0;
  }
  else {
    FUN_0802d5a8();
    local_c = DAT_20001358 + 0xc;
  }
  return local_c;
}



// FUNCTION FUN_0802c5cc @ 0802c5cc

/* WARNING: Removing unreachable block (ram,0x0802c63a) */

undefined1 FUN_0802c5cc(void)

{
  char cVar1;
  undefined1 local_9;
  
  cVar1 = FUN_0802b17c(DAT_20001341,DAT_2000133e._1_1_);
  if (DAT_20001346 == '\0') {
    local_9 = 2;
  }
  else if (((cVar1 == '\0') && (DAT_20001340 == '\0')) && ((char)DAT_2000133e == '\0')) {
    FUN_0802d5a8();
    DAT_20001347 = DAT_20001341;
    DAT_20001348 = DAT_2000133e._1_1_;
    local_9 = 0;
  }
  else {
    local_9 = 2;
  }
  return local_9;
}


