// Estrutura para representar o grafo
typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;

//Assinatura das funções
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);