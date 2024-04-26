#include <stdio.h>
#include <stdlib.h>
#include "quick.h"


// Função principal
int main() {
    // Vetor a) C=(27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0)
    int arr_a[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    int n_a = sizeof(arr_a) / sizeof(arr_a[0]);

    printf("Array original (a):\n");
    printArray(arr_a, n_a);
    quickSort(arr_a, 0, n_a - 1);
    printf("\nArray ordenado (a):\n");
    printArray(arr_a, n_a);

    // Vetor b) A=(5, 3, 17, 10,84, 19,6,22,9)
    int arr_b[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    int n_b = sizeof(arr_b) / sizeof(arr_b[0]);

    printf("\nArray original (b):\n");
    printArray(arr_b, n_b);
    quickSort(arr_b, 0, n_b - 1);
    printf("\nArray ordenado (b):\n");
    printArray(arr_b, n_b);

    // Vetor c) B=(5, 13, 2,25,7,17,20,8,4)
    int arr_c[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n_c = sizeof(arr_c) / sizeof(arr_c[0]);

    printf("\nArray original (c):\n");
    printArray(arr_c, n_c);
    quickSort(arr_c, 0, n_c - 1);
    printf("\nArray ordenado (c):\n");
    printArray(arr_c, n_c);

    return 0;
}
