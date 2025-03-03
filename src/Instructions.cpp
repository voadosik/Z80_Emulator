#include "../include/Instructions.h"

bool Instructions::getFlag(Z80Registers& regs, Flag flag) {
    return (regs.a & flag) != 0;
}

void Instructions::setFlag(Z80Registers& regs, Flag flag, bool value) {
    if (value) {
        regs.f |= flag;
    }
    else {
        regs.f &= ~flag;
    }
}

void Instructions::LD_r_n(Z80Registers &regs, ui8 &reg, ui8 n) {
    reg = n;
    regs.pc += 1;
}

void Instructions::LD_r_r(Z80Registers &regs, ui8 &reg1, ui8 reg2) {
    reg1 = reg2;
    regs.pc += 1;
}

void Instructions::LD_r_HL(Z80Registers &regs, Z80Memory &mem, ui8 &reg) {
    reg = mem.readByte(regs.hl);
    regs.pc += 1;
}

void Instructions::LD_HL_r(Z80Registers &regs, Z80Memory &mem, ui8 reg) {
    mem.writeByte(regs.hl, reg);
    regs.pc += 1;
}


void Instructions::LD_HL_n(Z80Registers &regs, Z80Memory &mem, ui8 n) {
    mem.writeByte(regs.hl, n);
    regs.pc += 2;
}

void Instructions::LD_A_BC(Z80Registers &regs, Z80Memory &mem) {
    regs.a = mem.readByte(regs.bc);
    regs.pc += 1;
}

void Instructions::LD_A_DE(Z80Registers &regs, Z80Memory &mem) {
    regs.a = mem.readByte(regs.de);
    regs.pc += 1;
}

void Instructions::LD_A_nn(Z80Registers &regs, Z80Memory &mem, ui16 addr) {
    regs.a = mem.readByte(addr);
    regs.pc += 3;
}

void Instructions::LD_BC_A(Z80Registers &regs, Z80Memory &mem) {
    mem.writeByte(regs.bc, regs.a);
    regs.pc += 1;
}

void Instructions::LD_DE_A(Z80Registers &regs, Z80Memory &mem) {
    mem.writeByte(regs.de, regs.a);
    regs.pc += 1;
}

void Instructions::LD_nn_A(Z80Registers &regs, Z80Memory &mem, ui16 addr) {
    mem.writeByte(addr, regs.a);
    regs.pc += 3;
}

void Instructions::LD_rr_nn(Z80Registers &regs, ui16 &regPair, ui16 nn) {
    regPair = nn;
    regs.pc += 2;
}

void Instructions::LD_SP_HL(Z80Registers &regs) {
    regs.sp = regs.hl;
    regs.pc += 1;
}

void Instructions::PUSH_rr(Z80Registers &regs, Z80Memory &mem, ui16 regPair) {
    regs.sp -= 2;
    mem.writeWord(regs.sp, regPair);
    regs.pc += 1;
}

void Instructions::POP_rr(Z80Registers& regs, Z80Memory& mem, ui16& regPair) {
    regPair = mem.readWord(regs.sp);
    regs.sp += 2;
    regs.pc += 1;
}











