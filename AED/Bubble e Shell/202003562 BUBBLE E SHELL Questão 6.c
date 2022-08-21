#include <stdio.h>
#include <stdlib.h>    
#include <time.h> 
void bubbleSort(int vetor[], int tam);
void shellSort(int *vet, int tam);
int main()
{
    srand (time(NULL));
    int t, i, a[5000], b[5000];
    for ( i = 0 ; i < 5000; i++)
    {
        a[i] = rand() % 10000;
        b[i] = a[i];
    }
    t = clock();
    bubbleSort(a, 5000);
    t = clock() - t;
    printf("Tempo demorado com Bubble sort: %f segundos\n", ((float)t)/CLOCKS_PER_SEC);

    t = clock();
    shellSort(b, 5000);
    t = clock() - t;
    printf("Tempo demorado com Shell sort:u: %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
    return 0;
}
void bubbleSort(int vetor[], int tam)
{
    int k, j, aux, trocas = 0;
    for (k = tam - 1; k > 0; k--)
    {
        for (j = 0; j < k; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocas += 1;
            }
        }
        if (trocas == 0)
        {
            return;
        }
        trocas = 0;
    }
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