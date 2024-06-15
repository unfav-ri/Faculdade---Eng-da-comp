#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Boleto
{
    char conta[7];
    char num_boleto[9];
    char data_pagamento[9];
    char valor_pago[9];
};

struct Cliente
{
    char cliente[6];
    int total_boletos;
    float total_pago;
    struct Boleto *boletos;
    int num_boletos;
    int capacidade_boletos;
};

struct Cliente *obter_cliente(struct Cliente **clientes, int *num_clientes, const char *cliente_id)
{
    for (int i = 0; i < *num_clientes; ++i)
    {
        if (strcmp((*clientes)[i].cliente, cliente_id) == 0)
        {
            return &(*clientes)[i];
        }
    }
    struct Cliente *temp = realloc(*clientes, (*num_clientes + 1) * sizeof(struct Cliente));
    if (temp == NULL)
    {
        return NULL;
    }
    *clientes = temp;
    strcpy((*clientes)[*num_clientes].cliente, cliente_id);
    (*clientes)[*num_clientes].total_boletos = 0;
    (*clientes)[*num_clientes].total_pago = 0.0;
    (*clientes)[*num_clientes].num_boletos = 0;
    (*clientes)[*num_clientes].capacidade_boletos = 10;
    (*clientes)[*num_clientes].boletos = malloc((*clientes)[*num_clientes].capacidade_boletos * sizeof(struct Boleto));
    if ((*clientes)[*num_clientes].boletos == NULL)
    {
        return NULL;
    }
    return &(*clientes)[(*num_clientes)++];
}

void adicionar_boleto(struct Cliente *cliente, struct Boleto boleto)
{
    if (cliente->num_boletos >= cliente->capacidade_boletos)
    {
        struct Boleto *temp = realloc(cliente->boletos, cliente->capacidade_boletos * 2 * sizeof(struct Boleto));
        if (temp == NULL)
        {
            return;
        }
        cliente->boletos = temp;
        cliente->capacidade_boletos *= 2;
    }
    cliente->boletos[cliente->num_boletos++] = boleto;
}

int eh_numerico(const char *str, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

void gerar_arquivo_retorno(struct Cliente cliente, const char *data_retorno)
{
    char nome_arquivo[20];
    sprintf(nome_arquivo, "%s_%s.txt", data_retorno, cliente.cliente);
    FILE *retorno = fopen(nome_arquivo, "w");
    if (retorno == NULL)
    {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    fprintf(retorno, "1%s\n", data_retorno);

    for (int i = 0; i < cliente.num_boletos; ++i)
    {
        struct Boleto *boleto = &cliente.boletos[i];
        fprintf(retorno, "2%s%s%s%s\n", boleto->conta, boleto->num_boleto, boleto->data_pagamento, boleto->valor_pago);
    }

    fprintf(retorno, "3%06d%010.0f\n", cliente.total_boletos, cliente.total_pago * 100);

    fclose(retorno);
}

void escrever_erro(const char *mensagem)
{
    FILE *erro = fopen("ERRO.TXT", "a");
    if (erro != NULL)
    {
        fprintf(erro, "%s\n", mensagem);
        fclose(erro);
    }
    else
    {
        printf("Erro ao abrir o arquivo ERRO.TXT para escrita.\n");
    }
}

int main(void)
{
    FILE *entrada;
    char linha[46];
    char data_retorno[9] = "";
    int total_boletos = 0;
    float total_pago = 0.0;
    struct Cliente *clientes = NULL;
    int num_clientes = 0;
    int houve_erro = 0;
    int line_count = 1;

    entrada = fopen("remessa.txt", "r");
    if (entrada == NULL)
    {
        houve_erro = 1;
        escrever_erro("Erro: falha ao abrir o arquivo de entrada 'remessa.txt'.");
        return 1;
    }

    FILE *erro = fopen("ERRO.TXT", "w");
    if (erro != NULL)
    {
        fclose(erro);
    }
    else
    {
        fclose(entrada);
        printf("Erro ao abrir o arquivo ERRO.TXT.\n");
        return 1;
    }

    if (fgets(linha, sizeof(linha), entrada) != NULL)
    {
        if (linha[0] != '1' || strlen(linha) != 10)
        {
            houve_erro = 1;
            escrever_erro("Erro: Formato de cabeçalho inválido.");
        }
        else
        {
            strncpy(data_retorno, linha + 1, 8);
            data_retorno[8] = '\0';
        }
    }
    else
    {
        houve_erro = 1;
        escrever_erro("Erro: Não foi possível ler o cabeçalho do arquivo de remessa.");
    }

    while (fgets(linha, sizeof(linha), entrada) != NULL)
    {
        if (strlen(linha) > 0 && linha[strlen(linha) - 1] == '\n')
        {
            linha[strlen(linha) - 1] = '\0';
        }

        if (linha[0] == '\0')
        {
            continue;
        }

        line_count++;

        if (linha[0] != '2' || strlen(linha) != 44)
        {
            houve_erro = 1;
            char mensagem[100];
            sprintf(mensagem, "Erro: Formato de linha de boleto inválido. Linha: %d", line_count);
            escrever_erro(mensagem);
            continue;
        }

        if (!eh_numerico(linha + 1, 5) || !eh_numerico(linha + 6, 6) || !eh_numerico(linha + 12, 8) ||
            !eh_numerico(linha + 20, 8) || !eh_numerico(linha + 28, 8) || !eh_numerico(linha + 36, 8))
        {
            houve_erro = 1;
            char mensagem[100];
            sprintf(mensagem, "Erro: Caractere inválido encontrado na linha de boleto. Linha: %d", line_count);
            escrever_erro(mensagem);
            continue;
        }

        char cliente_id[6];
        strncpy(cliente_id, linha + 1, 5);
        cliente_id[5] = '\0';

        struct Cliente *cliente = obter_cliente(&clientes, &num_clientes, cliente_id);
        if (cliente == NULL)
        {
            houve_erro = 1;
            char mensagem[100];
            sprintf(mensagem, "Erro: Falha ao alocar memória para o cliente. Linha: %d", line_count);
            escrever_erro(mensagem);
            continue;
        }

        total_boletos++;
        float valor = atof(linha + 36) / 100.0;
        total_pago += valor;

        cliente->total_boletos++;
        cliente->total_pago += valor;

        struct Boleto novo_boleto;
        strncpy(novo_boleto.conta, linha + 6, 6);
        novo_boleto.conta[6] = '\0';

        strncpy(novo_boleto.num_boleto, linha + 12, 8);
        novo_boleto.num_boleto[8] = '\0';

        strncpy(novo_boleto.data_pagamento, linha + 28, 8);
        novo_boleto.data_pagamento[8] = '\0';

        strncpy(novo_boleto.valor_pago, linha + 36, 8);
        novo_boleto.valor_pago[8] = '\0';

        adicionar_boleto(cliente, novo_boleto);
    }

    fclose(entrada);

    if (houve_erro == 0)
    {
        remove("ERRO.TXT");

        for (int i = 0; i < num_clientes; ++i)
        {
            gerar_arquivo_retorno(clientes[i], data_retorno);
        }
    }

    for (int i = 0; i < num_clientes; ++i)
    {
        free(clientes[i].boletos);
    }
    free(clientes);

    return 0;
}