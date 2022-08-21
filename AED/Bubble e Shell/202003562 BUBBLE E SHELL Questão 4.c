#include <stdio.h>
#include <stdlib.h>    
void shellSort(int *vet, int tam);
int main()
{
    int i, a[10] = {99, 50, 1, 2, 100, 43, 25, 24, 3, 0};
    shellSort(a, 10);
    printf("Vetor antes da ordenação: {99, 50, 1, 2, 100, 43, 25, 24, 3, 0}\n");
    printf("Vetor depois da ordenação: {");
    for(i = 0 ; i < 10 ; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("}\n");
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
            while (j > h - 1 && valor <= vet[j - h])
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = valor;
        }
        h = h / 3;
    }
}
