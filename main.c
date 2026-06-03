#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "agv.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "hash.h"

#define SIZE 8

int main() {
    int map[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, -1, 0, 0, -1, 0, 0},
        {0, 0, 0, 0, 0, -1, 0, 0},
        {0, -1, 0, 0, 0, -1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, -1, -1, 0},
        {-1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, -1, -1, 0}
    };

    initHashTable();

    struct stack* bucket = initStack();
    struct queue* orderQueue = initQueue();
    struct treeNode* deliveryRecord = NULL;

    printf("\n[SYS] Registering products...");
    insertHash(8092, 5, 7);
    insertHash(3341, 1, 6);
    insertHash(9999, 7, 7);

    printf("\n[SYS] Receiving orders from the internet...");
    enqueue(orderQueue, 1050, 8092);
    enqueue(orderQueue, 1051, 3341);
    enqueue(orderQueue, 1052, 9999);

    int currentOrder, currentProduct;

    while (dequeue(orderQueue, &currentOrder, &currentProduct)) {
        printf("\n[AGV] Start Task -> Request: %d | Product ID: %d", currentOrder, currentProduct);

        int targetX, targetY;

        if(searchAndPickProduct(currentProduct, &targetX, &targetY)) {
            printf("\n[AGV] Product located at [%d, %d]. Calculating route...", targetX, targetY);

            if (solvePath(map, 0, 0, targetX, targetY)) {
                printf("\n[AGV] Route found");
                printMap(map);

                for (int i = 0; i < SIZE; i++) {
                    for(int j = 0; j < SIZE; j++) {
                        if(map[i][j] == 2) map[i][j] = 0;
                    }
                }

                push(bucket, currentOrder, currentProduct);
                printf("\n[AGV] Product placed in the truck bed. Returning to the coordinate [0, 0]...");

                int orderUnloaded, productUnloaded;
                pop(bucket, &orderUnloaded, &productUnloaded);
                printf("\n[AGV] Product unloaded.");

                deliveryRecord = addOrderID(deliveryRecord, orderUnloaded);
                printf("\n[SYS] Request %d registered in the audit.", orderUnloaded);
            } else printf("\n[AGV] Error! Route unavailable.");
        } else printf("\n[AGV] Product %d not found in warehouse.", currentProduct);
    }

    int ordersToCheck[] = {1050, 1051, 1052, 1099};

    for (int i = 0; i < 4; i++) {
        if (searchOrderID(deliveryRecord, ordersToCheck[i])) {
            printf("\n[SYS] Order %d: DELIVERED (Status OK)", ordersToCheck[i]);
        } else {
            printf("\n[SYS] Order %d: NOT FOUND (Status PENDING)", ordersToCheck[i]);
        }
    }
}