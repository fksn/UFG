#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>

struct cliente
{
    char NOME[32], LOGIN[32], SENHA[32],  ENDERECO[64], TEL[20];
}typedef CLIENTE;
struct produto
{
    char NOME[32], MARCA[32];
    int COD, QUANT;
    double P_COMPRA, P_VENDA;
}typedef PRODUTO;

void MAIUSCULA(char * N);
void OrdenaNovo(PRODUTO * ITEM, int NUM_PROD, char N[32]);
void BuscaProduto(PRODUTO * ITEM, int NUM_PROD);
int Abre_Arq(PRODUTO * ITEM, FILE * arq);
int binarySearch(PRODUTO * ITEM, int x, int low, int high);
int VerificaLogin(CLIENTE * USER, char * N);
PRODUTO * NovoProduto(PRODUTO * ITEM, int NUM_PROD);
CLIENTE * NovoUsuario(CLIENTE * USER, int NUM_USER);

int NUM_PROD, NUM_USER;
int main()
{
    int i = 0, op, AUX_INT, Sel;
    double AUX_D;
    FILE * arq = NULL;
    PRODUTO * ITEM = NULL; 
    CLIENTE * USER = NULL;
    ITEM = (PRODUTO *) malloc(2 * sizeof(PRODUTO));
    USER = (CLIENTE *) malloc(1 * sizeof(CLIENTE));
    NUM_PROD = Abre_Arq(ITEM, arq);
    if (NUM_PROD == 0)
    {
        printf("Erro ao iniciar\n");
        return 0;
    }
    printf("Escolha o que deseja: \n0 - Area do Cliente\n1 - Area do Funcionario\n");
    scanf("%d", &Sel);
    if (Sel == 0)
    {
        printf("Escolha o que deseja: \n0 - Login\n1 - Novo Usuario\n");
        scanf("%d", &Sel);
        if (Sel == 0)
        {
            return 0;
        }
        else
        {
            NovoUsuario(USER, NUM_USER);
        }
        
        
    }
    else
    {
        printf("Escolha o que deseja fazer:\n1. Cadastrar novo produto\n2. Pesquisar produto\n3. Cadastra novo fornecedor\n4. Gerar relatorio de produtos\n5. Fila de compras\n6. Sair\n");
        scanf("%d", &op);
        while (op != 6)
        {
            if (op == 1)
            {
                ITEM = NovoProduto(ITEM, NUM_PROD);
                // for ( i = 0; i < NUM_PROD; i++)
                // {
                //     printf("Cod: %d\n", ITEM[i].COD);
                //     printf("Nome: %s\n", ITEM[i].NOME);
                //     printf("Marca: %s\n", ITEM[i].MARCA);
                //     printf("Preco_C: %lf\n", ITEM[i].P_COMPRA);
                //     printf("Preco_V: %lf\n", ITEM[i].P_VENDA);
                //     printf("Quant: %d\n", ITEM[i].QUANT);
                // }
                
                NUM_PROD++;
            }
            else
            {
                if (op == 2)
                {
                    BuscaProduto(ITEM, NUM_PROD);
                }
                else
                {
                    
                }
                
            }
            printf("Escolha o que deseja fazer:\n1. Cadastrar novo produto\n2. Pesquisar produto\n3. Cadastra novo fornecedor\n4. Gerar relatorio de produtos\n5. Fila de compras\n6. Sair\n");
            scanf("%d", &op);
        }
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
    // ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD+1) * sizeof(PRODUTO));
    // for ( i = 0; i < NUM_PROD; i++)
    // {
    //     fread(&((ITEM+i)->NOME), sizeof(char), 32, arq);
    //     fread(&((ITEM+i)->P_COMPRA), sizeof(double), 1, arq);
    //     fread(&((ITEM+i)->QUANT), sizeof(int), 1, arq);
    //     fread(&((ITEM+i)->P_VENDA), sizeof(double), 1, arq);
    //     fread(&((ITEM+i)->COD), sizeof(int), 1, arq);
    //     fread(&((ITEM+i)->FORNECEDOR.NOME), sizeof(char), 32, arq);
    //     fread(&((ITEM+i)->FORNECEDOR.ENDERECO), sizeof(char), 64, arq);
    //     fread(&((ITEM+i)->FORNECEDOR.TEL), sizeof(char), 20, arq);
    // }
    // fclose(arq);
    return NUM_PROD;
}

PRODUTO * NovoProduto(PRODUTO * ITEM, int NUM_PROD)
{
    int i, NUM, j, X, AUX;
    char N[32];
    ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD + 1)*sizeof(PRODUTO));
    printf("Digite o codigo do produto: ");
    scanf("%d", &X);
    AUX = binarySearch(ITEM, X, 0, NUM_PROD - 1);
    if (NUM_PROD == 1)
    {
        ITEM[0].COD = X;
        printf("Digite o nome do produto: ");
        scanf("%*c%[^\n]", ITEM[0].NOME);
        MAIUSCULA(ITEM[0].NOME);
        printf("Digite a marca do produto: ");
        scanf("%*c%[^\n]", ITEM[0].MARCA);
        MAIUSCULA(ITEM[0].MARCA);
        printf("Digite o preço de compra do produto: ");
        scanf("%lf", &(ITEM[0].P_COMPRA));
        printf("Digite o preço de venda do produto: ");
        scanf("%lf", &(ITEM[0].P_VENDA)); 
        printf("Digite a quantidade: ");
        scanf("%d", &(ITEM[0].QUANT));
    }
    else
    {
        while (AUX != -1)
        {
            printf("Código de produto já utilizado!!!\n");
            printf("Digite o codigo do produto: ");
            scanf("%d", &X);
            AUX = binarySearch(ITEM, X, 0, NUM_PROD - 1);
        }
        if (NUM_PROD == 2)
        {
            if (ITEM[0].COD < X)
            {
                printf("Digite o nome do produto: ");
                scanf("%*c%[^\n]", ITEM[1].NOME);
                MAIUSCULA(ITEM[1].NOME);
                ITEM[1].COD = X;
                printf("Digite a marca do produto: ");
                scanf("%*c%[^\n]", ITEM[1].MARCA);
                MAIUSCULA(ITEM[1].MARCA);
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
                printf("Digite o nome do produto: ");
                scanf("%*c%[^\n]", ITEM[0].NOME);
                MAIUSCULA(ITEM[0].NOME);
                ITEM[1].COD = ITEM[0].COD;
                ITEM[0].COD = X;
                
                printf("Digite a marca do produto: ");
                scanf("%*c%[^\n]", ITEM[0].MARCA);
                MAIUSCULA(ITEM[0].MARCA);
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
        }
        else
        {
            j = NUM_PROD - 1;
            while(j >= 0) 
            {   
                if (X < ITEM[j-1].COD)
                {
                    strcpy(ITEM[j].NOME, ITEM[j-1].NOME);
                    strcpy(ITEM[j].MARCA, ITEM[j-1].MARCA);
                    ITEM[j].COD = ITEM[j-1].COD;
                    ITEM[j].P_COMPRA = ITEM[j-1].P_COMPRA;
                    ITEM[j].P_VENDA = ITEM[j-1].P_VENDA;
                    ITEM[j].QUANT = ITEM[j-1].QUANT;
                }
                else
                {
                    ITEM[j].COD = X;
                    printf("Digite o nome do produto: ");
                    scanf("%*c%[^\n]", ITEM[j].NOME);
                    MAIUSCULA(ITEM[j].NOME);
                    printf("Digite a marca do produto: ");
                    scanf("%*c%[^\n]", ITEM[j].MARCA);
                    MAIUSCULA(ITEM[j].MARCA);
                    printf("Digite o preço de compra do produto: ");
                    scanf("%lf", &(ITEM[j].P_COMPRA));
                    printf("Digite o preço de venda do produto: ");
                    scanf("%lf", &(ITEM[j].P_VENDA)); 
                    printf("Digite a quantidade: ");
                    scanf("%d", &(ITEM[j].QUANT));
                    break;
                }
                j = j-1;
            }
        }
    }
    return ITEM;
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

void BuscaProduto(PRODUTO * ITEM, int NUM_PROD)
{
    int op = 1, num, x, mid, mod, i, aux;
    char N[32];
    printf("Modelo de pesquisa por codigo do produto - '1 codigo'\n");
    printf("Modelo de pesquisa por nome de produto - '2 nome do produto'\n");
    printf("Para modificar o item busque pelo codigo\n");
    while (op == 1)
    {
        aux = 0;
        printf("O que deseja buscar: \n");
        scanf("%d", &num);
        if (num == 1)
        {
            scanf("%d", &x);
            mid = binarySearch(ITEM, x, 0, NUM_PROD-1);
            printf("Cod: %d | ", ITEM[mid].COD);
            printf("Nome: %s | ", ITEM[mid].NOME);
            printf("Marca: %s | ", ITEM[mid].MARCA);
            printf("Preço de Compra: %.2lf | ", ITEM[mid].P_COMPRA);
            printf("Preço de Venda: %.2lf | ", ITEM[mid].P_VENDA);
            printf("Quantidade: %d\n\n", ITEM[mid].QUANT);
            printf("Deseja modificar o item? 0 - Não | 1 - Sim\n");
            scanf("%d", &mod);
            if (mod == 1)
            {
                printf("Digite: 'Preco de compra' 'preco de venda' 'quant'\n");
                scanf("%lf %lf %d", &(ITEM[mid].P_COMPRA), &(ITEM[mid].P_VENDA), &(ITEM[mid].QUANT));
            }
        }
        else
        {
            scanf("%*c%[^\n]", N);
            MAIUSCULA(N);
            for (i = 0; i < NUM_PROD-1; i++)
            {
                if (strcmp(ITEM[i].NOME, N) == 0) 
                {
                    printf("Cod: %d | ", ITEM[i].COD);
                    printf("Nome: %s | ", ITEM[i].NOME);
                    printf("Marca: %s | ", ITEM[i].MARCA);
                    printf("Preço de Compra: %.2lf | ", ITEM[i].P_COMPRA);
                    printf("Preço de Venda: %.2lf | ", ITEM[i].P_VENDA);
                    printf("Quantidade: %d\n", ITEM[i].QUANT);
                    aux = 1;
                }
            }
            if (aux == 0)
            {
                printf("Nao achado\n");
            }
        }
        printf("Deseja realizar outra pesquisa? 0 - Não 1 - Sim\n");
        scanf("%d", &op);
    }
}

int binarySearch(PRODUTO * ITEM, int x, int low, int high) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (ITEM[mid].COD == x)
            return mid;

        if (ITEM[mid].COD < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

CLIENTE * NovoUsuario(CLIENTE * USER, int NUM_USER)
{
    char N[32];
    int X;
    USER = (CLIENTE *) realloc(USER, (NUM_USER + 1)*sizeof(CLIENTE));
    printf("Digite o login: ");
    scanf("%*c%[^\n]", N);
    X = VerificaLogin(USER, N);
    while (X == -1)
    {
        printf("Login já utilizado\n");
        printf("Digite o login: ");
        scanf("%*c%[^\n]", N);
        X = VerificaLogin(USER, N);
    }
    strcpy(USER[NUM_USER-1].LOGIN, N);
    printf("Digite a senha: ");
    scanf("%*c%[^\n]", USER[NUM_USER-1].SENHA);

    printf("Digite seu nome: ");
    scanf("%*c%[^\n]", USER[NUM_USER-1].NOME);

    printf("Digite o endereço: ");
    scanf("%*c%[^\n]", USER[NUM_USER-1].ENDERECO);

    printf("Digite o telefone: '(XX)XXXXX-XXXX': ");
    scanf("%*c%[^\n]", USER[NUM_USER-1].TEL);
    printf("%s\n", USER[NUM_USER-1].LOGIN);
    printf("%s\n", USER[NUM_USER-1].SENHA);
    printf("%s\n", USER[NUM_USER-1].NOME);
    printf("%s\n", USER[NUM_USER-1].ENDERECO);
    printf("%s\n", USER[NUM_USER-1].TEL);

}

int VerificaLogin(CLIENTE * USER, char * N)
{
    int i;
    for ( i = 0; i < NUM_USER; i++)
    {
        if (strcmp(N, USER[i].LOGIN) == 0)
        {
            return -1;
        }
    }
    return 0;
}