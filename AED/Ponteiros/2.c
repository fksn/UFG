#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void circulo(double * r, double * peri, double * area);

int main()
{
    double r, peri, area;

    printf("Valor do raio: ");
    scanf("%lf",&r);
    circulo(&r, &peri, &area);
    printf("Perimetro: %lf\nArea: %lf\n", peri, area);
    return 0;
}

void circulo(double * r, double * peri, double * area)
{
    *peri = 2 * M_PI * (*r);
    *area = M_PI * ( (*r) * (*r) );
}