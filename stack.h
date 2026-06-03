#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stackNode {
    int orderID;
    int productID;
    struct stackNode* next;
};

struct stack {
    struct stackNode* top;
};

struct stack* initStack();
bool isEmptyStack (struct stack* stack);
void push (struct stack* stack, int orderID, int productID);
bool pop (struct stack* stack, int* orderID, int* productID);

#endif