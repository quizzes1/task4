#pragma once
#include <SDL2/SDL_ttf.h>

typedef struct widgets{
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect drect;
    SDL_Rect image_rect;
    SDL_Texture* image_texture;
} widgets;

widgets initialize_widgets_health(SDL_Renderer * renderer);
void draw_widget_health(widgets *current_widget, SDL_Renderer * renderer, int health_count);
void draw_widget_lose_screen(widgets *current_widget, SDL_Renderer * renderer);
widgets initialize_loser_screen(SDL_Renderer * renderer);
