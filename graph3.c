#include "graph.h"


struct grafo_{
    int** matriz_adjacencia;
    int tamanho;
};

int add_edge(GRAFO* grafo, int v1, int v2);
int remove_less_weight(GRAFO* grafo);
int * adjacency_matrix(GRAFO* grafo);
