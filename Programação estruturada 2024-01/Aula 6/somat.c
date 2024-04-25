#include <stdio.h>

int main()
{
    float x, soma = 0;
    int i;

    printf("Informe o valor de [x]: ");
    scanf("%f", &x);

    for (i = 1; i <= 50; i++)
    {
        soma += x / i;
    }

    printf("O somatorio dos 50 primeiros termos da serie: %.2f\n", soma);
    return 0;
}