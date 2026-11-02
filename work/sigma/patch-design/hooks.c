
// FUNCTION FUN_0802044a @ 0802044a
// XREF 0802026c

void FUN_0802044a(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_lr;
  uint *puVar3;
  
  uVar1 = FUN_0802058c();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = unaff_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_080202ac();
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



// FUNCTION FUN_08020494 @ 08020494
// XREF 0802027a

void FUN_08020494(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_08020268();
  uVar1 = FUN_0802b488(param_1,param_2);
  FUN_08020688(uVar1);
  return;
}



// FUNCTION FUN_08020688 @ 08020688
// XREF 0802028c

/* WARNING: Removing unreachable block (ram,0x08020748) */

undefined8 FUN_08020688(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  byte *pbVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uStack_2c = param_1;
  uStack_28 = param_2;
  pcVar2 = (char *)FUN_08020666(&uStack_2c,0x100);
  if (pcVar2 == (char *)0x0) {
    FUN_080207e8();
  }
  pbVar3 = (byte *)FUN_0802b474(pcVar2,0x100);
  if (pbVar3 == (byte *)0x0) {
    *(char **)pcVar2 = pcVar2 + 8;
    pcVar2[4] = '\0';
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    **(undefined1 **)pcVar2 = 0;
    iVar13 = 1;
  }
  else {
    iVar13 = 1;
    pcVar8 = pcVar2;
    uVar10 = 0;
    pcVar5 = pcVar2;
    uVar11 = 0;
LAB_080206c0:
    do {
      pbVar9 = pbVar3 + 1;
      uVar7 = (uint)*pbVar3;
      if (uVar10 == 0) {
        uVar4 = uVar7;
        uVar12 = uVar7;
        if ((uVar7 != 0x22) && (uVar7 != 0x27)) goto LAB_08020712;
      }
      else {
        if ((uVar7 == 0x5c) &&
           (((uVar4 = (uint)*pbVar9, uVar4 == 0x22 || (uVar4 == 0x5c)) || (uVar4 == 0x27)))) {
          pbVar9 = pbVar3 + 2;
          uVar7 = uVar4;
        }
        else if (uVar7 == uVar10) {
          uVar4 = 0;
          uVar12 = uVar11;
          goto LAB_08020752;
        }
LAB_08020712:
        if ((uVar7 != 0) && ((uVar10 != 0 || ((uVar7 != 0x20 && (4 < uVar7 - 9)))))) {
          *pcVar8 = (char)uVar7;
          pcVar8 = pcVar8 + 1;
          pbVar3 = pbVar9;
          goto LAB_080206c0;
        }
        uVar4 = uVar10;
        if ((pcVar8 != pcVar5) || (uVar12 = uVar11, uVar11 != 0)) {
          pcVar5 = pcVar8 + 1;
          *pcVar8 = '\0';
          iVar13 = iVar13 + 1;
          pcVar8 = pcVar5;
          uVar12 = 0;
        }
      }
LAB_08020752:
      pbVar3 = pbVar9;
      uVar10 = uVar4;
      uVar11 = uVar12;
    } while (uVar7 != 0);
    pcVar5 = (char *)FUN_08020666(&uStack_2c,iVar13 << 2);
    if (pcVar5 == (char *)0x0) {
      FUN_080207e8(0);
    }
    iVar13 = 0;
    *(char **)pcVar5 = pcVar2;
    while (pcVar2 < pcVar8) {
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
      if (cVar1 == '\0') {
        iVar13 = iVar13 + 1;
        *(char **)(pcVar5 + iVar13 * 4) = pcVar6;
      }
    }
    pcVar2 = pcVar5 + iVar13 * 4;
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar5;
  }
  return CONCAT44(pcVar2,iVar13);
}



// FUNCTION FUN_08023ba0 @ 08023ba0
// XREF 08046698
// XREF 08046750
// XREF 080467f8
// XREF 080469f4
// XREF 08046a4c
// XREF 08046aa4

char FUN_08023ba0(int *param_1,undefined1 param_2,undefined1 param_3,byte param_4)

{
  undefined1 uVar1;
  byte local_89;
  undefined1 auStack_88 [63];
  byte local_49;
  int *local_48;
  byte local_42;
  byte local_41;
  int local_40;
  int *local_3c;
  char local_35;
  byte *local_34;
  byte local_2e [18];
  undefined1 local_1c;
  byte local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  int *local_18;
  char local_11;
  
  local_1c = 0x12;
  local_34 = local_2e;
  local_3c = (int *)0x0;
  local_40 = 0;
  local_41 = 0;
  local_1b = param_4;
  local_1a = param_3;
  local_19 = param_2;
  local_18 = param_1;
  local_48 = (int *)FUN_08022b5c(param_1[2]);
  if ((char)param_1[3] == '\0') {
    local_3c = (int *)(**(code **)*local_48)(local_48,0);
    if (local_3c == (int *)0x0) {
      local_11 = -0x2a;
    }
    else if (*local_3c == 0) {
      local_11 = -0x29;
    }
    else {
      local_40 = *local_3c;
      *local_3c = (int)param_1 + 0x3a;
      *(byte *)((int)local_3c + 6) = local_1b & 1;
      local_35 = FUN_08022b68(param_1[2],0,8,local_2e);
      if ((local_35 == '\0') && (local_41 = local_2e[0], 0x12 < local_2e[0])) {
        local_41 = 0x12;
      }
      if (local_35 == '\0') {
        *local_3c = local_40;
        uVar1 = (**(code **)(*local_48 + 4))(local_48,local_19,0,local_1a);
        *(undefined1 *)(param_1 + 3) = uVar1;
        if ((char)param_1[3] == '\0') {
          return -0x2c;
        }
        *(byte *)((int)param_1 + 0x3b) = local_34[7];
        local_35 = FUN_08022de8(param_1[2],(char)param_1[3]);
        if (local_35 != '\0') {
          *(undefined1 *)((int)local_3c + 6) = 0;
          (**(code **)(*local_48 + 8))(local_48,(char)param_1[3]);
          *(undefined1 *)(param_1 + 3) = 0;
          FUN_08022524(local_35,0x80);
          return local_35;
        }
        FUN_08022524((char)param_1[3],0x80);
        *(undefined1 *)((int)local_3c + 6) = 0;
        local_3c = (int *)(**(code **)*local_48)(local_48,(char)param_1[3]);
        if (local_3c == (int *)0x0) {
          return -0x2a;
        }
        *(byte *)((int)local_3c + 6) = local_1b & 1;
        if (local_41 != 0) {
          local_35 = FUN_08022b68(param_1[2],(char)param_1[3],local_41,local_2e);
        }
        if (local_35 == '\0') {
          *(undefined2 *)((int)param_1 + 0x72) = *(undefined2 *)(local_34 + 8);
          *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(local_34 + 10);
          local_42 = local_34[0x11];
          local_35 = FUN_08021aa4(param_1[2],(char)param_1[3],1,(int)param_1 + 0x3a);
          if (local_35 == '\0') {
            FUN_08022524(local_42,0x80);
            for (local_49 = 0; local_49 < local_42; local_49 = local_49 + 1) {
              FUN_08024470(auStack_88,param_1 + 1);
              local_35 = FUN_08023068(param_1[2],(char)param_1[3],local_49,auStack_88);
              if (local_35 != '\0') goto LAB_08023eac;
              local_35 = '\0';
              if (1 < *(byte *)((int)param_1 + 0x31)) break;
            }
            if (*(byte *)((int)param_1 + 0x31) < 2) {
              return -0x2f;
            }
            local_35 = FUN_08021aa4(param_1[2],(char)param_1[3],*(undefined1 *)((int)param_1 + 0x31)
                                    ,(int)param_1 + 0x3a);
            FUN_08022524(*(undefined1 *)((int)param_1 + 0x2f),0x80);
            local_35 = FUN_08023108(param_1[2],(char)param_1[3],*(undefined1 *)((int)param_1 + 0x2f)
                                   );
            if (local_35 == '\0') {
              FUN_08022524((char)param_1[0xc],0x80);
              local_89 = 0;
              do {
                if (*(byte *)(param_1 + 0xc) <= local_89) {
                  (**(code **)(*param_1 + 0x2c))(param_1);
                  *(undefined1 *)((int)param_1 + 0x39) = 1;
                  return '\0';
                }
                if (*(char *)((int)param_1 + (uint)local_89 * 4 + 0x5d) != '\0') {
                  FUN_08022524(*(byte *)((int)param_1 + (uint)local_89 * 4 + 0x5b) & 7,0x80);
                  local_35 = FUN_080231a8(param_1,*(byte *)((int)param_1 + (uint)local_89 * 4 + 0x5b
                                                           ) & 7);
                  if ((local_35 != '\0') && (local_35 != '\x05')) break;
                }
                local_89 = local_89 + 1;
              } while( true );
            }
          }
        }
      }
      else {
        *local_3c = local_40;
      }
LAB_08023eac:
      (**(code **)(*param_1 + 8))(param_1);
      local_11 = local_35;
    }
  }
  else {
    local_11 = -0x27;
  }
  return local_11;
}



// FUNCTION FUN_08023ef4 @ 08023ef4
// XREF 080466a4

undefined1 FUN_08023ef4(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort local_5e;
  byte local_5b;
  byte local_5a;
  undefined1 local_59 [64];
  undefined1 local_19;
  int *local_18;
  undefined1 local_11;
  
  local_19 = 0;
  if ((*(byte *)((int)param_1 + 0x39) & 1) == 0) {
    local_11 = 0;
  }
  else {
    local_18 = param_1;
    iVar3 = FUN_0802503c();
    if (-1 < iVar3 - param_1[0xd]) {
      iVar3 = FUN_0802503c();
      param_1[0xd] = iVar3 + (uint)*(byte *)(param_1 + 0xe);
      for (local_5a = 0; local_5a < *(byte *)(param_1 + 0xc); local_5a = local_5a + 1) {
        local_5b = *(byte *)((int)param_1 + (uint)local_5a * 4 + 0x5d);
        if (local_5b != 0) {
          local_5e = (ushort)*(byte *)((int)param_1 + (uint)local_5b * 3 + 0x3b);
          FUN_08024430(param_1,local_59);
          cVar1 = FUN_08022490(param_1[2],(char)param_1[3],
                               *(undefined1 *)((int)param_1 + (uint)local_5b * 3 + 0x3a),&local_5e,
                               local_59);
          if (cVar1 == '\0') {
            if (local_5e != 0) {
              if (0x40 < local_5e) {
                local_5e = 0x40;
              }
              (**(code **)(*param_1 + 0x30))
                        (param_1,param_1,*(undefined1 *)((int)param_1 + (uint)local_5b * 3 + 0x3a),
                         *(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_5e,local_59);
              uVar2 = local_59[0];
              if ((*(byte *)((int)param_1 + 0x6f) & 1) == 0) {
                uVar2 = 0;
              }
              puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x24))(param_1,uVar2);
              if (puVar4 != (undefined4 *)0x0) {
                (**(code **)*puVar4)
                          (puVar4,param_1,*(byte *)((int)param_1 + 0x6f) & 1,(undefined1)local_5e,
                           local_59);
              }
            }
          }
          else if (cVar1 != '\x04') {
            FUN_08022524(cVar1,0x81);
          }
        }
      }
    }
    local_11 = local_19;
  }
  return local_11;
}



