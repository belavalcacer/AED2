#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Função para fazer o Heapify de um subárvore enraizada no índice 'root'
// 'n' é o tamanho do heap
void heapify(int arr[], int n, int root) {
    int largest = root; // Inicializa o maior como raiz
    int left = 2 * root + 1; // Esquerda = 2*i + 1
    int right = 2 * root + 2; // Direita = 2*i + 2

    // Se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != root) {
        // Troca a raiz com o maior
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        // Chama heapify recursivamente na subárvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal para ordenar um array de tamanho 'n' usando o Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um por um os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama max heapify no heap reduzido
        heapify(arr, i, 0);
    }
}

// Função para imprimir um array de tamanho 'n'
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

