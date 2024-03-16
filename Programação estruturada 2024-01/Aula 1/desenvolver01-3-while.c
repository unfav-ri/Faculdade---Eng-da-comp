#include <stdio.h>

int main()
{

    int num, i = 1;

    printf("digite um numero inteiro entre [1] e [20]: ");
    scanf("%d", &num);

    if (num < 1 || num > 20)
    {
        printf("ESCOLHEU ERRADO, BURRO! \n");
        return 1;
    }

    printf("Tabuada do %d:\n", num);
    while (i <= 10)
    {
        printf("%d x %d = %d\n", num, i, num * i);
        i++;
    }
    return 0;
}