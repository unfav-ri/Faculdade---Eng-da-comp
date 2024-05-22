#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100

typedef struct
{
    int DDD;
    char numero[15];
} Telefone;

typedef struct
{
    char rua[50];
    int numero;
    char complemento[30];
    char bairro[30];
    int cep;
    char cidade[30];
    char estado[3];
    char pais[30];
} Endereco;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char nome[50];
    char email[50];
    Telefone telefone;
    Endereco endereco;
    Data dataNascimento;
    char obs[100];
} Pessoa;

Pessoa agenda[MAX_PESSOAS];
int totalPessoas = 0;

void limparBufferEntrada();
void buscarPorNome(char *nome);
void buscarPorMesNascimento(int mes);
void inserirPessoas(Pessoa p);
void retirarPessoas(char *nome);
void imprimirAgenda(int opcao);
void imprimirPessoas(Pessoa p);
void menu();

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void buscarPorNome(char *nome)
{
    int encontrou = 0;

    for (int i = 0; i < totalPessoas; i++)
    {
        if (strstr(agenda[i].nome, nome) != NULL)
        {
            imprimirPessoas(agenda[i]);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("-------------------------------------------\n");
        printf("Nenhuma pessoa encontrada com o nome '%s'.\n", nome);
    }
}

void buscarPorMesNascimento(int mes)
{
    if (mes < 1 || mes > 12)
    {
        printf("-------------------------------------------\n");
        printf("Mes de nascimento invalido! Informe um valor entre [1 - 12].\n");
        return;
    }

    int encontrou = 0;

    for (int i = 0; i < totalPessoas; i++)
    {
        if (agenda[i].dataNascimento.mes == mes)
        {
            imprimirPessoas(agenda[i]);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("-------------------------------------------\n");
        printf("Nenhuma pessoa encontrada com data de nascimento no mes '%d'.\n", mes);
    }
}

void inserirPessoas(Pessoa p)
{
    if (totalPessoas >= MAX_PESSOAS)
    {
        printf("-------------------------------------------\n");
        printf("Agenda cheia! Nao e possivel adicionar mais pessoas.\n");
        return;
    }
    int i, j;
    for (i = 0; i < totalPessoas; i++)
    {
        if (strcmp(p.nome, agenda[i].nome) < 0)
        {
            break;
        }
    }
    for (j = totalPessoas; j > i; j--)
    {
        agenda[j] = agenda[j - 1];
    }
    agenda[i] = p;
    totalPessoas++;
}

void retirarPessoas(char *nome)
{
    for (int i = 0; i < totalPessoas; i++)
    {
        if (strcmp(agenda[i].nome, nome) == 0)
        {
            for (int j = i; j < totalPessoas - 1; j++)
            {
                agenda[j] = agenda[j + 1];
            }
            totalPessoas--;
            printf("-------------------------------------------\n");
            printf("Pessoa '%s' removida da agenda.\n", nome);
            return;
        }
    }
    printf("-------------------------------------------\n");
    printf("Pessoa '%s' nao encontrada na agenda.\n", nome);
}

void imprimirAgenda(int opcao)
{
    if (totalPessoas == 0)
    {
        printf("-------------------------------------------\n");
        printf("A agenda esta vazia. Nenhuma pessoa cadastrada.\n");
        return;
    }

    for (int i = 0; i < totalPessoas; i++)
    {
        if (opcao == 1)
        {
            printf("-------------------------------------------\n");
            printf("Nome: %s, Telefone: (%d) %s, Email: %s\n", agenda[i].nome, agenda[i].telefone.DDD, agenda[i].telefone.numero, agenda[i].email);
        }
        else
        {
            imprimirPessoas(agenda[i]);
        }
    }
}

void imprimirPessoas(Pessoa p)
{
    printf("-------------------------------------------\n");
    printf("Nome: %s\n", p.nome);
    printf("Email: %s\n", p.email);
    printf("Endereco: %s, %d, %s, %s, %d, %s, %s, %s\n", p.endereco.rua, p.endereco.numero, p.endereco.complemento, p.endereco.bairro, p.endereco.cep, p.endereco.cidade, p.endereco.estado, p.endereco.pais);
    printf("Telefone: (%d) %s\n", p.telefone.DDD, p.telefone.numero);
    printf("Data de Nascimento: %02d/%02d/%04d\n", p.dataNascimento.dia, p.dataNascimento.mes, p.dataNascimento.ano);
    printf("Observacao: %s\n", p.obs);
}

void menu()
{
    int opcao;
    do
    {
        printf("-------------------------------------------\n");
        printf("1. Inserir pessoa\n");
        printf("2. Buscar por nome\n");
        printf("3. Buscar por mes de nascimento\n");
        printf("4. Retirar pessoa\n");
        printf("5. Mostrar agenda\n");
        printf("6. Mostrar todos os dados\n");
        printf("7. Sair\n");
        printf("-------------------------------------------\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
        {
            Pessoa p;
            printf("Nome: ");
            fgets(p.nome, sizeof(p.nome), stdin);
            p.nome[strcspn(p.nome, "\n")] = '\0';

            printf("Email: ");
            fgets(p.email, sizeof(p.email), stdin);
            p.email[strcspn(p.email, "\n")] = '\0';

            printf("Endereco - Rua: ");
            fgets(p.endereco.rua, sizeof(p.endereco.rua), stdin);
            p.endereco.rua[strcspn(p.endereco.rua, "\n")] = '\0';

            printf("Endereco - Numero: ");
            scanf("%d", &p.endereco.numero);
            limparBufferEntrada();

            printf("Complemento: ");
            fgets(p.endereco.complemento, sizeof(p.endereco.complemento), stdin);
            p.endereco.complemento[strcspn(p.endereco.complemento, "\n")] = '\0';

            printf("Bairro: ");
            fgets(p.endereco.bairro, sizeof(p.endereco.bairro), stdin);
            p.endereco.bairro[strcspn(p.endereco.bairro, "\n")] = '\0';

            printf("CEP: ");
            scanf("%d", &p.endereco.cep);
            limparBufferEntrada();

            printf("Cidade: ");
            fgets(p.endereco.cidade, sizeof(p.endereco.cidade), stdin);
            p.endereco.cidade[strcspn(p.endereco.cidade, "\n")] = '\0';

            printf("Estado: ");
            fgets(p.endereco.estado, sizeof(p.endereco.estado), stdin);
            p.endereco.estado[strcspn(p.endereco.estado, "\n")] = '\0';

            printf("Pais: ");
            fgets(p.endereco.pais, sizeof(p.endereco.pais), stdin);
            p.endereco.pais[strcspn(p.endereco.pais, "\n")] = '\0';

            printf("Telefone - DDD: ");
            scanf("%d", &p.telefone.DDD);
            limparBufferEntrada();

            printf("Telefone - Numero: ");
            fgets(p.telefone.numero, sizeof(p.telefone.numero), stdin);
            p.telefone.numero[strcspn(p.telefone.numero, "\n")] = '\0';

            printf("Data de nascimento - Dia: ");
            scanf("%d", &p.dataNascimento.dia);
            limparBufferEntrada();

            printf("Mes: ");
            scanf("%d", &p.dataNascimento.mes);
            limparBufferEntrada();

            printf("Ano: ");
            scanf("%d", &p.dataNascimento.ano);
            limparBufferEntrada();

            printf("Observacao: ");
            fgets(p.obs, sizeof(p.obs), stdin);
            p.obs[strcspn(p.obs, "\n")] = '\0';

            inserirPessoas(p);
            break;
        }
        case 2:
        {
            char nome[50];
            printf("Informe o nome para busca: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            buscarPorNome(nome);
            break;
        }
        case 3:
        {
            int mes;
            printf("Informe o mes de nascimento [1 - 12] para a busca: ");
            scanf("%d", &mes);
            limparBufferEntrada();
            buscarPorMesNascimento(mes);
            break;
        }
        case 4:
        {
            char nome[50];
            printf("Informe o nome para remover: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            retirarPessoas(nome);
            break;
        }
        case 5:
        {
            imprimirAgenda(1);
            break;
        }
        case 6:
        {
            imprimirAgenda(2);
            break;
        }
        case 7:
            printf("-------------------------------------------\n");
            printf("Saindo...\n");
            printf("-------------------------------------------\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);
}

int main()
{
    menu();
    return 0;
}