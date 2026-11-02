
// FUNCTION FUN_080291e4 @ 080291e4
// XREF 080298f6

undefined4 FUN_080291e4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = DAT_08029228;
  iVar3 = DAT_0802922c;
  do {
    if (*(char *)(iVar1 + 5) == '\0') {
      if (*(int *)(iVar3 + 0x10) != 2) {
        iVar4 = 0;
        do {
          *(undefined4 *)(iVar3 + 0x20 + iVar4 * 4) = 0;
          iVar4 = iVar4 + 4;
        } while (iVar4 != 0x30);
      }
      *(undefined4 *)(iVar3 + 0x120) = 0;
      *(undefined4 *)(iVar3 + 0x130) = 0;
    }
    else {
      *(char *)(iVar1 + 5) = *(char *)(iVar1 + 5) + -1;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x12;
    iVar3 = iVar3 + 0x13c;
  } while (iVar2 != 4);
  return 0;
}



// FUNCTION FUN_08029484 @ 08029484
// XREF 080298ea

undefined4 FUN_08029484(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_080294b4;
  iVar2 = DAT_080294b0;
  if (*(char *)(DAT_080294b0 + 8) == '\0') {
    *(undefined4 *)(DAT_080294b4 + 0x60) = 0;
    *(undefined4 *)(iVar3 + 0x70) = 0;
  }
  else {
    *(char *)(DAT_080294b0 + 8) = *(char *)(DAT_080294b0 + 8) + -1;
  }
  iVar3 = DAT_080294b4;
  cVar1 = *(char *)(iVar2 + 0x11);
  if (cVar1 == '\0') {
    *(undefined4 *)(DAT_080294b4 + 0xd8) = 0;
    *(undefined4 *)(iVar3 + 0xe8) = 0;
  }
  else {
    *(char *)(iVar2 + 0x11) = cVar1 + -1;
  }
  return 0;
}



// FUNCTION FUN_080299e0 @ 080299e0
// XREF 080298f0

undefined4 FUN_080299e0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = DAT_08029a08;
  iVar3 = DAT_08029a0c;
  do {
    if (*(char *)(iVar2 + 3) == '\0') {
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
    }
    else {
      *(char *)(iVar2 + 3) = *(char *)(iVar2 + 3) + -1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 0x28;
  } while (iVar1 != 4);
  return 0;
}


