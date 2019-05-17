#include <iostream>
#include <fstream>
#include "chip8.hpp"
using namespace std;

void Chip8::initialize()
{
}

int Chip8::loadGame(char *filename)
{
    ifstream game;
    game.open(filename);
    if (game.fail()) {
        // File could not be opened
        return EXIT_FAILURE;
    }
    game.read((char*)memory, 4096);
    return EXIT_SUCCESS;
}

void Chip8::emulateCycle()
{
}

void Chip8::setKeys()
{
}