
// FUNCTION FUN_08028434 @ 08028434
// XREF 0802c4e0

void FUN_08028434(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_200008e8,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_08047104;
  puVar1[1] = &DAT_08047150;
  *(undefined1 *)((int)puVar1 + 0x157) = 1;
  return;
}



// FUNCTION FUN_0802847c @ 0802847c
// XREF 08028ec8

void FUN_0802847c(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  for (local_5 = 0; local_5 < 2; local_5 = local_5 + 1) {
    *(undefined1 *)(param_1 + 0x10 + (uint)local_5 * 8) = 0;
    *(undefined4 *)(param_1 + 0x10 + (uint)local_5 * 8 + 4) = 0;
  }
  for (local_6 = 0; local_6 < 5; local_6 = local_6 + 1) {
    *(undefined1 *)(param_1 + 0x20 + (uint)local_6 * 3) = 0;
    *(undefined2 *)(param_1 + 0x20 + (uint)local_6 * 3 + 1) = 0;
  }
  for (local_7 = 0; local_7 < 5; local_7 = local_7 + 1) {
    iVar1 = param_1 + 0x5b;
    *(byte *)(iVar1 + (uint)local_7 * 4) = *(byte *)(iVar1 + (uint)local_7 * 4) & 0xf8;
    *(byte *)(iVar1 + (uint)local_7 * 4) = *(byte *)(iVar1 + (uint)local_7 * 4) & 0x3f;
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      *(undefined1 *)(param_1 + (uint)local_7 * 4 + (uint)local_8 + 0x5c) = 0;
    }
  }
  for (local_9 = 0; local_9 < 0xb; local_9 = local_9 + 1) {
    iVar1 = param_1 + 0x3a;
    *(undefined1 *)(iVar1 + (uint)local_9 * 3) = 0;
    *(char *)((uint)local_9 * 3 + iVar1 + 1) = (local_9 == 0) << 3;
    iVar2 = (uint)local_9 * 3 + iVar1;
    *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) & 0xfe;
    iVar2 = (uint)local_9 * 3 + iVar1;
    *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) & 0xfd;
    cVar3 = '\x0f';
    if (local_9 != 0) {
      cVar3 = '\x01';
    }
    iVar1 = iVar1 + (uint)local_9 * 3;
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 3 | cVar3 << 2;
  }
  *(undefined1 *)(param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  *(undefined1 *)(param_1 + 0x38) = 0;
  return;
}



// FUNCTION FUN_080289ac @ 080289ac

