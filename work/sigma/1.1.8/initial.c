
// FUNCTION Reset_Handler @ 080202b0
// XREF 08020004
// XREF Entry Point

void Reset_Handler(void)

{
  (*DAT_080202d8)();
                    /* WARNING: Could not recover jumptable at 0x080202b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_080202dc)();
  return;
}



// FUNCTION FUN_080202cc @ 080202cc
// XREF 08020482

undefined8 FUN_080202cc(void)

{
  return CONCAT44(DAT_080202e4,DAT_080202e0);
}


