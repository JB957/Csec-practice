/*
To run this test file, commment out main() in assignment5.c and linkedlist2.c
To compile,
gcc linkedlist2.c assignment5.c delete_all_test.c -o delete_all_test 
To run this test file,
./delete_all_test
*/


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"

int delete_all(struct Linkedlist *list, int data);

struct Linkedlist *makelist_10(){ // 10->NULL
    struct Linkedlist *list = make_list();
    struct Node *node1 = malloc(sizeof(struct Node));
    node1->data = 10;
    node1->next = NULL;
    
    list->head = node1;
    list->size = 1;
    return list;
}

struct Linkedlist *makelist_20_10(){// 20->10->NULL
    struct Linkedlist *list = make_list();
    struct Node *node1 = malloc(sizeof(struct Node));
    node1->data = 10;
    node1->next = NULL;
    
    struct Node *node2 = malloc(sizeof(struct Node));
    node2->data = 20;
    node2->next = node1;

    list->head = node2;
    list->size = 2;
    return list;
}

struct Linkedlist *makelist_30_30(){ // 30->30->NULL
    struct Linkedlist *list = make_list();
    struct Node *node1 = malloc(sizeof(struct Node));
    node1->data = 30;
    node1->next = NULL;
    
    struct Node *node2 = malloc(sizeof(struct Node));
    node2->data = 30;
    node2->next = node1;

    list->head = node2;
    list->size = 2;
    return list;
}

struct Linkedlist *makelist_30_5_30(){
    // 20->10->NULL
    struct Linkedlist *list = make_list();
    struct Node *node1 = malloc(sizeof(struct Node));
    node1->data = 30;
    node1->next = NULL;
    
    struct Node *node2 = malloc(sizeof(struct Node));
    node2->data = 5;
    node2->next = node1;

    struct Node *node3 = malloc(sizeof(struct Node));
    node3->data = 30;
    node3->next = node2;

    list->head = node3;
    list->size = 3;
    return list;
}

void test_delete_all_1(){
    struct Linkedlist *list = makelist_10(); // 10->NULL
    int result = delete_all(list, 5); // fail
    assert(result == 0);
    assert(list->size == 1);
    assert(list->head->data == 10);
    assert(list->head->next == NULL);
}

void test_delete_all_2(){
    struct Linkedlist *list = makelist_10(); // 10->NULL
    
    int result = delete_all(list, 10); 
    assert(result == 1);
    assert(list->size == 0);
    assert(list->head == NULL);
}


void test_delete_all_3(){
    struct Linkedlist *list = makelist_20_10(); // 20->10->NULL
   

    int result = delete_all(list, 10); 
    assert(result == 1);
    assert(list->size == 1);
    assert(list->head != NULL);
    assert(list->head->data == 20);
    assert(list->head->next == NULL);
}

void test_delete_all_4(){
    struct Linkedlist *list = makelist_20_10(); // 20->10->NULL
    
    int result = delete_all(list, 20); 
    assert(result == 1);
    assert(list->size == 1);
    assert(list->head != NULL);
    assert(list->head->data == 10);
    assert(list->head->next == NULL);
}
void test_delete_all_5(){
    struct Linkedlist *list = makelist_30_30(); // 30->30->NULL
    
    int result = delete_all(list, 30); 
    assert(result == 1);
    assert(list->size == 0);
    assert(list->head == NULL);
}

void test_delete_all_6(){
    struct Linkedlist *list = makelist_30_5_30(); // 30->5->30->NULL
    
    int result = delete_all(list, 30); 
    assert(result == 1);
    assert(list->size == 1);
    assert(list->head != NULL);
    assert(list->head->data == 5);
    assert(list->head->next == NULL);
}

void test_delete_all_7(){
    struct Linkedlist *list = makelist_30_5_30(); // 30->5->30->NULL
    
    int result = delete_all(list, 5); 
    assert(result == 1);
    assert(list->size == 2);
    assert(list->head != NULL);
    assert(list->head->data == 30);
    assert(list->head->next != NULL);
    assert(list->head->next->data == 30);
    assert(list->head->next->next == NULL);
}

int main(){
    test_delete_all_1();
    test_delete_all_2();
    test_delete_all_3();
    test_delete_all_4();
    test_delete_all_5();
    test_delete_all_6();
    test_delete_all_7();

    printf("All tests for delete_all passed!");
}

