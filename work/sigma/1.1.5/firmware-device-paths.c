Program sigma-decoded.bin language=ARM:LE:32:Cortex

// FUNCTION FUN_0802503c @ 0802503c

undefined4 FUN_0802503c(void)

{
  return DAT_2000081c;
}



// FUNCTION FUN_08025048 @ 08025048

void FUN_08025048(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_10 = FUN_08024fd8();
  local_c = param_1;
  if (param_1 != 0) {
    while( true ) {
      do {
        iVar1 = FUN_08024fd8();
      } while ((uint)(iVar1 - local_10) < 0x3e9);
      local_c = local_c + -1;
      if (local_c == 0) break;
      local_10 = local_10 + 1000;
    }
  }
  return;
}



// FUNCTION FUN_0802508c @ 0802508c

void FUN_0802508c(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_08024fd8();
  do {
    uVar2 = FUN_08024fd8();
  } while (uVar2 < iVar1 + 100U);
  return;
}



// FUNCTION FUN_080250b4 @ 080250b4

void FUN_080250b4(void)

{
  undefined4 local_8;
  
  for (local_8 = 5000; local_8 != 0; local_8 = local_8 + -1) {
  }
  return;
}



// FUNCTION FUN_080250d8 @ 080250d8

int FUN_080250d8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802503c();
  return iVar1 - param_1;
}



// FUNCTION FUN_080250ec @ 080250ec

void FUN_080250ec(void)

{
  FUN_08025108();
  FUN_08025118();
  FUN_08025130();
  FUN_08025138();
  FUN_08025140();
  FUN_08025148();
  return;
}



// FUNCTION FUN_08025108 @ 08025108

void FUN_08025108(void)

{
  FUN_0802157c(&DAT_20000820);
  return;
}



// FUNCTION FUN_08025118 @ 08025118

void FUN_08025118(void)

{
  FUN_08023a58(&DAT_200008dc,&DAT_20000820);
  return;
}



// FUNCTION FUN_08025130 @ 08025130

void FUN_08025130(void)

{
  FUN_08025220();
  return;
}



// FUNCTION FUN_08025138 @ 08025138

void FUN_08025138(void)

{
  FUN_080251e8();
  return;
}



// FUNCTION FUN_08025140 @ 08025140

void FUN_08025140(void)

{
  FUN_080251b0();
  return;
}



// FUNCTION FUN_08025148 @ 08025148

void FUN_08025148(void)

{
  FUN_08025150();
  return;
}



// FUNCTION FUN_08025150 @ 08025150

void FUN_08025150(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_20000bc4,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_08046aa4;
  puVar1[1] = &PTR_FUN_08024cb0_1_08046af0;
  return;
}



// FUNCTION FUN_08025188 @ 08025188

void FUN_08025188(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08024818(param_1,param_2);
  *puVar1 = &PTR_FUN_08023ba0_1_08046750;
  puVar1[1] = &DAT_0804679c;
  return;
}



// FUNCTION FUN_080251b0 @ 080251b0

void FUN_080251b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_20000b0c,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_080469f4;
  puVar1[1] = &DAT_08046a40;
  return;
}



// FUNCTION FUN_080251e8 @ 080251e8

void FUN_080251e8(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_20000a94,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_08046a4c;
  puVar1[1] = &DAT_08046a98;
  return;
}



// FUNCTION FUN_08025220 @ 08025220

void FUN_08025220(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_08025188(&DAT_200008f4,&DAT_20000820);
  *puVar1 = &PTR_FUN_08023ba0_1_080467f8;
  puVar1[1] = &DAT_08046844;
  *(undefined1 *)((int)puVar1 + 0x157) = 1;
  return;
}



// FUNCTION FUN_0802525c @ 0802525c

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



// FUNCTION FUN_080253f8 @ 080253f8

int FUN_080253f8(void)

{
  int iVar1;
  char local_9;
  
  FUN_08025490();
  FUN_08021c60();
  FUN_080254b8();
  FUN_080254bc();
  FUN_08021be8(&DAT_20000820,0x88,0x18);
  iVar1 = FUN_080254e4(&DAT_20000820);
  if (iVar1 == 0) {
    local_9 = -1;
  }
  else {
    FUN_08021be8(&DAT_20000820,0xd8,0xc1);
    FUN_08021be8(&DAT_20000820,0xd0,0x60);
    FUN_08021be8(&DAT_20000820,0xe8,4);
    do {
      iVar1 = FUN_08021c20(&DAT_20000820,0xe8);
    } while (-1 < iVar1 * 0x20000000);
    FUN_08022e9c(&DAT_20000820);
    FUN_08021be8(&DAT_20000820,200,0x20);
    FUN_08021be8(&DAT_20000820,0x80,1);
    local_9 = '\0';
  }
  return (int)local_9;
}



// FUNCTION FUN_08025490 @ 08025490

void FUN_08025490(void)

{
  DAT_20000c80 = 0x1000;
  DAT_20000c83 = 0x10;
  DAT_20000c82 = 1;
  FUN_08020ae8(0x40010c00);
  return;
}



// FUNCTION FUN_080254b8 @ 080254b8

void FUN_080254b8(void)

{
  return;
}



// FUNCTION FUN_080254bc @ 080254bc

void FUN_080254bc(void)

{
  DAT_20000c7c = 0x800;
  DAT_20000c7f = 4;
  DAT_20000c7e = 1;
  FUN_08020ae8(0x40010c00);
  return;
}



// FUNCTION FUN_080254e4 @ 080254e4

short FUN_080254e4(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  short local_e;
  
  local_e = 0;
  FUN_08021be8(param_1,0x78,0x20);
  FUN_08021be8(param_1,0x78,0);
  do {
    sVar1 = local_e + 1;
    if (local_e == -1) {
      return 0;
    }
    uVar2 = FUN_08021c20(param_1,0x68);
    local_e = sVar1;
  } while ((uVar2 & 1) == 0);
  return sVar1;
}



// FUNCTION FUN_08025538 @ 08025538

void FUN_08025538(void)

{
  return;
}



// FUNCTION thunk_FUN_0802553e @ 0802553c

void thunk_FUN_0802553e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802553e @ 0802553e

void FUN_0802553e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION thunk_FUN_08025542 @ 08025540

