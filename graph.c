#include "graph.h"

struct grafo_{
    int** matriz_adjacencia;
    int tamanho;
};

GRAFO * MyGraph(int N){
    GRAFO * grafo = (GRAFO *) malloc(sizeof(GRAFO));

    if (grafo == NULL){
        free(grafo);
        return NULL;
    }

    grafo->tamanho = (int) malloc(sizeof(int));

    if(grafo->tamanho == NULL){
        free(grafo);
        free(grafo->tamanho);
        return NULL;
    }

    grafo->tamanho = N;

    grafo->matriz_adjacencia = (int **)malloc(sizeof(int*));

    if(grafo->matriz_adjacencia == NULL){
        free(grafo);
        free(grafo->tamanho);
        free(grafo->matriz_adjacencia);
        return NULL;
    }

    int ** matriz[N][N];
    
    for(int i =0; i< N; i++){
        matriz[i][i] = -1;
    }

    grafo->matriz_adjacencia = matriz;

    return grafo;
}
    
int exist_edge(GRAFO* grafo, int v1, int v2){

}
int ** get_adj_vertex(GRAFO* grafo, int posicao);
int remove_edge(GRAFO* grafo, int v1, int v2);
void print_info(GRAFO * grafo);
int number_of_vertexs(GRAFO * grafo);
int remove_graph(GRAFO* grafo);
int add_edge(GRAFO* grafo, int v1, int v2);
int remove_less_weight(GRAFO* grafo);
int * adjacency_matrix(GRAFO* grafo);
