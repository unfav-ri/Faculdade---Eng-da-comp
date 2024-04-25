#include <stdio.h>

float somat(float x)
{
    float somatorio = 0;
    int i;

    for (i = 1; i <= 50; i++)
    {
        somatorio += x / i;
    }
    return somatorio;
}

int main()
{
    float x, somatorio;

    printf("Informe o valor de [x]: ");
    scanf("%f", &x);

    somatorio = somat(x);

    printf("O somatorio dos 50 primeiros termos da serie: %.2f\n", somatorio);
    return 0;
}