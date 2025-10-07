#include "linkedlist.h"


int main(void) {
    struct Linkedlist *list = make_list();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    delete_one(list, 30);

    print_list(list); // Expected: 30 -> 20 -> 10 -> NULL

    free_memory(list);
    return 0;
}

struct Linkedlist *make_list(void) {
    struct Linkedlist *list = malloc(sizeof(struct Linkedlist));
    if (!list) {
        fprintf(stderr, "malloc failed in make_list\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(struct Linkedlist *list, int data) {
    struct Node *newnode = malloc(sizeof(struct Node));
    if (!newnode) {
        fprintf(stderr, "malloc failed in add\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = list->head;

    list->head = newnode;
    list->size += 1;
}

void print_list(struct Linkedlist *list) {
    struct Node *curr = list->head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}


int delete_one(struct Linkedlist *list, int data) {
    struct Node *curr = list->head;
    struct Node *prev = NULL;

    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                // removing head
                list->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            list->size -= 1;
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

void free_memory(struct Linkedlist *list) {
    struct Node *curr = list->head;
    while (curr != NULL) {
        struct Node *next = curr->next;
        printf("Deallocating the node %d...\n", curr->data);
        free(curr);
        curr = next;
    }
    free(list);
}
