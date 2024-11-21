#include "foods.h"

Food foods[MAX_FOOD];

// Starting food values

void loadFood(Food* food) {
    for (int i = 0; i < sizeof(foods) / sizeof(foods[0]); i++) {
        foods[i].position.x = food->position.x + GetRandomValue(0, 200); // random x position assigned within range of org spawn
        foods[i].position.y = food->position.y + GetRandomValue(0, 200); // random y position assigned within range of org spawn
        foods[i].color = food->color; // color of each food
        foods[i].size = food->size; // size of each food
        foods[i].taken = food->taken; // taken is deafult
        foods[i].active = food->active;
    }
}

void drawFood() {
    for (int i = 0; i < (sizeof(foods) / sizeof(foods[0])); i++) {
        if (!foods[i].active) continue;  
        DrawCircle(foods[i].position.x, foods[i].position.y, foods[i].size, foods[i].color);
    }
}