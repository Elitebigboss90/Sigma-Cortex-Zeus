
// FUNCTION FUN_080228b0 @ 080228b0
// XREF 08022820
// XREF 080239d2

char FUN_080228b0(int param_1,undefined1 param_2,undefined1 param_3,byte param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  int local_34;
  int *local_30;
  undefined1 *local_2c;
  undefined1 auStack_27 [18];
  char local_15;
  byte local_14;
  byte local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  char local_9;
  
  local_15 = 0;
  local_2c = auStack_27;
  local_30 = (int *)0x0;
  local_34 = 0;
  local_38 = 0;
  local_37 = 8;
  local_36 = 0x3c;
  local_13 = param_4;
  local_12 = param_3;
  local_11 = param_2;
  local_10 = param_1;
  puVar5 = (undefined4 *)FUN_08022b5c(param_1);
  local_30 = (int *)(**(code **)*puVar5)(puVar5,0);
  if (local_30 == (int *)0x0) {
    local_9 = -0x2a;
  }
  else {
    local_34 = *local_30;
    *local_30 = (int)&local_38;
    *(byte *)((int)local_30 + 6) = local_13 & 1;
    local_15 = FUN_08022b68(param_1,0,0x12,auStack_27);
    *local_30 = local_34;
    local_9 = local_15;
    if (local_15 == '\0') {
      uVar3 = *(undefined2 *)(local_2c + 8);
      uVar4 = *(undefined2 *)(local_2c + 10);
      uVar1 = local_2c[4];
      uVar2 = local_2c[5];
      local_14 = 0;
      while ((local_14 < 0x10 &&
             (((((*(int *)(param_1 + (uint)local_14 * 4 + 0x78) == 0 ||
                 (iVar6 = (**(code **)(**(int **)(param_1 + (uint)local_14 * 4 + 0x78) + 0x10))(),
                 iVar6 != 0)) ||
                (piVar7 = *(int **)(param_1 + (uint)local_14 * 4 + 0x78),
                iVar6 = (**(code **)(*piVar7 + 0x20))(piVar7,uVar2), iVar6 == 0)) ||
               ((piVar7 = *(int **)(param_1 + (uint)local_14 * 4 + 0x78),
                iVar6 = (**(code **)(*piVar7 + 0x18))(piVar7,uVar3,uVar4), iVar6 == 0 &&
                (piVar7 = *(int **)(param_1 + (uint)local_14 * 4 + 0x78),
                iVar6 = (**(code **)(*piVar7 + 0x1c))(piVar7,uVar1), iVar6 == 0)))) ||
              (local_15 = FUN_08022bb8(param_1,local_14,local_11,local_12,local_13 & 1),
              local_15 == -0x2f))))) {
        local_14 = local_14 + 1;
      }
      if (local_14 < 0x10) {
        local_9 = local_15;
      }
      else {
        for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
          if (((((*(int *)(param_1 + (uint)local_14 * 4 + 0x78) != 0) &&
                (iVar6 = (**(code **)(**(int **)(param_1 + (uint)local_14 * 4 + 0x78) + 0x10))(),
                iVar6 == 0)) &&
               ((piVar7 = *(int **)(param_1 + (uint)local_14 * 4 + 0x78),
                iVar6 = (**(code **)(*piVar7 + 0x20))(piVar7,uVar2), iVar6 == 0 ||
                ((piVar7 = *(int **)(param_1 + (uint)local_14 * 4 + 0x78),
                 iVar6 = (**(code **)(*piVar7 + 0x18))(piVar7,uVar3,uVar4), iVar6 == 0 &&
                 (piVar7 = *(int **)(param_1 + (uint)local_14 * 4 + 0x78),
                 iVar6 = (**(code **)(*piVar7 + 0x1c))(piVar7,uVar1), iVar6 == 0)))))) &&
              (local_15 = FUN_08022bb8(param_1,local_14,local_11,local_12,local_13 & 1),
              local_15 != -0x2f)) && (local_15 != -0x27)) {
            return local_15;
          }
        }
        local_9 = FUN_08022d10(param_1,local_11,local_12,local_13 & 1);
      }
    }
  }
  return local_9;
}



// FUNCTION FUN_0802a8b4 @ 0802a8b4
// XREF 0802537c

void FUN_0802a8b4(void)

{
  DAT_20000c88 = 1;
  DAT_20000c89 = 0x80;
  DAT_20000c8a = 0x80;
  DAT_20000c8b = 0x80;
  DAT_20000c8c = 0x80;
  DAT_20000c8d = DAT_20004578;
  if (((DAT_20004528 & 1) != 0) || ((DAT_2000452a & 1) != 0)) {
    if ((&DAT_20000d86)[DAT_20000ecc * 0x12] == 0) {
      if ((DAT_20004528 & 1) == 0) {
        if ((DAT_2000452a & 1) != 0) {
          DAT_20004580 = DAT_20004580 | 1;
        }
      }
      else {
        DAT_20004580 = DAT_20004580 | 2;
      }
    }
    else if ((DAT_20004528 & 1) == 0) {
      if ((DAT_2000452a & 1) != 0) {
        DAT_20004580 = DAT_20004580 | 2;
      }
    }
    else {
      DAT_20004580 = DAT_20004580 | 1;
    }
  }
  DAT_20000c8e = DAT_20004580;
  DAT_20000c8f = DAT_200044f8;
  FUN_0802053e(&DAT_20000c90,0x23);
  DAT_20000cb3 = (char)DAT_20004508;
  DAT_20000cb4 = DAT_20004508._1_1_;
  DAT_20000cb5 = (char)DAT_20004510;
  DAT_20000cb6 = DAT_20004510._1_1_;
  DAT_20000cb7 = (char)DAT_20004514;
  DAT_20000cb8 = DAT_20004514._1_1_;
  DAT_20000cb9 = (char)DAT_20004518;
  DAT_20000cba = DAT_20004518._1_1_;
  DAT_20000cbb = DAT_20004530;
  DAT_20000cbc = -1 - DAT_20004520;
  DAT_20000cbd = -1 - DAT_20004520;
  DAT_20000cc6 = 0;
  DAT_20000cc2 = 0;
  DAT_20000cbe = 0;
  if (((DAT_20004588 & 1) == 0) && ((DAT_20004582 & 1) != 0)) {
    DAT_20004558 = DAT_20004558 + 1;
  }
  if (((DAT_20004588 >> 1 & 1) == 0) && ((DAT_20004582 >> 1 & 1) != 0)) {
    DAT_20004560 = DAT_20004560 + 1;
  }
  if (((DAT_20004588 >> 2 & 1) == 0) && ((DAT_20004582 >> 2 & 1) != 0)) {
    DAT_20004568 = DAT_20004568 + 1;
  }
  if (((DAT_20004588 >> 3 & 1) == 0) && ((DAT_20004582 >> 3 & 1) != 0)) {
    DAT_20004570 = DAT_20004570 + 1;
  }
  DAT_20004588 = DAT_20004582;
  return;
}


