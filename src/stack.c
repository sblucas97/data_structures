#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

// Stack = LIFO -> last in, first out

struct stackNode *newStackNode(int val) {
    struct stackNode *n = (struct stackNode*) malloc(sizeof(struct stackNode));
    n->val = val;
    n->next = NULL;
    return n;
}

void addStack(struct stackNode** s, int val) {
    if (*s == NULL) {
        *s = newStackNode(val);
        return;
    }

    struct stackNode *temp = *s;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newStackNode(val);
}

int popStack(struct stackNode **s) {
    if (*s == NULL) {
        printf("Stack is empty");
        return -1;
    }

    struct stackNode *temp = *s;
    struct stackNode *prev = NULL;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    int val = NULL;
    if (prev == NULL) {
        val = temp->val;
        *s = NULL;
    } else {
        val = prev->next->val;
        prev->next = NULL;
    }
    return val;
}

void printStack(struct stackNode* s) {
    struct stackNode *temp = s;

    if (temp == NULL) {
        printf("Empty stack\n");
        return;
    }

    while(temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}
