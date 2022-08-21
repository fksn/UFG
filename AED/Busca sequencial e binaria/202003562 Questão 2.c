#include <stdio.h>
#include <stdlib.h>
int buscaSequencial(int vet[], int tam, int chave); 
int binarySearch(int arr[], int l, int r, int x);
int BinC = 0;
int main()
{
    int i, *V, x, num;
    printf("Quantos elementos no vetor?\n");
    scanf("%d", &x);
    V = (int*) malloc(x * sizeof(int));
    printf("Digite os %d elementos do vetor de forma ordenado: \n", x);
    for ( i = 0; i < x; i++)
    {
        scanf("%d", &V[i]);
    }
    printf("Qual o valor a ser procurado? ");
    scanf("%d", &num);

    binarySearch(V, 0, x-1, num);
    i = buscaSequencial(V, x, num);
    printf("Comparacoes totais feitas na busca sequencial: %d, sao %d comparacoes no laço principal e uma para verificar no final pra saber se foi achado o valor\n", i+1, i);
    printf("Comparacoes feitas na busca binaria: %d\n", BinC);
    return 0;
}
int buscaSequencial(int vet[], int tam, int chave) 
{
    int i = 0;
    while (i < tam && vet[i] != chave)
    {
        i++;
    }
    i++;
    if (i < tam) 
    {
        return i;
    }
    else return -1;
}
int binarySearch(int arr[], int l, int r, int x)
{
    BinC++;
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}