void thunk_FUN_08025542(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_08025542 @ 08025542

void FUN_08025542(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION thunk_FUN_08025546 @ 08025544

void thunk_FUN_08025546(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_08025546 @ 08025546

void FUN_08025546(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION thunk_FUN_0802554a @ 08025548

void thunk_FUN_0802554a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802554a @ 0802554a

void FUN_0802554a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802554c @ 0802554c

void FUN_0802554c(void)

{
  return;
}



// FUNCTION FUN_08025550 @ 08025550

void FUN_08025550(void)

{
  return;
}



// FUNCTION FUN_08025554 @ 08025554

void FUN_08025554(void)

{
  FUN_0802ad3c();
  return;
}



// FUNCTION FUN_0802555c @ 0802555c

uint FUN_0802555c(int param_1,uint param_2,char *param_3,uint *param_4)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  bool bVar8;
  uint local_70;
  char *local_6c;
  uint local_68;
  undefined4 local_4c;
  uint local_40;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  char *local_2c;
  uint local_28;
  int local_24;
  code *local_20;
  uint *local_1c;
  
  local_20 = (code *)&LAB_08026f2c_1;
  local_40 = 0;
  local_2c = param_3;
  local_28 = param_2;
  local_24 = param_1;
  local_1c = param_4;
  if (param_1 == 0) {
    local_20 = (code *)0x8025e65;
  }
  while (*local_2c != '\0') {
    if (*local_2c == '%') {
      local_2c = local_2c + 1;
      local_30 = 0;
      do {
        switch(*local_2c) {
        case ' ':
          local_30 = local_30 | 8;
          local_2c = local_2c + 1;
          bVar8 = true;
          break;
        default:
          bVar8 = false;
          break;
        case '#':
          local_30 = local_30 | 0x10;
          local_2c = local_2c + 1;
          bVar8 = true;
          break;
        case '+':
          local_30 = local_30 | 4;
          local_2c = local_2c + 1;
          bVar8 = true;
          break;
        case '-':
          local_30 = local_30 | 2;
          local_2c = local_2c + 1;
          bVar8 = true;
          break;
        case '0':
          local_30 = local_30 | 1;
          local_2c = local_2c + 1;
          bVar8 = true;
        }
      } while (bVar8);
      local_34 = 0;
      iVar2 = FUN_08025e74(*local_2c);
      if (iVar2 == 0) {
        if (*local_2c == '*') {
          local_34 = *local_1c;
          if (0x7fffffff < local_34) {
            local_30 = local_30 | 2;
            local_34 = -local_34;
          }
          local_2c = local_2c + 1;
          local_1c = local_1c + 1;
        }
      }
      else {
        local_34 = FUN_08025e9c(&local_2c);
      }
      local_38 = 0;
      if (*local_2c == '.') {
        local_30 = local_30 | 0x400;
        local_2c = local_2c + 1;
        iVar2 = FUN_08025e74(*local_2c);
        if (iVar2 == 0) {
          if (*local_2c == '*') {
            local_38 = *local_1c;
            if ((int)local_38 < 1) {
              local_38 = 0;
            }
            local_2c = local_2c + 1;
            local_1c = local_1c + 1;
          }
        }
        else {
          local_38 = FUN_08025e9c(&local_2c);
        }
      }
      switch(*local_2c) {
      case 'h':
        uVar5 = local_30 | 0x80;
        pcVar1 = local_2c + 1;
        if (local_2c[1] == 'h') {
          uVar5 = local_30 | 0xc0;
          pcVar1 = local_2c + 2;
        }
        break;
      default:
        uVar5 = local_30;
        pcVar1 = local_2c;
        break;
      case 'j':
        uVar5 = local_30 | 0x200;
        pcVar1 = local_2c + 1;
        break;
      case 'l':
        uVar5 = local_30 | 0x100;
        pcVar1 = local_2c + 1;
        if (local_2c[1] == 'l') {
          uVar5 = local_30 | 0x300;
          pcVar1 = local_2c + 2;
        }
        break;
      case 't':
        uVar5 = local_30 | 0x100;
        pcVar1 = local_2c + 1;
        break;
      case 'z':
        uVar5 = local_30 | 0x100;
        pcVar1 = local_2c + 1;
      }
      local_2c = pcVar1;
      local_30 = uVar5;
      switch(*local_2c) {
      case '%':
        (*local_20)(0x25,local_24,local_40,local_28);
        local_2c = local_2c + 1;
        local_40 = local_40 + 1;
        break;
      default:
        (*local_20)(*local_2c,local_24,local_40,local_28);
        local_2c = local_2c + 1;
        local_40 = local_40 + 1;
        break;
      case 'E':
      case 'G':
      case 'e':
      case 'g':
        if ((*local_2c == 'g') || (*local_2c == 'G')) {
          local_30 = local_30 | 0x800;
        }
        if ((*local_2c == 'E') || (*local_2c == 'G')) {
          local_30 = local_30 | 0x20;
        }
        puVar7 = (undefined8 *)((uint)((int)local_1c + 7) & 0xfffffff8);
        local_1c = (uint *)(puVar7 + 1);
        local_40 = FUN_08026640((int)*puVar7,local_20,local_24,local_40,local_28,local_38,local_34,
                                local_30);
        local_2c = local_2c + 1;
        break;
      case 'F':
      case 'f':
        if (*local_2c == 'F') {
          local_30 = local_30 | 0x20;
        }
        puVar7 = (undefined8 *)((uint)((int)local_1c + 7) & 0xfffffff8);
        local_1c = (uint *)(puVar7 + 1);
        local_40 = FUN_080260e0((int)*puVar7,local_20,local_24,local_40,local_28,local_38,local_34,
                                local_30);
        local_2c = local_2c + 1;
        break;
      case 'X':
      case 'b':
      case 'd':
      case 'i':
      case 'o':
      case 'u':
      case 'x':
        if ((*local_2c == 'x') || (*local_2c == 'X')) {
          local_4c = 0x10;
        }
        else if (*local_2c == 'o') {
          local_4c = 8;
        }
        else if (*local_2c == 'b') {
          local_4c = 2;
        }
        else {
          local_4c = 10;
          local_30 = local_30 & 0xffffffef;
        }
        if (*local_2c == 'X') {
          local_30 = local_30 | 0x20;
        }
        if ((*local_2c != 'i') && (*local_2c != 'd')) {
          local_30 = local_30 & 0xfffffff3;
        }
        if ((int)((local_30 >> 8) * 0x20000000) < 0) {
          local_30 = local_30 & 0xfffffffe;
        }
        if ((*local_2c == 'i') || (*local_2c == 'd')) {
          if ((int)((uint)local_30._1_1_ * 0x40000000) < 0) {
            piVar3 = (int *)((uint)((int)local_1c + 7) & 0xfffffff8);
            local_1c = (uint *)(piVar3 + 2);
            iVar2 = *piVar3;
            uVar4 = piVar3[1];
            uVar5 = uVar4;
            if ((int)uVar4 < (int)(uint)(iVar2 == 0)) {
              bVar8 = iVar2 != 0;
              iVar2 = -iVar2;
              uVar5 = -(uint)bVar8 - uVar4;
            }
            local_40 = FUN_08025ed8(local_20,local_24,local_40,local_28,iVar2,uVar5,uVar4 >> 0x1f);
          }
          else if ((local_30 & 0x100) == 0) {
            if ((int)(local_30 * 0x2000000) < 0) {
              uVar5 = (uint)(byte)*local_1c;
            }
            else if ((int)(local_30 * 0x1000000) < 0) {
              uVar5 = (uint)(short)(ushort)*local_1c;
            }
            else {
              uVar5 = *local_1c;
            }
            local_1c = local_1c + 1;
            uVar4 = uVar5;
            if ((int)uVar5 < 1) {
              uVar4 = -uVar5;
            }
            local_40 = FUN_08025fe4(local_20,local_24,local_40,local_28,uVar4,uVar5 >> 0x1f,local_4c
                                    ,local_38,local_34,local_30);
          }
          else {
            uVar4 = *local_1c;
            uVar5 = uVar4;
            if ((int)uVar4 < 1) {
              uVar5 = -uVar4;
            }
            local_1c = local_1c + 1;
            local_40 = FUN_08025fe4(local_20,local_24,local_40,local_28,uVar5,uVar4 >> 0x1f,local_4c
                                    ,local_38,local_34,local_30);
          }
        }
        else if ((int)((uint)local_30._1_1_ * 0x40000000) < 0) {
          puVar6 = (undefined4 *)((uint)((int)local_1c + 7) & 0xfffffff8);
          local_1c = puVar6 + 2;
          local_40 = FUN_08025ed8(local_20,local_24,local_40,local_28,*puVar6,puVar6[1],0);
        }
        else if ((local_30 & 0x100) == 0) {
          if ((int)(local_30 * 0x2000000) < 0) {
            uVar5 = (uint)(byte)*local_1c;
          }
          else if ((int)(local_30 * 0x1000000) < 0) {
            uVar5 = (uint)(ushort)*local_1c;
          }
          else {
            uVar5 = *local_1c;
          }
          local_1c = local_1c + 1;
          local_40 = FUN_08025fe4(local_20,local_24,local_40,local_28,uVar5,0,local_4c,local_38,
                                  local_34,local_30);
        }
        else {
          uVar5 = *local_1c;
          local_1c = local_1c + 1;
          local_40 = FUN_08025fe4(local_20,local_24,local_40,local_28,uVar5,0,local_4c,local_38,
                                  local_34,local_30);
        }
        local_2c = local_2c + 1;
        break;
      case 'c':
        local_68 = 1;
        if (-1 < (int)(local_30 * 0x40000000)) {
          while (uVar5 = local_68 + 1, bVar8 = local_68 < local_34, local_68 = uVar5, bVar8) {
            (*local_20)(0x20,local_24,local_40,local_28);
            local_40 = local_40 + 1;
          }
        }
        uVar4 = local_40 + 1;
        uVar5 = *local_1c;
        local_1c = local_1c + 1;
        (*local_20)((byte)uVar5,local_24,local_40,local_28);
        local_40 = uVar4;
        if ((int)(local_30 * 0x40000000) < 0) {
          while (local_68 < local_34) {
            (*local_20)(0x20,local_24,local_40,local_28);
            local_68 = local_68 + 1;
            local_40 = local_40 + 1;
          }
        }
        local_2c = local_2c + 1;
        break;
      case 'p':
        uVar5 = *local_1c;
        local_1c = local_1c + 1;
        local_40 = FUN_08025fe4(local_20,local_24,local_40,local_28,uVar5,0,0x10,local_38,8,
                                local_30 | 0x21);
        local_2c = local_2c + 1;
        break;
      case 's':
        local_6c = (char *)*local_1c;
        uVar5 = local_38;
        if (local_38 == 0) {
          uVar5 = 0xffffffff;
        }
        local_1c = local_1c + 1;
        uVar5 = FUN_08026bf8(local_6c,uVar5);
        local_70 = uVar5;
        if (((int)((local_30 >> 8) * 0x20000000) < 0) && (local_70 = local_38, uVar5 < local_38)) {
          local_70 = uVar5;
        }
        if (-1 < (int)(local_30 * 0x40000000)) {
          while (uVar5 = local_70 + 1, bVar8 = local_70 < local_34, local_70 = uVar5, bVar8) {
            (*local_20)(0x20,local_24,local_40,local_28);
            local_40 = local_40 + 1;
          }
        }
        while( true ) {
          bVar8 = false;
          if ((*local_6c != '\0') && (bVar8 = true, (int)((local_30 >> 8) * 0x20000000) < 0)) {
            bVar8 = local_38 != 0;
            local_38 = local_38 - 1;
          }
          if (!bVar8) break;
          (*local_20)(*local_6c,local_24,local_40,local_28);
          local_6c = local_6c + 1;
          local_40 = local_40 + 1;
        }
        if ((int)(local_30 * 0x40000000) < 0) {
          while (local_70 < local_34) {
            (*local_20)(0x20,local_24,local_40,local_28);
            local_70 = local_70 + 1;
            local_40 = local_40 + 1;
          }
        }
        local_2c = local_2c + 1;
      }
    }
    else {
      (*local_20)(*local_2c,local_24,local_40,local_28);
      local_2c = local_2c + 1;
      local_40 = local_40 + 1;
    }
  }
  uVar5 = local_40;
  if (local_28 <= local_40) {
    uVar5 = local_28 - 1;
  }
  (*local_20)(0,local_24,uVar5,local_28);
  return local_40;
}



// FUNCTION FUN_08025e64 @ 08025e64

void FUN_08025e64(void)

{
  return;
}



// FUNCTION FUN_08025e74 @ 08025e74

bool FUN_08025e74(byte param_1)

{
  return 0x2f < param_1 && param_1 < 0x3a;
}



// FUNCTION FUN_08025e9c @ 08025e9c

int FUN_08025e9c(undefined4 *param_1)

{
  int iVar1;
  byte *pbVar2;
  int local_10;
  
  local_10 = 0;
  while (iVar1 = FUN_08025e74(*(undefined1 *)*param_1), iVar1 != 0) {
    pbVar2 = (byte *)*param_1;
    *param_1 = pbVar2 + 1;
    local_10 = (uint)*pbVar2 + local_10 * 10 + -0x30;
  }
  return local_10;
}



// FUNCTION FUN_08025ed8 @ 08025ed8

void FUN_08025ed8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,byte param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  longlong lVar1;
  char cVar2;
  byte extraout_r2;
  uint uVar3;
  longlong lVar4;
  uint local_84;
  char acStack_80 [64];
  undefined4 local_40;
  undefined4 local_3c;
  byte local_31;
  undefined8 local_30;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  lVar4 = CONCAT44(param_6,param_5);
  local_31 = param_7;
  local_3c = param_10;
  local_40 = param_9;
  local_84 = 0;
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  local_24 = param_4;
  local_20 = param_3;
  local_1c = param_2;
  local_18 = param_1;
  lVar1 = CONCAT44(param_6,param_5);
  if ((-1 < (int)((param_13 >> 8) * 0x20000000)) ||
     (lVar1 = CONCAT44(param_6,param_5), param_5 != 0 || param_6 != 0)) {
    do {
      local_30._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
      local_30._0_4_ = (undefined4)lVar1;
      FUN_080459ba((undefined4)local_30,local_30._4_4_,local_40,local_3c);
      local_30 = lVar1;
      if (extraout_r2 < 10) {
        cVar2 = extraout_r2 + 0x30;
      }
      else {
        cVar2 = 'a';
        if ((int)(param_13 * 0x4000000) < 0) {
          cVar2 = 'A';
        }
        cVar2 = extraout_r2 + cVar2 + -10;
      }
      uVar3 = local_84 + 1;
      acStack_80[local_84] = cVar2;
      lVar4 = FUN_080459ba((undefined4)local_30,local_30._4_4_,local_40,local_3c);
      local_84 = uVar3;
      lVar1 = lVar4;
    } while (lVar4 != 0 && uVar3 < 0x40);
  }
  local_30 = lVar4;
  FUN_08026cfc(local_18,local_1c,local_20,local_24,acStack_80,local_84,local_31 & 1,local_40,
               param_11,param_12,param_13);
  return;
}



// FUNCTION FUN_08025fe4 @ 08025fe4

void FUN_08025fe4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,byte param_6,uint param_7,undefined4 param_8,undefined4 param_9,
                 uint param_10)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint local_6c;
  char acStack_65 [64];
  byte local_25;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_25 = param_6;
  local_6c = 0;
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  local_24 = param_4;
  local_20 = param_3;
  local_1c = param_2;
  local_18 = param_1;
  if ((-1 < (int)((param_10 >> 8) * 0x20000000)) || (param_5 != 0)) {
    do {
      bVar1 = (char)param_5 - (char)(param_5 / param_7) * (char)param_7;
      if (bVar1 < 10) {
        cVar2 = bVar1 + 0x30;
      }
      else {
        cVar2 = 'a';
        if ((int)(param_10 * 0x4000000) < 0) {
          cVar2 = 'A';
        }
        cVar2 = bVar1 + cVar2 + -10;
      }
      uVar3 = local_6c + 1;
      acStack_65[local_6c] = cVar2;
      param_5 = param_5 / param_7;
      local_6c = uVar3;
    } while (param_5 != 0 && uVar3 < 0x40);
  }
  FUN_08026cfc(local_18,local_1c,local_20,local_24,acStack_65,local_6c,local_25 & 1,param_7,param_8,
               param_9,param_10);
  return;
}



// FUNCTION FUN_080260e0 @ 080260e0

