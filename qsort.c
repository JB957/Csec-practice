#include<stdio.h>
#include<stdlib.h>

 #include <stdio.h>
#include <stdlib.h>

// Comparison function for integers
int compare_ints(const void *a, const void *b) {
    // Cast to int pointers, then dereference
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return (int_a - int_b);
}

int main() {
    int arr[] = { 42, 7, 13, 99, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare_ints);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
