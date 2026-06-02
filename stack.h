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

void initStack();
bool isEmpty();
void push (int orderID, int productID);
bool pop (int* orderID, int* productID);

#endif