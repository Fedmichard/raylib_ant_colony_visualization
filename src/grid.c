#include "grid.h"
int grid[COLS][ROWS] = { 0 }; // 0 for unused, 1 for used

const int cell_width = WIDTH / COLS;
const int cell_height = HEIGHT / ROWS;

Color updateGrid() {
    Color color;
    // for every single ant
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {

        // calculation for which grid cell the ant is currently in
        int col = ants[i].position.x / cell_width;
        int row = ants[i].position.y / cell_height;

        if (col >= 0 && col < COLS && row >= 0 && row < ROWS) {
            grid[col][row] = 1;
        }
        
        if (!ants[i].carrying) {
            color = (Color) { 163, 196, 243, 255 };
        } else {
            color = (Color) { 163, 196, 243, 255 };
        }
    }

    return color;
}

void drawGrid() {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (grid[i][j] == 1) {
                DrawRectangle(i * cell_width, j * cell_height, cell_width, cell_height, updateGrid());
                continue;
            }
            DrawRectangleLines(i * cell_width, j * cell_height, cell_width, cell_height, (Color) { 255, 255, 255, 25 });    
        }
    }
}