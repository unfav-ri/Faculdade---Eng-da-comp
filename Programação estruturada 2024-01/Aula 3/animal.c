/*
Neste problema, você deverá ler 3 palavras que definem o tipo de animal possível segundo o esquema abaixo, da esquerda para a direita.  Em seguida conclua qual dos animais seguintes foi escolhido, através das três palavras fornecidas.

             / carnivoro - aguia
         / ave
        /    \ onivoro - pomba
Vertebrado
        \         / onivoro - homem
         \ mamifero
                  \ herbivoro - vaca


                / hematofago - pulga
         / inseto
        /       \ herbivoro - lagarta
invertebrado
        \         / hematofago - sanguessuga
         \ anelideo
                  \ onivoro - minhoca

Entrada
A entrada contém 3 palavras, uma em cada linha, necessárias para identificar o animal segundo a figura acima, com todas as letras minúsculas.

Saída
Imprima o nome do animal correspondente à entrada fornecida.
*/

//Meu resultado:
#include <stdio.h>
#include <string.h>

int main()
{
    char palavra1[20], palavra2[20], palavra3[20];

    scanf("%s", palavra1);
    scanf("%s", palavra2);
    scanf("%s", palavra3);

    if (strcmp(palavra1, "vertebrado") == 0)
    {
        if (strcmp(palavra2, "ave") == 0)
        {
            if (strcmp(palavra3, "carnivoro") == 0)
            {
                printf("aguia\n");
            }
            else if (strcmp(palavra3, "onivoro") == 0)
            {
                printf("pomba\n");
            }
        }
        else if (strcmp(palavra2, "mamifero") == 0)
        {
            if (strcmp(palavra3, "onivoro") == 0)
            {
                printf("homem\n");
            }
            else if (strcmp(palavra3, "herbivoro") == 0)
            {
                printf("vaca\n");
            }
        }
    }
    else if (strcmp(palavra1, "invertebrado") == 0)
    {
        if (strcmp(palavra2, "inseto") == 0)
        {
            if (strcmp(palavra3, "hematofago") == 0)
            {
                printf("pulga\n");
            }
            else if (strcmp(palavra3, "herbivoro") == 0)
            {
                printf("lagarta\n");
            }
        }
        else if (strcmp(palavra2, "anelideo") == 0)
        {
            if (strcmp(palavra3, "hematofago") == 0)
            {
                printf("sanguessuga\n");
            }
            else if (strcmp(palavra3, "onivoro") == 0)
            {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}
