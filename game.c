#include <stdio.h>
#include <SDL2/SDL.h>
#include "headers/allheaders.h"
#include "headers/ball.h"
#include "headers/bonuses.h"
#include "headers/bricks.h"
#include "headers/racket.h"
#include "headers/widgets.h"


int bricks_qualities_list[9][6] = {{300, 105, 2, 100, 50}, {450, 105, 3, 100, 50}, {600, 105, 1, 100, 50}, {300, 205, 1, 100, 50}, {450, 205, 1, 100, 50}, {600, 205, 1, 100, 50}, 
    {300, 305, 1, 100, 50}, {450, 305, 1, 100, 50}, {600, 305, 4, 100, 50}
};
// parser?
int main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
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
    int health_count = 3;
    racket main_racket = initialize_racket(renderer);
    ball main_ball = initialize_ball(main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h, 3, renderer);
    bricks bricks_list[9];
    for(int i = 0; i < 9; i++){
        bricks_list[i] = initialize_brick(bricks_qualities_list[i][0], bricks_qualities_list[i][1], bricks_qualities_list[i][2], bricks_qualities_list[i][3], bricks_qualities_list[i][4], renderer);
    }
    Uint32 last_ticks = 0;
    widgets health_widget = initialize_widgets_health(renderer);

    while(true){
        
        if (health_count <= 0){
            printf("\nYou've lost! ");
            break;
        }

        if(SDL_GetTicks() - last_ticks < INPUT_DELAY){
            continue;
        }
        else{
            last_ticks = SDL_GetTicks();
        }

        draw_widget(&health_widget, renderer, health_count);    
        draw_racket(renderer, main_racket);
        draw_ball(renderer, main_ball);
        draw_bricks(bricks_list, 9, renderer);

        if(main_ball.is_active == true){
            for(int i = 0; i < 9; i++){
                if(bricks_list[i].is_existing == true){
                    check_collision(&main_ball, &bricks_list[i].rect, 2);
                        if (main_ball.is_changed == true){          
                            main_ball.is_changed = false;
                            change_health_point(&bricks_list[i]);
                            change_colour_bricks(&bricks_list[i], renderer);
                        }
                }
            }
            int is_collision_with_borders = check_collision_borders(main_ball);
            check_collision(&main_ball, &main_racket.rect, 1);
            
            if (is_collision_with_borders == 1){
                main_ball.speed.x *= -1;
                main_ball.hitbox.x += 5;
            }else if (is_collision_with_borders == 2) {
                main_ball.speed.y *= -1;
                main_ball.hitbox.y += 5;
            }
            else if (is_collision_with_borders == 3) {
                main_ball.speed.x *= -1;
                main_ball.hitbox.x -=5;
            }
            else if  (is_collision_with_borders == 4){
                main_ball.is_active = false;
                health_count--;
                main_ball = initialize_ball(main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h, 3, renderer);
                continue;
            }
            
            main_ball.hitbox.x += main_ball.speed.x;
            main_ball.hitbox.y += main_ball.speed.y;
        }

        if ( SDL_PollEvent ( &window_event ) ){
            
            if ( SDL_QUIT == window_event.type ){
                break;
            }
            if ( SDL_KEYDOWN == window_event.type){
                   switch(window_event.key.keysym.sym){
                        case SDLK_a:
                            if(main_racket.rect.x == 0){
                                continue;
                            }
                            else{
                                move_racket(&main_racket, 2);
                                if(main_ball.is_active == false){    
                                    update_ball_position(&main_ball, main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h);
                                }
                            }
                            break;
    
                        case SDLK_d:
                            if(main_racket.rect.x+main_racket.rect.w == SCREEN_WIDTH){
                                continue;
                            }
                            else{
                                move_racket(&main_racket, 1);
                                if(main_ball.is_active == false){
                                    update_ball_position(&main_ball, main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h);
                                }
                            }
                            break;
                        case SDLK_SPACE:
                            if(main_ball.is_active == false){
                                main_ball.is_active = true;
                            }
                            break;
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