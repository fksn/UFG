#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char nome[16];
	int prio;
	struct node* prox;
} Node;
Node* Inicia(char * s, int p)
{
	Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->nome,s);
	temp->prio = p;
	temp->prox = NULL;
	return temp;
}
void Remove(Node** head)
{
    printf("Proximo a ser chamado: %s, idade: %d\n", (*head)->nome, -(*head)->prio);
	Node* temp = *head;
	(*head) = (*head)->prox;
	free(temp);
}
void Insere(Node** head, char * s, int p)
{
	Node* start = (*head);
	Node* temp = Inicia(s, p);
	if ((*head)->prio > p) 
    {
		temp->prox = *head;
		(*head) = temp;
	}
	else 
    {
		while (start->prox != NULL && start->prox->prio < p) 
        {
			start = start->prox;
		}
		temp->prox = start->prox;
		start->prox = temp;
	}
}
int main()
{
    int idade, aux, op = 0, cont = 0;
    char nome[16];
    Node* pq;
    printf("Sistema para cadastrar pessoas a serem vacinadas, em que o índice de prioridade é dado atravez da idade.\n");
    switch(op)
    {
        case 1:
            printf("Digite o primeiro nome e idade: ");
            scanf("%s %d", nome, &idade);
            Insere(&pq, nome, -idade);
            cont++;
            break;
        case 2:
            if (cont>0)
            {
                Remove(&pq);
                cont--;
            }
            else
                printf("Fila vazia\n");
            break;
        case 3:
            break;
        default:
            printf("Opção desconhecida\n");
    }
	return 0;
}
