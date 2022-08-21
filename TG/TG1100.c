#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
//definição de V = 64, pois 64 será bastante usado visto que sareão 64 vertices devido o tamanho do tabuleiro
#define V 64

//função que realiza a ligação entre os vertices possiveis de serem ligados atravez de arestas
void FloodFill(int graph[V][V]); 
//função que auxilia dijkstra
int minDistance(int dist[], bool sptSet[]); 
//função que realiza o algoritmo de dijkstra
int dijkstra(int graph[V][V], int inicio, int fim); 

int main()
{
    int inicio, fim, move;
    int graph[V][V] = {};
    char s1[3], s2[3];
    //chamada da função FloodFill
    FloodFill(graph);
	
    while (scanf("%s %s", s1, s2)!= EOF) //laço de entrada de dados 
    {
        //definição de inicio e fim atravez das entradas do usuario
        inicio = (s1[0]-97)*8 + s1[1]-49;
        fim = (s2[0]-97)*8 + s2[1]-49;
        move = dijkstra(graph, inicio, fim);
        //saida de resultado para o usuario
        printf("To get from %c%c to %c%c takes %d knight moves.\n", s1[0], s1[1], s2[0], s2[1], move);
    }
    return 0;
}

void FloodFill(int graph[V][V])
{
    int i, I, J;
    for(i = 0; i < V; i++){
        I = i/8;
        J = i%8;
        if((I + 2) <= 7 && (J - 1) >= 0) graph[i][(I+2)*8+(J-1)] = 1;
        if((I - 1) >= 0 && (J + 2) <= 7) graph[i][(I-1)*8+(J+2)] = 1; 
        if((I - 2) >= 0 && (J - 1) >= 0) graph[i][(I-2)*8+(J-1)] = 1;
        if((I - 1) >= 0 && (J - 2) >= 0) graph[i][(I-1)*8+(J-2)] = 1; 
        if((I + 2) <= 7 && (J + 1) <= 7) graph[i][(I+2)*8+(J+1)] = 1; 
        if((I + 1) <= 7 && (J - 2) >= 0) graph[i][(I+1)*8+(J-2)] = 1; 
        if((I - 2) >= 0 && (J + 1) <= 7) graph[i][(I-2)*8+(J+1)] = 1; 
        if((I + 1) <= 7 && (J + 2) <= 7) graph[i][(I+1)*8+(J+2)] = 1;
    }
}
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

int dijkstra(int graph[V][V], int inicio, int fim)
{
	int dist[V]; 
	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[inicio] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	return dist[fim];
}