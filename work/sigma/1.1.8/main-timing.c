
// FUNCTION FUN_0802028c @ 0802028c
// XREF 080202a4
// XREF 0802045c

void FUN_0802028c(void)

{
  return;
}



// FUNCTION FUN_08020290 @ 08020290
// XREF 0802019c
// XREF 080201ae
// XREF 080201dc

void FUN_08020290(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined8 uVar2;
  
  uVar1 = FUN_0802046a();
  FUN_08020278(uVar1,extraout_r2);
  FUN_08043a60();
  uVar2 = FUN_080204b4();
  FUN_0802028c();
  FUN_0802d5d8((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  (*DAT_080202d8)();
                    /* WARNING: Could not recover jumptable at 0x080202b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_080202dc)();
  return;
}



// FUNCTION Reset_Handler @ 080202b0
// XREF 08020004
// XREF Entry Point

void Reset_Handler(void)

{
  (*DAT_080202d8)();
                    /* WARNING: Could not recover jumptable at 0x080202b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_080202dc)();
  return;
}



// FUNCTION FUN_08023a08 @ 08023a08
// XREF 0802003c

void FUN_08023a08(void)

{
  DAT_20002104 = DAT_20002104 + 1;
  FUN_08045aa8();
  return;
}



// FUNCTION FUN_08023a20 @ 08023a20
// XREF 080202b2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08023a20(void)

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
  FUN_080231a0();
  _DAT_e000ed08 = 0x8000000;
  if (_DAT_1ffff298 != 0x49524b42) {
    FUN_08023300();
  }
  return;
}



// FUNCTION FUN_0802d5d8 @ 0802d5d8
// XREF 080202aa
// XREF 080204e0
// XREF 08020466

void FUN_0802d5d8(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


