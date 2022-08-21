#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
int main()
{
    int i = 1, aux;
    FILE * arq = NULL;
    arq = fopen ("teste", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    aux = 10;
    fwrite(&aux, sizeof(int), 1, arq);
    for (i = 0; i < 10; i++)
    {
        fwrite(&i, sizeof(int), 1, arq);
    }
    fclose(arq);
    
}