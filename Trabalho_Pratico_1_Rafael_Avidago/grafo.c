#include "prototipo.h"

void adicionaAresta(ListaAdjacencia* listaAdj, int origem, int destino, int peso) {
    NoAresta* novoNo = (NoAresta*)malloc(sizeof(NoAresta)); //aloca memoria para novo no de aresta
    novoNo->aresta.destino = destino; //devine o destino da nova aresta
    novoNo->aresta.peso = peso; //define o peso da aresta
    novoNo->proximo = listaAdj[origem].cabeca; //Liga o no a cabeca atual da lista de adjacencia da origem
    listaAdj[origem].cabeca = novoNo; //atualiza a cabeca da lista para o novo no
}