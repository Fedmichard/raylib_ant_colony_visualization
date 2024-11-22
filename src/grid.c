#include "grid.h"

int grid[COLS][ROWS] = { 0 }; // 0 for unused, 1 for used

const int cell_width = WIDTH / COLS; // width of each cell
const int cell_height = HEIGHT / ROWS; // height of each cell

const float gridUpdateInterval = 0.5f; // Update every 0.15 seconds
float gridUpdateTimer = 0.0f;  // Keeps track of elapsed time

float max_strength = 255.0f; // max strength of a cell, corresponding to opacity
float min_strength = 25.0f;
float base_decay_rate = 0.25f; // rate of decay of each colored cell

float calculateDecayRate(float distance) {
    return distance;
}

float updateStrength() {
    
}

void updateGrid() {
    // Increment the timer with the time since the last frame
    gridUpdateTimer += GetFrameTime();

    // Check if it's time to update the grid
    if (gridUpdateTimer >= gridUpdateInterval) {
        gridUpdateTimer = 0.0f;  // Reset the timer if it's time to update

        // Update the grid with ants' current positions
        // for all the ants
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            printf("Current Distance: %zf\n", calculateDecayRate(ants[i].distance_from_home));
            int col = ants[i].position.x / cell_width; // check which colum the ant is currently in
            int row = ants[i].position.y / cell_height; // check which row the ant is currently in

            // make sure the column and row the ants are within the range of 0 - COL/ROW
            if ((col >= 0 && col < COLS) && (row >= 0 && row < ROWS)) {
                // Update grid based on carrying status
                // if the ant is carrying
                if (ants[i].carrying) {
                    // add/subtract one to i so even if it was the 0 index you will always get a positive or negative value
                    grid[col][row] = max_strength;  // Positive value for carrying
                } else {
                    grid[col][row] = -(max_strength);  // Negative value for not carrying
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
            float decay_rate;

            for (int k = 0; k < (sizeof(ants) / sizeof(ants[0])); k++) {
                decay_rate = calculateDecayRate(ants[i].distance_from_home);
            }

            // Update grid cell value and determine the color
            if (grid[i][j] != 0) {
                // Apply decay
                // if the grid cell has a carrying state
                if (grid[i][j] > 0) {
                    carrying = true;
                    grid[i][j] -= decay; // Decay it 
                    // don't let it decay past 0 so it doesn't turn to not carrying
                    if (grid[i][j] < 0) grid[i][j] = 0; 
                } else {
                    carrying = false;
                    grid[i][j] += decay; // Decay it
                    // don't let it decay past 0 so it doesn't turn to carrying
                    if (grid[i][j] > 0) grid[i][j] = 0; 
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