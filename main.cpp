#include <stdio.h>
#include <SDL2/SDL.h>
#include "chip8.hpp"

Chip8 chip8;

SDL_Window *window;
SDL_Renderer *renderer;


void init_SDL()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        printf("Can't initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Chip-8", 0, 0, SCREEN_WIDTH * SCALE, 
            SCREEN_HEIGHT * SCALE, 0);
    if (window == NULL) {
        printf("Can't create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, 
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Can't initialize renderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Set up linear texture filtering
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Linear texture rendering not enabled.\n");
    }
}

void drawGraphics()
{
}

void drawGraphicsTerminal()
{
    // For debugging purposes, draw graphics to the terminal.
    for (int c = 0; c < SCREEN_WIDTH; c++) {
        for (int r = 0; r < SCREEN_HEIGHT; r++)
            printf(chip8.gfx[(r*c)+c] == 1 ? "█" : " ");
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Chip-8: No filename given...\n");
        return EXIT_SUCCESS;
    } else {
        // Initialize Chip8 processor
        chip8.initialize();
        // Load rom
        if (chip8.loadGame(argv[1]) == EXIT_FAILURE) {
            exit(EXIT_FAILURE);
        } else {
            printf("Chip-8: Loaded rom");
        }
    }

    // Initialize graphics
    init_SDL();

    // Initialize Input

    SDL_Event event;
    bool quit = false;
    while (!quit){
        chip8.emulateCycle();
        if (chip8.drawFlag) drawGraphicsTerminal();
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
            if (event.type == SDL_KEYDOWN){
                quit = true;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
    }

    // for (;;) {
    //     chip8.emulateCycle();
    //     if (chip8.drawFlag)
    //         drawGraphics();
    //     chip8.setKeys();
    // }

    return 0;
}