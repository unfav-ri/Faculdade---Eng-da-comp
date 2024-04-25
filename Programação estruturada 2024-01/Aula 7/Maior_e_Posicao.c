/*
eia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.

Entrada
O arquivo de entrada contém 100 números inteiros, positivos e distintos.

Saída
Apresente o maior valor lido e a posição de entrada, conforme exemplo abaixo.

Exemplo de Entrada	    Exemplo de Saída
2                       34565
113                     4
45
34565
6
...
8
*/
/*
Meu Resultado: 
*/

#include <stdio.h>

int main()
{
    int num[100];
    int maior = 0, pos = 0;

    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > maior)
        {
            maior = num[i];
            pos = i + 1;
        }
    }

    printf("%d\n", maior);
    printf("%d\n", pos);

    return 0;
}