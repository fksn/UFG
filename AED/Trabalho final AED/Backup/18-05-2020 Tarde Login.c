#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>

struct cliente
{
    char NOME[32], LOGIN[32], SENHA[32],  ENDERECO[64], TEL[20];
}typedef CLIENTE;

struct compra
{
    int COD_C;
    int * COD;
    int * QUANT;
    double P_Compra;
}typedef COMPRA;

struct produto
{
    char NOME[32], MARCA[32];
    int COD, QUANT;
    double P_COMPRA, P_VENDA;
}typedef PRODUTO;


void MAIUSCULA(char * N);
void OrdenaNovo(char N[32]);
void BuscaProduto();
int Abre_Arq(FILE * arq);
int binarySearch(int x, int low, int high);
int VerificaLogin(char * N);
int VerificaBinario(char * N, int low, int high);
void NovoProduto();
void NovoUsuario();
void RealizarCompra();


int NUM_PROD = 1, NUM_USER = 1, NUM_COMPRA = 1;
PRODUTO * ITEM = NULL; 
CLIENTE * USER = NULL;
COMPRA * C = NULL;

int main()
{
    int i = 0, op, AUX_INT, Sel, X;
    double AUX_D;
    char N[32];
    FILE * arq = NULL;
    ITEM = (PRODUTO *) malloc(sizeof(PRODUTO));
    USER = (CLIENTE *) malloc(sizeof(CLIENTE));
    C = (COMPRA *) malloc(sizeof(COMPRA));
    // Abre_Arq(ITEM, arq);
    if (NUM_PROD == 0)
    {
        printf("Erro ao iniciar\n");
        return 0;
    }
    system("tput reset"); //Limpa o terminal
    printf("Escolha o que deseja: \n0 - Area do Cliente\n1 - Area do Funcionario\n2 - Sair\n");
    scanf("%d", &Sel);
    while (Sel != 2)
    {
        if (Sel == 0)
        {
            system("tput reset"); //Limpa o terminal
            printf("Escolha o que deseja: \n0 - Login\n1 - Novo Usuario\n2 - Voltar\n");
            scanf("%d", &Sel);
            while (Sel != 2)
            {
                if (Sel == 0)
                {
                    printf("Digite o login: ");
                    scanf("%*c%[^\n]", N);
                    MAIUSCULA(N);
                    X = VerificaBinario(N, 0, NUM_USER-1);
                    printf("X = %d", X);
                    while (X == -1)
                    {
                        printf("Login nao encontrado\nDigite o login: ");
                        scanf("%*c%[^\n]", N);
                        MAIUSCULA(N);
                        X = VerificaBinario(N, 0, NUM_USER-1);
                    }
                    printf("Digite a senha: ");
                    scanf("%*c%[^\n]", N);
                    while (strcmp(USER[X].SENHA, N) != 0)
                    {
                        printf("Senha Incorreta\nDigite a senha: ");
                        scanf("%*c%[^\n]", N);
                    }
                    printf("Escolha o que deseja: \n0 - Realizar Compra\n1 - Novo Usuario\n2 - Voltar\n");
                    scanf("%d", &Sel);
                    while (Sel != 2)
                    {
                        if (Sel == 0)
                        {
                            
                        }
                        
                        printf("Escolha o que deseja: \n0 - Realizar Compra\n1 - Novo Usuario\n2 - Voltar\n");
                        scanf("%d", &Sel);
                    }
                    
                }
                else
                {
                    if (Sel == 1)
                    {
                        NovoUsuario(USER);
                        // for ( i = 0; i < NUM_USER; i++)
                        // {
                        //     printf("%s\n", USER[i].LOGIN);
                        //     printf("%s\n", USER[i].SENHA);
                        //     printf("%s\n", USER[i].NOME);
                        //     printf("%s\n", USER[i].ENDERECO);
                        //     printf("%s\n", USER[i].TEL);
                        // }
                        
                        NUM_USER++;
                    }
                }
                system("tput reset"); //Limpa o terminal
                printf("Escolha o que deseja: \n0 - Login\n1 - Novo Usuario\n2 - Voltar\n");
                scanf("%d", &Sel);
            }
        }
        else
        {
            if (Sel == 1)
            {
                system("tput reset"); //Limpa o terminal
                printf("Escolha o que deseja fazer:\n1 - Cadastrar novo produto\n2 - Pesquisar produto\n3 - Gerar relatorio de produtos\n4 - Fila de compras\n5 - Sair\n");
                scanf("%d", &op);
                while (op != 6)
                {
                    if (op == 1)
                    {
                        NovoProduto(ITEM);
                        NUM_PROD++;
                        for ( i = 0; i < NUM_PROD-1; i++)
                        {
                            printf("%d\n", ITEM[i].COD);
                            printf("%s\n", ITEM[i].NOME);
                            printf("%s\n", ITEM[i].MARCA);
                            printf("%lf\n", ITEM[i].P_COMPRA);
                            printf("%lf\n", ITEM[i].P_VENDA);
                            printf("%d\n", ITEM[i].QUANT);
                        }
                    }
                    else
                    {
                        if (op == 2)
                        {
                            BuscaProduto(ITEM);
                        }
                    }
                    system("tput reset"); //Limpa o terminal
                    printf("Escolha o que deseja fazer:\n1. Cadastrar novo produto\n2. Pesquisar produto\n3. Cadastra novo fornecedor\n4. Gerar relatorio de produtos\n5. Fila de compras\n6. Voltar\n");
                    scanf("%d", &op);
                }
            }
            else
            {
                free(USER);
                free(ITEM);
                return 0;
            }
        }
        system("tput reset"); //Limpa o terminal
        printf("Escolha o que deseja: \n0 - Area do Cliente\n1 - Area do Funcionario\n2 - Sair\n");
        scanf("%d", &Sel);
    }
    free(USER);
    free(ITEM);
    return 0;
} 

