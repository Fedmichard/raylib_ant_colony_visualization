#include "pheromones.h"

void createPheromone() {

}

void drawPheromone(float size, Color color) {
    for (int i = 0; i < (sizeof(ants) / sizeof(ants[0])); i++) {
        if (ants[i].carrying) continue;

        DrawCircle(ants[i].position.x, ants[i].position.y, size, color);
    }
}
