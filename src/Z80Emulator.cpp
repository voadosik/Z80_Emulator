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
        case 0x06: // LD B, n
            Instructions::LD_r_n(registers, registers.b, memory.readByte(registers.pc + 1));
            break;
        case 0x0E: // LD C, n
            Instructions::LD_r_n(registers, registers.c, memory.readByte(registers.pc + 1));
            break;
        case 0x16: // LD D, n
            Instructions::LD_r_n(registers, registers.d, memory.readByte(registers.pc + 1));
            break;
        case 0x1E: // LD E, n
            Instructions::LD_r_n(registers, registers.e, memory.readByte(registers.pc + 1));
            break;
        case 0x26: // LD H, n
            Instructions::LD_r_n(registers, registers.h, memory.readByte(registers.pc + 1));
            break;
        case 0x2E: // LD L, n
            Instructions::LD_r_n(registers, registers.l, memory.readByte(registers.pc + 1));
            break;
        case 0x3E: // LD A, n
            Instructions::LD_r_n(registers, registers.a, memory.readByte(registers.pc + 1));
            break;

        default:
            break;

    }
}
