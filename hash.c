#include "hash.h"

struct hashNode* hashTable[HASH_SIZE];

void initTable() {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = NULL;
}

int hashFunction(int productID) {
    if (productID < 0) {
        printf("\nError! Invalid product ID");
        return -1;
    }

    return productID % HASH_SIZE;
}

void insertHash (int productID, int x, int y) {
    int hashi = hashFunction(productID);

    if (hashi == -1) {
        printf("\nThe product was not added! Exiting...");
        return;
    }

    struct hashNode* newProduct = (struct hashNode*) malloc (sizeof(struct hashNode));

    if (newProduct == NULL) {
        printf("\nNot enough memory space to add more products.");
        printf("\nThe product was not added! Exiting...");
        return;
    }

    newProduct->productID = productID;
    newProduct->x = x;
    newProduct->y = y;
    newProduct->next = NULL;

    if (hashTable[hashi] == NULL) hashTable[hashi] = newProduct;
    else {
        newProduct->next = hashTable[hashi];
        hashTable[hashi] = newProduct;
    }
}

bool searchAndPickProduct (int productID, int* x, int* y) {
    int hashi = hashFunction(productID);

    if (hashi == -1) {
        printf("\nThe product was not removed! Exiting...");
        return false;
    }

    struct hashNode* auxPointer = hashTable[hashi];
    struct hashNode* prevPointer = NULL;

    while (auxPointer != NULL) {
        if (auxPointer->productID == productID) {
            *x = auxPointer->x;
            *y = auxPointer->y;

            if (prevPointer == NULL) hashTable[hashi] = auxPointer->next;
            else prevPointer->next = auxPointer->next;

            free(auxPointer);
            return true;
        }

        prevPointer = auxPointer;
        auxPointer = auxPointer->next;
    }

    return false;
}