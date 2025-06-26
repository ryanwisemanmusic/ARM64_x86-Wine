#pragma once
#include <stdint.h>

/*
This is the amount of RAM that is applicable to x86 (DOS)
Since this is the foudnational architecture we will be working with,
we will be temporarily limiting the amount of RAM to 1MB.

RAM segments off into 0x0000-0xFFFF mapped to 20-bit addresses
*/
#define RAM_SIZE (1024 * 1024)

extern uint8_t *RAM;

uint8_t   mem_read8(uint16_t seg, uint16_t off);
uint16_t  mem_read16(uint16_t seg, uint16_t off);
void      mem_write8(uint16_t seg, uint16_t off, uint8_t v);
void      mem_write16(uint16_t seg, uint16_t off, uint16_t v);
void      mem_init(void);