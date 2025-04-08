#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int get_list_size(struct listNode **list) {
    if (*list == NULL) {
        return 0;
    }

    int s = 1;
    struct listNode *temp = *list;
    while(temp->next != NULL) {
        temp = temp->next;
        s++;
    };

    return s;
}

void print_list(struct listNode *list) {
    if (list == NULL) {
        printf("list is empty");
        return;
    }

    struct listNode *temp = list;
    while (temp != NULL) {
        printf("Value: %d\n", temp->value);
        temp = temp->next;
    }
}

struct listNode *new_listNode(int val) {
    struct listNode *newlistNode = (struct listNode *)malloc(sizeof(struct listNode));
    newlistNode->value = val;
    newlistNode->next = NULL;

    return newlistNode;
}

void insert_list(struct listNode **list, int val) {
    struct listNode *n = new_listNode(val);
    if (*list == NULL) {
        *list = n;
    } else {
        struct listNode *temp = *list;
        while(temp->next != NULL) {
            temp = temp->next;
        };
        temp->next = n;
    }
}

void remove_last(struct listNode **list) {
    if (list == NULL) {
        printf("list is empty");
        return;
    }

    struct listNode *temp = *list;
    struct listNode *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    };

    prev->next = NULL;
}

void remove_first(struct listNode **list) {
    if (list == NULL) {
        printf("list is empty");
        return;
    }

    *list = (*list)->next;
}

void remove_at(struct listNode **list, int idx) {
    if (*list == NULL) {
        printf("List is empty.");
        return;
    }

    int s = get_list_size(list);
    if (idx < 0 || s-1 < idx) {
        printf("Index out of bound\n");
    }

    int i = 0;
    struct listNode *temp = *list;
    while (i != idx) {
        temp = temp->next;
        i++;
    }

    temp->next = temp->next->next;
}

void insert_after(struct listNode **list, int idx, int val) {
    if (*list == NULL) {
        printf("list is empty");
        return;
    }

    int s = get_list_size(list);
    if (idx < 0 || s-1 < idx) {
        printf("Index out of bound\n");
    }

    int i = 0;
    struct listNode *temp = *list;
    while (i < idx) {
        temp = temp->next;
        i++;
    }

    struct listNode *n = new_listNode(val);
    struct listNode *aux = NULL;
    aux = temp->next;
    temp->next = n;
    temp->next->next = aux;
}
