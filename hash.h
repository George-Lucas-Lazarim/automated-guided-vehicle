#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define HASH_SIZE 11

struct hashNode {
    int productID;
    int x, y;
    struct hashNode* next;
};

extern struct hashNode* hashTable[HASH_SIZE];

void initHashTable();
int hashFunction(int productID);
void insertHash (int productID, int x, int y);
bool searchAndPickProduct (int productID, int* x, int* y);

#endif