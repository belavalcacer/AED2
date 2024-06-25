#include <stdio.h>
#include <stdlib.h>
#include "matriz-grafos.h"

// Função principal para testar o TAD de grafo
int main() {
    // Cria um grafo de 5 vértices
    int V = 5;
    Graph* graph = createGraph(V);

    // Adiciona arestas ao grafo
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Imprime o grafo
    printGraph(graph);

    // Libera a memória alocada para o grafo
    freeGraph(graph);

    return 0;
}