undefined4
FUN_080260e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,uint param_6,uint param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined8 in_d0;
  undefined8 uVar7;
  undefined8 uVar8;
  uint local_a0;
  uint local_9c;
  uint local_90;
  uint local_7c;
  byte abStack_78 [64];
  undefined8 local_38;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_7c = 0;
  local_38._0_4_ = (undefined4)in_d0;
  local_38._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
  uVar7 = in_d0;
  local_2c = param_4;
  local_28 = param_3;
  local_24 = param_2;
  local_20 = param_1;
  iVar2 = FUN_080465a0((undefined4)local_38,local_38._4_4_,(undefined4)local_38,local_38._4_4_);
  local_38 = uVar7;
  if (iVar2 == 0) {
    local_1c = FUN_08026c38(local_20,local_24,local_28,local_2c,&LAB_0804dee6,3,param_6,param_7);
  }
  else {
    iVar2 = FUN_080465ca((undefined4)local_38,local_38._4_4_,(int)DAT_080264a0,
                         (int)((ulonglong)DAT_080264a0 >> 0x20));
    if (iVar2 == 0) {
      local_1c = FUN_08026c38(local_20,local_24,local_28,local_2c,&DAT_0804dded,4,param_6,param_7);
    }
    else {
      iVar2 = FUN_080465d8((undefined4)local_38,local_38._4_4_,(int)DAT_080264a8,
                           (int)((ulonglong)DAT_080264a8 >> 0x20));
      if (iVar2 == 0) {
        puVar6 = &DAT_0804dea8;
        if ((param_7 & 4) != 0) {
          puVar6 = &DAT_0804dde8;
        }
        uVar5 = 3;
        if ((param_7 & 4) != 0) {
          uVar5 = 4;
        }
        local_1c = FUN_08026c38(local_20,local_24,local_28,local_2c,puVar6,uVar5,param_6,param_7);
      }
      else {
        iVar2 = FUN_080465bc((undefined4)local_38,local_38._4_4_,(int)DAT_080264b0,
                             (int)((ulonglong)DAT_080264b0 >> 0x20));
        if (iVar2 == 0) {
          iVar2 = FUN_080465ca((undefined4)local_38,local_38._4_4_,(int)DAT_080264b8,
                               (int)((ulonglong)DAT_080264b8 >> 0x20));
          if (iVar2 != 0) {
            iVar2 = FUN_080465ca((undefined4)local_38,local_38._4_4_,(int)DAT_080264c0,
                                 (int)((ulonglong)DAT_080264c0 >> 0x20));
            bVar1 = iVar2 == 0;
            if (bVar1) {
              local_38 = FUN_080463cc((int)DAT_080264c8,(int)((ulonglong)DAT_080264c8 >> 0x20),
                                      (int)local_38,(int)((ulonglong)local_38 >> 0x20));
            }
            if (-1 < (int)((param_7 >> 8) * 0x20000000)) {
              param_5 = 6;
            }
            for (; local_7c < 0x40 && 9 < param_5; param_5 = param_5 - 1) {
              abStack_78[local_7c] = 0x30;
              local_7c = local_7c + 1;
            }
            local_90 = FUN_08045fd0((int)local_38,(int)((ulonglong)local_38 >> 0x20));
            uVar7 = local_38;
            uVar8 = FUN_0804608a(local_90);
            uVar8 = FUN_080463cc((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                                 (int)((ulonglong)uVar8 >> 0x20));
            uVar7 = *(undefined8 *)(param_5 * 8 + 0x80467a0);
            uVar7 = FUN_080461d0((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                                 (int)((ulonglong)uVar7 >> 0x20));
            uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
            local_9c = FUN_08046030((int)uVar7,uVar5);
            uVar8 = FUN_080460b8(local_9c);
            uVar7 = FUN_080463cc((int)uVar7,uVar5,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
            uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
            iVar2 = FUN_080465d8((int)uVar7,uVar5,(int)DAT_08026638,
                                 (int)((ulonglong)DAT_08026638 >> 0x20));
            if (iVar2 == 0) {
              local_9c = local_9c + 1;
              uVar8 = FUN_080460b8(local_9c);
              uVar7 = *(undefined8 *)(param_5 * 8 + 0x80467a0);
              iVar2 = FUN_080465e6((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                                   (int)((ulonglong)uVar7 >> 0x20));
              if (iVar2 == 0) {
                local_9c = 0;
                local_90 = local_90 + 1;
              }
            }
            else {
              iVar2 = FUN_080465ca((int)uVar7,uVar5,(int)DAT_08026638,
                                   (int)((ulonglong)DAT_08026638 >> 0x20));
              if ((iVar2 != 0) && ((local_9c == 0 || ((local_9c & 1) != 0)))) {
                local_9c = local_9c + 1;
              }
            }
            uVar7 = local_38;
            if (param_5 == 0) {
              uVar8 = FUN_0804608a(local_90);
              uVar7 = FUN_080463cc((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                                   (int)((ulonglong)uVar8 >> 0x20));
              uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
              iVar2 = FUN_080465ca((int)uVar7,uVar5,(int)DAT_08026638,
                                   (int)((ulonglong)DAT_08026638 >> 0x20));
              if (((iVar2 != 0) ||
                  (iVar2 = FUN_080465d8((int)uVar7,uVar5,(int)DAT_08026638,
                                        (int)((ulonglong)DAT_08026638 >> 0x20)), iVar2 == 0)) &&
                 ((local_90 & 1) != 0)) {
                local_90 = local_90 + 1;
              }
            }
            else {
              local_a0 = param_5;
              do {
                if (0x3f < local_7c) break;
                local_a0 = local_a0 - 1;
                uVar3 = local_7c + 1;
                abStack_78[local_7c] = (char)local_9c + (char)(local_9c / 10) * -10 | 0x30;
                uVar4 = local_9c / 10;
                local_9c = local_9c / 10;
                local_7c = uVar3;
              } while (uVar4 != 0);
              while( true ) {
                uVar4 = local_a0;
                if (local_7c < 0x40) {
                  local_a0 = local_a0 - 1;
                }
                if (local_7c >= 0x40 || uVar4 == 0) break;
                abStack_78[local_7c] = 0x30;
                local_7c = local_7c + 1;
              }
              if (local_7c < 0x40) {
                abStack_78[local_7c] = 0x2e;
                local_7c = local_7c + 1;
              }
            }
            do {
              if (0x3f < local_7c) break;
              uVar4 = local_7c + 1;
              abStack_78[local_7c] =
                   (char)local_90 +
                   ((char)(uint)((ulonglong)((longlong)(int)local_90 * 0x66666667) >> 0x22) -
                   (char)((longlong)(int)local_90 * 0x66666667 >> 0x3f)) * -10 + 0x30;
              local_90 = (int)local_90 / 10;
              local_7c = uVar4;
            } while (local_90 != 0);
            if ((-1 < (int)(param_7 * 0x40000000)) && ((param_7 & 1) != 0)) {
              if ((param_6 != 0) && ((bVar1 || ((param_7 & 0xc) != 0)))) {
                param_6 = param_6 - 1;
              }
              while (local_7c < param_6 && local_7c < 0x40) {
                abStack_78[local_7c] = 0x30;
                local_7c = local_7c + 1;
              }
            }
            if (local_7c < 0x40) {
              if (bVar1) {
                abStack_78[local_7c] = 0x2d;
                local_7c = local_7c + 1;
              }
              else if ((int)(param_7 * 0x20000000) < 0) {
                abStack_78[local_7c] = 0x2b;
                local_7c = local_7c + 1;
              }
              else if ((int)(param_7 * 0x10000000) < 0) {
                abStack_78[local_7c] = 0x20;
                local_7c = local_7c + 1;
              }
            }
            uVar5 = FUN_08026c38(local_20,local_24,local_28,local_2c,abStack_78,local_7c,param_6,
                                 param_7);
            return uVar5;
          }
        }
        local_1c = FUN_08026640((int)local_38,local_20,local_24,local_28,local_2c,param_5,param_6,
                                param_7);
      }
    }
  }
  return local_1c;
}



// FUNCTION FUN_08026640 @ 08026640

int FUN_08026640(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                uint param_6,uint param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  ulonglong in_d0;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  int local_78;
  uint local_74;
  uint local_60;
  undefined4 local_58;
  uint uStack_54;
  undefined8 local_48;
  int local_38;
  int local_2c;
  
  local_48._0_4_ = (undefined4)in_d0;
  local_48._4_4_ = (undefined4)(in_d0 >> 0x20);
  iVar1 = FUN_080465a0((undefined4)local_48,local_48._4_4_,(undefined4)local_48,local_48._4_4_);
  if (((iVar1 == 0) ||
      (iVar1 = FUN_080465bc((undefined4)local_48,local_48._4_4_,(int)DAT_08026a00,
                            (int)((ulonglong)DAT_08026a00 >> 0x20)), iVar1 != 0)) ||
     (iVar1 = FUN_080465ca((undefined4)local_48,local_48._4_4_,(int)DAT_08026a08,
                           (int)((ulonglong)DAT_08026a08 >> 0x20)), iVar1 == 0)) {
    local_2c = FUN_080260e0((undefined4)local_48,param_1,param_2,param_3,param_4,param_5,param_6,
                            param_7);
  }
  else {
    iVar1 = FUN_080465e6((undefined4)local_48,local_48._4_4_,(int)DAT_08026a10,
                         (int)((ulonglong)DAT_08026a10 >> 0x20));
    uVar9 = in_d0;
    if (iVar1 != 0) {
      uVar9 = FUN_080463cc((int)DAT_08026a18,(int)((ulonglong)DAT_08026a18 >> 0x20),
                           (undefined4)local_48,local_48._4_4_);
    }
    local_48 = uVar9;
    if (-1 < (int)((uint)param_7._1_1_ * 0x20000000)) {
      param_5 = 6;
    }
    uStack_54 = (uint)(local_48 >> 0x20);
    uVar8 = uStack_54;
    local_58 = (undefined4)local_48;
    uVar5 = local_58;
    uVar10 = FUN_0804608a(((uStack_54 & 0x7fffffff) >> 0x14) - 0x3ff);
    uVar10 = FUN_080461d0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)DAT_08026a20,
                          (int)((ulonglong)DAT_08026a20 >> 0x20));
    uVar10 = FUN_08045b40((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)DAT_08026a28,
                          (int)((ulonglong)DAT_08026a28 >> 0x20));
    uVar11 = FUN_08045b40((int)(local_48 & 0xfffffffffffff),
                          (uint)((local_48 & 0xfffffffffffff) >> 0x20) | 0x3ff00000,
                          (int)DAT_08026a30,(int)((ulonglong)DAT_08026a30 >> 0x20));
    uVar11 = FUN_080461d0((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)DAT_08026a38,
                          (int)((ulonglong)DAT_08026a38 >> 0x20));
    uVar10 = FUN_08045b40((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    local_60 = FUN_08045fd0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar10 = FUN_0804608a(local_60);
    uVar10 = FUN_080461d0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)DAT_08026a40,
                          (int)((ulonglong)DAT_08026a40 >> 0x20));
    uVar10 = FUN_08045b40((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)DAT_08026a48,
                          (int)((ulonglong)DAT_08026a48 >> 0x20));
    iVar2 = FUN_08045fd0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar10 = FUN_0804608a(local_60);
    uVar10 = FUN_080461d0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)DAT_08026a50,
                          (int)((ulonglong)DAT_08026a50 >> 0x20));
    uVar11 = FUN_0804608a(iVar2);
    uVar11 = FUN_080461d0((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)DAT_08026a58,
                          (int)((ulonglong)DAT_08026a58 >> 0x20));
    uVar10 = FUN_08045b40((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar3 = (undefined4)uVar10;
    uVar10 = FUN_080461d0(uVar3,uVar6,uVar3,uVar6);
    uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar4 = (undefined4)uVar10;
    uVar10 = FUN_08045b40(uVar3,uVar6,uVar3,uVar6);
    uVar11 = FUN_080463cc((int)DAT_08026bc0,(int)((ulonglong)DAT_08026bc0 >> 0x20),uVar3,uVar6);
    uVar12 = FUN_08045ca8(uVar4,uVar7,(int)DAT_08026bc8,(int)((ulonglong)DAT_08026bc8 >> 0x20));
    uVar12 = FUN_08045b40((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)DAT_08026bd0,
                          (int)((ulonglong)DAT_08026bd0 >> 0x20));
    uVar12 = FUN_08045ca8(uVar4,uVar7,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
    uVar12 = FUN_08045b40((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)DAT_08026bd8,
                          (int)((ulonglong)DAT_08026bd8 >> 0x20));
    uVar12 = FUN_08045ca8(uVar4,uVar7,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
    uVar11 = FUN_08045b40((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
    uVar10 = FUN_08045ca8((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar10 = FUN_08045b40((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)DAT_08026be0,
                          (int)((ulonglong)DAT_08026be0 >> 0x20));
    uVar10 = FUN_080461d0(0,iVar2 * 0x100000 + 0x3ff00000,(int)uVar10,
                          (int)((ulonglong)uVar10 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar2 = FUN_080465ca(local_58,uStack_54,(int)uVar10,uVar3);
    if (iVar2 == 0) {
      local_60 = local_60 - 1;
      uVar10 = FUN_08045ca8((int)uVar10,uVar3,(int)DAT_08026bd0,
                            (int)((ulonglong)DAT_08026bd0 >> 0x20));
    }
    uStack_54 = (uint)((ulonglong)uVar10 >> 0x20);
    local_58 = (undefined4)uVar10;
    local_74 = 5;
    if ((int)local_60 < 100 && -100 < (int)local_60) {
      local_74 = 4;
    }
    if ((int)((uint)param_7._1_1_ * 0x10000000) < 0) {
      iVar2 = FUN_080465e6(uVar5,uVar8,(int)DAT_08026be8,(int)((ulonglong)DAT_08026be8 >> 0x20));
      if ((iVar2 == 0) &&
         (iVar2 = FUN_080465ca(uVar5,uVar8,(int)DAT_08026bf0,(int)((ulonglong)DAT_08026bf0 >> 0x20))
         , iVar2 == 0)) {
        if ((int)local_60 < param_5) {
          param_5 = (param_5 - local_60) + -1;
        }
        else {
          param_5 = 0;
        }
        param_7 = param_7 | 0x400;
        local_74 = 0;
        local_60 = 0;
      }
      else if ((param_5 != 0) && ((int)((uint)param_7._1_1_ * 0x20000000) < 0)) {
        param_5 = param_5 + -1;
      }
    }
    if (local_74 < param_6) {
      local_78 = param_6 - local_74;
    }
    else {
      local_78 = 0;
    }
    if (((int)(param_7 * 0x40000000) < 0) && (local_74 != 0)) {
      local_78 = 0;
    }
    if (local_60 != 0) {
      local_48 = FUN_08045ca8(uVar5,uVar8,local_58,uStack_54);
    }
    if (iVar1 != 0) {
      local_48._0_4_ =
           FUN_080463cc((int)DAT_08026bb8,(int)((ulonglong)DAT_08026bb8 >> 0x20),
                        (undefined4)local_48,local_48._4_4_);
    }
    local_38 = FUN_080260e0((undefined4)local_48,param_1,param_2,param_3,param_4,param_5,local_78,
                            param_7 & 0xfffff7ff);
    if (local_74 != 0) {
      uVar5 = 0x65;
      if ((param_7 & 0x20) != 0) {
        uVar5 = 0x45;
      }
      (*param_1)(uVar5,param_2,local_38,param_4);
      uVar8 = local_60;
      if (0x7fffffff < local_60) {
        uVar8 = -local_60;
      }
      local_38 = FUN_08025fe4(param_1,param_2,local_38 + 1,param_4,uVar8,local_60 >> 0x1f,10,0,
                              local_74 - 1,5);
      if ((int)(param_7 * 0x40000000) < 0) {
        while ((uint)(local_38 - param_3) < param_6) {
          (*param_1)(0x20,param_2,local_38,param_4);
          local_38 = local_38 + 1;
        }
      }
    }
    local_2c = local_38;
  }
  return local_2c;
}



// FUNCTION FUN_08026bf8 @ 08026bf8

int FUN_08026bf8(char *param_1,int param_2)

{
  int iVar1;
  char *local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_2;
  while( true ) {
    iVar1 = local_8;
    if (*local_c != '\0') {
      local_8 = local_8 + -1;
    }
    if (*local_c == '\0' || iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return (int)local_c - (int)param_1;
}



// FUNCTION FUN_08026c38 @ 08026c38

int FUN_08026c38(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                uint param_6,uint param_7,byte param_8)

{
  uint local_20;
  int local_14;
  
  local_14 = param_3;
  if ((-1 < (int)((uint)param_8 * 0x40000000)) && ((param_8 & 1) == 0)) {
    local_14 = param_3;
    for (local_20 = param_6; local_20 < param_7; local_20 = local_20 + 1) {
      (*param_1)(0x20,param_2,local_14,param_4);
      local_14 = local_14 + 1;
    }
  }
  while (param_6 != 0) {
    param_6 = param_6 - 1;
    (*param_1)(*(undefined1 *)(param_5 + param_6),param_2,local_14,param_4);
    local_14 = local_14 + 1;
  }
  if ((int)((uint)param_8 * 0x40000000) < 0) {
    while ((uint)(local_14 - param_3) < param_7) {
      (*param_1)(0x20,param_2,local_14,param_4);
      local_14 = local_14 + 1;
    }
  }
  return local_14;
}



// FUNCTION FUN_08026cfc @ 08026cfc

void FUN_08026cfc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6,uint param_7,int param_8,uint param_9,uint param_10,
                 uint param_11)

{
  uint uVar1;
  bool bVar2;
  
  if (-1 < (int)(param_11 * 0x40000000)) {
    if (((param_10 != 0) && ((param_11 & 1) != 0)) &&
       (((param_7 & 1) != 0 || ((param_11 & 0xc) != 0)))) {
      param_10 = param_10 - 1;
    }
    while (param_6 < param_9 && param_6 < 0x40) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
      param_6 = param_6 + 1;
    }
    while( true ) {
      bVar2 = false;
      if (((param_11 & 1) != 0) && (bVar2 = false, param_6 < param_10)) {
        bVar2 = param_6 < 0x40;
      }
      if (!bVar2) break;
      *(undefined1 *)(param_5 + param_6) = 0x30;
      param_6 = param_6 + 1;
    }
  }
  if ((int)(param_11 * 0x8000000) < 0) {
    uVar1 = param_6;
    if ((((-1 < (int)((param_11 >> 8) * 0x20000000)) && (param_6 != 0)) &&
        ((param_6 == param_9 || (param_6 == param_10)))) &&
       ((uVar1 = param_6 - 1, uVar1 != 0 && (param_8 == 0x10)))) {
      uVar1 = param_6 - 2;
    }
    param_6 = uVar1;
    if (((param_8 == 0x10) && (-1 < (int)(param_11 * 0x4000000))) && (param_6 < 0x40)) {
      *(undefined1 *)(param_5 + param_6) = 0x78;
      param_6 = param_6 + 1;
    }
    else if (((param_8 == 0x10) && ((int)(param_11 * 0x4000000) < 0)) && (param_6 < 0x40)) {
      *(undefined1 *)(param_5 + param_6) = 0x58;
      param_6 = param_6 + 1;
    }
    else if ((param_8 == 2) && (param_6 < 0x40)) {
      *(undefined1 *)(param_5 + param_6) = 0x62;
      param_6 = param_6 + 1;
    }
    if (param_6 < 0x40) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
      param_6 = param_6 + 1;
    }
  }
  if (param_6 < 0x40) {
    if ((param_7 & 1) == 0) {
      if ((int)(param_11 * 0x20000000) < 0) {
        *(undefined1 *)(param_5 + param_6) = 0x2b;
        param_6 = param_6 + 1;
      }
      else if ((int)(param_11 * 0x10000000) < 0) {
        *(undefined1 *)(param_5 + param_6) = 0x20;
        param_6 = param_6 + 1;
      }
    }
    else {
      *(undefined1 *)(param_5 + param_6) = 0x2d;
      param_6 = param_6 + 1;
    }
  }
  FUN_08026c38(param_1,param_2,param_3,param_4,param_5,param_6,param_10,param_11);
  return;
}



// FUNCTION FUN_08026f54 @ 08026f54

void FUN_08026f54(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_4;
  
  local_4 = param_4;
  FUN_0802555c(&DAT_20003d3a,10,param_3,&local_4);
  return;
}



// FUNCTION FUN_08026f88 @ 08026f88

void FUN_08026f88(void)

{
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_14;
  undefined1 local_12;
  undefined1 local_11;
  
  FUN_080210f4(8);
  FUN_08021130(0x4000);
  FUN_080210f4(1);
  local_14 = 4;
  local_12 = 3;
  local_11 = 0x28;
  FUN_08020ae8(0x40011400,&local_14);
  FUN_08020cd4();
  local_12 = 3;
  local_14 = 0x1000;
  local_11 = 0x10;
  FUN_08020ae8(0x40010c00,&local_14);
  local_14 = 0x2000;
  local_12 = 3;
  local_11 = 0x18;
  FUN_08020ae8(0x40010c00,&local_14);
  local_14 = 0x8000;
  local_11 = 0x18;
  FUN_08020ae8(0x40010c00,&local_14);
  local_14 = 0x4000;
  local_11 = 0x18;
  FUN_08020ae8(0x40010c00,&local_14);
  local_28 = 0;
  local_26 = 0x104;
  local_24 = 0;
  local_22 = 0;
  local_20 = 0;
  local_1e = 0x200;
  local_1c = 0x20;
  local_1a = 0;
  local_18 = 7;
  FUN_0802116c(0x40003800,&local_28);
  FUN_080211d4(0x40003800);
  return;
}



// FUNCTION FUN_08027080 @ 08027080

undefined1 FUN_08027080(undefined1 param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  do {
    iVar2 = FUN_0802122c(0x40003800,2);
  } while (iVar2 == 0);
  FUN_08021204(0x40003800,param_1);
  do {
    iVar2 = FUN_0802122c(0x40003800,1);
  } while (iVar2 == 0);
  uVar1 = FUN_08021218();
  return uVar1;
}



// FUNCTION FUN_080270d4 @ 080270d4

void FUN_080270d4(int param_1,byte param_2)

{
  undefined4 local_18;
  
  for (local_18 = 0; local_18 < (int)(uint)param_2; local_18 = local_18 + 1) {
    FUN_08027080(*(undefined1 *)(param_1 + local_18));
  }
  return;
}



// FUNCTION FUN_0802713c @ 0802713c

undefined4 FUN_0802713c(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x522)) {
    FUN_0802a020(param_1);
    FUN_08025048(0x32);
    *(undefined1 *)(param_1 + 0x101) = 0;
    *(undefined1 *)(param_1 + 0x103) = 0;
    *(undefined1 *)(param_1 + 0x156) = 0;
    FUN_0802a068(param_1);
    uVar1 = *(ushort *)(param_1 + 0xae) % 1000;
    if ((uVar1 < 0x96) || (0xaa < uVar1)) {
      *(undefined1 *)(param_1 + 0x157) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x157) = 0;
    }
    FUN_0802a0d8(param_1);
    FUN_0802a2a8(param_1);
    FUN_0802a848();
    uVar2 = FUN_0802503c();
    *(undefined4 *)(param_1 + 0x148) = uVar2;
    iVar3 = param_1 + 0x104;
    FUN_0802c250(iVar3);
    *(undefined1 *)(param_1 + 0x144) = 3;
    FUN_0802c1fc(iVar3,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c2fc(iVar3);
    *(undefined1 *)(param_1 + 0x144) = 3;
    FUN_0802c1fc(iVar3,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c328(iVar3);
    *(undefined1 *)(param_1 + 0x144) = 3;
    FUN_0802c1fc(iVar3,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c3a0(iVar3,1);
    *(undefined1 *)(param_1 + 0x144) = 0x11;
    FUN_0802c1fc(iVar3,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c1b8(iVar3,0);
    *(undefined1 *)(param_1 + 0x144) = 5;
    FUN_0802c1fc(iVar3,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c35c(iVar3,1);
    *(undefined1 *)(param_1 + 0x144) = 5;
    FUN_0802c1fc(iVar3,*(undefined1 *)(param_1 + 0x144));
    FUN_0802a34c(param_1);
    FUN_0802a440(param_1);
    FUN_0802a46c(param_1);
  }
  return 0;
}



// FUNCTION FUN_08027280 @ 08027280

void FUN_08027280(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5)

{
  *(undefined1 *)(param_1 + 0x38) = 6;
  if ((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x522)) {
    if ((*(byte *)(param_1 + 0x157) & 1) == 0) {
      FUN_08027810(param_1,param_5,param_4);
    }
    else {
      FUN_080272e0(param_1,param_5,param_4);
    }
  }
  return;
}



// FUNCTION FUN_080272e0 @ 080272e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080272e0(int param_1,int param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == '\'') {
    DAT_20004508 = *(undefined2 *)(param_2 + 1);
    DAT_20004500 = (uint)(*(byte *)(param_2 + 0xc) >> 4) | (uint)*(byte *)(param_2 + 0xd) << 4 |
                   (uint)*(byte *)(param_2 + 0xe) << 0xc | (uint)*(byte *)(param_2 + 0xf) << 0x14 |
                   (uint)*(byte *)(param_2 + 0x10) << 0x1c;
    DAT_20004504 = (uint)(*(byte *)(param_2 + 0x10) >> 4) | (uint)*(byte *)(param_2 + 0x11) << 4 |
                   (uint)*(byte *)(param_2 + 0x12) << 0xc | (uint)*(byte *)(param_2 + 0x13) << 0x14
                   | (uint)*(byte *)(param_2 + 0x14) << 0x1c;
    *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_2 + 0x1c);
    if ((((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) &&
        ((*(ushort *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)((DAT_20004500 >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    DAT_20000c84 = (ushort)*(byte *)(param_2 + 9) | (*(byte *)(param_2 + 10) & 0xf) << 8;
    DAT_20000c86 = (ushort)(*(byte *)(param_2 + 10) >> 4) | (ushort)*(byte *)(param_2 + 0xb) << 4;
    if ((*(ushort *)(param_1 + 0x158) & 0xff) >> 6 != (uint)DAT_20000004) {
      DAT_20000004 = (ushort)(((uint)*(ushort *)(param_1 + 0x158) << 0x18) >> 0x1e);
      if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) == 0) {
        FUN_080444c0(2);
      }
      else {
        FUN_0804449c(2);
      }
    }
    if ((*(ushort *)(param_1 + 0x158) >> 0xc & 3) == 0) {
      iVar2 = FUN_08027d00();
      if (iVar2 == 0) {
        DAT_20004520 = 0;
      }
      else {
        uVar1 = FUN_08027d64();
        DAT_20004520 = (undefined1)(uVar1 >> 4);
      }
    }
    else {
      DAT_20004520 = *(undefined1 *)(param_2 + 8);
    }
    if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) {
      switch(*(ushort *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08029284(param_1);
        }
        else {
          FUN_08028d38(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004514 = DAT_20000c86 * -0x10 + -1;
            DAT_20004510 = DAT_20000c84 * -0x10 + -1;
            DAT_20004518 = -1;
          }
        }
        break;
      case 2:
        FUN_08027d84(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = DAT_20000c86 * -0x10 + -1;
          DAT_20004510 = DAT_20000c84 * -0x10 + -1;
          DAT_20004518 = -1;
        }
        break;
      case 3:
        FUN_080282d4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = DAT_20000c86 * -0x10 + -1;
          DAT_20004510 = DAT_20000c84 * -0x10 + -1;
          DAT_20004518 = -1;
        }
        break;
      case 4:
        FUN_08028824(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = DAT_20000c86 * -0x10 + -1;
          DAT_20004510 = DAT_20000c84 * -0x10 + -1;
          DAT_20004518 = -1;
        }
        break;
      case 5:
        FUN_08029558(param_1);
        break;
      case 6:
        FUN_08029a84(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = DAT_20000c86 * -0x10 + -1;
          DAT_20004510 = DAT_20000c84 * -0x10 + -1;
          DAT_20004518 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004510 = *(short *)(param_2 + 3) * -0x10 + -1;
      DAT_20004514 = ((ushort)(*(byte *)(param_2 + 4) >> 4) | (ushort)*(byte *)(param_2 + 5) << 4) *
                     -0x10 + -1;
      DAT_20004518 = *(short *)(param_2 + 6) * -0x10 + -1;
    }
    if (DAT_20000f1c == '\x01') {
      DAT_20004510 = _DAT_20000ee1 * -0x10 + -1;
      DAT_20004514 = _DAT_20000edf * -0x10 + -1;
      DAT_20004518 = _DAT_20000edd * -0x10 + -1;
    }
    if (*(ushort *)(param_1 + 0x158) >> 0xe == 0) {
      iVar2 = FUN_08029f78();
      if (iVar2 == 0) {
        DAT_20004530 = 0;
        DAT_20004528 = 0;
        DAT_2000452a = 0;
        DAT_20004534 = 0;
      }
      else {
        DAT_20004530 = FUN_0802bda4();
        iVar2 = FUN_08029fc0();
        if (iVar2 == 0) {
          DAT_20004528 = FUN_08029fe0();
          DAT_2000452a = FUN_0802a000();
        }
        else {
          DAT_20004528 = 0;
          DAT_2000452a = 0;
        }
        DAT_20004534 = iVar2 != 0;
      }
    }
    else if ((int)((uint)*(byte *)(param_2 + 0x1b) * 0x1000000) < 0) {
      DAT_20004530 = 0;
      DAT_20004534 = 0;
    }
    else {
      if ((int)((uint)*(byte *)(param_2 + 0x13) * 0x8000000) < 0) {
        DAT_20004530 = 0x80;
      }
      else {
        DAT_20004530 = FUN_08029f4c(*(byte *)(param_2 + 0x12) >> 4 | *(char *)(param_2 + 0x13) << 4)
        ;
      }
      DAT_20004534 = 1;
    }
  }
  return;
}



// FUNCTION FUN_08027810 @ 08027810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08027810(int param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == ' ') {
    FUN_080204b4(param_1 + 0xe1,param_2,0x20);
    if (*(char *)(param_1 + 0xf6) == '\a') {
      *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_1 + 0xf7);
    }
    DAT_20004508 = *(undefined2 *)(param_1 + 0xe2);
    uVar1 = *(uint *)(param_1 + 0xed) >> 4;
    DAT_20004504 = (*(uint *)(param_1 + 0xf1) & 0xfff) >> 4;
    DAT_20004500 = uVar1 | *(uint *)(param_1 + 0xf1) << 0x1c;
    if ((((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) &&
        ((*(ushort *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)(((uVar1 & 0xff0000) >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    if ((*(ushort *)(param_1 + 0x158) & 0xff) >> 6 != (uint)DAT_20000002) {
      DAT_20000002 = (ushort)(((uint)*(ushort *)(param_1 + 0x158) << 0x18) >> 0x1e);
      if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) == 0) {
        FUN_080444c0(2);
      }
      else {
        FUN_0804449c(2);
      }
    }
    if ((*(ushort *)(param_1 + 0x158) >> 0xc & 3) == 0) {
      iVar2 = FUN_08027d00();
      if (iVar2 == 0) {
        DAT_20004520 = 0;
      }
      else {
        uVar1 = FUN_08027d64();
        DAT_20004520 = (undefined1)(uVar1 >> 4);
      }
    }
    else {
      DAT_20004520 = *(undefined1 *)(param_1 + 0x100);
    }
    if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) {
      switch(*(ushort *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08029284(param_1);
        }
        else {
          FUN_08028d38(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004514 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
            DAT_20004510 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
            DAT_20004518 = -1;
          }
        }
        break;
      case 2:
        FUN_08027d84(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004510 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004518 = -1;
        }
        break;
      case 3:
        FUN_080282d4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004510 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004518 = -1;
        }
        break;
      case 4:
        FUN_08028824(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004510 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004518 = -1;
        }
        break;
      case 5:
        FUN_08029558(param_1);
        break;
      case 6:
        FUN_08029a84(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004514 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004510 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004518 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004510 = -1 - ((ushort)(*(uint *)(param_1 + 0xe5) >> 0xc) & 0xfff0);
      DAT_20004514 = -1 - ((ushort)*(undefined4 *)(param_1 + 0xe5) & 0xfff0);
      DAT_20004518 = -1 - (short)(*(int *)(param_1 + 0xe4) << 4);
    }
    if (DAT_20000f1c == '\x01') {
      DAT_20004510 = _DAT_20000ee1 * -0x10 + -1;
      DAT_20004514 = _DAT_20000edf * -0x10 + -1;
      DAT_20004518 = _DAT_20000edd * -0x10 + -1;
    }
    if ((*(ushort *)(param_1 + 0x158) >> 10 & 3) != 0) {
      DAT_20004528 = (int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0;
      DAT_2000452a = (int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0;
    }
    if (*(ushort *)(param_1 + 0x158) >> 0xe == 0) {
      iVar2 = FUN_08029f78();
      if (iVar2 == 0) {
        DAT_20004534 = 0;
        DAT_20004530 = 0;
        DAT_20004528 = 0;
        DAT_2000452a = 0;
      }
      else {
        DAT_20004530 = FUN_0802bda4();
        iVar2 = FUN_08029fc0();
        if (iVar2 == 0) {
          DAT_20004534 = 0;
          DAT_20004528 = FUN_08029fe0();
          DAT_2000452a = FUN_0802a000();
        }
        else {
          DAT_20004534 = 1;
          DAT_20004528 = 0;
          DAT_2000452a = 0;
        }
      }
    }
    else {
      DAT_20004530 = FUN_08029f4c((*(uint *)(param_1 + 0xf1) & 0x1fffffff) >> 0x14);
      DAT_20004534 = 1;
    }
  }
  return;
}



// FUNCTION FUN_08027d00 @ 08027d00

bool FUN_08027d00(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_08024194(&DAT_20000b0c);
  bVar2 = false;
  if ((iVar1 != 0) && ((DAT_20000b7e != 0x483 || (bVar2 = true, DAT_20000b7c != 0x530)))) {
    bVar2 = DAT_20000b7e == 0x3670 && DAT_20000b7c == 0xa04;
  }
  return bVar2;
}



// FUNCTION FUN_08027d64 @ 08027d64

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_08027d64(void)

{
  return _DAT_20000b85;
}



// FUNCTION FUN_08027d84 @ 08027d84

void FUN_08027d84(void)

{
  if ((int)((uint)DAT_20004500._3_1_ * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._3_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._3_1_ * 0x4000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x8000000) < 0) {
    DAT_20004582 = DAT_20004582 | 1;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x4000000) < 0) {
    DAT_20004582 = DAT_20004582 | 2;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x2000000) < 0) {
    DAT_20004582 = DAT_20004582 | 4;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x1000000) < 0) {
    DAT_20004582 = DAT_20004582 | 8;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xf7;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x40000000) < 0) {
    DAT_20004582 = DAT_20004582 | 0x10;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xef;
  }
  DAT_200044f8 = (int)((uint)(byte)DAT_20004500 * 0x8000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0) {
    DAT_20004580 = DAT_20004580 | 4;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x1000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x40;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xbf;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 8;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x80;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0x7f;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if (((byte)DAT_20004500 & 1) == 0) {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  else {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x10;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x20;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0)) {
    DAT_20004538 = 1;
  }
  else {
    DAT_20004538 = 0;
  }
  if (((int)((uint)DAT_20004500._2_1_ * 0x20000000) < 0) &&
     ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0)) {
    DAT_2000453a = 1;
  }
  else {
    DAT_2000453a = 0;
  }
  return;
}



// FUNCTION FUN_080282d4 @ 080282d4

void FUN_080282d4(void)

{
  if ((int)((uint)DAT_20004500._3_1_ * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._3_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._3_1_ * 0x4000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x8000000) < 0) {
    DAT_20004582 = DAT_20004582 | 4;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x4000000) < 0) {
    DAT_20004582 = DAT_20004582 | 2;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x2000000) < 0) {
    DAT_20004582 = DAT_20004582 | 0x10;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004504 * 0x1000000) < 0) {
    DAT_20004582 = DAT_20004582 | 8;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xf7;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x40000000) < 0) {
    DAT_20004582 = DAT_20004582 | 1;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfe;
  }
  DAT_200044f8 = (int)((uint)(byte)DAT_20004500 * 0x8000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0) {
    DAT_20004580 = DAT_20004580 | 4;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x1000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x40;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xbf;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 8;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x80;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0x7f;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if (((byte)DAT_20004500 & 1) == 0) {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  else {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x10;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x20;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0)) {
    DAT_20004538 = 1;
  }
  else {
    DAT_20004538 = 0;
  }
  if (((int)((uint)DAT_20004500._2_1_ * 0x20000000) < 0) &&
     ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0)) {
    DAT_2000453a = 1;
  }
  else {
    DAT_2000453a = 0;
  }
  return;
}



// FUNCTION FUN_08028824 @ 08028824

void FUN_08028824(void)

{
  if ((int)((uint)DAT_20004500._2_1_ * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._2_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._2_1_ * 0x2000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x40000000) < 0) {
    DAT_20004582 = DAT_20004582 | 4;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfb;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x10000000) < 0) {
    DAT_20004582 = DAT_20004582 | 2;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfd;
  }
  if ((DAT_20004500._1_1_ & 1) == 0) {
    DAT_20004582 = DAT_20004582 & 0xf7;
  }
  else {
    DAT_20004582 = DAT_20004582 | 8;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x20000000) < 0) {
    DAT_20004582 = DAT_20004582 | 1;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfe;
  }
  DAT_200044f8 = (int)((uint)DAT_20004500._3_1_ * 0x40000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0) {
    DAT_20004580 = DAT_20004580 | 4;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x1000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x40;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xbf;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 8;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x80;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if (((byte)DAT_20004500 & 1) == 0) {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  else {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x10;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xef;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x20;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0)) {
    DAT_20004538 = 1;
  }
  else {
    DAT_20004538 = 0;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0)) {
    DAT_2000453a = 1;
  }
  else {
    DAT_2000453a = 0;
  }
  return;
}



// FUNCTION FUN_08028d38 @ 08028d38

void FUN_08028d38(void)

{
  if ((int)((uint)DAT_20004500._3_1_ * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._3_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._3_1_ * 0x2000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x10000000) < 0) {
    DAT_20004582 = DAT_20004582 | 4;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfb;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x20000000) < 0) {
    DAT_20004582 = DAT_20004582 | 2;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfd;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x40000000) < 0) {
    DAT_20004582 = DAT_20004582 | 0x10;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xef;
  }
  if ((DAT_20004500._1_1_ & 1) == 0) {
    DAT_20004582 = DAT_20004582 & 0xf7;
  }
  else {
    DAT_20004582 = DAT_20004582 | 8;
  }
  if ((DAT_20004500._2_1_ & 1) == 0) {
    DAT_20004582 = DAT_20004582 & 0xfe;
  }
  else {
    DAT_20004582 = DAT_20004582 | 1;
  }
  DAT_200044f8 = (int)((uint)DAT_20004500._2_1_ * 0x40000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0) {
    DAT_20004580 = DAT_20004580 | 4;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x1000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x40;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xbf;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 8;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x80;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if (((byte)DAT_20004500 & 1) == 0) {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  else {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x10;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xef;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x20;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0)) {
    DAT_20004538 = 1;
  }
  else {
    DAT_20004538 = 0;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) && (((byte)DAT_20004500 & 1) != 0)) {
    DAT_2000453a = 1;
  }
  else {
    DAT_2000453a = 0;
  }
  return;
}



// FUNCTION FUN_08029284 @ 08029284

void FUN_08029284(void)

{
  if ((int)((uint)DAT_20004500._1_1_ * 0x20000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._1_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._1_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._1_1_ * 0x40000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  DAT_200044f8 = (int)((uint)(byte)DAT_20004500 * 0x10000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0)) {
    DAT_20004538 = 1;
  }
  else {
    DAT_20004538 = 0;
  }
  if (((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) &&
     ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0)) {
    DAT_2000453a = 1;
  }
  else {
    DAT_2000453a = 0;
  }
  return;
}



// FUNCTION FUN_08029558 @ 08029558

void FUN_08029558(void)

{
  if ((int)((uint)DAT_20004500._2_1_ * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._2_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._2_1_ * 0x2000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x10000000) < 0) {
    DAT_20004582 = DAT_20004582 | 4;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfb;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x20000000) < 0) {
    DAT_20004582 = DAT_20004582 | 2;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfd;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x40000000) < 0) {
    DAT_20004582 = DAT_20004582 | 0x10;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xef;
  }
  if ((DAT_20004500._1_1_ & 1) == 0) {
    DAT_20004582 = DAT_20004582 & 0xf7;
  }
  else {
    DAT_20004582 = DAT_20004582 | 8;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0) {
    DAT_20004582 = DAT_20004582 | 1;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfe;
  }
  DAT_200044f8 = (int)((uint)(byte)DAT_20004500 * 0x20000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0) {
    DAT_20004580 = DAT_20004580 | 4;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfb;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x40000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x40;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xbf;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 8;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xf7;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x40000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x80;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if (((byte)DAT_20004500 & 1) == 0) {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  else {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x10;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xef;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x10000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x20;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xdf;
  }
  DAT_20004538 = (int)((uint)DAT_20004500._2_1_ * 0x20000000) < 0;
  DAT_2000453a = (int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0;
  return;
}



// FUNCTION FUN_08029a84 @ 08029a84

void FUN_08029a84(void)

{
  if ((int)((uint)DAT_20004500._2_1_ * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0;
  }
  else if ((int)((uint)DAT_20004500._2_1_ * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 & 0xf0 | 4;
  }
  else if ((DAT_20004500._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004500._2_1_ * 0x2000000) < 0) {
      DAT_20004578 = DAT_20004578 & 0xf0 | 2;
    }
    else {
      DAT_20004578 = DAT_20004578 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x10000000) < 0) {
    DAT_20004582 = DAT_20004582 | 1;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfe;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x20000000) < 0) {
    DAT_20004582 = DAT_20004582 | 2;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfd;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x8000000) < 0) {
    DAT_20004582 = DAT_20004582 | 4;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xfb;
  }
  if ((int)((uint)DAT_20004500._2_1_ * 0x20000000) < 0) {
    DAT_20004582 = DAT_20004582 | 8;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xf7;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x10000000) < 0) {
    DAT_20004582 = DAT_20004582 | 0x10;
  }
  else {
    DAT_20004582 = DAT_20004582 & 0xef;
  }
  DAT_200044f8 = (int)((uint)(byte)DAT_20004500 * 0x1000000) < 0;
  if ((int)((uint)DAT_20004500._1_1_ * 0x4000000) < 0) {
    DAT_20004580 = DAT_20004580 | 1;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfe;
  }
  if (((byte)DAT_20004500 & 1) == 0) {
    DAT_20004580 = DAT_20004580 & 0xfb;
  }
  else {
    DAT_20004580 = DAT_20004580 | 4;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x40000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x40;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xbf;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 2;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xfd;
  }
  if ((int)((uint)DAT_20004500._1_1_ * 0x40000000) < 0) {
    DAT_20004580 = DAT_20004580 | 8;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xf7;
  }
  if ((DAT_20004500._1_1_ & 1) == 0) {
    DAT_20004580 = DAT_20004580 & 0x7f;
  }
  else {
    DAT_20004580 = DAT_20004580 | 0x80;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x10000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x80;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x8000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x10;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x2000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x40;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xbf;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x4000000) < 0) {
    DAT_20004578 = DAT_20004578 | 0x20;
  }
  else {
    DAT_20004578 = DAT_20004578 & 0xdf;
  }
  if ((int)((uint)DAT_20004500._3_1_ * 0x8000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x10;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004500 * 0x20000000) < 0) {
    DAT_20004580 = DAT_20004580 | 0x20;
  }
  else {
    DAT_20004580 = DAT_20004580 & 0xdf;
  }
  return;
}



// FUNCTION FUN_08029f4c @ 08029f4c

undefined1 FUN_08029f4c(uint param_1)

{
  undefined1 local_5;
  
  if (param_1 < 0x41) {
    local_5 = (undefined1)param_1;
  }
  else {
    local_5 = 0x40;
  }
  return local_5;
}



// FUNCTION FUN_08029f78 @ 08029f78

bool FUN_08029f78(void)

{
  int iVar1;
  
  iVar1 = FUN_08024194(&DAT_20000bc4);
  return iVar1 != 0 && (DAT_20000c36 == 0x483 && DAT_20000c34 == 0x531);
}



// FUNCTION FUN_08029fc0 @ 08029fc0

uint FUN_08029fc0(void)

{
  return (DAT_20000c3e & 8) >> 3 ^ 1;
}



// FUNCTION FUN_08029fe0 @ 08029fe0

bool FUN_08029fe0(void)

{
  return DAT_20000c3e == '\f';
}



// FUNCTION FUN_0802a000 @ 0802a000

bool FUN_0802a000(void)

{
  return DAT_20000c3e == '\n';
}



// FUNCTION FUN_0802a020 @ 0802a020

void FUN_0802a020(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_1c = 0x5501f180;
  local_18 = 0xffaa;
  local_c = param_1;
  FUN_08023148(param_1,*(undefined1 *)(param_1 + 0x3a),0x80,&local_1c);
  return;
}



// FUNCTION FUN_0802a068 @ 0802a068

void FUN_0802a068(int param_1)

{
  FUN_0802053e(param_1 + 0x74,0x3c);
  FUN_08021c74(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0xa1,1,0x81,3,0,0x10,0x40,param_1 + 0x74,0);
  if ((*(char *)(param_1 + 0x74) == -0x7f) && (*(char *)(param_1 + 0x75) == '\x06')) {
    FUN_08043650(*(undefined1 *)(param_1 + 0xab));
    *(undefined1 *)(param_1 + 0x101) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x101) = 0;
  }
  return;
}



// FUNCTION FUN_0802a0d8 @ 0802a0d8

void FUN_0802a0d8(int param_1)

{
  undefined4 *puVar1;
  
  *(undefined1 *)(param_1 + 0xb0) = 0x80;
  *(undefined1 *)(param_1 + 0xb1) = 1;
  *(undefined2 *)(param_1 + 0xb2) = (&DAT_20000d6c)[DAT_20000ecc * 0x12];
  *(undefined2 *)(param_1 + 0xb4) = (&DAT_20000d64)[DAT_20000ecc * 0x12];
  *(undefined1 *)(param_1 + 0xb6) = *(undefined1 *)(&DAT_20000d6a + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xb7) = *(undefined1 *)(&DAT_20000d66 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xb8) = *(undefined1 *)(&DAT_20000d6e + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xb9) = *(undefined1 *)(&DAT_20000d70 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xbb) = *(undefined1 *)(&DAT_20000d72 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xba) = *(undefined1 *)(&DAT_20000d76 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xbc) = *(undefined1 *)(&DAT_20000d78 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xbd) = *(undefined1 *)(&DAT_20000d7e + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xbe) = *(undefined1 *)(&DAT_20000d7a + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xbf) = *(undefined1 *)(&DAT_20000d7c + DAT_20000ecc * 0x12);
  FUN_08021c74(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,
               (undefined1 *)(param_1 + 0xb0),0);
  puVar1 = (undefined4 *)(param_1 + 0xc0);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined1 *)puVar1 = 0x80;
  *(undefined1 *)(param_1 + 0xc1) = 2;
  *(undefined2 *)(param_1 + 0xc2) = (&DAT_20000d6c)[DAT_20000ecc * 0x12];
  *(undefined1 *)(param_1 + 0xc4) = *(undefined1 *)(&DAT_20000d80 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xc5) = *(undefined1 *)(&DAT_20000d82 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xc6) = *(undefined1 *)(&DAT_20000d84 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 199) = 1;
  *(undefined1 *)(param_1 + 200) = *(undefined1 *)(&DAT_20000d74 + DAT_20000ecc * 0x12);
  *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(&DAT_20000d68 + DAT_20000ecc * 0x12);
  FUN_08021c74(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,puVar1,0);
  return;
}



// FUNCTION FUN_0802a2a8 @ 0802a2a8

void FUN_0802a2a8(int param_1)

{
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined1 *)(param_1 + 0xd0) = 0x80;
  *(undefined1 *)(param_1 + 0xd1) = 5;
  *(undefined2 *)(param_1 + 0xd2) = 0x2222;
  if ((&DAT_20000d86)[DAT_20000ecc * 0x12] == 0) {
    *(undefined1 *)(param_1 + 0xd4) = 1;
    *(undefined1 *)(param_1 + 0xd5) = 0;
    *(undefined1 *)(param_1 + 0xd6) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0xd4) = 1;
    *(undefined1 *)(param_1 + 0xd5) = 1;
    *(undefined1 *)(param_1 + 0xd6) = 0;
  }
  FUN_08021c74(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,param_1 + 0xd0,0);
  return;
}



