/*
Após a cerimônia de encerramento da Maratona um número enorme de balões soltos estão flutuando no espaço do salão. O dono do salão está bravo porque no dia seguinte ocorre outro evento importante e os balões precisam ser removidos. Felizmente este ano Carlinhos veio preparado com seu arco e flecha para estourar os balões.

Felizmente também, devido ao fluxo do ar condicionado, os balões estão todos em um mesmo plano vertical (isto é, um plano paralelo a uma das paredes), embora em alturas e posições distintas.

Carlinhos vai atirar a partir do lado esquerdo do salão, a uma altura de sua escolha, em direção ao lado direito do salão. Cada flecha se move da esquerda para a direita, na altura em que foi lançada, no mesmo plano vertical dos balões. Ao encontrar um balão, este estoura e a flecha continua seu movimento para a direita, com a altura diminuída de 1. Ou seja, se a flecha estava a uma altura H, após atingir um balão ela continua na altura H-1.

Carlinhos quer estourar todos os balões atirando o menor número possível de flechas. Você pode ajudá-lo?

Entrada
A primeira linha da entrada contém um inteiro N, o número de balões (1≤N≤5*105). Como todos os balões estão num mesmo plano vertical, vamos definir que a altura de um balão é dada em relação ao eixo y e a posição de um balão é dada em relação ao eixo x desse plano. Os balões são numerados de 1 a N. Os números dos balões indicam as suas posições, da esquerda (balão número 1) para a direita (balão número N), independentemente das suas alturas. A posição do balão número i é diferente da posição do balão número i+1, para todo i. A segunda linha contém N inteiros Hi, onde Hi indica a altura em que o balão número i está (1≤Hi≤106 para 1≤i≤N).

Saída
Seu programa deve produzir uma única linha, contendo um único inteiro, o menor número de flechas que Carlinhos precisa atirar para estourar todos os balões.

Exemplos de Entrada	    Exemplos de Saída
5                       2
3 2 1 5 4

4                       4
1 2 3 4

6                       3
5 3 2 4 6 1
*/
/*
Meu Resultado:
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 1000000

int main() {
    int n;
    scanf("%d", &n);
    
    int *heights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    
    int *balloons = (int *)calloc(MAX_HEIGHT + 1, sizeof(int));
    int arrows = 0;

    for (int i = 0; i < n; i++) {
        int height = heights[i];
        if (balloons[height] > 0) {
            balloons[height]--;
            balloons[height - 1]++;
        } else {
            balloons[height - 1]++;
            arrows++;
        }
    }

    printf("%d\n", arrows);

    free(heights);
    free(balloons);

    return 0;
}
