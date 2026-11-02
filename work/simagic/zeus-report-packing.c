// FUNCTION 08025514

undefined4 FUN_08025514(int param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined1 local_54;
  undefined1 local_53;
  byte abStack_52 [18];
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  byte abStack_3d [15];
  undefined4 local_2e;
  undefined1 local_2a;
  
  FUN_08035d8c(&local_40,0,0x17);
  iVar5 = DAT_08025840;
  FUN_08035d8c(&local_54,0);
  puVar1 = DAT_08025844;
  iVar4 = *(int *)(iVar5 + 0x18);
  iVar13 = *(int *)(iVar5 + 0x1c);
  bVar2 = 0;
  local_40 = 1;
  if (param_1 == 1) {
    for (; (int)(uint)bVar2 < iVar4; bVar2 = bVar2 + 1) {
      iVar3 = (uint)bVar2 * 0x28 + iVar13;
      if (*(int *)(iVar3 + 0x20) == 1) {
        iVar3 = *(int *)(iVar3 + 0x24);
        uVar11 = iVar3 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar3 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
      }
    }
    iVar4 = *(int *)(iVar5 + 0x30);
    iVar13 = *(int *)(iVar5 + 0x34);
    for (uVar6 = 0; (int)(uVar6 & 0xff) < iVar4; uVar6 = uVar6 + 1) {
      iVar3 = (uVar6 & 0xff) * 0x78 + iVar13;
      iVar9 = iVar3 + 0x70;
      do {
        if (*(int *)(iVar3 + 0x10) == 1) {
          uVar12 = *(int *)(iVar3 + 0x14) - 1;
          uVar11 = uVar12;
          if ((int)uVar12 < 0) {
            uVar11 = *(int *)(iVar3 + 0x14) + 6;
          }
          uVar10 = uVar12 & 7;
          if (-1 < (int)-uVar12) {
            uVar10 = -(-uVar12 & 7);
          }
          abStack_52[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_52[(int)uVar11 >> 3]
          ;
        }
        iVar3 = iVar3 + 0x10;
      } while (iVar9 != iVar3);
    }
    iVar4 = *(int *)(iVar5 + 0x60);
    iVar13 = *(int *)(iVar5 + 100);
    for (bVar2 = 0; uVar6 = (uint)bVar2, (int)uVar6 < iVar4; bVar2 = bVar2 + 1) {
      iVar3 = uVar6 * 0x13c + iVar13;
      iVar9 = *(int *)(iVar3 + 0x120);
      if (*(int *)(iVar3 + 0x10) == 0) {
        if (iVar9 == 1) {
          uVar12 = *(int *)(iVar3 + 0x124) - 1;
          uVar11 = uVar12;
          if ((int)uVar12 < 0) {
            uVar11 = *(int *)(iVar3 + 0x124) + 6;
          }
          uVar10 = uVar12 & 7;
          if (-1 < (int)-uVar12) {
            uVar10 = -(-uVar12 & 7);
          }
          abStack_52[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_52[(int)uVar11 >> 3]
          ;
        }
        if (*(int *)(iVar3 + 0x130) == 1) {
          uVar12 = *(int *)(iVar3 + 0x134) - 1;
          uVar11 = uVar12;
          if ((int)uVar12 < 0) {
            uVar11 = *(int *)(iVar3 + 0x134) + 6;
          }
          uVar10 = uVar12 & 7;
          if (-1 < (int)-uVar12) {
            uVar10 = -(-uVar12 & 7);
          }
          abStack_52[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_52[(int)uVar11 >> 3]
          ;
        }
        bVar8 = *(byte *)((int)puVar1 + uVar6) | 0x80;
LAB_080257fe:
        *(byte *)((int)puVar1 + uVar6) = bVar8;
      }
      else if (*(int *)(iVar3 + 0x10) - 1U < 2) {
        iVar14 = *(int *)(iVar3 + 0x14);
        for (bVar8 = 0; (int)(uint)bVar8 < iVar14; bVar8 = bVar8 + 1) {
          iVar15 = iVar3 + (uint)bVar8 * 0x10;
          if (*(int *)(iVar15 + 0x20) == 1) {
            iVar15 = *(int *)(iVar15 + 0x24);
            uVar12 = iVar15 - 1;
            uVar11 = uVar12;
            if ((int)uVar12 < 0) {
              uVar11 = iVar15 + 6;
            }
            uVar10 = uVar12 & 7;
            if (-1 < (int)-uVar12) {
              uVar10 = -(-uVar12 & 7);
            }
            abStack_52[(int)uVar11 >> 3] =
                 (byte)(1 << (uVar10 & 0xff)) | abStack_52[(int)uVar11 >> 3];
          }
        }
        bVar8 = *(byte *)((int)puVar1 + uVar6) & 0x7f;
        goto LAB_080257fe;
      }
      bVar8 = *(byte *)((int)puVar1 + uVar6);
      bVar7 = (byte)*(undefined4 *)(iVar3 + 0x138) & 0xf;
      *(byte *)((int)puVar1 + uVar6) = bVar8 & 0xf0 | bVar7;
      if (iVar9 == 1) {
        bVar7 = bVar8 & 0xc0 | bVar7 | 0x20;
      }
      else if (*(int *)(iVar3 + 0x130) == 1) {
        bVar7 = bVar8 & 0xc0 | bVar7 | 0x10;
      }
      else {
        bVar7 = bVar8 & 0xc0 | bVar7;
      }
      *(byte *)((int)puVar1 + uVar6) = bVar7;
    }
    FUN_080248c4();
    iVar4 = DAT_08025848;
    iVar13 = *(int *)(iVar5 + 0x58);
    iVar3 = *(int *)(iVar5 + 0x5c);
    for (uVar6 = 0; (int)(uVar6 & 0xff) < iVar13; uVar6 = uVar6 + 1) {
      iVar9 = (uVar6 & 0xff) * 0x28 + iVar3;
      if (*(int *)(iVar9 + 0x10) == 1) {
        iVar9 = *(int *)(iVar9 + 0x14);
LAB_080258be:
        uVar12 = iVar9 - 1;
        uVar11 = uVar12;
        if ((int)uVar12 < 0) {
          uVar11 = iVar9 + 6;
        }
        uVar10 = uVar12 & 7;
        if (-1 < (int)-uVar12) {
          uVar10 = -(-uVar12 & 7);
        }
        abStack_52[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_52[(int)uVar11 >> 3];
      }
      else if (*(int *)(iVar9 + 0x20) == 1) {
        iVar9 = *(int *)(iVar9 + 0x24);
        goto LAB_080258be;
      }
    }
    bVar2 = *(byte *)(DAT_08025848 + 5);
    if (bVar2 != 0) {
      if (bVar2 == 3) {
        if (*(char *)(DAT_08025848 + 0x2b) == '\x01') {
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x68);
          uVar11 = iVar13 - 1;
          uVar6 = uVar11;
          if ((int)uVar11 < 0) {
            uVar6 = iVar13 + 6;
          }
          uVar12 = uVar11 & 7;
          if (-1 < (int)-uVar11) {
            uVar12 = -(-uVar11 & 7);
          }
          abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
        }
        if (*(char *)(DAT_08025848 + 0x2c) == '\x01') {
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0xf8);
LAB_0802597a:
          uVar11 = iVar13 - 1;
          uVar6 = uVar11;
          if ((int)uVar11 < 0) {
            uVar6 = iVar13 + 6;
          }
          uVar12 = uVar11 & 7;
          if (-1 < (int)-uVar11) {
            uVar12 = -(-uVar11 & 7);
          }
          abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
        }
      }
      else if (bVar2 < 4) {
        if (*(char *)(DAT_08025848 + 0x2b) == '\x01') {
LAB_0802592a:
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x68);
          goto LAB_0802597a;
        }
      }
      else if (bVar2 == 4) {
        if (*(char *)(DAT_08025848 + 0x2b) == '\x01') goto LAB_0802592a;
        if (*(char *)(DAT_08025848 + 0x2b) == '\x02') {
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x6c);
          goto LAB_0802597a;
        }
      }
    }
    bVar2 = *(byte *)(DAT_08025848 + 6);
    if (bVar2 != 0) {
      if (bVar2 == 3) {
        if (*(char *)(DAT_08025848 + 0x2d) == '\x01') {
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x218);
          uVar11 = iVar13 - 1;
          uVar6 = uVar11;
          if ((int)uVar11 < 0) {
            uVar6 = iVar13 + 6;
          }
          uVar12 = uVar11 & 7;
          if (-1 < (int)-uVar11) {
            uVar12 = -(-uVar11 & 7);
          }
          abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
        }
        if (*(char *)(DAT_08025848 + 0x2e) == '\x01') {
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x2a8);
LAB_08025a24:
          uVar11 = iVar13 - 1;
          uVar6 = uVar11;
          if ((int)uVar11 < 0) {
            uVar6 = iVar13 + 6;
          }
          uVar12 = uVar11 & 7;
          if (-1 < (int)-uVar11) {
            uVar12 = -(-uVar11 & 7);
          }
          abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
        }
      }
      else if (bVar2 < 4) {
        if (*(char *)(DAT_08025848 + 0x2d) == '\x01') {
LAB_080259d0:
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x218);
          goto LAB_08025a24;
        }
      }
      else if (bVar2 == 4) {
        if (*(char *)(DAT_08025848 + 0x2d) == '\x01') goto LAB_080259d0;
        if (*(char *)(DAT_08025848 + 0x2d) == '\x02') {
          iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + 0x21c);
          goto LAB_08025a24;
        }
      }
    }
    if ((*(byte *)(DAT_08025848 + 0x2f) & 0xfd) == 0) {
      local_54 = (undefined1)*(undefined4 *)(DAT_08025848 + 0x46);
      local_53 = (undefined1)*(undefined4 *)(DAT_08025848 + 0x42);
    }
    else if (*(byte *)(DAT_08025848 + 0x2f) == 1) {
      local_54 = 0;
      local_53 = 0;
      iVar13 = FUN_0802cee4();
      if (((iVar13 != 0) && (iVar13 = FUN_0802cf50(*(undefined1 *)(iVar4 + 0xd)), iVar13 != 0)) &&
         (*(int *)(iVar4 + 0x42) == 1)) {
        iVar13 = *(int *)(*(int *)(iVar5 + 0x54) + (uint)*(byte *)(iVar4 + 0xd) * 0x90 + 0x68);
        uVar11 = iVar13 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar13 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
      }
      iVar13 = FUN_0802cee4(*(undefined1 *)(iVar4 + 6));
      if (((iVar13 != 0) && (iVar13 = FUN_0802cf50(*(undefined1 *)(iVar4 + 0xe)), iVar13 != 0)) &&
         (*(int *)(iVar4 + 0x46) == 1)) {
        iVar5 = *(int *)(*(int *)(iVar5 + 0x54) + (uint)*(byte *)(iVar4 + 0xe) * 0x90 + 0x68);
        uVar11 = iVar5 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar5 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_52[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_52[(int)uVar6 >> 3];
      }
    }
    local_2e = *DAT_08025844;
    local_2a = *(int *)(DAT_0802584c + 0xf4) == 2;
    FUN_08026fe0(4,0,0x200,&local_54,0x14);
    goto LAB_080256f4;
  }
  for (; (int)(uint)bVar2 < iVar4; bVar2 = bVar2 + 1) {
    iVar3 = (uint)bVar2 * 0x28 + iVar13;
    if (*(int *)(iVar3 + 0x20) == 1) {
      iVar3 = *(int *)(iVar3 + 0x24);
      uVar11 = iVar3 - 1;
      uVar6 = uVar11;
      if ((int)uVar11 < 0) {
        uVar6 = iVar3 + 6;
      }
      uVar12 = uVar11 & 7;
      if (-1 < (int)-uVar11) {
        uVar12 = -(-uVar11 & 7);
      }
      abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
    }
  }
  iVar4 = *(int *)(iVar5 + 0x30);
  iVar13 = *(int *)(iVar5 + 0x34);
  for (bVar2 = 0; (int)(uint)bVar2 < iVar4; bVar2 = bVar2 + 1) {
    iVar3 = (uint)bVar2 * 0x78 + iVar13;
    iVar9 = iVar3 + 0x70;
    do {
      if (*(int *)(iVar3 + 0x10) == 1) {
        uVar11 = *(int *)(iVar3 + 0x14) - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = *(int *)(iVar3 + 0x14) + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
      }
      iVar3 = iVar3 + 0x10;
    } while (iVar9 != iVar3);
  }
  iVar4 = *(int *)(iVar5 + 0x60);
  iVar13 = *(int *)(iVar5 + 100);
  for (bVar2 = 0; iVar3 = DAT_08025848, uVar6 = (uint)bVar2, (int)uVar6 < iVar4; bVar2 = bVar2 + 1)
  {
    iVar3 = uVar6 * 0x13c + iVar13;
    iVar9 = *(int *)(iVar3 + 0x120);
    if (*(int *)(iVar3 + 0x10) == 0) {
      if (iVar9 == 1) {
        uVar12 = *(int *)(iVar3 + 0x124) - 1;
        uVar11 = uVar12;
        if ((int)uVar12 < 0) {
          uVar11 = *(int *)(iVar3 + 0x124) + 6;
        }
        uVar10 = uVar12 & 7;
        if (-1 < (int)-uVar12) {
          uVar10 = -(-uVar12 & 7);
        }
        abStack_3d[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3d[(int)uVar11 >> 3];
      }
      if (*(int *)(iVar3 + 0x130) == 1) {
        uVar12 = *(int *)(iVar3 + 0x134) - 1;
        uVar11 = uVar12;
        if ((int)uVar12 < 0) {
          uVar11 = *(int *)(iVar3 + 0x134) + 6;
        }
        uVar10 = uVar12 & 7;
        if (-1 < (int)-uVar12) {
          uVar10 = -(-uVar12 & 7);
        }
        abStack_3d[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3d[(int)uVar11 >> 3];
      }
      bVar8 = *(byte *)((int)puVar1 + uVar6) | 0x80;
LAB_08025c4e:
      *(byte *)((int)puVar1 + uVar6) = bVar8;
    }
    else if (*(int *)(iVar3 + 0x10) - 1U < 2) {
      iVar14 = *(int *)(iVar3 + 0x14);
      for (bVar8 = 0; (int)(uint)bVar8 < iVar14; bVar8 = bVar8 + 1) {
        iVar15 = iVar3 + (uint)bVar8 * 0x10;
        if (*(int *)(iVar15 + 0x20) == 1) {
          iVar15 = *(int *)(iVar15 + 0x24);
          uVar12 = iVar15 - 1;
          uVar11 = uVar12;
          if ((int)uVar12 < 0) {
            uVar11 = iVar15 + 6;
          }
          uVar10 = uVar12 & 7;
          if (-1 < (int)-uVar12) {
            uVar10 = -(-uVar12 & 7);
          }
          abStack_3d[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3d[(int)uVar11 >> 3]
          ;
        }
      }
      bVar8 = *(byte *)((int)puVar1 + uVar6) & 0x7f;
      goto LAB_08025c4e;
    }
    bVar8 = *(byte *)((int)puVar1 + uVar6);
    bVar7 = (byte)*(undefined4 *)(iVar3 + 0x138) & 0xf;
    *(byte *)((int)puVar1 + uVar6) = bVar8 & 0xf0 | bVar7;
    if (iVar9 == 1) {
      bVar7 = bVar8 & 0xc0 | bVar7 | 0x20;
    }
    else if (*(int *)(iVar3 + 0x130) == 1) {
      bVar7 = bVar8 & 0xc0 | bVar7 | 0x10;
    }
    else {
      bVar7 = bVar8 & 0xc0 | bVar7;
    }
    *(byte *)((int)puVar1 + uVar6) = bVar7;
  }
  iVar4 = *(int *)(iVar5 + 0x58);
  iVar13 = *(int *)(iVar5 + 0x5c);
  for (uVar6 = 0; (int)(uVar6 & 0xff) < iVar4; uVar6 = uVar6 + 1) {
    iVar9 = (uVar6 & 0xff) * 0x28 + iVar13;
    if (*(int *)(iVar9 + 0x10) == 1) {
      iVar9 = *(int *)(iVar9 + 0x14);
LAB_08025cfe:
      uVar12 = iVar9 - 1;
      uVar11 = uVar12;
      if ((int)uVar12 < 0) {
        uVar11 = iVar9 + 6;
      }
      uVar10 = uVar12 & 7;
      if (-1 < (int)-uVar12) {
        uVar10 = -(-uVar12 & 7);
      }
      abStack_3d[(int)uVar11 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3d[(int)uVar11 >> 3];
    }
    else if (*(int *)(iVar9 + 0x20) == 1) {
      iVar9 = *(int *)(iVar9 + 0x24);
      goto LAB_08025cfe;
    }
  }
  bVar2 = *(byte *)(DAT_08025848 + 5);
  if (bVar2 != 0) {
    if (bVar2 == 3) {
      if (*(char *)(DAT_08025848 + 0x2b) == '\x01') {
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x68);
        uVar11 = iVar4 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar4 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
      }
      if (*(char *)(DAT_08025848 + 0x2c) == '\x01') {
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0xf8);
LAB_08025dba:
        uVar11 = iVar4 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar4 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
      }
    }
    else if (bVar2 < 4) {
      if (*(char *)(DAT_08025848 + 0x2b) == '\x01') {
LAB_08025d6a:
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x68);
        goto LAB_08025dba;
      }
    }
    else if (bVar2 == 4) {
      if (*(char *)(DAT_08025848 + 0x2b) == '\x01') goto LAB_08025d6a;
      if (*(char *)(DAT_08025848 + 0x2b) == '\x02') {
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x6c);
        goto LAB_08025dba;
      }
    }
  }
  bVar2 = *(byte *)(DAT_08025848 + 6);
  if (bVar2 != 0) {
    if (bVar2 == 3) {
      if (*(char *)(DAT_08025848 + 0x2d) == '\x01') {
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x218);
        uVar11 = iVar4 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar4 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
      }
      if (*(char *)(DAT_08025848 + 0x2e) == '\x01') {
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x2a8);
LAB_08025e66:
        uVar11 = iVar4 - 1;
        uVar6 = uVar11;
        if ((int)uVar11 < 0) {
          uVar6 = iVar4 + 6;
        }
        uVar12 = uVar11 & 7;
        if (-1 < (int)-uVar11) {
          uVar12 = -(-uVar11 & 7);
        }
        abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
      }
    }
    else if (bVar2 < 4) {
      if (*(char *)(DAT_08025848 + 0x2d) == '\x01') {
LAB_08025e12:
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x218);
        goto LAB_08025e66;
      }
    }
    else if (bVar2 == 4) {
      if (*(char *)(DAT_08025848 + 0x2d) == '\x01') goto LAB_08025e12;
      if (*(char *)(DAT_08025848 + 0x2d) == '\x02') {
        iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + 0x21c);
        goto LAB_08025e66;
      }
    }
  }
  if ((*(byte *)(DAT_08025848 + 0x2f) & 0xfd) == 0) {
    local_3f = (undefined1)*(undefined4 *)(DAT_08025848 + 0x46);
    local_3e = (undefined1)*(undefined4 *)(DAT_08025848 + 0x42);
  }
  else if (*(byte *)(DAT_08025848 + 0x2f) == 1) {
    iVar4 = FUN_0802cee4();
    if (((iVar4 != 0) && (iVar4 = FUN_0802cf50(*(undefined1 *)(iVar3 + 0xd)), iVar4 != 0)) &&
       (*(int *)(iVar3 + 0x42) == 1)) {
      iVar4 = *(int *)(*(int *)(iVar5 + 0x54) + (uint)*(byte *)(iVar3 + 0xd) * 0x90 + 0x68);
      uVar11 = iVar4 - 1;
      uVar6 = uVar11;
      if ((int)uVar11 < 0) {
        uVar6 = iVar4 + 6;
      }
      uVar12 = uVar11 & 7;
      if (-1 < (int)-uVar11) {
        uVar12 = -(-uVar11 & 7);
      }
      abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
    }
    iVar4 = FUN_0802cee4(*(undefined1 *)(iVar3 + 6));
    if (((iVar4 != 0) && (iVar4 = FUN_0802cf50(*(undefined1 *)(iVar3 + 0xe)), iVar4 != 0)) &&
       (*(int *)(iVar3 + 0x46) == 1)) {
      iVar5 = *(int *)(*(int *)(iVar5 + 0x54) + (uint)*(byte *)(iVar3 + 0xe) * 0x90 + 0x68);
      uVar11 = iVar5 - 1;
      uVar6 = uVar11;
      if ((int)uVar11 < 0) {
        uVar6 = iVar5 + 6;
      }
      uVar12 = uVar11 & 7;
      if (-1 < (int)-uVar11) {
        uVar12 = -(-uVar11 & 7);
      }
      abStack_3d[(int)uVar6 >> 3] = (byte)(1 << (uVar12 & 0xff)) | abStack_3d[(int)uVar6 >> 3];
    }
  }
  local_2e = *DAT_08025844;
  local_2a = *(int *)(DAT_0802584c + 0xf4) == 2;
