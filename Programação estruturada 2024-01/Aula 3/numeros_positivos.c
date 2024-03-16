/*
Faça um programa que leia 6 valores. Estes valores serão somente negativos ou positivos (desconsidere os valores nulos). A seguir, mostre a quantidade de valores positivos digitados.

Entrada
Seis valores, negativos e/ou positivos.

Saída
Imprima uma mensagem dizendo quantos valores positivos foram lidos.
*/

//Meu resultado:
#include <stdio.h>

int main()
{
    float valores[6];
    int positivos = 0;

    for (int i = 0; i < 6; i++)
    {
        scanf("%f", &valores[i]);
        if (valores[i] > 0)
        {
            positivos++;
        }
    }

    printf("%d valores positivos\n", positivos);

    return 0;
}
