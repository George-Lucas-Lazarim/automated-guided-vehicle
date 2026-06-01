#include "queue.h"

struct queue* createQueue() {
    struct queue* newQueue = (struct queue*) malloc (sizeof(struct queue));
    if (newQueue == NULL) return newQueue;

    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}
