#include "../headers/fetch.h"
#include "../headers/memory.h"
#include "../headers/storageTypes.h"

uint8_t fetch_byte(void)
{
    uint8_t b = mem_read8(cpu.CS, cpu.IP);
    cpu.IP = (uint16_t)(cpu.IP + 1);
    return b;
}

uint16_t fetch_word(void)
{
    uint16_t lo = fetch_byte();
    uint16_t hi = fetch_byte();
    return lo | (hi << 8);
}
