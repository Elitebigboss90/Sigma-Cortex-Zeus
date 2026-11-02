Program sigma-decoded.bin language=ARM:LE:32:Cortex

// FUNCTION FUN_08044004 @ 08044004

undefined1 FUN_08044004(int param_1,undefined4 param_2,char param_3)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_36;
  int local_34;
  char local_2d;
  undefined4 local_2c;
  int local_28;
  undefined1 local_21;
  
  local_2d = param_3;
  local_2c = param_2;
  local_28 = param_1;
  local_34 = FUN_080326d4(param_1);
  if (local_2d == '\0') {
    if (*(char *)(local_34 + 1) == '\x02') {
      sVar1 = **(short **)(local_34 + 0x10);
      if ((sVar1 < 1) || (0xd < sVar1)) {
        FUN_080326f0(local_28);
        (*DAT_20003dcc)(local_28,local_2c,local_2d);
        uVar2 = local_2c;
        local_38 = 4;
        local_36 = 4;
        iVar5 = local_28 + 0x10;
        uVar3 = FUN_080314e8();
        uVar4 = *(undefined4 *)(local_34 + 4);
        FUN_0803100c(local_28);
        FUN_080352c0(iVar5,uVar2,&DAT_20003c70,uVar3,uVar4,0,&local_38,0,0);
        uVar2 = local_2c;
        local_3c = 4;
        local_3a = 0x13;
        iVar5 = local_28 + 0x10;
        uVar3 = FUN_080314e8();
        uVar4 = *(undefined4 *)(local_34 + 0x1c);
        FUN_0803100c(local_28);
        FUN_080352c0(iVar5,uVar2,&DAT_20003cac,uVar3,uVar4,0,&local_3c,0,0);
        iVar5 = FUN_080326f0(local_28);
        uVar2 = local_2c;
        if (iVar5 != 0) {
          local_3c = 0x70;
          local_3a = 0x13;
          iVar5 = local_28 + 0x10;
          uVar3 = FUN_080314e8();
          FUN_0803100c(local_28);
          FUN_080352c0(iVar5,uVar2,&DAT_20003cac,uVar3,&DAT_0804dfe6,0,&local_3c,0,0);
        }
      }
      else {
        FUN_080326f0(local_28);
        (*DAT_20003dcc)(local_28,local_2c,local_2d);
        uVar2 = local_2c;
        local_38 = 4;
        local_36 = 4;
        iVar5 = local_28 + 0x10;
        uVar3 = FUN_080314e8();
        uVar4 = *(undefined4 *)(local_34 + 4);
        FUN_0803100c(local_28);
        FUN_080352c0(iVar5,uVar2,&DAT_20003c70,uVar3,uVar4,0,&local_38,0,0);
        uVar2 = local_2c;
        local_3c = 4;
        local_3a = 0x13;
        iVar5 = local_28 + 0x10;
        uVar3 = FUN_080314e8();
        FUN_0803100c(local_28);
        FUN_080352c0(iVar5,uVar2,&DAT_20003cac,uVar3,&DAT_20000624 + sVar1 * 0x14,0,&local_3c,0,0);
      }
    }
    else {
      FUN_080326f0(local_28);
      (*DAT_20003dcc)(local_28,local_2c,local_2d);
      uVar2 = local_2c;
      local_38 = 4;
      local_36 = 4;
      iVar5 = local_28 + 0x10;
      uVar3 = FUN_080314e8();
      uVar4 = *(undefined4 *)(local_34 + 4);
      FUN_0803100c(local_28);
      FUN_080352c0(iVar5,uVar2,&DAT_20003c70,uVar3,uVar4,0,&local_38,0,0);
      uVar2 = local_2c;
      local_3c = 4;
      local_3a = 0x13;
      iVar5 = local_28 + 0x10;
      uVar3 = FUN_080314e8();
      uVar4 = (**(code **)(local_34 + 8))();
      FUN_0803100c(local_28);
      FUN_080352c0(iVar5,uVar2,&DAT_20003cac,uVar3,uVar4,0,&local_3c,0,0);
      iVar5 = FUN_080326f0(local_28);
      uVar2 = local_2c;
      if (iVar5 != 0) {
        local_3c = 0x70;
        local_3a = 0x13;
        iVar5 = local_28 + 0x10;
        uVar3 = FUN_080314e8();
        FUN_0803100c(local_28);
        FUN_080352c0(iVar5,uVar2,&DAT_20003cac,uVar3,&DAT_0804dfe2,0,&local_3c,0,0);
      }
    }
    local_21 = 1;
  }
  else {
    local_21 = (*DAT_20003dcc)(local_28,local_2c,local_2d);
  }
  return local_21;
}