int Abre_Arq(FILE * arq)
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

void NovoProduto()
{
    int i, NUM, j, X, AUX;
    char N[32];
    ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD + 1)*sizeof(PRODUTO));
    printf("Digite o codigo do produto: ");
    scanf("%d", &X);
    AUX = binarySearch(X, 0, NUM_PROD - 1);
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
            AUX = binarySearch(X, 0, NUM_PROD - 1);
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
    return;
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

void BuscaProduto()
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
            mid = binarySearch(x, 0, NUM_PROD-1);
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

int binarySearch(int x, int low, int high) 
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

void NovoUsuario()
{
    char N[32];
    int X, i, j;
    USER = (CLIENTE *) realloc(USER, (NUM_USER + 1)*sizeof(CLIENTE));
    printf("Digite o login: ");
    scanf("%*c%[^\n]", N);
    MAIUSCULA(N);
    X = VerificaLogin(N);
    while (X == -1)
    {
        X = 0;
        printf("Login já utilizado\n");
        printf("Digite o login: ");
        scanf("%*c%[^\n]", N);
        MAIUSCULA(N);
        X = VerificaLogin(N);
    }
    
    if (NUM_USER == 1)
    {
        strcpy(USER[0].LOGIN, N);
        printf("Digite a senha: ");
        scanf("%*c%[^\n]", USER[0].SENHA);

        printf("Digite seu nome: ");
        scanf("%*c%[^\n]", USER[0].NOME);

        printf("Digite o endereço: ");
        scanf("%*c%[^\n]", USER[0].ENDERECO);

        printf("Digite o telefone: '(XX)XXXXX-XXXX': ");
        scanf("%*c%[^\n]", USER[0].TEL);
    }
    else
    {
        if (NUM_USER == 2)
        {
            if (strcmp(USER[0].LOGIN, N) < 0)
            {
                strcpy(USER[1].LOGIN, N);
                printf("Digite a senha: ");
                scanf("%*c%[^\n]", USER[1].SENHA);

                printf("Digite seu nome: ");
                scanf("%*c%[^\n]", USER[1].NOME);

                printf("Digite o endereço: ");
                scanf("%*c%[^\n]", USER[1].ENDERECO);

                printf("Digite o telefone: '(XX)XXXXX-XXXX': ");
                scanf("%*c%[^\n]", USER[1].TEL);
            }
            else
            {
                strcpy(USER[1].LOGIN, USER[0].LOGIN);
                strcpy(USER[1].ENDERECO, USER[0].ENDERECO);
                strcpy(USER[1].NOME, USER[0].NOME);
                strcpy(USER[1].SENHA, USER[0].SENHA);
                strcpy(USER[1].TEL, USER[0].TEL);

                strcpy(USER[0].LOGIN, N);
                printf("Digite a senha: ");
                scanf("%*c%[^\n]", USER[0].SENHA);

                printf("Digite seu nome: ");
                scanf("%*c%[^\n]", USER[0].NOME);

                printf("Digite o endereço: ");
                scanf("%*c%[^\n]", USER[0].ENDERECO);

                printf("Digite o telefone: '(XX)XXXXX-XXXX': ");
                scanf("%*c%[^\n]", USER[0].TEL);
            }
        }
        else
        {
            j = NUM_USER - 1;
            while(j >= 0) 
            {   
                
                if (strcmp(N, USER[j-1].LOGIN) < 0)
                {
                    strcpy(USER[j].LOGIN, USER[j-1].LOGIN);
                    strcpy(USER[j].ENDERECO, USER[j-1].ENDERECO);
                    strcpy(USER[j].NOME, USER[j-1].NOME);
                    strcpy(USER[j].SENHA, USER[j-1].SENHA);
                    strcpy(USER[j].TEL, USER[j-1].TEL);
                }
                else
                {
                    MAIUSCULA(N);
                    strcpy(USER[j].LOGIN, N);
                    printf("Digite a senha: ");
                    scanf("%*c%[^\n]", USER[j].SENHA);
                    MAIUSCULA(USER[j].SENHA);

                    printf("Digite seu nome: ");
                    scanf("%*c%[^\n]", USER[j].NOME);
                    MAIUSCULA(USER[j].NOME);

                    printf("Digite o endereço: ");
                    scanf("%*c%[^\n]", USER[j].ENDERECO);
                    MAIUSCULA(USER[j].ENDERECO);

                    printf("Digite o telefone: '(XX)XXXXX-XXXX': ");
                    scanf("%*c%[^\n]", USER[j].TEL);
                    MAIUSCULA(USER[j].TEL);
                    break;
                }
                j = j-1;
            }
        }
    }
    return;
}

