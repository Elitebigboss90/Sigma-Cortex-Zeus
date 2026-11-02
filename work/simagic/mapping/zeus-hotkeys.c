// FUNCTION 08023910

void FUN_08023910(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  
  FUN_08026e04(2);
  FUN_08034d64(DAT_08023a70);
  FUN_0802ca7c();
  sVar6 = 8;
  do {
    FUN_0802c61c(sVar6,1);
    FUN_0802c41c(0,0xec,0x2b,0x24);
    sVar7 = sVar6 + 1;
    FUN_0802c2a8(sVar6,1);
    sVar6 = sVar7;
  } while (sVar7 != 0xc);
  FUN_0802c32c(8);
  FUN_0802c32c(9);
  FUN_0802c32c(10);
  FUN_0802c32c(0xb);
  uVar3 = DAT_08023a78;
  puVar2 = DAT_08023a74;
  uVar1 = DAT_08023a70;
  uVar9 = 0;
  uVar11 = 7;
  do {
    iVar4 = FUN_0802b814(7);
    if ((iVar4 == 0) && (iVar4 = FUN_0802b814(8), iVar4 == 0)) {
      uVar9 = uVar9 + 1 & 0xff;
      if (uVar9 < 0x3c) {
        uVar8 = uVar9 / 10;
        if (uVar11 == uVar8) goto LAB_08023a58;
      }
      else {
        if (uVar11 == 6) {
LAB_080239bc:
          FUN_08034d6e(DAT_08023a70);
          FUN_0802c61c(0xc,10);
          FUN_0802c61c(0xd,10);
          FUN_0802c41c(0,0xec,0x2b,0x24);
          FUN_0802c2a8(0xc,3);
          FUN_0802c2a8(0xd,3);
          FUN_0802c32c(0xc);
          FUN_0802c32c(0xd);
          FUN_08034d64(DAT_08023a70);
          FUN_0802aec4(1);
          thunk_FUN_0802fec8(3000);
          FUN_08034d6e(DAT_08023a70);
          FUN_0802ca7c();
          thunk_FUN_0802fec8(2000);
          FUN_08029894(0);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uVar8 = 6;
        uVar9 = 0x3c;
      }
      FUN_08034d6e(uVar1);
      FUN_0802bf7c(puVar2[uVar8],uVar3);
      FUN_0802bf7c(puVar2[uVar8 + 7],uVar3);
      FUN_08034d64(uVar1);
      if (uVar9 == 0x3c) goto LAB_080239bc;
    }
    else {
      uVar8 = uVar11;
      if (uVar11 != 7) {
        FUN_08034d6e(uVar1);
        cVar5 = '\0';
        puVar10 = DAT_08023a74;
        do {
          cVar5 = cVar5 + '\x01';
          FUN_0802bf7c(*puVar10,0);
          FUN_0802bf7c(puVar10[7],0);
          puVar10 = puVar10 + 1;
        } while (cVar5 != '\a');
        FUN_08034d64(uVar1);
        uVar8 = 7;
      }
      uVar9 = 0;
    }
LAB_08023a58:
    thunk_FUN_0802fec8(0x32);
    uVar11 = uVar8;
  } while( true );
}


// 08023910 push {r3,r4,r5,r6,r7,r8,r9,lr}
// 08023914 movs r0,#0x2
// 08023916 bl 0x08026e04
// 0802391a ldr r0,[0x08023a70]
// 0802391c bl 0x08034d64
// 08023920 movs r4,#0x8
// 08023922 bl 0x0802ca7c
// 08023926 movs r1,#0x1
// 08023928 mov r0,r4
// 0802392a bl 0x0802c61c
// 0802392e movs r3,#0x24
// 08023930 movs r2,#0x2b
// 08023932 movs r1,#0xec
// 08023934 movs r0,#0x0
// 08023936 bl 0x0802c41c
// 0802393a mov r0,r4
// 0802393c adds r4,#0x1
// 0802393e movs r1,#0x1
// 08023940 uxth r4,r4
// 08023942 bl 0x0802c2a8
// 08023946 cmp r4,#0xc
// 08023948 bne 0x08023926
// 0802394a movs r0,#0x8
// 0802394c bl 0x0802c32c
// 08023950 movs r0,#0x9
// 08023952 bl 0x0802c32c
// 08023956 movs r0,#0xa
// 08023958 bl 0x0802c32c
// 0802395c movs r0,#0xb
// 0802395e bl 0x0802c32c
// 08023962 movs r6,#0x7
// 08023964 movs r5,#0x0
// 08023966 ldr r7,[0x08023a70]
// 08023968 ldr.w r8,[0x08023a74]
// 0802396c ldr.w r9,[0x08023a78]
// 08023970 movs r0,#0x7
// 08023972 bl 0x0802b814
// 08023976 cmp r0,#0x0
// 08023978 bne 0x08023a28
// 0802397a movs r0,#0x8
// 0802397c bl 0x0802b814
// 08023980 cmp r0,#0x0
// 08023982 bne 0x08023a28
// 08023984 adds r5,#0x1
// 08023986 uxtb r5,r5
// 08023988 cmp r5,#0x3b
// 0802398a bhi 0x08023a66
// 0802398c movs r4,#0xa
// 0802398e udiv r4,r5,r4
// 08023992 cmp r6,r4
// 08023994 beq 0x08023a58
// 08023996 mov r0,r7
// 08023998 bl 0x08034d6e
// 0802399c mov r1,r9
// 0802399e ldrb.w r0,[r8,r4]
// 080239a2 bl 0x0802bf7c
// 080239a6 add.w r3,r8,r4
// 080239aa ldrb r0,[r3,#0x7]
// 080239ac mov r1,r9
// 080239ae bl 0x0802bf7c
// 080239b2 mov r0,r7
// 080239b4 bl 0x08034d64
// 080239b8 cmp r5,#0x3c
// 080239ba bne 0x08023a58
// 080239bc ldr r0,[0x08023a70]
// 080239be bl 0x08034d6e
// 080239c2 movs r1,#0xa
// 080239c4 movs r0,#0xc
// 080239c6 bl 0x0802c61c
// 080239ca movs r1,#0xa
// 080239cc movs r0,#0xd
// 080239ce bl 0x0802c61c
// 080239d2 movs r3,#0x24
// 080239d4 movs r2,#0x2b
// 080239d6 movs r1,#0xec
// 080239d8 movs r0,#0x0
// 080239da bl 0x0802c41c
// 080239de movs r1,#0x3
// 080239e0 movs r0,#0xc
// 080239e2 bl 0x0802c2a8
// 080239e6 movs r1,#0x3
// 080239e8 movs r0,#0xd
// 080239ea bl 0x0802c2a8
// 080239ee movs r0,#0xc
// 080239f0 bl 0x0802c32c
// 080239f4 movs r0,#0xd
// 080239f6 bl 0x0802c32c
// 080239fa ldr r0,[0x08023a70]
// 080239fc bl 0x08034d64
// 08023a00 movs r0,#0x1
// 08023a02 bl 0x0802aec4
// 08023a06 movw r0,#0xbb8
// 08023a0a bl 0x080273a4
// 08023a0e ldr r0,[0x08023a70]
// 08023a10 bl 0x08034d6e
// 08023a14 bl 0x0802ca7c
// 08023a18 mov.w r0,#0x7d0
// 08023a1c bl 0x080273a4
// 08023a20 movs r0,#0x0
// 08023a22 bl 0x08029894
// 08023a26 b 0x08023a26
// 08023a28 cmp r6,#0x7
// 08023a2a beq 0x08023a62
// 08023a2c mov r0,r7
// 08023a2e bl 0x08034d6e
// 08023a32 movs r4,#0x0
// 08023a34 ldr r5,[0x08023a74]
// 08023a36 ldrb.w r0,[r5],#0x1
// 08023a3a movs r1,#0x0
// 08023a3c adds r4,#0x1
// 08023a3e bl 0x0802bf7c
// 08023a42 uxtb r4,r4
// 08023a44 movs r1,#0x0
// 08023a46 ldrb r0,[r5,#0x6]
// 08023a48 bl 0x0802bf7c
// 08023a4c cmp r4,#0x7
// 08023a4e bne 0x08023a36
// 08023a50 mov r0,r7
// 08023a52 bl 0x08034d64
// 08023a56 movs r5,#0x0
// 08023a58 movs r0,#0x32
// 08023a5a bl 0x080273a4
// 08023a5e mov r6,r4
// 08023a60 b 0x08023970
// 08023a62 mov r4,r6
// 08023a64 b 0x08023a56
// 08023a66 cmp r6,#0x6
// 08023a68 beq 0x080239bc
// 08023a6a movs r4,#0x6
// 08023a6c movs r5,#0x3c
// 08023a6e b 0x08023996
// FUNCTION 08023d30

void FUN_08023d30(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  short sVar11;
  short sVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined4 *puVar17;
  byte bVar18;
  byte bVar19;
  bool bVar20;
  uint in_fpscr;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined4 local_4c [10];
  
  FUN_08034d64(DAT_08024010);
  uVar13 = 0;
  FUN_0802ca7c();
  do {
    uVar15 = uVar13 & 0xffff;
    FUN_0802c61c(uVar15,1);
    FUN_0802c41c(0,0x54,0x41,7);
    uVar13 = uVar13 + 1;
    FUN_0802c2a8(uVar15,1);
  } while (uVar13 != 0xe);
  uVar13 = 0;
  do {
    uVar15 = uVar13 & 0xffff;
    uVar13 = uVar13 + 1;
    FUN_0802c32c(uVar15);
  } while (uVar13 != 0xe);
  thunk_FUN_0802fec8(0x5dc);
  uVar13 = 0;
  do {
    uVar15 = uVar13 & 0xffff;
    uVar13 = uVar13 + 1;
    FUN_0802c3b8(uVar15);
  } while (uVar13 != 0xe);
  FUN_08034d6e(DAT_08024010);
  FUN_0802ca7c();
  iVar5 = DAT_0802402c;
  iVar4 = DAT_08024014;
  for (bVar18 = 0; uVar13 = (uint)bVar18, (int)uVar13 < *(int *)(iVar4 + 0x60); bVar18 = bVar18 + 1)
  {
    bVar19 = 0;
    *(undefined4 *)(*(int *)(iVar4 + 100) + uVar13 * 0x13c + 0x10) = 2;
    while( true ) {
      uVar15 = (uint)bVar19;
      bVar19 = bVar19 + 1;
      if (*(int *)(*(int *)(iVar4 + 100) + uVar13 * 0x13c + 0x14) <= (int)uVar15) break;
      iVar14 = uVar15 + uVar13 * 0xd;
      FUN_0802b890(*(undefined1 *)(iVar5 + iVar14 * 2),0);
      *(undefined1 *)(iVar5 + iVar14 * 2 + 1) = 0;
    }
  }
  local_4c[0] = *DAT_08024018;
  local_4c[1] = DAT_08024018[1];
  local_4c[2] = DAT_08024018[2];
  local_4c[3] = DAT_08024018[3];
  local_4c[4] = DAT_08024018[4];
  *(undefined4 *)(DAT_0802401c + 8) = 100;
  sVar11 = 0x3a;
  do {
    sVar12 = sVar11 + 1;
    FUN_0802b890(sVar11,0xff);
    sVar11 = sVar12;
  } while (sVar12 != 0x4a);
  uVar13 = 0;
  do {
    uVar15 = uVar13 & 0xffff;
    uVar13 = uVar13 + 1;
    FUN_0802b890(uVar15,0xff);
    iVar14 = DAT_0802402c;
    iVar5 = DAT_08024024;
  } while (uVar13 != 10);
  iVar16 = 0;
  uVar13 = 0;
  fVar22 = DAT_08024020;
  fVar24 = DAT_08024020;
  do {
    do {
      for (bVar18 = 0; uVar15 = (uint)bVar18, (int)uVar15 < *(int *)(iVar4 + 0x60);
          bVar18 = bVar18 + 1) {
        bVar19 = 0;
        while( true ) {
          uVar6 = (uint)bVar19;
          iVar9 = *(int *)(iVar4 + 100) + uVar15 * 0x13c;
          if (*(int *)(iVar9 + 0x14) <= (int)uVar6) break;
          iVar8 = uVar15 * 0xd + uVar6;
          if (*(int *)(iVar9 + uVar6 * 0x10 + 0x20) == 1) {
            *(undefined1 *)(iVar14 + iVar8 * 2 + 1) = 1;
LAB_0802412a:
            uVar3 = *(undefined1 *)(iVar14 + (uVar15 * 0xd + uVar6) * 2);
            uVar7 = local_4c[uVar13];
          }
          else {
            if (*(char *)(iVar14 + iVar8 * 2 + 1) == '\x01') goto LAB_0802412a;
            uVar7 = 0;
            uVar3 = *(undefined1 *)(iVar14 + iVar8 * 2);
          }
          FUN_0802b890(uVar3,uVar7);
          bVar19 = bVar19 + 1;
        }
      }
      FUN_0802b884();
      iVar16 = iVar16 + 1;
      FUN_0802b88a();
      thunk_FUN_0802fec8(5);
    } while (iVar16 != 0x15);
    if ((*(int *)(*(int *)(iVar4 + 0x34) + 0x20) == 1) &&
       (*(int *)(*(int *)(iVar4 + 0x34) + 0xb8) == 1)) {
      for (bVar18 = 0; uVar15 = (uint)bVar18, (int)uVar15 < *(int *)(iVar4 + 0x60);
          bVar18 = bVar18 + 1) {
        bVar19 = 0;
        while( true ) {
          uVar6 = (uint)bVar19;
          bVar19 = bVar19 + 1;
          if (*(int *)(*(int *)(iVar4 + 100) + uVar15 * 0x13c + 0x14) <= (int)uVar6) break;
          iVar16 = uVar6 + uVar15 * 0xd;
          FUN_0802b890(*(undefined1 *)(iVar14 + iVar16 * 2),0);
          *(undefined1 *)(iVar14 + iVar16 * 2 + 1) = 0;
        }
      }
    }
    bVar18 = 0;
    while (uVar15 = (uint)bVar18, (int)uVar15 < *(int *)(iVar4 + 0x18)) {
      bVar18 = bVar18 + 1;
      if (*(int *)(uVar15 * 0x28 + *(int *)(iVar4 + 0x1c) + 0x20) == 1) {
        uVar13 = uVar13 + 1 & 0xff;
      }
    }
    uVar15 = 0;
    bVar20 = false;
    iVar9 = *(int *)(iVar4 + 0x30);
    iVar8 = *(int *)(iVar4 + 0x34);
    iVar16 = *(int *)(DAT_0802401c + 8);
    while ((int)(uVar15 & 0xff) < iVar9) {
      puVar10 = (undefined4 *)((uVar15 & 0xff) * 0x78 + iVar8);
      puVar17 = puVar10;
      do {
        piVar1 = puVar17 + 4;
        puVar17 = puVar17 + 4;
        if (*piVar1 == 1) {
          *puVar17 = 0;
          uVar13 = uVar13 + 1 & 0xff;
        }
      } while (puVar17 != puVar10 + 0x14);
      uVar15 = uVar15 + 1;
      if (puVar10[0x18] == 1) {
        bVar20 = true;
      }
      if (puVar10[0x18] == 1) {
        iVar16 = iVar16 + -0x14;
        puVar10[0x18] = 0;
      }
      if (puVar10[0x1c] == 1) {
        iVar16 = iVar16 + 0x14;
        puVar10[0x1c] = 0;
        bVar20 = true;
      }
    }
    if (bVar20) {
      *(int *)(DAT_0802401c + 8) = iVar16;
    }
    iVar16 = *(int *)(iVar4 + 0x58);
    iVar9 = *(int *)(iVar4 + 0x5c);
    for (uVar15 = 0; (int)(uVar15 & 0xff) < iVar16; uVar15 = uVar15 + 1) {
      iVar8 = (uVar15 & 0xff) * 0x28 + iVar9;
      if ((*(int *)(iVar8 + 0x10) == 1) || (*(int *)(iVar8 + 0x20) == 1)) {
        uVar13 = uVar13 + 1 & 0xff;
        *(undefined4 *)(iVar8 + 0x10) = 0;
        *(undefined4 *)(iVar8 + 0x20) = 0;
      }
    }
    bVar18 = *(byte *)(iVar5 + 5);
    if (bVar18 != 0) {
      if (bVar18 == 3) {
        bVar20 = *(char *)(iVar5 + 0x2b) == '\x01';
        if (bVar20) {
          uVar13 = uVar13 + 1;
        }
        cVar2 = *(char *)(iVar5 + 0x2c);
        if (bVar20) {
          uVar13 = uVar13 & 0xff;
        }
LAB_080240a4:
        bVar20 = cVar2 == '\x01';
LAB_080240a6:
        if (!bVar20) goto LAB_08023f24;
      }
      else {
        if (bVar18 < 4) {
          cVar2 = *(char *)(iVar5 + 0x2b);
          goto LAB_080240a4;
        }
        if (bVar18 != 4) goto LAB_08023f24;
        if (*(char *)(iVar5 + 0x2b) != '\x01') {
          bVar20 = *(char *)(iVar5 + 0x2b) == '\x02';
          goto LAB_080240a6;
        }
      }
      uVar13 = uVar13 + 1 & 0xff;
    }
LAB_08023f24:
    bVar18 = *(byte *)(iVar5 + 6);
    if (bVar18 != 0) {
      if (bVar18 == 3) {
        bVar20 = *(char *)(iVar5 + 0x2d) == '\x01';
        if (bVar20) {
          uVar13 = uVar13 + 1;
        }
        cVar2 = *(char *)(iVar5 + 0x2e);
        if (bVar20) {
          uVar13 = uVar13 & 0xff;
        }
LAB_080240dc:
        bVar20 = cVar2 == '\x01';
LAB_080240de:
        if (!bVar20) goto LAB_08023f36;
      }
      else {
        if (bVar18 < 4) {
          cVar2 = *(char *)(iVar5 + 0x2d);
          goto LAB_080240dc;
        }
        if (bVar18 != 4) goto LAB_08023f36;
        if (*(char *)(iVar5 + 0x2d) != '\x01') {
          bVar20 = *(char *)(iVar5 + 0x2d) == '\x02';
          goto LAB_080240de;
        }
      }
      uVar13 = uVar13 + 1 & 0xff;
    }
LAB_08023f36:
    iVar16 = FUN_0802cee4();
    if (iVar16 != 0) {
      uVar7 = FUN_08029b9c(0);
      fVar23 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      fVar21 = fVar23 - fVar24;
      uVar15 = in_fpscr & 0xfffffff;
      uVar6 = uVar15 | (uint)(fVar21 < DAT_08024028) << 0x1f |
              (uint)(fVar21 == DAT_08024028) << 0x1e;
      in_fpscr = uVar6 | (uint)(NAN(fVar21) || NAN(DAT_08024028)) << 0x1c;
      bVar18 = (byte)(uVar6 >> 0x18);
      if ((bool)(bVar18 >> 6 & 1) || bVar18 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar24 = fVar24 - fVar23;
        uVar15 = uVar15 | (uint)(fVar24 < DAT_08024028) << 0x1f |
                 (uint)(fVar24 == DAT_08024028) << 0x1e;
        in_fpscr = uVar15 | (uint)(NAN(fVar24) || NAN(DAT_08024028)) << 0x1c;
        bVar18 = (byte)(uVar15 >> 0x18);
        fVar24 = fVar23;
        if ((bool)(bVar18 >> 6 & 1) || bVar18 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1))
        goto LAB_08023f72;
      }
      uVar13 = uVar13 + 1 & 0xff;
      fVar24 = fVar23;
    }
LAB_08023f72:
    iVar16 = FUN_0802cee4(*(undefined1 *)(iVar5 + 6));
    if (iVar16 != 0) {
      uVar7 = FUN_08029b9c(4);
      fVar23 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      fVar21 = fVar23 - fVar22;
      uVar15 = in_fpscr & 0xfffffff;
      uVar6 = uVar15 | (uint)(fVar21 < DAT_08024028) << 0x1f |
              (uint)(fVar21 == DAT_08024028) << 0x1e;
      in_fpscr = uVar6 | (uint)(NAN(fVar21) || NAN(DAT_08024028)) << 0x1c;
      bVar18 = (byte)(uVar6 >> 0x18);
      if ((bool)(bVar18 >> 6 & 1) || bVar18 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar22 = fVar22 - fVar23;
        uVar15 = uVar15 | (uint)(fVar22 < DAT_08024028) << 0x1f |
                 (uint)(fVar22 == DAT_08024028) << 0x1e;
        in_fpscr = uVar15 | (uint)(NAN(fVar22) || NAN(DAT_08024028)) << 0x1c;
        bVar18 = (byte)(uVar15 >> 0x18);
        fVar22 = fVar23;
        if ((bool)(bVar18 >> 6 & 1) || bVar18 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1))
        goto LAB_08023fb0;
      }
      uVar13 = uVar13 + 1 & 0xff;
      fVar22 = fVar23;
    }
LAB_08023fb0:
    if (4 < uVar13) {
      uVar13 = 0;
    }
    if (*(uint *)(DAT_0802401c + 8) < 0x65) {
      if (*(uint *)(DAT_0802401c + 8) == 0) {
        uVar7 = 100;
        iVar16 = DAT_0802418c;
        goto LAB_08023fc2;
      }
    }
    else {
      uVar7 = 0x14;
      iVar16 = DAT_0802401c;
LAB_08023fc2:
      *(undefined4 *)(iVar16 + 8) = uVar7;
    }
    sVar11 = 0x3a;
    do {
      uVar7 = local_4c[uVar13];
      sVar12 = sVar11 + 1;
      FUN_0802b890(sVar11,uVar7);
      sVar11 = sVar12;
    } while (sVar12 != 0x4a);
    uVar15 = 0;
    do {
      uVar6 = uVar15 & 0xffff;
      uVar15 = uVar15 + 1;
      FUN_0802b890(uVar6,uVar7);
    } while (uVar15 != 10);
    iVar16 = 0;
  } while( true );
}


