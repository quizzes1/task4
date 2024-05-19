#pragma once

typedef struct ball {
    SDL_Texture * texture;
    SDL_Rect hitbox;
    SDL_Rect source_image;
    point speed;
    bool is_active;    
    bool is_changed;
} ball;

ball initialize_ball(float  x, float  y, float  radius, SDL_Renderer * renderer);
void check_collision(ball *current_ball, SDL_Rect  *current_rect, float  flag);
void update_ball_qualities(ball *current_ball, float  flag);
void draw_ball(SDL_Renderer * renderer, ball current_ball);
void update_ball_position(ball *current_ball, float  x, float  y);
int  check_collision_borders(ball current_ball);