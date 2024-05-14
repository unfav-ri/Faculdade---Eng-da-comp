#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nomeInteiro(const char *nome, const char *sobrenome)
{
    char *nomeCompleto = malloc(strlen(nome) + strlen(sobrenome) + 2);
    strcpy(nomeCompleto, nome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenome);
    return nomeCompleto;
}

int main()
{
    char nome[50], sobrenome[50];
    printf("Informe o nome: ");
    gets(nome);
    printf("Informe o sobrenome: ");
    gets(sobrenome);

    char *nomeCompleto = nomeInteiro(nome, sobrenome);
    printf("Nome completo: %s\n", nomeCompleto);

    free(nomeCompleto);

    return 0;
}