#include "grid.h"
int grid[COLS][ROWS] = { 0 }; // 0 for unused, 1 for used

const int cell_width = WIDTH / COLS; // width of each cell
const int cell_height = HEIGHT / ROWS; // height of each cell
float gridUpdateTimer = 0.0f;  // Keeps track of elapsed time
const float gridUpdateInterval = 0.75f; // Update every 0.15 seconds
float opacity = 255.0f;

void updateGrid() {
    // Increment the timer with the time since the last frame
    gridUpdateTimer += GetFrameTime();

    // Check if it's time to update the grid
    if (gridUpdateTimer >= gridUpdateInterval) {
        gridUpdateTimer = 0.0f;  // Reset the timer

        // Update the grid with ants' current positions
        // for all the ants
        for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
            int col = ants[i].position.x / cell_width; // check which colum the ant is currently in
            int row = ants[i].position.y / cell_height; // check which row the ant is currently in

            // make sure the column and row the ants are within the range of 0 - COL/ROW
            if ((col >= 0 && col < COLS) && (row >= 0 && row < ROWS)) {

                // Update grid based on carrying status
                if (ants[i].carrying) {
                    // add/subtract one to i so even if it was the 0 index you will always get a positive or negative value
                    grid[col][row] = i + 1;  // Positive value for carrying
                } else {
                    grid[col][row] = -(i + 1);  // Negative value for not carrying
                }
            }
        }
    }
}

void drawGrid() {
    gridUpdateTimer += GetFrameTime();
    
    // gradually decrease opacity
    opacity -= gridUpdateTimer * 2.0f;

    if (opacity < 0) {
        opacity = 0;
    }

    // for each row/col
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            // as long as the specific location of the grid doesn't equal 0
            if (grid[i][j] != 0) {
                // Determine the color based on the value in the grid
                bool carrying = grid[i][j] > 0;    // Positive means carrying
                Color cell_color;

                // Set color based on carrying state
                if (carrying) {
                    cell_color = (Color){ 255, 93, 143, opacity};
                } else {
                    cell_color = (Color){ 163, 196, 243, opacity };
                }

                DrawRectangle(i * cell_width, j * cell_height, cell_width, cell_height, cell_color);
            }

            // Draw grid lines
            DrawRectangleLines(i * cell_width, j * cell_height, cell_width, cell_height, (Color){ 255, 255, 255, 25 });
        }
    }

    if (opacity == 0) {
        gridUpdateTimer = 0;  // Reset the timer after opacity fades out
    }
}