LAB_080256f4:
  FUN_08026fe0(1,0,0,&local_40,0x17);
  return 0;
}


// 08025514 push {r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 08025518 sub sp,#0x44
// 0802551a mov r6,r0
// 0802551c movs r2,#0x17
// 0802551e movs r1,#0x0
// 08025520 add r0,sp,#0x28
// 08025522 bl 0x08035d8c
// 08025526 movs r2,#0x14
// 08025528 movs r7,#0x1
// 0802552a movs r1,#0x0
// 0802552c ldr r4,[0x08025840]
// 0802552e add.w r0,sp,r2
// 08025532 bl 0x08035d8c
// 08025536 ldrd r1,r5,[r4,#0x18]
// 0802553a cmp r6,r7
// 0802553c mov.w r0,#0x0
// 08025540 strb.w r7,[sp,#0x28]
// 08025544 beq.w 0x0802570c
// 08025548 movs r6,#0x28
// 0802554a uxtb r3,r0
// 0802554c cmp r3,r1
// 0802554e blt.w 0x08025b16
// 08025552 ldrd r5,r6,[r4,#0x30]
// 08025556 movs r0,#0x0
// 08025558 movs r7,#0x78
// 0802555a mov.w r12,#0x1
// 0802555e uxtb r3,r0
// 08025560 cmp r3,r5
// 08025562 blt.w 0x08025b60
// 08025566 movs r5,#0x0
// 08025568 mov.w r12,#0x13c
// 0802556c movs r6,#0x1
// 0802556e mov.w lr,#0x2
// 08025572 ldr r3,[r4,#0x60]
// 08025574 ldr r1,[0x08025844]
// 08025576 str r3,[sp,#0xc]
// 08025578 ldr r3,[r4,#0x64]
// 0802557a str r3,[sp,#0x8]
// 0802557c ldr r3,[sp,#0xc]
// 0802557e uxtb r2,r5
// 08025580 cmp r2,r3
// 08025582 blt.w 0x08025bb4
// 08025586 ldrd r0,r5,[r4,#0x58]
// 0802558a movs r2,#0x0
// 0802558c movs r6,#0x28
// 0802558e movs r1,#0x1
// 08025590 uxtb r3,r2
// 08025592 cmp r3,r0
// 08025594 blt.w 0x08025cf0
// 08025598 ldr r5,[0x08025848]
// 0802559a ldrb r0,[r5,#0x5]
// 0802559c cbz r0,0x080255ac
// 0802559e cmp r0,#0x3
// 080255a0 beq.w 0x08025d70
// 080255a4 bhi.w 0x08025d46
// 080255a8 bne.w 0x08025d60
// 080255ac ldrb r3,[r5,#0x6]
// 080255ae cbz r3,0x080255be
// 080255b0 cmp r3,#0x3
// 080255b2 beq.w 0x08025e1a
// 080255b6 bhi.w 0x08025dec
// 080255ba bne.w 0x08025e08
// 080255be ldrb.w r3,[r5,#0x2f]
// 080255c2 tst r3,#0xfd
// 080255c6 bne.w 0x08025e98
// 080255ca ldr.w r3,[r5,#0x46]
// 080255ce strb.w r3,[sp,#0x29]
// 080255d2 ldr.w r3,[r5,#0x42]
// 080255d6 strb.w r3,[sp,#0x2a]
// 080255da ldr r3,[0x08025844]
// 080255dc ldr r3,[r3,#0x0]
// 080255de str.w r3,[sp,#0x3a]
// 080255e2 ldr r3,[0x0802584c]
// 080255e4 ldr.w r3,[r3,#0xf4]
// 080255e8 subs r2,r3,#0x2
// 080255ea rsbs r3,r2
// 080255ec adcs r3,r2
// 080255ee strb.w r3,[sp,#0x3e]
// 080255f2 b 0x080256f4
// 080255f4 mla r3,r7,r3,r5
// 080255f8 ldr r2,[r3,#0x20]
// 080255fa cmp r2,#0x1
// 080255fc bne 0x0802563a
// 080255fe ldr.w r12,[r3,#0x24]
// 08025602 add.w r3,r12,#0xffffffff
// 08025606 mov r2,r3
// 08025608 cmp r3,#0x0
// 0802560a it lt
// 0802560c add.lt.w r2,r12,#0x6
// 08025610 add.w r12,sp,#0x40
// 08025614 add.w r2,r12,r2, asr #0x3
// 08025618 rsbs.w r12,r3,#0x0
// 0802561c and r12,r12,#0x7
// 08025620 and r3,r3,#0x7
// 08025624 it pl
// 08025626 rsb.pl.w r3,r12,#0x0
// 0802562a ldrb.w r12,[r2,#-0x2a]
// 0802562e lsl.w r3,r6,r3
// 08025632 orr.w r3,r3,r12
// 08025636 strb.w r3,[r2,#-0x2a]
// 0802563a adds r0,#0x1
// 0802563c uxtb r3,r0
// 0802563e cmp r3,r1
// 08025640 blt 0x080255f4
// 08025642 ldrd r5,r6,[r4,#0x30]
// 08025646 movs r0,#0x0
// 08025648 movs r7,#0x78
// 0802564a mov.w r12,#0x1
// 0802564e uxtb r2,r0
// 08025650 cmp r2,r5
// 08025652 blt 0x08025710
// 08025654 movs r5,#0x0
// 08025656 mov.w r12,#0x13c
// 0802565a movs r6,#0x1
// 0802565c mov.w lr,#0x2
// 08025660 ldr r3,[r4,#0x60]
// 08025662 ldr r1,[0x08025844]
// 08025664 str r3,[sp,#0xc]
// 08025666 ldr r3,[r4,#0x64]
// 08025668 str r3,[sp,#0x8]
// 0802566a ldr r3,[sp,#0xc]
// 0802566c uxtb r2,r5
// 0802566e cmp r2,r3
// 08025670 blt 0x08025764
// 08025672 bl 0x080248c4
// 08025676 ldrd r0,r5,[r4,#0x58]
// 0802567a movs r2,#0x0
// 0802567c movs r6,#0x28
// 0802567e movs r1,#0x1
// 08025680 uxtb r3,r2
// 08025682 cmp r3,r0
// 08025684 blt.w 0x080258b0
// 08025688 ldr r5,[0x08025848]
// 0802568a ldrb r0,[r5,#0x5]
// 0802568c cbz r0,0x0802569c
// 0802568e cmp r0,#0x3
// 08025690 beq.w 0x08025930
// 08025694 bhi.w 0x08025906
// 08025698 bne.w 0x08025920
// 0802569c ldrb r3,[r5,#0x6]
// 0802569e cbz r3,0x080256ae
// 080256a0 cmp r3,#0x3
// 080256a2 beq.w 0x080259d8
// 080256a6 bhi.w 0x080259aa
// 080256aa bne.w 0x080259c6
// 080256ae ldrb.w r3,[r5,#0x2f]
// 080256b2 tst r3,#0xfd
// 080256b6 bne.w 0x08025a54
// 080256ba ldr.w r3,[r5,#0x46]
// 080256be strb.w r3,[sp,#0x14]
// 080256c2 ldr.w r3,[r5,#0x42]
// 080256c6 strb.w r3,[sp,#0x15]
// 080256ca ldr r3,[0x08025844]
// 080256cc mov.w r2,#0x200
// 080256d0 ldr r3,[r3,#0x0]
// 080256d2 movs r0,#0x4
// 080256d4 str.w r3,[sp,#0x3a]
// 080256d8 ldr r3,[0x0802584c]
// 080256da ldr.w r3,[r3,#0xf4]
// 080256de subs r1,r3,#0x2
// 080256e0 rsbs r3,r1
// 080256e2 adcs r3,r1
// 080256e4 strb.w r3,[sp,#0x3e]
// 080256e8 movs r3,#0x14
// 080256ea movs r1,#0x0
// 080256ec str r3,[sp,#0x0]
// 080256ee add r3,sp
// 080256f0 bl 0x08026fe0
// 080256f4 movs r2,#0x0
// 080256f6 movs r3,#0x17
// 080256f8 mov r1,r2
// 080256fa str r3,[sp,#0x0]
// 080256fc movs r0,#0x1
// 080256fe add r3,sp,#0x28
// 08025700 bl 0x08026fe0
// 08025704 movs r0,#0x0
// 08025706 add sp,#0x44
// 08025708 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 0802570c movs r7,#0x28
// 0802570e b 0x0802563c
// 08025710 mla r2,r7,r2,r6
// 08025714 add.w lr,r2,#0x70
// 08025718 ldr r3,[r2,#0x10]
// 0802571a cmp r3,#0x1
// 0802571c bne 0x0802575a
// 0802571e ldr.w r8,[r2,#0x14]
// 08025722 add.w r3,r8,#0xffffffff
// 08025726 mov r1,r3
// 08025728 cmp r3,#0x0
// 0802572a it lt
// 0802572c add.lt.w r1,r8,#0x6
// 08025730 add.w r8,sp,#0x40
// 08025734 add.w r1,r8,r1, asr #0x3
// 08025738 rsbs.w r8,r3,#0x0
// 0802573c and r8,r8,#0x7
// 08025740 and r3,r3,#0x7
// 08025744 it pl
// 08025746 rsb.pl.w r3,r8,#0x0
// 0802574a ldrb.w r8,[r1,#-0x2a]
// 0802574e lsl.w r3,r12,r3
// 08025752 orr.w r3,r3,r8
// 08025756 strb.w r3,[r1,#-0x2a]
// 0802575a adds r2,#0x10
// 0802575c cmp lr,r2
// 0802575e bne 0x08025718
// 08025760 adds r0,#0x1
// 08025762 b 0x0802564e
// 08025764 ldr r3,[sp,#0x8]
// 08025766 mla r0,r12,r2,r3
// 0802576a ldr r3,[r0,#0x10]
// 0802576c ldr.w r7,[r0,#0x120]
// 08025770 cmp r3,#0x0
// 08025772 bne 0x08025822
// 08025774 cmp r7,#0x1
// 08025776 bne 0x080257b4
// 08025778 ldr.w r9,[r0,#0x124]
// 0802577c add.w r3,r9,#0xffffffff
// 08025780 mov r8,r3
// 08025782 cmp r3,#0x0
// 08025784 it lt
// 08025786 add.lt.w r8,r9,#0x6
// 0802578a add.w r9,sp,#0x40
// 0802578e add.w r8,r9,r8, asr #0x3
// 08025792 rsbs.w r9,r3,#0x0
// 08025796 and r9,r9,#0x7
// 0802579a and r3,r3,#0x7
// 0802579e it pl
// 080257a0 rsb.pl.w r3,r9,#0x0
// 080257a4 ldrb.w r9,[r8,#-0x2a]
// 080257a8 lsl.w r3,r6,r3
// 080257ac orr.w r3,r3,r9
// 080257b0 strb.w r3,[r8,#-0x2a]
// 080257b4 ldr.w r3,[r0,#0x130]
// 080257b8 cmp r3,#0x1
// 080257ba bne 0x080257f8
// 080257bc ldr.w r9,[r0,#0x134]
// 080257c0 add.w r3,r9,#0xffffffff
// 080257c4 mov r8,r3
// 080257c6 cmp r3,#0x0
// 080257c8 it lt
// 080257ca add.lt.w r8,r9,#0x6
// 080257ce add.w r9,sp,#0x40
// 080257d2 add.w r8,r9,r8, asr #0x3
// 080257d6 rsbs.w r9,r3,#0x0
// 080257da and r9,r9,#0x7
// 080257de and r3,r3,#0x7
// 080257e2 it pl
// 080257e4 rsb.pl.w r3,r9,#0x0
// 080257e8 ldrb.w r9,[r8,#-0x2a]
// 080257ec lsl.w r3,r6,r3
// 080257f0 orr.w r3,r3,r9
// 080257f4 strb.w r3,[r8,#-0x2a]
// 080257f8 ldrb r3,[r1,r2]
// 080257fa orr r3,r3,#0x80
// 080257fe strb r3,[r1,r2]
// 08025800 ldrb.w r8,[r1,r2]
// 08025804 ldr.w r3,[r0,#0x138]
// 08025808 cmp r7,#0x1
// 0802580a bfi r8,r3,#0x0,#0x4
// 0802580e strb.w r8,[r1,r2]
// 08025812 uxtb.w r3,r8
// 08025816 bne 0x0802589e
// 08025818 bfi r3,lr,#0x4,#0x2
// 0802581c strb r3,[r1,r2]
// 0802581e adds r5,#0x1
// 08025820 b 0x0802566a
// 08025822 subs r3,#0x1
// 08025824 cmp r3,#0x1
// 08025826 bhi 0x08025800
// 08025828 mov.w r8,#0x0
// 0802582c ldr.w r9,[r0,#0x14]
// 08025830 uxtb.w r10,r8
// 08025834 cmp r10,r9
// 08025836 blt 0x08025850
// 08025838 ldrb r3,[r1,r2]
// 0802583a bfc r3,#0x7,#0x1
// 0802583e b 0x080257fe
// 08025850 add.w r10,r0,r10, lsl #0x4
// 08025854 ldr.w r3,[r10,#0x20]
// 08025858 cmp r3,#0x1
// 0802585a bne 0x08025898
// 0802585c ldr.w r11,[r10,#0x24]
// 08025860 add.w r3,r11,#0xffffffff
// 08025864 mov r10,r3
// 08025866 cmp r3,#0x0
// 08025868 it lt
// 0802586a add.lt.w r10,r11,#0x6
// 0802586e add.w r11,sp,#0x40
// 08025872 add.w r10,r11,r10, asr #0x3
// 08025876 rsbs.w r11,r3,#0x0
// 0802587a and r11,r11,#0x7
// 0802587e and r3,r3,#0x7
// 08025882 it pl
// 08025884 rsb.pl.w r3,r11,#0x0
// 08025888 ldrb.w r11,[r10,#-0x2a]
// 0802588c lsl.w r3,r6,r3
// 08025890 orr.w r3,r3,r11
// 08025894 strb.w r3,[r10,#-0x2a]
// 08025898 add.w r8,r8,#0x1
// 0802589c b 0x08025830
// 0802589e ldr.w r0,[r0,#0x130]
// 080258a2 cmp r0,#0x1
// 080258a4 ite eq
// 080258a6 bfi.eq r3,r0,#0x4,#0x2
// 080258aa bfc.ne r3,#0x4,#0x2
// 080258ae b 0x0802581c
// 080258b0 mla r3,r6,r3,r5
// 080258b4 ldr r7,[r3,#0x10]
// 080258b6 cmp r7,#0x1
// 080258b8 bne 0x080258fa
// 080258ba ldr.w r12,[r3,#0x14]
// 080258be add.w r3,r12,#0xffffffff
// 080258c2 mov r7,r3
// 080258c4 cmp r3,#0x0
// 080258c6 it lt
// 080258c8 add.lt.w r7,r12,#0x6
// 080258cc add.w r12,sp,#0x40
// 080258d0 add.w r7,r12,r7, asr #0x3
// 080258d4 rsbs.w r12,r3,#0x0
// 080258d8 and r12,r12,#0x7
// 080258dc and r3,r3,#0x7
// 080258e0 it pl
// 080258e2 rsb.pl.w r3,r12,#0x0
// 080258e6 ldrb.w r12,[r7,#-0x2a]
// 080258ea lsl.w r3,r1,r3
// 080258ee orr.w r3,r3,r12
// 080258f2 strb.w r3,[r7,#-0x2a]
// 080258f6 adds r2,#0x1
// 080258f8 b 0x08025680
// 080258fa ldr r7,[r3,#0x20]
// 080258fc cmp r7,#0x1
// 080258fe bne 0x080258f6
// 08025900 ldr.w r12,[r3,#0x24]
// 08025904 b 0x080258be
// 08025906 cmp r0,#0x4
// 08025908 bne.w 0x0802569c
// 0802590c ldrb.w r3,[r5,#0x2b]
// 08025910 cmp r3,#0x1
// 08025912 beq 0x0802592a
// 08025914 cmp r3,#0x2
// 08025916 bne.w 0x0802569c
// 0802591a ldr r3,[r4,#0x54]
// 0802591c ldr r1,[r3,#0x6c]
// 0802591e b 0x0802597a
// 08025920 ldrb.w r3,[r5,#0x2b]
// 08025924 cmp r3,#0x1
// 08025926 bne.w 0x0802569c
// 0802592a ldr r3,[r4,#0x54]
// 0802592c ldr r1,[r3,#0x68]
// 0802592e b 0x0802597a
// 08025930 ldrb.w r3,[r5,#0x2b]
// 08025934 cmp r3,#0x1
// 08025936 bne 0x0802596a
// 08025938 ldr r3,[r4,#0x54]
// 0802593a ldr r1,[r3,#0x68]
// 0802593c subs r3,r1,#0x1
// 0802593e mov r2,r3
// 08025940 cmp r3,#0x0
// 08025942 it lt
// 08025944 add.lt r2,r1,#0x6
// 08025946 add r1,sp,#0x40
// 08025948 add.w r2,r1,r2, asr #0x3
// 0802594c rsbs r1,r3
// 0802594e and r1,r1,#0x7
// 08025952 and r3,r3,#0x7
// 08025956 it pl
// 08025958 rsb.pl r3,r1
// 0802595a movs r1,#0x1
// 0802595c lsl.w r3,r1,r3
// 08025960 ldrb.w r1,[r2,#-0x2a]
// 08025964 orrs r3,r1
// 08025966 strb.w r3,[r2,#-0x2a]
// 0802596a ldrb.w r3,[r5,#0x2c]
// 0802596e cmp r3,#0x1
// 08025970 bne.w 0x0802569c
// 08025974 ldr r3,[r4,#0x54]
// 08025976 ldr.w r1,[r3,#0xf8]
// 0802597a subs r3,r1,#0x1
// 0802597c mov r2,r3
// 0802597e cmp r3,#0x0
// 08025980 it lt
// 08025982 add.lt r2,r1,#0x6
// 08025984 add r1,sp,#0x40
// 08025986 add.w r2,r1,r2, asr #0x3
// 0802598a rsbs r1,r3
// 0802598c and r1,r1,#0x7
// 08025990 and r3,r3,#0x7
// 08025994 it pl
// 08025996 rsb.pl r3,r1
// 08025998 movs r1,#0x1
// 0802599a lsl.w r3,r1,r3
// 0802599e ldrb.w r1,[r2,#-0x2a]
// 080259a2 orrs r3,r1
// 080259a4 strb.w r3,[r2,#-0x2a]
// 080259a8 b 0x0802569c
// 080259aa cmp r3,#0x4
// 080259ac bne.w 0x080256ae
// 080259b0 ldrb.w r3,[r5,#0x2d]
// 080259b4 cmp r3,#0x1
// 080259b6 beq 0x080259d0
// 080259b8 cmp r3,#0x2
// 080259ba bne.w 0x080256ae
// 080259be ldr r3,[r4,#0x54]
// 080259c0 ldr.w r1,[r3,#0x21c]
// 080259c4 b 0x08025a24
// 080259c6 ldrb.w r3,[r5,#0x2d]
// 080259ca cmp r3,#0x1
// 080259cc bne.w 0x080256ae
// 080259d0 ldr r3,[r4,#0x54]
// 080259d2 ldr.w r1,[r3,#0x218]
// 080259d6 b 0x08025a24
// 080259d8 ldrb.w r3,[r5,#0x2d]
// 080259dc cmp r3,#0x1
// 080259de bne 0x08025a14
// 080259e0 ldr r3,[r4,#0x54]
// 080259e2 ldr.w r1,[r3,#0x218]
// 080259e6 subs r3,r1,#0x1
// 080259e8 mov r2,r3
// 080259ea cmp r3,#0x0
// 080259ec it lt
// 080259ee add.lt r2,r1,#0x6
// 080259f0 add r1,sp,#0x40
// 080259f2 add.w r2,r1,r2, asr #0x3
// 080259f6 rsbs r1,r3
// 080259f8 and r1,r1,#0x7
// 080259fc and r3,r3,#0x7
// 08025a00 it pl
// 08025a02 rsb.pl r3,r1
// 08025a04 movs r1,#0x1
// 08025a06 lsl.w r3,r1,r3
// 08025a0a ldrb.w r1,[r2,#-0x2a]
// 08025a0e orrs r3,r1
// 08025a10 strb.w r3,[r2,#-0x2a]
// 08025a14 ldrb.w r3,[r5,#0x2e]
// 08025a18 cmp r3,#0x1
// 08025a1a bne.w 0x080256ae
// 08025a1e ldr r3,[r4,#0x54]
// 08025a20 ldr.w r1,[r3,#0x2a8]
// 08025a24 subs r3,r1,#0x1
// 08025a26 mov r2,r3
// 08025a28 cmp r3,#0x0
// 08025a2a it lt
// 08025a2c add.lt r2,r1,#0x6
// 08025a2e add r1,sp,#0x40
// 08025a30 add.w r2,r1,r2, asr #0x3
// 08025a34 rsbs r1,r3
// 08025a36 and r1,r1,#0x7
// 08025a3a and r3,r3,#0x7
// 08025a3e it pl
// 08025a40 rsb.pl r3,r1
// 08025a42 movs r1,#0x1
// 08025a44 lsl.w r3,r1,r3
// 08025a48 ldrb.w r1,[r2,#-0x2a]
// 08025a4c orrs r3,r1
// 08025a4e strb.w r3,[r2,#-0x2a]
// 08025a52 b 0x080256ae
// 08025a54 cmp r3,#0x1
// 08025a56 bne.w 0x080256ca
// 08025a5a movs r3,#0x0
// 08025a5c strb.w r3,[sp,#0x14]
// 08025a60 strb.w r3,[sp,#0x15]
// 08025a64 bl 0x0802cee4
// 08025a68 cbz r0,0x08025ab6
// 08025a6a ldrb r0,[r5,#0xd]
// 08025a6c bl 0x0802cf50
// 08025a70 cbz r0,0x08025ab6
// 08025a72 ldr.w r3,[r5,#0x42]
// 08025a76 cmp r3,#0x1
// 08025a78 bne 0x08025ab6
// 08025a7a ldrb r3,[r5,#0xd]
// 08025a7c ldr r2,[r4,#0x54]
// 08025a7e add.w r3,r3,r3, lsl #0x3
// 08025a82 add.w r3,r2,r3, lsl #0x4
// 08025a86 ldr r1,[r3,#0x68]
// 08025a88 subs r3,r1,#0x1
// 08025a8a mov r2,r3
// 08025a8c cmp r3,#0x0
// 08025a8e it lt
// 08025a90 add.lt r2,r1,#0x6
// 08025a92 add r1,sp,#0x40
// 08025a94 add.w r2,r1,r2, asr #0x3
// 08025a98 rsbs r1,r3
// 08025a9a and r1,r1,#0x7
// 08025a9e and r3,r3,#0x7
// 08025aa2 it pl
// 08025aa4 rsb.pl r3,r1
// 08025aa6 movs r1,#0x1
// 08025aa8 lsl.w r3,r1,r3
// 08025aac ldrb.w r1,[r2,#-0x2a]
// 08025ab0 orrs r3,r1
// 08025ab2 strb.w r3,[r2,#-0x2a]
// 08025ab6 ldrb r0,[r5,#0x6]
// 08025ab8 bl 0x0802cee4
// 08025abc cmp r0,#0x0
// 08025abe beq.w 0x080256ca
// 08025ac2 ldrb r0,[r5,#0xe]
// 08025ac4 bl 0x0802cf50
// 08025ac8 cmp r0,#0x0
// 08025aca beq.w 0x080256ca
// 08025ace ldr.w r3,[r5,#0x46]
// 08025ad2 cmp r3,#0x1
// 08025ad4 bne.w 0x080256ca
// 08025ad8 ldrb r3,[r5,#0xe]
// 08025ada ldr r2,[r4,#0x54]
// 08025adc add.w r3,r3,r3, lsl #0x3
// 08025ae0 add.w r3,r2,r3, lsl #0x4
// 08025ae4 ldr r1,[r3,#0x68]
// 08025ae6 subs r3,r1,#0x1
// 08025ae8 mov r2,r3
// 08025aea cmp r3,#0x0
// 08025aec it lt
// 08025aee add.lt r2,r1,#0x6
// 08025af0 add r1,sp,#0x40
// 08025af2 add.w r2,r1,r2, asr #0x3
// 08025af6 rsbs r1,r3
// 08025af8 and r1,r1,#0x7
// 08025afc and r3,r3,#0x7
// 08025b00 it pl
// 08025b02 rsb.pl r3,r1
// 08025b04 movs r1,#0x1
// 08025b06 lsl.w r3,r1,r3
// 08025b0a ldrb.w r1,[r2,#-0x2a]
// 08025b0e orrs r3,r1
// 08025b10 strb.w r3,[r2,#-0x2a]
// 08025b14 b 0x080256ca
// 08025b16 mla r3,r6,r3,r5
// 08025b1a ldr r2,[r3,#0x20]
// 08025b1c cmp r2,#0x1
// 08025b1e bne 0x08025b5c
// 08025b20 ldr.w r12,[r3,#0x24]
// 08025b24 add.w r3,r12,#0xffffffff
// 08025b28 mov r2,r3
// 08025b2a cmp r3,#0x0
// 08025b2c it lt
// 08025b2e add.lt.w r2,r12,#0x6
// 08025b32 add.w r12,sp,#0x40
// 08025b36 add.w r2,r12,r2, asr #0x3
// 08025b3a rsbs.w r12,r3,#0x0
// 08025b3e and r12,r12,#0x7
// 08025b42 and r3,r3,#0x7
// 08025b46 it pl
// 08025b48 rsb.pl.w r3,r12,#0x0
// 08025b4c ldrb.w r12,[r2,#-0x15]
// 08025b50 lsl.w r3,r7,r3
// 08025b54 orr.w r3,r3,r12
// 08025b58 strb.w r3,[r2,#-0x15]
// 08025b5c adds r0,#0x1
// 08025b5e b 0x0802554a
// 08025b60 mla r2,r7,r3,r6
// 08025b64 add.w lr,r2,#0x70
// 08025b68 ldr r3,[r2,#0x10]
// 08025b6a cmp r3,#0x1
// 08025b6c bne 0x08025baa
// 08025b6e ldr.w r8,[r2,#0x14]
// 08025b72 add.w r3,r8,#0xffffffff
// 08025b76 mov r1,r3
// 08025b78 cmp r3,#0x0
// 08025b7a it lt
// 08025b7c add.lt.w r1,r8,#0x6
// 08025b80 add.w r8,sp,#0x40
// 08025b84 add.w r1,r8,r1, asr #0x3
// 08025b88 rsbs.w r8,r3,#0x0
// 08025b8c and r8,r8,#0x7
// 08025b90 and r3,r3,#0x7
// 08025b94 it pl
// 08025b96 rsb.pl.w r3,r8,#0x0
// 08025b9a ldrb.w r8,[r1,#-0x15]
// 08025b9e lsl.w r3,r12,r3
// 08025ba2 orr.w r3,r3,r8
// 08025ba6 strb.w r3,[r1,#-0x15]
// 08025baa adds r2,#0x10
// 08025bac cmp lr,r2
// 08025bae bne 0x08025b68
// 08025bb0 adds r0,#0x1
// 08025bb2 b 0x0802555e
// 08025bb4 ldr r3,[sp,#0x8]
// 08025bb6 mla r0,r12,r2,r3
// 08025bba ldr r3,[r0,#0x10]
// 08025bbc ldr.w r7,[r0,#0x120]
// 08025bc0 cmp r3,#0x0
// 08025bc2 bne 0x08025c72
// 08025bc4 cmp r7,#0x1
// 08025bc6 bne 0x08025c04
// 08025bc8 ldr.w r9,[r0,#0x124]
// 08025bcc add.w r3,r9,#0xffffffff
// 08025bd0 mov r8,r3
// 08025bd2 cmp r3,#0x0
// 08025bd4 it lt
// 08025bd6 add.lt.w r8,r9,#0x6
// 08025bda add.w r9,sp,#0x40
// 08025bde add.w r8,r9,r8, asr #0x3
// 08025be2 rsbs.w r9,r3,#0x0
// 08025be6 and r9,r9,#0x7
// 08025bea and r3,r3,#0x7
// 08025bee it pl
// 08025bf0 rsb.pl.w r3,r9,#0x0
// 08025bf4 ldrb.w r9,[r8,#-0x15]
// 08025bf8 lsl.w r3,r6,r3
// 08025bfc orr.w r3,r3,r9
// 08025c00 strb.w r3,[r8,#-0x15]
// 08025c04 ldr.w r3,[r0,#0x130]
// 08025c08 cmp r3,#0x1
// 08025c0a bne 0x08025c48
// 08025c0c ldr.w r9,[r0,#0x134]
// 08025c10 add.w r3,r9,#0xffffffff
// 08025c14 mov r8,r3
// 08025c16 cmp r3,#0x0
// 08025c18 it lt
// 08025c1a add.lt.w r8,r9,#0x6
// 08025c1e add.w r9,sp,#0x40
// 08025c22 add.w r8,r9,r8, asr #0x3
// 08025c26 rsbs.w r9,r3,#0x0
// 08025c2a and r9,r9,#0x7
// 08025c2e and r3,r3,#0x7
// 08025c32 it pl
// 08025c34 rsb.pl.w r3,r9,#0x0
// 08025c38 ldrb.w r9,[r8,#-0x15]
// 08025c3c lsl.w r3,r6,r3
// 08025c40 orr.w r3,r3,r9
// 08025c44 strb.w r3,[r8,#-0x15]
// 08025c48 ldrb r3,[r1,r2]
// 08025c4a orr r3,r3,#0x80
// 08025c4e strb r3,[r1,r2]
// 08025c50 ldrb.w r8,[r1,r2]
// 08025c54 ldr.w r3,[r0,#0x138]
// 08025c58 cmp r7,#0x1
// 08025c5a bfi r8,r3,#0x0,#0x4
// 08025c5e strb.w r8,[r1,r2]
// 08025c62 uxtb.w r3,r8
// 08025c66 bne 0x08025cde
// 08025c68 bfi r3,lr,#0x4,#0x2
// 08025c6c strb r3,[r1,r2]
// 08025c6e adds r5,#0x1
// 08025c70 b 0x0802557c
// 08025c72 subs r3,#0x1
// 08025c74 cmp r3,#0x1
// 08025c76 bhi 0x08025c50
// 08025c78 mov.w r8,#0x0
// 08025c7c ldr.w r9,[r0,#0x14]
// 08025c80 uxtb.w r10,r8
// 08025c84 cmp r10,r9
// 08025c86 blt 0x08025c90
// 08025c88 ldrb r3,[r1,r2]
// 08025c8a bfc r3,#0x7,#0x1
// 08025c8e b 0x08025c4e
// 08025c90 add.w r10,r0,r10, lsl #0x4
// 08025c94 ldr.w r3,[r10,#0x20]
// 08025c98 cmp r3,#0x1
// 08025c9a bne 0x08025cd8
// 08025c9c ldr.w r11,[r10,#0x24]
// 08025ca0 add.w r3,r11,#0xffffffff
// 08025ca4 mov r10,r3
// 08025ca6 cmp r3,#0x0
// 08025ca8 it lt
// 08025caa add.lt.w r10,r11,#0x6
// 08025cae add.w r11,sp,#0x40
// 08025cb2 add.w r10,r11,r10, asr #0x3
// 08025cb6 rsbs.w r11,r3,#0x0
// 08025cba and r11,r11,#0x7
// 08025cbe and r3,r3,#0x7
// 08025cc2 it pl
// 08025cc4 rsb.pl.w r3,r11,#0x0
// 08025cc8 ldrb.w r11,[r10,#-0x15]
// 08025ccc lsl.w r3,r6,r3
// 08025cd0 orr.w r3,r3,r11
// 08025cd4 strb.w r3,[r10,#-0x15]
// 08025cd8 add.w r8,r8,#0x1
// 08025cdc b 0x08025c80
// 08025cde ldr.w r0,[r0,#0x130]
// 08025ce2 cmp r0,#0x1
// 08025ce4 ite eq
// 08025ce6 bfi.eq r3,r0,#0x4,#0x2
// 08025cea bfc.ne r3,#0x4,#0x2
// 08025cee b 0x08025c6c
// 08025cf0 mla r3,r6,r3,r5
// 08025cf4 ldr r7,[r3,#0x10]
// 08025cf6 cmp r7,#0x1
// 08025cf8 bne 0x08025d3a
// 08025cfa ldr.w r12,[r3,#0x14]
// 08025cfe add.w r3,r12,#0xffffffff
// 08025d02 mov r7,r3
// 08025d04 cmp r3,#0x0
// 08025d06 it lt
// 08025d08 add.lt.w r7,r12,#0x6
// 08025d0c add.w r12,sp,#0x40
// 08025d10 add.w r7,r12,r7, asr #0x3
// 08025d14 rsbs.w r12,r3,#0x0
// 08025d18 and r12,r12,#0x7
// 08025d1c and r3,r3,#0x7
// 08025d20 it pl
// 08025d22 rsb.pl.w r3,r12,#0x0
// 08025d26 ldrb.w r12,[r7,#-0x15]
// 08025d2a lsl.w r3,r1,r3
// 08025d2e orr.w r3,r3,r12
// 08025d32 strb.w r3,[r7,#-0x15]
// 08025d36 adds r2,#0x1
// 08025d38 b 0x08025590
// 08025d3a ldr r7,[r3,#0x20]
// 08025d3c cmp r7,#0x1
// 08025d3e bne 0x08025d36
// 08025d40 ldr.w r12,[r3,#0x24]
// 08025d44 b 0x08025cfe
// 08025d46 cmp r0,#0x4
// 08025d48 bne.w 0x080255ac
// 08025d4c ldrb.w r3,[r5,#0x2b]
// 08025d50 cmp r3,#0x1
// 08025d52 beq 0x08025d6a
// 08025d54 cmp r3,#0x2
// 08025d56 bne.w 0x080255ac
// 08025d5a ldr r3,[r4,#0x54]
// 08025d5c ldr r1,[r3,#0x6c]
// 08025d5e b 0x08025dba
// 08025d60 ldrb.w r3,[r5,#0x2b]
// 08025d64 cmp r3,#0x1
// 08025d66 bne.w 0x080255ac
// 08025d6a ldr r3,[r4,#0x54]
// 08025d6c ldr r1,[r3,#0x68]
// 08025d6e b 0x08025dba
// 08025d70 ldrb.w r3,[r5,#0x2b]
// 08025d74 cmp r3,#0x1
// 08025d76 bne 0x08025daa
// 08025d78 ldr r3,[r4,#0x54]
// 08025d7a ldr r1,[r3,#0x68]
// 08025d7c subs r3,r1,#0x1
// 08025d7e mov r2,r3
// 08025d80 cmp r3,#0x0
// 08025d82 it lt
// 08025d84 add.lt r2,r1,#0x6
// 08025d86 add r1,sp,#0x40
// 08025d88 add.w r2,r1,r2, asr #0x3
// 08025d8c rsbs r1,r3
// 08025d8e and r1,r1,#0x7
// 08025d92 and r3,r3,#0x7
// 08025d96 it pl
// 08025d98 rsb.pl r3,r1
// 08025d9a movs r1,#0x1
// 08025d9c lsl.w r3,r1,r3
// 08025da0 ldrb.w r1,[r2,#-0x15]
// 08025da4 orrs r3,r1
// 08025da6 strb.w r3,[r2,#-0x15]
// 08025daa ldrb.w r3,[r5,#0x2c]
// 08025dae cmp r3,#0x1
// 08025db0 bne.w 0x080255ac
// 08025db4 ldr r3,[r4,#0x54]
// 08025db6 ldr.w r1,[r3,#0xf8]
// 08025dba subs r3,r1,#0x1
// 08025dbc mov r2,r3
// 08025dbe cmp r3,#0x0
// 08025dc0 it lt
// 08025dc2 add.lt r2,r1,#0x6
// 08025dc4 add r1,sp,#0x40
// 08025dc6 add.w r2,r1,r2, asr #0x3
// 08025dca rsbs r1,r3
// 08025dcc and r1,r1,#0x7
// 08025dd0 and r3,r3,#0x7
// 08025dd4 it pl
// 08025dd6 rsb.pl r3,r1
// 08025dd8 movs r1,#0x1
// 08025dda lsl.w r3,r1,r3
// 08025dde ldrb.w r1,[r2,#-0x15]
// 08025de2 orrs r3,r1
// 08025de4 strb.w r3,[r2,#-0x15]
// 08025de8 b.w 0x080255ac
// 08025dec cmp r3,#0x4
// 08025dee bne.w 0x080255be
// 08025df2 ldrb.w r3,[r5,#0x2d]
// 08025df6 cmp r3,#0x1
// 08025df8 beq 0x08025e12
// 08025dfa cmp r3,#0x2
// 08025dfc bne.w 0x080255be
// 08025e00 ldr r3,[r4,#0x54]
// 08025e02 ldr.w r1,[r3,#0x21c]
// 08025e06 b 0x08025e66
// 08025e08 ldrb.w r3,[r5,#0x2d]
// 08025e0c cmp r3,#0x1
// 08025e0e bne.w 0x080255be
// 08025e12 ldr r3,[r4,#0x54]
// 08025e14 ldr.w r1,[r3,#0x218]
// 08025e18 b 0x08025e66
// 08025e1a ldrb.w r3,[r5,#0x2d]
// 08025e1e cmp r3,#0x1
// 08025e20 bne 0x08025e56
// 08025e22 ldr r3,[r4,#0x54]
// 08025e24 ldr.w r1,[r3,#0x218]
// 08025e28 subs r3,r1,#0x1
// 08025e2a mov r2,r3
// 08025e2c cmp r3,#0x0
// 08025e2e it lt
// 08025e30 add.lt r2,r1,#0x6
// 08025e32 add r1,sp,#0x40
// 08025e34 add.w r2,r1,r2, asr #0x3
// 08025e38 rsbs r1,r3
// 08025e3a and r1,r1,#0x7
// 08025e3e and r3,r3,#0x7
// 08025e42 it pl
// 08025e44 rsb.pl r3,r1
// 08025e46 movs r1,#0x1
// 08025e48 lsl.w r3,r1,r3
// 08025e4c ldrb.w r1,[r2,#-0x15]
// 08025e50 orrs r3,r1
// 08025e52 strb.w r3,[r2,#-0x15]
// 08025e56 ldrb.w r3,[r5,#0x2e]
// 08025e5a cmp r3,#0x1
// 08025e5c bne.w 0x080255be
// 08025e60 ldr r3,[r4,#0x54]
// 08025e62 ldr.w r1,[r3,#0x2a8]
// 08025e66 subs r3,r1,#0x1
// 08025e68 mov r2,r3
// 08025e6a cmp r3,#0x0
// 08025e6c it lt
// 08025e6e add.lt r2,r1,#0x6
// 08025e70 add r1,sp,#0x40
// 08025e72 add.w r2,r1,r2, asr #0x3
// 08025e76 rsbs r1,r3
// 08025e78 and r1,r1,#0x7
// 08025e7c and r3,r3,#0x7
// 08025e80 it pl
// 08025e82 rsb.pl r3,r1
// 08025e84 movs r1,#0x1
// 08025e86 lsl.w r3,r1,r3
// 08025e8a ldrb.w r1,[r2,#-0x15]
// 08025e8e orrs r3,r1
// 08025e90 strb.w r3,[r2,#-0x15]
// 08025e94 b.w 0x080255be
// 08025e98 cmp r3,#0x1
// 08025e9a bne.w 0x080255da
// 08025e9e bl 0x0802cee4
// 08025ea2 cbz r0,0x08025ef0
// 08025ea4 ldrb r0,[r5,#0xd]
// 08025ea6 bl 0x0802cf50
// 08025eaa cbz r0,0x08025ef0
// 08025eac ldr.w r3,[r5,#0x42]
// 08025eb0 cmp r3,#0x1
// 08025eb2 bne 0x08025ef0
// 08025eb4 ldrb r3,[r5,#0xd]
// 08025eb6 ldr r2,[r4,#0x54]
// 08025eb8 add.w r3,r3,r3, lsl #0x3
// 08025ebc add.w r3,r2,r3, lsl #0x4
// 08025ec0 ldr r1,[r3,#0x68]
// 08025ec2 subs r3,r1,#0x1
// 08025ec4 mov r2,r3
// 08025ec6 cmp r3,#0x0
// 08025ec8 it lt
// 08025eca add.lt r2,r1,#0x6
// 08025ecc add r1,sp,#0x40
// 08025ece add.w r2,r1,r2, asr #0x3
// 08025ed2 rsbs r1,r3
// 08025ed4 and r1,r1,#0x7
// 08025ed8 and r3,r3,#0x7
// 08025edc it pl
// 08025ede rsb.pl r3,r1
// 08025ee0 movs r1,#0x1
// 08025ee2 lsl.w r3,r1,r3
// 08025ee6 ldrb.w r1,[r2,#-0x15]
// 08025eea orrs r3,r1
// 08025eec strb.w r3,[r2,#-0x15]
// 08025ef0 ldrb r0,[r5,#0x6]
// 08025ef2 bl 0x0802cee4
// 08025ef6 cmp r0,#0x0
// 08025ef8 beq.w 0x080255da
// 08025efc ldrb r0,[r5,#0xe]
// 08025efe bl 0x0802cf50
// 08025f02 cmp r0,#0x0
// 08025f04 beq.w 0x080255da
// 08025f08 ldr.w r3,[r5,#0x46]
// 08025f0c cmp r3,#0x1
// 08025f0e bne.w 0x080255da
// 08025f12 ldrb r3,[r5,#0xe]
// 08025f14 ldr r2,[r4,#0x54]
// 08025f16 add.w r3,r3,r3, lsl #0x3
// 08025f1a add.w r3,r2,r3, lsl #0x4
// 08025f1e ldr r1,[r3,#0x68]
// 08025f20 subs r3,r1,#0x1
// 08025f22 mov r2,r3
// 08025f24 cmp r3,#0x0
// 08025f26 it lt
// 08025f28 add.lt r2,r1,#0x6
// 08025f2a add r1,sp,#0x40
// 08025f2c add.w r2,r1,r2, asr #0x3
// 08025f30 rsbs r1,r3
// 08025f32 and r1,r1,#0x7
// 08025f36 and r3,r3,#0x7
// 08025f3a it pl
// 08025f3c rsb.pl r3,r1
// 08025f3e movs r1,#0x1
// 08025f40 lsl.w r3,r1,r3
// 08025f44 ldrb.w r1,[r2,#-0x15]
// 08025f48 orrs r3,r1
// 08025f4a strb.w r3,[r2,#-0x15]
// 08025f4e b.w 0x080255da
// FUNCTION 08025f54

