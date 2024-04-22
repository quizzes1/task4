#pragma once

typedef struct bricks{
    SDL_Texture * texture;
    SDL_Rect rect;
    SDL_Rect source_image;
    int health_points;
    int is_existing;
} bricks;

bricks initialize_brick(point coordinates, int health_points, int rect_width, int brick_width, int brick_height);
bricks change_health_point(bricks current_brick);
void draw_bricks(bricks bricks_list[], int bricks_count, SDL_Renderer * renderer);


// 192, 192, 192 Silver
// 165, 42, 42 Brown
// 255, 215, 0 Gold
// 34, 139, 34 Forest Green