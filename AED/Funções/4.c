#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct vet
{
    int N;
    float * v;
} typedef Vet;

Vet * aloca_vetor(int N);
void print_vetores(Vet * v1, Vet * v2, Vet * v3, Vet * v4, Vet * v5);

int main()
{
    int N, i;
    Vet * V1 = NULL;
    Vet * V2 = NULL;
    Vet * V3 = NULL;
    Vet * V4 = NULL;
    Vet * V5 = NULL;

    printf("Tamanho primeiro vetor: ");
    scanf("%d",&N);
    V1 = aloca_vetor(N);
    
    printf("Tamanho segundo vetor: ");
    scanf("%d",&N);
    V2 = aloca_vetor(N);

    printf("Tamanho terceiro vetor: ");
    scanf("%d",&N);
    V3 = aloca_vetor(N);

    printf("Tamanho quarto vetor: ");
    scanf("%d",&N);
    V4 = aloca_vetor(N);

    printf("Tamanho quinto vetor: ");
    scanf("%d",&N);
    V5 = aloca_vetor(N);

    print_vetores(V1, V2, V3, V4, V5);

    free(V1);
    free(V2);
    free(V3);
    free(V4);
    free(V5);

    return 0;
}

Vet * aloca_vetor(int N) 
{
    float t;
    int i;
    Vet * V = NULL;
    V = (Vet *) malloc(sizeof(Vet));
    V->N = N;

    V->v = (float *) malloc(N * sizeof(float *));
    for (i = 0; i < V->N ; i++)
    {
        printf("Digite o valor a ser colocado no vetor: ");
        scanf("%f", &t);
        V->v[i] = t;
    }
    return V;
}
void print_vetores(Vet * v1, Vet * v2, Vet * v3, Vet * v4, Vet * v5)
{
    int i;
    printf("Primeiro vetor:\n");
    for (i = 0; i < v1->N; i++)
    {
        printf("%lf ", v1->v[i]);
    }
    printf("\n");
    printf("Segundo vetor:\n");
    for (i = 0; i < v2->N; i++)
    {
        printf("%lf ", v2->v[i]);
    }
    printf("\n");
    printf("Terceiro vetor:\n");
    for (i = 0; i < v3->N; i++)
    {
        printf("%lf ", v3->v[i]);
    }
    printf("\n");
    printf("Quarto vetor:\n");
    for (i = 0; i < v4->N; i++)
    {
        printf("%lf ", v4->v[i]);
    }
    printf("\n");
    printf("Quinto vetor:\n");
    for (i = 0; i < v5->N; i++)
    {
        printf("%lf ", v5->v[i]);
    }
    printf("\n");
}