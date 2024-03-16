#include <stdio.h>
#include <stdbool.h>

bool Primo(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{

    int num;

    printf("informe um numero inteiro: ");
    scanf("%d", &num);

    if (Primo(num))
    {
        printf("%d primo. \n", num);
    }
    else
    {
        printf("%d nao primo. \n", num);
    }

    return 0;
}