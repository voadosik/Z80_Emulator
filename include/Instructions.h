#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Z80Emulator.h"

class Instructions {
public:
    enum Flag {
        C = 0x01,  // Carry Flag
        N = 0x02,  // Add/Subtract Flag (BCD)
        P = 0x04,  // Parity/Overflow Flag
        X = 0x08,  // Not used
        H = 0x10,  // Half Carry Flag (BCD)
        Y = 0x20,  // Not used
        Z = 0x40,  // Zero Flag
        S = 0x80   // Sign Flag
    };
    // Helper functions for flag manipulation
    static bool getFlag(Z80Registers& regs, Flag flag);
    static void setFlag(Z80Registers& regs, Flag flag, bool value);

    // 8-bit load instructions
    static void LD_r_n(Z80Registers& regs, ui8& reg, ui8 n);
    static void LD_r_r(Z80Registers& regs, ui8& reg1, ui8 reg2);
    static void LD_r_HL(Z80Registers& regs, Z80Memory& mem, ui8& reg);
    static void LD_HL_r(Z80Registers& regs, Z80Memory& mem, ui8 reg);
    static void LD_HL_n(Z80Registers& regs, Z80Memory& mem, ui8 n);
    static void LD_A_BC(Z80Registers& regs, Z80Memory& mem);
    static void LD_A_DE(Z80Registers& regs, Z80Memory& mem);
    static void LD_A_nn(Z80Registers& regs, Z80Memory& mem, ui16 addr);
    static void LD_BC_A(Z80Registers& regs, Z80Memory& mem);
    static void LD_DE_A(Z80Registers& regs, Z80Memory& mem);
    static void LD_nn_A(Z80Registers& regs, Z80Memory& mem, ui16 addr);

    // 16-bit load instructions
    static void LD_rr_nn(Z80Registers& regs, ui16& regPair, ui16 nn);
    static void LD_SP_HL(Z80Registers& regs);
    static void PUSH_rr(Z80Registers& regs, Z80Memory& mem, ui16 regPair);
    static void POP_rr(Z80Registers& regs, Z80Memory& mem, ui16& regPair);
};


#endif //INSTRUCTIONS_H
