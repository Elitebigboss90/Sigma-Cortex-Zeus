
// FUNCTION FUN_080298e6 @ 080298e6
// XREF 08027fe8

undefined4 FUN_080298e6(void)

{
  FUN_08029484(0);
  FUN_080299e0(0);
  FUN_080291e4(0);
  return 0;
}



// FUNCTION FUN_08029a58 @ 08029a58
// XREF 08028090

undefined4 FUN_08029a58(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == 0) || (param_4 < 1)) {
    uVar1 = 0xffffffff;
  }
  else {
    (**(code **)(DAT_08029a74 + 0x10))(param_3,param_4);
    uVar1 = 0;
  }
  return uVar1;
}


