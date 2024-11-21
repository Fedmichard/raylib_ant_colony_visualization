#include "foods.h"
#include "ants.h"

Food foods[MAX_FOOD];

void getFood(Food* food) {
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            if (ants[i].carrying == true) continue; // if the ant is currently carrying, skip to next ant

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

void depositFood(Spawn* spawn) {
    // food deposit
    for (int i = 0; i < (sizeof(foods) / sizeof(foods[0])); i++) {
        if (Vector2Distance(foods[i].position, spawn->position) < spawn->size) {
            // foods[i]
            // free(foods[i]);
            // foods[i].active = false;
            foods[i].color = WHITE;
        }
    }
}