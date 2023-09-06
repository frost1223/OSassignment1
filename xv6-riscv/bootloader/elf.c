#include "types.h"
#include "param.h"
#include "layout.h"
#include "riscv.h"
#include "defs.h"
#include "buf.h"
#include "elf.h"

#include <stdbool.h>

struct elfhdr* kernel_elfhdr;
struct proghdr* kernel_phdr;

uint64 find_kernel_load_addr(enum kernel ktype) {
    /* CSE 536: Get kernel load address from headers */
    kernel_elfhdr = (elfhdr *)RAMDISK;
    kernel_phdr = (proghdr *)((uint64_t)kernel_elfhdr + kernel_elfhdr->phoff + kernel_elfhdr->phentsize);

    uint64_t kernload_start = kernel_phdr->vaddr;

    return kernload_start;
}

uint64 find_kernel_size(enum kernel ktype) {
    /* CSE 536: Get kernel binary size from headers */
   kernel_elfhdr = (elfhdr *)RAMDISK;
    uint64_t kernel_size = kernel_elfhdr->phoff + (kernel_elfhdr->phnum)*(kernel_elfhdr->phentsize) + (kernel_elfhdr->shnum)*(kernel_elfhdr->shentsize) ;
    return kernel_size;
}

uint64 find_kernel_entry_addr(enum kernel ktype) {
    /* CSE 536: Get kernel entry point from headers */
    return 0;
}