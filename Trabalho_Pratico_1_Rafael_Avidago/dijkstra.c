#include "prototipo.h"

//insere o novo custo em um array
void insereNovoCusto(int distancias[], int k, int novoCusto) {
    int i;
    for (i = k-1; i > 0 && distancias[i-1] > novoCusto; i--) { //encontra a posicao correta do final do array (menor custo) e retrocede enquanto custo anterior maior que o novo
        distancias[i] = distancias[i-1];
    }
    distancias[i] = novoCusto;
}

//dijkstra modificado para encontrar os k caminhos magicos
void dijkstra(ListaAdjacencia* listaAdj, int n, int k, int distancias[][k]) {
    //inicializa todas as distancias como infinito
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            distancias[i][j] = INT_MAX;
        }
    }
    //Define custo do caminho para o vertice inicial como 0
    distancias[1][0] = 0;

    //inicia fp
    FilaPrioridade fp;
    inicializaFilaPrioridade(&fp, 10); 
    //insere o vertice de origem na fp com o custo 0
    insere(&fp, (No){1, 0});

    while (fp.tamanho > 0) { //enquanto houver vertices na fila
        No atual = pop(&fp); //remove o vertice com o menor caminho
        for (NoAresta* p = listaAdj[atual.vertice].cabeca; p != NULL; p = p->proximo) { //loop que passa por todos os vizinhos de um vertice.
            int novoCusto = atual.custo + p->aresta.peso; //calcula custo para vertice adjacente

            if (novoCusto < distancias[p->aresta.destino][k - 1]) { //se novo custo < k menores custos ja encontrados
                insereNovoCusto(distancias[p->aresta.destino], k, novoCusto); //novo custo e adcionado
                insere(&fp, (No){p->aresta.destino, novoCusto});
            }
        }
    }
    liberaFilaPrioridade(&fp);

}