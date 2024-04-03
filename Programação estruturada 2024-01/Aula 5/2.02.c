//Somatória

#include <stdio.h>

int Somat(int n)
{
    if (n == 1)
    {
        return 1;
    }

    else
    {
        return n + Somat(n - 1);
    }
}

int main()
{
    int numero;

    printf("Informe um numero para calcular a somatoria: ");
    scanf("%d", &numero);

    printf("Somatoria ate %d = %d\n", numero, Somat(numero));

    return 0;
}
