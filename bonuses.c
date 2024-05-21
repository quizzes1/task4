#include <stdio.h>
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
    if (!initializing_bonus_extra_life.image_texture){
        printf("Cannot download heart dropping image!");
        exit(0);
    }
    return initializing_bonus_extra_life;

}

broadthen_racket initialize_broadthen_racket_bonus(SDL_Renderer * renderer, SDL_Rect *rect_dropped){
    broadthen_racket initializing_bonus_broadthen_racket;
    initializing_bonus_broadthen_racket.speed.x = 0;
    initializing_bonus_broadthen_racket.speed.y = 1;

    initializing_bonus_broadthen_racket.drect.h = 50;
    initializing_bonus_broadthen_racket.drect.w = 50;
    initializing_bonus_broadthen_racket.drect.x = rect_dropped->x + rect_dropped->w/2;
    initializing_bonus_broadthen_racket.drect.y = rect_dropped->y + rect_dropped->h/2;

    TTF_Init();
    initializing_bonus_broadthen_racket.font = TTF_OpenFont("fonts_and_images/font.ttf", 100);
    
    if (!initializing_bonus_broadthen_racket.font){
        printf("Cannot download font!");
        exit(0);
    }

    SDL_Color text_colour;
    text_colour.r = 255;
    text_colour.g = 255;
    text_colour.b = 255;
    text_colour.a = SDL_ALPHA_OPAQUE;
    // char seconds[256];
    // sprintf(seconds, "Broadthen racket: %u", a);
    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(initializing_bonus_broadthen_racket.font, "11", text_colour, 600);
    SDL_Texture *broadthen_text = SDL_CreateTextureFromSurface(renderer, stext);

    initializing_bonus_broadthen_racket.texture = broadthen_text;


    initializing_bonus_broadthen_racket.image_texture = IMG_LoadTexture(renderer, "fonts_and_images/broadthen_racket_icon.png");

    if (!initializing_bonus_broadthen_racket.image_texture){
        printf("Cannot downaload heart dropping image!");
        exit(0);
    }

    initializing_bonus_broadthen_racket.text_rect.h = 100;
    initializing_bonus_broadthen_racket.text_rect.w = 300;
    initializing_bonus_broadthen_racket.text_rect.x = 1000;
    initializing_bonus_broadthen_racket.text_rect.y = 150;

    initializing_bonus_broadthen_racket.is_active = false;

    return initializing_bonus_broadthen_racket;
    
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

int check_collision_broadthen_racket(broadthen_racket *current_bonus, SDL_Rect *current_rect){
    if (current_bonus->drect.x <= current_rect->x + current_rect->w 
        && current_bonus->drect.x >= current_rect->x 
        && current_bonus->drect.y + current_bonus->drect.h > current_rect->y) 
    {
        current_bonus->is_active = true;
        return 1;
    }
    return 0;
}

int check_collision_broadthen_racket_border(broadthen_racket *current_bonus){
    if (current_bonus->drect.y + current_bonus->drect.h/2 == SCREEN_HEIGHT){
        return 1;
    }
    return 0;
}

void draw_bonus_extra_life(SDL_Renderer * renderer, extra_life * bonus){
    SDL_RenderCopy(renderer, bonus->image_texture, NULL, &bonus->drect);
}

void draw_bonus_broadthen_racket(SDL_Renderer * renderer, broadthen_racket * bonus){
    if(bonus->is_active == true){
        SDL_RenderCopy(renderer, bonus->texture, NULL, &bonus->text_rect);
    }
    else{
        SDL_RenderCopy(renderer, bonus->image_texture, NULL, &bonus->drect);
    }
}