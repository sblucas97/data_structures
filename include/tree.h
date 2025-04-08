#ifndef TREE_H
#define TREE_H

struct treeNode {
    int val;
    struct treeNode *right;
    struct treeNode *left;
};

struct queue {
    struct treeNode *n;
    struct queue *next;
};

struct treeNode *newtreeNode(int val);
void insert(struct treeNode **tree, int val);
void printTree(struct treeNode *tree);

int isQueueEmpty(struct queue *q);
struct queue *newQueueNode2(struct treeNode *n);
struct treeNode *popQ(struct queue **q);
void addQ(struct queue** q, struct treeNode *n);
void printQueue2(struct queue *q);

#endif
