#include <stdio.h>
#include <math.h>
void calcula(int X);
double y = 0;
int main()
{
    int N;
    scanf("%d",&N);
    calcula(N);
    printf("O valor da somatoria e: %lf\n", y);
    return 0;
}
void calcula( int X )
{
    int i;
    double fat = 1;
    for (i = 1; i <= X; i++)
    {
        fat = fat * i;
        y += 1 / fat;
    }
}