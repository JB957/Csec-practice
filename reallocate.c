#include<stdio.h>
#include<stdlib.h>

int *my_reallc(int *arr, int size){

    int *newarr = (int*)malloc(size * sizeof(int));
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        newarr[i] = arr[i];
    }
    free(arr);

    return newarr;

}


int main(){
    int *ptr = malloc(5*sizeof(int));
        for(int i=0; i<5; i++){
        ptr[i] = i;
    }

    int *newptr = realloc(ptr, 20*sizeof(int));
        for(int i=5; i<20; i++){
        newptr[i] = i;
    }

    
    for (int i=0; i<20; i++){
        printf("%d ", newptr[i]);
    }
    printf("\n");

    for (int i=0; i<10; i++){
        printf("%d ", ptr[i]);
    }
    printf("\n");

    return 0;
}