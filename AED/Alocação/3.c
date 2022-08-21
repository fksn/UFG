#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void print_matriz(int * nl, int * nc, int **m);
void le_matriz(int * nl, int * nc, int **m);
void libera_matriz(int **m, int nl);

int main()
{
    int nl, nc, i, j, **m = NULL;
    printf("Quantidade de linhas ");
    scanf("%d",&nl);
    printf("Quantidade de colunas ");
    scanf("%d",&nc);
    m = (int **) malloc(nl * sizeof(int *));
    for ( i = 0; i < nl; i++)
    {
        m[i] = (int*) calloc( nc, sizeof(int));
    }
    le_matriz(&nl, &nc, m);
    print_matriz(&nl, &nc, m);
    libera_matriz(m, nl);
    return 0;
}

void le_matriz(int * nl, int * nc, int **m)
{
    int i, j, aux;
    for ( i = 0; i < *nl; i++)
    {
        for ( j = 0; j < *nc; j++)
        {
            scanf("%d", &aux);
            m[i][j]=aux;
        }
    }
}

void print_matriz(int * nl, int * nc, int **m)
{
    int i, j;
    for ( i = 0; i < *nl; i++)
    {
        for ( j = 0; j < *nc; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void libera_matriz(int **m, int nl)
{
    int i;
    for ( i = 0; i < nl ;i++)
    {
        free(m[i]);
    }
    free(m);
}