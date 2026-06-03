#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queueNode {
    int orderID;
    int productID;
    struct queueNode* next;
};

struct queue {
    struct queueNode* front;
    struct queueNode* rear;  
};

struct queue* initQueue();
bool isEmptyQueue (struct queue* queue);
void enqueue (struct queue* queue, int orderID, int productID);
bool dequeue (struct queue* queue, int* orderID, int* productID);

#endif