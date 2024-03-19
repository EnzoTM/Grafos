#include "graph.h"

int menu() {
  printf("Digite uma opcao:\n");
  printf("0 - Remover o grafo e sair do programa\n");
  printf("1 - Verificar se uma aresta existe\n");
  printf("2 - Vertices adjacentes a determinado vertice\n");
  printf("3 - Remover uma aresta do grafo\n");
  printf("4 - Imprimir vertices e arestas\n");
  printf("5 - Número de vertices no grafo\n");
  printf("6 - Inserir arestas\n");
  printf("7 - Remover aresta de menor peso\n");
}

int main() {
  GRAFO *grafo;
  int N, opcao;

  printf("Numero de vertices do grafo: ");
  scanf("%d", &N);

  grafo = MyGraph(N);

  do {
    menu();
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        int arestaExiste, v1, v2;
        printf("Digite as coordenadas da aresta (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        arestaExiste = exist_edge(grafo, v1, v2);

        if(arestaExiste) {
          printf("A aresta existe\n");
        } else {
          printf("A aresta nao existe\n");
        }
        break;
      
      case 2:
        int vertice, *lista, tam_lista;
        printf("Digite o numero de um vertice: ");
        scanf("%d", &vertice);

        lista = get_adj_vertex(grafo, vertice);
        tam_lista = sizeof(tam_lista) / sizeof(int);

        for(int i=0; i<tam_lista; i++) {
          printf("%d ", &lista[i]);
        }
        printf("\n");
        break;

      case 3:
        int v1, v2;
        printf("Digite as coordenadas da aresta a ser removida (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        remove_edge(grafo, v1, v2);
        break;

      default:
        remove_graph(grafo);
    }
  } while(opcao != 0);

  scanf("%d", &N);
  grafo = MyGraph(N);

  

  return 0;
}