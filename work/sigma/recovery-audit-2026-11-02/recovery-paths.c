
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



// FUNCTION FUN_0802525c @ 0802525c
// XREF 08020276

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802525c(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  _DAT_e000ed08 = &VectorTable;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(0);
  }
  FUN_08024f20(0);
  FUN_08024dd4();
  FUN_080430c4();
  FUN_080458a8();
  while (iVar2 = FUN_080446a0(), iVar2 == 0) {
    FUN_08025048(1);
  }
  do {
    iVar2 = FUN_080445d4();
  } while (iVar2 == 0);
  FUN_08025048(8);
  do {
    iVar2 = FUN_0804460c();
  } while (iVar2 == 0);
  FUN_08025048(8);
  do {
    iVar2 = FUN_08044644();
  } while (iVar2 == 0);
  FUN_08025048(8);
  FUN_08026f88();
  FUN_0802c2dc();
  FUN_08024d94();
  FUN_08024d7c();
  FUN_0802d5ac();
  FUN_0802053e(&DAT_20000d64,0x170);
  iVar2 = FUN_0802b5b8();
  if (iVar2 == 0) {
    FUN_0802b614();
    FUN_0802b898();
  }
  FUN_080253f8();
  do {
    FUN_08022598();
    FUN_0802a608();
    FUN_080433f4();
    FUN_0802b8f0();
    FUN_08044724();
    uVar3 = FUN_080250d8(DAT_20000f20);
    if (0x4b0 < uVar3) {
      DAT_20000f1c = 0;
      FUN_08045aa8(&DAT_20000edc,0x40);
    }
    if ((DAT_20000d60 == 5) && (DAT_20000000 != '\0')) {
      FUN_0802a8b4();
      iVar2 = FUN_0802a7ec();
      if (iVar2 != 0) {
        FUN_0802a7dc();
        FUN_080204b4(&DAT_20000cc8,&DAT_20000c88,0x40);
        DAT_20000000 = '\0';
      }
    }
    if (DAT_20000d60 == 5) {
      FUN_0804449c(1);
    }
    else {
      FUN_080444c0(1);
    }
    iVar2 = FUN_08024194(&DAT_200008f4);
    if (iVar2 == 0) {
      FUN_080444c0(4);
    }
    else {
      FUN_0804449c(4);
    }
  } while( true );
}



// FUNCTION FUN_08025538 @ 08025538
// XREF 08020008

void FUN_08025538(void)

{
  return;
}



// FUNCTION thunk_FUN_0802553e @ 0802553c
// XREF 0802000c

void thunk_FUN_0802553e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802553e @ 0802553e
// XREF 0802553c
// XREF 0802553e

void FUN_0802553e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION thunk_FUN_08025542 @ 08025540
// XREF 08020010

void thunk_FUN_08025542(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_08025542 @ 08025542
// XREF 08025540
// XREF 08025542

void FUN_08025542(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION thunk_FUN_08025546 @ 08025544
// XREF 08020014

void thunk_FUN_08025546(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_08025546 @ 08025546
// XREF 08025544
// XREF 08025546

void FUN_08025546(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION thunk_FUN_0802554a @ 08025548
// XREF 08020018

void thunk_FUN_0802554a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802554a @ 0802554a
// XREF 08025548
// XREF 0802554a

void FUN_0802554a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802ae8c @ 0802ae8c
// XREF 0802d38e

void FUN_0802ae8c(void)

{
  if ((DAT_20000d16 & 1) != 0) {
    if ((((DAT_20000d20 == '\x03') && (DAT_20000d21 == 'U')) && (DAT_20000d22 == -1)) &&
       (((DAT_20000d23 == -0x55 && (DAT_20000d24 == -0x53)) &&
        ((DAT_20000d25 == -0x46 && (DAT_20000d26 == -0x42)))))) {
      FUN_0802ba20();
      FUN_0802b9f4();
    }
    else {
      DAT_20000d1c = 1;
    }
    DAT_20000d16 = 0;
  }
  return;
}



// FUNCTION FUN_0802b930 @ 0802b930
// XREF 0802ba22

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
// XREF 0802af14

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
// XREF 0802b9f4

void FUN_0802b9f8(void)

{
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802ba20 @ 0802ba20
// XREF 0802af10

void FUN_0802ba20(void)

{
  FUN_0802b930();
  return;
}


