// Função recursiva expoentes.

#include <stdio.h>

int Eleva(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else if (b % 2 != 0) {
        return a * Eleva(a, b - 1);
    }
    else {
        int temp = Eleva(a, b / 2);
        return temp * temp;
    }
}

int main() {
    int base, expoente;
    
    printf("Informe a base: ");
    scanf("%d", &base);
    printf("Informe o expoente: ");
    scanf("%d", &expoente);
    
    printf("Resultado: %d\n", Eleva(base, expoente));
    
    return 0;
}
