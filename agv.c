#include "agv.h"

bool isSafe (int map[SIZE][SIZE], int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return false; // map limits
    
    if (map[x][y] != 0) return false; // walls and trail

    return true;
}

bool solvePath(int map[SIZE][SIZE], int x, int y, int destX, int destY) {
    if (x == destX && y == destY) {
        map[x][y] = 2;
        return true;
    }

    if (isSafe(map, x, y)) {
        map[x][y] = 2;

        if (solvePath(map, x + 1, y, destX, destY)) return true;
        if (solvePath(map, x, y + 1, destX, destY)) return true;
        if (solvePath(map, x - 1, y, destX, destY)) return true;
        if (solvePath(map, x, y - 1, destX, destY)) return true;

        map[x][y] = 0;
    }

    return false;
}

void printMap(int map[SIZE][SIZE]) {
    printf("\n");
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (map[x][y] == -1) printf(" [X] "); // wall
            else if (map[x][y] == 2) printf("  * "); // trail
            else printf("  .  "); // clean floor
        }
        printf("\n");
    }
}