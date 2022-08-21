#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int bin(int n);

int main()
{
    int n;
    scanf("%d", &n);
    bin(n);
    printf("\n");
    return 0;
}
int bin(int n)
{
    if (n>1)
    {
        bin(n/2);
    }
    printf("%d", n%2);
    return 0;
}