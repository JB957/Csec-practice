#include<stdio.h>
#include<stdlib.h>


int main(){

    int a=10,b=20,c=30;

    int *arr[3] = {&a,&b,&c};

    for (int i = 0; i < 3; i++) {
    printf("Value that arr[%d] points to = %d\n", i, *arr[i]);
    }

    return 0;
}