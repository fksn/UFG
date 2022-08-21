#include <stdio.h>
#include <stdlib.h>    
#include <time.h> 
void shellSort(int *vet, int tam);
int main()
{
    srand (time(NULL));
    int i, a[100];
    for(i = 0 ; i < 100 ; i++)
    {
        a[i] = rand() % 1000;
    }
    shellSort(a, 100);
    for(i = 0 ; i < 100 ; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}
void shellSort(int *vet, int tam)
{
    int i, j, valor;
    int h = 1;
    while (h < tam)
    {
        h = 3 * h + 1;
    }
    while (h > 0)
    {
        for (i = h; i < tam; i++)
        {
            valor = vet[i];
            j = i;
            while (j > h - 1 && valor >= vet[j - h])
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = valor;
        }
        h = h / 3;
    }
}