#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    int orderID;
    int productID;
    struct queueNode* next;
};

struct queue {
    struct queueNode* front;
    struct queueNode* rear;  
};

struct queue* createQueue();

#endif