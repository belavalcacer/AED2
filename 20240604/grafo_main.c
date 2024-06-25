#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    // Cria um grafo de 4 vértices
    int V = 4;
    Graph* graph = createGraph(V);

    // Adiciona arestas ao grafo
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Imprime o grafo
    printGraph(graph);

    // Libera a memória alocada para o grafo
    freeGraph(graph);

    return 0;
}