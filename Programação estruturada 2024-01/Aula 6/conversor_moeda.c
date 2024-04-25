#include <stdio.h>
#include <stdlib.h>

int main()
{
    float reais, dolar;

    printf("Informe o valor em reais: ");
    scanf("%f", &reais);

    dolar = reais / 4.22;

    printf("Valor em reais: %.2f e em dolar: %.2f", reais, dolar);

    return 0;
}