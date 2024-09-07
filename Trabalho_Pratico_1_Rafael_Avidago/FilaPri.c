#include "prototipo.h"

//inicializa fila e aloca memoria
void inicializaFilaPrioridade(FilaPrioridade *fp, int capacidadeInicial) {
    fp->nos = (No*)malloc(capacidadeInicial * sizeof(No)); 
    fp->tamanho = 0;
    fp->capacidade = capacidadeInicial;
}

//libera a memoria alocada para os nos da fila
void liberaFilaPrioridade(FilaPrioridade *fp) {
    free(fp->nos);
}
//insere e verifica se a fila esta cheia
void insere(FilaPrioridade *fp, No no) {
    if (fp->tamanho == fp->capacidade) { //verifica se a fila esta cheia, caso sim dobra a capacidade
        fp->capacidade *= 2;
        fp->nos = (No*)realloc(fp->nos, fp->capacidade * sizeof(No));
    }
    int i = fp->tamanho++; //Insere o novo no ao final da fila e incrementa o tamnho da fila
    while (i && no.custo < fp->nos[(i - 1) / 2].custo) { //Troca o lugar do no com base no seu custo
        fp->nos[i] = fp->nos[(i - 1) / 2]; //Move os nos para baixo para fazer espaco para o novo
        i = (i - 1) / 2; //Troca o indice para o pai do no atual
    }
    fp->nos[i] = no;//insere o no no local correto
}

No pop(FilaPrioridade *fp) {
    No topo = fp->nos[0], ultimoNo = fp->nos[--fp->tamanho]; //armazena o no no topo da fila
    int i = 0, filho;
    while ((filho = 2 * i + 1) < fp->tamanho) { //Itera enquanto filhos a esquerda
        if (filho + 1 < fp->tamanho && fp->nos[filho + 1].custo < fp->nos[filho].custo) { //confere existencia do filhos da direita e se seu custo for menor que o da esquerda
            filho++; // usa filho da direita
        }
        if (ultimoNo.custo <= fp->nos[filho].custo) break; //ultimo no = filho o loop e parado
        fp->nos[i] = fp->nos[filho]; //Move o filgo para cima
        i = filho; // atualiza iindex
    }
    fp->nos[i] = ultimoNo; //coloca ultimo no na posicao certa 
    return topo;
}