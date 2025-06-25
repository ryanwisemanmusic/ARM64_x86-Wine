#pragma once
#include <cstdint>

//Byte ARM equivalent
typedef uint8_t byte;
//Word ARM equivalent
typedef uint16_t word;
//Double-Word ARM equivalent
typedef uint32_t dword;
//Quad-Word ARM equivalent
typedef uint64_t qword;
//Double-Quad-Word ARM equivalent
typedef uint64_t dqword;

typedef union 
{
    qword r64;
    dword r32;
    word r16;
    struct 
    {
        byte low8;
        byte high8;
    };

} X86Reg;

typedef struct {
    X86Reg RAX, RBX, RCX, RDX;
    X86Reg RSI, RDI, RBP, RSP; 
    X86Reg R8, R9, R10, R11; 
    X86Reg R12, R13, R14, R15;
} cpu_registers_t;

extern cpu_registers_t cpu;

typedef enum {
    REG_RAX, REG_RBX, REG_RCX, REG_RDX,
    REG_RSI, REG_RDI, REG_RBP, REG_RSP,
    REG_R8, REG_R9, REG_R10, REG_R11,
    REG_R12, REG_R13, REG_R14, REG_R15,
    REG_COUNT
} X86RegID;



