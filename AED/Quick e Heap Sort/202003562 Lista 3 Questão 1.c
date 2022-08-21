#include <stdio.h>
void quickSort(int vet[], int began, int tam);
int main()
{
    int V[10] = {5, 13, 7, 20, 12, 9, 1, 4, 18, 3};
    quickSort(V, 0, 10);
    return 0;
}

void quickSort(int vet[], int began, int tam)
{
    int i, j, pivo, aux, c;
    printf("Sequencia passo a passo: ");
    for ( c = 0; c < 10; c++)
    {
        printf(" %d,", vet[c]);
    }
    printf("\n");
    i = began;
    j = tam - 1;
    pivo = vet[(began + tam) / 2];
    while (i <= j)
    {
        while (vet[i] < pivo && i < tam)
        {
            i++;
        }
        while (vet[j] > pivo && j > began)
        {
            j--;
        }
        if (i <= j)
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    if (j > began)
    {
        quickSort(vet, began, j + 1);
    }
    if (i < tam)
    {
        quickSort(vet, i, tam);
    }
}