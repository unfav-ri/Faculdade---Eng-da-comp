#include <stdio.h>

int main () {
    float base, altura, area;

    printf("Informe o valor da base: ");
    scanf("%f", &base);

    printf("informe o valor da altura: ");
    scanf("%f",&altura);

    area = (base * altura) / 2;

    printf("Area: %.2f\n", area);
    
    return 0;
}