// FUNCTION FUN_08044324 @ 08044324

void FUN_08044324(char param_1)

{
  if (param_1 != DAT_2000073c) {
    DAT_2000073c = param_1;
    if (DAT_20003dd1 == '\a') {
      FUN_0803fa60(DAT_20003dc4,&DAT_0804dda7);
    }
    else if (DAT_20003dd1 == '\x03') {
      FUN_0803fa60(DAT_20003dc4,&DAT_0804dd47);
    }
    else if (DAT_20003dd1 == '\x05') {
      FUN_0803fa60(DAT_20003dc4,&DAT_0804ddc6);
    }
    else if (DAT_20003dd1 == '\x01') {
      FUN_0803fa60(DAT_20003dc4,&DAT_0804dd87);
    }
    else {
      FUN_0803fa60(DAT_20003dc4,&DAT_0804dd67);
    }
  }
  return;
}



// FUNCTION FUN_08044414 @ 08044414

void FUN_08044414(void)

{
  undefined1 *puVar1;
  
  if (DAT_20003dd0 != '\x01') {
    DAT_20003dd0 = '\x01';
    DAT_20003dc4 = 0;
    FUN_08042218(DAT_20003dc8);
    DAT_20003bb6 = FUN_08031070();
    FUN_0802ebf8(DAT_20003d28);
    puVar1 = (undefined1 *)FUN_080326d4();
    DAT_20003bb8 = *puVar1;
    FUN_0802ecc0(DAT_20003d28);
    FUN_0802ec98(DAT_20003d28,0);
    FUN_0802ea04(DAT_20003d28);
    FUN_08043cd8();
    FUN_08031980();
  }
  return;
}



// FUNCTION FUN_0804449c @ 0804449c

void FUN_0804449c(byte param_1)

{
  DAT_20003dd1 = param_1 | DAT_20003dd1;
  FUN_08044324(DAT_20003dd1);
  return;
}



// FUNCTION FUN_080444c0 @ 080444c0

void FUN_080444c0(byte param_1)

{
  DAT_20003dd1 = DAT_20003dd1 & ~param_1;
  FUN_08044324(DAT_20003dd1);
  return;
}



// FUNCTION FUN_080444e8 @ 080444e8

void FUN_080444e8(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 != DAT_20003d2c) {
    uVar1 = *(undefined4 *)((&PTR_DAT_080498c4)[param_1] + 0x34);
    FUN_0802ea64(uVar1);
    FUN_0804235c(DAT_20003dc8,uVar1,1);
    DAT_20003d2c = param_1;
  }
  FUN_08043cd8();
  FUN_08031174();
  return;
}



// FUNCTION FUN_08044550 @ 08044550

void FUN_08044550(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_080445b4();
  uVar2 = FUN_0803ebb4(uVar1);
  FUN_0803eff8(uVar2,&DAT_080498b8);
  uVar2 = FUN_0803f200(uVar1);
  FUN_0803fa60(uVar2,&DAT_0804de00);
  FUN_080310a8(uVar2,4,0x7d);
  uVar1 = FUN_0803f200(uVar1);
  FUN_0803fa60(uVar1,&DAT_0804ddf2);
  FUN_080310a8(uVar1,4,0x8c);
  return;
}



// FUNCTION FUN_080445b4 @ 080445b4

void FUN_080445b4(void)

{
  FUN_0803b578();
  FUN_0802df78();
  return;
}



// FUNCTION FUN_080445c0 @ 080445c0

void FUN_080445c0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_080445b4();
  FUN_08031980(uVar1);
  return;
}



// FUNCTION FUN_080445d4 @ 080445d4

bool FUN_080445d4(void)

{
  int iVar1;
  
  DAT_20003dd2 = 0xf;
  iVar1 = FUN_08045940(9,1);
  return iVar1 == 0xc;
}



// FUNCTION FUN_0804460c @ 0804460c

bool FUN_0804460c(void)

{
  int iVar1;
  undefined1 auStack_c [4];
  
  DAT_20003dd2 = 0x1f;
  iVar1 = FUN_08045970(9,auStack_c);
  return iVar1 == 0xc;
}



// FUNCTION FUN_08044644 @ 08044644

undefined4 FUN_08044644(void)

