/*
Leia um valor inteiro N que é a quantidade de casos de teste que vem a seguir. Cada caso de teste consiste de dois inteiros X e Y. Você deve apresentar a soma de todos os ímpares existentes entre X e Y.

Entrada
A primeira linha de entrada é um inteiro N que é a quantidade de casos de teste que vem a seguir. Cada caso de teste consiste em uma linha contendo dois inteiros X e Y.

Saída
Imprima a soma de todos valores ímpares entre X e Y.

Exemplo de Entrada	    Exemplo de Saída
7                       0
4 5                     11
13 10                   5
6 4                     0
3 3                     0
3 5                     0
3 4                     12
3 8
*/
/*
Meu Resultado:
*/
#include <stdio.h>

int main()
{
    int N, X, Y;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int som_imp = 0;

        scanf("%d %d", &X, &Y);

        if (X > Y)
        {
            int temp = X;
            X = Y;
            Y = temp;
        }

        for (int j = X + 1; j < Y; j++)
        {
            if (j % 2 != 0)
            {
                som_imp += j;
            }
        }

        printf("%d\n", som_imp);
    }

    return 0;
}
