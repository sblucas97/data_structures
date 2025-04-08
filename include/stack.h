#ifndef STACK_H
#define STACK_H

struct stackNode {
    int val;
    struct stackNode* next;
};

struct stackNode *newStackNode(int val);
int popStack(struct stackNode **s);
void addStack(struct stackNode **s, int val);
void printStack(struct stackNode* s);

#endif
