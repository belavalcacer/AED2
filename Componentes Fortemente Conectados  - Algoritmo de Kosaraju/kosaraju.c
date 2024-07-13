#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "kosaraju.h"

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

Grafo* criarGrafo(int V) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = V;
    grafo->adj = (No**)malloc(V * sizeof(No*));
    for (int i = 0; i < V; i++) {
        grafo->adj[i] = NULL;
    }
    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = criarNo(destino);
    novoNo->proximo = grafo->adj[origem];
    grafo->adj[origem] = novoNo;
}

void imprimirGrafo(Grafo* grafo) {
    for (int v = 0; v < grafo->V; v++) {
        No* no = grafo->adj[v];
        printf("%d: ", v);
        while (no != NULL) {
            printf("%d -> ", no->valor);
            no = no->proximo;
        }
        printf("NULL\n");
    }
}

void preencherOrdem(int v, bool visitado[], int* pilha, int* topo, Grafo* grafo) {
    visitado[v] = true;

    No* no = grafo->adj[v];
    while (no != NULL) {
        if (!visitado[no->valor]) {
            preencherOrdem(no->valor, visitado, pilha, topo, grafo);
        }
        no = no->proximo;
    }

    pilha[++(*topo)] = v;
}

void DFS(int v, bool visitado[], Grafo* grafo) {
    visitado[v] = true;
    printf("%d ", v);

    No* no = grafo->adj[v];
    while (no != NULL) {
        if (!visitado[no->valor]) {
            DFS(no->valor, visitado, grafo);
        }
        no = no->proximo;
    }
}

Grafo* obterTransposto(Grafo* grafo) {
    Grafo* transposto = criarGrafo(grafo->V);

    for (int v = 0; v < grafo->V; v++) {
        No* no = grafo->adj[v];
        while (no != NULL) {
            adicionarAresta(transposto, no->valor, v);
            no = no->proximo;
        }
    }

    return transposto;
}

void imprimirComponentes(Grafo* grafo) {
    int pilha[grafo->V];
    int topo = -1;
    bool* visitado = (bool*)malloc(grafo->V * sizeof(bool));

    for (int i = 0; i < grafo->V; i++) {
        visitado[i] = false;
    }

    for (int i = 0; i < grafo->V; i++) {
        if (!visitado[i]) {
            preencherOrdem(i, visitado, pilha, &topo, grafo);
        }
    }

    Grafo* transposto = obterTransposto(grafo);

    printf("\nGrafo Original:\n");
    imprimirGrafo(grafo);

    printf("\nGrafo Transposto:\n");
    imprimirGrafo(transposto);

    for (int i = 0; i < grafo->V; i++) {
        visitado[i] = false;
    }

    printf("\nComponentes Fortemente Conectadas:\n");
    while (topo != -1) {
        int v = pilha[topo--];

        if (!visitado[v]) {
            DFS(v, visitado, transposto);
            printf("\n");
        }
    }

    free(visitado);
    for (int i = 0; i < transposto->V; i++) {
        No* no = transposto->adj[i];
        while (no != NULL) {
            No* temp = no;
            no = no->proximo;
            free(temp);
        }
    }
    free(transposto->adj);
    free(transposto);
}