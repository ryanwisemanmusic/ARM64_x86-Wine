#include <stdint.h>
#include <unistd.h>

void emulator_run(void);

__attribute__((noreturn))
void _start(void)
{
    emulator_run();
    _exit(0);
}

void emulator_run(void)
{
    _exit(0);
}