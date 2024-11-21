#include "ants.h"

// Array of ants
Ant ants[MAX_ANTS];
// Ant texture
Texture2D ant_texture;

void loadAnt(Ant* ant) {
    // Ants starting positions and angles
    for (int i = 0; i < sizeof(ants) / sizeof(ants[0]); i++) {
        ants[i].speed = ant->speed; // starting speed of each ant
        ants[i].rotation_speed = ant->rotation_speed; // rotation speed of each ant
        ants[i].position = ant->position; // starting position of each
        ants[i].angle = (i * (360.0f / MAX_ANTS)); // each ant spawns around the circumference of the circle
        ants[i].sensing_radius = ant->sensing_radius; // set the sensing radius of the ant
    }
}

void drawAnt() {
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
        DrawTextureEx(ant_texture, ants[i].position, ants[i].angle, 0.02f, (Color) { 213, 189, 175, 255 });    
    }
}

void forwardMovement(float rotation_delta, float delta_time, Vector2 spawn) {
    // Ants movement updates
    // The direction is calculated based on the angle and returns a 2d normalized vector
    // A normalized vector is one of length 1 so if we were to draw this vector it would
    // be of length 1 in the direction your character is facing
    // sin represents x, cos represents y. We flip cos since our x,y starts at the top right
    // instead of using cos for x and sin for y, we do it this way since in computer graphics
    // the positive y points downwards instead of upwards
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
        Vector2 base_direction = Vector2Normalize((Vector2) { sinf(DEG2RAD * ants[i].angle), -cosf(DEG2RAD * ants[i].angle) });
        ants[i].direction = base_direction;
        Food* nearest_food = NULL; // the nearest food to the ant
        float nearest_distance = ants[i].sensing_radius; // the nearest distance to the food

        // update its position based on the direction and speed
        ants[i].position.y += (ants[i].direction.y * ants[i].speed) * delta_time;
        ants[i].position.x += (ants[i].direction.x * ants[i].speed) * delta_time;

        // if ant is currently carrying a piece of food
        if (ants[i].carrying) {
            ants[i].food->position = ants[i].position; // make the current position of the stored food reference = to ant pos
        }
        
        // add random permutations of angle while the ants are moving forward
        if (GetRandomValue(0, 100) < 1) {
            ants[i].angle += GetRandomValue(-5, 5) * rotation_delta; // add random permutations to the ants angle
        }

        // for every single food 
        for (int v = 0; v < (sizeof(foods) / sizeof(foods[0])); v++) {
            if (foods[v].taken || !foods[v].active) continue; // if the food is taken or the food is not active skip

            float distance = Vector2Distance(ants[i].position, foods[v].position); // get the distance between the current and and current food

            // if the distance between current ant and food is less than current tracked nearest 
            if (distance < nearest_distance) {
                nearest_food = &foods[v]; // nearest food will be the nearest food item
                nearest_distance = distance; // nearest distance will be the nearest distance
            }
        }

        // if there is a nearest food and an ant is not carrying
        if (nearest_food && !ants[i].carrying) {
            Vector2 direction = Vector2Subtract(nearest_food->position, ants[i].position); // go in the direction of the food
            ants[i].angle = RAD2DEG * atan2f(direction.y, direction.x) + 90.0f; // update ants angle towards direction
        }

        backToSpawn(&ants[i], spawn); // head back to spawn with food
        
    }
}

void backToSpawn(Ant* ant, Vector2 spawn) {
    // if the ant is currently holding food
    if (ant->carrying) {
        Vector2 direction = Vector2Subtract((Vector2) {spawn.x, spawn.y}, ant->position); // set its direction to the spawn position
        ant->angle = RAD2DEG * atan2f(direction.y, direction.x) + 90.0f; // set its angle to that direction so it moves towards it
    }
}

void handleWallCollision(float rotation_delta, int width, int height) {
    // Update angle for the ants
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
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

void getFood(Food* food, Spawn* spawn) {
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
        // If the ant is carrying food
        if (ants[i].carrying) {
            // Check if the ant is near the spawn
            if (Vector2Distance(ants[i].position, spawn->position) < spawn->size) {
                // Drop off the food
                ants[i].carrying = false;  // The ant is no longer carrying food
                ants[i].food->position = spawn->position;
                ants[i].food = NULL;  // Remove the reference to the food
                continue;  // Skip to the next ant
            }

            // If the ant is carrying food but hasn't reached the spawn, continue moving
            continue;
        }

        // for every food in our food array
        for (int v = 0; v < (sizeof(foods) / sizeof(foods[0])); v++) {
            if (foods[v].taken) continue; // if food is currently taken skip to next food

            // create a vector between current ant position and current food position is less than size of the food
            if (Vector2Distance(ants[i].position, foods[v].position) < food->size) {
                foods[v].taken = true; // set the current food taken to true
                ants[i].carrying = true; // set that current ant carrying to true
                ants[i].food = &foods[v]; // pass reference of current food to be held in ant struct
                break; // break out of loop for current food
            }
        }
    }
}