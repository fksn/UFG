#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int procura(char * str, char c, int i);

int main()
{
    int n;
    char str[50], c;
    scanf("%[^\n]%*c", str);
    scanf("%c", &c);
    n = procura(str, c, 0);;
    if (n == -1)
    {
        printf("Caractere nao encontrado\n");
    }
    else
    {
        printf("Caractere encontrado na posicao: %d\n", n+1);
    }
    
    
    return 0;
}
int procura(char * str, char c, int i)
{
    if (str[i] == c)
    {
        return i;
    }
    else
    {
        if (str[i+1] != '\0')
        {
            procura(str, c, i+1);
        }
        else
        {
            return -1;
        }
        
    }
}