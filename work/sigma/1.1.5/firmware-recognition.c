
// FUNCTION Reset_Handler @ 08020290
// XREF 08020004
// XREF Entry Point

void Reset_Handler(void)

{
  (*DAT_080202b8)();
                    /* WARNING: Could not recover jumptable at 0x08020296. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_080202bc)();
  return;
}



// FUNCTION FUN_080207f8 @ 080207f8
// XREF 08020292

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080207f8(void)

{
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  _DAT_40021000 = _DAT_40021000 & 0xfef2ffff | 1;
  _DAT_40021004 = _DAT_40021004 & 0xf000c000;
  _DAT_4002102c = 0x3800;
  _DAT_40021030 = 0x3840;
  _DAT_40021008 = 0x9f0000;
  _DAT_4000700c = _DAT_4000700c | 1;
  _DAT_4002101c = _DAT_4002101c & 0xefffffff;
  _DAT_40022000 = _DAT_40022000 | 0x90;
  FUN_080208e8();
  _DAT_e000ed08 = 0x8000000;
  if (_DAT_1ffff298 != 0x49524b42) {
    FUN_08020a50();
  }
  return;
}



// FUNCTION FUN_08027d00 @ 08027d00
// XREF 08027428
// XREF 08027914

bool FUN_08027d00(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_08024194(&DAT_20000b0c);
  bVar2 = false;
  if ((iVar1 != 0) && ((DAT_20000b7e != 0x483 || (bVar2 = true, DAT_20000b7c != 0x530)))) {
    bVar2 = DAT_20000b7e == 0x3670 && DAT_20000b7c == 0xa04;
  }
  return bVar2;
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


