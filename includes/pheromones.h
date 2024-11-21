#ifndef PHEROMONES_H
#define PHEROMONES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#include "ants.h"

// struct that holds pheromones
typedef struct Pheromones {
    Color color; // color of each pheromone
    int size; // size of each
    Vector2 position; // position of each
    float strength; // strength of each which also determines size
} Pheromones;

void drawPheromone(float size, Color color, Vector2 position, float strength);

#endif