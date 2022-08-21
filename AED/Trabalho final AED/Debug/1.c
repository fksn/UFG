#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>

struct fornecedor
{
    char NOME[32], ENDERECO[64], TEL[20];
};
struct produto
{
    char NOME[32];
    int COD, QUANT;
    double P_COMPRA, P_VENDA;
    struct fornecedor FORNECEDOR;
}typedef PRODUTO;
void MAIUSCULA(char * N);
void OrdenaNovo(PRODUTO * ITEM, int NUM_PROD, char N[32]);
int Abre_Arq(PRODUTO * ITEM, FILE * arq);
void NovoProduto(PRODUTO * ITEM, int NUM_PROD);
int main()
{
    int i = 0, op, NUM_PROD, AUX_INT;
    double AUX_D;
    FILE * arq = NULL;
    PRODUTO * ITEM = NULL; 
    ITEM = (PRODUTO *) malloc(2 * sizeof(PRODUTO));
    NUM_PROD = Abre_Arq(ITEM, arq);
    if (NUM_PROD == 0)
    {
        printf("Erro ao iniciar\n");
        return 0;
    }
    printf("Escolha o que deseja fazer:\n1. Cadastrar novo produto\n2. Pesquisar produto\n3. Cadastra novo fornecedor\n4. Gerar relatorio de produtos\n5. Fila de compras\n6. Sair\n");
    scanf("%d", &op);
    while (op != 6)
    {
        if (op == 1)
        {
            NovoProduto(ITEM, NUM_PROD);
            NUM_PROD++;
        }
        printf("Escolha o que deseja fazer:\n1. Cadastrar novo produto\n2. Pesquisar produto\n3. Cadastra novo fornecedor\n4. Gerar relatorio de produtos\n5. Fila de compras\n6. Sair\n");
        scanf("%d", &op);
    }
    free(ITEM);
    return 0;
} 
int Abre_Arq(PRODUTO * ITEM, FILE * arq)
{
    int NUM_PROD, i;
    arq = fopen ("save", "rb+");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 0;
    }
    // fwrite(&NUM_PROD, sizeof(int), 1, arq);
    fread(&NUM_PROD, sizeof(int), 1, arq);
    printf("NUM_PROD: %d\n", NUM_PROD);
    ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD+1) * sizeof(PRODUTO));
    for ( i = 0; i < NUM_PROD; i++)
    {
        fread(&((ITEM+i)->NOME), sizeof(char), 32, arq);
        fread(&((ITEM+i)->P_COMPRA), sizeof(double), 1, arq);
        fread(&((ITEM+i)->QUANT), sizeof(int), 1, arq);
        fread(&((ITEM+i)->P_VENDA), sizeof(double), 1, arq);
        fread(&((ITEM+i)->COD), sizeof(int), 1, arq);
        fread(&((ITEM+i)->FORNECEDOR.NOME), sizeof(char), 32, arq);
        fread(&((ITEM+i)->FORNECEDOR.ENDERECO), sizeof(char), 64, arq);
        fread(&((ITEM+i)->FORNECEDOR.TEL), sizeof(char), 20, arq);
    }
    fclose(arq);
    return NUM_PROD;
}

void NovoProduto(PRODUTO * ITEM, int NUM_PROD)
{
    int i, NUM, AUX1;
    double AUX2;
    char N[32];
    ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD + 1)*sizeof(PRODUTO));
    printf("Digite o nome do produto: ");
    scanf("%s", N);
    MAIUSCULA(N);
    OrdenaNovo(ITEM, NUM_PROD, N);
    
    for ( i = 0; i < NUM_PROD; i++)
    {
        printf("%s\n", ITEM[i].NOME);
        printf("%d\n", ITEM[i].COD);
        printf("%d\n", ITEM[i].QUANT);
        printf("%.2lf\n", ITEM[i].P_COMPRA);
        printf("%.2lf\n", ITEM[i].P_VENDA);
    }
    return;
}

