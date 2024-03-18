#include "graph.h"


// PARA ESSE TRABALHO ESTAMOS SUPONDO QUE O GRAFO PODE SER ORIENTADO E VALORADO COM INTUITO DE ABRANGER TODOS
// OS POSSÍVEIS GRAFOS
// Caso as linhas da matriz de adjacência seja igual às suas respectivas colunas, o grafo seria não orientado

// Um elemento da linha i está ligado a coluna j


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

    for(int i = 0; i< grafo->tamanho; i++){
        grafo->matriz_adjacencia[i] = (int*) malloc(sizeof(int));
    }


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

    if(grafo == NULL){
        print("Erro: grafo inexistente");
        return ERRO;
    }

    if(v1 < grafo->tamanho && v2 < grafo->tamanho){
        if(grafo->matriz_adjacencia[v1][v2]){
            return 1;
        }

        return 0;
    }

    return 0;
    

}
int ** get_adj_vertex(GRAFO* grafo, int posicao){ // Ver se esse cara funciona

    if(grafo == NULL){
        print("Erro: grafo inexistente");
        return ERRO;
    }

    int * lista;

    for(int i =0, j= 0; i<grafo->tamanho; i++){

        if(i != posicao && grafo->matriz_adjacencia[posicao][i] == grafo->matriz_adjacencia[i][posicao] && grafo->matriz_adjacencia[posicao][i] != -1){ // se o grafo for orientado
            lista[j] = grafo->matriz_adjacencia[posicao][i];
            j++;
        }else{
            if(grafo->matriz_adjacencia[posicao][i] != -1){
                lista[j] = grafo->matriz_adjacencia[posicao][i];
                j++;
            }
            if(grafo->matriz_adjacencia[i][posicao] != -1){
                lista[j] = grafo->matriz_adjacencia[i][posicao];
                j++;
            }
        }


    }
    


    return lista;

}
