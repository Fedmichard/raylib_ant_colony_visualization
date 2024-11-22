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
#include "grid.h"

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

    // define base spawn information
    Spawn spawn = {
        .color = PURPLE,
        .position = { 100, 650 }, 
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
        .color = (Color) { 144, 219, 244, 255 }, // color of food
        .size = 3.5f, // size of each
        .taken = false, // whether or not its taken is default false
        .active = true,
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
            ClearBackground((Color) { 6.0f, 8.0f, 9.0f, 255.0f });

            // Draw Grid
            updateGrid();
            drawGrid();

            // Draw ants
            drawAnt();

            // Draw Food
            drawFood();

            // Draw Pheromones
            // drawPheromone(pheromone.size, pheromone.color);

            // Draw Spawn
            DrawCircle(spawn.position.x, spawn.position.y, spawn.size, spawn.color);

            DrawFPS(10, 10);

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