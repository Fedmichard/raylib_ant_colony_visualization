#ifndef ANTS_H
#define ANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#include "foods.h"
#include "spawn.h"

#define MAX_ANTS 1000

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
    float sensing_radius;
    bool carrying; // is currently carrying food
} Ant;

// Array of ants
extern Ant ants[MAX_ANTS];
// Ant texture
extern Texture2D ant_texture;

void loadAnt(Ant* ant); // load ants
void drawAnt(); // draw all of our ants

void forwardMovement(float rotation_delta, float delta_time, Vector2 spawn); // keeps ants moving forward 
void backToSpawn(Ant* ant, Vector2 spawn);
void handleWallCollision(float rotation_delta, int width, int height); // update movement based on angle and direction

void getFood(Food* food, Spawn* spawn); // collect food

#endif