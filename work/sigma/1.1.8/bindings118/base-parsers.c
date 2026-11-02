
// FUNCTION FUN_08024c38 @ 08024c38
// XREF 08024be4

void FUN_08024c38(int param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == ' ') {
    FUN_0802063a(param_1 + 0xe1,param_2,0x20);
    if (*(char *)(param_1 + 0xf6) == '\a') {
      *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_1 + 0xf7);
    }
    DAT_20004570 = *(undefined2 *)(param_1 + 0xe2);
    uVar1 = *(uint *)(param_1 + 0xed) >> 4;
    DAT_20004564 = (*(uint *)(param_1 + 0xf1) & 0xfff) >> 4;
    DAT_20004560 = uVar1 | *(uint *)(param_1 + 0xf1) << 0x1c;
    if (((*(byte *)(param_1 + 0x158) >> 6 != 0) && ((*(byte *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)(((uVar1 & 0xff0000) >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    if (DAT_20000064 != *(byte *)(param_1 + 0x158) >> 6) {
      DAT_20000064 = (ushort)(*(byte *)(param_1 + 0x158) >> 6);
      if (*(byte *)(param_1 + 0x158) >> 6 == 0) {
        FUN_080452e0(2);
      }
      else {
        FUN_0804521c(2);
      }
    }
    if ((*(byte *)(param_1 + 0x159) >> 4 & 3) == 0) {
      iVar2 = FUN_08029b98();
      if (iVar2 == 0) {
        DAT_20004578 = 0;
      }
      else {
        uVar1 = FUN_08029b2c();
        DAT_20004578 = (undefined1)(uVar1 >> 4);
      }
    }
    else {
      DAT_20004578 = *(undefined1 *)(param_1 + 0x100);
    }
    if (*(byte *)(param_1 + 0x158) >> 6 != 0) {
      switch(*(byte *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08026798(param_1);
        }
        else {
          FUN_08026a6c(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004574 = *(short *)(param_1 + 0xea) * -0x10 - 1;
            DAT_20004572 = ~*(ushort *)(param_1 + 0xeb) | 0xf;
            DAT_20004576 = -1;
          }
        }
        break;
      case 2:
        FUN_08025ce4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = ~*(ushort *)(param_1 + 0xeb) | 0xf;
          DAT_20004572 = *(short *)(param_1 + 0xea) * -0x10 - 1;
          DAT_20004576 = -1;
        }
        break;
      case 3:
        FUN_08027ac4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = ~*(ushort *)(param_1 + 0xeb) | 0xf;
          DAT_20004572 = *(short *)(param_1 + 0xea) * -0x10 - 1;
          DAT_20004576 = -1;
        }
        break;
      case 4:
        FUN_08026fb8(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = ~*(ushort *)(param_1 + 0xeb) | 0xf;
          DAT_20004572 = *(short *)(param_1 + 0xea) * -0x10 - 1;
          DAT_20004576 = -1;
        }
        break;
      case 5:
        FUN_0802626c(param_1);
        break;
      case 6:
        FUN_080256e0(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = ~*(ushort *)(param_1 + 0xeb) | 0xf;
          DAT_20004572 = *(short *)(param_1 + 0xea) * -0x10 - 1;
          DAT_20004576 = -1;
        }
        break;
      case 0xb:
        FUN_0802754c(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = ~*(ushort *)(param_1 + 0xeb) | 0xf;
          DAT_20004572 = *(short *)(param_1 + 0xea) * -0x10 - 1;
          DAT_20004576 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004572 = *(short *)(param_1 + 0xe7) * -0x10 - 1;
      DAT_20004574 = ~*(ushort *)(param_1 + 0xe5) | 0xf;
      DAT_20004576 = -1 - (*(short *)(param_1 + 0xe5) << 0xc |
                          (ushort)*(byte *)(param_1 + 0xe4) << 4);
    }
    if (DAT_20003b68 == '\x01') {
      DAT_20004572 = -((ushort)DAT_20003b2e << 0xc | (ushort)DAT_20003b2d << 4) - 1;
      DAT_20004574 = -((ushort)DAT_20003b2c << 0xc | (ushort)DAT_20003b2b << 4) - 1;
      DAT_20004576 = -1 - ((ushort)DAT_20003b2a << 0xc | (ushort)DAT_20003b29 << 4);
    }
    if ((*(byte *)(param_1 + 0x159) >> 2 & 3) == 0) {
      iVar2 = FUN_08029550();
      if (iVar2 != 0) {
        DAT_20004579 = FUN_08029358();
        DAT_2000457a = FUN_0802944c();
      }
    }
    else {
      DAT_20004579 = (int)((uint)DAT_20004560._1_1_ * 0x8000000) < 0;
      DAT_2000457a = (int)((uint)DAT_20004560._1_1_ * 0x4000000) < 0;
    }
    if (*(byte *)(param_1 + 0x159) >> 6 == 0) {
      iVar2 = FUN_080292d8();
      if (iVar2 == 0) {
        DAT_2000457c = 0;
        DAT_2000457b = 0;
      }
      else {
        DAT_2000457b = FUN_08029224();
        iVar2 = FUN_08029284();
        if (iVar2 == 0) {
          DAT_2000457c = 0;
          DAT_20004579 = FUN_0802914c();
          DAT_2000457a = FUN_080291cc();
        }
        else {
          DAT_2000457c = 1;
        }
      }
    }
    else {
      DAT_2000457b = FUN_08024750((*(uint *)(param_1 + 0xf1) & 0x1fffffff) >> 0x14);
      DAT_2000457c = 1;
    }
    iVar2 = FUN_08029550();
    if (((iVar2 == 0) && (iVar2 = FUN_080292d8(), iVar2 == 0)) ||
       ((iVar2 = FUN_08029284(), iVar2 != 0 && (iVar2 = FUN_080292d8(), iVar2 != 0)))) {
      DAT_20004579 = 0;
      DAT_2000457a = 0;
    }
    DAT_2000456c = DAT_20004564;
    DAT_20004568 = DAT_20004560;
  }
  return;
}



// FUNCTION FUN_08025114 @ 08025114
// XREF 08024bd8

void FUN_08025114(int param_1,int param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == '\'') {
    DAT_20004570 = *(undefined2 *)(param_2 + 1);
    DAT_20004560 = (uint)(*(byte *)(param_2 + 0xc) >> 4) | (uint)*(byte *)(param_2 + 0xd) << 4 |
                   (uint)*(byte *)(param_2 + 0xe) << 0xc | (uint)*(byte *)(param_2 + 0xf) << 0x14 |
                   (uint)*(byte *)(param_2 + 0x10) << 0x1c;
    DAT_20004564 = (uint)(*(byte *)(param_2 + 0x10) >> 4) | (uint)*(byte *)(param_2 + 0x11) << 4 |
                   (uint)*(byte *)(param_2 + 0x12) << 0xc | (uint)*(byte *)(param_2 + 0x13) << 0x14
                   | (uint)*(byte *)(param_2 + 0x14) << 0x1c;
    *(undefined2 *)(param_1 + 0x158) = *(undefined2 *)(param_2 + 0x1c);
    if (((*(byte *)(param_1 + 0x158) >> 6 != 0) && ((*(byte *)(param_1 + 0x158) & 0x3f) == 1)) &&
       ((int)((DAT_20004560 >> 0x10) * 0x40000000) < 0)) {
      *(undefined1 *)(param_1 + 0x156) = 1;
    }
    DAT_2000084e = (ushort)*(byte *)(param_2 + 9) | (*(byte *)(param_2 + 10) & 0xf) << 8;
    DAT_2000084c = (ushort)(*(byte *)(param_2 + 10) >> 4) | (ushort)*(byte *)(param_2 + 0xb) << 4;
    if (DAT_20000066 != *(byte *)(param_1 + 0x158) >> 6) {
      DAT_20000066 = (ushort)(*(byte *)(param_1 + 0x158) >> 6);
      if (*(byte *)(param_1 + 0x158) >> 6 == 0) {
        FUN_080452e0(2);
      }
      else {
        FUN_0804521c(2);
      }
    }
    if ((*(byte *)(param_1 + 0x159) >> 4 & 3) == 0) {
      iVar2 = FUN_08029b98();
      if (iVar2 == 0) {
        DAT_20004578 = 0;
      }
      else {
        uVar1 = FUN_08029b2c();
        DAT_20004578 = (undefined1)(uVar1 >> 4);
      }
    }
    else {
      DAT_20004578 = *(undefined1 *)(param_2 + 8);
    }
    if (*(byte *)(param_1 + 0x158) >> 6 != 0) {
      switch(*(byte *)(param_1 + 0x158) & 0x3f) {
      case 0:
        break;
      case 1:
        if ((*(byte *)(param_1 + 0x156) & 1) == 0) {
          FUN_08026798(param_1);
        }
        else {
          FUN_08026a6c(param_1);
          if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
            DAT_20004574 = DAT_2000084c * -0x10 + -1;
            DAT_20004572 = DAT_2000084e * -0x10 + -1;
            DAT_20004576 = -1;
          }
        }
        break;
      case 2:
        FUN_08025ce4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = DAT_2000084c * -0x10 + -1;
          DAT_20004572 = DAT_2000084e * -0x10 + -1;
          DAT_20004576 = -1;
        }
        break;
      case 3:
        FUN_08027ac4(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = DAT_2000084c * -0x10 + -1;
          DAT_20004572 = DAT_2000084e * -0x10 + -1;
          DAT_20004576 = -1;
        }
        break;
      case 4:
        FUN_08026fb8(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = DAT_2000084c * -0x10 + -1;
          DAT_20004572 = DAT_2000084e * -0x10 + -1;
          DAT_20004576 = -1;
        }
        break;
      case 5:
        FUN_0802626c(param_1);
        break;
      case 6:
        FUN_080256e0(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = DAT_2000084c * -0x10 + -1;
          DAT_20004572 = DAT_2000084e * -0x10 + -1;
          DAT_20004576 = -1;
        }
        break;
      case 0xb:
        FUN_0802754c(param_1);
        if ((*(byte *)(param_1 + 0x159) & 3) == 0) {
          DAT_20004574 = DAT_2000084c * -0x10 + -1;
          DAT_20004572 = DAT_2000084e * -0x10 + -1;
          DAT_20004576 = -1;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x159) & 3) != 0) {
      DAT_20004572 = -1 - ((ushort)*(byte *)(param_2 + 4) << 0xc |
                          (ushort)*(byte *)(param_2 + 3) << 4);
      DAT_20004574 = -1 - (*(byte *)(param_2 + 4) & 0xf0 | (ushort)*(byte *)(param_2 + 5) << 8);
      DAT_20004576 = -1 - ((ushort)*(byte *)(param_2 + 7) << 0xc |
                          (ushort)*(byte *)(param_2 + 6) << 4);
    }
    if (DAT_20003b68 == '\x01') {
      DAT_20004572 = -1 - ((ushort)DAT_20003b2e << 0xc | (ushort)DAT_20003b2d << 4);
      DAT_20004574 = -1 - ((ushort)DAT_20003b2c << 0xc | (ushort)DAT_20003b2b << 4);
      DAT_20004576 = -1 - ((ushort)DAT_20003b2a << 0xc | (ushort)DAT_20003b29 << 4);
    }
    if ((*(byte *)(param_1 + 0x159) >> 2 & 3) == 0) {
      iVar2 = FUN_08029550();
      if (iVar2 != 0) {
        DAT_20004579 = FUN_08029358();
        DAT_2000457a = FUN_0802944c();
      }
    }
    else {
      DAT_20004579 = (int)((uint)DAT_20004560._1_1_ * 0x8000000) < 0;
      DAT_2000457a = (int)((uint)DAT_20004560._1_1_ * 0x4000000) < 0;
    }
    if (*(byte *)(param_1 + 0x159) >> 6 == 0) {
      iVar2 = FUN_080292d8();
      if (iVar2 == 0) {
        DAT_2000457b = 0;
        DAT_2000457c = false;
      }
      else {
        DAT_2000457b = FUN_08029224();
        iVar2 = FUN_08029284();
        if (iVar2 == 0) {
          DAT_20004579 = FUN_0802914c();
          DAT_2000457a = FUN_080291cc();
        }
        DAT_2000457c = iVar2 != 0;
      }
    }
    else if ((int)((uint)*(byte *)(param_2 + 0x1b) * 0x1000000) < 0) {
      DAT_2000457b = 0;
      DAT_2000457c = false;
    }
    else {
      if ((int)((uint)*(byte *)(param_2 + 0x13) * 0x8000000) < 0) {
        DAT_2000457b = 0x80;
      }
      else {
        DAT_2000457b = FUN_08024750(*(byte *)(param_2 + 0x12) >> 4 | *(char *)(param_2 + 0x13) << 4)
        ;
      }
      DAT_2000457c = true;
    }
    iVar2 = FUN_08029550();
    if (((iVar2 == 0) && (iVar2 = FUN_080292d8(), iVar2 == 0)) ||
       ((iVar2 = FUN_08029284(), iVar2 != 0 && (iVar2 = FUN_080292d8(), iVar2 != 0)))) {
      DAT_20004579 = 0;
      DAT_2000457a = 0;
    }
    DAT_2000456c = DAT_20004564;
    DAT_20004568 = DAT_20004560;
  }
  return;
}


