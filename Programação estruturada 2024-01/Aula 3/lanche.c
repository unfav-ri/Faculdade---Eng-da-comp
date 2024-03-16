/*
Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. A seguir, calcule e mostre o valor da conta a pagar.

CODIGO    ESPECIFICAÇÃO      PREÇO
1        Cachorro Quente    R$ 4,00
2        X-Salada           R$ 4,50 
3        X-Bacon            R$ 5,00
4        Torrada simples    R$ 2,00 
5        Refrigerante       R$ 1,50


Entrada
O arquivo de entrada contém dois valores inteiros correspondentes ao código e à quantidade de um item conforme tabela acima.

Saída
O arquivo de saída deve conter a mensagem "Total: R$ " seguido pelo valor a ser pago, com 2 casas após o ponto decimal.
*/

//Meu resultado:
#include <stdio.h>

int main()
{

    int cod, qnt;
    double price;

    scanf("%d %d", &cod, &qnt);

    switch (cod)
    {
    case 1:
        price = 4.00;
        break;
    case 2:
        price = 4.50;
        break;
    case 3:
        price = 5.00;
        break;
    case 4:
        price = 2.00;
        break;
    case 5:
        price = 1.50;
        break;
    default:
        printf("Codigo invalido\n");
        return 1;
    }

    double total = price * qnt;

    printf("Total: R$ %.2f\n", total);

    return 0;
}