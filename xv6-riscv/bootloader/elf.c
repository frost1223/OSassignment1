#include "types.h"
#include "param.h"
#include "layout.h"
#include "riscv.h"
#include "defs.h"
#include "buf.h"
#include "elf.h"
#include <stdint.h>
#include <stdbool.h>

struct elfhdr* kernel_elfhdr;
struct proghdr* kernel_phdr;

uint64 find_kernel_load_addr(enum kernel ktype) {
    /* CSE 536: Get kernel load address from headers */
    struct elfhdr* eh = (struct elfhdr *)RAMDISK;
    struct proghdr* ph = (struct proghdr *)((uint64_t)eh + eh->phoff + eh->phentsize);

    uint64_t kernload_start = ph->vaddr;

    return kernload_start;
}

uint64 find_kernel_size(enum kernel ktype) {
    /* CSE 536: Get kernel binary size from headers */
    struct elfhdr *eh = (struct elfhdr *)RAMDISK;
    uint64_t kernel_size = (eh->shoff) + (eh->shnum)*(eh->shentsize) ;
    return kernel_size;
}

uint64 find_kernel_entry_addr(enum kernel ktype) {
    /* CSE 536: Get kernel entry point from headers */
    struct elfhdr *eh = (struct elfhdr *)RAMDISK;
    return eh->entry;
}
