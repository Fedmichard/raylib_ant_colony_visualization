#ifndef ANTS_H
#define ANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#include "foods.h"

#define MAX_ANTS 2000

typedef struct Ant {
    Vector2 direction; // direction vector of ants face
    Vector2 position; // position of each ant
    Food* food; // reference to the food it currently carries
    float speed; // speed of each ant
    float angle; // angle which defines direction
    float rotation_speed; // speed of rotation to create rotation delta
    bool carrying; // is currently carrying food
} Ant;

// Array of ants
extern Ant ants[MAX_ANTS];
// Ant texture
extern Texture2D ant_texture;

void forwardMovement(float delta_time);
void updateMovement(float rotation_delta, int width, int height);

#endif