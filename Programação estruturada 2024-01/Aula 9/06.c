#include <stdio.h>
#include <string.h>

int main()
{
    int totalAlunos;

    printf("Informe o total de alunos: ");
    scanf("%d", &totalAlunos);
    getchar();

    if (totalAlunos <= 0)
    {
        printf("ERRO! Informe um numero positivo de alunos!\n");
        return 1;
    }

    printf("\n");
    printf("RA\tNome\tNota 1\tNota 2\tMedia\tSituacao\n");
    printf("---------------------------------------------\n");
    float mediaTotal = 0;
    for (int i = 0; i < totalAlunos; i++)
    {
        char ra[15];
        char nome[100];
        float nota1, nota2;

        printf("Aluno %d\n", i + 1);
        printf("RA: ");
        scanf("%s", ra);

        printf("Nome: ");
        scanf(" %[^\n]", nome);

        printf("Nota 1: ");
        scanf("%f", &nota1);

        printf("Nota 2: ");
        scanf("%f", &nota2);
        getchar();

        float media = (nota1 + nota2) / 2;
        mediaTotal += media;

        char situacao[15];
        if (media >= 5)
        {
            strcpy(situacao, "Aprovado");
        }
        else
        {
            strcpy(situacao, "Reprovado");
        }

        printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%s\n", ra, nome, nota1, nota2, media, situacao);
    }
    printf("---------------------------------------------\n");

    if (totalAlunos > 0)
    {
        mediaTotal /= totalAlunos;
        printf("Media final da turma: %.1f\n", mediaTotal);
    }

    return 0;
}
