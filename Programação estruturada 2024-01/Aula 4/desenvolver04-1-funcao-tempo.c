#include <stdio.h>

int seg_decorridos(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int total_s1 = h1 * 3600 + m1 * 60 + s1;
    int total_s2 = h2 * 3600 + m2 * 60 + s2;

    if (total_s2 < total_s1)
    {
        printf("Erro: O segundo instante ocorre antes do primeiro instante. \n");
        return 1;
    }

    return total_s2 - total_s1;
}

int main()
{
    int h1, h2, m1, m2, s1, s2;

    printf("Informe o primeiro instante [hora minuto segundo]: ");
    scanf("%d %d %d", &h1, &m1, &s1);
    printf("Informe o segundo instante [hora minuto segundo]: ");
    scanf("%d %d %d", &h2, &m2, &s2);

    int seg = seg_decorridos(h1, m1, s1, h2, m2, s2);

    if (seg != 1)
    {
        printf("Segundos decorridos: %d\n", seg);
    }

    return 0;
}