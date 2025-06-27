#include "../headers/fetch.h"
#include "../headers/memory.h"
#include "../headers/storageTypes.h"
#include "../headers/registers.h"
#include "../headers/JITCompiler.h"

void decode_and_execute(void)
{
    uint8_t opcode = fetch_byte();
    if ((opcode & 0xF0) == 0xB0)
    {
        int reg_lo = opcode & 0x07;
        uint8_t imm = fetch_byte();
        static const X86RegID map8[4] = 
        {
            REG_RAX, REG_RBX, REG_RCX, REG_RDX
        };
        X86Reg *r = reg_ptr(map8[reg_lo]);
        if (r)
        {
            r->low8 = imm;
        }
        return;
    }
    else
    {
        /*TODO: Add more opcodes*/
    }
}

void emulator_run(const char *com_image_path)
{
    (void)com_image_path;
    mem_init();
    cpu.CS = 0x0000;
    cpu.IP = 0x0100;
    while (1)
    {
        decode_and_execute();
    }
}