#include <stdio.h>
#include <SDL2/SDL.h>
#include "headers/allheaders.h"
#include "headers/ball.h"

ball initialize_ball(int x, int y, int radius, SDL_Renderer * renderer){
    ball initializing_ball;

    int health_count = 3;

    initializing_ball.hitbox.x = x;
    initializing_ball.hitbox.y = y;
    initializing_ball.hitbox.w = 25;
    initializing_ball.hitbox.h = 25;

    // initializing_ball.source_image.x = 100;
    // initializing_ball.source_image.y = 100;
    // initializing_ball.source_image.w = 100;
    // initializing_ball.source_image.h = 100;

    initializing_ball.speed.x = -1;
    initializing_ball.speed.y = -1;

    SDL_Surface *surface = SDL_CreateRGBSurface(0, 200, 150, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    initializing_ball.texture = texture;
    initializing_ball.is_active = false;
    return initializing_ball;
}  


int check_collision_borders(ball current_ball){
    if(
        (current_ball.hitbox.x == 0)
        || (current_ball.hitbox.y == 0)
        || (current_ball.hitbox.x+current_ball.hitbox.w == SCREEN_WIDTH)
    ){
        return 1;
    }
    else if (current_ball.hitbox.y + current_ball.hitbox.h/2 == SCREEN_HEIGHT){
        return 2;
    } else{
        return 0;
    }
}

int check_collision(ball current_ball, SDL_Rect  current_rect, int flag){
    if (flag == 1){
        if (current_ball.hitbox.x <= current_rect.x + current_rect.w 
                && current_ball.hitbox.x > current_rect.x 
                && current_ball.hitbox.y > current_rect.y) {
                return 1;
        }
    }
    if(flag == 2){
        if (current_ball.hitbox.x >= current_rect.x 
                && current_ball.hitbox.x <= current_rect.x + current_rect.w
                && current_ball.hitbox.y - current_ball.hitbox.h <= current_rect.y + current_rect.h
                && current_ball.hitbox.y - current_ball.hitbox.h >= current_rect.y) {
                current_ball.speed.y *= -1;
                current_ball.hitbox.y += 5;
                return 1;
            }

            else if (current_ball.hitbox.x >= current_rect.x
                && current_ball.hitbox.x <= current_rect.x + current_rect.w
                && current_ball.hitbox.y + current_ball.hitbox.h >= current_rect.y
                && current_ball.hitbox.y + current_ball.hitbox.h <= current_rect.y + current_rect.h) {
                current_ball.speed.y *= -1;
                current_ball.hitbox.y -= 5;
                return 1;
            }

            // Check by horizontal
            else if (current_ball.hitbox.y >= current_rect.y
                && current_ball.hitbox.y <= current_rect.y + current_rect.h
                && current_ball.hitbox.x - current_ball.hitbox.w <= current_rect.x + current_rect.w
                && current_ball.hitbox.x - current_ball.hitbox.w >= current_rect.x) {
                current_ball.speed.x *= -1;
                current_ball.hitbox.x += 5;
                return 1;
            }

            else if (current_ball.hitbox.y >= current_rect.y
                && current_ball.hitbox.y <= current_rect.y + current_rect.h
                && current_ball.hitbox.x + current_ball.hitbox.w >= current_rect.x
                && current_ball.hitbox.x + current_ball.hitbox.w <= current_rect.x + current_rect.w) {
                current_ball.speed.x *= -1;
                current_ball.hitbox.x += 5;
                return 1;
            }
    }
}

ball update_ball_qualities(ball current_ball, int flag){
    if (flag == 1){
        current_ball.source_image.x = 200;
        current_ball.source_image.w = 200;
        current_ball.source_image.h = 200;
        current_ball.source_image.y = 200;
        
        current_ball.speed.x += 100;
        current_ball.speed.y += 100;
    }
    else if (flag == 1){
        current_ball.source_image.x = 100;
        current_ball.source_image.w = 100;
        current_ball.source_image.h = 100;
        current_ball.source_image.y = 100;
        
        current_ball.speed.x -= 100;
        current_ball.speed.y -= 100;
    }
    return current_ball;
}

ball update_ball_position(ball current_ball, int x, int y){
    current_ball.hitbox.x = x;
    current_ball.hitbox.y = y;
    return current_ball;
}

void draw_ball(SDL_Renderer * renderer, ball current_ball){
    SDL_RenderCopy(renderer, current_ball.texture, NULL, &current_ball.hitbox);
}