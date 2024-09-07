#include "prototipo.h"

int main(int argc, char *argv[]) {
    char *inputFileName = NULL;
    char *outputFileName = NULL;
    
    // Analisa linha de comando (uteis.c)
    analisaArgumentos(argc, argv, &inputFileName, &outputFileName);
    
    // Var para medir o tempo
    struct timeval start, end;
    struct rusage usage;
    double mtime;
    
    // Inicio do temporizador e contador de memoria (uteis.c)
    MedeTempo(&start, &usage);

    int n, m, k;
    int distancias[n+1][k];

    ListaAdjacencia *listaAdj = malloc((n + 1) * sizeof(ListaAdjacencia));
    if (listaAdj == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    
    lerEntrada(inputFileName, listaAdj, &n, &m, &k);

    // Inicio do algoritmo de djikstra modificado (dijkstra.c)
    dijkstra(listaAdj, n, k, distancias);

    // Fim do temporizador e contador de uso (uteis.c)
    FinalMedeTempo(&start, &end, &mtime, &usage);

    //Escreve a saida (uteis.c)
    escreverSaida(outputFileName, mtime, &usage, n, k, distancias);

    free(listaAdj);

    return 0;
}