char FUN_080289ac(int *param_1,undefined1 param_2,undefined1 param_3,byte param_4)

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
  local_48 = (int *)FUN_0802ade0(param_1[2]);
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
      local_35 = FUN_0802aa38(param_1[2],0,8,local_2e);
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
        local_35 = FUN_0802b51c(param_1[2],(char)param_1[3]);
        if (local_35 != '\0') {
          *(undefined1 *)((int)local_3c + 6) = 0;
          (**(code **)(*local_48 + 8))(local_48,(char)param_1[3]);
          *(undefined1 *)(param_1 + 3) = 0;
          FUN_08024744(local_35,0x80);
          return local_35;
        }
        FUN_08024744((char)param_1[3],0x80);
        *(undefined1 *)((int)local_3c + 6) = 0;
        local_3c = (int *)(**(code **)*local_48)(local_48,(char)param_1[3]);
        if (local_3c == (int *)0x0) {
          return -0x2a;
        }
        *(byte *)((int)local_3c + 6) = local_1b & 1;
        if (local_41 != 0) {
          local_35 = FUN_0802aa38(param_1[2],(char)param_1[3],local_41,local_2e);
        }
        if (local_35 == '\0') {
          *(undefined2 *)((int)param_1 + 0x72) = *(undefined2 *)(local_34 + 8);
          *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(local_34 + 10);
          local_42 = local_34[0x11];
          local_35 = FUN_0802ae6c(param_1[2],(char)param_1[3],1,(int)param_1 + 0x3a);
          if (local_35 == '\0') {
            FUN_08024744(local_42,0x80);
            for (local_49 = 0; local_49 < local_42; local_49 = local_49 + 1) {
              FUN_08029f1c(auStack_88,param_1 + 1);
              local_35 = FUN_0802aaf0(param_1[2],(char)param_1[3],local_49,auStack_88);
              if (local_35 != '\0') goto LAB_08028cbe;
              local_35 = '\0';
              if (1 < *(byte *)((int)param_1 + 0x31)) break;
            }
            if (*(byte *)((int)param_1 + 0x31) < 2) {
              return -0x2f;
            }
            local_35 = FUN_0802ae6c(param_1[2],(char)param_1[3],*(undefined1 *)((int)param_1 + 0x31)
                                    ,(int)param_1 + 0x3a);
            FUN_08024744(*(undefined1 *)((int)param_1 + 0x2f),0x80);
            local_35 = FUN_0802b56c(param_1[2],(char)param_1[3],*(undefined1 *)((int)param_1 + 0x2f)
                                   );
            if (local_35 == '\0') {
              FUN_08024744((char)param_1[0xc],0x80);
              local_89 = 0;
              do {
                if (*(byte *)(param_1 + 0xc) <= local_89) {
                  FUN_0802b61c(param_1);
                  (**(code **)(*param_1 + 0x2c))(param_1);
                  *(undefined1 *)((int)param_1 + 0x39) = 1;
                  return '\0';
                }
                if (*(char *)((int)param_1 + (uint)local_89 * 4 + 0x5d) != '\0') {
                  FUN_08024744(*(byte *)((int)param_1 + (uint)local_89 * 4 + 0x5b) & 7,0x80);
                  local_35 = FUN_0802b690(param_1,*(byte *)((int)param_1 + (uint)local_89 * 4 + 0x5b
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
LAB_08028cbe:
      (**(code **)(*param_1 + 8))(param_1);
      local_11 = local_35;
    }
  }
  else {
    local_11 = -0x27;
  }
  return local_11;
}



// FUNCTION FUN_08028e50 @ 08028e50

undefined4 FUN_08028e50(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0802ade0(*(undefined4 *)(param_1 + 8));
  (**(code **)(*piVar1 + 8))(piVar1,*(undefined1 *)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x39) = 0;
  return 0;
}



// FUNCTION FUN_08028e7c @ 08028e7c
// XREF 080292ea
// XREF 08029562
// XREF 08029baa
// XREF 08043be0

byte FUN_08028e7c(int param_1)

{
  return *(byte *)(param_1 + 0x39) & 1;
}



// FUNCTION FUN_08028e90 @ 08028e90
// XREF 08029118

undefined4 * FUN_08028e90(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802b738(param_1,param_2);
  *param_1 = &PTR_FUN_080289ac_1_0804715c;
  param_1[1] = &DAT_080471a4;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  *(undefined1 *)((int)param_1 + 0x6f) = 0;
  FUN_0802847c(param_1);
  if (param_1[2] != 0) {
    FUN_0802afa4(param_1[2],param_1);
  }
  return param_1;
}



// FUNCTION FUN_08028efc @ 08028efc

void FUN_08028efc(int *param_1,undefined4 param_2,undefined4 param_3,byte param_4,undefined1 param_5
                 ,undefined4 param_6)

{
  (**(code **)(*param_1 + 0x40))(param_1,param_2,param_4 & 1,param_5,param_6);
  return;
}



// FUNCTION FUN_08028f3c @ 08028f3c
// XREF 0802c41e

void FUN_08028f3c(int param_1,char param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5,
                 undefined4 param_6)

{
  if ((*(byte *)(param_1 + 0x31) < 2) || (param_2 == *(char *)(param_1 + 0x2f))) {
    FUN_08028724(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}



// FUNCTION FUN_08028fb0 @ 08028fb0

char FUN_08028fb0(int *param_1)

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
    iVar3 = FUN_08043c60();
    if (-1 < iVar3 - param_1[0xd]) {
      iVar3 = FUN_08043c60();
      param_1[0xd] = iVar3 + (uint)*(byte *)(param_1 + 0xe);
      for (local_5a = 0; local_5a < *(byte *)(param_1 + 0xc); local_5a = local_5a + 1) {
        local_5b = *(byte *)((int)param_1 + (uint)local_5a * 4 + 0x5d);
        local_5e = (ushort)*(byte *)((int)param_1 + (uint)local_5b * 3 + 0x3b);
        FUN_08028610(param_1,local_59);
        cVar1 = FUN_0802a36c(param_1[2],(char)param_1[3],
                             *(undefined1 *)((int)param_1 + (uint)local_5b * 3 + 0x3a),&local_5e,
                             local_59);
        if (cVar1 != '\0') {
          if (cVar1 == '\x04') {
            return '\x04';
          }
          FUN_08024744(cVar1,0x81);
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



// FUNCTION FUN_0802910c @ 0802910c
// XREF 08024a34
// XREF 0802933c
// XREF 080295f0
// XREF 08029c18
// XREF 08028450

void FUN_0802910c(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08028e90(param_1,param_2);
  *puVar1 = &PTR_FUN_080289ac_1_080471b0;
  puVar1[1] = &DAT_080471fc;
  return;
}



// FUNCTION FUN_08029320 @ 08029320
// XREF 0802c4ec

void FUN_08029320(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_2000267c,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_08047214;
  puVar1[1] = &DAT_08047260;
  return;
}



// FUNCTION FUN_080295d4 @ 080295d4
// XREF 0802c4f0

void FUN_080295d4(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_20004128,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_0804726c;
  puVar1[1] = &DAT_080472b8;
  *(undefined1 *)(puVar1 + 0x2e) = 9;
  *(undefined1 *)((int)puVar1 + 0xb9) = 0xd;
  return;
}



// FUNCTION FUN_08029bfc @ 08029bfc
// XREF 0802c4e8

void FUN_08029bfc(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0802910c(&DAT_200025c0,&DAT_20004488);
  *puVar1 = &PTR_FUN_080289ac_1_080472d8;
  puVar1[1] = &DAT_08047324;
  return;
}



// FUNCTION FUN_0802afa4 @ 0802afa4
// XREF 08028ed6
// XREF 0802c008

void FUN_0802afa4(int param_1,undefined4 param_2)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xf < local_d) {
      return;
    }
    if (*(int *)(param_1 + (uint)local_d * 4 + 0x78) == 0) break;
    local_d = local_d + 1;
  }
  *(undefined4 *)(param_1 + (uint)local_d * 4 + 0x78) = param_2;
  return;
}



// FUNCTION FUN_0802b738 @ 0802b738
// XREF 08028ea0

undefined4 * FUN_0802b738(undefined4 *param_1,undefined4 param_2)

{
  FUN_08029cc8(param_1);
  FUN_08029fc0(param_1 + 1);
  *param_1 = &PTR_LAB_08029c84_1_08047374;
  param_1[1] = &DAT_080473a8;
  param_1[2] = param_2;
  return param_1;
}



// FUNCTION FUN_0802c3e0 @ 0802c3e0

void FUN_0802c3e0(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined4 param_6)

{
  FUN_08028f3c(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}


