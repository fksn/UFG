#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>

struct produto
{
    char NOME[32];
    int COD, QUANT_T, QUANT_C;
    double P_COMPRA, P_VENDA;
};
struct compra
{
    int ID;
    char DATA[32];
    struct produto * PRODUTO;
};
struct cliente
{
    char NOME[32], SENHA[32];
    struct compra * COMPRA;
} typedef Cliente;

void AbaCliente(Cliente USER);
void RealizarCompra(Cliente USER);
void HistoricoCompra();

void AbaEStoque();

int main()
{
    int op;
    Cliente USER;
    memset(&USER, 1, sizeof(USER));;
    printf("entrou\n");
    USER.COMPRA.PRODUTO[1].COD = 10;
    printf("entrou\n");
    printf("Cliente ou funcionario:\n1. Cliente\n2. Funcionario\n3. Sair\n");
    scanf("%d", &op);
    while (op != 3)
    {
        if (op == 1)
        {
            // AbaCliente(USER);
        }
        else
        {
            if (op == 2)
            {
                AbaEStoque();
            }
            else
            {
                return 0;
            }
        }
        printf("Cliente ou funcionario:\n1. Cliente\n2. Funcionario\n3. Sair\n");
        scanf("%d", &op); 
    }
    
    
    return 0;
} 

void AbaCliente(Cliente USER)
{
    int op;
    char SENHA[32];
    printf("Escolha um:\n1. Fazer login\n2. Criar usuario\n3. Retornar\n");
    scanf("%d", &op);
    if (op == 1)
    {
        printf("Usuario: ");
        scanf("%s%*c", USER.NOME);
        printf("Senha: ");
        scanf("%s%*c", SENHA);
        FILE * arq = NULL;
        arq = fopen(USER.NOME, "rb+");
        if (arq == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            return;
        }
        fread(&(USER.SENHA), sizeof(char), 32, arq);
        if (strcmp(USER.SENHA, SENHA) != 0)
        {
            printf("Senha incorreta!!!\n");
            fclose(arq);
            return;
        }
        else
        {
            printf("Escolha um:\n1. Realizar compra\n2. Historico de compras\n3. Sair\n");
            scanf("%d", &op);
            if (op == 1)
            {
                RealizarCompra(USER);
            }
            else
            {
                if (op == 2)
                {
                    HistoricoCompra();
                }
                else
                {
                    return;
                }
            }
        }
    }
    else
    {
        if (op == 2)
        {
            printf("Usuario: ");
            scanf("%s%*c", USER.NOME);
            FILE * arq = NULL;
            arq = fopen (USER.NOME, "rb+");
            if (arq != NULL)
            {
                printf("Usuario já utilizado\n");
                return;
            }
            arq = fopen (USER.NOME, "wb+");
            printf("Senha: ");
            scanf("%s%*c", USER.SENHA);
            fwrite(&(USER.NOME), sizeof(char), 32, arq);
            printf("%s %s\n", USER.NOME, USER.SENHA);
            fclose(arq);
            return;
        }
        else
        {
            return ;
        }
    }
}
void RealizarCompra(Cliente USER)
{

}
void HistoricoCompra()
{

}

void AbaEStoque()
{
    
}