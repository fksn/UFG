#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void le_conjunto( int * vect, int n );

int main()
{
    int n, v1[100], i;
    scanf("%d", &n);
    le_conjunto(v1, n);
    printf("(%d",v1[0]);
    for (i = 1; i < n; i++)
    {
        printf(",%d",v1[i]);
    }
    printf(")\n");
    return 0;
}
void le_conjunto( int * vect, int n )
{
    int i, cont = 0, aux, j = 0;
    while (n>0)
    {  
        scanf("%d", &aux);
        for (i = 0; i < cont; i++)
        {
            if (aux == vect[i])
            {
                i = 0;
                break;
            }
        }
        if (i == cont)
        {
            vect[j] = aux;
            n--;
            j++;
            cont++;
        }
    }
}