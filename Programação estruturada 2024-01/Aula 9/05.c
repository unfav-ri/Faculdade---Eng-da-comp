#include <stdio.h>
#include <string.h>

void trocaPalavra(char *str1, char *str2)
{
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main()
{
    char palavras[3][100];

    printf("Informe a primeira palavra: ");
    gets(palavras[0]);

    printf("Informe a segunda palavra: ");
    gets(palavras[1]);

    printf("Informe a terceira palavra: ");
    gets(palavras[2]);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (strcmp(palavras[j], palavras[j + 1]) > 0)
            {
                trocaPalavra(palavras[j], palavras[j + 1]);
            }
        }
    }

    printf("\nAs palavras em ordem crescente sao:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", palavras[i]);
    }

    return 0;
}
