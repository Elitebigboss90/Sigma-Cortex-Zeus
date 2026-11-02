
// FUNCTION FUN_08027f98 @ 08027f98

void FUN_08027f98(void)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  undefined1 local_63;
  undefined2 local_62;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [60];
  
  iVar4 = FUN_08026bb4();
  uVar2 = DAT_08028000;
  iVar1 = DAT_08027ffc;
  do {
    local_60 = 0;
    local_63 = 0;
    local_58 = 0;
    FUN_08035d8c(auStack_54,0,0x3c);
    local_5c = 0;
    FUN_08026be8(&local_62);
    (**(code **)(iVar1 + 0x134))(local_62,0,uVar2,&local_60,&local_63,&local_58,&local_5c);
    FUN_080298e6(0);
    sVar3 = *(short *)(iVar4 + 0x3a);
    if (sVar3 == 0) {
      sVar3 = 10;
    }
    thunk_FUN_0802fec8(sVar3);
  } while( true );
}



// FUNCTION FUN_08028028 @ 08028028

void FUN_08028028(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined1 auStack_a4 [8];
  uint local_9c;
  uint local_98;
  undefined1 local_94;
  undefined1 auStack_90 [108];
  
  iVar2 = FUN_08026bb4();
  local_a8 = 0;
  FUN_08035d8c(auStack_a4,0,0x7c);
  do {
    iVar3 = FUN_08027288(*DAT_08028168,&local_a8,0x58,0xffffffff);
    if (iVar3 == 0) {
      switch(local_a8) {
      case 1:
      case 9:
        FUN_08029a58(0,0,auStack_90,local_9c);
        break;
      case 3:
        local_b0 = 0;
        uStack_ac = 0;
        if ((local_98 < 0x100) || (local_98 == 0x700)) {
          uVar8 = local_9c >> 3;
          uVar5 = local_9c & 7;
          if (uVar5 != 0) {
            uVar8 = uVar8 + 1;
          }
          puVar7 = auStack_90;
          for (uVar6 = 0; uVar8 != uVar6; uVar6 = uVar6 + 1) {
            FUN_0802238c(&local_b0,puVar7);
            if ((uVar8 - 1 != uVar6) || (uVar4 = uVar5, uVar5 == 0)) {
              uVar4 = 8;
            }
            FUN_08028fcc(0,local_98,&local_b0,uVar4);
            thunk_FUN_0802fec8(1);
            puVar7 = puVar7 + 8;
          }
        }
        else {
          uVar8 = local_9c / 7;
          uVar5 = local_9c % 7;
          if (uVar5 != 0) {
            uVar8 = uVar8 + 1;
          }
          puVar7 = auStack_90;
          for (uVar6 = 0; uVar8 != uVar6; uVar6 = uVar6 + 1) {
            local_b0 = CONCAT31(local_b0._1_3_,(byte)(uVar8 << 4) | (byte)uVar6);
            FUN_0802238c((int)&local_b0 + 1,puVar7);
            iVar3 = uVar5 + 1;
            if (uVar8 - 1 != uVar6) {
              iVar3 = 8;
            }
            FUN_08028fcc(0,local_98,&local_b0,iVar3);
            thunk_FUN_0802fec8(1);
            puVar7 = puVar7 + 7;
          }
        }
        break;
      case 4:
        FUN_08028ffc(local_94,local_98,auStack_90,local_9c & 0xff);
      }
    }
    sVar1 = *(short *)(iVar2 + 0x38);
    if (sVar1 == 0) {
      sVar1 = 1;
    }
    thunk_FUN_0802fec8(sVar1);
  } while( true );
}