undefined4 FUN_08025f54(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  char *pcVar16;
  int iVar17;
  byte bVar18;
  char *pcVar19;
  int iVar20;
  int iVar21;
  undefined1 local_3c;
  undefined1 local_3b;
  byte abStack_3a [22];
  
  FUN_08035d8c(&local_3c,0,0x14);
  iVar17 = DAT_080262a8;
  iVar2 = DAT_0802629c;
  iVar8 = DAT_08026298;
  iVar3 = *(int *)(DAT_08026298 + 0x18);
  iVar15 = *(int *)(DAT_08026298 + 0x1c);
  for (bVar6 = 0; (int)(uint)bVar6 < iVar3; bVar6 = bVar6 + 1) {
    iVar5 = (uint)bVar6 * 0x28 + iVar15;
    if (*(int *)(iVar5 + 0x20) == 1) {
      iVar5 = *(int *)(iVar5 + 0x24);
      uVar13 = iVar5 - 1;
      uVar4 = uVar13;
      if ((int)uVar13 < 0) {
        uVar4 = iVar5 + 6;
      }
      uVar14 = uVar13 & 7;
      if (-1 < (int)-uVar13) {
        uVar14 = -(-uVar13 & 7);
      }
      abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
    }
  }
  iVar3 = *(int *)(DAT_08026298 + 0x30);
  iVar15 = *(int *)(DAT_08026298 + 0x34);
  for (uVar4 = 0; (int)(uVar4 & 0xff) < iVar3; uVar4 = uVar4 + 1) {
    iVar5 = (uVar4 & 0xff) * 0x78 + iVar15;
    iVar21 = iVar5 + 0x70;
    do {
      if (*(int *)(iVar5 + 0x10) == 1) {
        uVar14 = *(int *)(iVar5 + 0x14) - 1;
        uVar13 = uVar14;
        if ((int)uVar14 < 0) {
          uVar13 = *(int *)(iVar5 + 0x14) + 6;
        }
        uVar10 = uVar14 & 7;
        if (-1 < (int)-uVar14) {
          uVar10 = -(-uVar14 & 7);
        }
        abStack_3a[(int)uVar13 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3a[(int)uVar13 >> 3];
      }
      iVar5 = iVar5 + 0x10;
    } while (iVar21 != iVar5);
  }
  iVar3 = *(int *)(DAT_08026298 + 0x60);
  iVar15 = *(int *)(DAT_08026298 + 100);
  for (bVar6 = 0; uVar4 = (uint)bVar6, (int)uVar4 < iVar3; bVar6 = bVar6 + 1) {
    iVar5 = uVar4 * 0x13c + iVar15;
    iVar21 = *(int *)(iVar5 + 0x120);
    if (*(int *)(iVar5 + 0x10) == 0) {
      if (iVar21 == 1) {
        uVar14 = *(int *)(iVar5 + 0x124) - 1;
        uVar13 = uVar14;
        if ((int)uVar14 < 0) {
          uVar13 = *(int *)(iVar5 + 0x124) + 6;
        }
        uVar10 = uVar14 & 7;
        if (-1 < (int)-uVar14) {
          uVar10 = -(-uVar14 & 7);
        }
        abStack_3a[(int)uVar13 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3a[(int)uVar13 >> 3];
      }
      if (*(int *)(iVar5 + 0x130) == 1) {
        uVar14 = *(int *)(iVar5 + 0x134) - 1;
        uVar13 = uVar14;
        if ((int)uVar14 < 0) {
          uVar13 = *(int *)(iVar5 + 0x134) + 6;
        }
        uVar10 = uVar14 & 7;
        if (-1 < (int)-uVar14) {
          uVar10 = -(-uVar14 & 7);
        }
        abStack_3a[(int)uVar13 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3a[(int)uVar13 >> 3];
      }
      bVar9 = *(byte *)(iVar2 + uVar4) | 0x80;
LAB_08026176:
      *(byte *)(iVar2 + uVar4) = bVar9;
    }
    else if (*(int *)(iVar5 + 0x10) - 1U < 2) {
      iVar11 = *(int *)(iVar5 + 0x14);
      for (bVar9 = 0; pcVar16 = DAT_080262a0, pcVar19 = (char *)(uint)bVar9, (int)pcVar19 < iVar11;
          bVar9 = bVar9 + 1) {
        iVar20 = iVar5 + (int)pcVar19 * 0x10;
        if (*(int *)(iVar20 + 0x20) == 1) {
          iVar20 = *(int *)(iVar20 + 0x24);
          uVar14 = iVar20 - 1;
          uVar13 = uVar14;
          if ((int)uVar14 < 0) {
            uVar13 = iVar20 + 6;
          }
          uVar10 = uVar14 & 7;
          if (-1 < (int)-uVar14) {
            uVar10 = -(-uVar14 & 7);
          }
          abStack_3a[(int)uVar13 >> 3] = (byte)(1 << (uVar10 & 0xff)) | abStack_3a[(int)uVar13 >> 3]
          ;
          pcVar12 = (char *)(uint)*(byte *)(iVar17 + uVar4);
          pcVar1 = pcVar12;
          if (pcVar12 != pcVar19) {
            *(byte *)(iVar17 + uVar4) = bVar9;
            pcVar1 = pcVar16;
          }
          if (pcVar12 != pcVar19) {
            pcVar1[uVar4] = '\x01';
          }
        }
      }
      bVar9 = *(byte *)(iVar2 + uVar4) & 0x7f;
      goto LAB_08026176;
    }
    bVar9 = *(byte *)(iVar2 + uVar4);
    bVar18 = (byte)*(undefined4 *)(iVar5 + 0x138) & 0xf;
    *(byte *)(iVar2 + uVar4) = bVar9 & 0xf0 | bVar18;
    if (iVar21 == 1) {
      cVar7 = '\x02';
LAB_0802618e:
      bVar18 = bVar9 & 0xc0 | bVar18 | cVar7 << 4;
    }
    else {
      cVar7 = '\x01';
      if (*(int *)(iVar5 + 0x130) == 1) goto LAB_0802618e;
      bVar18 = bVar9 & 0xc0 | bVar18;
    }
    *(byte *)(iVar2 + uVar4) = bVar18;
  }
  cVar7 = '\x04';
  pcVar16 = DAT_080262a0;
  do {
    if (*pcVar16 == '\x01') {
      FUN_08024708();
      *pcVar16 = '\0';
    }
    cVar7 = cVar7 + -1;
    pcVar16 = pcVar16 + 1;
  } while (cVar7 != '\0');
  FUN_080248c4();
  iVar2 = DAT_080262a4;
  iVar17 = *(int *)(DAT_08026298 + 0x58);
  iVar3 = *(int *)(DAT_08026298 + 0x5c);
  for (bVar6 = 0; (int)(uint)bVar6 < iVar17; bVar6 = bVar6 + 1) {
    iVar15 = (uint)bVar6 * 0x28 + iVar3;
    if (*(int *)(iVar15 + 0x10) == 1) {
      iVar15 = *(int *)(iVar15 + 0x14);
LAB_08026234:
      uVar13 = iVar15 - 1;
      uVar4 = uVar13;
      if ((int)uVar13 < 0) {
        uVar4 = iVar15 + 6;
      }
      uVar14 = uVar13 & 7;
      if (-1 < (int)-uVar13) {
        uVar14 = -(-uVar13 & 7);
      }
      abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
    }
    else if (*(int *)(iVar15 + 0x20) == 1) {
      iVar15 = *(int *)(iVar15 + 0x24);
      goto LAB_08026234;
    }
  }
  bVar6 = *(byte *)(DAT_080262a4 + 5);
  if (bVar6 != 0) {
    if (bVar6 == 3) {
      if (*(char *)(DAT_080262a4 + 0x2b) == '\x01') {
        iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x68);
        uVar13 = iVar17 - 1;
        uVar4 = uVar13;
        if ((int)uVar13 < 0) {
          uVar4 = iVar17 + 6;
        }
        uVar14 = uVar13 & 7;
        if (-1 < (int)-uVar13) {
          uVar14 = -(-uVar13 & 7);
        }
        abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
      }
      if (*(char *)(DAT_080262a4 + 0x2c) == '\x01') {
        iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0xf8);
LAB_08026306:
        uVar13 = iVar17 - 1;
        uVar4 = uVar13;
        if ((int)uVar13 < 0) {
          uVar4 = iVar17 + 6;
        }
        uVar14 = uVar13 & 7;
        if (-1 < (int)-uVar13) {
          uVar14 = -(-uVar13 & 7);
        }
        abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
      }
    }
    else if (bVar6 < 4) {
      if (*(char *)(DAT_080262a4 + 0x2b) == '\x01') {
LAB_080262b6:
        iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x68);
        goto LAB_08026306;
      }
    }
    else if (bVar6 == 4) {
      if (*(char *)(DAT_080262a4 + 0x2b) == '\x01') goto LAB_080262b6;
      if (*(char *)(DAT_080262a4 + 0x2b) == '\x02') {
        iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x6c);
        goto LAB_08026306;
      }
    }
  }
  bVar6 = *(byte *)(DAT_080262a4 + 6);
  if (bVar6 == 0) goto LAB_08026006;
  if (bVar6 == 3) {
    if (*(char *)(DAT_080262a4 + 0x2d) == '\x01') {
      iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x218);
      uVar13 = iVar17 - 1;
      uVar4 = uVar13;
      if ((int)uVar13 < 0) {
        uVar4 = iVar17 + 6;
      }
      uVar14 = uVar13 & 7;
      if (-1 < (int)-uVar13) {
        uVar14 = -(-uVar13 & 7);
      }
      abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
    }
    if (*(char *)(DAT_080262a4 + 0x2e) != '\x01') goto LAB_08026006;
    iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x2a8);
  }
  else {
    if (bVar6 < 4) {
      if (*(char *)(DAT_080262a4 + 0x2d) != '\x01') goto LAB_08026006;
    }
    else {
      if (bVar6 != 4) goto LAB_08026006;
      if (*(char *)(DAT_080262a4 + 0x2d) != '\x01') {
        if (*(char *)(DAT_080262a4 + 0x2d) != '\x02') goto LAB_08026006;
        iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x21c);
        goto LAB_080263b0;
      }
    }
    iVar17 = *(int *)(*(int *)(DAT_08026298 + 0x54) + 0x218);
  }
