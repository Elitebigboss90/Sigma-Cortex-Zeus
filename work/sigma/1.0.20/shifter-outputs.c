
// FUNCTION FUN_08025b98 @ 08025b98
// XREF 08025b22

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08025b98(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 == ' ') {
    FUN_08020496(param_1 + 0xe1,param_2,0x20);
    if (*(char *)(param_1 + 0xf6) == '\a') {
      *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_1 + 0xf7);
    }
    DAT_20004a90 = *(undefined2 *)(param_1 + 0xe2);
    uVar2 = *(uint *)(param_1 + 0xed) >> 4;
    DAT_20004a84 = (*(uint *)(param_1 + 0xf1) & 0xfff) >> 4;
    DAT_20004a80 = uVar2 | *(uint *)(param_1 + 0xf1) << 0x1c;
    if ((((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) &&
        ((*(ushort *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)(((uVar2 & 0xff0000) >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    if ((*(ushort *)(param_1 + 0x158) & 0xff) >> 6 != (uint)DAT_200000bc) {
      DAT_200000bc = (ushort)(((uint)*(ushort *)(param_1 + 0x158) << 0x18) >> 0x1e);
      if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) == 0) {
        FUN_0804a81c(2);
      }
      else {
        FUN_0804a73c(2);
      }
    }
    if ((*(ushort *)(param_1 + 0x158) >> 0xc & 3) == 0) {
      iVar1 = FUN_0802aa8c(&DAT_20002774);
      if (iVar1 == 0) {
        DAT_20004a98 = 0;
      }
      else {
        DAT_20004a98 = FUN_0802aa00(&DAT_20002774);
      }
    }
    else {
      DAT_20004a98 = (ushort)((uint3)*(undefined3 *)(param_1 + 0xfe) >> 0xc);
    }
    if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) {
      switch(*(ushort *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08027730(param_1);
        }
        else {
          FUN_08027a4c(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004a94 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
            DAT_20004a92 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
            DAT_20004a96 = -1;
          }
        }
        break;
      case 2:
        FUN_08026c24(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
        break;
      case 3:
        FUN_0802863c(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
        break;
      case 4:
        FUN_08027fe4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
        break;
      case 5:
        FUN_080271bc(param_1);
        break;
      case 6:
        FUN_08026580(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = -1 - (*(ushort *)(param_1 + 0xeb) & 0xfff0);
          DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe9) >> 4) & 0xfff0);
          DAT_20004a96 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004a92 = -1 - ((ushort)(*(uint *)(param_1 + 0xe5) >> 0xc) & 0xfff0);
      DAT_20004a94 = -1 - ((ushort)*(undefined4 *)(param_1 + 0xe5) & 0xfff0);
      DAT_20004a96 = -1 - (short)(*(int *)(param_1 + 0xe4) << 4);
    }
    if (DAT_20003d30 == '\x01') {
      DAT_20004a92 = _DAT_20003cf5 * -0x10 + -1;
      DAT_20004a94 = _DAT_20003cf3 * -0x10 + -1;
      DAT_20004a96 = _DAT_20003cf1 * -0x10 + -1;
    }
    if (*(ushort *)(param_1 + 0x158) >> 0xe == 0) {
      iVar1 = FUN_0802a348(&DAT_20002830);
      if (iVar1 == 0) {
        DAT_20004a9c = 0;
        DAT_20004a9a = 0;
        DAT_20004a9b = 0;
      }
      else {
        DAT_20004a9c = FUN_0802a27c();
        iVar1 = FUN_0802a2e0(&DAT_20002830);
        if (iVar1 == 0) {
          DAT_20004a9a = FUN_0802a16c();
          DAT_20004a9b = FUN_0802a208(&DAT_20002830);
        }
      }
    }
    else {
      DAT_20004a9c = FUN_08025654((*(uint *)(param_1 + 0xf1) & 0x1fffffff) >> 0x14);
    }
    DAT_20004a8c = DAT_20004a84;
    DAT_20004a88 = DAT_20004a80;
  }
  return;
}



// FUNCTION FUN_08026028 @ 08026028
// XREF 08025b14

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08026028(int param_1,int param_2,char param_3)

{
  int iVar1;
  
  if (param_3 == '\'') {
    DAT_20004a90 = *(undefined2 *)(param_2 + 1);
    DAT_20004a80 = (uint)(*(byte *)(param_2 + 0xc) >> 4) | (uint)*(byte *)(param_2 + 0xd) << 4 |
                   (uint)*(byte *)(param_2 + 0xe) << 0xc | (uint)*(byte *)(param_2 + 0xf) << 0x14 |
                   (uint)*(byte *)(param_2 + 0x10) << 0x1c;
    DAT_20004a84 = (uint)(*(byte *)(param_2 + 0x10) >> 4) | (uint)*(byte *)(param_2 + 0x11) << 4 |
                   (uint)*(byte *)(param_2 + 0x12) << 0xc | (uint)*(byte *)(param_2 + 0x13) << 0x14
                   | (uint)*(byte *)(param_2 + 0x14) << 0x1c;
    *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_2 + 0x1c);
    if ((((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) &&
        ((*(ushort *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)((DAT_20004a80 >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    DAT_20000d80 = (ushort)*(byte *)(param_2 + 9) | (*(byte *)(param_2 + 10) & 0xf) << 8;
    DAT_20000d7e = (ushort)(*(byte *)(param_2 + 10) >> 4) | (ushort)*(byte *)(param_2 + 0xb) << 4;
    if ((*(ushort *)(param_1 + 0x158) & 0xff) >> 6 != (uint)DAT_200000be) {
      DAT_200000be = (ushort)(((uint)*(ushort *)(param_1 + 0x158) << 0x18) >> 0x1e);
      if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) == 0) {
        FUN_0804a81c(2);
      }
      else {
        FUN_0804a73c(2);
      }
    }
    if ((*(ushort *)(param_1 + 0x158) >> 0xc & 3) == 0) {
      iVar1 = FUN_0802aa8c(&DAT_20002774);
      if (iVar1 == 0) {
        DAT_20004a98 = 0;
      }
      else {
        DAT_20004a98 = FUN_0802aa00(&DAT_20002774);
      }
    }
    else {
      DAT_20004a98 = (ushort)(*(byte *)(param_2 + 7) >> 4) | (ushort)*(byte *)(param_2 + 8) << 4;
    }
    if ((*(ushort *)(param_1 + 0x158) >> 6 & 3) != 0) {
      switch(*(ushort *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08027730(param_1);
        }
        else {
          FUN_08027a4c(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
            DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
            DAT_20004a96 = -1;
          }
        }
        break;
      case 2:
        FUN_08026c24(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
        break;
      case 3:
        FUN_0802863c(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
        break;
      case 4:
        FUN_08027fe4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
        break;
      case 5:
        FUN_080271bc(param_1);
        break;
      case 6:
        FUN_08026580(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004a94 = DAT_20000d7e * -0x10 + -1;
          DAT_20004a92 = DAT_20000d80 * -0x10 + -1;
          DAT_20004a96 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004a92 = *(short *)(param_2 + 3) * -0x10 + -1;
      DAT_20004a94 = ((ushort)(*(byte *)(param_2 + 4) >> 4) | (ushort)*(byte *)(param_2 + 5) << 4) *
                     -0x10 + -1;
      DAT_20004a96 = *(short *)(param_2 + 6) * -0x10 + -1;
    }
    if (DAT_20003d30 == '\x01') {
      DAT_20004a92 = _DAT_20003cf5 * -0x10 + -1;
      DAT_20004a94 = _DAT_20003cf3 * -0x10 + -1;
      DAT_20004a96 = _DAT_20003cf1 * -0x10 + -1;
    }
    if (*(ushort *)(param_1 + 0x158) >> 0xe == 0) {
      iVar1 = FUN_0802a348(&DAT_20002830);
      if (iVar1 == 0) {
        DAT_20004a9c = 0;
        DAT_20004a9a = 0;
        DAT_20004a9b = 0;
      }
      else {
        DAT_20004a9c = FUN_0802a27c();
        iVar1 = FUN_0802a2e0(&DAT_20002830);
        if (iVar1 == 0) {
          DAT_20004a9a = FUN_0802a16c();
          DAT_20004a9b = FUN_0802a208(&DAT_20002830);
        }
      }
    }
    else {
      if ((int)((uint)*(byte *)(param_2 + 0x1b) * 0x1000000) < 0) {
        DAT_20004a9c = 0;
      }
      else if ((int)((uint)*(byte *)(param_2 + 0x13) * 0x8000000) < 0) {
        DAT_20004a9c = 0x80;
      }
      else {
        DAT_20004a9c = FUN_08025654(*(byte *)(param_2 + 0x12) >> 4 | *(char *)(param_2 + 0x13) << 4)
        ;
      }
      DAT_20004a9b = 0;
      DAT_20004a9a = 0;
    }
    DAT_20004a8c = DAT_20004a84;
    DAT_20004a88 = DAT_20004a80;
  }
  return;
}



// FUNCTION FUN_08026580 @ 08026580
// XREF 0802635a
// XREF 08025e82

void FUN_08026580(void)

{
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._2_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  else {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  else {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  return;
}



// FUNCTION FUN_08026c24 @ 08026c24
// XREF 08026212
// XREF 08025d42

void FUN_08026c24(void)

{
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._3_1_ * 0x4000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x4000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x2000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x1000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) &&
     ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_080271bc @ 080271bc
// XREF 08025e7a
// XREF 08026352

void FUN_080271bc(void)

{
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._2_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  DAT_20004a9d = (int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0;
  DAT_20004a9e = (int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0;
  return;
}



// FUNCTION FUN_08027730 @ 08027730
// XREF 08025e70
// XREF 08026348

void FUN_08027730(void)

{
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._1_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_08027a4c @ 08027a4c
// XREF 08025e28
// XREF 080262fe

void FUN_08027a4c(void)

{
  if ((int)((uint)DAT_20004a80._3_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._3_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  if ((DAT_20004a80._2_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  DAT_20004a7b = (int)((uint)DAT_20004a80._2_1_ * 0x40000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) && (((byte)DAT_20004a80 & 1) != 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_08027fe4 @ 08027fe4
// XREF 080262a6
// XREF 08025dd2

void FUN_08027fe4(void)

{
  if ((int)((uint)DAT_20004a80._2_1_ * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._2_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._2_1_ * 0x2000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x20000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x10000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((DAT_20004a80._1_1_ & 1) == 0) {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  else {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  DAT_20004a7b = (int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_0802863c @ 0802863c
// XREF 0802625c
// XREF 08025d8a

void FUN_0802863c(void)

{
  if ((int)((uint)DAT_20004a80._3_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0;
  }
  else if ((int)((uint)DAT_20004a80._3_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 4;
  }
  else if ((DAT_20004a80._3_1_ & 1) == 0) {
    if ((int)((uint)DAT_20004a80._3_1_ * 0x4000000) < 0) {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 2;
    }
    else {
      DAT_20004a78 = DAT_20004a78 & 0xf0 | 8;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xf0 | 6;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x8000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 4;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x4000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 2;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x2000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 0x10;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a84 * 0x1000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 8;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xf7;
  }
  if ((int)((uint)DAT_20004a80._3_1_ * 0x40000000) < 0) {
    DAT_20004a7a = DAT_20004a7a | 1;
  }
  else {
    DAT_20004a7a = DAT_20004a7a & 0xfe;
  }
  DAT_20004a7b = (int)((uint)(byte)DAT_20004a80 * 0x8000000) < 0;
  if ((int)((uint)DAT_20004a80._1_1_ * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 1;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfe;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 4;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfb;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x1000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x40;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xbf;
  }
  if ((int)((uint)DAT_20004a80._1_1_ * 0x8000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 2;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xfd;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 8;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xf7;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x80;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0x7f;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x80;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0x7f;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x10000000) < 0) {
    DAT_20004a78 = DAT_20004a78 | 0x10;
  }
  else {
    DAT_20004a78 = DAT_20004a78 & 0xef;
  }
  if (DAT_20004a98 < 0x47f) {
    DAT_20004a78 = DAT_20004a78 & 0xbf;
    if ((int)((uint)(byte)DAT_20004a80 * 0x40000000) < 0) {
      DAT_20004a78 = DAT_20004a78 | 0x40;
    }
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x40;
  }
  if (((byte)DAT_20004a80 & 1) == 0) {
    DAT_20004a78 = DAT_20004a78 & 0xdf;
  }
  else {
    DAT_20004a78 = DAT_20004a78 | 0x20;
  }
  if ((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x10;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xef;
  }
  if ((int)((uint)(byte)DAT_20004a80 * 0x4000000) < 0) {
    DAT_20004a79 = DAT_20004a79 | 0x20;
  }
  else {
    DAT_20004a79 = DAT_20004a79 & 0xdf;
  }
  if (((int)((uint)(byte)DAT_20004a80 * 0x10000000) < 0) &&
     ((int)((uint)(byte)DAT_20004a80 * 0x2000000) < 0)) {
    DAT_20004a9d = 1;
  }
  else {
    DAT_20004a9d = 0;
  }
  if (((int)((uint)DAT_20004a80._2_1_ * 0x20000000) < 0) &&
     ((int)((uint)DAT_20004a80._2_1_ * 0x8000000) < 0)) {
    DAT_20004a9e = 1;
  }
  else {
    DAT_20004a9e = 0;
  }
  return;
}



// FUNCTION FUN_0804b70c @ 0804b70c
// XREF 08048d84

void FUN_0804b70c(void)

{
  DAT_20004b20 = 1;
  DAT_20004b21 = 0x80;
  DAT_20004b22 = 0x80;
  DAT_20004b23 = 0x80;
  DAT_20004b24 = 0x80;
  DAT_20004b25 = DAT_20004a78;
  DAT_20004b26 = DAT_20004a79;
  if ((DAT_20004a9a & 1) != 0) {
    DAT_20004b26 = DAT_20004a79 | 1;
  }
  if ((DAT_20004a9b & 1) != 0) {
    DAT_20004b26 = DAT_20004b26 | 2;
  }
  DAT_20004b27 = DAT_20004a7b;
  FUN_08020520(&DAT_20004b28,0x23);
  DAT_20004b4b = (char)DAT_20004a90;
  DAT_20004b4c = DAT_20004a90._1_1_;
  DAT_20004b4d = (char)DAT_20004a92;
  DAT_20004b4e = DAT_20004a92._1_1_;
  DAT_20004b4f = (char)DAT_20004a94;
  DAT_20004b50 = DAT_20004a94._1_1_;
  DAT_20004b51 = (char)DAT_20004a96;
  DAT_20004b52 = DAT_20004a96._1_1_;
  DAT_20004b53 = DAT_20004a9c;
  DAT_20004b56 = DAT_20004a7a;
  return;
}


