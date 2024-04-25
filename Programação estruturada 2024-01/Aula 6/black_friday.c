#include <stdio.h>
#include <stdlib.h>

int main()
{
    float preco, desconto;
    int cod;

    printf("Informe o codigo do produto: ");
    scanf("%d", &cod);
    printf("Informe o preco do produto: ");
    scanf("%f", &preco);

    if (preco < 0)
    {
        printf("ERRO: Nao pode ser negativo!");
    }
    else if (preco >= 0 && preco < 50)
    {
        desconto = preco * 0.30;
    }
    else if (preco >= 50 && preco < 200)
    {
        desconto = preco * 0.20;
    }
    else if (preco >= 200 && preco < 500)
    {
        desconto = preco * 0.10;
    }
    else
    {
        desconto = preco * 0.05;
    }

    float pn = preco - desconto;
    printf("O codigo do produto e: %d e seu preco com desconto: %.2f\n", cod, pn);

    return 0;
}
