OUTPUT_ARCH( "riscv" )

/* Task: ensure the correct starting function. */
ENTRY( _entry )

SECTIONS
{
  /* Task: ensure the correct entry address based on where -kernel in QEMU jumps. */
  . = 0x80000000;
  

  /* Task lay out the sections as mentioned in the handout */

.text :  {
        ecode = .; 
        *(.text)
    }

    
    .data : {
        edata = .; 
        *(.data)
    }

    
    .rodata : {
        erodata = .; 
        *(.rodata)
    }

    
    .bss : {
        ebss = .;
        *(.bss)
    }

    
    end = .;
}
