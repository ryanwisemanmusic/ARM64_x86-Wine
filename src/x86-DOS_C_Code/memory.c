#include <stdlib.h>
#include <stdio.h>
#include "../headers/memory.h"

uint8_t *RAM = NULL;

void mem_init(void)
{
    RAM = malloc(RAM_SIZE);
    if (!RAM)
    {
        printf("Unable to allocate RAM\n"); 
        exit(1);
    }
    //If we are successful, we should load either a .COM or .EXE image 
    //into RAM[0x0000:0x0100]
}

uint32_t linear_addr(uint16_t seg, uint16_t off)
{
    return ((uint32_t)seg << 4) + off & 0xFFFFF;
}

uint8_t mem_read8(uint16_t seg, uint16_t off)
{
    return RAM[linear_addr(seg, off)];
}

uint16_t mem_read16(uint16_t seg, uint16_t off)
{
    uint32_t a = linear_addr(seg, off);
    return RAM[a] | (RAM[a + 1] << 8);
}

void mem_write8(uint16_t seg, uint16_t off, uint8_t v)
{
    RAM[linear_addr(seg, off)] = v;
}

void mem_write16(uint16_t seg, uint16_t off, uint16_t v)
{
    uint32_t a = linear_addr(seg, off);
    RAM[a] = v & 0xFF;
    RAM[a + 1] = v >> 8;
}