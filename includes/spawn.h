#ifndef SPAWN_H
#define SPAWN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"

// struct that holds our spawn
typedef struct Spawn {
    Color color; // color of the spawn
    Vector2 position; // position of spawn
    int size; // size of spawn
} Spawn;

#endif