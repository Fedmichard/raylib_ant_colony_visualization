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

#define WIDTH 1080
#define HEIGHT 720

// Time Variables
float delta_time;
float rotation_delta;

// struct that holds pheromones
typedef struct pheromones {
    Color color; // color of each pheromone
    int size; // size of each
    Vector2 position; // position of each
    float strength; // strength of each which also determines size
} pheromones;


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
        .rotation_speed = 10.0f // beginnning rotation speed
    };

    // define base food information
    Food food = {
        .position = { 800, 200}, // starting position of each food
        .color = GREEN, // color of food
        .size = 4.0f, // size of each
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
        getFood(&food);
        depositFood(&spawn);

        // Ants
        forwardMovement(rotation_delta, delta_time);
        handleWallCollision(rotation_delta, WIDTH, HEIGHT);

        // 3. Draw
        //----------------------------------------------------------------------------------


        BeginDrawing();
            // Background
            ClearBackground(BLACK);

            // Draw ants
            for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
                DrawTextureEx(ant_texture, ants[i].position, ants[i].angle, 0.015f, RED);    
            }

            // Draw Food
            for (int i = 0; i < (sizeof(foods) / sizeof(foods[0])); i++) {
                if (!foods[i].active) continue;  
                DrawCircle(foods[i].position.x, foods[i].position.y, foods[i].size, foods[i].color);
            }

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