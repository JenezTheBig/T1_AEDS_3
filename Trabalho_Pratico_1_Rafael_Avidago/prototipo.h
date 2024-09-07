#ifndef PROTOTIPO_H
#define PROTOTIPO_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

//Definicao de estruturas

//Estrutura para aresta
typedef struct {
    int destino; //Para onde a aresta
    int peso; //Peso da aresta
} Aresta;

//struct para representar a aresta em uma lista de ajacencia
typedef struct NoAresta {
    Aresta aresta;
    struct NoAresta* proximo; //Ponteiro para o proximo no de aresta
} NoAresta;

//struct para representar uma lista de adjacencia para um vertice 
typedef struct {
    NoAresta* cabeca;
} ListaAdjacencia;

//representa no na fila de prioridade 
typedef struct {
    int vertice; 
    int custo;
} No;

//Fila de prioridade
typedef struct {
    No* nos;
    int tamanho;
    int capacidade;
} FilaPrioridade;

//Funcoes da fila (FilaPri.c)
void inicializaFilaPrioridade(FilaPrioridade *fp, int capacidadeInicial);
void liberaFilaPrioridade(FilaPrioridade *fp);
void insere(FilaPrioridade *fp, No no);
No pop(FilaPrioridade *fp);

//funcao para adicionar aresta na lista (grafo.c)
void adicionaAresta(ListaAdjacencia* listaAdj, int origem, int destino, int peso);
//dijkstra modificado (dijkstra.c)
void dijkstra(ListaAdjacencia* listaAdj, int n, int k, int distancias[][k]);
//utilitarios para a main (uteis.c)
void MedeTempo(struct timeval *start, struct rusage *usage);
void FinalMedeTempo(const struct timeval *start, struct timeval *end, double *mtime, struct rusage *usage);
void lerEntrada(const char* inputFileName, ListaAdjacencia* listaAdj, int* n, int* m, int* k);
void escreverSaida(const char* outputFileName, double mtime, const struct rusage *usage, int n, int k, int distancias[][k]);
void analisaArgumentos(int argc, char *argv[], char **inputFileName, char **outputFileName);

#endif
