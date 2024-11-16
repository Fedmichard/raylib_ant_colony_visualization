#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define WIDTH 1080
#define HEIGHT 720
#define MAX_ANTS 5000

// Time Variables
float delta_time;
float rotation_delta;

/*************************************************************************
 *                              STRUCTS
 *************************************************************************
 */

// Structure that holds all of our ant information
// direction represents the direction the ant is facing
// position represents its pos
// speed represents its speed
// angle represents the angle its facing
typedef struct Ant {
    Vector2 direction;
    Vector2 position;
    float speed;
    float angle;
    float rotation_speed;
} Ant;

// Array of ants
Ant ants[MAX_ANTS];
// Ant texture
Texture2D ant_texture;

typedef struct Spawn {
    Color color;
    Vector2 position;
    int size;
} Spawn;

// Wall structure
typedef struct Wall {
    Color color;

} Wall;

typedef struct pheromones {

} pheromones;


typedef struct Food {

} Food;



//------------------------------------------------------------------------------------
// Program main entry point
// Compile with GCC Compiler
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window");

    // Set our game to run at inf frames
    SetTargetFPS(-1);

    // defining spawn information
    Spawn spawn = {
        .color = RED,
        .position = { 200, 600 },
        .size = 10.0f
    };

    // ant texture
    ant_texture = LoadTexture("../resources/ant.png");
    // defining our ant information
    Ant ant = {
        .position = spawn.position,
        .direction = { 0.0f, 0.0f },
        .angle = 0.0f,
        .speed = 100.0f,
        .rotation_speed = 5.0f
    };

    for (int i = 0; i < sizeof(ants) / sizeof(ants[0]); i++) {
        ants[i].position = ant.position;
        ants[i].angle = (i * (360.0f / MAX_ANTS));
    }


    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {
        delta_time = GetFrameTime();
        rotation_delta = (90.0f * delta_time) * ant.rotation_speed;

        // 1. Updates / Inputs
        //----------------------------------------------------------------------------------
        // Testing rotation

        /*
        if (IsKeyDown(KEY_D)) {
            ant.angle += rotation_delta;
        } 

        if (IsKeyDown(KEY_A)) {
            ant.angle -= rotation_delta;
        }
        */

        // 2. TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // The direction is calculated based on the angle and returns a 2d normalized vector
        // A normalized vector is one of length 1 so if we were to draw this vector it would
        // be of length 1 in the direction your character is facing
        // sin represents x, cos represents y. We flip cos since our x,y starts at the top right
        // instead of using cos for x and sin for y, we do it this way since in computer graphics
        // the positive y points downwards instead of upwards

        /* ant.direction = Vector2Normalize((Vector2) {sinf(DEG2RAD * ant.angle), -cos(DEG2RAD * ant.angle)}); */

        // updates the position by adding the currently x, y value by the normalized vector
        // of length 1 and multiplying by the speed and delta_time

        /*
        ant.position.y += (ant.direction.y * ant.speed) * delta_time;
        ant.position.x += (ant.direction.x * ant.speed) * delta_time;
        */  

        // Ants starting positions
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            ants[i].speed = ant.speed;
            ants[i].rotation_speed = ant.rotation_speed;

            ants[i].direction = Vector2Normalize((Vector2) { sinf(DEG2RAD * ants[i].angle), -cos(DEG2RAD * ants[i].angle) });

            ants[i].position.y += (ants[i].direction.y * ants[i].speed) * delta_time;
            ants[i].position.x += (ants[i].direction.x * ants[i].speed) * delta_time;
        }

        // Update movement for the ants
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            if (GetRandomValue(0, 1000) < 5) {
                int target_angle = GetRandomValue(-45, 45);
                ants[i].angle += (target_angle - ants[i].angle) * 0.1f;
                // ants[i].angle += GetRandomValue(-45, 45) * rotation_delta;

            }

            // Collisions
            if (ants[i].position.x < 5) { 
                ants[i].position.x = 5;
                int target_angle = GetRandomValue(-180, 180);
                ants[i].angle += (target_angle - ants[i].angle) * 0.1f;
                // ants[i].angle += GetRandomValue(-90, 90) * rotation_delta;
            }
            if (ants[i].position.x > WIDTH - 5) {
                ants[i].position.x = WIDTH - 5;
                int target_angle = GetRandomValue(-180, 180);
                ants[i].angle += (target_angle - ants[i].angle) * 0.1f;
                // ants[i].angle += GetRandomValue(-180, 180) * rotation_delta;
            }
            if (ants[i].position.y < 5) {
                ants[i].position.y = 5;
                int target_angle = GetRandomValue(-360, 360);
                ants[i].angle += (target_angle - ants[i].angle) * 0.1f;
                // ants[i].angle += GetRandomValue(-90, 90) * rotation_delta;
            }
            if (ants[i].position.y > HEIGHT - 5) {
                ants[i].position.y = HEIGHT - 5;
                int target_angle = GetRandomValue(-360, 360);
                ants[i].angle += (target_angle - ants[i].angle) * 0.1f;
                // ants[i].angle += GetRandomValue(-180, 180) * rotation_delta;
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

            // Draw Food

            // Draw ants
            for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
                DrawTextureEx(ant_texture, ants[i].position, ants[i].angle, 0.015f, RED);    
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