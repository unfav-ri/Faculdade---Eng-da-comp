#include <stdio.h>

int main()
{
    char resposta;
    int cont_O = 0, cont_B = 0, cont_R = 0, cont_U = 0, total_respostas = 0;

    printf("Informe as respostas ([O] para Otimo, [B] para Bom, [R] para Regular, [U] para Ruim e [-] para finalizar):\n");
    scanf(" %c", &resposta);

    while (resposta != '-')
    {
        switch (resposta)
        {
        case 'O':
            cont_O++;
            break;
        case 'B':
            cont_B++;
            break;
        case 'R':
            cont_R++;
            break;
        case 'U':
            cont_U++;
            break;
        default:
            break;
        }
        scanf(" %c", &resposta);
    }

    total_respostas = cont_O + cont_B + cont_R + cont_U;

    float percentual_O = (float)cont_O / total_respostas * 100;
    float percentual_B = (float)cont_B / total_respostas * 100;
    float percentual_R = (float)cont_R / total_respostas * 100;
    float percentual_U = (float)cont_U / total_respostas * 100;

    printf("\nQuantidade de respostas:\n");
    printf("Otimo: %d\n", cont_O);
    printf("Bom: %d\n", cont_B);
    printf("Regular: %d\n", cont_R);
    printf("Ruim: %d\n", cont_U);
    printf("Total de respostas: %d\n", total_respostas);
    printf("\nPorcentagem de respostas:\n");
    printf("Otimo: %.2f%%\n", percentual_O);
    printf("Bom: %.2f%%\n", percentual_B);
    printf("Regular: %.2f%%\n", percentual_R);
    printf("Ruim: %.2f%%\n", percentual_U);

    if (cont_O + cont_B > cont_R + cont_U)
    {
        printf("\nO feedback [Otimo] e [Bom] e maior que [Regular] e [Ruim].\n");
    }
    else
    {
        printf("\nO feedback [Otimo] e [Bom] nao e maior que [Regular] e [Ruim].\n");
    }

    return 0;
}
