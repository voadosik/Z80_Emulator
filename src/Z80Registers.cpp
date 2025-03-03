#include "../include/Z80Registers.h"

Z80Registers::Z80Registers() {
    init();
}

void Z80Registers::init() {
    af = 0;
    bc = 0;
    de = 0;
    hl = 0;
    alt_af = 0;
    alt_bc = 0;
    alt_de = 0;
    alt_hl = 0;
    sp = 0xFFFF;
    pc = 0;
    ix = 0;
    iy = 0;
    i = 0;
    r = 0;
}

