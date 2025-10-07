#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void my_strcpy1(char *dest, char *src){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';
}


char *my_strcpy2(char *src){
    char *dest = (char*)malloc(strlen(src) * sizeof(char));
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';
    
    return dest;
}


int main(){

    char src[] = "Hello World!";
    char dest[50];

    my_strcpy1(dest,src);
    char *result = my_strcpy2(src);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", result);



    return 0;
}