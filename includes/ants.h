#ifndef ANTS_H
#define ANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#include "foods.h"

#define MAX_ANTS 2000

// Structure that holds all of our ant information
// direction represents the direction the ant is facing
// position represents its pos
// speed represents its speed
// angle represents the angle its facing
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

void loadAnt(Ant* ant); // load ants

void forwardMovement(float rotation_delta, float delta_time); // keeps ants moving forward 
void handleWallCollision(float rotation_delta, int width, int height); // update movement based on angle and direction


void getFood(Food* food); // collect food

#endif