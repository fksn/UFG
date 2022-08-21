#include <stdio.h>
#include <math.h>
void calcula(int N);
double X = 1;
int main()
{
    int N;
    printf("Raiz quadrada a ser calculada: ");
    scanf("%d",&N);
    calcula(N);
    printf("O valor da raiz quadrada calculada e: %lf, via SQRT e: %lf\n", X, sqrt(N));
    return 0;
}
void calcula( int N )
{
    int i;
    for (i = 0; i < 10; i++)
    {
        X = X/2.0 + N/(2.0*X);
    }
}