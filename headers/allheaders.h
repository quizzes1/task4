#pragma once
#include <math.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
typedef enum bool {false, true} bool;
typedef enum direction{left, right, up, down} direction;

typedef struct point {
    float x;
    float y;
} point;

typedef struct rgb {
    int r;
    int g;
    int b;
} rgb;
