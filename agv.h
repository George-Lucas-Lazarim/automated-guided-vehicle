#ifndef AGV_H
#define AGV_H

#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

bool isSafe (int map[SIZE][SIZE], int x, int y);
bool solvePath (int map[SIZE][SIZE], int x, int y, int destX, int destY);
void printMap (int map[SIZE][SIZE]);

#endif