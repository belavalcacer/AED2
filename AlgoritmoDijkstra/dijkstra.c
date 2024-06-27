#include "dijkstra.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó de aresta
Edge *createEdge(int dest, int weight) {
  Edge *newEdge = (Edge *)malloc(sizeof(Edge));
  newEdge->dest = dest;
  newEdge->weight = weight;
  newEdge->next = NULL;
  return newEdge;
}

// Função para criar um grafo com V vértices
Graph *createGraph(int V) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = V;
  graph->adjList = (Node *)malloc(V * sizeof(Node));
  for (int i = 0; i < V; ++i) {
    graph->adjList[i].head = NULL;
  }
  return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph *graph, int src, int dest, int weight) {
  Edge *newEdge = createEdge(dest, weight);
  newEdge->next = graph->adjList[src].head;
  graph->adjList[src].head = newEdge;

  // Para grafos não direcionados, adicione também a aresta inversa
  newEdge = createEdge(src, weight);
  newEdge->next = graph->adjList[dest].head;
  graph->adjList[dest].head = newEdge;
}

// Função para encontrar o vértice com a menor distância que ainda não foi
// processado
int minDistance(int dist[], int sptSet[], int V) {
  int min = INF, min_index;

  for (int v = 0; v < V; v++)
    if (sptSet[v] == 0 && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

// Função para imprimir a solução
void printSolution(int dist[], int V) {
  printf("Vertice \tDistancia da origem\n");
  for (int i = 0; i < V; i++)
    printf("%d\t%d\n", i, dist[i]);
}

// Função para implementar o algoritmo de Dijkstra
void dijkstra(Graph *graph, int src) {
  int V = graph->numVertices;
  int dist[V];
  int sptSet[V];

  // Inicializa as distâncias como infinitas e sptSet como falso
  for (int i = 0; i < V; i++)
    dist[i] = INF, sptSet[i] = 0;

  // Distância da origem para ela mesma é sempre 0
  dist[src] = 0;

  // Encontra o caminho mais curto para todos os vértices
  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet, V);

    sptSet[u] = 1;

    // Atualiza o valor da distância dos vértices adjacentes do vértice
    // escolhido
    Edge *pCrawl = graph->adjList[u].head;
    while (pCrawl != NULL) {
      int v = pCrawl->dest;

      if (!sptSet[v] && dist[u] != INF && dist[u] + pCrawl->weight < dist[v])
        dist[v] = dist[u] + pCrawl->weight;

      pCrawl = pCrawl->next;
    }
  }

  printSolution(dist, V);
}
