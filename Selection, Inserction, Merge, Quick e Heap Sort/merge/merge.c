#include <stdio.h>
#include <stdlib.h>
#include "merge.h"


// Função para mesclar duas sublistas ordenadas
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Mescla os arrays temporários de volta em arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontra o ponto médio para dividir a matriz em dois
        int middle = left + (right - left) / 2;

        // Ordena a primeira e a segunda metades
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Mescla as metades ordenadas
        merge(arr, left, middle, right);
    }
}

// Função para imprimir uma matriz
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