// FUNCTION FUN_0802a34c @ 0802a34c

void FUN_0802a34c(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xb9) == '\0') {
    FUN_0802c214(param_1 + 0x104,6);
    *(undefined1 *)(param_1 + 0x144) = 5;
    FUN_0802c1fc(param_1 + 0x104,*(undefined1 *)(param_1 + 0x144));
  }
  else {
    iVar1 = param_1 + 0x104;
    FUN_0802c3a0(iVar1,5);
    *(undefined1 *)(param_1 + 0x144) = 0x11;
    FUN_0802c1fc(iVar1,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c444(iVar1,5);
    *(undefined1 *)(param_1 + 0x144) = 0x10;
    FUN_0802c1fc(iVar1,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c35c(iVar1,5);
    *(undefined1 *)(param_1 + 0x144) = 5;
    FUN_0802c1fc(iVar1,*(undefined1 *)(param_1 + 0x144));
  }
  if (*(char *)(param_1 + 0xb8) == '\0') {
    FUN_0802c214(param_1 + 0x104,6);
    *(undefined1 *)(param_1 + 0x144) = 5;
    FUN_0802c1fc(param_1 + 0x104,*(undefined1 *)(param_1 + 0x144));
  }
  else {
    iVar1 = param_1 + 0x104;
    FUN_0802c3a0(iVar1,6);
    *(undefined1 *)(param_1 + 0x144) = 0x11;
    FUN_0802c1fc(iVar1,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c444(iVar1,6);
    *(undefined1 *)(param_1 + 0x144) = 0x10;
    FUN_0802c1fc(iVar1,*(undefined1 *)(param_1 + 0x144));
    FUN_0802c35c(iVar1,6);
    *(undefined1 *)(param_1 + 0x144) = 5;
    FUN_0802c1fc(iVar1,*(undefined1 *)(param_1 + 0x144));
  }
  return;
}



// FUNCTION FUN_0802a440 @ 0802a440

void FUN_0802a440(int param_1)

{
  FUN_08045aa8(param_1 + 0x15a,0x40);
  *(undefined1 *)(param_1 + 0x15a) = 0x91;
  *(undefined1 *)(param_1 + 0x15b) = 4;
  FUN_0802a4ac(param_1,10);
  return;
}



// FUNCTION FUN_0802a46c @ 0802a46c

void FUN_0802a46c(int param_1)

{
  FUN_08021c74(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x3e,0x3e,param_1 + 0x15a,0);
  return;
}



// FUNCTION FUN_0802a4ac @ 0802a4ac

void FUN_0802a4ac(int param_1,char param_2)

{
  *(char *)(param_1 + 0x15f) = param_2 << 4;
  return;
}



// FUNCTION FUN_0802a4c4 @ 0802a4c4

void FUN_0802a4c4(ushort param_1)

{
  DAT_20000a50 = (char)param_1;
  DAT_20000a51 = (char)((param_1 & 0x100) >> 1);
  return;
}



// FUNCTION FUN_0802a4f0 @ 0802a4f0

void FUN_0802a4f0(char param_1)

{
  undefined1 local_5;
  
  local_5 = param_1;
  if (param_1 != '\0') {
    local_5 = param_1 + '\x01';
  }
  DAT_20000a54 = local_5 << 4;
  return;
}



// FUNCTION FUN_0802a528 @ 0802a528

void FUN_0802a528(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0x2d2d0580;
  local_c = param_1;
  FUN_08021c74(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 0x3a),0x21,9,0x80,3,0,0x10,0x10,&local_1c,0);
  return;
}



// FUNCTION FUN_0802a57c @ 0802a57c

void FUN_0802a57c(undefined4 param_1)

{
  FUN_0802b748();
  FUN_0802a0d8(param_1);
  return;
}



// FUNCTION FUN_0802a594 @ 0802a594

void FUN_0802a594(byte param_1)

{
  DAT_200009d0 = 0;
  DAT_200009cc = 0;
  DAT_200009c4 = 0x99990580;
  DAT_200009c8 = (uint)param_1;
  FUN_08021c74(DAT_200008fc,DAT_20000900,DAT_2000092e,0x21,9,0x80,3,0,0x10,0x10,&DAT_200009c4,0);
  return;
}



// FUNCTION FUN_0802a608 @ 0802a608

void FUN_0802a608(void)

{
  uint uVar1;
  
  FUN_0802bf34();
  if (DAT_20004538 == '\x01') {
    uVar1 = FUN_080250d8(DAT_20000a3c);
    if (4999 < uVar1) {
      FUN_0802a528(&DAT_200008f4);
      DAT_20000a3c = FUN_0802503c();
    }
  }
  else {
    DAT_20000a3c = FUN_0802503c();
  }
  if (DAT_2000453a == '\x01') {
    uVar1 = FUN_080250d8(DAT_20000a44);
    if (4999 < uVar1) {
      FUN_0802a57c(&DAT_200008f4);
      DAT_20000a44 = FUN_0802503c();
    }
  }
  else {
    DAT_20000a44 = FUN_0802503c();
  }
  if ((DAT_200009f7 & 1) != 0) {
    DAT_200009f7 = 0;
    FUN_0802b8b4();
    FUN_080444e8(DAT_200009f6);
  }
  return;
}



// FUNCTION FUN_0802a6bc @ 0802a6bc

void FUN_0802a6bc(int param_1,short param_2)

{
  if ((DAT_20000a4b & 1) == 0) {
    FUN_08022530(DAT_200008fc,DAT_20000900,DAT_20000934,param_2 + -1,param_1 + 1);
  }
  else {
    FUN_08022530(DAT_200008fc,DAT_20000900,DAT_20000934,param_2,param_1);
  }
  return;
}



// FUNCTION FUN_0802a71c @ 0802a71c

void FUN_0802a71c(void)

{
  FUN_0802a0d8(&DAT_200008f4);
  return;
}



// FUNCTION FUN_0802a72c @ 0802a72c

void FUN_0802a72c(void)

{
  FUN_0802a2a8(&DAT_200008f4);
  return;
}



// FUNCTION FUN_0802a73c @ 0802a73c

void FUN_0802a73c(short param_1)

{
  FUN_0802a594((int)param_1);
  return;
}



// FUNCTION FUN_0802a750 @ 0802a750

void FUN_0802a750(void)

{
  FUN_0802a528(&DAT_200008f4);
  return;
}



// FUNCTION FUN_0802a760 @ 0802a760

void FUN_0802a760(undefined4 param_1,undefined2 param_2)

{
  FUN_0802a6bc(param_1,param_2);
  return;
}



// FUNCTION FUN_0802a778 @ 0802a778

void FUN_0802a778(void)

{
  FUN_0802a440(&DAT_200008f4);
  return;
}



// FUNCTION FUN_0802a788 @ 0802a788

void FUN_0802a788(undefined2 param_1)

{
  FUN_0802a4c4(param_1);
  return;
}



// FUNCTION FUN_0802a79c @ 0802a79c

void FUN_0802a79c(undefined1 param_1)

{
  FUN_0802a4f0(param_1);
  return;
}



// FUNCTION FUN_0802a7b0 @ 0802a7b0

void FUN_0802a7b0(undefined1 param_1)

{
  FUN_0802a4ac(&DAT_200008f4,param_1);
  return;
}



// FUNCTION FUN_0802a7cc @ 0802a7cc

void FUN_0802a7cc(void)

{
  FUN_0802a46c(&DAT_200008f4);
  return;
}



// FUNCTION FUN_0802a7dc @ 0802a7dc

void FUN_0802a7dc(void)

{
  FUN_0802def0();
  FUN_0802db7c(4);
  return;
}



// FUNCTION FUN_0802a7ec @ 0802a7ec

bool FUN_0802a7ec(void)

{
  int iVar1;
  
  iVar1 = FUN_080202d2(&DAT_20000c88,&DAT_20000cc8,0x40);
  return iVar1 != 0;
}



// FUNCTION FUN_0802a824 @ 0802a824

void FUN_0802a824(void)

{
  undefined1 auStack_10a [256];
  undefined2 local_a;
  
  local_a = FUN_0802df38(auStack_10a);
  FUN_0802c27c(auStack_10a);
  FUN_0802dbcc(3);
  return;
}



// FUNCTION FUN_0802a848 @ 0802a848

void FUN_0802a848(void)

{
  FUN_080204b4(&DAT_20000c88,&DAT_08046848,0x40);
  DAT_20004578 = 8;
  DAT_20004580 = 0;
  DAT_200044f8 = 0;
  DAT_20004508 = 0x8000;
  DAT_20004514 = 0xffff;
  DAT_20004518 = 0xffff;
  return;
}



// FUNCTION FUN_0802a8b4 @ 0802a8b4

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



// FUNCTION FUN_0802ab38 @ 0802ab38

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0802ab38(void)

{
  if (DAT_20004558 < 1) {
    _DAT_20000d08 = _DAT_20000d08 & 0xfffffdff;
  }
  else if ((int)((_DAT_20000d08 >> 8) * 0x40000000) < 0) {
    _DAT_20000d08 = _DAT_20000d08 & 0xfffffdff;
  }
  else {
    _DAT_20000d08 = _DAT_20000d08 | 0x200;
    DAT_20004558 = DAT_20004558 + -1;
  }
  if (DAT_20004560 < 1) {
    _DAT_20000d08 = _DAT_20000d08 & 0xffffffef;
  }
  else if ((int)(_DAT_20000d08 * 0x8000000) < 0) {
    _DAT_20000d08 = _DAT_20000d08 & 0xffffffef;
  }
  else {
    _DAT_20000d08 = _DAT_20000d08 | 0x10;
    DAT_20004560 = DAT_20004560 + -1;
  }
  if (DAT_20004568 < 1) {
    _DAT_20000d08 = _DAT_20000d08 & 0xffffbfff;
  }
  else if ((int)((_DAT_20000d08 >> 8) * 0x2000000) < 0) {
    _DAT_20000d08 = _DAT_20000d08 & 0xffffbfff;
  }
  else {
    _DAT_20000d08 = _DAT_20000d08 | 0x4000;
    DAT_20004568 = DAT_20004568 + -1;
  }
  if (DAT_20004570 < 1) {
    _DAT_20000d08 = _DAT_20000d08 & 0xfff7ffff;
  }
  else if ((int)((_DAT_20000d08 >> 0x10) * 0x10000000) < 0) {
    _DAT_20000d08 = _DAT_20000d08 & 0xfff7ffff;
  }
  else {
    _DAT_20000d08 = _DAT_20000d08 | 0x80000;
    DAT_20004570 = DAT_20004570 + -1;
  }
  return _DAT_20000d08;
}



// FUNCTION FUN_0802ace4 @ 0802ace4

undefined4 FUN_0802ace4(void)

{
  DAT_20000d0c = DAT_20000d0c + 1;
  if (5 < DAT_20000d0c) {
    DAT_20000d10 = FUN_0802ab38();
    DAT_20000d0c = 0;
  }
  return DAT_20000d10;
}



// FUNCTION FUN_0802ad3c @ 0802ad3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802ad3c(void)

{
  DAT_20000d14 = (ushort)_DAT_40005c44;
  if ((int)((uint)(DAT_20000d14 & DAT_2000135e) * 0x10000) < 0) {
    FUN_0802d5dc();
  }
  if ((int)((uint)(DAT_20000d14 & DAT_2000135e) * 0x200000) < 0) {
    _DAT_40005c44 = 0xfbff;
    FUN_0802adcc();
  }
  return;
}



// FUNCTION FUN_0802ada8 @ 0802ada8

void FUN_0802ada8(void)

{
  DAT_20001346 = 0;
  FUN_0802b434();
  FUN_0802dec8();
  DAT_20000d60 = 0;
  return;
}



// FUNCTION FUN_0802adcc @ 0802adcc

void FUN_0802adcc(void)

{
  DAT_20001346 = 0;
  DAT_20001347 = 0;
  DAT_20001345 = 0xc0;
  FUN_0802da38();
  FUN_0802da58(0,0x200);
  FUN_0802da8c(0,0x10);
  FUN_0802dd14(0,0x40);
  FUN_0802dcdc(0,0x80);
  FUN_0802dc1c(0);
  FUN_0802ddd8(0,0x40);
  FUN_0802dbcc(0);
  FUN_0802da58(3,0x600);
  FUN_0802dd14(3,0xc0);
  FUN_0802db04(3,0x3000);
  FUN_0802da8c(3,0);
  FUN_0802dc1c(3);
  FUN_0802ddd8(3,0x40);
  FUN_0802dbcc(3);
  FUN_0802da58(4,0x600);
  FUN_0802dcdc(4,0x100);
  FUN_0802db04(4,0);
  FUN_0802da8c(4,0x20);
  FUN_0802d3b4(0);
  DAT_20000d60 = 1;
  return;
}



// FUNCTION FUN_0802ae8c @ 0802ae8c

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



// FUNCTION FUN_0802af38 @ 0802af38

void FUN_0802af38(void)

{
  return;
}



// FUNCTION FUN_0802af3c @ 0802af3c

undefined1 FUN_0802af3c(char param_1)

{
  undefined4 uVar1;
  undefined2 local_18;
  undefined1 uStack_16;
  code *local_10;
  undefined1 local_9;
  
  local_10 = (code *)0x0;
  if (((param_1 == '\x06') && ((DAT_2000133c & 0x7f) == 1)) && (DAT_20001341 == '\0')) {
    if ((char)DAT_2000133e == '\"') {
      local_10 = (code *)0x802b261;
    }
    else if ((char)DAT_2000133e == '!') {
      local_10 = (code *)0x802b27d;
    }
    if (local_10 == (code *)0x0) {
      return 2;
    }
  }
  else if ((DAT_2000133c & 0x7f) == 0x21) {
    if (param_1 == '\x01') {
      if (DAT_2000133e._1_1_ == '3') {
        uVar1 = FUN_0802ace4();
        uStack_16 = (undefined1)((uint)uVar1 >> 0x10);
        DAT_20000063 = uStack_16;
        local_18 = (undefined2)uVar1;
        DAT_20000061 = local_18;
      }
      else if (DAT_2000133e._1_1_ != '2') {
        if (DAT_2000133e._1_1_ != '1') {
          DAT_20000d1c = 1;
          DAT_20000d1d = DAT_2000133e._1_1_;
          DAT_20000d1e = 1;
          DAT_20000d1f = (undefined1)DAT_20001342;
          return 3;
        }
        FUN_0802ace4();
        if (DAT_20004534 == '\x01') {
          DAT_20000096 = 0x40;
          DAT_2000009a = 1;
        }
        else {
          DAT_20000096 = 0x41;
          DAT_2000009a = 2;
        }
      }
      local_10 = (code *)0x802b2cd;
    }
    else if (param_1 == '\x03') {
      local_10 = (code *)&LAB_0802b298_1;
    }
    else if (param_1 == '\t') {
      local_10 = (code *)&LAB_0802b36c_1;
      DAT_20000d1e = 9;
      DAT_20000d1d = DAT_2000133e._1_1_;
      DAT_20000d1f = (undefined1)DAT_20001342;
      DAT_20000d16 = 1;
    }
  }
  if (local_10 == (code *)0x0) {
    local_9 = 2;
  }
  else {
    DAT_20001354 = local_10;
    DAT_2000134e = 0;
    (*local_10)(0);
    local_9 = 0;
  }
  return local_9;
}



// FUNCTION FUN_0802b138 @ 0802b138

undefined1 FUN_0802b138(char param_1)

{
  undefined1 local_9;
  
  if (((DAT_2000133c & 0x7f) == 0x21) && (param_1 == '\v')) {
    FUN_0802b23c();
    local_9 = 0;
  }
  else {
    local_9 = 2;
  }
  return local_9;
}



// FUNCTION FUN_0802b17c @ 0802b17c

undefined1 FUN_0802b17c(char param_1,char param_2)

{
  undefined1 local_1;
  
  if (param_2 == '\0') {
    if (param_1 == '\0') {
      local_1 = 0;
    }
    else {
      local_1 = 2;
    }
  }
  else {
    local_1 = 2;
  }
  return local_1;
}



// FUNCTION FUN_0802b1bc @ 0802b1bc

void FUN_0802b1bc(undefined2 param_1)

{
  FUN_0802cb00(param_1,&DAT_2000004c);
  return;
}



// FUNCTION FUN_0802b1d8 @ 0802b1d8

void FUN_0802b1d8(undefined2 param_1)

{
  FUN_0802cb00(param_1,&DAT_20000044);
  return;
}



// FUNCTION FUN_0802b1f4 @ 0802b1f4

undefined4 FUN_0802b1f4(undefined2 param_1)

{
  undefined4 local_c;
  
  if (DAT_2000133e._1_1_ < 4) {
    local_c = FUN_0802cb00(param_1,(uint)DAT_2000133e._1_1_ * 8 + 0x20000024);
  }
  else {
    local_c = 0;
  }
  return local_c;
}



// FUNCTION FUN_0802b23c @ 0802b23c

void FUN_0802b23c(void)

{
  DAT_20000d18 = (uint)DAT_2000133e._1_1_;
  return;
}



// FUNCTION FUN_0802b260 @ 0802b260

void FUN_0802b260(undefined2 param_1)

{
  FUN_0802cb00(param_1,&DAT_2000011c);
  return;
}



// FUNCTION FUN_0802b27c @ 0802b27c

void FUN_0802b27c(undefined2 param_1)

{
  FUN_0802cb00(param_1,&DAT_20000114);
  return;
}



// FUNCTION FUN_0802b2cc @ 0802b2cc

undefined * FUN_0802b2cc(short param_1)

{
  undefined *local_4;
  
  if (param_1 == 0) {
    if (DAT_2000133e._1_1_ - 0x31 < 3) {
      DAT_2000134c = 0x40;
    }
    else {
      DAT_2000134c = (ushort)DAT_20000d1f;
    }
    local_4 = (undefined *)0x0;
  }
  else if (DAT_2000133e._1_1_ == 0x31) {
    local_4 = &DAT_20000094;
  }
  else if (DAT_2000133e._1_1_ == 0x32) {
    local_4 = &DAT_200000d4;
  }
  else if (DAT_2000133e._1_1_ == 0x33) {
    local_4 = &DAT_20000054;
  }
  else {
    local_4 = &DAT_20000d20;
  }
  return local_4;
}



// FUNCTION FUN_0802b3a8 @ 0802b3a8

void FUN_0802b3a8(void)

{
  if (DAT_20001346 != '\0') {
    DAT_20000d60 = 5;
  }
  return;
}



// FUNCTION FUN_0802b3c8 @ 0802b3c8

void FUN_0802b3c8(void)

{
  DAT_20000d60 = 4;
  return;
}



// FUNCTION FUN_0802b3d8 @ 0802b3d8

void FUN_0802b3d8(void)

{
  DAT_20001354 = 0x802b2cd;
  DAT_2000134e = 0;
  FUN_0802b2cc(0);
  if (DAT_20001342 < DAT_2000134c) {
    DAT_2000134c = DAT_20001342;
  }
  DAT_20001350 = 0x40;
  FUN_0802cb48();
  FUN_0802db7c(0);
  FUN_0802dbcc(0);
  return;
}



// FUNCTION FUN_0802b434 @ 0802b434

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802b434(void)

{
  _DAT_40005c44 = 0;
  DAT_2000135e = 0x1c00;
  _DAT_40005c40 = 0x1c00;
  return;
}



// FUNCTION FUN_0802b474 @ 0802b474

undefined4 FUN_0802b474(void)

{
  return 0;
}



// FUNCTION FUN_0802b480 @ 0802b480

void FUN_0802b480(void)

{
  return;
}



// FUNCTION FUN_0802b488 @ 0802b488

void FUN_0802b488(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802b4b0 @ 0802b4b0

void FUN_0802b4b0(void)

{
  FUN_080204b4(&DAT_20000d64,0x8019000,0x170);
  return;
}



// FUNCTION FUN_0802b4e0 @ 0802b4e0

void FUN_0802b4e0(void)

{
  bool bVar1;
  char cVar2;
  int local_28;
  uint local_14;
  
  local_14 = 0x8019000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(1);
  }
  FUN_080250b4(1);
  FUN_08021344();
  while (local_14 < 0x8019170) {
    cVar2 = FUN_08021378(local_14);
    local_14 = local_14 + 0x800;
    if (cVar2 != '\x06') goto LAB_0802b5a4;
  }
  local_28 = 0;
  while ((local_28 < 0x5c &&
         (cVar2 = FUN_080214f8(local_28 * 4 + 0x8019000,
                               *(undefined4 *)(&DAT_20000d64 + local_28 * 2)), cVar2 == '\x06'))) {
    local_28 = local_28 + 1;
  }
LAB_0802b5a4:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(0);
  }
  FUN_08021364(0);
  return;
}



