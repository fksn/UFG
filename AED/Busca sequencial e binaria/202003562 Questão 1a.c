#include <stdio.h>
int buscaSequencial(int vet[], int tam, int chave); 
int binarySearch(int arr[], int l, int r, int x);
int BinC = 0;
int main()
{
    int i, V[9] = {2, 7, 11, 33, 54, 85, 85, 90, 115};
    binarySearch(V, 0, 8, 54);
    i = buscaSequencial(V, 8, 54);
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