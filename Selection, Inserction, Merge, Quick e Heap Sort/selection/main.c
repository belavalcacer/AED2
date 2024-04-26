#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Percorre a lista
    for (i = 0; i < n - 1; i++) {
        // Encontra o índice do menor elemento na lista não ordenada
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento com o primeiro elemento não ordenado
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Função para imprimir a lista
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
