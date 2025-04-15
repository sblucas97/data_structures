#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"avl_tree.h"

/*
TODOS:
1. use the height variable properly
2. add rotations functions
*/
struct avlTreeNode *newAvlTreeNode(int val) {
    struct avlTreeNode *n = (struct avlTreeNode *) malloc(sizeof(struct avlTreeNode));

    n->val = val;
    n->right = NULL;
    n->left = NULL;
    n->height = 0;

    return n;
}

void insertAvlTree(struct avlTreeNode **tree, int val) {
    struct avlTreeNode *n = newAvlTreeNode(val);
    if (*tree == NULL) {
        *tree = n;
    } else {
        struct avlTreeNode *temp = *tree;
        struct avlTreeNode *prev = NULL;
        assert(temp != NULL);

        do {
            prev = temp;
            if (val > temp->val) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        } while(temp != NULL);

        if (val > prev->val) {
            prev->right = n;
        } else {
            prev->left = n;
        }

    }
}

void printAvlTree(struct avlTreeNode *tree) {
    if (tree == NULL) {
        printf("Empty Tree\n");
        return;
    }

    struct queue *q = NULL;
    addQueueAvlTree(&q, tree);

    while(isQueueEmptyAvlTree(q) == 0) {
        struct avlTreeNode *temp = popQueueAvlTree(&q);
        printf("%d ", temp->val);
        if (temp->left != NULL) {
            addQueueAvlTree(&q, temp->left);
        }
        if (temp->right != NULL) {
            addQueueAvlTree(&q, temp->right);
        }
    }
}

int isQueueEmptyAvlTree(struct queue *q) {
    if (q == NULL) {
        return 1;
    } else {
        return 0;
    }
}
struct queue *newQueueNodeAvlTree(struct avlTreeNode *n) {
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->n= n;
    q->next = NULL;
    return q;
}

struct avlTreeNode *popQueueAvlTree(struct queue **q) {
    if (*q == NULL) {
        printf("Queue is empty");
        return NULL;
    }
    struct avlTreeNode *temp = (*q)->n;
    *q = (*q)->next;
    return temp;
}

void addQueueAvlTree(struct queue** q, struct avlTreeNode *n) {
    if (*q == NULL) {
        *q = newQueueNodeAvlTree(n);
        return;
    }

    struct queue *temp = *q;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newQueueNodeAvlTree(n);
}

void printQueueAvlTree(struct queue* q) {
    printf("Printinf queue from tree file\n");
    struct queue *temp = q;

    if (temp == NULL) {
        printf("Empty queue\n");
        return;
    }

    while(temp != NULL) {
        printf("%d\n", temp->n->val);
        temp = temp->next;
    }
}
