#include "../headers/fetch.h"
#include "../headers/memory.h"
#include "../headers/storageTypes.h"
#include "../headers/registers.h"

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

uint32_t fetch_dword(void) 
{
    uint32_t b0 = fetch_byte();
    uint32_t b1 = fetch_byte() << 8;
    uint32_t b2 = fetch_byte() << 16;
    uint32_t b3 = fetch_byte() << 24;
    return b0 | b1 | b2 | b3;
}

uint64_t fetch_qword(void) 
{
    uint64_t lo = fetch_dword();
    uint64_t hi = fetch_dword();
    return lo | (hi << 32);
}
