#include <SDL2/SDL.h>
#include <stdio.h>
#include "bricks.h"
#include "allheaders.h"

int brick_colours[4][3] = {{34, 139, 34}, {255, 215, 0}, {165, 42, 42}, {192, 192, 192}};

bricks initialize_brick(point coordinates, int health_points, int rect_width, int brick_width, int brick_height){
    bricks initializing_brick;
    initializing_brick.health_points = health_points;

    initializing_brick.rect.w = brick_width;
    initializing_brick.rect.h = brick_height;
    initializing_brick.rect.x = coordinates.x;
    initializing_brick.rect.y = coordinates.y;

    // initializing_brick.source_image.x = 100;
    // initializing_brick.source_image.y = 100;
    // initializing_brick.source_image.w = 100;
    // initializing_brick.source_image.h = 100;

    initializing_brick.is_existing = true;
    return initializing_brick;
}


bricks change_health_point(bricks current_brick){
    if(current_brick.health_points != 3){
        current_brick.health_points--;
    }
    if(current_brick.health_points == -1){
        current_brick.is_existing = false;
    }

    return current_brick;
}

void draw_bricks(bricks bricks_list[], int bricks_count, SDL_Renderer * renderer){
    for(int i = 0; i < bricks_count; i++){
        if(bricks_list[i].is_existing){
            SDL_SetRenderDrawColor(renderer, brick_colours[bricks_list[i].health_points][0], brick_colours[bricks_list[i].health_points][1], brick_colours[bricks_list[i].health_points][2], SDL_ALPHA_OPAQUE);
            SDL_RendererFillRect(renderer, &bricks_list[i].rect);
        }
    }
}

