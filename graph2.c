#include "graph.h"


struct grafo_{
    int** matriz_adjacencia;
    int tamanho;
};

int remove_edge(GRAFO* grafo, int v1, int v2) {
  grafo->matriz_adjacencia[v1][v2] = -1;
  return 1;
}

void print_info(GRAFO * grafo) {
  for(int i=0; i<grafo->tamanho; i++) {
    for(int j=0; j<grafo->tamanho; j++) {
      printf("%d ", grafo->matriz_adjacencia[i][j]);
    }
    printf("\n");
  }
}

int number_of_vertexs(GRAFO * grafo) {
  return grafo->tamanho;
}

int remove_graph(GRAFO* grafo) {
  for(int i=0; i<grafo->tamanho; i++) {
    free(grafo->matriz_adjacencia[i]);
  }
  free(grafo->matriz_adjacencia);
  free(grafo);
  return 1;
}

int add_edge(GRAFO* grafo, int v1, int v2, int peso) {
  grafo->matriz_adjacencia[v1][v2] = peso;
  return 1;
}

int remove_less_weight(GRAFO* grafo) {
  int menorI = 0, menorJ = 0;
  for(int i=0; i<grafo->tamanho; i++) {
    for(int j=0; j<grafo->tamanho; j++) {
      if(grafo->matriz_adjacencia[i][j] < grafo->matriz_adjacencia[menorI][menorJ]) {
        menorI = i;
        menorJ = j;
      }
    }
  }
  grafo->matriz_adjacencia[menorI][menorJ] = -1;
  return 1;
}

int ** adjacency_matrix(GRAFO* grafo) {
  return grafo->matriz_adjacencia;
}
