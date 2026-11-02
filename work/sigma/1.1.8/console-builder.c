
// FUNCTION FUN_08020278 @ 08020278
// XREF 08020296

undefined8 FUN_08020278(undefined4 param_1,undefined4 param_2)

{
  FUN_08046dd0();
  FUN_08020758();
  return CONCAT44(param_2,param_1);
}



// FUNCTION FUN_080231a0 @ 080231a0
// XREF 08023ade

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080231a0(void)

{
  uint uVar1;
  bool bVar2;
  int local_c;
  
  local_c = 0;
  uVar1 = _DAT_40021000 | 0x10000;
  do {
    bVar2 = local_c != 0x7fff;
    local_c = local_c + 1;
  } while (-1 < (int)(uVar1 << 0xe) && bVar2);
  if ((int)(uVar1 << 0xe) < 0) {
    _DAT_40022000 = _DAT_40022000 & 0xfffffff8 | 4;
    _DAT_40021000 = _DAT_40021000 | 0x1010000;
    do {
    } while (-1 < (int)(_DAT_40021000 * 0x40));
    do {
      uVar1 = _DAT_40021004 & 0xf7c0fffc | 0x8052502;
    } while ((_DAT_40021004 & 0xc) != 8);
  }
  else {
    DAT_20000848 = 1;
    _DAT_40021000 = uVar1;
    uVar1 = _DAT_40021004;
  }
  _DAT_40021004 = uVar1;
  return;
}



// FUNCTION FUN_080451c4 @ 080451c4
// XREF 08043a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080451c4(void)

{
  _DAT_e000e014 = 0x23280;
  if (DAT_20000848 != '\0') {
    _DAT_e000e014 = 8000;
  }
  _DAT_e000e018 = 0;
  _DAT_e000e010 = 7;
  FUN_0802c428();
  DAT_20002104 = 0;
  return;
}



// FUNCTION FUN_08046010 @ 08046010
// XREF 08043b84

bool FUN_08046010(void)

{
  int iVar1;
  
  iVar1 = FUN_080202f2(&DAT_20004608,&DAT_200045c8,0x40);
  return iVar1 != 0;
}



// FUNCTION FUN_0804606c @ 0804606c
// XREF 08043b8c

void FUN_0804606c(void)

{
  FUN_080246d4();
  FUN_080245e8(4);
  return;
}



// FUNCTION FUN_080460c0 @ 080460c0
// XREF 08043b80

void FUN_080460c0(void)

{
  DAT_20004608 = 1;
  DAT_20004609 = 0x80;
  DAT_2000460a = 0x80;
  DAT_2000460b = 0x80;
  DAT_2000460c = 0x80;
  DAT_2000460d = DAT_20004548;
  if (((DAT_20004579 & 1) != 0) || ((DAT_2000457a & 1) != 0)) {
    if ((&DAT_20001fb6)[DAT_200020fc * 0x12] == 0) {
      if ((DAT_20004579 & 1) == 0) {
        if ((DAT_2000457a & 1) != 0) {
          DAT_20004549 = DAT_20004549 | 1;
        }
      }
      else {
        DAT_20004549 = DAT_20004549 | 2;
      }
    }
    else if ((DAT_20004579 & 1) == 0) {
      if ((DAT_2000457a & 1) != 0) {
        DAT_20004549 = DAT_20004549 | 2;
      }
    }
    else {
      DAT_20004549 = DAT_20004549 | 1;
    }
  }
  DAT_2000460e = DAT_20004549;
  DAT_2000460f = DAT_2000455c;
  FUN_08020708(&DAT_20004610,0x23);
  DAT_20004633 = (char)DAT_20004570;
  DAT_20004634 = DAT_20004570._1_1_;
  DAT_20004635 = (char)DAT_20004572;
  DAT_20004636 = DAT_20004572._1_1_;
  DAT_20004637 = (char)DAT_20004574;
  DAT_20004638 = DAT_20004574._1_1_;
  DAT_20004639 = (char)DAT_20004576;
  DAT_2000463a = DAT_20004576._1_1_;
  DAT_2000463b = DAT_2000457b;
  DAT_2000463c = -1 - DAT_20004578;
  DAT_2000463d = -1 - DAT_20004578;
  DAT_20004646 = 0;
  DAT_20004642 = 0;
  DAT_2000463e = 0;
  if (((DAT_2000454b & 1) == 0) && ((DAT_2000454a & 1) != 0)) {
    DAT_2000454c = DAT_2000454c + 1;
  }
  if (((DAT_2000454b >> 1 & 1) == 0) && ((DAT_2000454a >> 1 & 1) != 0)) {
    DAT_20004550 = DAT_20004550 + 1;
  }
  if (((DAT_2000454b >> 2 & 1) == 0) && ((DAT_2000454a >> 2 & 1) != 0)) {
    DAT_20004554 = DAT_20004554 + 1;
  }
  if (((DAT_2000454b >> 3 & 1) == 0) && ((DAT_2000454a >> 3 & 1) != 0)) {
    DAT_20004558 = DAT_20004558 + 1;
  }
  DAT_2000454b = DAT_2000454a;
  return;
}


