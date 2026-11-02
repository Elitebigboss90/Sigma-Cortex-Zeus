// FUNCTION 1405784a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_1405784a0(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined **ppuVar7;
  undefined1 *puVar8;
  undefined1 auStack_458 [32];
  char cStack_438;
  uint uStack_434;
  undefined1 uStack_430;
  undefined1 auStack_42f [3];
  uint uStack_42c;
  uint uStack_428;
  uint uStack_424;
  longlong lStack_420;
  longlong *plStack_418;
  longlong *plStack_410;
  longlong *plStack_408;
  longlong *plStack_400;
  longlong lStack_3f8;
  longlong lStack_3f0;
  ulonglong uStack_3e0;
  longlong lStack_3d8;
  undefined8 uStack_3d0;
  undefined8 uStack_3c8;
  undefined1 *puStack_3c0;
  longlong lStack_3b8;
  undefined8 uStack_3b0;
  longlong lStack_3a8;
  longlong *plStack_3a0;
  longlong lStack_398;
  longlong *plStack_390;
  longlong lStack_388;
  undefined1 *puStack_380;
  undefined8 uStack_378;
  longlong lStack_370;
  longlong lStack_368;
  longlong lStack_360;
  longlong lStack_358;
  longlong lStack_350;
  longlong lStack_348;
  longlong *plStack_340;
  undefined1 auStack_330 [8];
  undefined1 *puStack_328;
  longlong *plStack_320;
  undefined1 auStack_310 [8];
  undefined1 *puStack_308;
  longlong lStack_2f0;
  undefined8 uStack_2e8;
  undefined *puStack_2e0;
  undefined4 uStack_2d8;
  undefined *puStack_2d0;
  undefined *puStack_2c8;
  undefined4 uStack_2c0;
  undefined *puStack_2b8;
  undefined *puStack_2b0;
  undefined4 uStack_2a8;
  undefined *puStack_2a0;
  undefined *puStack_298;
  undefined4 uStack_290;
  undefined *puStack_288;
  undefined1 auStack_280 [8];
  longlong *plStack_278;
  longlong *plStack_270;
  undefined1 auStack_268 [8];
  undefined1 auStack_260 [24];
  undefined1 auStack_248 [32];
  undefined1 auStack_228 [32];
  undefined1 auStack_208 [32];
  undefined1 auStack_1e8 [32];
  undefined1 auStack_1c8 [13];
  undefined1 uStack_1bb;
  ushort uStack_1ba;
  undefined1 uStack_1a9;
  undefined1 uStack_199;
  int iStack_198;
  undefined1 auStack_188 [256];
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined1 uStack_86;
  undefined1 uStack_85;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined1 uStack_82;
  undefined1 uStack_81;
  undefined1 uStack_80;
  undefined1 uStack_7f;
  undefined1 uStack_7e;
  undefined1 uStack_7d;
  undefined1 uStack_7c;
  undefined1 uStack_7b;
  undefined1 uStack_7a;
  undefined1 uStack_79;
  undefined1 uStack_78;
  undefined1 uStack_77;
  undefined1 uStack_76;
  undefined1 uStack_75;
  undefined1 uStack_74;
  undefined1 uStack_73;
  undefined1 uStack_72;
  undefined1 uStack_71;
  undefined1 uStack_70;
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  undefined1 uStack_6d;
  undefined1 uStack_6c;
  undefined1 uStack_6b;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined1 uStack_66;
  undefined1 uStack_65;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 uStack_59;
  undefined1 uStack_58;
  undefined1 uStack_57;
  undefined1 uStack_56;
  undefined1 uStack_55;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 auStack_48 [32];
  ulonglong uStack_28;
  
  uStack_28 = _DAT_1417011c0 ^ (ulonglong)auStack_458;
  iVar1 = FUN_1401f3fc0(param_2,param_1 + 0x30);
  if (iVar1 == 0) {
    FUN_1400dadd0(param_1 + 0x50,param_2);
    uStack_3e0 = *(ulonglong *)(param_1 + 0x40);
    if (uStack_3e0 < 0x40) {
      puStack_2c8 = &UNK_141348d80;
      uStack_2c0 = 0x80;
      puStack_2b8 = &UNK_141348df0;
      ppuVar7 = &puStack_2c8;
      puVar6 = auStack_228;
      for (lVar5 = 0x18; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar6 = *(undefined1 *)ppuVar7;
        ppuVar7 = (undefined **)((longlong)ppuVar7 + 1);
        puVar6 = puVar6 + 1;
      }
      FUN_1401cb600(4,auStack_228,&UNK_141348d60);
    }
    else {
      func_0x00014107e1bb(auStack_1c8,0,0x40);
      uVar3 = FUN_1400d6c70(param_1 + 0x30);
      func_0x00014107e1af(auStack_1c8,uVar3,0x40);
      uStack_1bb = 0;
      uStack_1a9 = 0;
      uStack_199 = 0;
      iVar1 = strncmp(auStack_1c8,&UNK_141348e00,0xd);
      if (iVar1 == 0) {
        lStack_3d8 = *(longlong *)(param_1 + 0x40);
        if ((ulonglong)(longlong)iStack_198 <= lStack_3d8 - 0x40U) {
          uStack_3d0 = *(undefined8 *)(param_1 + 0x40);
          *(int *)(param_1 + 0x20) = (int)uStack_3d0;
          uStack_42c = (uint)uStack_1ba;
          if (uStack_42c == 0) {
            uVar2 = FUN_140579ac0(param_1,auStack_1c8);
            *(undefined4 *)(param_1 + 0x70) = uVar2;
          }
          else if (uStack_42c == 0x40) {
            uVar2 = FUN_14057a0e0(param_1,auStack_1c8);
            *(undefined4 *)(param_1 + 0x70) = uVar2;
          }
          if (*(int *)(param_1 + 0x70) == 0) {
            puStack_298 = &UNK_141348ed0;
            uStack_290 = 0xa5;
            puStack_288 = &UNK_141348f40;
            ppuVar7 = &puStack_298;
            puVar6 = auStack_1e8;
            for (lVar5 = 0x18; lVar5 != 0; lVar5 = lVar5 + -1) {
              *puVar6 = *(undefined1 *)ppuVar7;
              ppuVar7 = (undefined **)((longlong)ppuVar7 + 1);
              puVar6 = puVar6 + 1;
            }
            FUN_1401cb600(4,auStack_1e8,&UNK_141348eb0);
          }
          else {
            *(undefined4 *)(param_1 + 0x24) = 0x40;
            cStack_438 = '\x01';
            if (((((((((*(int *)(param_1 + 0x70) == 0x18) || (*(int *)(param_1 + 0x70) == 0x19)) ||
                     (*(int *)(param_1 + 0x70) == 0x1a)) ||
                    ((*(int *)(param_1 + 0x70) == 0x1b || (*(int *)(param_1 + 0x70) == 0x1c)))) ||
                   (*(int *)(param_1 + 0x70) == 0x20)) ||
                  (((*(int *)(param_1 + 0x70) == 0x21 || (*(int *)(param_1 + 0x70) == 0x25)) ||
                   ((*(int *)(param_1 + 0x70) == 0x26 ||
                    (((*(int *)(param_1 + 0x70) == 0x27 || (*(int *)(param_1 + 0x70) == 0xe)) ||
                     (*(int *)(param_1 + 0x70) == 0x22)))))))) ||
                 ((*(int *)(param_1 + 0x70) == 0x28 || (*(int *)(param_1 + 0x70) == 0x2e)))) ||
                (((*(int *)(param_1 + 0x70) == 0x2a ||
                  (((*(int *)(param_1 + 0x70) == 0x2b || (*(int *)(param_1 + 0x70) == 0x2c)) ||
                   ((*(int *)(param_1 + 0x70) == 0x2d ||
                    (((*(int *)(param_1 + 0x70) == 0x29 || (*(int *)(param_1 + 0x70) == 0x2f)) ||
                     (*(int *)(param_1 + 0x70) == 0x30)))))))) ||
                 (((*(int *)(param_1 + 0x70) == 0x32 || (*(int *)(param_1 + 0x70) == 0x1f)) ||
                  (*(int *)(param_1 + 0x70) == 0x1e)))))) ||
               ((*(int *)(param_1 + 0x70) == 0x1d || (*(int *)(param_1 + 0x70) == 0x31)))) {
              cStack_438 = '\0';
            }
            if (cStack_438 != '\0') {
              uStack_68 = 0x20;
              uStack_67 = 0x37;
              uStack_66 = 0xdf;
              uStack_65 = 0x28;
              uStack_64 = 0x88;
              uStack_63 = 0xab;
              uStack_62 = 0x45;
              uStack_61 = 0xf7;
              uStack_60 = 0x84;
              uStack_5f = 0x11;
              uStack_5e = 0x78;
              uStack_5d = 0xe2;
              uStack_5c = 0x5d;
              uStack_5b = 0x25;
              uStack_5a = 0x99;
              uStack_59 = 0x8c;
              uStack_58 = 0x99;
              uStack_57 = 0xaa;
              uStack_56 = 0x34;
              uStack_55 = 0x77;
              uStack_54 = 0x43;
              uStack_53 = 0x83;
              uStack_52 = 0xee;
              uStack_51 = 0x92;
              uStack_50 = 0x22;
              uStack_4f = 0x34;
              uStack_4e = 0x12;
              uStack_4d = 0x98;
              uStack_4c = 0x33;
              uStack_4b = 0x83;
              uStack_4a = 0x32;
              uStack_49 = 0x84;
              uStack_88 = 0x34;
              uStack_87 = 0x34;
              uStack_86 = 0x13;
              uStack_85 = 0x99;
              uStack_84 = 0x12;
              uStack_83 = 0x35;
              uStack_82 = 0xdd;
              uStack_81 = 0xf3;
              uStack_80 = 0x39;
              uStack_7f = 0x38;
              uStack_7e = 0x99;
              uStack_7d = 0xa1;
              uStack_7c = 0xaa;
              uStack_7b = 0x84;
              uStack_7a = 0x32;
              uStack_79 = 0x99;
              uStack_78 = 0x67;
              uStack_77 = 0x83;
              uStack_76 = 0xe1;
              uStack_75 = 0x77;
              uStack_74 = 0x24;
              uStack_73 = 0x99;
              uStack_72 = 0xae;
              uStack_71 = 0x11;
              uStack_70 = 0x98;
              uStack_6f = 0x34;
              uStack_6e = 0x83;
              uStack_6d = 0xf6;
              uStack_6c = 0x70;
              uStack_6b = 0x5d;
              uStack_6a = 0x45;
              uStack_69 = 0x77;
              puVar6 = auStack_48;
              for (lVar5 = 0x20; lVar5 != 0; lVar5 = lVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
              FUN_140b7fc80(auStack_188,&uStack_68,&uStack_88);
              uStack_3c8 = *(undefined8 *)(param_1 + 0x40);
              uStack_424 = (int)uStack_3c8 - 0x40;
              puStack_3c0 = &uStack_430;
              lStack_3b8 = param_1 + 0x30;
              puStack_380 = puStack_3c0;
              puVar4 = (undefined8 *)FUN_14010c2a0(lStack_3b8,auStack_268);
              uStack_3b0 = *puVar4;
              lStack_3a8 = param_1 + 0x30;
              uStack_378 = uStack_3b0;
              plStack_3a0 = (longlong *)FUN_140107290(lStack_3a8,auStack_280);
              lStack_420 = *plStack_3a0 + 0x40;
              plStack_390 = &lStack_398;
              lStack_398 = lStack_420;
              lStack_388 = lStack_420;
              lStack_370 = lStack_420;
              FUN_140382cc0(&lStack_3f8,lStack_420,uStack_378,puStack_380);
              uStack_428 = uStack_424 % 0x20;
              if (uStack_428 != 0) {
                plStack_418 = &lStack_3f8;
                lStack_368 = lStack_3f0 - lStack_3f8;
                FUN_1403304f0(&lStack_3f8,lStack_368 + (int)uStack_428,auStack_42f);
              }
              for (uStack_434 = 0; uStack_434 < uStack_424; uStack_434 = uStack_434 + 0x20) {
                lStack_360 = lStack_3f8;
                lStack_358 = lStack_3f8;
                lStack_350 = lStack_3f8;
                FUN_140b7fd10(auStack_188,lStack_3f8 + (int)uStack_434,0x20);
              }
              plStack_410 = &lStack_3f8;
              lStack_348 = lStack_3f0 - lStack_3f8;
              *(int *)(param_1 + 0x20) = (int)lStack_348;
              FUN_1401055c0(param_1 + 0x30,0);
              lStack_2f0 = param_1 + 0x30;
              plStack_408 = &lStack_3f8;
              puStack_328 = auStack_330;
              plStack_400 = &lStack_3f8;
              puStack_308 = auStack_310;
              plStack_340 = plStack_408;
              plStack_320 = plStack_400;
              plStack_278 = plStack_408;
              plStack_270 = plStack_400;
              FUN_14057b0c0(lStack_2f0,lStack_3f8,lStack_3f0);
              *(undefined4 *)(param_1 + 0x24) = 0;
              FUN_1400dc0b0(&lStack_3f8);
            }
          }
        }
      }
      else {
        puStack_2b0 = &UNK_141348e30;
        uStack_2a8 = 0x8f;
        puStack_2a0 = &UNK_141348ea0;
        ppuVar7 = &puStack_2b0;
        puVar6 = auStack_208;
        for (lVar5 = 0x18; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar6 = *(undefined1 *)ppuVar7;
          ppuVar7 = (undefined **)((longlong)ppuVar7 + 1);
          puVar6 = puVar6 + 1;
        }
        FUN_1401cb600(4,auStack_208,&UNK_141348e10);
      }
    }
  }
  else {
    uStack_2e8 = FUN_1400d6c70(param_2);
    puStack_2e0 = &UNK_141348ce0;
    uStack_2d8 = 0x78;
    puStack_2d0 = &UNK_141348d50;
    ppuVar7 = &puStack_2e0;
    puVar6 = auStack_260;
    for (lVar5 = 0x18; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar6 = *(undefined1 *)ppuVar7;
      ppuVar7 = (undefined **)((longlong)ppuVar7 + 1);
      puVar6 = puVar6 + 1;
    }
    puVar6 = auStack_260;
    puVar8 = auStack_248;
    for (lVar5 = 0x18; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_1401cb600(4,auStack_248,&UNK_141348cc8,uStack_2e8);
  }
  FUN_14107c400(uStack_28 ^ (ulonglong)auStack_458);
  return;
}


// 1405784a0 MOV qword ptr [RSP + 0x10],RDX
// FUNCTION 140139390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140139390(undefined8 param_1)

{
  longlong lVar1;
  undefined1 **ppuVar2;
  undefined1 *puVar3;
  undefined1 auStack_ed8 [32];
  uint uStack_eb8;
  undefined *puStack_eb0;
  undefined1 *puStack_ea8;
  undefined *puStack_ea0;
  undefined1 *puStack_e98;
  undefined *puStack_e90;
  undefined1 *puStack_e88;
  undefined *puStack_e80;
  undefined1 *puStack_e78;
  undefined *puStack_e70;
  undefined1 *puStack_e68;
  undefined *puStack_e60;
  undefined1 *puStack_e58;
  undefined *puStack_e50;
  undefined1 *puStack_e48;
  undefined *puStack_e40;
  undefined1 *puStack_e38;
  undefined *puStack_e30;
  undefined1 *puStack_e28;
  undefined *puStack_e20;
  undefined1 *puStack_e18;
  undefined *puStack_e10;
  undefined1 *puStack_e08;
  undefined *puStack_e00;
  undefined1 *puStack_df8;
  undefined *puStack_df0;
  undefined1 *puStack_de8;
  undefined *puStack_de0;
  undefined1 *puStack_dd8;
  undefined *puStack_dd0;
  undefined1 *puStack_dc8;
  undefined *puStack_dc0;
  undefined1 *puStack_db8;
  undefined *puStack_db0;
  undefined1 *puStack_da8;
  undefined *puStack_da0;
  undefined1 *puStack_d98;
  undefined *puStack_d90;
  undefined1 *puStack_d88;
  undefined *puStack_d80;
  undefined1 *puStack_d78;
  undefined *puStack_d70;
  undefined1 *puStack_d68;
  undefined *puStack_d60;
  undefined1 *puStack_d58;
  undefined *puStack_d50;
  undefined1 *puStack_d48;
  undefined *puStack_d40;
  undefined1 *puStack_d38;
  undefined *puStack_d30;
  undefined1 *puStack_d28;
  undefined *puStack_d20;
  undefined1 *puStack_d18;
  undefined *puStack_d10;
  undefined1 *puStack_d08;
  undefined *puStack_d00;
  undefined1 *puStack_cf8;
  undefined *puStack_cf0;
  undefined1 *puStack_ce8;
  undefined *puStack_ce0;
  undefined1 *puStack_cd8;
  undefined *puStack_cd0;
  undefined1 *puStack_cc8;
  undefined *puStack_cc0;
  undefined1 *puStack_cb8;
  undefined *puStack_cb0;
  undefined1 *puStack_ca8;
  undefined *puStack_ca0;
  undefined1 *puStack_c98;
  undefined *puStack_c90;
  undefined1 *puStack_c88;
  undefined *puStack_c80;
  undefined1 *puStack_c78;
  undefined *puStack_c70;
  undefined1 *puStack_c68;
  undefined *puStack_c60;
  undefined1 *puStack_c58;
  undefined *puStack_c50;
  undefined1 *puStack_c48;
  undefined *puStack_c40;
  undefined1 *puStack_c38;
  undefined *puStack_c30;
  undefined1 *puStack_c28;
  undefined *puStack_c20;
  undefined1 *puStack_c18;
  undefined *puStack_c10;
  undefined1 *puStack_c08;
  undefined *puStack_c00;
  undefined1 *puStack_bf8;
  undefined *puStack_bf0;
  undefined1 *puStack_be8;
  undefined *puStack_be0;
  undefined1 *puStack_bd8;
  undefined *puStack_bd0;
  undefined1 *puStack_bc8;
  undefined *puStack_bc0;
  undefined1 *puStack_bb8;
  undefined *puStack_bb0;
  undefined1 *puStack_ba8;
  undefined *puStack_ba0;
  undefined1 *puStack_b98;
  undefined *puStack_b90;
  undefined1 *puStack_b88;
  undefined *puStack_b80;
  undefined1 *puStack_b78;
  undefined *puStack_b70;
  undefined1 *puStack_b68;
  undefined *puStack_b60;
  undefined1 *puStack_b58;
  undefined *puStack_b50;
  undefined1 *puStack_b48;
  undefined *puStack_b40;
  undefined1 *puStack_b38;
  undefined *puStack_b30;
  undefined1 *puStack_b28;
  undefined *puStack_b20;
  undefined1 *puStack_b18;
  undefined *puStack_b10;
  undefined1 *puStack_b08;
  undefined *puStack_b00;
  undefined1 *puStack_af8;
  undefined *puStack_af0;
  undefined1 *puStack_ae8;
  undefined *puStack_ae0;
  undefined1 *puStack_ad8;
  undefined *puStack_ad0;
  undefined1 *puStack_ac8;
  undefined *puStack_ac0;
  undefined1 *puStack_ab8;
  undefined1 **ppuStack_ab0;
  undefined1 *puStack_aa8;
  undefined1 *puStack_aa0;
  undefined8 uStack_a98;
  undefined1 auStack_a88 [16];
  undefined1 auStack_a78 [32];
  undefined1 auStack_a58 [32];
  undefined1 auStack_a38 [32];
  undefined1 auStack_a18 [32];
  undefined1 auStack_9f8 [32];
  undefined1 auStack_9d8 [32];
  undefined1 auStack_9b8 [32];
  undefined1 auStack_998 [32];
  undefined1 auStack_978 [32];
  undefined1 auStack_958 [32];
  undefined1 auStack_938 [32];
  undefined1 auStack_918 [32];
  undefined1 auStack_8f8 [32];
  undefined1 auStack_8d8 [32];
  undefined1 auStack_8b8 [32];
  undefined1 auStack_898 [32];
  undefined1 auStack_878 [32];
  undefined1 auStack_858 [32];
  undefined1 auStack_838 [32];
  undefined1 auStack_818 [32];
  undefined1 auStack_7f8 [32];
  undefined1 auStack_7d8 [32];
  undefined1 auStack_7b8 [32];
  undefined1 auStack_798 [32];
  undefined1 auStack_778 [32];
  undefined1 auStack_758 [32];
  undefined1 auStack_738 [32];
  undefined1 auStack_718 [32];
  undefined1 auStack_6f8 [32];
  undefined1 auStack_6d8 [32];
  undefined1 auStack_6b8 [32];
  undefined1 auStack_698 [32];
  undefined1 auStack_678 [32];
  undefined1 auStack_658 [32];
  undefined1 auStack_638 [32];
  undefined1 auStack_618 [32];
  undefined1 auStack_5f8 [32];
  undefined1 auStack_5d8 [32];
  undefined1 auStack_5b8 [32];
  undefined1 auStack_598 [32];
  undefined1 auStack_578 [32];
  undefined1 auStack_558 [32];
  undefined1 auStack_538 [32];
  undefined1 auStack_518 [32];
  undefined1 auStack_4f8 [32];
  undefined1 auStack_4d8 [32];
  undefined1 auStack_4b8 [32];
  undefined1 auStack_498 [32];
  undefined1 auStack_478 [32];
  undefined1 auStack_458 [32];
  undefined1 auStack_438 [32];
  undefined1 auStack_418 [32];
  undefined1 auStack_3f8 [32];
  undefined1 auStack_3d8 [32];
  undefined1 auStack_3b8 [32];
  undefined1 auStack_398 [32];
  undefined1 auStack_378 [32];
  undefined1 auStack_358 [32];
  undefined1 auStack_338 [32];
  undefined1 auStack_318 [32];
  undefined1 auStack_2f8 [32];
  undefined1 auStack_2d8 [32];
  undefined1 auStack_2b8 [32];
  undefined1 auStack_298 [32];
  undefined1 auStack_278 [64];
  undefined1 auStack_238 [64];
  undefined1 auStack_1f8 [64];
  undefined1 auStack_1b8 [64];
  undefined1 auStack_178 [64];
  undefined1 auStack_138 [64];
  undefined1 auStack_f8 [64];
  undefined1 auStack_b8 [64];
  undefined1 auStack_78 [64];
  undefined1 auStack_38 [16];
  ulonglong uStack_28;
  
  uStack_28 = _DAT_1417011c0 ^ (ulonglong)auStack_ed8;
  uStack_eb8 = 0;
  puStack_ea8 = auStack_a78;
  puStack_eb0 = &UNK_1412a9398;
  FUN_1400d2110(puStack_ea8,&UNK_1412a9398);
  puStack_e98 = auStack_a58;
  puStack_ea0 = &UNK_1412a9330;
  FUN_1400d2110(puStack_e98,&UNK_1412a9330);
  puStack_e88 = auStack_a38;
  puStack_e90 = &UNK_1412a9428;
  FUN_1400d2110(puStack_e88,&UNK_1412a9428);
  puStack_e78 = auStack_a18;
  puStack_e80 = &UNK_1412a93c0;
  FUN_1400d2110(puStack_e78,&UNK_1412a93c0);
  puStack_e68 = auStack_9f8;
  puStack_e70 = &UNK_1412a94f0;
  FUN_1400d2110(puStack_e68,&UNK_1412a94f0);
  puStack_e58 = auStack_9d8;
  puStack_e60 = &UNK_1412a9450;
  FUN_1400d2110(puStack_e58,&UNK_1412a9450);
  puStack_e48 = auStack_9b8;
  puStack_e50 = &UNK_1412a9590;
  FUN_1400d2110(puStack_e48,&UNK_1412a9590);
  puStack_e38 = auStack_998;
  puStack_e40 = &UNK_1412a9510;
  FUN_1400d2110(puStack_e38,&UNK_1412a9510);
  puStack_e28 = auStack_978;
  puStack_e30 = &UNK_1412a9638;
  FUN_1400d2110(puStack_e28,&UNK_1412a9638);
  puStack_e18 = auStack_958;
  puStack_e20 = &UNK_1412a95b0;
  FUN_1400d2110(puStack_e18,&UNK_1412a95b0);
  puStack_e08 = auStack_938;
  puStack_e10 = &UNK_1412a96c0;
  FUN_1400d2110(puStack_e08,&UNK_1412a96c0);
  puStack_df8 = auStack_918;
  puStack_e00 = &UNK_1412a9660;
  FUN_1400d2110(puStack_df8,&UNK_1412a9660);
  puStack_de8 = auStack_8f8;
  puStack_df0 = &UNK_1412a9738;
  FUN_1400d2110(puStack_de8,&UNK_1412a9738);
  puStack_dd8 = auStack_8d8;
  puStack_de0 = &UNK_1412a96e0;
  FUN_1400d2110(puStack_dd8,&UNK_1412a96e0);
  puStack_dc8 = auStack_8b8;
  puStack_dd0 = &UNK_1412a97d0;
  FUN_1400d2110(puStack_dc8,&UNK_1412a97d0);
  puStack_db8 = auStack_898;
  puStack_dc0 = &UNK_1412a9760;
  FUN_1400d2110(puStack_db8,&UNK_1412a9760);
  puStack_da8 = auStack_878;
  puStack_db0 = &UNK_1412a9850;
  FUN_1400d2110(puStack_da8,&UNK_1412a9850);
  puStack_d98 = auStack_858;
  puStack_da0 = &UNK_1412a97f0;
  FUN_1400d2110(puStack_d98,&UNK_1412a97f0);
  puStack_d88 = auStack_838;
  puStack_d90 = &UNK_1412a98d0;
  FUN_1400d2110(puStack_d88,&UNK_1412a98d0);
  puStack_d78 = auStack_818;
  puStack_d80 = &UNK_1412a9870;
  FUN_1400d2110(puStack_d78,&UNK_1412a9870);
  puStack_d68 = auStack_7f8;
  puStack_d70 = &UNK_1412a9960;
  FUN_1400d2110(puStack_d68,&UNK_1412a9960);
  puStack_d58 = auStack_7d8;
  puStack_d60 = &UNK_1412a98f0;
  FUN_1400d2110(puStack_d58,&UNK_1412a98f0);
  puStack_d48 = auStack_7b8;
  puStack_d50 = &UNK_1412a9980;
  FUN_1400d2110(puStack_d48,&UNK_1412a9980);
  puStack_d38 = auStack_798;
  puStack_d40 = &UNK_1412a9978;
  FUN_1400d2110(puStack_d38,&UNK_1412a9978);
  puStack_d28 = auStack_778;
  puStack_d30 = &UNK_1412a9a00;
  FUN_1400d2110(puStack_d28,&UNK_1412a9a00);
  puStack_d18 = auStack_758;
  puStack_d20 = &UNK_1412a99a0;
  FUN_1400d2110(puStack_d18,&UNK_1412a99a0);
  puStack_d08 = auStack_738;
  puStack_d10 = &UNK_1412a9a90;
  FUN_1400d2110(puStack_d08,&UNK_1412a9a90);
  puStack_cf8 = auStack_718;
  puStack_d00 = &UNK_1412a9a20;
  FUN_1400d2110(puStack_cf8,&UNK_1412a9a20);
  puStack_ce8 = auStack_6f8;
  puStack_cf0 = &UNK_1412a9b18;
  FUN_1400d2110(puStack_ce8,&UNK_1412a9b18);
  puStack_cd8 = auStack_6d8;
  puStack_ce0 = &UNK_1412a9ab0;
  FUN_1400d2110(puStack_cd8,&UNK_1412a9ab0);
  puStack_cc8 = auStack_6b8;
  puStack_cd0 = &UNK_1412a9ba0;
  FUN_1400d2110(puStack_cc8,&UNK_1412a9ba0);
  puStack_cb8 = auStack_698;
  puStack_cc0 = &UNK_1412a9b30;
  FUN_1400d2110(puStack_cb8,&UNK_1412a9b30);
  puStack_ca8 = auStack_678;
  puStack_cb0 = &UNK_1412a9c20;
  FUN_1400d2110(puStack_ca8,&UNK_1412a9c20);
  puStack_c98 = auStack_658;
  puStack_ca0 = &UNK_1412a9bc0;
  FUN_1400d2110(puStack_c98,&UNK_1412a9bc0);
  puStack_c88 = auStack_638;
  puStack_c90 = &UNK_1412a9ca8;
  FUN_1400d2110(puStack_c88,&UNK_1412a9ca8);
  puStack_c78 = auStack_618;
  puStack_c80 = &UNK_1412a9c40;
  FUN_1400d2110(puStack_c78,&UNK_1412a9c40);
  puStack_c68 = auStack_5f8;
  puStack_c70 = &UNK_1412a9d40;
  FUN_1400d2110(puStack_c68,&UNK_1412a9d40);
  puStack_c58 = auStack_5d8;
  puStack_c60 = &UNK_1412a9cc0;
  FUN_1400d2110(puStack_c58,&UNK_1412a9cc0);
  puStack_c48 = auStack_5b8;
  puStack_c50 = &UNK_1412a9db8;
  FUN_1400d2110(puStack_c48,&UNK_1412a9db8);
  puStack_c38 = auStack_598;
  puStack_c40 = &UNK_1412a9d60;
  FUN_1400d2110(puStack_c38,&UNK_1412a9d60);
  puStack_c28 = auStack_578;
  puStack_c30 = &UNK_1412a9e38;
  FUN_1400d2110(puStack_c28,&UNK_1412a9e38);
  puStack_c18 = auStack_558;
  puStack_c20 = &UNK_1412a9dd0;
  FUN_1400d2110(puStack_c18,&UNK_1412a9dd0);
  puStack_c08 = auStack_538;
  puStack_c10 = &UNK_1412a9ed0;
  FUN_1400d2110(puStack_c08,&UNK_1412a9ed0);
  puStack_bf8 = auStack_518;
  puStack_c00 = &UNK_1412a9e50;
  FUN_1400d2110(puStack_bf8,&UNK_1412a9e50);
  puStack_be8 = auStack_4f8;
  puStack_bf0 = &UNK_1412a9f50;
  FUN_1400d2110(puStack_be8,&UNK_1412a9f50);
  puStack_bd8 = auStack_4d8;
  puStack_be0 = &UNK_1412a9ef0;
  FUN_1400d2110(puStack_bd8,&UNK_1412a9ef0);
  puStack_bc8 = auStack_4b8;
  puStack_bd0 = &UNK_1412a9fd8;
  FUN_1400d2110(puStack_bc8,&UNK_1412a9fd8);
  puStack_bb8 = auStack_498;
  puStack_bc0 = &UNK_1412a9f70;
  FUN_1400d2110(puStack_bb8,&UNK_1412a9f70);
  puStack_ba8 = auStack_478;
  puStack_bb0 = &UNK_1412aa050;
  FUN_1400d2110(puStack_ba8,&UNK_1412aa050);
  puStack_b98 = auStack_458;
  puStack_ba0 = &UNK_1412a9ff0;
  FUN_1400d2110(puStack_b98,&UNK_1412a9ff0);
  puStack_b88 = auStack_438;
  puStack_b90 = &UNK_1412aa0d0;
  FUN_1400d2110(puStack_b88,&UNK_1412aa0d0);
  puStack_b78 = auStack_418;
  puStack_b80 = &UNK_1412aa070;
  FUN_1400d2110(puStack_b78,&UNK_1412aa070);
  puStack_b68 = auStack_3f8;
  puStack_b70 = &UNK_1412aa150;
  FUN_1400d2110(puStack_b68,&UNK_1412aa150);
  puStack_b58 = auStack_3d8;
  puStack_b60 = &UNK_1412aa0f0;
  FUN_1400d2110(puStack_b58,&UNK_1412aa0f0);
  puStack_b48 = auStack_3b8;
  puStack_b50 = &UNK_1412aa1d0;
  FUN_1400d2110(puStack_b48,&UNK_1412aa1d0);
  puStack_b38 = auStack_398;
  puStack_b40 = &UNK_1412aa170;
  FUN_1400d2110(puStack_b38,&UNK_1412aa170);
  puStack_b28 = auStack_378;
  puStack_b30 = &UNK_1412aa278;
  FUN_1400d2110(puStack_b28,&UNK_1412aa278);
  puStack_b18 = auStack_358;
  puStack_b20 = &UNK_1412aa1f0;
  FUN_1400d2110(puStack_b18,&UNK_1412aa1f0);
  puStack_b08 = auStack_338;
  puStack_b10 = &UNK_1412aa308;
  FUN_1400d2110(puStack_b08,&UNK_1412aa308);
  puStack_af8 = auStack_318;
  puStack_b00 = &UNK_1412aa290;
  FUN_1400d2110(puStack_af8,&UNK_1412aa290);
  puStack_ae8 = auStack_2f8;
  puStack_af0 = &UNK_1412aa390;
  FUN_1400d2110(puStack_ae8,&UNK_1412aa390);
  puStack_ad8 = auStack_2d8;
  puStack_ae0 = &UNK_1412aa320;
  FUN_1400d2110(puStack_ad8,&UNK_1412aa320);
  puStack_ac8 = auStack_2b8;
  puStack_ad0 = &UNK_1412aa410;
  FUN_1400d2110(puStack_ac8,&UNK_1412aa410);
  puStack_ab8 = auStack_298;
  puStack_ac0 = &UNK_1412aa3b0;
  FUN_1400d2110(puStack_ab8,&UNK_1412aa3b0);
  FUN_140147b80(auStack_278,&UNK_1412aa498,&UNK_1412aa430);
  FUN_140147b80(auStack_238,&UNK_1412aa528,&UNK_1412aa4b0);
  FUN_140147b80(auStack_1f8,&UNK_1412aa5c8,&UNK_1412aa550);
  FUN_140147b80(auStack_1b8,&UNK_1412aa670,&UNK_1412aa5f0);
  FUN_140147b80(auStack_178,&UNK_1412aa6f8,&UNK_1412aa690);
  FUN_140147b80(auStack_138,&UNK_1412aa798,&UNK_1412aa720);
  FUN_140147b80(auStack_f8,&UNK_1412aa830,&UNK_1412aa7c0);
  FUN_140147b80(auStack_b8,&UNK_1412aa8c0,&UNK_1412aa850);
  FUN_140147b80(auStack_78,&UNK_1412aa940,&UNK_1412aa8e0);
  puStack_aa8 = auStack_a78;
  puStack_aa0 = auStack_38;
  ppuStack_ab0 = &puStack_aa8;
  ppuVar2 = ppuStack_ab0;
  puVar3 = auStack_a88;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *(undefined1 *)ppuVar2;
    ppuVar2 = (undefined1 **)((longlong)ppuVar2 + 1);
    puVar3 = puVar3 + 1;
  }
  uStack_a98 = FUN_140150240(param_1,auStack_a88);
  uStack_eb8 = uStack_eb8 | 1;
  FUN_14107c4b0(auStack_a78,0x40,0x29,FUN_1400e13c0);
  FUN_14107c400(uStack_28 ^ (ulonglong)auStack_ed8);
  return;
}


