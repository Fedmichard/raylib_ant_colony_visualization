#include "grid.h"

int grid[COLS][ROWS] = { 0 }; // 0 for unused, 1 for used

const int cell_width = WIDTH / COLS; // width of each cell
const int cell_height = HEIGHT / ROWS; // height of each cell

const float gridUpdateInterval = 0.5f; // Update every 0.15 seconds
float gridUpdateTimer = 0.0f;  // Keeps track of elapsed time

float max_strength = 255.0f; // max strength of a cell, corresponding to opacity
float min_strength = 10.0f;
float strength_decay_rate = 20.0f;

float base_decay_rate = 0.0003f; // rate of decay of each colored cell

float calculateDecayRate(float distance) {
    return distance;
}

float updateStrength() {
    // strength will start at 255
    // over time the strength will gradually decrease less and less to a minimum value
    // use this strength value when drawing the 
    float strength;

    strength -= GetFrameTime() * strength_decay_rate;

    return strength;
}

void updateGrid() {
    // Increment the timer with the time since the last frame
    gridUpdateTimer += GetFrameTime();

    // Gradually reduce max_strength using exponential decay
    float decay_factor = 0.1f; // Adjust this to control the decay speed
    max_strength -= (max_strength - min_strength) * decay_factor * GetFrameTime();
    if (max_strength < min_strength) {
        max_strength = min_strength; // Clamp to min_strength
    }
    printf("Current max_strength: %.2f\n", max_strength);

    // Check if it's time to update the grid
    if (gridUpdateTimer >= gridUpdateInterval) {
        gridUpdateTimer = 0.0f;  // Reset the timer if it's time to update

        // Update the grid with ants' current positions
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            int col = ants[i].position.x / cell_width; // Check which column the ant is currently in
            int row = ants[i].position.y / cell_height; // Check which row the ant is currently in

            // Ensure the column and row are within valid ranges
            if ((col >= 0 && col < COLS) && (row >= 0 && row < ROWS)) {
                // Update grid based on carrying status
                if (ants[i].carrying) {
                    grid[col][row] = max_strength;  // Positive value for carrying
                } else {
                    grid[col][row] = -max_strength;  // Negative value for not carrying
                }
            }
        }
    }
}

void drawGrid() {
    // for each row/col
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            // Apply decay and determine the color based on pheromone strength
            float decay = base_decay_rate * GetFrameTime();
            // Determine if the cell represents a "carrying" state
            bool carrying;

            // Update grid cell value and determine the color
            if (grid[i][j] != 0) {
                // Apply decay
                // if the grid cell has a carrying state
                if (grid[i][j] > 0) {
                    carrying = true;
                    grid[i][j] -= decay; // Decay it 
                    // don't let it decay past 0 so it doesn't turn to not carrying
                    if (grid[i][j] < 10) grid[i][j] = 10; 
                } else {
                    carrying = false;
                    grid[i][j] += decay; // Decay it
                    // don't let it decay past 0 so it doesn't turn to carrying
                    if (grid[i][j] > -10) grid[i][j] = -10; 
                }

                // Set the color based on carrying state
                Color cell_color;

                // if the grid is in a carrying state
                if (carrying) {
                    cell_color = (Color){ 255, 93, 143, grid[i][j] }; // set its color
                } else {
                    // if its not in a carrying state
                    cell_color = (Color){ 233, 255, 112, -grid[i][j] }; // set its color
                }

                // Draw the cell with its assigned color
                DrawRectangle(i * cell_width, j * cell_height, cell_width, cell_height, cell_color);
            }

            // Draw grid lines
            DrawRectangleLines(i * cell_width, j * cell_height, cell_width, cell_height, (Color){ 255, 255, 255, 25 });
        }
    }
}