/* Append after every original byte, including the unclassified final16bytes. */
ENTRY(zeus_construct_hook)
MEMORY { FLASH (rx) : ORIGIN = 0x0804e280, LENGTH = 0x6c60 }
SECTIONS {
  .text : { *(.text*) *(.rodata*) } > FLASH
  .data : { *(.data*) } > FLASH
  .bss : { *(.bss*) *(COMMON) } > FLASH
  ASSERT(SIZEOF(.data)==0, "patch must not require initialized RAM")
  ASSERT(SIZEOF(.bss)==0, "patch must use only its reserved RAM")
  /DISCARD/ : { *(.ARM.exidx*) *(.ARM.extab*) *(.comment) *(.note*) }
}
