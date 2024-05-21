#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct button{
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect drect;
    SDL_Color main_col;
    SDL_Color highlight_col;
    bool is_selected;
} button;
