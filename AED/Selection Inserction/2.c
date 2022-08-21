#include <stdio.h>
void selectionSort(int vetor[], int tam);
int main()
{
    int i, v[10] = {0, 17, 53, 51, 99, 1, 4, 14, 16, 24};
    selectionSort(v, 9);
    for ( i = 0; i < 10; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("\n");
    return 0;
}

void selectionSort(int vetor[], int tam)
{
    int i, j;
    int max, aux;
    for (i = tam; i > 0; i--)
    {
        max = i;
        for (j = i - 1; j >= 0; j--){
            if (vetor[j] > vetor[max])
            {
                max = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[max];
        vetor[max] = aux;
    }
}