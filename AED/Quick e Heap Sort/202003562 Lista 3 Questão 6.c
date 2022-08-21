#include <stdio.h>
#include <ctype.h>
void swap(int *a, int *b);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
int main()
{
    int i, v[24];
    char N[24] = "Ordenando com Heap Sort";

    printf("Antes de ordenar: ");
    for ( i = 0; i < 23; i++)
    {
        printf("%c", N[i]);
    }
    printf("\n");
    for ( i = 0; i < 23; i++) v[i] = N[i];
    heapSort(v, 23);
    for ( i = 0; i < 23; i++) N[i] = v[i];
    printf("Ordenação com valores maiusculos menores que minusculos: ");
    for ( i = 0; i < 23; i++)
    {
        printf("%c", N[i]);
    }
    printf("\n");
    for ( i = 0; i < 23; i++) 
    {
        if (v[i] >=65 && v[i] <= 90)
        {
            v[i] = v[i]+32;
        }
    }
    heapSort(v, 23);
    for ( i = 0; i < 23; i++) N[i] = v[i];
    printf("Ordenação transformando maiusculos em minusculo: ");
    for ( i = 0; i < 23; i++)
    {
        printf("%c", N[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(int arr[], int n, int i)
{
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] < arr[max]) max = leftChild;
    if (rightChild < n && arr[rightChild] < arr[max]) max = rightChild;
    if (max != i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}