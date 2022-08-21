#include<stdio.h>
#include<stdlib.h>

void sequencial(int vet[], int tam, int v);
void binario(int vet[], int tam, int v);

int main(void)
{
    int *vet = NULL, tam, i, v;
    printf("Qual o tamanho do vetor a ser lido?: ");
    scanf("%d", &tam);
    vet = (int *) malloc(sizeof(int)*tam);
    printf("Digite os valores: (em ordem)\n");
    for(i=0; i<tam; i++)
    {
        scanf("%d", &vet[i]);
    }
    printf("Valor para busca: ");
    scanf("%d", &v);
    sequencial(vet, tam, v);
    binario(vet, tam, v);
    printf("\n");
    free(vet);
    return 0;
}
void sequencial(int vet[], int tam, int v)
{
    int i, x = 0; 

    for(i=0; i<tam; i++)
    {
        if(v == vet[i])
        {
            if (x == 0)
            {
                printf("Sequencial - Valor buscado foi encontrado na posição: ");
                x = 1;
            }
            printf("%d ", i);
        }
    }
    if (x == 0)
    {
        printf("Valor não encontrado");
    }
    printf("\n");
}

void binario(int vet[], int tam, int v){

    int begin = 0, end = tam - 1, i, tras, frente, x = 0;
    while (begin <= end){
        i = (begin + end) / 2;

        if(vet[i] == v)
        {
            x = 1;
            printf("Binario - Valor buscado foi encontrado na posição: ");
            printf("%d ", i);   
            frente = i + 1;
            tras = i - 1;

            while (vet[frente] == v)
            {
                if(vet[frente] == v)
                {
                    printf("%d ", frente);
                }else break;

                frente++;
            }

            while (vet[tras] == v)
            {
                if(vet[tras] == v){
                    printf("%d ", tras);

                }else break;

                tras--;
            }
            return;
        }
        
        if(vet[i] < v) begin = i + 1;
        else end = i;
        
        if(begin==end && end==i) break;
    }
    printf("Valor não encontrado");
}

