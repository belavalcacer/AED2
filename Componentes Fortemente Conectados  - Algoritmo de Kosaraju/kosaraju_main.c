#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "kosaraju.h"

int main() {
    Grafo* grafo = criarGrafo(8);
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 6);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 2);
    adicionarAresta(grafo, 3, 7);
    adicionarAresta(grafo, 4, 0);
    adicionarAresta(grafo, 4, 5);
    adicionarAresta(grafo, 5, 6);
    adicionarAresta(grafo, 6, 5);
    adicionarAresta(grafo, 6, 7);
    adicionarAresta(grafo, 7, 7);
    
    imprimirComponentes(grafo);

    for (int i = 0; i < grafo->V; i++) {
        No* no = grafo->adj[i];
        while (no != NULL) {
            No* temp = no;
            no = no->proximo;
            free(temp);
        }
    }
    free(grafo->adj);
    free(grafo);

    return 0;
}
