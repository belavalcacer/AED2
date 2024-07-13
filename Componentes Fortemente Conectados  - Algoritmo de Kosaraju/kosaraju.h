typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    int V;
    No** adj;
} Grafo;


No* criarNo(int valor);
Grafo* criarGrafo(int V);
void adicionarAresta(Grafo* grafo, int origem, int destino);
void imprimirGrafo(Grafo* grafo);
void preencherOrdem(int v, bool visitado[], int* pilha, int* topo, Grafo* grafo);
void DFS(int v, bool visitado[], Grafo* grafo);
Grafo* obterTransposto(Grafo* grafo);
void imprimirComponentes(Grafo* grafo);