#include <stdio.h>

// Função para ordenar um array usando o algoritmo de insertion sort
void insertionSort(int arr[], int n) {
    int i, j, chave;

    // Percorre todos os elementos do array, exceto o primeiro (índice 0)
    for (i = 1; i < n; i++) {
        // Define o elemento atual como a "chave" para comparar e inserir
        chave = arr[i];
        // Define o índice anterior ao elemento atual
        j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        // até encontrar a posição correta para inserir a chave
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insere a chave na posição correta
        arr[j + 1] = chave;
    }
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {12, 5, 7, 4, 15, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chama a função de ordenação
    insertionSort(arr, n);

    // Imprime o array ordenado
    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}



