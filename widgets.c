#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "headers/widgets.h"
#include "headers/allheaders.h"

widgets initialize_widgets_health(SDL_Renderer * renderer){
    widgets initializing_widget;
    TTF_Init();
    initializing_widget.font = TTF_OpenFont("fonts_and_images/font.ttf", 100);

    if (!initializing_widget.font){
        printf("Cannot download font!");
        exit(0);
    }

    initializing_widget.image_texture = IMG_LoadTexture(renderer, "fonts_and_images/heart.png");

    if (!initializing_widget.image_texture){
        printf("Cannot downaload heart image!");
        exit(0);
    }

    SDL_Color text_colour;
    text_colour.r = 255;
    text_colour.g = 255;
    text_colour.b = 255;
    text_colour.a = SDL_ALPHA_OPAQUE;

    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(initializing_widget.font, "Health points", text_colour, 600);
    SDL_Texture *health_text = SDL_CreateTextureFromSurface(renderer, stext);
    
    initializing_widget.texture = health_text;
    initializing_widget.drect.h = 100;
    initializing_widget.drect.w = 300;
    initializing_widget.drect.x = 1000;
    initializing_widget.drect.y = 0;

    initializing_widget.image_rect.h = 50;
    initializing_widget.image_rect.w = 50;
    initializing_widget.image_rect.x = 1000;
    initializing_widget.image_rect.y = 100;



    return initializing_widget;
}

void draw_widget(widgets *current_widget, SDL_Renderer * renderer, int health_count){
    SDL_RenderCopy(renderer, current_widget->texture, NULL, &current_widget->drect);
    for(int i = 1; i <= health_count; i++){
        SDL_Rect new_rect;
        new_rect.h = current_widget->image_rect.h;
        new_rect.w = current_widget->image_rect.w;
        new_rect.x = current_widget->image_rect.x + 30*i;
        new_rect.y = current_widget->image_rect.y;
        SDL_RenderCopy(renderer, current_widget->image_texture, NULL, &new_rect);
    }
}