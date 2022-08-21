#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
struct cliente
{
    char NOME[32], LOGIN[32], SENHA[32],  ENDERECO[64];
}typedef CLIENTE;

struct compra
{
    int COD_CLIENTES;
    int * COD_ITENS;
    int * QUANT_ITENS;
    int QUANT_PROD;
    double P_Compra;
}typedef COMPRA;

struct produto
{
    char NOME[32], MARCA[32];
    int COD, QUANT;
    double P_COMPRA, P_VENDA;
}typedef PRODUTO;

typedef struct no
{
    int info;
    struct no *link;
} fila;

fila *p, *q, *ini, *fim;

void MAIUSCULA(char * N);
void OrdenaNovo(char N[32]);
void BuscaProduto();
int Abre_Arq();
int Salvar_Arq();
int binarySearch(int x, int low, int high);
int VerificaLogin(char * N);
int VerificaBinario(char * N, int low, int high);
void NovoProduto();
void NovoUsuario();
void RealizarCompra(int X);
void Login();
void VerFila();
void Reset();

int NUM_PROD = 1, NUM_USER = 1, NUM_COMPRA = 1, NUM_FILA = 0;
PRODUTO * ITEM = NULL; 
CLIENTE * USER = NULL;
COMPRA * C = NULL;

int main()
{
    p = NULL;
    q = NULL;
    ini = NULL;

    int i = 0, op, AUX_INT, Sel, X, prox_c;
    double AUX_D;
    char N[32];
    ITEM = (PRODUTO *) malloc(sizeof(PRODUTO));
    USER = (CLIENTE *) malloc(sizeof(CLIENTE));
    C = (COMPRA *) malloc(sizeof(COMPRA));
    Abre_Arq();
    if (NUM_PROD == 0)
    {
        printf("Erro ao iniciar\n");
        return 0;
    }
    system("tput reset"); //Limpa o terminal
    printf("Escolha o que deseja: \n0 - Area do Cliente\n1 - Area do Funcionario\n2 - Salvar e Sair\n");
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
                    Login();
                }
                else
                {
                    if (Sel == 1)
                    {
                        NovoUsuario();
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
                printf("Escolha o que deseja fazer:\n1 - Cadastrar novo produto\n2 - Pesquisar produto\n3 - Fila de compras\n4 - Resetar arquivos\n5 - Voltar\n");
                scanf("%d", &op);
                while (op != 5)
                {
                    if (op == 1)
                    {
                        NovoProduto();
                        NUM_PROD++;
                    }
                    else
                    {
                        if (op == 2)
                        {
                            BuscaProduto();
                        }
                        else
                        {
                            if (op == 3)
                            {
                                if (NUM_FILA==1)
                                {
                                    VerFila();
                                }
                                else
                                {
                                    if (NUM_FILA>1)
                                    {
                                        VerFila();
                                        printf("Deseja ver outra compra? 0 - Não | 1 - Sim:");
                                        scanf("%d", &prox_c);
                                        while (prox_c != 0 && NUM_FILA > 0)
                                        {
                                            if (prox_c == 1)
                                            {
                                                VerFila();
                                            }
                                            printf("Deseja ver outra compra? 0 - Não | 1 - Sim:");
                                            scanf("%d", &prox_c);
                                        }
                                    }
                                    else
                                    {
                                        system("tput reset"); //Limpa o terminal
                                        printf("Fila vazia!!!\n");
                                        printf("para prosseguir digite 0\n");
                                        scanf("%d",&op);
                                        while (op != 0)
                                        {
                                            system("tput reset"); //Limpa o terminal
                                            printf("Fila vazia!!!\n");
                                            printf("para prosseguir digite 0\n");
                                            scanf("%d",&op);
                                        }
                                        
                                    }
                                    
                                }
                                
                                
                                
                                
                            }
                            else
                            {
                                if (op == 4)
                                {
                                    printf("Tem certeza? 0 - Não | 1 - Sim: ");
                                    scanf("%d", &op);
                                    if (op == 1)
                                    {
                                        Reset();
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    system("tput reset"); //Limpa o terminal
                    printf("Escolha o que deseja fazer:\n1 - Cadastrar novo produto\n2 - Pesquisar produto\n3 - Fila de compras\n4 - Resetar Arquivos\n5 - Voltar\n");
                    scanf("%d", &op);
                }
            }
            else
            {
                free(C->COD_ITENS);
                free(C->QUANT_ITENS);
                free(C);
                free(USER);
                free(ITEM);
                return 0;
            }
        }
        system("tput reset"); //Limpa o terminal
        
        printf("Escolha o que deseja: \n0 - Area do Cliente\n1 - Area do Funcionario\n2 - Salvar e Sair\n");
        scanf("%d", &Sel);
    }
    Salvar_Arq();
    free(C->COD_ITENS);
    free(C->QUANT_ITENS);
    free(C);
    free(USER);
    free(ITEM);
    return 0;
} 

int Abre_Arq()
{
    int i, j, aux, x;
    p = NULL;
    q = NULL;
    ini = NULL;
    FILE * arq = NULL;
    arq = fopen ("save", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    fread(&NUM_PROD, sizeof(int), 1, arq);
    fread(&NUM_USER, sizeof(int), 1, arq);
    fread(&NUM_COMPRA, sizeof(int), 1, arq);
    fread(&NUM_FILA, sizeof(int), 1, arq);


    ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD + 1)*sizeof(PRODUTO));
    for ( i = 0; i < NUM_PROD-1; i++)
    {
        fread(&(ITEM[i].COD), sizeof(int), 1, arq);
        fread(&(ITEM[i].NOME), sizeof(char), 32, arq);
        fread(&(ITEM[i].MARCA), sizeof(char), 32, arq);
        fread(&(ITEM[i].QUANT), sizeof(int), 1, arq);
        fread(&(ITEM[i].P_COMPRA), sizeof(double), 1, arq);
        fread(&(ITEM[i].P_VENDA), sizeof(double), 1, arq);
    }

    USER = (CLIENTE *) realloc(USER, (NUM_USER + 1)*sizeof(CLIENTE));
    for ( i = 0; i < NUM_USER-1; i++)
    {
        fread(&(USER[i].LOGIN), sizeof(char), 32, arq);
        fread(&(USER[i].SENHA), sizeof(char), 32, arq);
        fread(&(USER[i].NOME), sizeof(char), 32, arq);
        fread(&(USER[i].ENDERECO), sizeof(char), 64, arq);
    }

    C = (COMPRA *) realloc(C, (NUM_COMPRA + 1)*sizeof(COMPRA));
    for ( i = 0; i < NUM_USER-1; i++)
    {
        fread(&(C[i].COD_CLIENTES), sizeof(int), 1, arq);
        fread(&(C[i].QUANT_PROD), sizeof(char), 1, arq);

        aux = C[i].QUANT_PROD;

        C[i].COD_ITENS = (int *) malloc(aux * sizeof(int));
        C[i].QUANT_ITENS = (int *) malloc(aux * sizeof(int));

        for (j = 0; j < C[i].QUANT_PROD-1; j++)
        {
            fread(&(C[i].COD_ITENS[j]), sizeof(int), 1, arq);
            fread(&(C[i].QUANT_ITENS[j]), sizeof(int), 1, arq);
        }
        fread(&(C[i].P_Compra), sizeof(double), 1, arq);
    }

    for ( i = 0; i < NUM_FILA; i++)
    {
        p = (fila *)malloc(sizeof(fila));
        p->link = NULL;
        p->info = i;
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
    arq = fopen ("save", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    fwrite(&NUM_PROD, sizeof(int), 1, arq);
    fwrite(&NUM_USER, sizeof(int), 1, arq);
    fwrite(&NUM_COMPRA, sizeof(int), 1, arq);
    fwrite(&NUM_FILA, sizeof(int), 1, arq);

    for ( i = 0; i < NUM_PROD-1; i++)
    {
        fwrite(&(ITEM[i].COD), sizeof(int), 1, arq);
        fwrite(&(ITEM[i].NOME), sizeof(char), 32, arq);
        fwrite(&(ITEM[i].MARCA), sizeof(char), 32, arq);
        fwrite(&(ITEM[i].QUANT), sizeof(int), 1, arq);
        fwrite(&(ITEM[i].P_COMPRA), sizeof(double), 1, arq);
        fwrite(&(ITEM[i].P_VENDA), sizeof(double), 1, arq);
    }
    for ( i = 0; i < NUM_USER-1; i++)
    {
        fwrite(&(USER[i].LOGIN), sizeof(char), 32, arq);
        fwrite(&(USER[i].SENHA), sizeof(char), 32, arq);
        fwrite(&(USER[i].NOME), sizeof(char), 32, arq);
        fwrite(&(USER[i].ENDERECO), sizeof(char), 64, arq);
    }
    for ( i = 0; i < NUM_USER-1; i++)
    {
        fwrite(&(C[i].COD_CLIENTES), sizeof(int), 1, arq);
        fwrite(&(C[i].QUANT_PROD), sizeof(char), 1, arq);
        for (j = 0; j < C[i].QUANT_PROD; j++)
        {
            fwrite(&(C[i].COD_ITENS[j]), sizeof(int), 1, arq);
            fwrite(&(C[i].QUANT_ITENS[j]), sizeof(int), 1, arq);
        }
        fwrite(&(C[i].P_Compra), sizeof(double), 1, arq);
    }
    for ( i = 0; i < NUM_FILA; i++)
    {
        p = ini;
        X = p->info;
        p = p->link;
        fwrite(&X, sizeof(int), 1, arq);
    }
    fclose(arq);
    return 0;
}

void Reset()
{
    int i = 0;
    FILE * arq = NULL;
    arq = fopen ("save", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }
    fwrite(&i, sizeof(int), 1, arq);
    fwrite(&i, sizeof(int), 1, arq);
    fwrite(&i, sizeof(int), 1, arq);
}

void NovoProduto()
{
    int i, NUM, j, X, AUX;
    char N[32];
    ITEM = (PRODUTO *) realloc(ITEM, (NUM_PROD + 1)*sizeof(PRODUTO));
    system("tput reset"); //Limpa o terminal
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

void NovoUsuario()
{
    char N[32];
    int X, i, j;
    USER = (CLIENTE *) realloc(USER, (NUM_USER + 1)*sizeof(CLIENTE));
    system("tput reset"); //Limpa o terminal
    printf("Digite o login: ");
    scanf("%*c%[^\n]", N);
    MAIUSCULA(N);
    X = VerificaLogin(N);
    while (X == -1)
    {
        X = 0;
        system("tput reset"); //Limpa o terminal
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
            }
            else
            {
                strcpy(USER[1].LOGIN, USER[0].LOGIN);
                strcpy(USER[1].ENDERECO, USER[0].ENDERECO);
                strcpy(USER[1].NOME, USER[0].NOME);
                strcpy(USER[1].SENHA, USER[0].SENHA);

                strcpy(USER[0].LOGIN, N);
                printf("Digite a senha: ");
                scanf("%*c%[^\n]", USER[0].SENHA);

                printf("Digite seu nome: ");
                scanf("%*c%[^\n]", USER[0].NOME);

                printf("Digite o endereço: ");
                scanf("%*c%[^\n]", USER[0].ENDERECO);
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
                    break;
                }
                j = j-1;
            }
        }
    }
    return;
}

void RealizarCompra(int X)
{
    C = (COMPRA *) realloc(C, (NUM_COMPRA + 1)*sizeof(COMPRA));
    C[NUM_COMPRA-1].COD_ITENS = (int *) malloc(1 * sizeof(int));
    C[NUM_COMPRA-1].QUANT_ITENS = (int *) malloc(1 * sizeof(int));
    C[NUM_COMPRA-1].QUANT_PROD = 0;
    C[NUM_COMPRA-1].COD_CLIENTES = X;


    int i, cod, Q, aux, cont = 0;
    double P_Total;
    char N[32];
    system("tput reset"); //Limpa o terminal
    printf("Item que deseja comprar: (Digite -1 para retornar)\n");
    scanf("%*c%[^\n]", N);
    MAIUSCULA(N);
    while (strcmp(N, "-1") != 0)
    {
        aux = 0;
        C[NUM_COMPRA-1].QUANT_PROD = C[NUM_COMPRA-1].QUANT_PROD + 1;

        C[NUM_COMPRA-1].COD_ITENS = (int *) realloc(C[NUM_COMPRA-1].COD_ITENS, (cont+1)*sizeof(int));
        C[NUM_COMPRA-1].QUANT_ITENS = (int *) realloc(C[NUM_COMPRA-1].QUANT_ITENS, (cont+1)*sizeof(int));

        for ( i = 0; i < NUM_PROD-1; i++)
        {
            if (strcmp(N, ITEM[i].NOME) == 0)
            {
                printf("Indice: %d, Nome: %s, Quantidade: %d, Preço: %lf\n", i, ITEM[i].NOME, ITEM[i].QUANT, ITEM[i].P_VENDA);
                aux = 1;
            }
        }
        if (aux == 0)
        {
            printf("Produto não encontrado\n");
        }
        else
        {
            printf("Qual indice do item: ");
            scanf("%d", &cod);
            printf("Quantos deseja comprar: ");
            scanf("%d", &Q);
            while (Q > ITEM[cod].QUANT)
            {
                printf("Quantidade indisponivel\nQuantos deseja comprar: ");
                scanf("%d", &Q);
            }
            ITEM[cod].QUANT = ITEM[cod].QUANT - Q;
            C[NUM_COMPRA-1].COD_ITENS[cont] = cod;
            C[NUM_COMPRA-1].QUANT_ITENS[cont] = Q;
            C[NUM_COMPRA-1].P_Compra = C[NUM_COMPRA-1].P_Compra + ITEM[cod].P_VENDA * Q;
            cont++;
        }
        system("tput reset"); //Limpa o terminal
        printf("Preço total: %.2lf\n", C[NUM_COMPRA-1].P_Compra);
        printf("Item que deseja comprar: (Digite -1 para retornar)\n");
        scanf("%*c%[^\n]", N);
        MAIUSCULA(N);
    }
    C[NUM_COMPRA-1].QUANT_PROD = cont;
    printf("Codigo Cliente: %d\n", C[NUM_COMPRA-1].COD_CLIENTES);
    printf("Quantidade de itens: %d\n", C[NUM_COMPRA-1].QUANT_PROD);
    for ( i = 0; i < C[NUM_COMPRA-1].QUANT_PROD; i++)
    {
        printf("Codigo produto: %d, Quantidade Pedida: %d\n", C[NUM_COMPRA-1].COD_ITENS[i], C[NUM_COMPRA-1].QUANT_ITENS[i]);
    }
    printf("Preço Compra: %lf\n", C[NUM_COMPRA-1].P_Compra);

    p = (fila *)malloc(sizeof(fila));
    p->link = NULL;
    p->info = NUM_COMPRA-1;
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
    NUM_FILA++;
}

void BuscaProduto()
{
    int op = 1, num, x, mid, mod, i, aux;
    char N[32];
    system("tput reset"); //Limpa o terminal
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
            system("tput reset"); //Limpa o terminal
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

void Login()
{
    int X, Sel, aux;
    char N[32];
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
    printf("Escolha o que deseja: \n0 - Realizar Compra\n1 - Voltar\n");
    scanf("%d", &Sel);
    while (Sel != 1)
    {
        if (Sel == 0)
        {
            RealizarCompra(X);
            NUM_COMPRA++;
        }
        printf("Escolha o que deseja: \n0 - Realizar Compra\n1 - Voltar\n");
        scanf("%d", &Sel);
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

void VerFila()
{
    int X, i, AUX;
    p = ini;
    X = p->info;
    printf("Indice da compra: %d\n", X);
    printf("Cliente: %s\n", USER[C[X].COD_CLIENTES].NOME);
    printf("Endereço: %s\n", USER[C[X].COD_CLIENTES].ENDERECO);
    for ( i = 0; i < C[X].QUANT_PROD; i++)
    {
        AUX = C[X].COD_ITENS[i];
        printf("Produto: %s | Marca: %s | Quantidade: %d\n", ITEM[AUX].NOME, ITEM[AUX].MARCA, C[X].QUANT_ITENS[i]);
    }
    p = p->link;
    ini = p;
    NUM_FILA--;

    printf("Deseja ver a proxima compra: 0 - Sim | 1 - Não\n");
    scanf("%d", &AUX);
    if (AUX == 0)
    {
        if (NUM_FILA>0)
        {
            VerFila();
        }
        else
        {
            printf("Fila vazia!!!\n");
        }
    }
    return;
}