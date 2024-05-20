#include <SDL2/SDL.h>
#include "headers/allheaders.h"
#include "headers/racket.h"

racket initialize_racket(SDL_Renderer * renderer){
    racket initializing_racket;

    initializing_racket.rect.w = 100;
    initializing_racket.rect.h = 25;
    initializing_racket.rect.x = SCREEN_WIDTH/2;
    initializing_racket.rect.y = SCREEN_HEIGHT-initializing_racket.rect.h-1;
    initializing_racket.speed.x = 20;

    // initializing_racket.source_image.x = 100;
    // initializing_racket.source_image.w = 100;
    // initializing_racket.source_image.h = 100;
    // initializing_racket.source_image.y = 100;
    SDL_Surface *surface = SDL_CreateRGBSurface(0, 200, 150, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    initializing_racket.tex = texture;
    return initializing_racket;
}

void move_racket(racket *current_racket, float flag){
    if (flag == 1){
        current_racket->rect.x += current_racket->speed.x;
    }
    else if (flag == 2){
        current_racket->rect.x -= current_racket->speed.x;
    }
}

void draw_racket(SDL_Renderer * renderer, racket current_racket){
    SDL_RenderCopy(renderer, current_racket.tex, NULL, &current_racket.rect);
}