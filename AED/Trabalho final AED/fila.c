#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *link;
} fila;

fila *p, *q, *ini, *fim;
int NUM_FILA;

int Abre_Arq()
{
    int i, j, aux, x;
    p = NULL;
    q = NULL;
    ini = NULL;

    FILE * arq = NULL;
    arq = fopen ("teste", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    printf("ENTROU\n");
    fread(&NUM_FILA, sizeof(int), 1, arq);
    printf("FILA: %d\n", NUM_FILA);
    for ( i = 0; i < NUM_FILA; i++)
    {
        p = (fila *)malloc(sizeof(fila));
        p->link = NULL;
        fread(&x, sizeof(int), 1, arq);
        printf("X: %d\n", x);
        p->info = x;
        if (q != NULL) 
        {
            q->link = p;
        }
        fim = p;
        if (ini == NULL) 
        {
            ini = p;
        }
        q = p;
    }
    fclose(arq);
    return 0;
}

int Salvar_Arq()
{
    int i, j, X;
    FILE * arq = NULL;
    arq = fopen ("teste", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    fwrite(&NUM_FILA, sizeof(int), 1, arq);
    for ( i = 0; i < NUM_FILA; i++)
    {
        p = ini;
        X = p->info;
        printf("X: %d\n", X);
        p = p->link;
        fwrite(&X, sizeof(int), 1, arq);
    }
    fclose(arq);
    return 0;
}

void VerFila()
{
    p = ini;
    printf("Indice da proxima compra: %d\n", p->info);
    p = p->link;
    ini = p;
    NUM_FILA--;
    return;
}

int main()
{
    p = NULL;
    q = NULL;
    ini = NULL;

    int i = 0, op, AUX_INT, Sel, X = 0, prox_c;
    double AUX_D;
    char N[32];
    Abre_Arq();
    VerFila();
    printf("pulou\n");
    for (i = 0; i < 9; i++)
    {
        VerFila();
    }
    Salvar_Arq();
    return 0;
} 




