#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#include "ants.h"

// screen width and height
#define WIDTH 1080
#define HEIGHT 720

// grid variables
#define COLS 180
#define ROWS 120

void updateGrid();
void drawGrid();

#endif