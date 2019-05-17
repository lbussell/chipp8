#include <stdio.h>


/*
    0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
    0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
    0x200-0xFFF - Program ROM and work RAM
*/

class Chip8 {
    public:
        unsigned short I; // Index register
        unsigned short pc; // Program counter
        unsigned short opcode;
        unsigned short stack[16];
        unsigned short sp; // Stack pointer

        unsigned char memory[4096];
        unsigned char V[16]; // Registers V0 - VF
        unsigned char gfx[64 * 32];
        unsigned char delay_timer;
        unsigned char sound_timer;
        unsigned char keypad[16];

        bool drawFlag;

        void initialize();
        void loadGame(char *);
        void emulateCycle();
        void setKeys();

    private:
};
