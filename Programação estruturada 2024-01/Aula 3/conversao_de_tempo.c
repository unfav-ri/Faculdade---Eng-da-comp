/*
Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento em uma fábrica, e informe-o expresso no formato horas:minutos:segundos.

Entrada
O arquivo de entrada contém um valor inteiro N.

Saída
Imprima o tempo lido no arquivo de entrada (segundos), convertido para horas:minutos:segundos, conforme exemplo fornecido.
*/

//Meu resultado:
#include <stdio.h>

int main()
{

    int tempo, hrs, mins, segs;

    scanf("%d", &tempo);

    hrs = tempo / 3600;
    tempo %= 3600;
    mins = tempo / 60;
    segs = tempo % 60;

    printf("%d:%d:%d\n", hrs, mins, segs);

    return 0;
}