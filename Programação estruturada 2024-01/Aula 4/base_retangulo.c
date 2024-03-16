#include <stdio.h>
#include <stdlib.h>

float area(float b, float h)
{
    return b * h;
}

int main()
{
    float b, h, a;
    printf("Informe a medida da base: ");
    scanf("%f", &b);
    printf("Informe a medida da altura: ");
    scanf("%f", &h);

    a = area(b, h);
    printf("Area: %.2f", a);
    return 0;
}