#include "ants.h"

// Array of ants
Ant ants[MAX_ANTS];
// Ant texture
Texture2D ant_texture;

void forwardMovement(float delta_time) {
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
}

void updateMovement(float rotation_delta, int width, int height) {
    // Update angle for the ants
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            if (GetRandomValue(0, 100) < 1) {
                ants[i].angle += GetRandomValue(-5, 5) * rotation_delta;
            }

            // Collisions
            // Left Wall
            if (ants[i].position.x < 5) { 
                ants[i].position.x = 5; // Reset position to prevent getting stuck
                ants[i].angle = GetRandomValue(0, 180) - ants[i].angle; // Reflect angle horizontally
                ants[i].angle += GetRandomValue(-45, 45) * rotation_delta; // Add random perturbation
            }

            // Right wall
            if (ants[i].position.x > width - 5) {
                ants[i].position.x = width - 5; // Reset position
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
            if (ants[i].position.y > height - 5) {
                ants[i].position.y = height - 5; // Reset position
                ants[i].angle = -ants[i].angle; // Reflect angle vertically
                ants[i].angle += GetRandomValue(-45, 45) * rotation_delta; // Add random perturbation
            }
        }
}