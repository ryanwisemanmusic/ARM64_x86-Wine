    .global _start
    .extern _emulator_run
_start:
    b      _emulator_run