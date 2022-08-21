#include <stdio.h>
void bubbleSort(int vetor[], int tam);
int main()
{
    int i, vet[10] = {2, 1, 3, 11, 5, 6, 7, 8, 9, 10};
    bubbleSort(vet, 10);
    printf("Vetor antes da ordenação: {2, 1, 3, 11, 5, 6, 7, 8, 9, 10}\n");
    printf("Vetor depois da ordenação: {");
    for ( i = 0; i < 10; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("}\n");
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