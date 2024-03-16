#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;

    printf("Informe os coeficientes [a], [b] e [c] da equacao (ax^2 + bx + c = 0): \n");
    printf("a: ");
    scanf("%f", &a);

    printf("b: ");
    scanf("%f", &b);

    printf("c: ");
    scanf("%f", &c);

    delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("x1 = %.2f e x2 = %.2f\n", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        printf("x = %.2f\n", x1);
    }
    else
    {
        printf("A equacao nao possui raizes reais.\n");
    }

    return 0;
}