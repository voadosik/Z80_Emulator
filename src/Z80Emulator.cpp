#include "../include/Z80Emulator.h"

Z80Emulator::Z80Emulator() {
    init();
}

void Z80Emulator::init() {
    registers.init();
    memory.init();
    halt = false;
}

void Z80Emulator::cycle() {
    if (!halt) {
        ui8 opcode = fetch();
        execute(opcode);
    }
    return;
}

ui8 Z80Emulator::fetch() {
    return memory.readByte(registers.pc++);
}

void Z80Emulator::execute(ui8 opcode) {
    switch (opcode) {

    }
}
