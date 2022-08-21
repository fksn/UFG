#include <stdio.h>

void BSRecursivo(int a[], int num);

int main()
{
    int i, a[10] = {20, 5, 1, 7, 19, 4, 3, 13, 12, 11};
    printf("Vetor antes da ordenação: {20, 5, 1, 7, 19, 4, 3, 13, 12, 11}\n");
    printf("Vetor depois da ordenação: {");
    BSRecursivo(a, 10);
    for(i = 0 ; i < 10 ; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("}\n");
}

void BSRecursivo(int a[],int num)
{
    int i,j,temp;
    i = num;
    if(i > 0)
    {
        for(j = 0 ; j < num-1 ; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        BSRecursivo(a, num-1);
    }
    else
    {
        return;
    }
}