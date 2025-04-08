#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"tree.h"

struct treeNode *newtreeNode(int val) {
    struct treeNode *n = (struct treeNode *) malloc(sizeof(struct treeNode));

    n->val = val;
    n->right = NULL;
    n->left = NULL;

    return n;
}

void insert(struct treeNode **tree, int val) {
    struct treeNode *n = newtreeNode(val);
    if (*tree == NULL) {
        *tree = n;
    } else {
        struct treeNode *temp = *tree;
        struct treeNode *prev = NULL;
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

void printTree(struct treeNode *tree) {
    if (tree == NULL) {
        printf("Empty Tree\n");
        return;
    }

    struct queue *q = NULL;
    addQ(&q, tree);

    while(isQueueEmpty(q) == 0) {
        struct treeNode *temp = popQ(&q);
        printf("%d ", temp->val);
        if (temp->left != NULL) {
            addQ(&q, temp->left);
        }
        if (temp->right != NULL) {
            addQ(&q, temp->right);
        }
    }
}

int isQueueEmpty(struct queue *q) {
    if (q == NULL) {
        return 1;
    } else {
        return 0;
    }
}
struct queue *newQueueNode2(struct treeNode *n) {
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->n= n;
    q->next = NULL;
    return q;
}

struct treeNode *popQ(struct queue **q) {
    if (*q == NULL) {
        printf("Queue is empty");
        return NULL;
    }
    struct treeNode *temp = (*q)->n;
    *q = (*q)->next;
    return temp;
}

void addQ(struct queue** q, struct treeNode *n) {
    if (*q == NULL) {
        *q = newQueueNode2(n);
        return;
    }

    struct queue *temp = *q;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newQueueNode2(n);
}

void printQueue2(struct queue* q) {
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
