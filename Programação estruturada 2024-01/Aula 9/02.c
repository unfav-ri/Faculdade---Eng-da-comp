#include <stdio.h>
#include <string.h>

int paraDecimal(const char *seq)
{
    int tamanho = strlen(seq);
    int decimal = 0;
    for (int i = tamanho - 1, exp = 0; i >= 0; i--, exp++)
    {
        if (seq[i] == '1')
        {
            decimal += (1 << exp);
        }
    }
    return decimal;
}

int main()
{
    char seq[100];
    printf("Informe uma sequencia binaria: ");
    gets(seq);

    int decimal = paraDecimal(seq);
    printf("O valor em decimal: %d\n", decimal);

    return 0;
}