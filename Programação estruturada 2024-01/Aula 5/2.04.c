//Função de Ackerman
#include <stdio.h>

int Ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return Ackermann(m - 1, 1);
    }
    else
    {
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main()
{
    int m, n;

    printf("Informe o valor de m: ");
    scanf("%d", &m);

    printf("Informe o valor de n: ");
    scanf("%d", &n);

    printf("Ackermann(%d,%d) = %d\n", m, n, Ackermann(m, n));

    return 0;
}
