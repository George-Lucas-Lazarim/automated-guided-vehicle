#include "queue.h"

struct queue* createQueue() {
    struct queue* newQueue = (struct queue*) malloc (sizeof(struct queue));
    if (newQueue == NULL) return newQueue;

    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

bool isEmpty (struct queue* queue) {
    return (queue->front == NULL);
}

void enqueue (struct queue* queue, int orderID, int productID) {
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

struct queueNode* dequeue (struct queue* queue) {
    if (isEmpty(queue)) {
        printf("Error! The queue is empty");
        return NULL;
    } else  {
        struct queueNode* auxPointer = queue->front;

        queue->front = queue->front->next;
        if (queue->front == NULL) queue->rear = NULL;

        return auxPointer;
    }
}