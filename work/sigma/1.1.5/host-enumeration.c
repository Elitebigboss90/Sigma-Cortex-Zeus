
// FUNCTION FUN_0802157c @ 0802157c
// XREF 08025112

int FUN_0802157c(int param_1)

{
  FUN_080215b0(param_1);
  FUN_080215bc(param_1);
  *(undefined1 *)(param_1 + 0xb8) = 0;
  DAT_20000811 = 0x11;
  FUN_08021614(param_1);
  return param_1;
}



// FUNCTION FUN_08023a58 @ 08023a58
// XREF 0802512a

undefined4 * FUN_08023a58(undefined4 *param_1,undefined4 param_2)

{
  FUN_08023ad8(param_1);
  *param_1 = &PTR_FUN_080231f0_1_08046640;
  param_1[1] = param_2;
  *(undefined1 *)((int)param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0xf) = 0;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 8;
  *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xfe;
  *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xfd;
  *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 3 | 0x3c;
  *(undefined1 *)((int)param_1 + 0xb) = 1;
  *(undefined1 *)(param_1 + 3) = 8;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfe;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 3 | 4;
  if (param_1[1] != 0) {
    FUN_08023af0(param_1[1],param_1);
  }
  return param_1;
}



// FUNCTION FUN_08023ec8 @ 08023ec8

undefined4 FUN_08023ec8(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_08022b5c(*(undefined4 *)(param_1 + 8));
  (**(code **)(*piVar1 + 8))(piVar1,*(undefined1 *)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x39) = 0;
  return 0;
}



// FUNCTION FUN_0802437c @ 0802437c
// XREF 080241e0

int FUN_0802437c(int param_1,byte param_2,byte param_3,byte param_4)

{
  byte local_c;
  
  local_c = 0;
  while( true ) {
    if (*(byte *)(param_1 + 0x30) <= local_c || 4 < local_c) {
      return 0;
    }
    if ((((*(byte *)(param_1 + (uint)local_c * 4 + 0x5b) & 7) == param_2) &&
        ((*(byte *)(param_1 + (uint)local_c * 4 + 0x5b) & 0x3f) >> 3 == (uint)param_3)) &&
       (param_4 == *(byte *)(param_1 + (uint)local_c * 4 + 0x5b) >> 6)) break;
    local_c = local_c + 1;
  }
  return param_1 + (uint)local_c * 4 + 0x5b;
}



// FUNCTION FUN_08024818 @ 08024818
// XREF 08025194

undefined4 * FUN_08024818(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802486c(param_1,param_2);
  *param_1 = &PTR_FUN_08023ba0_1_08046698;
  param_1[1] = &DAT_080466e0;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  *(undefined1 *)((int)param_1 + 0x6f) = 0;
  FUN_080248a0(param_1);
  if (param_1[2] != 0) {
    FUN_08023af0(param_1[2],param_1);
  }
  return param_1;
}



// FUNCTION FUN_08024a8c @ 08024a8c

char FUN_08024a8c(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort local_5e;
  byte local_5b;
  byte local_5a;
  undefined1 local_59 [64];
  char local_19;
  int *local_18;
  char local_11;
  
  local_19 = '\0';
  if ((*(byte *)((int)param_1 + 0x39) & 1) == 0) {
    local_11 = '\0';
  }
  else {
    local_18 = param_1;
    iVar3 = FUN_0802503c();
    if (-1 < iVar3 - param_1[0xd]) {
      iVar3 = FUN_0802503c();
      param_1[0xd] = iVar3 + (uint)*(byte *)(param_1 + 0xe);
      for (local_5a = 0; local_5a < *(byte *)(param_1 + 0xc); local_5a = local_5a + 1) {
        local_5b = *(byte *)((int)param_1 + (uint)local_5a * 4 + 0x5d);
        local_5e = (ushort)*(byte *)((int)param_1 + (uint)local_5b * 3 + 0x3b);
        FUN_08024430(param_1,local_59);
        cVar1 = FUN_08022490(param_1[2],(char)param_1[3],
                             *(undefined1 *)((int)param_1 + (uint)local_5b * 3 + 0x3a),&local_5e,
                             local_59);
        if (cVar1 != '\0') {
          if (cVar1 == '\x04') {
            return '\x04';
          }
          FUN_08022524(cVar1,0x81);
          return cVar1;
        }
        if (0x40 < local_5e) {
          local_5e = 0x40;
        }
        (**(code **)(*param_1 + 0x40))
                  (param_1,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_5e,local_59)
        ;
        uVar2 = local_59[0];
        if ((*(byte *)((int)param_1 + 0x6f) & 1) == 0) {
          uVar2 = 0;
        }
        puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x24))(param_1,uVar2);
        if (puVar4 != (undefined4 *)0x0) {
          (**(code **)*puVar4)
                    (puVar4,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_5e,local_59
                    );
        }
      }
    }
    local_11 = local_19;
  }
  return local_11;
}



// FUNCTION FUN_08027108 @ 08027108

bool FUN_08027108(undefined4 param_1,short param_2,short param_3)

{
  return param_2 == 0x483 && param_3 == 0x522;
}



// FUNCTION FUN_0802bd44 @ 0802bd44

void FUN_0802bd44(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x531)) &&
      (2 < param_4)) && ((param_4 < 0x41 && (param_5 != 0)))) {
    FUN_080204b4(param_1 + 0x78,param_5,param_4);
  }
  return;
}


