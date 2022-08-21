#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no {
char info;
struct no *link;
} pilha;

pilha *p, *q, *topo;

int j;
int main()
{
    char N;
    p = NULL;
    q = NULL;
    topo = NULL;
    printf("digite a palavra: ");
    scanf("%c", &N);
    while (N != '\n')
    {
        p = (pilha *)malloc(sizeof(pilha));
        p->info = N;
        p->link = q;
        topo = p;
        q = p;
        scanf("%c", &N);
    }
    while (p != NULL) 
    {
        printf("%c", p->info);
        p = p->link;
    }
    printf("\n");
}