#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int MaxDC(int a, int b, int i);

int main()
{
    int a, b, n;
    
    scanf("%d %d", &a, &b);
    n = fmin(a, b);
    n = MaxDC(n, a+b-n, n);
    printf("MaxDC: %d\n", n);
    return 0;
}
int MaxDC(int a, int b, int i)
{
    if (a%i==0 && b%i==0)
    {
        return i;
    }
    else
    {
        if (i>1)
        {
            i--;
            MaxDC(a, b, i);
        }
        else
        {
            return -1;
        }
    }
}