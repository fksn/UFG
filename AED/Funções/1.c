#include <stdio.h>
#include <math.h>
void calcula(int X);
double y = 1;
int main()
{
    int X;
    scanf("%d",&X);
    calcula(X);
    printf("O valor de Y e: %lf\n", y);
    return 0;
}
void calcula( int X )
{
    int i;
    double pot = X, fat = 1;
    for (i = 2; i <= X; i++)
    {
        pot = pot * X;
        fat = fat * i;
        y += ((i - 1) * pot) / fat;
    }
}