// 140139390 MOV qword ptr [RSP + 0x8],RCX
// FUNCTION 141083f10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_141083f10(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined1 auStack_188 [32];
  undefined4 *puStack_168;
  ulonglong uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  int iStack_138;
  undefined4 uStack_134;
  int iStack_130;
  longlong lStack_128;
  undefined4 *puStack_120;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined1 *puStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined1 auStack_e0 [16];
  undefined1 auStack_d0 [16];
  undefined1 auStack_c0 [16];
  undefined1 auStack_b0 [16];
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [16];
  undefined4 uStack_80;
  undefined2 uStack_7c;
  undefined2 uStack_7a;
  undefined1 uStack_78;
  undefined1 uStack_77;
  undefined1 uStack_76;
  undefined1 uStack_75;
  undefined1 uStack_74;
  undefined1 uStack_73;
  undefined1 uStack_72;
  undefined1 uStack_71;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [16];
  undefined8 uStack_40;
  undefined4 uStack_30;
  undefined1 auStack_2c [28];
  ulonglong uStack_10;
  
  uStack_10 = _DAT_1417011c0 ^ (ulonglong)auStack_188;
  uStack_80 = 0xa5dcbf10;
  uStack_7c = 0x6530;
  uStack_7a = 0x11d2;
  uStack_78 = 0x90;
  uStack_77 = 0x1f;
  uStack_76 = 0;
  uStack_75 = 0xc0;
  uStack_74 = 0x4f;
  uStack_73 = 0xb9;
  uStack_72 = 0x51;
  uStack_71 = 0xed;
  lStack_128 = SetupDiGetClassDevsW(&uStack_80,0,0,0x12);
  if (lStack_128 != -1) {
    uStack_30 = 0x20;
    puVar3 = auStack_2c;
    for (lVar2 = 0x1c; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    iStack_138 = 0;
    while( true ) {
      puStack_168 = &uStack_30;
      iVar1 = SetupDiEnumDeviceInterfaces(lStack_128,0,&uStack_80,iStack_138);
      if (iVar1 == 0) break;
      uStack_134 = 0;
      uStack_160 = 0;
      puStack_168 = &uStack_134;
      SetupDiGetDeviceInterfaceDetailW(lStack_128,&uStack_30,0,0);
      puStack_120 = (undefined4 *)malloc(uStack_134);
      *puStack_120 = 8;
      uStack_160 = 0;
      puStack_168 = (undefined4 *)0x0;
      iVar1 = SetupDiGetDeviceInterfaceDetailW(lStack_128,&uStack_30,puStack_120,uStack_134);
      if (iVar1 != 0) {
        FUN_140128030(auStack_50,puStack_120 + 1);
        uStack_110 = uStack_40;
        uStack_118 = (undefined4)uStack_40;
        uStack_108 = FUN_14012cae0(auStack_50);
        uStack_148 = 0;
        uStack_150 = 0;
        uStack_158 = 0;
        uStack_160 = uStack_160 & 0xffffffff00000000;
        puStack_168 = (undefined4 *)0x0;
        iStack_130 = LCMapStringEx(&UNK_14154f62c,0x100,uStack_108,uStack_118);
        puStack_100 = auStack_70;
        FUN_1400da900(puStack_100);
        FUN_140208630(auStack_70,0,(longlong)iStack_130);
        uStack_f0 = FUN_140129e60(auStack_70,0);
        uStack_f8 = uStack_40;
        uStack_114 = (undefined4)uStack_40;
        uStack_e8 = FUN_14012cae0(auStack_50);
        uStack_148 = 0;
        uStack_150 = 0;
        uStack_158 = 0;
        uStack_160 = CONCAT44(uStack_160._4_4_,iStack_130);
        puStack_168 = (undefined4 *)uStack_f0;
        LCMapStringEx(&UNK_14154f630,0x200,uStack_e8,uStack_114);
        lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f638,0);
        if ((lVar2 != -1) && (lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f650,0), lVar2 != -1)) {
          FUN_140321480(param_1,auStack_e0,auStack_70);
        }
        lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f668,0);
        if ((lVar2 != -1) && (lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f680,0), lVar2 != -1)) {
          FUN_140321480(param_1,auStack_d0,auStack_70);
        }
        lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f698,0);
        if ((lVar2 != -1) && (lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f6b0,0), lVar2 != -1)) {
          FUN_140321480(param_1,auStack_c0,auStack_70);
        }
        lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f6c8,0);
        if ((lVar2 != -1) && (lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f6e0,0), lVar2 != -1)) {
          FUN_140321480(param_1,auStack_b0,auStack_70);
        }
        lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f6f8,0);
        if ((lVar2 != -1) && (lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f710,0), lVar2 != -1)) {
          FUN_140321480(param_1,auStack_a0,auStack_70);
        }
        lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f728,0);
        if ((lVar2 != -1) && (lVar2 = FUN_1401f3b10(auStack_70,&UNK_14154f740,0), lVar2 != -1)) {
          FUN_140321480(param_1,auStack_90,auStack_70);
        }
        FUN_14012c4b0(auStack_70);
        FUN_14012c4b0(auStack_50);
      }
      free(puStack_120);
      iStack_138 = iStack_138 + 1;
    }
    SetupDiDestroyDeviceInfoList(lStack_128);
  }
  FUN_14107c400(uStack_10 ^ (ulonglong)auStack_188);
  return;
}


// 141083f10 MOV qword ptr [RSP + 0x8],RCX
