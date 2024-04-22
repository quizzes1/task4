#pragma once

typedef struct ball {
    SDL_Texture * texture;
    SDL_Rect hitbox;
    SDL_Rect source_image;
    int health_count;
    point speed;
    bool is_active;    
} ball;

ball initialize_ball(int x, int y, int radius, SDL_Renderer * renderer);
int check_collision(ball current_ball, SDL_Rect  current_rect, int flag);
ball update_ball_qualities(ball current_ball, int flag);
void draw_ball(SDL_Renderer * renderer, ball current_ball);
ball update_ball_position(ball current_ball, int x, int y);
int check_collision_borders(ball current_ball);