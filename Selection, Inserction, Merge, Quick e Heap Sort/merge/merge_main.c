#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

// Função principal
int main() {
    int arr[] = {31, 41, 59, 26, 41, 58};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, arr_size);

    // Chama a função mergeSort()
    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado:\n");
    printArray(arr, arr_size);
    return 0;
}
