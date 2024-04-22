#include <stdio.h>
#include <SDL2/SDL.h>
#include "headers/allheaders.h"
#include "headers/ball.h"
#include "headers/bonuses.h"
#include "headers/bricks.h"
#include "headers/racket.h"
#include "headers/widgets.h"
                                                                                                                 
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

    racket main_racket = initialize_racket(renderer);
    ball main_ball = initialize_ball(main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h, 3, renderer);
    while(true){
        draw_racket(renderer, main_racket);
        draw_ball(renderer, main_ball);
        if(main_ball.is_active == true){
            bool is_collision_with_racket = check_collision(main_ball, main_racket.rect, 1);
            // int is_collision_with_bricks =
            bool is_collision_with_borders = check_collision_borders(main_ball);
            if(is_collision_with_racket == 1){
                main_ball.speed.y *= -1;
                main_ball.hitbox.y -= 5;
                printf("Collision! ");
            } else if (is_collision_with_borders == 1){
                main_ball.speed.x *= -1;
                main_ball.speed.y *= -1;
                printf("Collision! (border) ");
            }else if (is_collision_with_borders == 2) {
                main_ball.is_active = false;
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
                            main_racket = move_racket(main_racket, 2);
                            if(main_ball.is_active == false){    
                                main_ball = update_ball_position(main_ball, main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h);
                            }
                            break;
                        case SDLK_d:
                            main_racket = move_racket(main_racket, 1);
                            if(main_ball.is_active == false){
                                main_ball = update_ball_position(main_ball, main_racket.rect.x+main_racket.rect.w/3+5, main_racket.rect.y-main_racket.rect.h);
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