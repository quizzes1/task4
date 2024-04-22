#pragma once
typedef enum type {widthen_racket, extra_life/*, double_balls*/} type;

typedef struct bonus {
    SDL_Rect rect;
    point speed;
    bool is_falling;
    type bonus_type;
} bonus;


bonus initialize_bonus(type bonus_type);
void update_draw_bonus(SDL_Renderer* renderer, int dt, bonus current_bonus);
bonus destroy_bonus(bonus current_bonus);