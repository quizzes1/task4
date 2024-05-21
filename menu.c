#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include "headers/allheaders.h"
#include "headers/buttons.h"
#include "headers/widgets.h"

int colors[10][3] = {{255, 0, 0}, {255, 20, 147}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}, {255, 69, 0}, {0, 255, 0}, {138, 43, 226}, {0, 0, 255}, {255, 255, 255}};
// int bricks_qualities_list[level_count_bricks][6] = {{300, 105, 2, 100, 50}, {450, 105, 3, 100, 50}, {600, 105, 1, 100, 50}, {300, 205, 1, 100, 50}, {450, 205, 1, 100, 50}, {600, 205, 1, 100, 50}, 
//     {300, 305, 1, 100, 50}, {450, 305, 1, 100, 50}, {600, 305, 4, 100, 50}
// };
// int bricks_qualities_list[level_count_bricks][6] = {{300, 105, 2, 100, 50}, {450, 105, 3, 100, 50}, {600, 105, 1, 100, 50}, {300, 205, 1, 100, 50}, {450, 205, 1, 100, 50}, {600, 205, 1, 100, 50}, 
//     {300, 305, 1, 100, 50}, {450, 305, 1, 100, 50}, {600, 305, 4, 100, 50}
// };
int bricks_qualities_list[level_count_bricks][6] = {
    {300, 105, 2, 100, 50}, {450, 105, 3, 100, 50}, {600, 105, 1, 100, 50}, {300, 205, 1, 100, 50}, {450, 205, 1, 100, 50}, {600, 205, 1, 100, 50}, {300, 305, 1, 100, 50}, {450, 305, 1, 100, 50}, {600, 305, 4, 100, 50},
    {150, 105, 1, 100, 50}, {750, 105, 4, 100, 50}, {900, 105, 3, 100, 50}, {150, 205, 2, 100, 50}, {750, 205, 4, 100, 50}, {900, 205, 3, 100, 50}, {150, 305, 1, 100, 50}, {750, 305, 4, 100, 50}, {900, 305, 4, 100, 50}
};
int main(int argc, char *argv[]){
    srand(time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("MENU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window){
        printf("Couldn't create window!");
        return 1;
    }
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL){
        printf("Couldn't create renderer!");
        return 1;
    }
    SDL_SetRenderDrawColor(renderer, 85, 85, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderPresent(renderer);

    SDL_Event window_event;
    point coordinates_buttons;
    coordinates_buttons.x = SCREEN_WIDTH/2-150;
    coordinates_buttons.y = SCREEN_HEIGHT/2-50;
    button start_button = initialize_button(renderer, "START", coordinates_buttons);
    coordinates_buttons.y += 100;
    button levels_button = initialize_button(renderer, "LEVELS", coordinates_buttons);
    coordinates_buttons.y += 100;
    button exit_button = initialize_button(renderer, "eXIT", coordinates_buttons);
    widgets main_title = initialize_main_title(renderer);
    clock_t ticks = clock();

    while(true){
        SDL_Rect mouse_point;
        mouse_point.h = 1;
        mouse_point.w = 1;
        SDL_GetMouseState(&mouse_point.x, &mouse_point.y);

        start_button = update_button(renderer, start_button, mouse_point);
        draw_button(&start_button, renderer);
        levels_button = update_button(renderer, levels_button, mouse_point);
        draw_button(&levels_button, renderer);
        exit_button = update_button(renderer, exit_button, mouse_point);
        draw_button(&exit_button, renderer);
        int current_col_index = rand()%10;
        SDL_Color current_col;
        current_col.r = colors[current_col_index][0];
        current_col.g = colors[current_col_index][1];
        current_col.b = colors[current_col_index][2];
        if((clock()-ticks)/CLOCKS_PER_SEC > 1){
            update_main_title(renderer, &main_title, &current_col);
            ticks = clock();
        }
        draw_main_title(renderer, &main_title);

        if ( SDL_PollEvent ( &window_event ) ){
            if ( SDL_QUIT == window_event.type ){
                break;
            }
            if ( SDL_MOUSEBUTTONUP == window_event.type){
                if (window_event.button.button == SDL_BUTTON_LEFT){
                    if(start_button.is_selected == true){
                        printf("start\n");
                    }
                    else if(exit_button.is_selected == true){
                        break;
                    }
                    else if (levels_button.is_selected == true){
                        printf("levels\n");
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return EXIT_SUCCESS;
}