// FUNCTION FUN_0802b5b8 @ 0802b5b8

undefined1 FUN_0802b5b8(void)

{
  undefined1 local_9;
  
  FUN_0802b4b0();
  if (DAT_20000ed0 == 0x1234567a) {
    if (9 < DAT_20000ecc) {
      DAT_20000ecc = 0;
    }
    local_9 = 1;
  }
  else {
    local_9 = 0;
  }
  return local_9;
}



// FUNCTION FUN_0802b614 @ 0802b614

void FUN_0802b614(void)

{
  int local_c;
  
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    (&DAT_20000d64)[local_c * 0x12] = 0x32;
    (&DAT_20000d66)[local_c * 0x12] = 0x14;
    (&DAT_20000d68)[local_c * 0x12] = 100;
    (&DAT_20000d6a)[local_c * 0x12] = 4;
    (&DAT_20000d6c)[local_c * 0x12] = 900;
    (&DAT_20000d6e)[local_c * 0x12] = 0;
    (&DAT_20000d70)[local_c * 0x12] = 0x19;
    (&DAT_20000d72)[local_c * 0x12] = 0x14;
    (&DAT_20000d74)[local_c * 0x12] = 0;
    (&DAT_20000d80)[local_c * 0x12] = 9;
    (&DAT_20000d82)[local_c * 0x12] = 0;
    (&DAT_20000d84)[local_c * 0x12] = 1;
    (&DAT_20000d76)[local_c * 0x12] = 0;
    (&DAT_20000d78)[local_c * 0x12] = 100;
    (&DAT_20000d7a)[local_c * 0x12] = 100;
    (&DAT_20000d7c)[local_c * 0x12] = 100;
    (&DAT_20000d7e)[local_c * 0x12] = 100;
    (&DAT_20000d86)[local_c * 0x12] = 0;
  }
  DAT_20000ecc = 0;
  return;
}



