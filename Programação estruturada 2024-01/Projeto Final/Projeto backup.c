#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char conta[7];
    char num_boleto[9];
    char data_pagamento[9];
    char valor_pago[9];
} Boleto;

typedef struct {
    char cliente[6];
    int total_boletos;
    float total_pago;
    Boleto *boletos;
    int num_boletos;
    int capacidade_boletos;
} Cliente;

Cliente *obter_cliente(Cliente **clientes, int *num_clientes, const char *cliente_id) {
    for (int i = 0; i < *num_clientes; ++i) {
        if (strcmp((*clientes)[i].cliente, cliente_id) == 0) {
            return &(*clientes)[i];
        }
    }
    *clientes = realloc(*clientes, (*num_clientes + 1) * sizeof(Cliente));
    strcpy((*clientes)[*num_clientes].cliente, cliente_id);
    (*clientes)[*num_clientes].total_boletos = 0;
    (*clientes)[*num_clientes].total_pago = 0.0;
    (*clientes)[*num_clientes].num_boletos = 0;
    (*clientes)[*num_clientes].capacidade_boletos = 10;
    (*clientes)[*num_clientes].boletos = malloc((*clientes)[*num_clientes].capacidade_boletos * sizeof(Boleto));
    return &(*clientes)[(*num_clientes)++];
}

void adicionar_boleto(Cliente *cliente, Boleto boleto) {
    if (cliente->num_boletos >= cliente->capacidade_boletos) {
        cliente->capacidade_boletos *= 2;
        cliente->boletos = realloc(cliente->boletos, cliente->capacidade_boletos * sizeof(Boleto));
    }
    cliente->boletos[cliente->num_boletos++] = boleto;
}

int is_numeric(const char *str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void gerar_arquivo_retorno(Cliente cliente, const char *data_retorno) {
    char nome_arquivo[20];
    sprintf(nome_arquivo, "%s_%s.txt", data_retorno, cliente.cliente);
    FILE *retorno = fopen(nome_arquivo, "w");
    if (retorno == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    fprintf(retorno, "1%s\n", data_retorno);

    for (int i = 0; i < cliente.num_boletos; ++i) {
        Boleto *boleto = &cliente.boletos[i];
        fprintf(retorno, "2%s%s%s%s\n", boleto->conta, boleto->num_boleto, boleto->data_pagamento, boleto->valor_pago);
    }

    fprintf(retorno, "3%06d%010.0f\n", cliente.total_boletos, cliente.total_pago * 100);

    fclose(retorno);
}

int main(void) {
    FILE *entrada;
    char linha[46];
    char data_retorno[9] = "";
    int total_boletos = 0;
    float total_pago = 0.0;
    Cliente *clientes = NULL;
    int num_clientes = 0;
    int houve_erro = 0;
    int line_count = 1;

    FILE *erro = fopen("ERRO.TXT", "w");
    if (erro == NULL) {
        printf("Erro ao abrir o arquivo ERRO.TXT.\n");
        return 1;
    }
    fclose(erro);

    entrada = fopen("remessa.txt", "r");
    if (entrada == NULL) {
        houve_erro = 1;
        erro = fopen("ERRO.TXT", "a");
        if (erro != NULL) {
            fprintf(erro, "Erro: falha ao abrir o arquivo de entrada 'remessa.txt'.\n");
            fclose(erro);
        }
        return 1;
    }

    if (fgets(linha, sizeof(linha), entrada) != NULL) {
        if (linha[0] != '1' || strlen(linha) != 10) {
            houve_erro = 1;
            erro = fopen("ERRO.TXT", "a");
            if (erro != NULL) {
                fprintf(erro, "Erro: Formato de cabeçalho inválido.\n");
                fclose(erro);
            }
        } else {
            strncpy(data_retorno, linha + 1, 8);
            data_retorno[8] = '\0';
        }
    } else {
        houve_erro = 1;
        erro = fopen("ERRO.TXT", "a");
        if (erro != NULL) {
            fprintf(erro, "Erro: Não foi possível ler o cabeçalho do arquivo de remessa.\n");
            fclose(erro);
        }
    }

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        if (strlen(linha) > 0 && linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        if (linha[0] == '\0') {
            continue;
        }

        line_count++;

        if (linha[0] != '2' || strlen(linha) != 44) {
            houve_erro = 1;
            erro = fopen("ERRO.TXT", "a");
            if (erro != NULL) {
                fprintf(erro, "Erro: Formato de linha de boleto inválido. Linha: %d\n", line_count);
                fclose(erro);
            }
            continue;
        }

        if (!is_numeric(linha + 1, 5) || !is_numeric(linha + 6, 6) || !is_numeric(linha + 12, 8) ||
            !is_numeric(linha + 20, 8) || !is_numeric(linha + 28, 8) || !is_numeric(linha + 36, 8)) {
            houve_erro = 1;
            erro = fopen("ERRO.TXT", "a");
            if (erro != NULL) {
                fprintf(erro, "Erro: Caractere inválido encontrado na linha de boleto. Linha: %d\n", line_count);
                fclose(erro);
            }
            continue;
        }

        char cliente_id[6];
        strncpy(cliente_id, linha + 1, 5);
        cliente_id[5] = '\0';

        Cliente *cliente = obter_cliente(&clientes, &num_clientes, cliente_id);
        if (cliente == NULL) {
            houve_erro = 1;
            erro = fopen("ERRO.TXT", "a");
            if (erro != NULL) {
                fprintf(erro, "Erro: Falha ao alocar memória para o cliente. Linha: %d\n", line_count);
                fclose(erro);
            }
            continue;
        }

        total_boletos++;
        float valor = atof(linha + 36) / 100.0;
        total_pago += valor;

        cliente->total_boletos++;
        cliente->total_pago += valor;

        Boleto novo_boleto;
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

    if (houve_erro == 0) {
        remove("ERRO.TXT");

        for (int i = 0; i < num_clientes; ++i) {
            gerar_arquivo_retorno(clientes[i], data_retorno);
        }
    } 

    for (int i = 0; i < num_clientes; ++i) {
        free(clientes[i].boletos);
    }
    free(clientes);

    return 0;
}
