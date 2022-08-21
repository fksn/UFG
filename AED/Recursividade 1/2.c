#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int potencia(int a, int b, int result);

int main()
{
    int a, b, n;
    scanf("%d %d", &a, &b);
    n = potencia(a, b-1, a);
    printf("resultado da potencia eh: %d\n", n);
    return 0;
}
int potencia(int a, int b, int result)
{
    result = result * a;
    b--;
    if (b>0)
    {
        potencia(a, b, result);
    }
    else
    {
        return result;
    }
    
}