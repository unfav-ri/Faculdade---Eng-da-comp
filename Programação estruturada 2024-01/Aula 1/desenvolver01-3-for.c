#include <stdio.h>

int main()
{

    int num;

    printf("digite um numero inteiro entre [1] e [20]: ");
    scanf("%d", &num);

    if (num < 1 || num > 20)
    {
        printf("ESCOLHEU ERRADO, BURRO! \n");
        return 1;
    }

    printf("Tabuada do %d:\n", num);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return 0;
}