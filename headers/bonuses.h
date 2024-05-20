#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "allheaders.h"

typedef struct extra_life {
    SDL_Rect drect;
    point speed;
    SDL_Texture *image_texture;
    bool is_active;
} extra_life;

void draw_bonus_extra_life(SDL_Renderer * renderer, extra_life * bonus);
extra_life initialize_extra_life_bonus(SDL_Renderer *renderer, SDL_Rect *rect_dropped);
int check_collision_extra_life(extra_life *current_bonus, SDL_Rect *current_rect);
int check_collision_extra_life_border(extra_life *current_bonus);