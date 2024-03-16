#include <stdio.h>
#include <stdlib.h>

int main()
{

    float medidaEmMetros, medidaEmPes;

    printf("Digite a medida em metros: ");
    scanf("%f", &medidaEmMetros);

    if (medidaEmMetros < 0)
    {
        printf("Erro: O valor fornecido e negativo. A operacao nao pode ser realizada.\n");
    }
    else
    {

        medidaEmPes = medidaEmMetros * 3.315;

        printf("Medida em metros: %.2f\n", medidaEmMetros);
        printf("Medida em pes: %.2f\n", medidaEmPes);
    }
    return 0;
}