// 08023d30 push {r4,r5,r6,r7,r8,r9,r10,r11,lr}
// 08023d34 vpush {d8,d9}
// 08023d38 ldr r0,[0x08024010]
// 08023d3a sub sp,#0x24
// 08023d3c bl 0x08034d64
// 08023d40 movs r4,#0x0
// 08023d42 bl 0x0802ca7c
// 08023d46 uxth r5,r4
// 08023d48 movs r1,#0x1
// 08023d4a mov r0,r5
// 08023d4c bl 0x0802c61c
// 08023d50 movs r3,#0x7
// 08023d52 movs r2,#0x41
// 08023d54 movs r1,#0x54
// 08023d56 movs r0,#0x0
// 08023d58 bl 0x0802c41c
// 08023d5c adds r4,#0x1
// 08023d5e movs r1,#0x1
// 08023d60 mov r0,r5
// 08023d62 bl 0x0802c2a8
// 08023d66 cmp r4,#0xe
// 08023d68 bne 0x08023d46
// 08023d6a movs r4,#0x0
// 08023d6c uxth r0,r4
// 08023d6e adds r4,#0x1
// 08023d70 bl 0x0802c32c
// 08023d74 cmp r4,#0xe
// 08023d76 bne 0x08023d6c
// 08023d78 movw r0,#0x5dc
// 08023d7c bl 0x080273a4
// 08023d80 movs r4,#0x0
// 08023d82 uxth r0,r4
// 08023d84 adds r4,#0x1
// 08023d86 bl 0x0802c3b8
// 08023d8a cmp r4,#0xe
// 08023d8c bne 0x08023d82
// 08023d8e ldr r0,[0x08024010]
// 08023d90 bl 0x08034d6e
// 08023d94 mov.w r8,#0x0
// 08023d98 bl 0x0802ca7c
// 08023d9c ldr r5,[0x08024014]
// 08023d9e ldr.w r10,[0x0802402c]
// 08023da2 ldr r2,[r5,#0x60]
// 08023da4 uxtb.w r3,r8
// 08023da8 cmp r3,r2
// 08023daa blt 0x08023e1a
// 08023dac ldr r6,[0x08024018]
// 08023dae add r4,sp,#0xc
// 08023db0 ldmia r6!,{r0,r1,r2,r3}
// 08023db2 stmia r4!,{r0,r1,r2,r3}
// 08023db4 ldr r3,[r6,#0x0]
// 08023db6 ldr r2,[0x0802401c]
// 08023db8 str r3,[r4,#0x0]
// 08023dba movs r3,#0x64
// 08023dbc movs r4,#0x3a
// 08023dbe str r3,[r2,#0x8]
// 08023dc0 mov r0,r4
// 08023dc2 adds r4,#0x1
// 08023dc4 movs r1,#0xff
// 08023dc6 uxth r4,r4
// 08023dc8 bl 0x0802b890
// 08023dcc cmp r4,#0x4a
// 08023dce bne 0x08023dc0
// 08023dd0 movs r4,#0x0
// 08023dd2 uxth r0,r4
// 08023dd4 movs r1,#0xff
// 08023dd6 adds r4,#0x1
// 08023dd8 bl 0x0802b890
// 08023ddc cmp r4,#0xa
// 08023dde bne 0x08023dd2
// 08023de0 movs r7,#0x0
// 08023de2 vldr.32 s16,[pc,#0x23c]
// 08023de6 mov r4,r7
// 08023de8 vmov.f32 s18,s16
// 08023dec ldr.w r8,[0x0802402c]
// 08023df0 ldr r6,[0x08024024]
// 08023df2 mov.w r10,#0x0
// 08023df6 ldr r2,[r5,#0x60]
// 08023df8 uxtb.w r9,r10
// 08023dfc cmp r9,r2
// 08023dfe bge.w 0x0802416a
// 08023e02 mov.w r3,#0x13c
// 08023e06 mul r3,r3,r9
// 08023e0a str r3,[sp,#0x0]
// 08023e0c add r3,sp,#0x20
// 08023e0e add.w r3,r3,r4, lsl #0x2
// 08023e12 mov.w r11,#0x0
// 08023e16 str r3,[sp,#0x4]
// 08023e18 b 0x08024142
// 08023e1a mov.w r7,#0x13c
// 08023e1e movs r6,#0xd
// 08023e20 movs r1,#0x2
// 08023e22 mov.w r9,#0x0
// 08023e26 muls r7,r3
// 08023e28 ldr r2,[r5,#0x64]
// 08023e2a muls r6,r3
// 08023e2c add r2,r7
// 08023e2e str r1,[r2,#0x10]
// 08023e30 ldr r3,[r5,#0x64]
// 08023e32 uxtb.w r4,r9
// 08023e36 add r3,r7
// 08023e38 ldr r3,[r3,#0x14]
// 08023e3a add.w r9,r9,#0x1
// 08023e3e cmp r4,r3
// 08023e40 blt 0x08023e48
// 08023e42 add.w r8,r8,#0x1
// 08023e46 b 0x08023da2
// 08023e48 add r4,r6
// 08023e4a ldrb.w r0,[r10,r4,lsl #0x1]
// 08023e4e movs r1,#0x0
// 08023e50 bl 0x0802b890
// 08023e54 movs r3,#0x0
// 08023e56 add.w r4,r10,r4, lsl #0x1
// 08023e5a strb r3,[r4,#0x1]
// 08023e5c b 0x08023e30
// 08023e5e ldr r3,[r5,#0x34]
// 08023e60 ldr r2,[r3,#0x20]
// 08023e62 cmp r2,#0x1
// 08023e64 bne 0x08023ec4
// 08023e66 ldr.w r3,[r3,#0xb8]
// 08023e6a cmp r3,#0x1
// 08023e6c bne 0x08023ec4
// 08023e6e mov.w r11,#0x0
// 08023e72 mov.w r2,#0x13c
// 08023e76 b 0x08023eaa
// 08023e78 add r7,r9
// 08023e7a movs r1,#0x0
// 08023e7c ldrb.w r0,[r8,r7,lsl #0x1]
// 08023e80 str r3,[sp,#0x0]
// 08023e82 bl 0x0802b890
// 08023e86 movs r1,#0x0
// 08023e88 mov.w r2,#0x13c
// 08023e8c add.w r7,r8,r7, lsl #0x1
// 08023e90 ldr r3,[sp,#0x0]
// 08023e92 strb r1,[r7,#0x1]
// 08023e94 ldr r1,[r5,#0x64]
// 08023e96 uxtb.w r7,r10
// 08023e9a add r1,r3
// 08023e9c ldr r1,[r1,#0x14]
// 08023e9e add.w r10,r10,#0x1
// 08023ea2 cmp r7,r1
// 08023ea4 blt 0x08023e78
// 08023ea6 add.w r11,r11,#0x1
// 08023eaa ldr r3,[r5,#0x60]
// 08023eac uxtb.w r9,r11
// 08023eb0 cmp r9,r3
// 08023eb2 bge 0x08023ec4
// 08023eb4 movs r1,#0xd
// 08023eb6 mul r3,r2,r9
// 08023eba mov.w r10,#0x0
// 08023ebe mul r9,r1,r9
// 08023ec2 b 0x08023e94
// 08023ec4 movs r2,#0x0
// 08023ec6 ldrd r1,r0,[r5,#0x18]
// 08023eca movs r7,#0x28
// 08023ecc uxtb r3,r2
// 08023ece cmp r3,r1
// 08023ed0 blt.w 0x08023ffc
// 08023ed4 movs r0,#0x0
// 08023ed6 mov.w r9,#0x78
// 08023eda mov r12,r0
// 08023edc mov lr,r0
// 08023ede ldr r3,[r5,#0x30]
// 08023ee0 ldr.w r11,[r5,#0x34]
// 08023ee4 str r3,[sp,#0x0]
// 08023ee6 ldr r3,[0x0802401c]
// 08023ee8 ldr r2,[r3,#0x8]
// 08023eea ldr r1,[sp,#0x0]
// 08023eec uxtb r3,r0
// 08023eee cmp r3,r1
// 08023ef0 blt.w 0x08024030
// 08023ef4 cmp.w r12,#0x0
// 08023ef8 beq 0x08023efe
// 08023efa ldr r3,[0x0802401c]
// 08023efc str r2,[r3,#0x8]
// 08023efe movs r2,#0x0
// 08023f00 ldrd r7,r12,[r5,#0x58]
// 08023f04 mov.w lr,#0x28
// 08023f08 mov r0,r2
// 08023f0a uxtb r3,r2
// 08023f0c cmp r3,r7
// 08023f0e blt.w 0x08024070
// 08023f12 ldrb r0,[r6,#0x5]
// 08023f14 cbz r0,0x08023f24
// 08023f16 cmp r0,#0x3
// 08023f18 beq.w 0x080240ac
// 08023f1c bhi.w 0x0802408c
// 08023f20 bne.w 0x080240a0
// 08023f24 ldrb r3,[r6,#0x6]
// 08023f26 cbz r3,0x08023f36
// 08023f28 cmp r3,#0x3
// 08023f2a beq.w 0x080240e4
// 08023f2e bhi.w 0x080240c4
// 08023f32 bne.w 0x080240d8
// 08023f36 bl 0x0802cee4
// 08023f3a cmp r0,#0x0
// 08023f3c beq.w 0x080240fc
// 08023f40 movs r0,#0x0
// 08023f42 bl 0x08029b9c
// 08023f46 vmov s15,r0
// 08023f4a vcvt.f32.u32 s17,s15
// 08023f4e vldr.32 s15,[pc,#0xd8]
// 08023f52 vsub.f32 s14,s17,s18
// 08023f56 vcmpe.f32 s14,s15
// 08023f5a vmrs apsr,fpscr
// 08023f5e bgt 0x08023f6e
// 08023f60 vsub.f32 s18,s18,s17
// 08023f64 vcmpe.f32 s18,s15
// 08023f68 vmrs apsr,fpscr
// 08023f6c ble 0x08023f72
// 08023f6e adds r4,#0x1
// 08023f70 uxtb r4,r4
// 08023f72 ldrb r0,[r6,#0x6]
// 08023f74 bl 0x0802cee4
// 08023f78 cmp r0,#0x0
// 08023f7a beq.w 0x08024102
// 08023f7e movs r0,#0x4
// 08023f80 bl 0x08029b9c
// 08023f84 vmov s15,r0
// 08023f88 vcvt.f32.u32 s19,s15
// 08023f8c vldr.32 s15,[pc,#0x98]
// 08023f90 vsub.f32 s14,s19,s16
// 08023f94 vcmpe.f32 s14,s15
// 08023f98 vmrs apsr,fpscr
// 08023f9c bgt 0x08023fac
// 08023f9e vsub.f32 s16,s16,s19
// 08023fa2 vcmpe.f32 s16,s15
// 08023fa6 vmrs apsr,fpscr
// 08023faa ble 0x08023fb0
// 08023fac adds r4,#0x1
// 08023fae uxtb r4,r4
// 08023fb0 ldr r2,[0x0802401c]
// 08023fb2 cmp r4,#0x5
// 08023fb4 ldr r3,[r2,#0x8]
// 08023fb6 it cs
// 08023fb8 mov.cs r4,#0x0
// 08023fba cmp r3,#0x64
// 08023fbc bls.w 0x08024108
// 08023fc0 movs r3,#0x14
// 08023fc2 str r3,[r2,#0x8]
// 08023fc4 movs r7,#0x3a
// 08023fc6 add r3,sp,#0x20
// 08023fc8 add.w r10,r3,r4, lsl #0x2
// 08023fcc ldr.w r9,[r10,#-0x14]
// 08023fd0 mov r0,r7
// 08023fd2 adds r7,#0x1
// 08023fd4 mov r1,r9
// 08023fd6 uxth r7,r7
// 08023fd8 bl 0x0802b890
// 08023fdc cmp r7,#0x4a
// 08023fde bne 0x08023fcc
// 08023fe0 movs r7,#0x0
// 08023fe2 uxth r0,r7
// 08023fe4 mov r1,r9
// 08023fe6 adds r7,#0x1
// 08023fe8 bl 0x0802b890
// 08023fec cmp r7,#0xa
// 08023fee bne 0x08023fe2
// 08023ff0 movs r7,#0x0
// 08023ff2 vmov.f32 s16,s19
// 08023ff6 vmov.f32 s18,s17
// 08023ffa b 0x08023df2
// 08023ffc mla r3,r7,r3,r0
// 08024000 ldr r3,[r3,#0x20]
// 08024002 adds r2,#0x1
// 08024004 cmp r3,#0x1
// 08024006 itt eq
// 08024008 add.eq r4,#0x1
// 0802400a uxtb.eq r4,r4
// 0802400c b 0x08023ecc
// 08024030 mla r3,r9,r3,r11
// 08024034 mov r7,r3
// 08024036 add.w r10,r3,#0x50
// 0802403a ldr r1,[r7,#0x10]
// 0802403c adds r7,#0x10
// 0802403e cmp r1,#0x1
// 08024040 ittt eq
// 08024042 add.eq r4,#0x1
// 08024044 str.w.eq lr,[r7,#0x0]
// 08024048 uxtb.eq r4,r4
// 0802404a cmp r7,r10
// 0802404c bne 0x0802403a
// 0802404e ldr r1,[r3,#0x60]
// 08024050 adds r0,#0x1
// 08024052 cmp r1,#0x1
// 08024054 it eq
// 08024056 mov.eq r12,r1
// 08024058 ldr r1,[r3,#0x70]
// 0802405a itt eq
// 0802405c sub.eq r2,#0x14
// 0802405e str.w.eq lr,[r3,#0x60]
// 08024062 cmp r1,#0x1
// 08024064 ittt eq
// 08024066 mov.eq r12,r1
// 08024068 add.eq r2,#0x14
// 0802406a str.w.eq lr,[r3,#0x70]
// 0802406e b 0x08023eea
// 08024070 mla r3,lr,r3,r12
// 08024074 ldr r1,[r3,#0x10]
// 08024076 cmp r1,#0x1
// 08024078 beq 0x08024080
// 0802407a ldr r1,[r3,#0x20]
// 0802407c cmp r1,#0x1
// 0802407e bne 0x08024088
// 08024080 adds r4,#0x1
// 08024082 uxtb r4,r4
// 08024084 str r0,[r3,#0x10]
// 08024086 str r0,[r3,#0x20]
// 08024088 adds r2,#0x1
// 0802408a b 0x08023f0a
// 0802408c cmp r0,#0x4
// 0802408e bne.w 0x08023f24
// 08024092 ldrb.w r3,[r6,#0x2b]
// 08024096 cmp r3,#0x1
// 08024098 bne 0x080240c0
// 0802409a adds r4,#0x1
// 0802409c uxtb r4,r4
// 0802409e b 0x08023f24
// 080240a0 ldrb.w r3,[r6,#0x2b]
// 080240a4 cmp r3,#0x1
// 080240a6 bne.w 0x08023f24
// 080240aa b 0x0802409a
// 080240ac ldrb.w r3,[r6,#0x2b]
// 080240b0 cmp r3,#0x1
// 080240b2 it eq
// 080240b4 add.eq r4,#0x1
// 080240b6 ldrb.w r3,[r6,#0x2c]
// 080240ba it eq
// 080240bc uxtb.eq r4,r4
// 080240be b 0x080240a4
// 080240c0 cmp r3,#0x2
// 080240c2 b 0x080240a6
// 080240c4 cmp r3,#0x4
// 080240c6 bne.w 0x08023f36
// 080240ca ldrb.w r3,[r6,#0x2d]
// 080240ce cmp r3,#0x1
// 080240d0 bne 0x080240f8
// 080240d2 adds r4,#0x1
// 080240d4 uxtb r4,r4
// 080240d6 b 0x08023f36
// 080240d8 ldrb.w r3,[r6,#0x2d]
// 080240dc cmp r3,#0x1
// 080240de bne.w 0x08023f36
// 080240e2 b 0x080240d2
// 080240e4 ldrb.w r3,[r6,#0x2d]
// 080240e8 cmp r3,#0x1
// 080240ea it eq
// 080240ec add.eq r4,#0x1
// 080240ee ldrb.w r3,[r6,#0x2e]
// 080240f2 it eq
// 080240f4 uxtb.eq r4,r4
// 080240f6 b 0x080240dc
// 080240f8 cmp r3,#0x2
// 080240fa b 0x080240de
// 080240fc vmov.f32 s17,s18
// 08024100 b 0x08023f72
// 08024102 vmov.f32 s19,s16
// 08024106 b 0x08023fb0
// 08024108 cmp r3,#0x0
// 0802410a bne.w 0x08023fc4
// 0802410e movs r3,#0x64
// 08024110 ldr r2,[0x0802418c]
// 08024112 b 0x08023fc2
// 08024114 add.w r2,r2,r0, lsl #0x4
// 08024118 ldr r1,[r2,#0x20]
// 0802411a movs r2,#0xd
// 0802411c cmp r1,#0x1
// 0802411e mla r2,r2,r9,r0
// 08024122 bne 0x08024158
// 08024124 add.w r2,r8,r2, lsl #0x1
// 08024128 strb r1,[r2,#0x1]
// 0802412a movs r2,#0xd
// 0802412c mla r0,r2,r9,r0
// 08024130 ldr r3,[sp,#0x4]
// 08024132 ldrb.w r0,[r8,r0,lsl #0x1]
// 08024136 ldr.w r1,[r3,#-0x14]
// 0802413a bl 0x0802b890
// 0802413e add.w r11,r11,#0x1
// 08024142 ldr r2,[r5,#0x64]
// 08024144 ldr r3,[sp,#0x0]
// 08024146 uxtb.w r0,r11
// 0802414a add r2,r3
// 0802414c ldr r1,[r2,#0x14]
// 0802414e cmp r0,r1
// 08024150 blt 0x08024114
// 08024152 add.w r10,r10,#0x1
// 08024156 b 0x08023df6
// 08024158 add.w r1,r8,r2, lsl #0x1
// 0802415c ldrb r1,[r1,#0x1]
// 0802415e cmp r1,#0x1
// 08024160 beq 0x0802412a
// 08024162 movs r1,#0x0
// 08024164 ldrb.w r0,[r8,r2,lsl #0x1]
// 08024168 b 0x0802413a
// 0802416a bl 0x0802b884
// 0802416e adds r7,#0x1
// 08024170 bl 0x0802b88a
// 08024174 movs r0,#0x5
// 08024176 bl 0x080273a4
// 0802417a cmp r7,#0x15
// 0802417c beq.w 0x08023e5e
// 08024180 vmov.f32 s19,s16
// 08024184 vmov.f32 s17,s18
// 08024188 b 0x08023ff2
// FUNCTION 0802b814

uint FUN_0802b814(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x36) {
    uVar1 = (uint)(*(byte *)(param_1 * 0x24 + DAT_0802b82c + 0xf) >> 7);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// 0802b814 cmp r0,#0x35
// 0802b816 itttt ls
// 0802b818 mov.ls r2,#0x24
// 0802b81a ldr.ls r3,[0x0802b82c]
// 0802b81c mla.ls r0,r2,r0,r3
// 0802b820 ldrb.ls r0,[r0,#0xf]
// 0802b822 ite ls
// 0802b824 lsr.ls r0,r0,#0x7
// 0802b826 mov.hi.w r0,#0xffffffff
// 0802b82a bx lr
