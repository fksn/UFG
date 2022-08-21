#include <stdio.h>
void insertionSort(int vetor[], int tam);
int main()
{
    int i, v[6] = {31,41,59,26,41,58};
    insertionSort(v, 6);
    for ( i = 0; i < 6; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("\n");
    return 0;
}

void insertionSort(int vetor[], int tam)
{
    int i, j, tmp;
    for (i = 1; i < tam; i++)
    {
        j = i;
        while (j > 0 && vetor[j - 1] < vetor[j])
        {
            tmp = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = tmp;
            j--;
        }
    }
}