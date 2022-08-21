#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int inverte(char * str, int n, int i);

int main()
{
    int n;
    char str[50];
    scanf("%[^\n]", str);
    n = strlen(str);
    inverte(str, n-1, 0);
    printf("%s\n", str);
    return 0;
}
int inverte(char * str, int n, int i)
{
    char a;
    a = str[i];
    str[i] = str[n-i];
    str[n-i] = a; 
    if (i >= n/2)
    {
        return 0;
    }
    else
    {
        i++;
        inverte(str, n, i);
    }
}