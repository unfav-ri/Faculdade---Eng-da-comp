#include <stdio.h>

int somamatriz(int matriz[][100], int linha, int coluna)
{
    int soma = 0;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            soma += matriz[i][j];
        }
    }
    return soma;
}

void impmatriz(int matriz[][100], int linha, int coluna)
{
    printf("\nMatriz:\n");
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int linha, coluna;

    printf("Informe o numero de linhas, max[100]: ");
    scanf("%d", &linha);
    printf("informe o numero de colunas, max[100]: ");
    scanf("%d", &coluna);

    int matriz[100][100];

    printf("Informe os elementos da matriz:\n");

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    impmatriz(matriz, linha, coluna);

    int soma = somamatriz(matriz, linha, coluna);
    printf("\nA soma da matriz: %d\n", soma);

    return 0;
}