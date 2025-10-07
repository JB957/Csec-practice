#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Forward declarations for new functions in this assignment:
int insert_at(struct Linkedlist *list, int index, int data);
int delete_all(struct Linkedlist *list, int data);

int main(void) {
    // Build initial list: head-first inserts -> 30 -> 20 -> 10 -> NULL
    struct Linkedlist *list = make_list();
    add(list, 10);
    add(list, 20);
    add(list, 30);

    printf("Initial list: ");
    print_list(list);
    printf("Size: %d\n\n", list->size);

    // ---- Test insert_at ----
    // Insert in the middle: index 1
    if (insert_at(list, 1, 40)) {
        printf("After insert_at(list, 1, 40): ");
        print_list(list);
        printf("Size: %d\n\n", list->size);
    } else {
        printf("insert_at failed for index 1\n\n");
    }

    // Insert at tail: index == size (append)
    int tail_index = list->size;
    if (insert_at(list, tail_index, 50)) {
        printf("After insert_at(list, %d, 50): ", tail_index);
        print_list(list);
        printf("Size: %d\n\n", list->size);
    } else {
        printf("insert_at failed for tail index\n\n");
    }

    // Insert at head: index 0
    if (insert_at(list, 0, 60)) {
        printf("After insert_at(list, 0, 60): ");
        print_list(list);
        printf("Size: %d\n\n", list->size);
    } else {
        printf("insert_at failed for index 0\n\n");
    }

    // Invalid index: negative
    if (!insert_at(list, -1, 999)) {
        printf("Correctly rejected insert_at(list, -1, 999)\n\n");
    }

    // Invalid index: > size
    if (!insert_at(list, list->size + 1, 999)) {
        printf("Correctly rejected insert_at(list, size+1, 999)\n\n");
    }

    // ---- Prepare a list to match delete_all example ----
    // Make list: 30->30->10->30->20->30->NULL
    free_memory(list);
    list = make_list();
    add(list, 30);
    add(list, 20);
    add(list, 30);
    add(list, 10);
    add(list, 30);
    add(list, 30);

    printf("Before delete_all(list, 30): ");
    print_list(list);
    printf("Size: %d\n", list->size);

    // ---- Test delete_all ----
    int removed = delete_all(list, 30);
    (void)removed; // not required by spec, but you can print if you want
    printf("After delete_all(list, 30): ");
    print_list(list);
    printf("Size: %d\n\n", list->size);

    free_memory(list);
    return 0;
}

/*
 * insert_at(list, index, data)
 * - Inserts a new node so that it occupies the given index (0-based).
 * - Valid indices: [0, list->size]
 *   - 0 inserts at head.
 *   - list->size appends at end.
 * - Returns 1 on success, 0 on out-of-bounds or allocation failure.
 */
int insert_at(struct Linkedlist *list, int index, int data) {
    if (index < 0 || index > list->size) {
        return 0;
    }

    // New node
    struct Node *node = malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "malloc failed in insert_at\n");
        return 0;
    }
    node->data = data;
    node->next = NULL;

    if (index == 0) {
        // Insert at head
        node->next = list->head;
        list->head = node;
        list->size += 1;
        return 1;
    }

    // Walk to the (index-1)-th node
    struct Node *curr = list->head;
    for (int i = 0; i < index - 1; i++) {
        // Since index <= size and index > 0, curr should be non-NULL here
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;
    list->size += 1;
    return 1;
}

/*
 * delete_all(list, data)
 * - Deletes **all** nodes whose data == data.
 * - Frees each removed node and prints:
 *     "free node with data X" when a node is freed
 *     "skip node with data Y" when a node is not removed
 * - Returns the count of removed nodes (return value not required by the prompt,
 *   but useful for testing).
 */
int delete_all(struct Linkedlist *list, int data) {
    int removed_any = 0;

    struct Node *curr = list->head;
    struct Node *prev = NULL;

    while (curr != NULL) {
        if (curr->data == data) {
            // Remove curr
            struct Node *victim = curr;
            if (prev == NULL) {
                list->head = curr->next;
                curr = list->head;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
            printf("free node with data %d\n", victim->data);
            free(victim);
            list->size -= 1;
            removed_any = 1;  // boolean success
        } else {
            printf("skip node with data %d\n", curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return removed_any; // 1 if anything was deleted, else 0
}
