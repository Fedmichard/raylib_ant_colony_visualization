#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define WIDTH 1080
#define HEIGHT 720
#define MAX_ANTS 2000
#define MAX_FOOD 500

// Time Variables
float delta_time;
float rotation_delta;

/*************************************************************************
 *                              STRUCTS
 *************************************************************************
 */

// All of our food information
typedef struct Food {
    Vector2 position; // Position of the food
    float size; // size of each food
    Color color; // color of each food
    bool taken; // whether or not the food is currently equipped
    bool active;
} Food;

Food foods[MAX_FOOD]; // array of food structs

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
Ant ants[MAX_ANTS];
// Ant texture
Texture2D ant_texture;

// struct that holds our spawn
typedef struct Spawn {
    Color color; // color of the spawn
    Vector2 position; // position of spawn
    int size; // size of spawn
} Spawn;

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

    // defining spawn information
    Spawn spawn = {
        .color = RED,
        .position = { WIDTH / 2, HEIGHT / 2 }, 
        .size = 10.0f
    };

    // ant texture
    ant_texture = LoadTexture("../resources/ant.png");
    // defining our ant information
    Ant ant = {
        .position = spawn.position, // position always starts at the spawn per ant
        .direction = { 0.0f, 0.0f }, // Beginning direction of each ant
        .angle = 0.0f, // beginning angle
        .speed = 100.0f, // beginning speed
        .rotation_speed = 10.0f // beginnning rotation speed
    };

    // definition our food information
    Food food = {
        .position = { 800, 200}, // starting position of each food
        .color = GREEN, // color of food
        .size = 4.0f, // size of each
        .taken = false, // whether or not its taken is default false
        .active = true,
    };

    // Starting food values
    for (int i = 0; i < sizeof(foods) / sizeof(foods[0]); i++) {
        foods[i].position.x = food.position.x + GetRandomValue(0, 50); // random x position assigned within range of org spawn
        foods[i].position.y = food.position.y + GetRandomValue(0, 50); // random y position assigned within range of org spawn
        foods[i].color = food.color; // color of each food
        foods[i].size = food.size; // size of each food
        foods[i].taken = food.taken; // taken is deafult
        foods[i].active = food.active;
    }

    // Ants starting positions and angles
    for (int i = 0; i < sizeof(ants) / sizeof(ants[0]); i++) {
        ants[i].speed = ant.speed; // starting speed of each ant
        ants[i].rotation_speed = ant.rotation_speed; // rotation speed of each ant
        ants[i].position = ant.position; // starting position of each
        ants[i].angle = (i * (360.0f / MAX_ANTS)); // each ant spawns around the circumference of the circle
    }


    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {
        delta_time = GetFrameTime();
        rotation_delta = (45.0f * delta_time) * ant.rotation_speed;

        // 1. Updates / Inputs
        //----------------------------------------------------------------------------------


        // 2. TODO: Update your variables here
        //----------------------------------------------------------------------------------

       
        // food collection
        // for every ant in our ant array
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            if (ants[i].carrying == true) continue; // if the ant is currently carrying, skip to next ant

            // for every food in our food array
            for (int v = 0; v < (sizeof(foods) / sizeof(foods[0])); v++) {
                if (foods[v].taken) continue; // if food is currently taken skip to next food

                // create a vector between current ant position and current food position is less than size of the food
                if (Vector2Distance(ants[i].position, foods[v].position) < food.size) {
                    foods[v].taken = true; // set the current food taken to true
                    ants[i].carrying = true; // set that current ant carrying to true
                    ants[i].food = &foods[v]; // pass reference of current food to be held in ant struct
                    break; // break out of loop for current food
                }
            }
        }

        // food deposit
        for (int i = 0; i < (sizeof(foods) / sizeof(foods[0])); i++) {
            if (Vector2Distance(foods[i].position, spawn.position) < spawn.size) {
                // foods[i]
                // free(foods[i]);
                // foods[i].active = false;
            }
        }

        // Ants movement updates
        // The direction is calculated based on the angle and returns a 2d normalized vector
        // A normalized vector is one of length 1 so if we were to draw this vector it would
        // be of length 1 in the direction your character is facing
        // sin represents x, cos represents y. We flip cos since our x,y starts at the top right
        // instead of using cos for x and sin for y, we do it this way since in computer graphics
        // the positive y points downwards instead of upwards
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            ants[i].direction = Vector2Normalize((Vector2) { sinf(DEG2RAD * ants[i].angle), -cosf(DEG2RAD * ants[i].angle) });

            ants[i].position.y += (ants[i].direction.y * ants[i].speed) * delta_time;
            ants[i].position.x += (ants[i].direction.x * ants[i].speed) * delta_time;

            // if ant is currently carrying a piece of food
            if (ants[i].carrying) {
                ants[i].food->position = ants[i].position; // make the current position of the stored food reference = to ant pos
            }
        }

        // Update angle for the ants
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            if (GetRandomValue(0, 1000) < 5) {
                ants[i].angle += GetRandomValue(-15, 15) * rotation_delta;
            }

            // Collisions
            // Left Wall
            if (ants[i].position.x < 5) { 
                ants[i].position.x = 5; // Reset position to prevent getting stuck
                ants[i].angle = GetRandomValue(0, 180) - ants[i].angle; // Reflect angle horizontally
                ants[i].angle += GetRandomValue(-45, 45) * rotation_delta; // Add random perturbation
            }

            // Right wall
            if (ants[i].position.x > WIDTH - 5) {
                ants[i].position.x = WIDTH - 5; // Reset position
                ants[i].angle = GetRandomValue(0, 180) - ants[i].angle; // Reflect angle horizontally
                ants[i].angle += GetRandomValue(-45, 45) * rotation_delta; // Add random perturbation
            }

            // Top wall
            if (ants[i].position.y < 5) {
                ants[i].position.y = 5; // Reset position
                ants[i].angle = -ants[i].angle; // Reflect angle vertically
                ants[i].angle += GetRandomValue(-45, 45) * rotation_delta; // Add random perturbation
            }

            // Bottom wall
            if (ants[i].position.y > HEIGHT - 5) {
                ants[i].position.y = HEIGHT - 5; // Reset position
                ants[i].angle = -ants[i].angle; // Reflect angle vertically
                ants[i].angle += GetRandomValue(-45, 45) * rotation_delta; // Add random perturbation
            }
        }

        // 3. Draw
        //----------------------------------------------------------------------------------


        BeginDrawing();
            // Background
            ClearBackground(BLACK);

            // Draw Walls

            /*
            DrawRectangle(0, 0, 5, HEIGHT, LIGHTGRAY); // Left
            DrawRectangle(WIDTH - 5, 0, 5, HEIGHT, LIGHTGRAY); // Right
            DrawRectangle(0, 0, WIDTH, 5, LIGHTGRAY); // Top
            DrawRectangle(0, HEIGHT - 5, WIDTH, 5, LIGHTGRAY); // Bottom
            */

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