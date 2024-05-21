#include "headers/buttons.h"
#include "headers/allheaders.h"

button initialize_button(SDL_Renderer * renderer){
    button initializing_button;
    TTF_Init();
    initializing_button.font = TTF_OpenFont("fonts_and_images/font.ttf", 100);
    if (!initializing_button.font){
        printf("Cannot download font on button!");
        exit(0);
    }
    SDL_Color text_colour;
    text_colour.r = 255;
    text_colour.g = 255;
    text_colour.b = 255;
    text_colour.a = SDL_ALPHA_OPAQUE;

    SDL_Surface *stext = TTF_RenderText_Blended_Wrapped(initializing_button.font, "Health points", text_colour, 600);
    SDL_Texture *health_text = SDL_CreateTextureFromSurface(renderer, stext);
}