#include <stdio.h>

int main()
{
    int identificacao, identificacao_maior, identificacao_menor;
    float peso, peso_maior = 0, peso_menor = 999999, peso_total = 0;
    int contador = 0;

    printf("Informe a identificacao e peso de cada boi [digite [0 0] para finalizar]:\n");

    while (1)
    {
        printf("Identificacao e peso: ");
        scanf("%d %f", &identificacao, &peso);

        if (identificacao == 0)
            break;

        peso_total += peso;
        contador++;

        if (peso > peso_maior)
        {
            peso_maior = peso;
            identificacao_maior = identificacao;
        }

        if (peso < peso_menor)
        {
            peso_menor = peso;
            identificacao_menor = identificacao;
        }
    }

    if (contador > 0)
    {
        float peso_medio = peso_total / contador;

        printf("\nMais pesado: \nIdentificacao: %d\nPeso: %.2f\n", identificacao_maior, peso_maior);
        printf("\nMais leve: \nIdentificacao: %d\nPeso: %.2f\n", identificacao_menor, peso_menor);
        printf("\nPeso medio: %.2f\n", peso_medio);
    }
    else
    {
        printf("Nenhum dado foi lido.\n");
    }

    return 0;
}
