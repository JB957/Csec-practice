#include<stdio.h>
#include<stdlib.h>

void *create_arr(int arr[]){
    for (int i=0; i<10; i++){
    arr[i] = i*10;
    }
}

int *create_dynamic_arr(){
    int *arr =(int*)malloc(10*sizeof(int));

    for (int i=0; i<10; i++){
        arr[i] = i*10;
    }

    return arr;
}

int main(){
    // int arr[10]; // {0, 10, ..., 90}
    int *arr = create_dynamic_arr();
    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}