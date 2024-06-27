
#include <limits.h>

#define INF INT_MAX

// Estrutura para representar uma aresta no grafo
typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

// Estrutura para representar um nó no grafo
typedef struct Node {
    Edge* head;
} Node;

// Estrutura para representar um grafo
typedef struct Graph {
    int numVertices;
    Node* adjList;
} Graph;
