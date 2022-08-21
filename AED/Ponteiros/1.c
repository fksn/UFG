#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int LerString(char * str);
int contida(char * a, char * b, int na, int nb);

int main()
{
    int n, na, nb;
    char a[50], b[50];
    na = LerString(a);
    nb = LerString(b);
    // printf("%d %d\n", na, nb);
    n = contida(a, b, na, nb);
    if (n == -1)
    {
        printf("Não esta contida\n");
    }
    else
    {
        printf("Esta contida no caractere %d\n", n+1);
    }
    
    return 0;
}

int contida(char * a, char * b, int na, int nb)
{
    int i, j;
    for ( i = 0; i < na; i++)
    {
        if (b[0] == a[i])
        {
            //printf("entrou %d %d\n", i, j);
            for ( j = 0; j < nb; j++)
            {
                if (b[j] != a[i+j])
                {
                    //printf("entrou aqui %c %c\n", b[i+j], a[j]);
                    break;
                }
            }
            if (j >= nb)
            {
                return i;
            }
        } 
    }
    return -1;
}

int LerString(char * str)
{
    char c;
    int i = 0;
    while (1)
    {
        scanf("%c", &c);
        if (c!='\n') 
        {
            str[i] = c;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}