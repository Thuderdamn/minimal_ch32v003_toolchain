.section .text.start, "ax", %progbits
.global _start
_start:

    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop


    la sp, _eusrstack


    la a0, _sdata
    la a1, _edata
    la a2, _sidata
copy_data:
    beq a0, a1, zero_bss
    lw t0, 0(a2)
    sw t0, 0(a0)
    addi a0, a0, 4
    addi a2, a2, 4
    j copy_data

zero_bss:
    la a0, _sbss
    la a1, _ebss
zero_loop:
    beq a0, a1, call_main
    sw zero, 0(a0)
    addi a0, a0, 4
    j zero_loop

call_main:
    jal ra, main
loop_forever:
    j loop_forever
