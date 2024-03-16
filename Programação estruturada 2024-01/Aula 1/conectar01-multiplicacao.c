#include <stdio.h>
#include <stdlib.h>

int main() // alterado void para int
{
   float n1, n2, m;

   printf("Digite um numero: ");
   scanf("%f", &n1);
   getchar(); // Limpa o buffer

   printf("Digite outro numero: ");
   scanf("%f", &n2);
   getchar(); // Limpa o buffer

   m = n1 * n2;
   printf("O produto dos numeros eh: %f\n", m);

   return 0; // adicionado o valor 0 para executar com sucesso.
}

/*
De acordo com o padrão ANSI C, a função main() deve retornar um valor inteiro, que geralmente é 0 para indicar que o programa foi executado com sucesso.
Portanto, é preferível declarar int main() em vez de void main().
Embora muitos compiladores permitam o uso de void main(), é uma prática melhor usar int main().
*/

/*
Limpeza de buffer após scanf(): É uma boa prática limpar o buffer de entrada após a leitura de valores usando scanf() para evitar problemas de entrada residual.
Você pode fazer isso adicionando um espaço em branco antes do %f na função scanf(), como %f, ou usando getchar() para limpar o buffer de entrada após a leitura.
*/