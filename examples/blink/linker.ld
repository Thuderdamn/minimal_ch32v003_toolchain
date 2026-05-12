ENTRY(_start)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 16K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 2K
}

SECTIONS
{
    .text : {
        . = ALIGN(4);
        KEEP(*(.text.start))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    } >FLASH

    .data : {
        . = ALIGN(4);
        _sdata = .;
        *(.data*)
        *(.sdata*)
        . = ALIGN(4);
        _edata = .;
    } >RAM AT>FLASH
    _sidata = LOADADDR(.data);

    .bss : {
        . = ALIGN(4);
        _sbss = .;
        *(.sbss*)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } >RAM

    _eusrstack = ORIGIN(RAM) + LENGTH(RAM);
}
__global_pointer$ = (_sdata + _ebss) / 2;
