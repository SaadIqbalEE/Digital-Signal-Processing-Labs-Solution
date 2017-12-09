/* c6713dsk.cmd  Linker command file 
*
*  332:348 - DSP Lab - Spring 2011
*  
*  Reference and installed DSP Lab software: R. Chassaing and D. Reay, "Digital Signal Processing 
*  and Applications with the TMS320C6713 and TMSC6416 DSK", Wiley, Hoboken, NJ, 2008. 
* ------------------------------------------------------------------------------------------------ */

-c                
-heap  0x400    
-stack 0x400    /* 1 Kbyte stack - added by SJO to prevent warnings */

MEMORY
{
  IVECS:        org=0h,   	len=0x220        /* 544  bytes */
  IRAM:		org=0x00000220,	len=0x0002FDE0   /* internal memory - 196 Kbytes */
  SDRAM:	org=0x80000000, len=0x01000000   /* external memory - 16 Mbytes  */
  FLASH:	org=0x90000000, len=0x00020000   /* flash memory - 128 Kbytes    */                    
}

SECTIONS
{
  .EXT_RAM > SDRAM
  .vectors > IVECS   /* in vector file */
  .text    > IRAM    /* Created by C Compiler */
  .bss     > IRAM
  .cinit   > IRAM
  .stack   > IRAM
  .sysmem  > IRAM
  .const   > IRAM
  .switch  > IRAM
  .far     > IRAM
  .cio     > IRAM
  .csldata > IRAM
}
