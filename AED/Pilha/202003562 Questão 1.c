#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int * V, X, i;
    printf("Qual quantidade de elementos?\n");
    scanf("%d", &X);
    V = (int *) malloc(X*sizeof(int));
    for ( i = 0; i < X; i++)
    {
        printf("Digite o valor do elemento: ");
        scanf("%d", &V[i]);
    }
    for (i = X-1; i >= 0; i--)
    {
        printf("%d\n", V[i]);
    }
    free(V);
}