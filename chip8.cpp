#include <iostream>
#include "chip8.hpp"
using namespace std;

void Chip8::initialize()
{
    pc = 0x200;
    opcode = 0;
    I = 0;
    sp = 0;

    // Clear memory
    fill_n(memory, sizeof(memory), 0);
    // Clear registers
    fill_n(V, sizeof(V), 0);
    // Clear screen
    fill_n(gfx, SCREEN_WIDTH * SCREEN_HEIGHT, 0);
}

int Chip8::loadGame(char *filename)
{
    printf("Loading ROM: %s\n", filename);

    // Load file
    FILE *rom;
    if (!(rom = fopen(filename, "rb"))) {
        printf("Unable to open ROM at %s\n", filename);
        return EXIT_FAILURE;
    }

    // Find size of ROM file
    fseek(rom, 0, SEEK_END);
    long rom_size = ftell(rom);
    rewind(rom);
    
    // Either only load what fits, or load all of the rom
    unsigned int load_size = rom_size < MAX_ROM_SIZE ? rom_size : MAX_ROM_SIZE;

    // Allocate space for ROM buffer
    // We are only going to read as much data as will fit in memory
    unsigned char *rom_buffer
            = (unsigned char*) malloc(sizeof(unsigned char) * load_size);

    if (!rom_buffer) {
        printf("Insufficient memory to load ROM! Stopping.");
        return EXIT_FAILURE;
    }

    fread(rom_buffer, sizeof(unsigned char), load_size, rom);

    // Copy rom to memory
    for(int i = 0; i < MAX_ROM_SIZE; ++i)
        memory[i + 512] = rom_buffer[i];

    free(rom_buffer);
    return EXIT_SUCCESS;
}

void Chip8::emulateCycle()
{
    // Fetch opcode
    opcode = memory[pc] << 8 | memory[pc + 1];
    // Decode opcode

    // switch (opcode) {
    // case /* constant-expression */:
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // }

    // Execute opcode
    // Update timers
}

void Chip8::setKeys()
{
}