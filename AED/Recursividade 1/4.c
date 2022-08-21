#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int maior(int * vet, int i);
int n = 0;
int main()
{
    srand (time(NULL));
    int vet[10], i, n;
    for ( i = 0; i < 10; i++)
    {
        vet[i] = rand() % 100;
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
    n = maior(vet, 9);
    printf("%d\n", n);
    return 0;
}
int maior(int * vet, int i)
{
    if (vet[i] > n)
    {
        n = vet[i];
    }
    i--;
    if (i >= 0)
    {
        maior(vet, i);
    }
    else
    {
        return n;
    }
    
}