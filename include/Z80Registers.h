#ifndef Z80REGISTERS_H
#define Z80REGISTERS_H

using ui8 = unsigned char;
using ui16 = unsigned short;
using ui32 = unsigned int;
using ui64 = unsigned long long;
using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;

class Z80Registers {
public:

    /*Main register Set*/

    // accumulator + flag
    union {
        struct {
            ui8 a,f;
        };
        ui16 af;
    };

    //general purpose register pair BC
    union {
        struct {
            ui8 b, c;
        };
        ui16 bc;
    };

    //general purpose register pair DE
    union {
        struct {
            ui8 d, e;
        };
        ui16 de;
    };

    //general purpose register pair HL
    union {
        struct {
            ui8 h, l;
        };
        ui16 hl;
    };

    /*Alternate register Set*/

    //alternate accumulator + flag
    union {
        struct {
            ui8 alt_a,alt_f;
        };
        ui16 alt_af;
    };

    //alternate register pair BC
    union {
        struct {
            ui8 alt_b, alt_c;
        };
        ui16 alt_bc;
    };

    //alternate register pair DE
    union {
        struct {
            ui8 alt_d, alt_e;
        };
        ui16 alt_de;
    };

    //alternate register pair HL
    union {
        struct {
            ui8 alt_h, alt_l;
        };
        ui16 alt_hl;
    };


    /*Special purpose registers*/

    //stack pointer
    ui16 sp;

    //program counter
    ui16 pc;

    //index registers
    ui16 ix;
    ui16 iy;

    //interrupt vector
    ui8 i;

    //memory refresh
    ui8 r;

    Z80Registers();

    void init();
};


#endif //Z80REGISTERS_H
