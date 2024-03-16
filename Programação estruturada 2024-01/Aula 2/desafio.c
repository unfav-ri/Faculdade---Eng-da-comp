#include <stdio.h>

int main()
{
    int num;

    printf("Informe um valor inteiro entre [0] e [1000]: ");
    scanf("%d", &num);

    if (num < 0 || num > 1000)
    {
        printf("Valor fora do intervalo permitido.\n");
        return 1;
    }

    int numeros[num];

    printf("Informe os [%d] numeros inteiros:\n", num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Valores:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (numeros[j] > numeros[j + 1])
            {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    printf("Crescente:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("Decrescente:\n");
    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
