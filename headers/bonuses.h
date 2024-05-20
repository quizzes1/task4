#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/allheaders.h"

typedef struct extra_life {
    SDL_Rect drect;
    SDL_Rect srect;
    point speed;
} extra_life;