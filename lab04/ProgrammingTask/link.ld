OUTPUT_ARCH( "riscv" )
ENTRY( main )
SECTIONS
{
  /* text: test code section */

  . = 0x80000000;
  .text : { *(.text) }

  /* data: Initialized data segment */

  . = ALIGN(0x1000);
  . = 0x80001000;
  .data : { *(.data) }

  /* End of uninitalized data segement */
  /* Put symbols in for tohost/fromhost */
  /* Spike pulls these out for its own use */
  /* Needs to be aligned to 8-byte boundary */
  /* because fesvr reads tohost/fromhost values */
  /* using memif_t::read_uint64() */

  . = ALIGN(0x1000);
  .tohost = .;
  
  _end = .;

}
