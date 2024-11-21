#ifndef FOODS_H
#define FOODS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#include "spawn.h"

#define MAX_FOOD 500

// All of our food information
typedef struct Food {
    Vector2 position; // Position of the food
    float size; // size of each food
    Color color; // color of each food
    bool taken; // whether or not the food is currently equipped
    bool active;
} Food;

extern Food foods[MAX_FOOD]; // array of food structs

void loadFood(Food* food); // loads all of our initial food 
void depositFood(Spawn* spawn); // deposit food to spawn

#endif