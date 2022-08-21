#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no {
double num;
struct no *link;
} pilha;

pilha *p, *q, *topo;

int j;
int main()
{
    double A, B, C;
    char N[16];
    p = NULL;
    q = NULL;
    topo = NULL;
    printf("digite o numero ou a operação: (para sair digite sair) ");
    scanf("%s", N);
    while (strcmp(N,"sair") != 0)
    {
        
        if (strcmp(N,"-") == 0)
        {
            p = topo;
            A = p->num;
            free(p);
            p = p->link;
            B = p->num;
            C = B-A;
            printf("%lf\n", C);
            p->num = C;
            p->link = q;
            q = p;
        }
        else
        {
            if (strcmp(N,"+") == 0)
            {
                p = topo;
                A = p->num;
                free(p);
                p = p->link;
                B = p->num;
                C = B+A;
                printf("%lf\n", C);
                p->num = C;
                p->link = q;
                topo = p;
                q = p;
            }
            else
            {
                if (strcmp(N,"/") == 0)
                {
                    p = topo;
                    A = p->num;
                    free(p);
                    p = p->link;
                    B = p->num;
                    C = B/A;
                    printf("%lf\n", C);
                    p->num = C;
                    p->link = q;
                    topo = p;
                    q = p;
                }
                else
                {
                    if (strcmp(N,"*") == 0)
                    {
                        p = topo;
                        A = p->num;
                        free(p);
                        p = p->link;
                        B = p->num;
                        C = B*A;
                        printf("%lf\n", C);
                        p->num = C;
                        p->link = q;
                        topo = p;
                        q = p;
                    }
                    else
                    {
                        p = (pilha *)malloc(sizeof(pilha));
                        p->num = atof(N);
                        p->link = q;
                        topo = p;
                        q = p;
                    }
                }
            }
        }
        scanf("%s", N);
    }
    printf("%lf\n", p->num);
}