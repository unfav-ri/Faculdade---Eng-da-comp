#include <stdio.h>

int main()
{
    float a, b, x, lim_inf, lim_sup, incr;

    printf("Informe os coeficientes [a] e [b] da funcao f(x) = ax + b:\n");
    printf("a: ");
    scanf("%f", &a);

    printf("b: ");
    scanf("%f", &b);

    printf("Informe o limite inferior do intervalo de x: ");
    scanf("%f", &lim_inf);

    printf("Informe o limite superior do intervalo de x: ");
    scanf("%f", &lim_sup);

    printf("Informe o incremento de x: ");
    scanf("%f", &incr);

    printf("\n  x     |     y\n");
    printf("--------|--------\n");

    for (x = lim_inf; x <= lim_sup; x += incr)
    {
        float y = a * x + b;
        printf("%7.2f | %7.2f\n", x, y);
    }

    return 0;
}