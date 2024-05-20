#include <SDL2/SDL.h>
#include <stdio.h>
#include "headers/bricks.h"
#include "headers/allheaders.h"

int  brick_colours[4][3] = {{34, 139, 34}, {255, 215, 0}, {165, 42, 42}, {192, 192, 192}};

bricks initialize_brick(float  x, float  y, float  health_points, float  brick_width, float  brick_height, SDL_Renderer * renderer){
    bricks initializing_brick;
    initializing_brick.health_points = health_points;

    initializing_brick.rect.w = brick_width;
    initializing_brick.rect.h = brick_height;
    initializing_brick.rect.x = x;
    initializing_brick.rect.y = y;

    // initializing_brick.source_image.x = 100;
    // initializing_brick.source_image.y = 100;
    // initializing_brick.source_image.w = 100;
    // initializing_brick.source_image.h = 100;
    // 192, 192, 192 Silver
    // 165, 42, 42 Brown
    // 255, 215, 0 Gold
    // 34, 139, 34 Forest
    change_colour_bricks(&initializing_brick, renderer);
    initializing_brick.is_existing = true;
    return initializing_brick;
}


void change_health_point(bricks *current_brick){
    if(current_brick->health_points != 4){
        current_brick->health_points--;
    }
    if(current_brick->health_points == 0){
        current_brick->is_existing = false;
    }
}

void change_colour_bricks(bricks *current_brick, SDL_Renderer* renderer){
    SDL_Surface *surface = SDL_CreateRGBSurface(0, 200, 150, 32, 0, 0, 0, 0);
    if(current_brick->health_points == 1){
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 34, 139, 34));
    }
    else if(current_brick->health_points == 2){
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 215, 0));
    }
    else if(current_brick->health_points == 3){
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 165, 42, 42));
    }
    else if(current_brick->health_points == 4){
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 192, 192, 192));
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    current_brick->texture = texture;
}

void draw_bricks(bricks *bricks_list, int bricks_count, SDL_Renderer * renderer){
    for(int i = 0; i < bricks_count; i++){
        if(bricks_list[i].is_existing == true){
            SDL_RenderCopy(renderer, bricks_list[i].texture, NULL, &bricks_list[i].rect);
        }
    }
}

 