// FUNCTION FUN_0802b748 @ 0802b748

void FUN_0802b748(void)

{
  if (9 < DAT_20000ecc) {
    DAT_20000ecc = 0;
  }
  (&DAT_20000d64)[DAT_20000ecc * 0x12] = 0x32;
  (&DAT_20000d68)[DAT_20000ecc * 0x12] = 100;
  (&DAT_20000d66)[DAT_20000ecc * 0x12] = 0x14;
  (&DAT_20000d6a)[DAT_20000ecc * 0x12] = 4;
  (&DAT_20000d6c)[DAT_20000ecc * 0x12] = 900;
  (&DAT_20000d6e)[DAT_20000ecc * 0x12] = 0;
  (&DAT_20000d70)[DAT_20000ecc * 0x12] = 0x19;
  (&DAT_20000d72)[DAT_20000ecc * 0x12] = 0x14;
  (&DAT_20000d74)[DAT_20000ecc * 0x12] = 0;
  (&DAT_20000d80)[DAT_20000ecc * 0x12] = 9;
  (&DAT_20000d82)[DAT_20000ecc * 0x12] = 0;
  (&DAT_20000d84)[DAT_20000ecc * 0x12] = 1;
  (&DAT_20000d76)[DAT_20000ecc * 0x12] = 0;
  (&DAT_20000d78)[DAT_20000ecc * 0x12] = 100;
  (&DAT_20000d7a)[DAT_20000ecc * 0x12] = 100;
  (&DAT_20000d7c)[DAT_20000ecc * 0x12] = 100;
  (&DAT_20000d7e)[DAT_20000ecc * 0x12] = 100;
  (&DAT_20000d86)[DAT_20000ecc * 0x12] = 0;
  return;
}



