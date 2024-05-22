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

widgets initialize_loser_screen(SDL_Renderer * renderer){
    widgets initializing_widget;
    TTF_Init();
    initializing_widget.font = TTF_OpenFont("fonts_and_images/font.ttf", 100);

    if (!initializing_widget.font){
        printf("Cannot download font!");
        exit(0);
    }

    initializing_widget.image_texture = IMG_LoadTexture(renderer, "fonts_and_images/lose_icon.png");

    if (!initializing_widget.image_texture){
        printf("Cannot download lose image!");
        exit(0);
    }

    SDL_Color text_colour;
    text_colour.r = 255;
    text_colour.g = 255;
    text_colour.b = 255;
    text_colour.a = SDL_ALPHA_OPAQUE;

    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(initializing_widget.font, "GAME OVER!\npress \nescape to quit\n0 to menu", text_colour, 900);
    SDL_Texture *lost_text = SDL_CreateTextureFromSurface(renderer, stext);
    
    initializing_widget.texture = lost_text;
    initializing_widget.drect.h = 150;
    initializing_widget.drect.w = 400;
    initializing_widget.drect.x = SCREEN_WIDTH/2-initializing_widget.drect.w;
    initializing_widget.drect.y = SCREEN_HEIGHT/2 - initializing_widget.drect.h;

    initializing_widget.image_rect.h = 200;
    initializing_widget.image_rect.w = 200;
    initializing_widget.image_rect.x = 1000;
    initializing_widget.image_rect.y = 180;

    return initializing_widget;
}

widgets initialize_winner_screen(SDL_Renderer * renderer){
    widgets initializing_widget;
    TTF_Init();
    initializing_widget.font = TTF_OpenFont("fonts_and_images/font.ttf", 100);

    if (!initializing_widget.font){
        printf("Cannot download font!");
        exit(0);
    }

    initializing_widget.image_texture = IMG_LoadTexture(renderer, "fonts_and_images/win.png");

    if (!initializing_widget.image_texture){
        printf("Cannot download win image!");
        exit(0);
    }

    SDL_Color text_colour;
    text_colour.r = 255;
    text_colour.g = 255;
    text_colour.b = 255;
    text_colour.a = SDL_ALPHA_OPAQUE;

    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(initializing_widget.font, "YOU WIN!\npress \nescape to quit\n0 to menu", text_colour, 900);
    SDL_Texture *win_text = SDL_CreateTextureFromSurface(renderer, stext);
    
    initializing_widget.texture = win_text;
    initializing_widget.drect.h = 150;
    initializing_widget.drect.w = 400;
    initializing_widget.drect.x = SCREEN_WIDTH/2-initializing_widget.drect.w;
    initializing_widget.drect.y = SCREEN_HEIGHT/2 - initializing_widget.drect.h;

    initializing_widget.image_rect.h = 200;
    initializing_widget.image_rect.w = 200;
    initializing_widget.image_rect.x = 1000;
    initializing_widget.image_rect.y = 180;

    return initializing_widget;
}

widgets initialize_main_title(SDL_Renderer * renderer){
    widgets initializing_widget;
    TTF_Init();
    initializing_widget.font = TTF_OpenFont("fonts_and_images/font.ttf", 100);

    if (!initializing_widget.font){
        printf("Cannot download font!");
        exit(0);
    }
    SDL_Color text_colour;
    text_colour.r = 255;
    text_colour.g = 255;
    text_colour.b = 255;
    text_colour.a = SDL_ALPHA_OPAQUE;

    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(initializing_widget.font, "ARKANOID", text_colour, 900);
    SDL_Texture *title_text = SDL_CreateTextureFromSurface(renderer, stext);
    
    initializing_widget.texture = title_text;
    initializing_widget.drect.h = 150;
    initializing_widget.drect.w = 400;
    initializing_widget.drect.x = SCREEN_WIDTH/2-200;
    initializing_widget.drect.y = SCREEN_HEIGHT/2 - 200;

    return initializing_widget;
}

void update_main_title(SDL_Renderer * renderer, widgets * current_widget, SDL_Color * col){

    SDL_Color text_colour;
    text_colour.r = col->r;
    text_colour.g = col->g;
    text_colour.b = col->b;
    text_colour.a = SDL_ALPHA_OPAQUE;

    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(current_widget->font, "ARKANOID", text_colour, 900);
    SDL_Texture *title_text = SDL_CreateTextureFromSurface(renderer, stext);
    
    current_widget->texture = title_text;
}

void draw_main_title(SDL_Renderer *renderer, widgets * current_widget){
    SDL_RenderCopy(renderer, current_widget->texture, NULL, &current_widget->drect); 
}

void draw_widget_lose_screen(widgets *current_widget, SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, current_widget->texture, NULL, &current_widget->drect);
    SDL_RenderCopy(renderer, current_widget->image_texture, NULL, &current_widget->image_rect);
}

void draw_widget_win_screen(widgets *current_widget, SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, current_widget->texture, NULL, &current_widget->drect);
    SDL_RenderCopy(renderer, current_widget->image_texture, NULL, &current_widget->image_rect);
}

void draw_widget_health(widgets *current_widget, SDL_Renderer * renderer, int health_count){
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