#pragma once
#include "storageTypes.h"
#include <stddef.h>

static inline X86Reg *reg_ptr(X86RegID id)
{
    if (id >= REG_COUNT) return NULL;
    return &((X86Reg *)&cpu)[id];
}

static inline uint64_t reg_read(X86RegID id, int size)
{
    X86Reg *r = reg_ptr(id);
    if (!r) return 0;
    switch (size)
    {
        case 1: return r->low8;
        case 2: return r->high8;
        case 3: return r->r16;
        case 4: return r->r32;
        case 8: return r->r64;
        default: return 0;
    }
}

static inline void reg_write(X86RegID id, int size, uint64_t v)
{
    X86Reg *r = reg_ptr(id);
    if (!r) return; 
    switch (size)
    {
        case 1: r->low8 = (byte)v; break;
        case 2: r->r16 = (word)v; break;
        case 3: r->r32 = (dword)v; break;
        case 4: r->r32 = (dword)v; break;
        case 8: r->r64 = (qword)v; break;
    }
}