#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
struct vet
{
    int N;
    int * v;
} typedef Vet;

Vet * aloca_vetor(int N);

int main()
{
    
    int N, i;
    Vet * V1 = NULL;

    printf("Tamanho do vetor: ");
    scanf("%d",&N);
    V1 = aloca_vetor(N);
    
    printf("Primeiro vetor:\n");
    for (i = 0; i < V1->N; i++)
    {
        printf("%d ", V1->v[i]);
    };
    printf("\n");
    free(V1);
    return 0;
}

Vet * aloca_vetor(int N) 
{
    srand (time(NULL));
    int i;
    Vet * V = NULL;
    V = (Vet *) malloc(sizeof(Vet));
    V->N = N;
    V->v = (int *) malloc(N * sizeof(int *));
    for (i = 0; i < V->N ; i++)
    {
        V->v[i] = rand()%10000;
    }
    return V;
}