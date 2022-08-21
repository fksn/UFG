#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
int main()
{
    int i = 1;
    FILE * arq = NULL;
    arq = fopen ("save", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    fwrite(&i, sizeof(int), 1, arq);
    fwrite(&i, sizeof(int), 1, arq);
    fwrite(&i, sizeof(int), 1, arq);
    i = 0;
    fwrite(&i, sizeof(int), 1, arq);
    fclose(arq);
}