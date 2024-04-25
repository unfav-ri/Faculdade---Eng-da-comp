/*
Um quadrado possui seus vértices nas coordenadas (0, 0), (0,2^N), (2^N,2^N), (2^N,0). Cada vértice possui um atrator. Uma partícula é posicionada inicialmente na posição (2^N-1,2^N-1), Cada atrator pode ser ativado individualmente, qualquer quantidade de vezes. Quando um atrator na posição (i,j) é ativado, se a partícula encontra-se na posição (p,q), ela desloca-se para o ponto médio entre (i,j) e (p,q).
Dados N e um ponto (x,y), determine o menor número de ativações necessárias para que a partícula seja posicionada na posição (x,y).

Entrada
A entrada consiste de uma única linha contendo três inteiros N, x e y, satisfazendo 1≤N≤20 e 0<x,y<2^N.

Saída
Imprima uma única linha, contendo o menor número de ativações necessárias.

Exemplos de Entrada	    Exemplos de Saída
1 1 1                   0
4 12 4                  1
4 3 1                   3
*/
/*
Meu Resultado:
*/

#include <stdio.h>

#define N 200010

void dp()
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    int cnt;
    for (cnt = 0; x % 2 == 0 && y % 2 == 0; cnt++)
    {
        x /= 2;
        y /= 2;
    }
    printf("%d\n", n - cnt - 1);
}

int main()
{
    int t;
    t = 1;
    while (t--)
        dp();
    return 0;
}