// FUNCTION FUN_08024168 @ 08024168
// XREF 080466c4
// XREF 0804677c

undefined4 FUN_08024168(void)

{
  return 0;
}



// FUNCTION FUN_08024174 @ 08024174
// XREF 080466c8

void FUN_08024174(void)

{
  return;
}



// FUNCTION FUN_08024194 @ 08024194
// XREF 080253dc
// XREF 08027d12
// XREF 08029f8a
// XREF 080466cc
// XREF 08046784
// XREF 0804682c
// XREF 08046a28
// XREF 08046a80
// XREF 08046ad8

byte FUN_08024194(int param_1)

{
  return *(byte *)(param_1 + 0x39) & 1;
}



// FUNCTION FUN_080241a8 @ 080241a8
// XREF 08024372
// XREF 08024c7a
// XREF 080466d0

void FUN_080241a8(int *param_1,undefined1 param_2,byte param_3,byte param_4,char param_5,int param_6
                 )

{
  int iVar1;
  byte *local_18;
  byte local_11;
  
  *(undefined1 *)((int)param_1 + 0x2f) = param_2;
  local_11 = 0;
  local_18 = (byte *)FUN_0802437c(param_1,param_3,param_4,param_5);
  if (local_18 == (byte *)0x0) {
    if (4 < *(byte *)(param_1 + 0xc)) {
      return;
    }
    local_18 = (byte *)((int)param_1 + (uint)*(byte *)(param_1 + 0xc) * 4 + 0x5b);
    *local_18 = param_3 & 7 | *local_18 & 0xf8;
    *local_18 = *local_18 & 199 | (param_4 & 7) << 3;
    *local_18 = *local_18 & 0x3f | param_5 << 6;
    *(char *)(param_1 + 0xc) = (char)param_1[0xc] + '\x01';
  }
  if (((*(byte *)(param_6 + 3) & 3) == 3) && (local_11 = 2, (*(byte *)(param_6 + 2) & 0x80) != 0)) {
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



// FUNCTION FUN_0802486c @ 0802486c
// XREF 08024828

undefined4 * FUN_0802486c(undefined4 *param_1,undefined4 param_2)

{
  FUN_08023ad8(param_1);
  FUN_08024a34(param_1 + 1);
  *param_1 = &PTR_FUN_08023b48_1_08046704;
  param_1[1] = &DAT_08046738;
  param_1[2] = param_2;
  return param_1;
}



// FUNCTION FUN_08024be8 @ 08024be8
// XREF 08046780
// XREF 08046828
// XREF 08046a24
// XREF 08046a7c
// XREF 08046ad4

void FUN_08024be8(int *param_1,undefined4 param_2,undefined4 param_3,byte param_4,undefined1 param_5
                 ,undefined4 param_6)

{
  (**(code **)(*param_1 + 0x40))(param_1,param_2,param_4 & 1,param_5,param_6);
  return;
}



// FUNCTION FUN_08024c24 @ 08024c24
// XREF 08024cee
// XREF 08046788
// XREF 08046830
// XREF 08046a2c
// XREF 08046a84
// XREF 08046adc

void FUN_08024c24(int param_1,char param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5,
                 undefined4 param_6)

{
  if ((*(byte *)(param_1 + 0x31) < 2) || (param_2 == *(char *)(param_1 + 0x2f))) {
    FUN_080241a8(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}



// FUNCTION FUN_08024c84 @ 08024c84
// XREF 0804678c
// XREF 08046834
// XREF 08046a30
// XREF 08046a88
// XREF 08046ae0

undefined4 FUN_08024c84(void)

{
  return 1;
}



// FUNCTION FUN_08024c98 @ 08024c98
// XREF 08046790

void FUN_08024c98(void)

{
  return;
}



// FUNCTION FUN_08024cb0 @ 08024cb0
// XREF 0804679c
// XREF 08046844
// XREF 08046a40
// XREF 08046a98
// XREF 08046af0

void FUN_08024cb0(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined4 param_6)

{
  FUN_08024c24(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// FUNCTION FUN_08045aec @ 08045aec
// XREF 08020262

void FUN_08045aec(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)(DAT_08045b0c + 0x8045af8);
  for (piVar1 = (int *)(DAT_08045b08 + 0x8045af4); piVar1 != piVar2; piVar1 = piVar1 + 1) {
    (*(code *)(*piVar1 + (int)piVar1))();
  }
  return;
}



// FUNCTION FUN_080465f4 @ 080465f4
// XREF 0802024e

uint FUN_080465f4(void)

{
  uint in_fpscr;
  
  return in_fpscr & 0xfc3f0000 | 0x3000000;
}


