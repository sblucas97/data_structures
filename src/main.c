#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
#include"avl_tree.h"

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

    struct avlTreeNode *t = NULL;

    insertAvlTree(&t, 8);
    insertAvlTree(&t, 6);
    insertAvlTree(&t, 12);
    insertAvlTree(&t, 4);
    insertAvlTree(&t, 7);
    insertAvlTree(&t, 10);
    insertAvlTree(&t, 14);
    insertAvlTree(&t, 1);
    insertAvlTree(&t, 5);
    insertAvlTree(&t, 9);
    insertAvlTree(&t, 11);
    insertAvlTree(&t, 13);
    insertAvlTree(&t, 15);
    printAvlTree(t);



    return 0;
}
