#include <stdio.h>
#include <math.h>

int fibonacci(int a, int b, int n);

int main()
{
    int a, result;
    scanf("%d", &a);
    if(a>2) result = fibonacci(1, 1, a-2);  
    else result = 1;
    printf("O termo fibonacci eh: %d\n", result);
    return 0;
}
int fibonacci(int a, int b, int n)
{
    int aux;
    aux = a+b;
    a = b;
    b = aux;
    n--;
    if (n>0)
    {
        fibonacci(a, b, n);
    }
    else
    {
        return b;
    }
    
}