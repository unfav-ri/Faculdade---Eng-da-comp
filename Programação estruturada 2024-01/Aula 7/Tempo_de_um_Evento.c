/*
Pedrinho está organizando um evento em sua Universidade. O evento deverá ser no mês de Abril, iniciando e terminando dentro do mês. O problema é que Pedrinho quer calcular o tempo que o evento vai durar, uma vez que ele sabe quando inicia e quando termina o evento.

Sabendo que o evento pode durar de poucos segundos a vários dias, você deverá ajudar Pedrinho a calcular a duração deste evento.

Entrada
Como entrada, na primeira linha vai haver a descrição “Dia”, seguido de um espaço e o dia do mês no qual o evento vai começar. Na linha seguinte, será informado o momento no qual o evento vai iniciar, no formato hh : mm : ss. Na terceira e quarta linha de entrada haverá outra informação no mesmo formato das duas primeiras linhas, indicando o término do evento.

Saída
Na saída, deve ser apresentada a duração do evento, no seguinte formato:

W dia(s)
X hora(s)
Y minuto(s)
Z segundo(s)

Obs: Considere que o evento do caso de teste para o problema tem duração mínima de 1 minuto.

Exemplo de Entrada	    Exemplo de Saída
Dia 5                   3 dia(s)
08 : 12 : 23            22 hora(s)
Dia 9                   1 minuto(s)
06 : 13 : 23            0 segundo(s)
*/
/*
Meu Resultado: 
*/

#include <stdio.h>

int main()
{
    char dia_inicio[4], dia_termino[4];
    int dia_ini, dia_fim, hora_ini, min_ini, seg_ini, hora_fim, min_fim, seg_fim;

    scanf("%s %d", dia_inicio, &dia_ini);
    scanf("%d : %d : %d", &hora_ini, &min_ini, &seg_ini);
    scanf("%s %d", dia_termino, &dia_fim);
    scanf("%d : %d : %d", &hora_fim, &min_fim, &seg_fim);

    int duracao_segundos = (dia_fim - dia_ini) * 24 * 3600 +
                           (hora_fim - hora_ini) * 3600 +
                           (min_fim - min_ini) * 60 +
                           (seg_fim - seg_ini);

    int dias = duracao_segundos / (24 * 3600);
    int horas = (duracao_segundos % (24 * 3600)) / 3600;
    int minutos = ((duracao_segundos % (24 * 3600)) % 3600) / 60;
    int segundos = ((duracao_segundos % (24 * 3600)) % 3600) % 60;

    printf("%d dia(s)\n", dias);
    printf("%d hora(s)\n", horas);
    printf("%d minuto(s)\n", minutos);
    printf("%d segundo(s)\n", segundos);

    return 0;
}