// FUNCTION FUN_0802b898 @ 0802b898

void FUN_0802b898(void)

{
  DAT_20000ed0 = 0x1234567a;
  FUN_0802b4e0();
  return;
}



// FUNCTION FUN_0802b8b4 @ 0802b8b4

void FUN_0802b8b4(void)

{
  FUN_0802a71c();
  FUN_0802a72c();
  DAT_20000ed4 = 1;
  DAT_20000ed8 = FUN_0802503c();
  return;
}



// FUNCTION FUN_0802b8dc @ 0802b8dc

void FUN_0802b8dc(short param_1)

{
  FUN_0802a73c((int)param_1);
  return;
}



// FUNCTION FUN_0802b8f0 @ 0802b8f0

void FUN_0802b8f0(void)

{
  uint uVar1;
  
  if ((DAT_20000ed4 == '\x01') && (uVar1 = FUN_080250d8(DAT_20000ed8), 5000 < uVar1)) {
    FUN_0802b898();
    DAT_20000ed4 = '\0';
  }
  return;
}



// FUNCTION FUN_0802b930 @ 0802b930

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

void FUN_0802b9f8(void)

{
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802ba20 @ 0802ba20

void FUN_0802ba20(void)

{
  FUN_0802b930();
  return;
}



// FUNCTION FUN_0802ba7c @ 0802ba7c

undefined4 FUN_0802ba7c(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x72) == 0x530)) ||
     ((*(short *)(param_1 + 0x72) == 0x3670 && (*(short *)(param_1 + 0x72) == 0xa04)))) {
    if (*(int *)(param_1 + 0x74) != 0) {
      (**(code **)(param_1 + 0x74))();
    }
    FUN_0802053e(param_1 + 0x78,0x40);
  }
  return 0;
}



// FUNCTION FUN_0802bad8 @ 0802bad8

void FUN_0802bad8(int param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  if ((((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x530)) ||
      ((*(short *)(param_1 + 0x72) == 0x3670 && (*(short *)(param_1 + 0x70) == 0xa04)))) &&
     (((2 < param_4 && (param_4 < 0x41)) && (param_5 != 0)))) {
    FUN_080204b4(param_1 + 0x78,param_5,param_4);
  }
  return;
}



// FUNCTION FUN_0802bba4 @ 0802bba4

undefined4 FUN_0802bba4(int param_1)

{
  if (((*(short *)(param_1 + 0x72) == 0x483) && (*(short *)(param_1 + 0x70) == 0x525)) ||
     ((*(short *)(param_1 + 0x72) == 0x483 && (*(short *)(param_1 + 0x70) == 0x524)))) {
    if (*(int *)(param_1 + 0x74) != 0) {
      (**(code **)(param_1 + 0x74))();
    }
    FUN_08045aa8(&DAT_20000edc,0x40);
    DAT_20000f1c = 1;
  }
  else {
    DAT_20000f1c = 0;
  }
  return 0;
}


