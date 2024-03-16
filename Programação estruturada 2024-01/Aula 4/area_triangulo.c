#include <stdio.h>
#include <stdlib.h>

float arearet(float b, float h)
{
    return b * h;
}

float areatri(float b, float h)
{
    return (b * h) / 2;
}

int main()
{
    float b, h, a;
    int escolha;

    printf("Escolha a forma. [1] retangulo e [2] triangulo: ");
    scanf("%d", &escolha);
    printf("Informe a base: ");
    scanf("%f", &b);
    printf("Informe a altura: ");
    scanf("%f", &h);

    if (escolha == 1)
    {
        a = arearet(b, h);
    }
    else
    {
        a = areatri(b, h);
    }
    printf("Area: %.2f", a);
    return 0;
}