#include <SDL2/SDL.h>
#include <stdio.h>
#include "headers/bricks.h"
#include "headers/allheaders.h"

int brick_colours[4][3] = {{34, 139, 34}, {255, 215, 0}, {165, 42, 42}, {192, 192, 192}};

bricks initialize_brick(int x, int y, int health_points, int brick_width, int brick_height, SDL_Renderer * renderer){
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

    SDL_Surface *surface = SDL_CreateRGBSurface(0, 200, 150, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    initializing_brick.texture = texture;
    initializing_brick.is_existing = true;
    return initializing_brick;
}


bricks change_health_point(bricks current_brick){
    // printf("1");
    if(current_brick.health_points != 4){
        current_brick.health_points--;
    }
    if(current_brick.health_points == 0){
        current_brick.is_existing = false;
    }
    printf("1");
    printf("\n%d %d", current_brick.rect.x, current_brick.rect.y);
    return current_brick;
}

void draw_bricks(bricks bricks_list[], int bricks_count, SDL_Renderer * renderer){
    for(int i = 0; i < bricks_count; i++){
        if(bricks_list[i].is_existing){
            SDL_RenderCopy(renderer, bricks_list[i].texture, NULL, &bricks_list[i].rect);
        }
    }
}

