#include<stdio.h>

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int compute(int (*operation)(int,int), int a, int b){

    return operation(a,b);
}



int main(){


    return 0;
}