int VerificaLogin(char * N)
{
    int i;
    printf("Num User%d\n", NUM_USER);
    for ( i = 0; i < NUM_USER-1; i++)
    {
        if (strcmp(N, USER[i].LOGIN) == 0)
        {
            return -1;
        }
    }
    return 0;
}

int VerificaBinario(char * N, int low, int high)
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (strcmp(USER[mid].LOGIN, N) == 0)
            return mid;

        if (strcmp(USER[mid].LOGIN, N) < 0)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

void RealizarCompra()
{
    C = (COMPRA *) realloc(C, (NUM_COMPRA + 1)*sizeof(COMPRA));
    int i, cod, Q;
    double P_Total;
    char N[32];
    printf("Item que deseja comprar: (Digite -1 para retornar)");
    scanf("%*c%[^\n]", N);
    MAIUSCULA(N);
    while (strcmp(N, "-1") == 0)
    {
        for ( i = 0; i < NUM_PROD-1; i++)
        {
            if (strcmp(N, ITEM[i].NOME) == 0)
            {
                printf("Indice: %d, Nome: %s, Quantidade: %d, Preço: %lf\n", i, ITEM[i].NOME, ITEM[i].QUANT, ITEM[i].P_VENDA);
            }
        }
        printf("Qual indice do item: ");
        scanf("%d", &cod);
        printf("Quantos deseja comprar: ");
        scanf("%d", &Q);
        while (Q > ITEM[cod].QUANT)
        {
            printf("Quantidade indisponivel\nQuantos deseja comprar: ");
            scanf("%d", &Q);
        }
        printf("Item que deseja comprar: (Digite -1 para retornar)");
        scanf("%*c%[^\n]", N);
    }
}