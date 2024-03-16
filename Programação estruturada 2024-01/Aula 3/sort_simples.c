/*
Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, uma linha em branco e em seguida, os valores na sequência como foram lidos.

Entrada
A entrada contem três números inteiros.

Saída
Imprima a saída conforme foi especificado.
*/

//Meu resultado:
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int numeros[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &numeros[i]);
    }

    int numeros_originais[3];
    for (int i = 0; i < 3; i++)
    {
        numeros_originais[i] = numeros[i];
    }

    bubbleSort(numeros, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", numeros[i]);
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", numeros_originais[i]);
    }

    return 0;
}
