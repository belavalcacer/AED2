// Estrutura para os nós da lista de adjacências
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Estrutura para representar uma lista de adjacências
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Estrutura para representar o grafo
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

AdjListNode* newAdjListNode(int dest);
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);