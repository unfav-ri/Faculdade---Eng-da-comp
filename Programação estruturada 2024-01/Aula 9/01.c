#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ehPalindrome(char *palavra)
{
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho / 2; i++)
    {
        if (palavra[i] != palavra[tamanho - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char palavra[100];
    printf("Informe uma palavra: ");
    gets(palavra);

    if (ehPalindrome(palavra))
    {
        printf("A palavra \"%s\" eh um palindromo.\n", palavra);
    }
    else
    {
        printf("A palavra \"%s\" nao eh um palindromo.\n", palavra);
    }

    return 0;
}