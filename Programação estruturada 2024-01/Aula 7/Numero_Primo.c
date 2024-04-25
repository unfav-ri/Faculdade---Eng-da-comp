/*
Na matemática, um Número Primo é aquele que pode ser dividido somente por 1 (um) e por ele mesmo. Por exemplo, o número 7 é primo, pois pode ser dividido apenas pelo número 1 e pelo número 7.

Entrada
A entrada contém vários casos de teste. A primeira linha da entrada contém um inteiro N (1 ≤ N ≤ 100), indicando o número de casos de teste da entrada. Cada uma das N linhas seguintes contém um valor inteiro X (1 < X ≤ 107), que pode ser ou não, um número primo.

Saída
Para cada caso de teste de entrada, imprima a mensagem “X eh primo” ou “X nao eh primo”, de acordo com a especificação fornecida.

Exemplo de Entrada	    Exemplo de Saída
3
8                       8 nao eh primo
51                      51 nao eh primo
7                       7 eh primo
*/
/*
Meu Resultado
*/

#include <stdio.h>
#include <math.h>

int Primo(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    if (num <= 3)
    {
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0)
    {
        return 0;
    }
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int X;
        scanf("%d", &X);

        if (Primo(X))
        {
            printf("%d eh primo\n", X);
        }
        else
        {
            printf("%d nao eh primo\n", X);
        }
    }

    return 0;
}
