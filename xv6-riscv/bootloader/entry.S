# _entry should be the first function invoked when
# the QEMU CPU starts executing. It's location should
# according to the memory layout provided in param.h

.section .text
.global _entry
.extern bl_stack
_entry:
        # task: setup a per-CPU stack for C and jump to start() function
        la a0, bl_stack
	li a1, 4096
        add a0, a0, a1
	li a2, 1
	csrr a3, mhartid
	add a3, a3, a2
        mul a0, a0, a3
        addi sp, a0, 0
        jal start

spin:
        j spin
