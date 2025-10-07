#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Linkedlist {
    struct Node *head;
    int size;
};

// Core list operations
struct Linkedlist *make_list(void);
void add(struct Linkedlist *list, int data);
void print_list(struct Linkedlist *list);
int  delete_one(struct Linkedlist *list, int data);
void free_memory(struct Linkedlist *list);

#endif // LINKEDLIST_H