{
  int iVar1;
  undefined1 auStack_e [2];
  undefined4 local_c;
  
  DAT_20003dd2 = 0x2f;
  iVar1 = FUN_08045970(9,auStack_e);
  if (iVar1 == 0xc) {
    FUN_08025048(4);
    DAT_20003dd2 = 0xff;
    iVar1 = FUN_08045970(9,auStack_e);
    if (iVar1 == 0xc) {
      local_c = 1;
    }
    else {
      local_c = 0;
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}



// FUNCTION FUN_080446a0 @ 080446a0

undefined1 FUN_080446a0(void)

{
  int iVar1;
  short local_c;
  undefined1 local_9;
  
  DAT_20003dd2 = 7;
  iVar1 = FUN_08045970(9,&local_c);
  if (iVar1 == 0xc) {
    if (((local_c == 2) && (DAT_20003edc == '\x01')) && (DAT_20003edd == '\a')) {
      DAT_20003fe6 = 0;
      local_9 = 1;
    }
    else {
      DAT_20003fe6 = DAT_20003fe6 + 1;
      local_9 = 0;
    }
  }
  else {
    local_9 = 0;
  }
  return local_9;
}



// FUNCTION FUN_08044724 @ 08044724

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_08044724(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uStack_11;
  short local_a;
  
  if ((DAT_20000d1c & 1) != 0) {
    if (DAT_20000d1e == '\x01') {
      if (DAT_20000d1d == '\x03') {
        FUN_080204b4(&DAT_20000d20,&DAT_0804d8f6,0x30);
      }
      else if (DAT_20000d1d == -0xe) {
        FUN_08045aa8(&DAT_20000d20,0x40);
        uVar2 = _DAT_20000d20;
        _DAT_20000d20 = CONCAT11(DAT_20004542,0xf2);
        DAT_20000d23 = SUB41(uVar2,3);
        if (DAT_2000453c == '\a') {
          _DAT_20000d20 = (uint3)_DAT_20000d20;
          DAT_20004544 = 0;
        }
        else {
          _DAT_20000d20 = CONCAT12(0x10,_DAT_20000d20);
        }
        uVar1 = FUN_0804505c(0xc);
        DAT_20000d2c = (undefined1)uVar1;
        DAT_20000d2d = (undefined1)((uint)uVar1 >> 8);
        DAT_20000d2e = (undefined1)((uint)uVar1 >> 0x10);
        uStack_11 = (undefined1)((uint)uVar1 >> 0x18);
        DAT_20000d2f = uStack_11;
      }
      else if (DAT_20000d1d == -0xd) {
        _DAT_20000d24 = 0;
        _DAT_20000d20 = 0x383800f3;
      }
      else if (DAT_20000d1d == -0xf) {
        FUN_08045aa8(&DAT_20000d20,0x40);
        _DAT_20000d20 = CONCAT11(DAT_20004542,0xf1);
        _DAT_20000d20 = CONCAT12(DAT_20004544,_DAT_20000d20);
        _DAT_20000d20 = (uint)_DAT_20000d20;
        if (DAT_20004544 < 0x12) {
          FUN_080204b4(&DAT_20000d24,(uint)DAT_20004544 * 0x38 + 0x20003fe8,0x38);
        }
        else if (0x11 < DAT_20004544) {
          FUN_080204b4(&DAT_20000d24,(uint)DAT_20004544 * 0x38 + 0x20003fe8,0x20);
          DAT_20000d58 = 0;
          DAT_20000d54 = 0;
          DAT_20000d50 = 0;
          DAT_20000d4c = 0;
          DAT_20000d48 = 0;
          DAT_20000d44 = 0;
        }
        uVar1 = FUN_0804505c(0x3c);
        DAT_20000d5c = (undefined1)uVar1;
        DAT_20000d5d = (undefined1)((uint)uVar1 >> 8);
        DAT_20000d5e = (undefined1)((uint)uVar1 >> 0x10);
        uStack_11 = (undefined1)((uint)uVar1 >> 0x18);
        DAT_20000d5f = uStack_11;
        DAT_20004544 = DAT_20004544 + 1;
        if (0x12 < DAT_20004544) {
          DAT_20004544 = 0;
        }
      }
      FUN_0802b3d8();
    }
    else if (DAT_20000d1e == '\t') {
      if (DAT_20000d1d == -0x10) {
        DAT_20004542 = DAT_20000d21;
        if (DAT_20000d22 < 4) {
          FUN_080204b4((uint)DAT_20000d22 * 0x38 + 0x200043f8,&DAT_20000d24,0x38);
        }
        else if (DAT_20000d22 == 4) {
          FUN_080204b4(&DAT_200044d8,&DAT_20000d24,0x20);
          DAT_2000453c = '\x02';
          DAT_20004548 = 0;
        }
      }
      else if (DAT_20000d1d == -0xd) {
        DAT_2000453c = '\x01';
        DAT_20004550 = FUN_0802503c();
      }
    }
    DAT_20000d1c = 0;
  }
  switch(DAT_2000453c) {
  case '\0':
    DAT_20004540 = 0;
    break;
  case '\x01':
    uVar2 = FUN_080250d8(DAT_20004550);
    if (99 < uVar2) {
      DAT_20004550 = FUN_0802503c();
      iVar3 = FUN_080446a0();
      if (iVar3 == 0) {
        DAT_20004554 = DAT_20004554 + 1;
        if (10 < DAT_20004554) {
          DAT_20004554 = 0;
          FUN_080459b8();
        }
      }
      else {
        DAT_20004554 = 0;
        FUN_08025048(1);
        DAT_20003dd2 = DAT_20004540 << 4;
        DAT_20003dd3 = 5;
        DAT_20003dd4 = 0x80;
        DAT_20003dd5 = 0x48;
        DAT_20003dd6 = 0;
        DAT_20003dd7 = 0;
        DAT_20003dd8 = 0;
        DAT_20004540 = DAT_20004540 + 1;
        if (7 < DAT_20004540) {
          DAT_20004540 = 0;
        }
        iVar3 = FUN_08045940(0x5a,7);
        if (iVar3 == 0xc) {
          DAT_2000453c = '\x02';
          DAT_20004548 = 0;
        }
        DAT_20004550 = FUN_0802503c();
      }
    }
    break;
  case '\x02':
    uVar2 = FUN_080250d8(DAT_20004550);
    if (9 < uVar2) {
      DAT_20004550 = FUN_0802503c();
      iVar3 = FUN_080446a0();
      if (iVar3 == 0) {
        DAT_20004554 = DAT_20004554 + 1;
        if (10 < DAT_20004554) {
          DAT_20004554 = 0;
          FUN_080459b8();
        }
      }
      else {
        DAT_20004554 = 0;
        FUN_08025048(1);
        DAT_20003dd2 = -0x7e;
        iVar3 = FUN_08045970(0x5a,&local_a);
        if (iVar3 == 0xc) {
          DAT_2000453c = '\x03';
        }
        DAT_20004550 = FUN_0802503c();
      }
    }
    break;
  case '\x03':
    uVar2 = FUN_080250d8(DAT_20004550);
    if (9 < uVar2) {
      DAT_20004550 = FUN_0802503c();
      iVar3 = FUN_080446a0();
      if (iVar3 == 0) {
        DAT_20004554 = DAT_20004554 + 1;
        if (10 < DAT_20004554) {
          DAT_20004554 = 0;
          FUN_080459b8();
        }
      }
      else {
        DAT_20004554 = 0;
        FUN_08025048(1);
        DAT_20003dd2 = DAT_20004540 << 4;
        DAT_20003dd3 = 0x85;
        DAT_20003dd4 = 0x80;
        DAT_20003dd5 = 0x44;
        DAT_20003dd6 = 0x80;
        DAT_20003dd7 = DAT_20004548;
        DAT_20003dd8 = 0x80;
        FUN_080204b4(&DAT_20003dd9,(uint)DAT_20004548 * 0x80 + 0x200043f8,0x80);
        FUN_08045940(0x5a,0x87);
        if (DAT_20004548 == 0) {
          DAT_2000453c = '\x02';
        }
        else {
          DAT_2000453c = '\x04';
        }
        DAT_20004540 = DAT_20004540 + 1;
        if (7 < DAT_20004540) {
          DAT_20004540 = 0;
        }
        DAT_20004548 = DAT_20004548 + 1;
        DAT_20004550 = FUN_0802503c();
      }
    }
    break;
  case '\x04':
    uVar2 = FUN_080250d8(DAT_20004550);
    if (199 < uVar2) {
      DAT_20004550 = FUN_0802503c();
      iVar3 = FUN_080446a0();
      if (iVar3 == 0) {
        if (10 < DAT_20004554 + 1) {
          DAT_20004554 = 0;
          FUN_080459b8();
        }
      }
      else {
        DAT_20004554 = 0;
        FUN_08025048(1);
        DAT_20003dd2 = -0x7e;
        iVar3 = FUN_08045970(0x5a,&local_a);
        if ((((iVar3 == 0xc) && (local_a == 4)) && (DAT_20003edc == 3)) &&
           ((((int)((uint)DAT_20003edd * 0x40000000) < 0 && (DAT_20003ede == -0x70)) &&
            (DAT_20003edf == '\0')))) {
          DAT_2000453c = '\x05';
          DAT_2000454c = 0;
        }
        DAT_20004550 = FUN_0802503c();
      }
      DAT_20004554 = 0;
    }
    break;
  case '\x05':
    uVar2 = FUN_080250d8(DAT_20004550);
    if (9 < uVar2) {
      DAT_20004550 = FUN_0802503c();
      iVar3 = FUN_080446a0();
      if (iVar3 == 0) {
        DAT_20004554 = DAT_20004554 + 1;
        if (10 < DAT_20004554) {
          DAT_20004554 = 0;
          FUN_080459b8();
        }
      }
      else {
        DAT_20004554 = 0;
        FUN_08025048(1);
        DAT_20003dd2 = DAT_20004540 << 4;
        DAT_20003dd3 = 5;
        DAT_20003dd4 = 0x80;
        DAT_20003dd5 = 0x46;
        DAT_20003dd6 = 0x80;
        DAT_20003dd7 = DAT_2000454c;
        if (DAT_2000454c < 8) {
          DAT_20003dd8 = 0x80;
        }
        else {
          DAT_20003dd8 = 0x10;
        }
        FUN_08045940(0x5a,7);
        DAT_2000453c = '\x06';
        DAT_20004550 = FUN_0802503c();
        DAT_20004540 = DAT_20004540 + 1;
        if (7 < DAT_20004540) {
          DAT_20004540 = 0;
        }
      }
    }
    break;
  case '\x06':
    uVar2 = FUN_080250d8(DAT_20004550);
    if (9 < uVar2) {
      DAT_20004550 = FUN_0802503c();
      iVar3 = FUN_080446a0();
      if (iVar3 == 0) {
        DAT_20004554 = DAT_20004554 + 1;
        if (10 < DAT_20004554) {
          DAT_20004554 = 0;
          FUN_080459b8();
        }
      }
      else {
        DAT_20004554 = 0;
        FUN_08025048(1);
        DAT_20003dd2 = -0x7e;
        FUN_08045970(0x5a,&local_a);
        DAT_20004550 = FUN_0802503c();
        if (local_a == (ushort)(DAT_20003edc + 1)) {
          FUN_080204b4((uint)DAT_2000454c * 0x80 + 0x20003fe8,&DAT_20003ede,DAT_20003edc - 2);
        }
        if (DAT_2000454c < 8) {
          DAT_2000453c = '\x05';
        }
        else {
          DAT_2000453c = '\a';
        }
        DAT_2000454c = DAT_2000454c + 1;
      }
    }
    break;
  case '\a':
    break;
  default:
    DAT_2000453c = '\0';
  }
  return;
}



// FUNCTION FUN_0804505c @ 0804505c

uint FUN_0804505c(ushort param_1)

{
  uint local_10;
  int local_c;
  
  local_10 = 0xffffffff;
  for (local_c = 0; local_c < (int)(uint)param_1; local_c = local_c + 1) {
    local_10 = *(uint *)(&DAT_0804d928 + (((byte)(&DAT_20000d20)[local_c] ^ local_10) & 0xff) * 4) ^
               local_10 >> 8;
  }
  return ~local_10;
}



// FUNCTION FUN_080450b8 @ 080450b8

void FUN_080450b8(void)

{
  (*DAT_200007a0)();
  return;
}



// FUNCTION FUN_080450d8 @ 080450d8

void FUN_080450d8(int param_1)

{
  (**(code **)(param_1 + 4))(1,0);
  (**(code **)(param_1 + 4))(3,0);
  return;
}



// FUNCTION FUN_080450f8 @ 080450f8

void FUN_080450f8(int param_1)

{
  (**(code **)(param_1 + 4))(1,0);
  (**(code **)(param_1 + 4))(3,0);
  (**(code **)(param_1 + 8))(0x14);
  (**(code **)(param_1 + 4))(0,0);
  (**(code **)(param_1 + 8))(0x14);
  (**(code **)(param_1 + 4))(2,0);
  (**(code **)(param_1 + 8))(0x28);
  return;
}



// FUNCTION FUN_08045144 @ 08045144

void FUN_08045144(int param_1,byte param_2,char param_3)

{
  undefined4 local_14;
  undefined1 local_d;
  
  if (param_3 == '\0') {
    local_d = param_2 & 0xfe;
  }
  else {
    local_d = param_2 | 1;
  }
  (**(code **)(param_1 + 4))(2,0);
  for (local_14 = 7; -1 < (int)local_14; local_14 = local_14 - 1) {
    FUN_080453d0(param_1,(uint)local_d & 1 << (local_14 & 0xff));
    (**(code **)(param_1 + 8))(0x14);
    FUN_08045390(param_1);
  }
  return;
}



// FUNCTION FUN_080451c0 @ 080451c0

undefined1 FUN_080451c0(int param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined1 local_d;
  
  (**(code **)(param_1 + 4))(4,0);
  (**(code **)(param_1 + 4))(3,0);
  local_d = 0;
  (**(code **)(param_1 + 8))(0x14);
  local_14 = 10;
  do {
    if (local_14 < 1) {
LAB_0804521e:
      (**(code **)(param_1 + 4))(2,0);
      (**(code **)(param_1 + 4))(5,0);
      (**(code **)(param_1 + 8))(0x14);
      return local_d;
    }
    iVar1 = FUN_080453b8(param_1);
    if (iVar1 == 0) {
      local_d = 1;
      goto LAB_0804521e;
    }
    local_14 = local_14 + -1;
  } while( true );
}



// FUNCTION FUN_08045244 @ 08045244

byte FUN_08045244(int param_1)

{
  int iVar1;
  undefined1 local_11;
  undefined4 local_10;
  
  local_11 = 0;
  (**(code **)(param_1 + 4))(4,0);
  local_10 = 8;
  while (local_10 != 0) {
    (**(code **)(param_1 + 4))(3,0);
    local_11 = local_11 << 1;
    iVar1 = FUN_080453b8(param_1);
    if (iVar1 != 0) {
      local_11 = local_11 | 1;
    }
    (**(code **)(param_1 + 8))(0x14);
    (**(code **)(param_1 + 4))(2,0);
    (**(code **)(param_1 + 8))(0x14);
    local_10 = local_10 + -1;
  }
  (**(code **)(param_1 + 4))(5,0);
  return local_11;
}



// FUNCTION FUN_080452c4 @ 080452c4

void FUN_080452c4(int param_1)

{
  (**(code **)(param_1 + 4))(5,0);
  (**(code **)(param_1 + 4))(0,0);
  (**(code **)(param_1 + 8))(0x14);
  (**(code **)(param_1 + 4))(3,0);
  (**(code **)(param_1 + 8))(0x28);
  (**(code **)(param_1 + 4))(0,0);
  (**(code **)(param_1 + 8))(0x28);
  (**(code **)(param_1 + 4))(2,0);
  (**(code **)(param_1 + 4))(5,0);
  (**(code **)(param_1 + 8))(0x14);
  return;
}



// FUNCTION FUN_0804532c @ 0804532c

void FUN_0804532c(int param_1)

{
  (**(code **)(param_1 + 4))(4,0);
  FUN_08045390(param_1);
  (**(code **)(param_1 + 4))(5,0);
  (**(code **)(param_1 + 8))(0x14);
  return;
}



// FUNCTION FUN_08045358 @ 08045358

void FUN_08045358(int param_1)

{
  (**(code **)(param_1 + 4))(0,0);
  (**(code **)(param_1 + 4))(3,0);
  (**(code **)(param_1 + 8))(0x14);
  (**(code **)(param_1 + 4))(1,0);
  (**(code **)(param_1 + 8))(0x14);
  return;
}



// FUNCTION FUN_08045390 @ 08045390

void FUN_08045390(int param_1)

{
  (**(code **)(param_1 + 4))(3,0);
  (**(code **)(param_1 + 8))(0x14);
  (**(code **)(param_1 + 4))(2,0);
  return;
}



// FUNCTION FUN_080453b8 @ 080453b8

undefined1 FUN_080453b8(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(param_1 + 4))(8,0);
  return uVar1;
}



// FUNCTION FUN_080453d0 @ 080453d0

void FUN_080453d0(int param_1,char param_2)

{
  if (param_2 == '\0') {
    (**(code **)(param_1 + 4))(0,0);
  }
  else {
    (**(code **)(param_1 + 4))(1,0);
  }
  return;
}


