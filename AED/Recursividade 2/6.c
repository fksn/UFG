#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double Raiz(double x, int n);

int main()
{
    int n;
    double r;
    scanf("%d", &n);
    r = Raiz(1, n);
    printf("Raiz: %lf\n", r);
    return 0;
}
double Raiz(double x, int n)
{
    double dif;
    x = x/2.0 + n/(2*x);
    printf("%lf\n", x);
    dif = x - sqrt(n);
    if (dif < 0) dif*=-1;
    
    if (dif > 0.0001)
    {
        Raiz(x, n);
    }
    else
    {
        return x;
    }
}