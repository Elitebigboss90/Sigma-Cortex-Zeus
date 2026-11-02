
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



// FUNCTION FUN_08024b90 @ 08024b90

void FUN_08024b90(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5)

{
  *(undefined1 *)(param_1 + 0x38) = 6;
  if ((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x522)) {
    if ((*(byte *)(param_1 + 0x157) & 1) == 0) {
      FUN_08024c38(param_1,param_5,param_4);
    }
    else {
      FUN_08025114(param_1,param_5,param_4);
    }
  }
  return;
}



// FUNCTION FUN_080281c0 @ 080281c0

bool FUN_080281c0(undefined4 param_1,short param_2,short param_3)

{
  return param_2 == 0x483 && param_3 == 0x522;
}



// FUNCTION FUN_08028724 @ 08028724
// XREF 08028f92
// XREF 0802c3d6

void FUN_08028724(int *param_1,undefined1 param_2,byte param_3,byte param_4,char param_5,int param_6
                 )

{
  int iVar1;
  byte *local_18;
  byte local_11;
  
  *(undefined1 *)((int)param_1 + 0x2f) = param_2;
  local_11 = 0;
  local_18 = (byte *)FUN_08028670(param_1,param_3,param_4,param_5);
  if (local_18 == (byte *)0x0) {
    if (4 < *(byte *)(param_1 + 0xc)) {
      return;
    }
    local_18 = (byte *)((int)param_1 + (uint)*(byte *)(param_1 + 0xc) * 4 + 0x5b);
    *local_18 = (param_3 & 7) + (*local_18 & 0xf8);
    *local_18 = *local_18 & 199 | (param_4 & 7) << 3;
    *local_18 = *local_18 & 0x3f | param_5 << 6;
    *(char *)(param_1 + 0xc) = (char)param_1[0xc] + '\x01';
  }
  if (((*(byte *)(param_6 + 3) & 3) == 3) &&
     (local_11 = 2, (int)((uint)*(byte *)(param_6 + 2) * 0x1000000) < 0)) {
    local_11 = 1;
  }
  iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,param_3,param_5);
  if (iVar1 == 0) {
    local_11 = 0;
  }
  if ((local_11 != 0) && (*(byte *)((int)param_1 + 0x31) < 0xb)) {
    *(byte *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x31) * 3 + 0x3a) =
         *(byte *)(param_6 + 2) & 0xf;
    *(undefined1 *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x31) * 3 + 0x3b) =
         *(undefined1 *)(param_6 + 4);
    iVar1 = (uint)*(byte *)((int)param_1 + 0x31) * 3;
    *(byte *)((int)param_1 + iVar1 + 0x3c) = *(byte *)((int)param_1 + iVar1 + 0x3c) & 0xfe;
    iVar1 = (uint)*(byte *)((int)param_1 + 0x31) * 3;
    *(byte *)((int)param_1 + iVar1 + 0x3c) = *(byte *)((int)param_1 + iVar1 + 0x3c) & 0xfd;
    iVar1 = (uint)*(byte *)((int)param_1 + 0x31) * 3;
    *(byte *)((int)param_1 + iVar1 + 0x3c) = *(byte *)((int)param_1 + iVar1 + 0x3c) & 3 | 4;
    local_18[local_11 + 1] = *(byte *)((int)param_1 + 0x31);
    if (*(byte *)(param_1 + 0xe) < *(byte *)(param_6 + 6)) {
      *(undefined1 *)(param_1 + 0xe) = *(undefined1 *)(param_6 + 6);
    }
    *(char *)((int)param_1 + 0x31) = *(char *)((int)param_1 + 0x31) + '\x01';
  }
  return;
}



// FUNCTION FUN_080292a4 @ 080292a4

bool FUN_080292a4(undefined4 param_1,short param_2,short param_3)

{
  return param_2 == 0x483 && param_3 == 0x531;
}



// FUNCTION FUN_080294dc @ 080294dc

bool FUN_080294dc(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if (((param_2 != 0x483) || (bVar1 = true, param_3 != 0x526)) &&
     ((param_2 != 0x483 || (bVar1 = true, param_3 != 0x525)))) {
    bVar1 = param_2 == 0x3670 && param_3 == 0xa06;
  }
  return bVar1;
}



// FUNCTION FUN_08029b44 @ 08029b44

bool FUN_08029b44(undefined4 param_1,short param_2,short param_3)

{
  bool bVar1;
  
  if ((param_2 != 0x483) || (bVar1 = true, param_3 != 0x530)) {
    bVar1 = param_2 == 0x3670 && param_3 == 0xa04;
  }
  return bVar1;
}


