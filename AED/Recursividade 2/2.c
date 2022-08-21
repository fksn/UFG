#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int MinDC(int a, int b, int i);

int main()
{
    int a, b, n;
    
    scanf("%d %d", &a, &b);
    n = fmin(a, b);
    n = MinDC(n, a+b-n, 2);
    if (n == -1)
    {
        printf("Nao tem MinDC\n");
    }
    else
    {
        printf("MinDC: %d\n", n);
    }
    return 0;
}
int MinDC(int a, int b, int i)
{
    if (a%i==0 && b%i==0)
    {
        return i;
    }
    else
    {
        if (i<=a)
        {
            i++;
            MinDC(a, b, i);
        }
        else
        {
            return -1;
        }
    }
}