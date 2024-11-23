#include "grid.h"

// Define separate strengths for carrying and not carrying
float carrying_strength = 255.0f;  // Maximum strength for carrying state
float not_carrying_strength = 255.0f;  // Maximum strength for not carrying state
float min_strength = 10.0f;

const int cell_width = WIDTH / COLS; // Width of each cell
const int cell_height = HEIGHT / ROWS; // Height of each cell

const float base_decay_rate = 100.0f; // Base decay rate for all trails

// Define a shared grid for all ants' pheromone trails
float shared_grid[COLS][ROWS] = { 0 }; // Single grid for all ants

void updateGrid() {
    // Decay pheromone trails for all ants
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (shared_grid[i][j] != 0) {
                // Decay pheromones in the shared grid
                float decay = base_decay_rate * GetFrameTime();
                if (shared_grid[i][j] > 0) { // Carrying pheromone
                    shared_grid[i][j] -= decay;
                    if (shared_grid[i][j] < min_strength) {
                        shared_grid[i][j] = 0; // Clear once below minimum
                    }
                } else { // Not carrying pheromone
                    shared_grid[i][j] += decay;
                    if (shared_grid[i][j] > -min_strength) {
                        shared_grid[i][j] = 0; // Clear once above minimum
                    }
                }
            }
        }
    }

    // Update pheromone deposits from ants
    for (int a = 0; a < MAX_ANTS; a++) { // Iterate over all ants
        int col = ants[a].position.x / cell_width;
        int row = ants[a].position.y / cell_height;

        if (col >= 0 && col < COLS && row >= 0 && row < ROWS) {
            if (ants[a].carrying) {
                shared_grid[col][row] = carrying_strength; // Deposit carrying pheromone
            } else {
                shared_grid[col][row] = -not_carrying_strength; // Deposit not carrying pheromone
            }
        }
    }
}

void drawGrid() {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            float carrying_total = 0.0f;
            float not_carrying_total = 0.0f;

            // Combine pheromone strengths from the shared grid
            if (shared_grid[i][j] > 0) {
                carrying_total = shared_grid[i][j];
            } else if (shared_grid[i][j] < 0) {
                not_carrying_total = shared_grid[i][j];
            }

            // Determine the final color of the cell
            if (carrying_total > 0) {
                Color carrying_color = (Color){ 255, 93, 143, (int)carrying_total };
                DrawRectangle(i * cell_width, j * cell_height, cell_width, cell_height, carrying_color);
            } else if (not_carrying_total < 0) {
                Color not_carrying_color = (Color){ 233, 255, 112, (int)-not_carrying_total };
                DrawRectangle(i * cell_width, j * cell_height, cell_width, cell_height, not_carrying_color);
            }

            // Draw grid lines for clarity
            DrawRectangleLines(i * cell_width, j * cell_height, cell_width, cell_height, (Color){ 255, 255, 255, 25 });
        }
    }
}