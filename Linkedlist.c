#include<stdio.h>
#include<stdlib.h>


struct Node{
    int value;
    struct Node *next;
};

struct LinkedList{
    int size;
    struct Node *head;
};

struct LinkedList make_list(){
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size=0;
}

void add_node(struct LinkedList *list, int value){
    struct Node *next = malloc(sizeof(struct Node));
    next->value = value;
    next->next = list->head;
    list->head = next;
    list->size ++;
}

int manin(){

}