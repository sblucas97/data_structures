#ifndef LIST_H
#define LIST_H

struct listNode {
    int value;
    struct listNode *next;
};

int get_list_size(struct listNode **list);
void print_list(struct listNode *list);
struct listNode *new_listNode(int val);
void insert_list(struct listNode **list, int val);
void remove_last(struct listNode **list);
void remove_first(struct listNode **list);
void remove_at(struct listNode **list, int idx);
void insert_after(struct listNode **list, int idx, int val);

#endif
