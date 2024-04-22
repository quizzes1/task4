#pragma once

typedef struct racket{
    SDL_Rect rect;
    SDL_Rect source_image;
    point speed;
    SDL_Texture * tex;
} racket;

racket initialize_racket(SDL_Renderer * renderer);
racket move_racket(racket current_racket, int flag);
void draw_racket(SDL_Renderer * renderer, racket current_racket);