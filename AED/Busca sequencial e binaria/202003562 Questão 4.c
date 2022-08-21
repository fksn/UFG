#include <stdio.h>
#include <stdlib.h>
typedef struct no{
int info;
union{
char caracter;
} elemento;
struct no *link;
} lista;
lista *p, *q, *prim;
int qtd = 0;

void inserir(int num); 

int main() 
{
    int x, n, i;
    prim = NULL;
    printf("Informe a quantidade de no\'s(elementos): ");
    scanf("%u", &qtd);
    printf("Digite os valores: ");
    for (i = 0; i < qtd; i++) 
    {
        scanf("%d", &x);
        inserir(x);
    }
    printf("\n");
    p = prim;
    printf("Qual valor a ser buscado: ");
    scanf("%d", &n);
    for (i = 0; i < qtd; i++) 
    {
        if (n == p->info++)
        {
            printf("Valor encontrado na posição %d\n", i);
            break;
        }
    }
    return 0;
}

void inserir(int num) 
{
    p = (lista *)malloc(sizeof(lista));
    p->info = num;
    p->elemento.caracter = num;
    p->link = NULL;
    if (prim == NULL) 
    {
        prim = p;
    } 
    else 
    {
        q->link = p;
    }
    q = p;
}