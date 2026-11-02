
// FUNCTION FUN_0802046a @ 0802046a
// XREF 08020290

void FUN_0802046a(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_lr;
  uint *puVar3;
  
  uVar1 = FUN_080204d4();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = unaff_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_080202cc();
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



// FUNCTION FUN_08023a08 @ 08023a08
// XREF 0802003c

void FUN_08023a08(void)

{
  DAT_20002104 = DAT_20002104 + 1;
  FUN_08045aa8();
  return;
}



// FUNCTION FUN_08043a60 @ 08043a60
// XREF 0802029a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08043a60(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  _DAT_e000ed08 = &VectorTable;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(0);
  }
  FUN_080451c4(0);
  FUN_0802fd6c();
  FUN_08045240();
  FUN_0802e1f4();
  while (iVar2 = FUN_08020844(), iVar2 == 0) {
    FUN_0802eecc(1);
  }
  do {
    iVar2 = FUN_08021238();
  } while (iVar2 == 0);
  FUN_0802eecc(8);
  do {
    iVar2 = FUN_080208c8();
  } while (iVar2 == 0);
  FUN_0802eecc(8);
  do {
    iVar2 = FUN_080207e8();
  } while (iVar2 == 0);
  FUN_0802eecc(8);
  FUN_080443c4();
  FUN_0802f2c4();
  FUN_0802410c();
  FUN_08023398();
  FUN_080240dc();
  FUN_08020708(&DAT_20001f94,0x170);
  iVar2 = FUN_0802e6c8();
  if (iVar2 == 0) {
    FUN_0802e724();
    FUN_0802e9a8();
  }
  FUN_0802c078();
  do {
    FUN_0802affc();
    FUN_08028108();
    FUN_08045968();
    FUN_0802e9d8();
    FUN_08020900();
    uVar3 = FUN_0802f814(DAT_20003b6c);
    if (0x4b0 < uVar3) {
      DAT_20003b68 = 0;
      FUN_080206c4(&DAT_20003b28,0x40);
    }
    if ((DAT_200008e4 == 5) && (DAT_20000040 != '\0')) {
      FUN_080460c0();
      iVar2 = FUN_08046010();
      if (iVar2 != 0) {
        FUN_0804606c();
        FUN_0802063a(&DAT_200045c8,&DAT_20004608,0x40);
        DAT_20000040 = '\0';
      }
    }
    if (DAT_200008e4 == 5) {
      FUN_0804521c(1);
    }
    else {
      FUN_080452e0(1);
    }
    iVar2 = FUN_08028e7c(&DAT_200008e8);
    if (iVar2 == 0) {
      FUN_080452e0(4);
    }
    else {
      FUN_0804521c(4);
    }
  } while( true );
}


