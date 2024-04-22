#include <SDL2/SDL.h>
#include "headers/allheaders.h"
#include "headers/bonuses.h"

bonus initialize_bonus(type bonus_type){
    bonus initializing_bonus;
    initializing_bonus.rect.x = 100;
    initializing_bonus.rect.y = 100;
    initializing_bonus.rect.w = 100;
    initializing_bonus.rect.h = 100;
    
    initializing_bonus.speed.x = 100;
    initializing_bonus.speed.y = 100;

    initializing_bonus.bonus_type = bonus_type;

    return initializing_bonus;
}

void update_draw_bonus(SDL_Renderer* renderer, int dt, bonus current_bonus) {
	if (current_bonus.is_falling) {
		current_bonus.rect.y += current_bonus.speed.y;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &current_bonus.rect);
		bonusCheckCollision(&current_bonus);
	}
}

bonus destroy_bonus(bonus current_bonus){
    current_bonus.is_falling = false;
    return current_bonus;
}