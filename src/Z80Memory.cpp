#include "../include/Z80Memory.h"


Z80Memory::Z80Memory() {
    init();
}

void Z80Memory::init() {
    memory.fill(0);
}

ui8 Z80Memory::readByte(ui16 address) const {
    return memory[address];
}

void Z80Memory::writeByte(ui16 address, ui8 value) {
    memory[address] = value;
}

ui16 Z80Memory::readWord(ui16 address) const {
    return memory[address] | (memory[address + 1] << 8);
}

void Z80Memory::writeWord(ui16 address, ui16 value) {
    memory[address] = value & 0xFF;
    memory[address + 1] = (value >> 8) & 0xFF;
}
