#include <stdio.h>

#define MAX_linhas 100
#define MAX_colunas 100

void transposta(int matrix[][MAX_colunas], int linhas, int colunas)
{
    int temp;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = i + 1; j < colunas; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void addMatrizes(int matrix1[][MAX_colunas], int matrix2[][MAX_colunas], int resultado[][MAX_colunas], int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            resultado[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main()
{
    int linhas, colunas;
    printf("Informe o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    int matrix[MAX_linhas][MAX_colunas];
    printf("Informe os elementos da matriz: \n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    transposta(matrix, linhas, colunas);

    printf("Matriz transposta: \n");
    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int matrix1[MAX_linhas][MAX_colunas], matrix2[MAX_linhas][MAX_colunas], resultado[MAX_linhas][MAX_colunas];
    printf("Informe os elementos da primeira matriz: \n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Informe os elementos da segunda matriz: \n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    addMatrizes(matrix1, matrix2, resultado, linhas, colunas);

    printf("Soma das matrizes: \n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
