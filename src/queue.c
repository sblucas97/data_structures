#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

// Queue = FIFO -> first in, first out

struct queueNode *newQueueNode(int val) {
    struct queueNode *n = (struct queueNode*) malloc(sizeof(struct queueNode));
    n->val = val;
    n->next = NULL;
    return n;
}

void add(struct queueNode** q, int val) {
    if (*q == NULL) {
        *q = newQueueNode(val);
        return;
    }

    struct queueNode *temp = *q;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newQueueNode(val);
}

int pop(struct queueNode **q) {
    if (*q == NULL) {
        printf("Queue is empty");
        return -1;
    }

    *q = (*q)->next;
}

void printQueue(struct queueNode* q) {
    struct queueNode *temp = q;

    if (temp == NULL) {
        printf("Empty queue\n");
        return;
    }

    while(temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}
