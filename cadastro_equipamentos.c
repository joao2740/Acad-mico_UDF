#include <stdio.h>
#include <string.h>

#define ARQUIVO "equipamentos.txt"
#define TAM 100

/* Remove o '\n' que o fgets deixa no final da string */
void limpar_enter(char *texto) {
    texto[strcspn(texto, "\n")] = '\0';
}

/* 1) Solicita dados ao usuario e salva no arquivo (modo "a") */
void cadastrar_equipamento(void) {
    FILE *arq;
    char codigo[TAM], nome[TAM], local[TAM], estado[TAM];

    printf("\n--- Novo equipamento ---\n");

    printf("Codigo: ");
    fgets(codigo, TAM, stdin);
    limpar_enter(codigo);

    printf("Nome: ");
    fgets(nome, TAM, stdin);
    limpar_enter(nome);

    printf("Local/Setor: ");
    fgets(local, TAM, stdin);
    limpar_enter(local);

    printf("Estado (Novo/Bom/Manutencao): ");
    fgets(estado, TAM, stdin);
    limpar_enter(estado);

    /* "a" acrescenta ao final sem apagar o conteudo existente */
    arq = fopen(ARQUIVO, "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arq, "%s;%s;%s;%s\n", codigo, nome, local, estado);
    fclose(arq);

    printf("Equipamento salvo com sucesso!\n");
}

/* 2) Le o arquivo (modo "r") e mostra os registros */
void listar_equipamentos(void) {
    FILE *arq;
    char linha[TAM * 4];
    int contador = 0;

    arq = fopen(ARQUIVO, "r");
    if (arq == NULL) {
        printf("\nNenhum equipamento cadastrado ainda.\n");
        return;
    }

    printf("\n--- Equipamentos cadastrados ---\n");
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        char *codigo, *nome, *local, *estado;

        limpar_enter(linha);
        codigo = strtok(linha, ";");
        nome   = strtok(NULL, ";");
        local  = strtok(NULL, ";");
        estado = strtok(NULL, ";");

        if (codigo && nome && local && estado) {
            contador++;
            printf("\nRegistro %d\n", contador);
            printf("  Codigo: %s\n", codigo);
            printf("  Nome:   %s\n", nome);
            printf("  Local:  %s\n", local);
            printf("  Estado: %s\n", estado);
        }
    }

    fclose(arq);

    if (contador == 0) {
        printf("Arquivo vazio.\n");
    } else {
        printf("\nTotal: %d equipamento(s).\n", contador);
    }
}

int main(void) {
    int opcao;
    char entrada[TAM];

    do {
        printf("\n===== CADASTRO DE EQUIPAMENTOS =====\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        fgets(entrada, TAM, stdin);
        if (sscanf(entrada, "%d", &opcao) != 1) {
            opcao = -1;
        }

        switch (opcao) {
            case 1: cadastrar_equipamento(); break;
            case 2: listar_equipamentos();   break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
