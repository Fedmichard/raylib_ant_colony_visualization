#include "grid.h"

const int cell_width = WIDTH / COLS;
const int cell_height = HEIGHT / ROWS;

void drawGrid() {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            DrawRectangleLines(i * cell_width, j * cell_height, cell_width, cell_height, (Color) { 255, 255, 255, 25 });    
        }
    }
}