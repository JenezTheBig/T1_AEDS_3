#include "prototipo.h"

//inicia o temporizador e a medida de usage
void MedeTempo(struct timeval *start, struct rusage *usage){
    getrusage(RUSAGE_SELF, usage);
    gettimeofday(start, NULL);
}

//Finaliza as execucoes anteriores
void FinalMedeTempo(const struct timeval *start, struct timeval *end, double *mtime, struct rusage *usage){
    long seconds, useconds;
    gettimeofday(end, NULL);
    seconds  = end->tv_sec  - start->tv_sec;
    useconds = end->tv_usec - start->tv_usec;
    *mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    getrusage(RUSAGE_SELF, usage);
}

//le o arquivo de entrada e inicializa a estrutura do grafo.
void lerEntrada(const char* inputFileName, ListaAdjacencia* listaAdj, int* n, int* m, int* k) {
    FILE *arquivo = fopen(inputFileName, "r");
    if (arquivo == NULL) {
        perror("Não foi possível abrir o arquivo de entrada");
        exit(1);
    }

    fscanf(arquivo, "%d %d %d", n, m, k);
    for (int i = 0; i <= *n; i++) {
        listaAdj[i].cabeca = NULL;
    }

    int origem, destino, peso;
    for (int i = 0; i < *m; i++) {
        fscanf(arquivo, "%d %d %d", &origem, &destino, &peso);
        adicionaAresta(listaAdj, origem, destino, peso);
    }

    fclose(arquivo);
}

//funcao para escrever a saida de dados para o txt
void escreverSaida(const char* outputFileName, double mtime, const struct rusage *usage, int n, int k, int distancias[][k]) {
    FILE *saida = fopen(outputFileName, "w");
    if (saida == NULL) {
        perror("Não foi possível abrir o arquivo de saída");
        exit(1);
    }

    for (int i = 0; i < k && distancias[n][i] != INT_MAX; i++) {
        fprintf(saida, "%d ", distancias[n][i]);
    }
    fprintf(saida, "\n");
    
    fprintf(saida, "Tempo de execução: %f ms\n", mtime);
    fprintf(saida, "Tempo de CPU utilizado: %ld.%06ld s\n", usage->ru_utime.tv_sec, usage->ru_utime.tv_usec);
    fprintf(saida, "Memória máxima residente: %ld kilobytes\n", usage->ru_maxrss);


    fclose(saida);
}

//verifica se a entrada de linha foi feita de maneira correta
void analisaArgumentos(int argc, char *argv[], char **inputFileName, char **outputFileName) {
    int opt;
    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                *inputFileName = optarg;
                break;
            case 'o':
                *outputFileName = optarg;
                break;
            default:
                fprintf(stderr, "Uso: %s -i <arquivo de entrada> -o <arquivo de saída>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!*inputFileName || !*outputFileName) {
        fprintf(stderr, "Ambos os parâmetros -i e -o são obrigatórios.\n");
        exit(EXIT_FAILURE);
    }
}