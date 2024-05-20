#include "headers/bonuses.h"

extra_life initialize_extra_life_bonus(SDL_Renderer *renderer, SDL_Rect *rect_dropped){
    extra_life initializing_bonus_extra_life;

    initializing_bonus_extra_life.speed.x = 0;
    initializing_bonus_extra_life.speed.y = 1;

    initializing_bonus_extra_life.drect.h = 50;
    initializing_bonus_extra_life.drect.w = 50;
    initializing_bonus_extra_life.drect.x = rect_dropped->x + rect_dropped->w/2;
    initializing_bonus_extra_life.drect.y = rect_dropped->y + rect_dropped->h/2;

    initializing_bonus_extra_life.image_texture = IMG_LoadTexture(renderer, "fonts_and_images/extra_life_icon.png");
    initializing_bonus_extra_life.is_active = false;
    return initializing_bonus_extra_life;

}


int check_collision_extra_life(extra_life *current_bonus, SDL_Rect *current_rect){
    if (current_bonus->drect.x <= current_rect->x + current_rect->w 
        && current_bonus->drect.x >= current_rect->x 
        && current_bonus->drect.y + current_bonus->drect.h > current_rect->y) 
    {
        return 1;
    }
    return 0;
}

int check_collision_extra_life_border(extra_life *current_bonus){
    if (current_bonus->drect.y + current_bonus->drect.h/2 == SCREEN_HEIGHT){
        return 1;
    }
    return 0;
}

void draw_bonus_extra_life(SDL_Renderer * renderer, extra_life * bonus){
    SDL_RenderCopy(renderer, bonus->image_texture, NULL, &bonus->drect);
}

