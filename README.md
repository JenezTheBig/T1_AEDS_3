# Trabalho Prático 1 de AEDS3

## A Busca por Caminhos Mágicos

### OBJETIVO
- Encontrar os **k** menores caminhos em um grafo direcionado ponderado, que conecta duas cidades, Mysthollow e Luminae.
- **Tema**: Utilização de uma versão modificada do algoritmo de Dijkstra para resolver o problema dos k menores caminhos.
- **Base Teórica**: Algoritmo de Dijkstra aplicado à busca por múltiplos caminhos em grafos direcionados com pesos.

### Mecânica do Algoritmo
- **Grafo e Lista de Adjacência**: Representação do grafo por meio de listas de adjacência, onde cada vértice armazena seus vizinhos e os custos das arestas conectadas.
- **Fila de Prioridade e Heap**: Utilização de uma fila de prioridade implementada por meio de um heap para selecionar os vértices com menor custo acumulado.
- **Algoritmo de Dijkstra Modificado**: Adaptado para armazenar os **k** menores custos para cada vértice, permitindo a busca por múltiplos caminhos.

### Estratégias de Implementação
- **Seleção por Custo**: A fila de prioridade garante que o vértice com menor custo seja processado primeiro.
- **Critérios de Parada**: O algoritmo para quando todos os vértices tiverem seus **k** menores caminhos identificados ou a fila de prioridade estiver vazia.
