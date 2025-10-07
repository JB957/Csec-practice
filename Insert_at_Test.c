/*
To run this test file, commment out main() in assignment5.c and linkedlist2.c
To compile,
gcc linkedlist2.c assignment5.c insert_at_test.c -o insert_at_test 
To run this test file,
./insert_at_test
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"

int insert_at(struct Linkedlist *list, int index, int data);

void test_insert_at_0_1(){
    struct Linkedlist *list = make_list();
    int result = insert_at(list, 0, 10);
    assert(result == 1);
    assert(list->size == 1);
    assert(list->head->data == 10);
    assert(list->head->next == NULL);
}

void test_insert_at_1_1(){ // invalid index
    struct Linkedlist *list = make_list();
    int result = insert_at(list, 1, 10);
    assert(result == 0);
    assert(list->size == 0);
    assert(list->head == NULL);
}

void test_insert_at_1_2(){
    struct Linkedlist *list = make_list();
    struct Node *node = malloc(sizeof(struct Node));
    node->data = 10;
    node->next = NULL;
    list->head = node;
    list->size = 1;

    int result = insert_at(list, 1, 20);
    assert(result == 1);
    assert(list->size == 2);
    assert(list->head->data == 10);
    assert(list->head->next != NULL);
    assert(list->head->next->data == 20);
    assert(list->head->next->next == NULL);
}

void test_insert_at_0_2(){
    struct Linkedlist *list = make_list();
    struct Node *node = malloc(sizeof(struct Node));
    node->data = 10;
    node->next = NULL;
    list->head = node;
    list->size = 1;

    int result = insert_at(list, 0, 20);
    assert(result == 1);
    assert(list->size == 2);
    assert(list->head->data == 20);
    assert(list->head->next != NULL);
    assert(list->head->next->data == 10);
    assert(list->head->next->next == NULL);
}

void test_insert_at_2_2(){  // invalid index
    struct Linkedlist *list = make_list();
    add(list, 10);
    int result = insert_at(list, 2, 20);
    assert(result == 0);
    assert(list->size == 1);
    assert(list->head->data == 10);
    assert(list->head->next == NULL);
}

void test_insert_at_012_3(){  
    struct Linkedlist *list = make_list();
    insert_at(list, 0, 10);
    insert_at(list, 1, 20);
    int result = insert_at(list, 2, 30);
    assert(result == 1);
    assert(list->size == 3);
    assert(list->head->data == 10);
    assert(list->head->next->data == 20);
    assert(list->head->next->next->data == 30);
    assert(list->head->next->next->next == NULL);
}

void test_insert_at_011_3(){  
    struct Linkedlist *list = make_list();
    insert_at(list, 0, 10);
    insert_at(list, 1, 20);
    int result = insert_at(list, 1, 30);
    assert(result == 1);
    assert(list->size == 3);
    assert(list->head->data == 10);
    assert(list->head->next->data == 30);
    assert(list->head->next->next->data == 20);
    assert(list->head->next->next->next == NULL);
}

void test_insert_at_000_3(){  
    struct Linkedlist *list = make_list();
    insert_at(list, 0, 10);
    insert_at(list, 0, 20);
    int result = insert_at(list, 0, 30);
    assert(result == 1);
    assert(list->size == 3);
    assert(list->head->data == 30);
    assert(list->head->next->data == 20);
    assert(list->head->next->next->data == 10);
    assert(list->head->next->next->next == NULL);
}

void test_insert_at_001_3(){  
    struct Linkedlist *list = make_list();
    insert_at(list, 0, 10);
    insert_at(list, 0, 20);
    int result = insert_at(list, 1, 30);
    assert(result == 1);
    assert(list->size == 3);
    assert(list->head->data == 20);
    assert(list->head->next->data == 30);
    assert(list->head->next->next->data == 10);
    assert(list->head->next->next->next == NULL);
}

int main(){
    test_insert_at_0_1();
    test_insert_at_1_1();
    test_insert_at_1_2();
    test_insert_at_0_2();
    test_insert_at_2_2();
    test_insert_at_012_3();
    test_insert_at_011_3();
    test_insert_at_000_3();
    test_insert_at_001_3();
    printf("All tests passed for insert_at!");
}

