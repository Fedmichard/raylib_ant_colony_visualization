#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ants.h"
#include "foods.h"
#include "spawn.h"
#include "pheromones.h"

// screen width and height
#define WIDTH 1080
#define HEIGHT 720

// grid variables
#define COLS 108
#define ROWS 72
#define DECAY_RATE 0.01f

const int cell_width = WIDTH / COLS;
const int cell_height = HEIGHT / ROWS;

// Time Variables
float delta_time;
float rotation_delta;

//------------------------------------------------------------------------------------
// Program main entry point
// Compile with GCC Compiler
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(WIDTH, HEIGHT, "Ant Colony Optimization"); // Windows

    // Set our game to run at inf frames
    SetTargetFPS(-1);

    // grid
    // float pheromoneGrid[GRID_WIDTH][GRID_HEIGHT] = { 0 };

    // define base spawn information
    Spawn spawn = {
        .color = RED,
        .position = { WIDTH / 2, HEIGHT / 2 }, 
        .size = 10.0f
    };

    // load ant texture
    ant_texture = LoadTexture("../resources/ant.png");
    // defining base ant information
    Ant ant = {
        .position = spawn.position, // position always starts at the spawn per ant
        .direction = { 0.0f, 0.0f }, // Beginning direction of each ant
        .angle = 0.0f, // beginning angle
        .speed = 100.0f, // beginning speed
        .sensing_radius = 50.0f,
        .rotation_speed = 10.0f, // beginnning rotation speed
    };

    // define base food information
    Food food = {
        .position = { 800, 200}, // starting position of each food
        .color = GREEN, // color of food
        .size = 4.0f, // size of each
        .taken = false, // whether or not its taken is default false
        .active = true,
    };

    Pheromones pheromone = {
        .color =  PURPLE,
        .position = { 0, 0 },
        .size = 4.0f,
        .strength = 1.0f
    };

    loadFood(&food);
    loadAnt(&ant);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {
        delta_time = GetFrameTime();
        rotation_delta = (45.0f * delta_time) * ant.rotation_speed;

        // 1. Updates / Inputs
        //----------------------------------------------------------------------------------


        // 2. TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // food
        getFood(&food, &spawn);

        // Ants
        forwardMovement(rotation_delta, delta_time, spawn.position);
        handleWallCollision(rotation_delta, WIDTH, HEIGHT);

        // 3. Draw
        //----------------------------------------------------------------------------------


        BeginDrawing();
            // Background
            ClearBackground((Color) { 6.0f, 8.0f, 9.0f, 1.0f });

            // Draw Grid
            for (int i = 0; i < COLS; i++) {
                for (int j = 0; j < ROWS; j++) {
                    DrawRectangleLines(i * cell_width, j * cell_height, cell_width, cell_height, (Color) { 255, 255, 255 });    
                }
            }

            // Draw ants
            drawAnt();

            // Draw Food
            drawFood();

            // Draw Pheromones
            // drawPheromone(pheromone.size, pheromone.color);

            // Draw Spawn
            DrawCircle(spawn.position.x, spawn.position.y, spawn.size, spawn.color);

            // GUI
            // GuiPanel((Rectangle){ 675, 100, 100, 25 }, "Hi!");

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}