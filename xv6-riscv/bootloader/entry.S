# _entry should be the first function invoked when
# the QEMU CPU starts executing. It's location should
# according to the memory layout provided in param.h

.section .text
.global _entry
_entry:
        # task: setup a per-CPU stack for C and jump to start() function
        .extern bl_stack
        la a0, bl_stack
        addi a0, a0, 4096
        li a1, r_mhartid
        mul a0, a0, a1
        la sp, a0
        jal zero, start

spin:
        j spin
