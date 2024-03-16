#include <stdio.h>

int main()
{
    float n1, n2, n3;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &n3);

    float maior = n1;

    if (n2 > maior)
    {
        maior = n2;
    }

    if (n3 > maior)
    {
        maior = n3;
    }

    printf("O maior: %.2f\n", maior);

    return 0;
}
