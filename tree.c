#include "tree.h"

struct treeNode* initNode (int orderID) {
    if (orderID < 0) {
        printf("\nError! invalid order ID");
        return NULL;
    }

    struct treeNode* newNode = (struct treeNode*) malloc (sizeof(struct treeNode));

    if (newNode == NULL) {
        printf("\nError! Memory allocation failed");
        return NULL;
    }

    newNode->orderID = orderID;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct treeNode* addOrderID (struct treeNode* root, int orderID) {
    struct treeNode* auxPointer = root;
    struct treeNode* prevPointer = NULL;

    while (auxPointer != NULL) {
        prevPointer = auxPointer;
        if (auxPointer->orderID > orderID) auxPointer = auxPointer->left;
        else if (auxPointer->orderID <= orderID) auxPointer = auxPointer->right;
    }

    if (prevPointer == NULL) return initNode(orderID);

    auxPointer = initNode(orderID);

    if (prevPointer->orderID > orderID) prevPointer->left = auxPointer;
    else prevPointer->right = auxPointer;

    return root;
}

bool searchOrderID (struct treeNode* root, int orderID) {
    struct treeNode* auxPointer = root;

    while (auxPointer != NULL) {
        if (auxPointer->orderID == orderID) return true;

        if (auxPointer->orderID > orderID) auxPointer = auxPointer->left;
        else if (auxPointer->orderID <= orderID) auxPointer = auxPointer->right;
    }

    return false;
}