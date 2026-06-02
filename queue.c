#include "queue.h"

struct queue* createQueue() {
    struct queue* newQueue = (struct queue*) malloc (sizeof(struct queue));

    if (newQueue == NULL) {
        printf("\nError! Memory allocation failed for queue.");
        return NULL;
    }

    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

bool isEmpty (struct queue* queue) {
    if (queue == NULL) return true;

    return (queue->front == NULL);
}

void enqueue (struct queue* queue, int orderID, int productID) {
    if (queue == NULL) {
        printf("\nError! The queue was not initialized (NULL).");
        return;
    }

    struct queueNode* newQueueNode = (struct queueNode*) malloc (sizeof(struct queueNode));
    if (newQueueNode == NULL) {
        printf("Error! Memory allocation failure");
        return;
    }

    newQueueNode->orderID = orderID;
    newQueueNode->productID = productID;
    newQueueNode->next = NULL;

    if (isEmpty(queue)) queue->front = queue->rear = newQueueNode;
    else {
        queue->rear->next = newQueueNode;
        queue->rear = newQueueNode;
    }
}

bool dequeue (struct queue* queue, int* orderID, int* productID) {
    if (isEmpty(queue)) {
        printf("Error! The queue is empty or was not initialized (NULL).");
        return false;
    }
    
    struct queueNode* auxPointer = queue->front;

    *orderID = auxPointer->orderID;
    *productID = auxPointer->productID;

    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;

    free(auxPointer);

    return true;
}