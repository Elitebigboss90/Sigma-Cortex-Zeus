
// FUNCTION FUN_08027298 @ 08027298
// XREF 080273de
// XREF 0802759e
// XREF 080275de
// XREF 08027ef6
// XREF 08027f7a
// XREF 0802800a
// XREF 08028172
// XREF 080281b6

undefined4
FUN_08027298(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_08022478(DAT_0802734c,param_1,param_3,param_4,param_1,param_2,param_3,param_4);
  uVar2 = DAT_08027374;
  if (((((((iVar1 != 0) &&
          (iVar1 = FUN_08022478(DAT_08027350,param_1), uVar2 = DAT_08027378, iVar1 != 0)) &&
         (iVar1 = FUN_08022478(DAT_08027354,param_1), uVar2 = DAT_0802737c, iVar1 != 0)) &&
        ((iVar1 = FUN_08022478(DAT_08027358,param_1), uVar2 = DAT_08027380, iVar1 != 0 &&
         (iVar1 = FUN_08022478(DAT_0802735c,param_1), uVar2 = DAT_08027384, iVar1 != 0)))) &&
       ((iVar1 = FUN_08022478(DAT_08027360,param_1), uVar2 = DAT_08027388, iVar1 != 0 &&
        ((iVar1 = FUN_08022478(DAT_08027364,param_1), uVar2 = DAT_0802738c, iVar1 != 0 &&
         (iVar1 = FUN_08022478(DAT_08027368,param_1), uVar2 = DAT_08027390, iVar1 != 0)))))) &&
      (iVar1 = FUN_08022478(DAT_0802736c,param_1), uVar2 = DAT_08027370, iVar1 != 0)) ||
     (iVar1 = FUN_0802fc60(uVar2,param_1,*param_2,param_2[1],param_2[4],param_2[5],
                           *(undefined1 *)(param_2 + 2),param_2[3]), iVar1 != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



// FUNCTION FUN_08028004 @ 08028004
// XREF 08023508

void FUN_08028004(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_08027298(DAT_08028014,param_1,param_3,param_4,param_4);
  *DAT_08028018 = uVar1;
  return;
}


