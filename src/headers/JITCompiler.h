#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>

void *code_buffer = mmap(NULL, 4096, PROT_READ | PROT_WRITE | 
    PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

void (*jit_fn)(void) = (void (*)(void))code_buffer;