#include <unistd.h>

extern void emulator_run(void);

__attribute__((noreturn))
void _start(void) {
    emulator_run();
    _exit(0);
}