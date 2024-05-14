#include <stdio.h>

size_t strlen(const char *str)
{
    size_t length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

char *strcat(char *dest, const char *src)
{
    char *ptr = dest;
    while (*ptr != '\0')
    {
        ptr++;
    }

    if (ptr != dest)
        *ptr++ = ' ';
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

char *strcpy(char *dest, const char *src)
{
    char *ptr = dest;
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

int main()
{
    char palavra[100];
    char destino[100];

    printf("Informe uma palavra: ");
    gets(palavra);

    printf("Tamanho da palavra: %zu\n", strlen(palavra));

    printf("Informe uma palavra para concatenar: ");
    gets(destino);

    strcat(palavra, destino);
    printf("Palavra concatenada: %s\n", palavra);

    strcpy(destino, palavra);
    printf("Palavra copiada: %s\n", destino);

    return 0;
}