LAB_080263b0:
  uVar13 = iVar17 - 1;
  uVar4 = uVar13;
  if ((int)uVar13 < 0) {
    uVar4 = iVar17 + 6;
  }
  uVar14 = uVar13 & 7;
  if (-1 < (int)-uVar13) {
    uVar14 = -(-uVar13 & 7);
  }
  abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
LAB_08026006:
  if ((*(byte *)(DAT_080262a4 + 0x2f) & 0xfd) == 0) {
    local_3c = (undefined1)*(undefined4 *)(DAT_080262a4 + 0x46);
    local_3b = (undefined1)*(undefined4 *)(DAT_080262a4 + 0x42);
  }
  else if (*(byte *)(DAT_080262a4 + 0x2f) == 1) {
    local_3c = 0;
    local_3b = 0;
    iVar17 = FUN_0802cee4();
    if (((iVar17 != 0) && (iVar17 = FUN_0802cf50(*(undefined1 *)(iVar2 + 0xd)), iVar17 != 0)) &&
       (*(int *)(iVar2 + 0x42) == 1)) {
      iVar17 = *(int *)(*(int *)(iVar8 + 0x54) + (uint)*(byte *)(iVar2 + 0xd) * 0x90 + 0x68);
      uVar13 = iVar17 - 1;
      uVar4 = uVar13;
      if ((int)uVar13 < 0) {
        uVar4 = iVar17 + 6;
      }
      uVar14 = uVar13 & 7;
      if (-1 < (int)-uVar13) {
        uVar14 = -(-uVar13 & 7);
      }
      abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
    }
    iVar17 = FUN_0802cee4(*(undefined1 *)(iVar2 + 6));
    if (((iVar17 != 0) && (iVar17 = FUN_0802cf50(*(undefined1 *)(iVar2 + 0xe)), iVar17 != 0)) &&
       (*(int *)(iVar2 + 0x46) == 1)) {
      iVar8 = *(int *)(*(int *)(iVar8 + 0x54) + (uint)*(byte *)(iVar2 + 0xe) * 0x90 + 0x68);
      uVar13 = iVar8 - 1;
      uVar4 = uVar13;
      if ((int)uVar13 < 0) {
        uVar4 = iVar8 + 6;
      }
      uVar14 = uVar13 & 7;
      if (-1 < (int)-uVar13) {
        uVar14 = -(-uVar13 & 7);
      }
      abStack_3a[(int)uVar4 >> 3] = (byte)(1 << (uVar14 & 0xff)) | abStack_3a[(int)uVar4 >> 3];
    }
  }
  FUN_08026fe0(4,0,0x200,&local_3c,0x14);
  return 0;
}