void OrdenaNovo(PRODUTO * ITEM, int NUM_PROD, char N[32])
{
    char AUX_S[32];
    int begin = 0, AUX_I;
    double AUX_D;
    int end = NUM_PROD - 1;
    int i = NUM_PROD - 1, j;
    if (NUM_PROD == 1)
    {
        strcpy(ITEM[0].NOME, N);
        printf("Digite o código do produto: ");
        scanf("%d", &(ITEM[0].COD));
        printf("Digite o preço de compra do produto: ");
        scanf("%lf", &(ITEM[0].P_COMPRA));
        printf("Digite o preço de venda do produto: ");
        scanf("%lf", &(ITEM[0].P_VENDA)); 
        printf("Digite a quantidade: ");
        scanf("%d", &(ITEM[0].QUANT));
        
        return;
    }
    else
    {
        if (NUM_PROD == 2)
        {
            if (strcmp(ITEM[0].NOME, N) <= 0)
            {
                strcpy(ITEM[1].NOME, N);
                printf("Digite o código do produto: ");
                scanf("%d", &(ITEM[1].COD));
                printf("Digite o preço de compra do produto: ");
                scanf("%lf", &(ITEM[1].P_COMPRA));
                printf("Digite o preço de venda do produto: ");
                scanf("%lf", &(ITEM[1].P_VENDA)); 
                printf("Digite a quantidade: ");
                scanf("%d", &(ITEM[1].QUANT));
            }
            else
            {
                strcpy(ITEM[1].NOME, ITEM[0].NOME);
                strcpy(ITEM[0].NOME, N);
                AUX_I = ITEM[0].COD;
                ITEM[1].COD = AUX_I;
                printf("Digite o código do produto: ");
                scanf("%d", &(ITEM[0].COD));

                ITEM[1].P_COMPRA = ITEM[0].P_COMPRA;
                printf("Digite o preço de compra do produto: ");
                scanf("%lf", &(ITEM[0].P_COMPRA));

                ITEM[1].P_VENDA = ITEM[0].P_VENDA;
                printf("Digite o preço de venda do produto: ");
                scanf("%lf", &(ITEM[0].P_VENDA));
                
                ITEM[1].QUANT = ITEM[0].QUANT;
                printf("Digite a quantidade: ");
                scanf("%d", &(ITEM[0].QUANT));
            }
            return;
        }
        else
        {
            printf("NUM_PORD %d\n", NUM_PROD);
            i = NUM_PROD - 1;
            while(strcmp(N, ITEM[i].NOME) < 0 || i )
            {
                j = i+1;
                printf("valor de i: %d e j: %d\n", i, j);
                strcpy(ITEM[j].NOME, ITEM[i].NOME);
                ITEM[j].COD = ITEM[i].COD;
                ITEM[j].P_COMPRA = ITEM[i].P_COMPRA;
                ITEM[j].P_VENDA = ITEM[i].P_VENDA;
                ITEM[j].QUANT = ITEM[i].QUANT;
                i--;
                j = i+1;
            }
            printf("valor de i: %d e j: %d\n", i, j);
            strcpy(ITEM[i].NOME, N);
            printf("Digite o código do produto: ");
            scanf("%d", &(ITEM[i].COD));

            printf("Digite o preço de compra do produto: ");
            scanf("%lf", &(ITEM[i].P_COMPRA));

            printf("Digite o preço de venda do produto: ");
            scanf("%lf", &(ITEM[i].P_VENDA));
            
            printf("Digite a quantidade: ");
            scanf("%d", &(ITEM[i].QUANT));
        }
    }
}

void MAIUSCULA(char * N)
{
    int i = 0;
    while (N[i] != '\0')
    {
        if (N[i] >= 97 && N[i] <= 122)
        {
            N[i] = N[i] - 32;
        }
        i++;
    }
    return;
}