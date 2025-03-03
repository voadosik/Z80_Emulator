#ifndef Z80EMULATOR_H
#define Z80EMULATOR_H

#include "../include/Z80Memory.h"
#include "../include/Z80Registers.h"
#include "../include/Instructions.h"
#include <iostream>

class Z80Emulator {
private:
    Z80Registers registers;
    Z80Memory memory;
    bool halt;

    //fetch opcode and increment the PC
    ui8 fetch();

    //decode the opcode and execute it
    void execute(ui8 opcode);
public:
    Z80Emulator();

    //initialize the CPU state
    void init();

    //perform one instruction cycle
    void cycle();
};

#endif //Z80EMULATOR_H
