#ifndef QUEUE_H
#define QUEUE_H

struct queueNode {
    int val;
    struct queueNode* next;
};

struct queueNode *newQueueNode(int val);
int pop(struct queueNode **q);
void add(struct queueNode **q, int val);
void printQueue(struct queueNode* q);

#endif
