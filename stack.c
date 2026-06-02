#include "stack.h"

struct stack* initStack() {
    struct stack* stack = (struct stack*) malloc (sizeof(struct stack));

    if (stack == NULL) {
        printf("Error! Memory allocation failed.");
        return;
    }

    stack->top = NULL;

    return stack;
}

bool isEmpty(struct stack* stack) {
    if (stack == NULL) return true;

    return (stack->top == NULL);
}

void push (struct stack* stack, int orderID, int productID) {
    struct stackNode* newStackNode = (struct stackNode*) malloc (sizeof(struct stackNode));

    if (newStackNode == NULL) {
        printf("\nError! Memory allocation failed. Exiting without pushing...");
        return;
    }
    
    newStackNode->orderID = orderID;
    newStackNode->productID = productID;
    newStackNode->next = stack->top;

    stack->top = newStackNode;
}

bool pop (struct stack* stack, int* orderID, int* productID) {
    if (isEmpty(stack)) {
        printf("\nError! The stack is empty or was not initialized (NULL).");
        return false;
    }

    *orderID = stack->top->orderID;
    *productID = stack->top->productID;

    struct stackNode* auxPointer = stack->top;

    stack->top = stack->top->next;

    free(auxPointer);

    return true;
}