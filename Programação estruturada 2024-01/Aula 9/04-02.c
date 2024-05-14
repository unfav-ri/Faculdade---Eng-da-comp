#include <stdio.h>
#include <ctype.h>

int ehNumero(const char *str)
{

    while (*str != '\0')
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int main()
{
    char palavra[100];

    printf("Informe uma palavra: ");
    gets(palavra);

    if (ehNumero(palavra))
    {
        printf("A palavra digitada eh um numero.\n");
    }
    else
    {
        printf("A palavra digitada eh uma palavra.\n");
    }

    return 0;
}
