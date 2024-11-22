#include "grid.h"

// Define separate strengths for carrying and not carrying
float carrying_strength = 255.0f;  // Maximum strength for carrying state
float not_carrying_strength = 255.0f;  // Maximum strength for not carrying state
float min_strength = 10.0f;

const int cell_width = WIDTH / COLS; // Width of each cell
const int cell_height = HEIGHT / ROWS; // Height of each cell

const float base_decay_rate = 100.0f; // Base decay rate for all trails

// Define a 3D array for individual ant pheromone trails
float ant_grid[MAX_ANTS][COLS][ROWS] = { 0 }; // Each ant has its own grid

void updateGrid() {
    // Decay pheromone trails for each ant
    for (int a = 0; a < MAX_ANTS; a++) { // Iterate over all ants
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < ROWS; j++) {
                if (ant_grid[a][i][j] != 0) {
                    // Decay based on carrying or not carrying state
                    float decay = base_decay_rate * GetFrameTime();
                    if (ant_grid[a][i][j] > 0) { // Carrying pheromone
                        ant_grid[a][i][j] -= decay;
                        if (ant_grid[a][i][j] < min_strength) {
                            ant_grid[a][i][j] = 0; // Clear once below minimum
                        }
                    } else { // Not carrying pheromone
                        ant_grid[a][i][j] += decay;
                        if (ant_grid[a][i][j] > -min_strength) {
                            ant_grid[a][i][j] = 0; // Clear once above minimum
                        }
                    }
                }
            }
        }
    }

    // Update each ant's current position in the grid
    for (int a = 0; a < MAX_ANTS; a++) {
        int col = ants[a].position.x / cell_width;
        int row = ants[a].position.y / cell_height;

        if (ants[a].carrying) {
            
        } else {
        }

        if (col >= 0 && col < COLS && row >= 0 && row < ROWS) {
            if (ants[a].carrying) {
                ant_grid[a][col][row] = carrying_strength; // Deposit carrying pheromone
            } else {
                ant_grid[a][col][row] = -not_carrying_strength; // Deposit not carrying pheromone
            }
        }
    }
}

void drawGrid() {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            float carrying_total = 0.0f;
            float not_carrying_total = 0.0f;

            // Combine pheromone strengths from all ants
            for (int a = 0; a < MAX_ANTS; a++) {
                if (ant_grid[a][i][j] > 0) {
                    carrying_total += ant_grid[a][i][j];
                } else if (ant_grid[a][i][j] < 0) {
                    not_carrying_total += ant_grid[a][i][j];
                }
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