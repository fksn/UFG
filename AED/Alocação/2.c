#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
struct mat
{
    int nl, nc;
    int **m;
} typedef Mat;

Mat * aloca_matriz(int nl, int nc);
void libera_matriz(Mat * M);

int main()
{
    int nl, nc, i, j;
    Mat * M = NULL;

    printf("Quantidade de linhas ");
    scanf("%d",&nl);
    printf("Quantidade de colunas ");
    scanf("%d",&nc);
    M = aloca_matriz(nl, nc);
    
    printf("Primeira matriz:\n");
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            printf("%d ", M->m[i][j]);
        }
        printf("\n");
    }
    libera_matriz(M);
    return 0;
}

Mat * aloca_matriz(int nl, int nc) 
{
    srand (time(NULL));
    int i, j;
    Mat * M = NULL;
    M = (Mat *) malloc(sizeof(Mat));
    M->nl = nl;
    M->nc = nc;
    M->m = (int **) malloc(nl * sizeof(int *));
    for ( i = 0; i < nl; i++)
    {
        M->m[i] = (int*) calloc( nc, sizeof(int));
    }
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            M->m[i][j] = rand()%10000;
        }
    }
    return M;
}
void libera_matriz(Mat * M)
{
    int i;
    for ( i = 0; i < M->nl ;i++)
    {
        free(M->m[i]);
    }
    free(M->m);
    free(M);
}