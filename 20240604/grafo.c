#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Função para criar um novo nó na lista de adjacências
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com V vértices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = V;

    // Cria um array de listas de adjacências. O tamanho do array é V
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    // Inicializa cada lista de adjacências como vazia
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Função para adicionar uma aresta no grafo
void addEdge(Graph* graph, int src, int dest) {
    // Adiciona uma aresta de src para dest. Um novo nó é adicionado na lista de adjacências de src
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Como o grafo é não direcionado, adiciona uma aresta de dest para src também
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Lista de adjacências do vértice %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada para o grafo
void freeGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}
