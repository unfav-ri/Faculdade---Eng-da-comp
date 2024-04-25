/*
No oitavo episodio da segunda temporada do seriado The Big Bang Theory, The Lizard-Spock Expansion, Sheldon e Raj discutem qual dos dois é o melhor: o filme Saturn 3 ou a série Deep Space 9. A sugestão de Raj para a resolução do impasse é uma disputa de Pedra-Papel-Tesoura. Contudo, Sheldon argumenta que, se as partes envolvidas se conhecem, entre 75% e 80% das disputas de Pedra-Papel-Tesoura terminam empatadas, e então sugere o Pedra-Papel-Tesoura-Lagarto-Spock.

As regras do jogo proposto são:

1.a tesoura corta o papel;
2.o papel embrulha a pedra;
3.a pedra esmaga o lagarto;
4.o lagarto envenena Spock;
5.Spock destrói a tesoura;
6.a tesoura decapita o lagarto;
7.o lagarto come o papel;
8.o papel contesta Spock;
9.Spock vaporiza a pedra;
10.a pedra quebra a tesoura.

Embora a situação não se resolva no episódio (ambos escolhem Spock, resultando em um empate), não é difıcil deduzir o que aconteceria se a disputa continuasse. Caso Sheldon vencesse, ele se deleitaria com a vitória, exclamando "Bazinga!"; caso Raj vencesse, ele concluiria que "Raj trapaceou!"; caso o resultado fosse empate, ele exigiria nova partida: "De novo!". Conhecidas as personagens do jogo escolhido por ambos, faça um programa que imprima a provável reação de Sheldon.

Entrada
A entrada consiste em uma série de casos de teste. A primeira linha contém um inteiro positivo T (T ≤ 100), que representa o número de casos de teste. Cada caso de teste é representado por uma linha da entrada, contendo as escolhas de Sheldon e Raj, respectivamente, separadas por um espaço em branco. As escolha possíveis são as personagens do jogo: pedra, papel, tesoura, lagarto e Spock.

Saida
Para cada caso de teste deverá ser impressa a mensagem "Caso #t: R", onde t é o número do caso de teste (cuja contagem se inicia no número um) e R é uma das três reações possíveis de Sheldon: "Bazinga!", "Raj trapaceou!", ou "De novo!".

Exemplos de Entrada	        Exemplos de Saída
3
papel pedra                 Caso #1: Bazinga!
lagarto tesoura             Caso #2: Raj trapaceou!
Spock Spock                 Caso #3: De novo!
*/
/*
Meu Resultado:
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        char sheldon[20], raj[20];
        scanf("%s %s", sheldon, raj);

        printf("Caso #%d: ", i + 1);

        if (strcmp(sheldon, raj) == 0)
        {
            printf("De novo!\n");
        }
        else if (strcmp(sheldon, "pedra") == 0)
        {
            if (strcmp(raj, "tesoura") == 0 || strcmp(raj, "lagarto") == 0)
            {
                printf("Bazinga!\n");
            }
            else
            {
                printf("Raj trapaceou!\n");
            }
        }
        else if (strcmp(sheldon, "papel") == 0)
        {
            if (strcmp(raj, "pedra") == 0 || strcmp(raj, "Spock") == 0)
            {
                printf("Bazinga!\n");
            }
            else
            {
                printf("Raj trapaceou!\n");
            }
        }
        else if (strcmp(sheldon, "tesoura") == 0)
        {
            if (strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0)
            {
                printf("Bazinga!\n");
            }
            else
            {
                printf("Raj trapaceou!\n");
            }
        }
        else if (strcmp(sheldon, "lagarto") == 0)
        {
            if (strcmp(raj, "papel") == 0 || strcmp(raj, "Spock") == 0)
            {
                printf("Bazinga!\n");
            }
            else
            {
                printf("Raj trapaceou!\n");
            }
        }
        else if (strcmp(sheldon, "Spock") == 0)
        {
            if (strcmp(raj, "pedra") == 0 || strcmp(raj, "tesoura") == 0)
            {
                printf("Bazinga!\n");
            }
            else
            {
                printf("Raj trapaceou!\n");
            }
        }
    }

    return 0;
}
