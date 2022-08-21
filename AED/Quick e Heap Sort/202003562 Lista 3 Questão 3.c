#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nome
{
    char NOME[32];
}typedef NOMES;
void quickSort(NOMES * N, int began, int tam);
int main()
{
    int i;
    NOMES * N = NULL;
    N = (NOMES *) malloc(10 * sizeof(NOMES));
    strcpy(N[0].NOME, "Joao");
    strcpy(N[1].NOME, "Maria");
    strcpy(N[2].NOME, "Chico");
    strcpy(N[3].NOME, "Xico");
    strcpy(N[4].NOME, "Davi");
    strcpy(N[5].NOME, "Pedro");
    strcpy(N[6].NOME, "Joana");
    strcpy(N[7].NOME, "Meire");
    strcpy(N[8].NOME, "Sther");
    strcpy(N[9].NOME, "Doglas");
    printf("Antes de ordenar\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%s", N[i].NOME);
        printf("\n");
    }
    quickSort(N, 0, 10);
    printf("Depois de ordenar\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%s", N[i].NOME);
        printf("\n");
    }
    
    return 0;
}

void quickSort(NOMES * N, int began, int tam)
{
    int i, j;
    char pivo[32], aux[32];
    i = began;
    j = tam - 1;
    strcpy(pivo, N[(began + tam) / 2].NOME);
    while (i <= j)
    {
        while (strcmp(N[i].NOME, pivo) < 0 && i < tam)
        {
            i++;
        }
        while (strcmp(N[j].NOME, pivo) > 0 && j > began)
        {
            j--;
        }
        if (i <= j)
        {
            strcpy(aux, N[i].NOME);
            strcpy(N[i].NOME, N[j].NOME);
            strcpy(N[j].NOME, aux);
            i++;
            j--;
        }
    }
    if (j > began)
    {
        quickSort(N, began, j + 1);
    }
    if (i < tam)
    {
        quickSort(N, i, tam);
    }
}