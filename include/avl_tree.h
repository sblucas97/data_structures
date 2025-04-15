#ifndef AVL_TREE_H
#define AVL_TREE_H

struct avlTreeNode {
    int val;
    struct avlTreeNode *right;
    struct avlTreeNode *left;
    int height;
};

struct queue {
    struct avlTreeNode *n;
    struct queue *next;
};

struct avlTreeNode *newAvlTreeNode(int val);
void insertAvlTree(struct avlTreeNode **tree, int val);
void printAvlTree(struct avlTreeNode *tree);

int isQueueEmptyAvlTree(struct queue *q);
struct queue *newQueueNodeAvlTree(struct avlTreeNode *n);
struct avlTreeNode *popQueueAvlTree(struct queue **q);
void addQueueAvlTree(struct queue** q, struct avlTreeNode *n);
void printQueueAvlTree(struct queue *q);

#endif
