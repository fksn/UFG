#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void troca_valor(int * a, int * b);

int main()
{
    int a, b;

    printf("Primeiro Valor: ");
    scanf("%d",&a);
    printf("Segundo valor: ");
    scanf("%d",&b);
    troca_valor(&a, &b);
    printf("Primeiro Valor: %d\nSegundo Valor: %d\n", a, b);
    return 0;
}

void troca_valor(int * a, int * b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}