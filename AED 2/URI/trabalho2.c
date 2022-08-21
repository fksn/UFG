#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tamanhoAtual = 0, tamanhoMaximo;
struct 
{
    int Idade, Tel, Comorbidade, AreaRisco, prio;
    char Nome[32];
} typedef HEAP;
HEAP * h;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void ReHeapUp() {
    int i = tamanhoAtual;
    char aux[32];
    while( i > 0 && h[i].prio > h[(i-1)/2].prio){
        swap(&(h[i].Idade), &(h[(i-1)/2].Idade));
        swap(&(h[i].Tel), &(h[(i-1)/2].Tel));
        swap(&(h[i].Comorbidade), &(h[(i-1)/2].Comorbidade));
        swap(&(h[i].AreaRisco), &(h[(i-1)/2].AreaRisco));
        swap(&(h[i].prio), &(h[(i-1)/2].prio));
        strcpy(aux, h[i].Nome);
        strcpy(h[i].Nome, h[(i-1)/2].Nome);
        strcpy(h[(i-1)/2].Nome, aux);
        i = (i-1)/2;
    }
}

void Insert(char * nome, int idade, int tel, int comorbidade, int areaRisco){
    int x;
    if (tamanhoAtual < tamanhoMaximo){
        h[tamanhoAtual].Idade = idade;
        h[tamanhoAtual].Tel = tel;
        h[tamanhoAtual].Comorbidade = comorbidade;
        h[tamanhoAtual].AreaRisco = areaRisco;
        strcpy(h[tamanhoAtual].Nome, nome);
        h[tamanhoAtual].prio = idade + comorbidade*50 + areaRisco*50;
        ReHeapUp();
        tamanhoAtual++;
    }
    else{
        printf("Está cheio, deseja aumentar em quantos espaços: ");
        scanf("%d", &x);
        tamanhoMaximo = tamanhoMaximo+x;
        h = (HEAP *) realloc(h,tamanhoMaximo*sizeof(HEAP));
        h[tamanhoAtual].Idade = idade;
        h[tamanhoAtual].Tel = tel;
        h[tamanhoAtual].Comorbidade = comorbidade;
        h[tamanhoAtual].AreaRisco = areaRisco;
        strcpy(h[tamanhoAtual].Nome, nome);
        h[tamanhoAtual].prio = idade + comorbidade*50 + areaRisco*50;
        ReHeapUp();
        tamanhoAtual++;
    }
}
void ReHeapDown(int i){
    int j;
    char aux[32];
    while(2*i + 1 < tamanhoAtual){
        j = 2*i + 1;
        if(j+1 < tamanhoAtual && h[j + 1].prio > h[j].prio)
            j = j + 1;
        if(h[i].prio > h[j].prio)
            break;
        else {
            swap(&(h[i].Idade), &(h[j].Idade));
            swap(&(h[i].Tel), &(h[j].Tel));
            swap(&(h[i].Comorbidade), &(h[j].Comorbidade));
            swap(&(h[i].AreaRisco), &(h[j].AreaRisco));
            swap(&(h[i].prio), &(h[j].prio));
            strcpy(aux, h[i].Nome);
            strcpy(h[i].Nome, h[j].Nome);
            strcpy(h[j].Nome, aux);
            i = j;
        }
    }
}
int Cadastro(){
    char nome[32], aux;
    int tel, idade, comorbidade, areaRisco;
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite a idade: ");
    scanf("%d", &idade);
    printf("Digite o telefone para contato: ");
    scanf("%d", &tel);
    printf("Possui alguma comorbidade S/N: ");
    scanf("%*c%c", &aux);
    if (aux == 115 || aux == 83) comorbidade = 1;
    else comorbidade = 0;
    printf("Atua em áreas de risco S/N: ");
    scanf("%*c%c", &aux);
    if (aux == 115 || aux == 83) areaRisco = 1;
    else areaRisco = 0;
    Insert(nome, idade, tel, comorbidade, areaRisco);
}
void Retirar(){
    char aux[32];
    if(tamanhoAtual <= 0)
        printf("Fila Vazia!!!\n");
    else
    {
        printf("Nome: %s, Idade: %d, Telefone: %d\n", h[0].Nome, h[0].Idade, h[0].Tel);
        swap(&(h[0].Idade), &(h[tamanhoAtual-1].Idade));
        swap(&(h[0].Tel), &(h[tamanhoAtual-1].Tel));
        swap(&(h[0].Comorbidade), &(h[tamanhoAtual-1].Comorbidade));
        swap(&(h[0].AreaRisco), &(h[tamanhoAtual-1].AreaRisco));
        swap(&(h[0].prio), &(h[tamanhoAtual-1].prio));
        strcpy(aux, h[0].Nome);
        strcpy(h[0].Nome, h[tamanhoAtual-1].Nome);
        strcpy(h[tamanhoAtual-1].Nome, aux);
        tamanhoAtual--;
        ReHeapDown(0);
    }
    return;
}

int main(){
    int Op, idade;

    printf("Digite o maximo de pessoas: ");
    scanf("%d", &tamanhoMaximo);
    h = (HEAP*) malloc(sizeof(HEAP)*(tamanhoMaximo));
    do
    {
        printf("1 - Adicionar cadastro\n2 - Verificar proximo a ser vacinado\n3 - Sair\n");
        scanf("%d",&Op);
        switch(Op)
        {
            case 1:
            Cadastro();
            break;
            case 2:
            Retirar();
            break;
        }
    }while(Op>0 && Op<3);
    free(h);
    return 0;
}