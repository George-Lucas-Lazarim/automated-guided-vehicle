#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode {
    int orderID;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* initNode (int orderID);
struct treeNode* addOrderID (struct treeNode* root, int orderID);
bool searchOrderID (struct treeNode* root, int orderID);

#endif