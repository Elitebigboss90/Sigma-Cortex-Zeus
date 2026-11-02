
// FUNCTION FUN_08024720 @ 08024720
// XREF 08020772

void FUN_08024720(void)

{
  FUN_0802c4c0();
  FUN_0802c4cc();
  thunk_FUN_08028434();
  thunk_FUN_08024a18();
  thunk_FUN_08029bfc();
  thunk_FUN_08029320();
  FUN_080295d4();
  return;
}



// FUNCTION FUN_080249a4 @ 080249a4

bool FUN_080249a4(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if (((param_2 != 0x483) || (bVar1 = true, param_3 != 0x525)) &&
     ((param_2 != 0x3670 || (bVar1 = true, param_3 != 0x903)))) {
    bVar1 = param_2 == 0x483 && param_3 == 0x524;
  }
  return bVar1;
}



// FUNCTION FUN_08024a18 @ 08024a18
// XREF 0802c4e4

void FUN_08024a18(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_20003ab0,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_080470ac;
  puVar1[1] = &DAT_080470f8;
  return;
}



// FUNCTION FUN_08028470 @ 08028470

undefined1 FUN_08028470(int param_1)

{
  return *(undefined1 *)(param_1 + 0xc);
}



// FUNCTION FUN_080288b0 @ 080288b0

undefined4 FUN_080288b0(int param_1,char param_2)

{
  byte bStack_a;
  undefined4 uStack_4;
  
  if ((*(byte *)(param_1 + 0x6f) & 1) == 0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      uStack_4 = 0;
    }
    else {
      uStack_4 = *(undefined4 *)(param_1 + 0x14);
    }
  }
  else {
    for (bStack_a = 0; bStack_a < 2; bStack_a = bStack_a + 1) {
      if (*(char *)(param_1 + (uint)bStack_a * 8 + 0x10) == param_2) {
        return *(undefined4 *)(param_1 + (uint)bStack_a * 8 + 0x14);
      }
    }
    uStack_4 = 0;
  }
  return uStack_4;
}



// FUNCTION FUN_08028924 @ 08028924

undefined1 FUN_08028924(int param_1,undefined1 param_2,undefined4 param_3)

{
  byte bStack_11;
  
  bStack_11 = 0;
  while( true ) {
    if (1 < bStack_11) {
      return 0;
    }
    if ((*(char *)(param_1 + (uint)bStack_11 * 8 + 0x10) == '\0') &&
       (*(int *)(param_1 + (uint)bStack_11 * 8 + 0x14) == 0)) break;
    bStack_11 = bStack_11 + 1;
  }
  *(undefined1 *)(param_1 + 0x10 + (uint)bStack_11 * 8) = param_2;
  *(undefined4 *)(param_1 + 0x10 + (uint)bStack_11 * 8 + 4) = param_3;
  return 1;
}



// FUNCTION FUN_080289a0 @ 080289a0

undefined4 FUN_080289a0(void)

{
  return 0;
}



// FUNCTION FUN_08028ee4 @ 08028ee4

void FUN_08028ee4(void)

{
  return;
}



// FUNCTION FUN_08028f9c @ 08028f9c

undefined4 FUN_08028f9c(void)

{
  return 1;
}



// FUNCTION FUN_08029c34 @ 08029c34

undefined4 FUN_08029c34(void)

{
  return 0;
}



// FUNCTION FUN_08029c50 @ 08029c50

void FUN_08029c50(void)

{
  return;
}



// FUNCTION FUN_08029c5c @ 08029c5c

undefined4 FUN_08029c5c(void)

{
  return 1;
}



// FUNCTION FUN_08029c6c @ 08029c6c

undefined4 FUN_08029c6c(void)

{
  return 0;
}



// FUNCTION FUN_08029cb4 @ 08029cb4

undefined4 FUN_08029cb4(void)

{
  return 0;
}



// FUNCTION FUN_0802c4c0 @ 0802c4c0
// XREF 08024722

void FUN_0802c4c0(void)

{
  FUN_0802b5ac(&DAT_20004488);
  return;
}



// FUNCTION FUN_0802c4cc @ 0802c4cc
// XREF 08024726

void FUN_0802c4cc(void)

{
  FUN_0802bf94(&DAT_20002734,&DAT_20004488);
  return;
}



// FUNCTION thunk_FUN_08028434 @ 0802c4e0
// XREF 0802472a

void thunk_FUN_08028434(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_200008e8,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_08047104;
  puVar1[1] = &DAT_08047150;
  *(undefined1 *)((int)puVar1 + 0x157) = 1;
  return;
}



// FUNCTION thunk_FUN_08024a18 @ 0802c4e4
// XREF 0802472e

void thunk_FUN_08024a18(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_20003ab0,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_080470ac;
  puVar1[1] = &DAT_080470f8;
  return;
}



// FUNCTION thunk_FUN_08029bfc @ 0802c4e8
// XREF 08024732

void thunk_FUN_08029bfc(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_200025c0,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_080472d8;
  puVar1[1] = &DAT_08047324;
  return;
}



// FUNCTION thunk_FUN_08029320 @ 0802c4ec
// XREF 08024736

void thunk_FUN_08029320(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_2000267c,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_08047214;
  puVar1[1] = &DAT_08047260;
  return;
}



// FUNCTION thunk_FUN_080295d4 @ 0802c4f0
// XREF 0802473e

void thunk_FUN_080295d4(void)

{
  FUN_080295d4();
  return;
}


