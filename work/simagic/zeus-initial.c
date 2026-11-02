
// FUNCTION Reset_Handler @ 0802691c
// XREF 08022004
// XREF Entry Point

void Reset_Handler(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  for (iVar1 = 0; puVar2 = DAT_0802695c, (uint)(DAT_08026954 + iVar1) < DAT_08026958;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(DAT_08026954 + iVar1) = *(undefined4 *)(DAT_08026950 + iVar1);
  }
  for (; puVar2 < DAT_08026960; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  FUN_08033764();
  FUN_08035668();
  FUN_0802e3be();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// FUNCTION FUN_0802a7e0 @ 0802a7e0

undefined4 FUN_0802a7e0(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  puVar2 = *(undefined1 **)(param_1 + 0x438);
  switch(param_2[1]) {
  case 1:
    *puVar2 = *param_2;
    puVar2[1] = 1;
    uVar1 = *(undefined2 *)(param_2 + 2);
    puVar2[2] = (char)uVar1;
    puVar2[3] = (char)((ushort)uVar1 >> 8);
    uVar1 = *(undefined2 *)(param_2 + 4);
    puVar2[4] = (char)uVar1;
    puVar2[5] = (char)((ushort)uVar1 >> 8);
    uVar1 = *(undefined2 *)(param_2 + 6);
    puVar2[6] = (char)uVar1;
    puVar2[7] = (char)((ushort)uVar1 >> 8);
    (**(code **)(DAT_0802a894 + 8))(0,puVar2,0x40,*(code **)(DAT_0802a894 + 8),param_4);
    break;
  case 2:
    puVar2 = puVar2 + 0x41;
    goto LAB_0802a830;
  case 3:
    puVar2 = puVar2 + 0x42;
LAB_0802a830:
    *(undefined1 **)(param_1 + 0xd8) = puVar2;
    *(undefined4 *)(param_1 + 0xe4) = 1;
    break;
  default:
    return 2;
  case 6:
    if (*(ushort *)(param_2 + 2) >> 8 == 0x22) {
      uVar3 = (uint)*(ushort *)(param_2 + 6);
      if (0xa3 < uVar3) {
        uVar3 = 0xa4;
      }
      *(uint *)(param_1 + 0xe4) = uVar3;
      uVar4 = DAT_0802a898;
    }
    else {
      if (*(ushort *)(param_2 + 2) >> 8 != 0x21) {
        return 0;
      }
      uVar3 = (uint)*(ushort *)(param_2 + 6);
      if (8 < uVar3) {
        uVar3 = 9;
      }
      *(uint *)(param_1 + 0xe4) = uVar3;
      uVar4 = DAT_0802a89c;
    }
    *(undefined4 *)(param_1 + 0xd8) = uVar4;
    break;
  case 9:
    *(undefined1 **)(param_1 + 0x27c) = puVar2;
    *(uint *)(param_1 + 0x288) = (uint)*(ushort *)(param_2 + 6);
    break;
  case 10:
    puVar2[0x41] = (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8);
    break;
  case 0xb:
    puVar2[0x42] = (char)*(undefined2 *)(param_2 + 2);
  }
  return 0;
}


