#ifndef Z80MEMORY_H
#define Z80MEMORY_H

#include <array>
#include "Z80Registers.h"

class Z80Memory {
private:
    static constexpr ui16 MEMORY_SIZE = 0x10000; // 64 KB of memory
    std::array<ui8, MEMORY_SIZE> memory;
public:

    Z80Memory();

    //reads a byte from memory
    ui8 readByte(ui16 address) const;

    //writes a byte to memory
    void writeByte(ui16 address, ui8 value);

    //reads a 16-bit word(LE)
    ui16 readWord(ui16 address) const;

    //writes a 16-bit word(LE)
    void writeWord(ui16 address, ui16 value);

    void init();
};


#endif //Z80MEMORY_H
