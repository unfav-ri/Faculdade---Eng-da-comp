#include <stdio.h>

int main()
{
    int qnt_alunos;
    float nota, soma_nt = 0.0, media;

    printf("Informe a quantidade de alunos na sala: ");
    scanf("%d", &qnt_alunos);

    if (qnt_alunos <= 0)
    {
        printf("Quantidade de alunos inválida.\n");
        return 1;
    }

    for (int i = 1; i <= qnt_alunos; i++)
    {
        printf("Digite a nota do aluno %d: ", i);
        scanf("%f", &nota);

        if (nota < 0 || nota > 10)
        {
            printf("Nota inválida.\n");
            return 1;
        }

        soma_nt += nota;
    }

    media = soma_nt / qnt_alunos;

    printf("Media: %.2f\n", media);

    return 0;
}
