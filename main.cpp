#include <stdio.h>
#include <SDL2/SDL.h>
#include "chip8.hpp"

Chip8 chip8;

SDL_Window *window;
SDL_Renderer *renderer;

#define SCREEN_HEIGHT 32
#define SCREEN_WIDTH 64
#define SCALE 8

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

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("No filename given...\n");
        return EXIT_SUCCESS;
    }

    // Initialize graphics
    init_SDL();

    // Initialize Input

    // Initialize Chip8 processor
    chip8.initialize();
    chip8.loadGame(argv[1]);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
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