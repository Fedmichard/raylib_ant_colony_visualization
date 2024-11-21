#include "pheromones.h"

void drawPheromone(float size, Color color, Vector2 position, float strength) {
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
        if (ants[i].carrying) continue;

        DrawCircle(ants[i].position.x, ants[i].position.y, size, color);
    }
}
