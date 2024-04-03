//Triângulo de Pascal
#include <stdio.h>

int Pascal(int lin, int col)
{
    if (col == 1 || col == lin)
    {
        return 1;
    }
    else
    {
        return Pascal(lin - 1, col - 1) + Pascal(lin - 1, col);
    }
}

int main()
{
    int linha, coluna;

    printf("Informe o numero da linha: ");
    scanf("%d", &linha);

    printf("Informe o numero da coluna: ");
    scanf("%d", &coluna);

    printf("Pascal(%d,%d) = %d\n", linha, coluna, Pascal(linha, coluna));

    return 0;
}
