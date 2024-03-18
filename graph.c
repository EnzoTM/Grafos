#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct grafo_{
    int* matriz_adjacencia;
};

GRAFO * MyGraph(int N);
    
int exist_edge(GRAFO* grafo, int v1, int v2);
int * get_adj_vertex(GRAFO* grafo, int posicao);
int remove_edge(GRAFO* grafo, int v1, int v2);
void print_info(GRAFO * grafo);
int number_of_vertexs(GRAFO * grafo);
int remove_graph(GRAFO* grafo);
int add_edge(GRAFO* grafo, int v1, int v2);
int remove_less_weight(GRAFO* grafo);
int * adjacency_matrix(GRAFO* grafo);