// 08025f54 push {r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 08025f58 sub sp,#0x34
// 08025f5a movs r1,#0x0
// 08025f5c movs r2,#0x14
// 08025f5e add r0,sp,#0x1c
// 08025f60 bl 0x08035d8c
// 08025f64 movs r6,#0x28
// 08025f66 movs r1,#0x0
// 08025f68 movs r7,#0x1
// 08025f6a ldr r4,[0x08026298]
// 08025f6c ldrd r0,r5,[r4,#0x18]
// 08025f70 uxtb r3,r1
// 08025f72 cmp r3,r0
// 08025f74 blt 0x0802603c
// 08025f76 ldrd r5,r6,[r4,#0x30]
// 08025f7a movs r0,#0x0
// 08025f7c movs r7,#0x78
// 08025f7e mov.w r12,#0x1
// 08025f82 uxtb r2,r0
// 08025f84 cmp r2,r5
// 08025f86 blt 0x08026086
// 08025f88 movs r7,#0x0
// 08025f8a mov.w r9,#0x13c
// 08025f8e movs r5,#0x1
// 08025f90 ldr r3,[r4,#0x60]
// 08025f92 ldr.w r12,[0x080262a8]
// 08025f96 str r3,[sp,#0x14]
// 08025f98 ldr r3,[r4,#0x64]
// 08025f9a ldr r1,[0x0802629c]
// 08025f9c str r3,[sp,#0xc]
// 08025f9e ldr r2,[sp,#0x14]
// 08025fa0 uxtb r3,r7
// 08025fa2 cmp r3,r2
// 08025fa4 blt.w 0x080260da
// 08025fa8 movs r7,#0x4
// 08025faa movs r6,#0x0
// 08025fac ldr r5,[0x080262a0]
// 08025fae ldrb.w r3,[r5],#0x1
// 08025fb2 cmp r3,#0x1
// 08025fb4 bne 0x08025fbe
// 08025fb6 bl 0x08024708
// 08025fba strb.w r6,[r5,#-0x1]
// 08025fbe subs r1,r7,#0x1
// 08025fc0 ands r7,r1,#0xff
// 08025fc4 bne 0x08025fae
// 08025fc6 bl 0x080248c4
// 08025fca mov r1,r7
// 08025fcc movs r0,#0x1
// 08025fce movs r7,#0x28
// 08025fd0 ldr r2,[0x08026298]
// 08025fd2 ldrd r5,r6,[r2,#0x58]
// 08025fd6 uxtb.w r12,r1
// 08025fda cmp r12,r5
// 08025fdc blt.w 0x08026224
// 08025fe0 ldr r5,[0x080262a4]
// 08025fe2 ldrb r0,[r5,#0x5]
// 08025fe4 cbz r0,0x08025ff4
// 08025fe6 cmp r0,#0x3
// 08025fe8 beq.w 0x080262bc
// 08025fec bhi.w 0x0802627e
// 08025ff0 bne.w 0x080262ac
// 08025ff4 ldrb r3,[r5,#0x6]
// 08025ff6 cbz r3,0x08026006
// 08025ff8 cmp r3,#0x3
// 08025ffa beq.w 0x08026364
// 08025ffe bhi.w 0x08026336
// 08026002 bne.w 0x08026352
// 08026006 ldrb.w r3,[r5,#0x2f]
// 0802600a tst r3,#0xfd
// 0802600e bne.w 0x080263e0
// 08026012 ldr.w r3,[r5,#0x46]
// 08026016 strb.w r3,[sp,#0x1c]
// 0802601a ldr.w r3,[r5,#0x42]
// 0802601e strb.w r3,[sp,#0x1d]
// 08026022 movs r3,#0x14
// 08026024 mov.w r2,#0x200
// 08026028 str r3,[sp,#0x0]
// 0802602a movs r1,#0x0
// 0802602c add r3,sp,#0x1c
// 0802602e movs r0,#0x4
// 08026030 bl 0x08026fe0
// 08026034 movs r0,#0x0
// 08026036 add sp,#0x34
// 08026038 pop.w {r4,r5,r6,r7,r8,r9,r10,r11,pc}
// 0802603c mla r3,r6,r3,r5
// 08026040 ldr r2,[r3,#0x20]
// 08026042 cmp r2,#0x1
// 08026044 bne 0x08026082
// 08026046 ldr.w r12,[r3,#0x24]
// 0802604a add.w r3,r12,#0xffffffff
// 0802604e mov r2,r3
// 08026050 cmp r3,#0x0
// 08026052 it lt
// 08026054 add.lt.w r2,r12,#0x6
// 08026058 add.w r12,sp,#0x30
// 0802605c add.w r2,r12,r2, asr #0x3
// 08026060 rsbs.w r12,r3,#0x0
// 08026064 and r12,r12,#0x7
// 08026068 and r3,r3,#0x7
// 0802606c it pl
// 0802606e rsb.pl.w r3,r12,#0x0
// 08026072 ldrb.w r12,[r2,#-0x12]
// 08026076 lsl.w r3,r7,r3
// 0802607a orr.w r3,r3,r12
// 0802607e strb.w r3,[r2,#-0x12]
// 08026082 adds r1,#0x1
// 08026084 b 0x08025f70
// 08026086 mla r2,r7,r2,r6
// 0802608a add.w lr,r2,#0x70
// 0802608e ldr r3,[r2,#0x10]
// 08026090 cmp r3,#0x1
// 08026092 bne 0x080260d0
// 08026094 ldr.w r8,[r2,#0x14]
// 08026098 add.w r3,r8,#0xffffffff
// 0802609c mov r1,r3
// 0802609e cmp r3,#0x0
// 080260a0 it lt
// 080260a2 add.lt.w r1,r8,#0x6
// 080260a6 add.w r8,sp,#0x30
// 080260aa add.w r1,r8,r1, asr #0x3
// 080260ae rsbs.w r8,r3,#0x0
// 080260b2 and r8,r8,#0x7
// 080260b6 and r3,r3,#0x7
// 080260ba it pl
// 080260bc rsb.pl.w r3,r8,#0x0
// 080260c0 ldrb.w r8,[r1,#-0x12]
// 080260c4 lsl.w r3,r12,r3
// 080260c8 orr.w r3,r3,r8
// 080260cc strb.w r3,[r1,#-0x12]
// 080260d0 adds r2,#0x10
// 080260d2 cmp lr,r2
// 080260d4 bne 0x0802608e
// 080260d6 adds r0,#0x1
// 080260d8 b 0x08025f82
// 080260da ldr r2,[sp,#0xc]
// 080260dc mla r0,r9,r3,r2
// 080260e0 ldr r2,[r0,#0x10]
// 080260e2 ldr.w lr,[r0,#0x120]
// 080260e6 cmp r2,#0x0
// 080260e8 bne 0x08026198
// 080260ea cmp.w lr,#0x1
// 080260ee bne 0x0802612c
// 080260f0 ldr.w r8,[r0,#0x124]
// 080260f4 add.w r2,r8,#0xffffffff
// 080260f8 mov r6,r2
// 080260fa cmp r2,#0x0
// 080260fc it lt
// 080260fe add.lt.w r6,r8,#0x6
// 08026102 add.w r8,sp,#0x30
// 08026106 add.w r6,r8,r6, asr #0x3
// 0802610a rsbs.w r8,r2,#0x0
// 0802610e and r8,r8,#0x7
// 08026112 and r2,r2,#0x7
// 08026116 it pl
// 08026118 rsb.pl.w r2,r8,#0x0
// 0802611c ldrb.w r8,[r6,#-0x12]
// 08026120 lsl.w r2,r5,r2
// 08026124 orr.w r2,r2,r8
// 08026128 strb.w r2,[r6,#-0x12]
// 0802612c ldr.w r2,[r0,#0x130]
// 08026130 cmp r2,#0x1
// 08026132 bne 0x08026170
// 08026134 ldr.w r8,[r0,#0x134]
// 08026138 add.w r2,r8,#0xffffffff
// 0802613c mov r6,r2
// 0802613e cmp r2,#0x0
// 08026140 it lt
// 08026142 add.lt.w r6,r8,#0x6
// 08026146 add.w r8,sp,#0x30
// 0802614a add.w r6,r8,r6, asr #0x3
// 0802614e rsbs.w r8,r2,#0x0
// 08026152 and r8,r8,#0x7
// 08026156 and r2,r2,#0x7
// 0802615a it pl
// 0802615c rsb.pl.w r2,r8,#0x0
// 08026160 ldrb.w r8,[r6,#-0x12]
// 08026164 lsl.w r2,r5,r2
// 08026168 orr.w r2,r2,r8
// 0802616c strb.w r2,[r6,#-0x12]
// 08026170 ldrb r2,[r1,r3]
// 08026172 orr r2,r2,#0x80
// 08026176 strb r2,[r1,r3]
// 08026178 ldrb r6,[r1,r3]
// 0802617a ldr.w r2,[r0,#0x138]
// 0802617e cmp.w lr,#0x1
// 08026182 bfi r6,r2,#0x0,#0x4
// 08026186 strb r6,[r1,r3]
// 08026188 uxtb r6,r6
// 0802618a bne 0x08026216
// 0802618c movs r2,#0x2
// 0802618e bfi r6,r2,#0x4,#0x2
// 08026192 strb r6,[r1,r3]
// 08026194 adds r7,#0x1
// 08026196 b 0x08025f9e
// 08026198 subs r2,#0x1
// 0802619a cmp r2,#0x1
// 0802619c bhi 0x08026178
// 0802619e mov.w r8,#0x0
// 080261a2 ldr r2,[r0,#0x14]
// 080261a4 str r2,[sp,#0x10]
// 080261a6 ldr r2,[sp,#0x10]
// 080261a8 uxtb.w r6,r8
// 080261ac cmp r6,r2
// 080261ae blt 0x080261b8
// 080261b0 ldrb r2,[r1,r3]
// 080261b2 bfc r2,#0x7,#0x1
// 080261b6 b 0x08026176
// 080261b8 add.w r10,r0,r6, lsl #0x4
// 080261bc ldr.w r2,[r10,#0x20]
// 080261c0 cmp r2,#0x1
// 080261c2 bne 0x08026210
// 080261c4 ldr.w r11,[r10,#0x24]
// 080261c8 add.w r2,r11,#0xffffffff
// 080261cc mov r10,r2
// 080261ce cmp r2,#0x0
// 080261d0 it lt
// 080261d2 add.lt.w r10,r11,#0x6
// 080261d6 add.w r11,sp,#0x30
// 080261da add.w r10,r11,r10, asr #0x3
// 080261de rsbs.w r11,r2,#0x0
// 080261e2 and r11,r11,#0x7
// 080261e6 and r2,r2,#0x7
// 080261ea it pl
// 080261ec rsb.pl.w r2,r11,#0x0
// 080261f0 ldrb.w r11,[r10,#-0x12]
// 080261f4 lsl.w r2,r5,r2
// 080261f8 orr.w r2,r2,r11
// 080261fc strb.w r2,[r10,#-0x12]
// 08026200 ldrb.w r2,[r12,r3]
// 08026204 cmp r2,r6
// 08026206 ittt ne
// 08026208 ldr.ne r2,[0x080262a0]
// 0802620a strb.ne.w r6,[r12,r3]
// 0802620e strb.ne r5,[r2,r3]
// 08026210 add.w r8,r8,#0x1
// 08026214 b 0x080261a6
// 08026216 ldr.w r2,[r0,#0x130]
// 0802621a cmp r2,#0x1
// 0802621c beq 0x0802618e
// 0802621e bfc r6,#0x4,#0x2
// 08026222 b 0x08026192
// 08026224 mla r12,r7,r12,r6
// 08026228 ldr.w r3,[r12,#0x10]
// 0802622c cmp r3,#0x1
// 0802622e bne 0x08026270
// 08026230 ldr.w lr,[r12,#0x14]
// 08026234 add.w r3,lr,#0xffffffff
// 08026238 mov r12,r3
// 0802623a cmp r3,#0x0
// 0802623c it lt
// 0802623e add.lt.w r12,lr,#0x6
// 08026242 add.w lr,sp,#0x30
// 08026246 add.w r12,lr,r12, asr #0x3
// 0802624a rsbs.w lr,r3,#0x0
// 0802624e and lr,lr,#0x7
// 08026252 and r3,r3,#0x7
// 08026256 it pl
// 08026258 rsb.pl.w r3,lr,#0x0
// 0802625c ldrb.w lr,[r12,#-0x12]
// 08026260 lsl.w r3,r0,r3
// 08026264 orr.w r3,r3,lr
// 08026268 strb.w r3,[r12,#-0x12]
// 0802626c adds r1,#0x1
// 0802626e b 0x08025fd6
// 08026270 ldr.w r3,[r12,#0x20]
// 08026274 cmp r3,#0x1
// 08026276 bne 0x0802626c
// 08026278 ldr.w lr,[r12,#0x24]
// 0802627c b 0x08026234
// 0802627e cmp r0,#0x4
// 08026280 bne.w 0x08025ff4
// 08026284 ldrb.w r3,[r5,#0x2b]
// 08026288 cmp r3,#0x1
// 0802628a beq 0x080262b6
// 0802628c cmp r3,#0x2
// 0802628e bne.w 0x08025ff4
// 08026292 ldr r3,[r2,#0x54]
// 08026294 ldr r6,[r3,#0x6c]
// 08026296 b 0x08026306
// 080262ac ldrb.w r3,[r5,#0x2b]
// 080262b0 cmp r3,#0x1
// 080262b2 bne.w 0x08025ff4
// 080262b6 ldr r3,[r2,#0x54]
// 080262b8 ldr r6,[r3,#0x68]
// 080262ba b 0x08026306
// 080262bc ldrb.w r3,[r5,#0x2b]
// 080262c0 cmp r3,#0x1
// 080262c2 bne 0x080262f6
// 080262c4 ldr r3,[r2,#0x54]
// 080262c6 ldr r6,[r3,#0x68]
// 080262c8 subs r3,r6,#0x1
// 080262ca mov r1,r3
// 080262cc cmp r3,#0x0
// 080262ce it lt
// 080262d0 add.lt r1,r6,#0x6
// 080262d2 add r6,sp,#0x30
// 080262d4 add.w r1,r6,r1, asr #0x3
// 080262d8 rsbs r6,r3
// 080262da and r6,r6,#0x7
// 080262de and r3,r3,#0x7
// 080262e2 it pl
// 080262e4 rsb.pl r3,r6
// 080262e6 movs r6,#0x1
// 080262e8 lsl.w r3,r6,r3
// 080262ec ldrb.w r6,[r1,#-0x12]
// 080262f0 orrs r3,r6
// 080262f2 strb.w r3,[r1,#-0x12]
// 080262f6 ldrb.w r3,[r5,#0x2c]
// 080262fa cmp r3,#0x1
// 080262fc bne.w 0x08025ff4
// 08026300 ldr r3,[r2,#0x54]
// 08026302 ldr.w r6,[r3,#0xf8]
// 08026306 subs r3,r6,#0x1
// 08026308 mov r1,r3
// 0802630a cmp r3,#0x0
// 0802630c it lt
// 0802630e add.lt r1,r6,#0x6
// 08026310 add r6,sp,#0x30
// 08026312 add.w r1,r6,r1, asr #0x3
// 08026316 rsbs r6,r3
// 08026318 and r6,r6,#0x7
// 0802631c and r3,r3,#0x7
// 08026320 it pl
// 08026322 rsb.pl r3,r6
// 08026324 movs r6,#0x1
// 08026326 lsl.w r3,r6,r3
// 0802632a ldrb.w r6,[r1,#-0x12]
// 0802632e orrs r3,r6
// 08026330 strb.w r3,[r1,#-0x12]
// 08026334 b 0x08025ff4
// 08026336 cmp r3,#0x4
// 08026338 bne.w 0x08026006
// 0802633c ldrb.w r3,[r5,#0x2d]
// 08026340 cmp r3,#0x1
// 08026342 beq 0x0802635c
// 08026344 cmp r3,#0x2
// 08026346 bne.w 0x08026006
// 0802634a ldr r3,[r2,#0x54]
// 0802634c ldr.w r1,[r3,#0x21c]
// 08026350 b 0x080263b0
// 08026352 ldrb.w r3,[r5,#0x2d]
// 08026356 cmp r3,#0x1
// 08026358 bne.w 0x08026006
// 0802635c ldr r3,[r2,#0x54]
// 0802635e ldr.w r1,[r3,#0x218]
// 08026362 b 0x080263b0
// 08026364 ldrb.w r3,[r5,#0x2d]
// 08026368 cmp r3,#0x1
// 0802636a bne 0x080263a0
// 0802636c ldr r3,[r2,#0x54]
// 0802636e ldr.w r6,[r3,#0x218]
// 08026372 subs r3,r6,#0x1
// 08026374 mov r1,r3
// 08026376 cmp r3,#0x0
// 08026378 it lt
// 0802637a add.lt r1,r6,#0x6
// 0802637c add r6,sp,#0x30
// 0802637e add.w r1,r6,r1, asr #0x3
// 08026382 rsbs r6,r3
// 08026384 and r6,r6,#0x7
// 08026388 and r3,r3,#0x7
// 0802638c it pl
// 0802638e rsb.pl r3,r6
// 08026390 movs r6,#0x1
// 08026392 lsl.w r3,r6,r3
// 08026396 ldrb.w r6,[r1,#-0x12]
// 0802639a orrs r3,r6
// 0802639c strb.w r3,[r1,#-0x12]
// 080263a0 ldrb.w r3,[r5,#0x2e]
// 080263a4 cmp r3,#0x1
// 080263a6 bne.w 0x08026006
// 080263aa ldr r3,[r2,#0x54]
// 080263ac ldr.w r1,[r3,#0x2a8]
// 080263b0 subs r3,r1,#0x1
// 080263b2 mov r2,r3
// 080263b4 cmp r3,#0x0
// 080263b6 it lt
// 080263b8 add.lt r2,r1,#0x6
// 080263ba add r1,sp,#0x30
// 080263bc add.w r2,r1,r2, asr #0x3
// 080263c0 rsbs r1,r3
// 080263c2 and r1,r1,#0x7
// 080263c6 and r3,r3,#0x7
// 080263ca it pl
// 080263cc rsb.pl r3,r1
// 080263ce movs r1,#0x1
// 080263d0 lsl.w r3,r1,r3
// 080263d4 ldrb.w r1,[r2,#-0x12]
// 080263d8 orrs r3,r1
// 080263da strb.w r3,[r2,#-0x12]
// 080263de b 0x08026006
// 080263e0 cmp r3,#0x1
// 080263e2 bne.w 0x08026022
// 080263e6 movs r3,#0x0
// 080263e8 strb.w r3,[sp,#0x1c]
// 080263ec strb.w r3,[sp,#0x1d]
// 080263f0 bl 0x0802cee4
// 080263f4 cbz r0,0x08026442
// 080263f6 ldrb r0,[r5,#0xd]
// 080263f8 bl 0x0802cf50
// 080263fc cbz r0,0x08026442
// 080263fe ldr.w r3,[r5,#0x42]
// 08026402 cmp r3,#0x1
// 08026404 bne 0x08026442
// 08026406 ldrb r3,[r5,#0xd]
// 08026408 ldr r2,[r4,#0x54]
// 0802640a add.w r3,r3,r3, lsl #0x3
// 0802640e add.w r3,r2,r3, lsl #0x4
// 08026412 ldr r1,[r3,#0x68]
// 08026414 subs r3,r1,#0x1
// 08026416 mov r2,r3
// 08026418 cmp r3,#0x0
// 0802641a it lt
// 0802641c add.lt r2,r1,#0x6
// 0802641e add r1,sp,#0x30
// 08026420 add.w r2,r1,r2, asr #0x3
// 08026424 rsbs r1,r3
// 08026426 and r1,r1,#0x7
// 0802642a and r3,r3,#0x7
// 0802642e it pl
// 08026430 rsb.pl r3,r1
// 08026432 movs r1,#0x1
// 08026434 lsl.w r3,r1,r3
// 08026438 ldrb.w r1,[r2,#-0x12]
// 0802643c orrs r3,r1
// 0802643e strb.w r3,[r2,#-0x12]
// 08026442 ldrb r0,[r5,#0x6]
// 08026444 bl 0x0802cee4
// 08026448 cmp r0,#0x0
// 0802644a beq.w 0x08026022
// 0802644e ldrb r0,[r5,#0xe]
// 08026450 bl 0x0802cf50
// 08026454 cmp r0,#0x0
// 08026456 beq.w 0x08026022
// 0802645a ldr.w r3,[r5,#0x46]
// 0802645e cmp r3,#0x1
// 08026460 bne.w 0x08026022
// 08026464 ldrb r3,[r5,#0xe]
// 08026466 ldr r2,[r4,#0x54]
// 08026468 add.w r3,r3,r3, lsl #0x3
// 0802646c add.w r3,r2,r3, lsl #0x4
// 08026470 ldr r1,[r3,#0x68]
// 08026472 subs r3,r1,#0x1
// 08026474 mov r2,r3
// 08026476 cmp r3,#0x0
// 08026478 it lt
// 0802647a add.lt r2,r1,#0x6
// 0802647c add r1,sp,#0x30
// 0802647e add.w r2,r1,r2, asr #0x3
// 08026482 rsbs r1,r3
// 08026484 and r1,r1,#0x7
// 08026488 and r3,r3,#0x7
// 0802648c it pl
// 0802648e rsb.pl r3,r1
// 08026490 movs r1,#0x1
// 08026492 lsl.w r3,r1,r3
// 08026496 ldrb.w r1,[r2,#-0x12]
// 0802649a orrs r3,r1
// 0802649c strb.w r3,[r2,#-0x12]
// 080264a0 b 0x08026022
