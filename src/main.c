#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
#include"tree.h"

int main() {
    // struct queueNode *q = NULL;

    // add(&q, 10);
    // add(&q, 20);
    // add(&q, 30);
    // printQueue(q);
    // pop(&q);
    // printQueue(q);
    // pop(&q);
    // printQueue(q);
    // pop(&q);
    // printQueue(q);

    struct treeNode *t = NULL;

    insert(&t, 8);
    insert(&t, 6);
    insert(&t, 12);
    insert(&t, 4);
    insert(&t, 7);
    insert(&t, 10);
    insert(&t, 14);
    insert(&t, 1);
    insert(&t, 5);
    insert(&t, 9);
    insert(&t, 11);
    insert(&t, 13);
    insert(&t, 15);
    printTree(t);



    return 0;
}
