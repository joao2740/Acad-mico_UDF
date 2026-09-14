/* ============================================================
 * Sistema Inteligente de Monitoramento Industrial
 * Disciplina: Programação em C
 * Professora: Karla Sartin
 *
 * Objetivo: monitorar a temperatura de uma máquina, validando
 * entradas, calculando estatísticas e encerrando automaticamente
 * o monitoramento caso sejam detectadas 3 leituras consecutivas
 * acima do limite de segurança configurado.
 *
 * Estruturas de repetição utilizadas: while e do...while
 * (ver justificativa detalhada no README.md)
 * ============================================================ */

#include <stdio.h>

int main(void) {

    /* --------- Constantes de configuração --------- */
    const float SENTINELA        = -999.0f; /* valor usado para encerrar manualmente */
    const float TEMP_MIN_VALIDA  = -50.0f;  /* faixa mínima aceitável de leitura */
    const float TEMP_MAX_VALIDA  = 200.0f;  /* faixa máxima aceitável de leitura */

    float limite;          /* limite de temperatura definido pelo usuário */
    int   entradaValida;   /* flag usada para controlar a validação do limite */

    printf("=================================================\n");
    printf(" SISTEMA INTELIGENTE DE MONITORAMENTO INDUSTRIAL\n");
    printf("=================================================\n\n");

    /* ---------------------------------------------------------
     * 1) Solicitar e validar o limite de temperatura.
     * Usamos do...while porque a leitura precisa ocorrer PELO
     * MENOS UMA VEZ antes de podermos avaliar se o valor é válido
     * (o teste de validade só faz sentido depois de já existir
     * um valor lido).
     * --------------------------------------------------------- */
    do {
        entradaValida = 1;
        printf("Informe o limite de temperatura de seguranca (C): ");

        if (scanf("%f", &limite) != 1) {
            printf(">> Entrada invalida! Digite um valor numerico.\n\n");
            entradaValida = 0;
            while (getchar() != '\n') {
                /* limpa o buffer de entrada após leitura inválida */
            }
        } else if (limite <= 0) {
            printf(">> O limite deve ser um numero positivo maior que zero.\n\n");
            entradaValida = 0;
        }

    } while (!entradaValida);

    printf("\nLimite definido: %.2f C\n", limite);
    printf("Digite as temperaturas lidas pelo sensor, uma por vez.\n");
    printf("Digite %.0f a qualquer momento para encerrar manualmente.\n\n", SENTINELA);

    /* --------- Variáveis de controle do monitoramento --------- */
    float temperatura;
    float soma               = 0.0f;
    float maior              = -9999.0f;
    float menor              = 9999.0f;
    int   totalLeituras      = 0;
    int   totalAcimaLimite   = 0;
    int   consecutivasAcima  = 0;
    int   encerramentoAuto   = 0;
    int   leituraOk;
    int   continuarMonitorando = 1;

    /* ---------------------------------------------------------
     * 2) Laço principal de leitura do sensor.
     * Usamos while porque não sabemos, a priori, quantas
     * leituras serão feitas: o laço deve continuar enquanto não
     * houver pedido de encerramento manual nem 3 leituras
     * consecutivas acima do limite.
     * --------------------------------------------------------- */
    while (continuarMonitorando) {

        /* -----------------------------------------------------
         * 2.1) Validação de cada leitura individual.
         * Novamente do...while: a leitura precisa acontecer
         * antes de sabermos se ela é válida.
         * ----------------------------------------------------- */
        do {
            leituraOk = 1;
            printf("Temperatura #%d: ", totalLeituras + 1);

            if (scanf("%f", &temperatura) != 1) {
                printf(">> Entrada invalida! Digite um valor numerico.\n");
                leituraOk = 0;
                while (getchar() != '\n') {
                    /* limpa o buffer de entrada após leitura inválida */
                }
            } else if (temperatura != SENTINELA &&
                       (temperatura < TEMP_MIN_VALIDA || temperatura > TEMP_MAX_VALIDA)) {
                printf(">> Valor fora da faixa aceitavel (%.0f a %.0f C). Tente novamente.\n",
                       TEMP_MIN_VALIDA, TEMP_MAX_VALIDA);
                leituraOk = 0;
            }

        } while (!leituraOk);

        /* Encerramento manual */
        if (temperatura == SENTINELA) {
            printf("\nEncerramento manual solicitado pelo usuario.\n");
            break;
        }

        /* Atualização das estatísticas */
        totalLeituras++;
        soma += temperatura;

        if (temperatura > maior) {
            maior = temperatura;
        }
        if (temperatura < menor) {
            menor = temperatura;
        }

        /* Controle de temperaturas acima do limite */
        if (temperatura > limite) {
            totalAcimaLimite++;
            consecutivasAcima++;
            printf(" -> ALERTA: temperatura acima do limite! (%d consecutiva(s))\n",
                   consecutivasAcima);
        } else {
            consecutivasAcima = 0; /* reinicia o contador de consecutivas */
        }

        /* Condição de segurança: 3 consecutivas acima do limite */
        if (consecutivasAcima >= 3) {
            encerramentoAuto = 1;
            printf("\n>>> 3 temperaturas consecutivas acima do limite detectadas!\n");
            printf(">>> Encerrando monitoramento automaticamente por seguranca.\n");
            break;
        }
    }

    /* ---------------------------------------------------------
     * 3) Relatório final
     * --------------------------------------------------------- */
    printf("\n================== RELATORIO FINAL ==================\n");

    if (totalLeituras == 0) {
        printf("Nenhuma leitura valida foi registrada.\n");
    } else {
        float media = soma / totalLeituras;
        float percentualAcima = (totalAcimaLimite * 100.0f) / totalLeituras;

        printf("Limite configurado........: %.2f C\n", limite);
        printf("Total de leituras.........: %d\n", totalLeituras);
        printf("Temperatura media.........: %.2f C\n", media);
        printf("Maior temperatura.........: %.2f C\n", maior);
        printf("Menor temperatura.........: %.2f C\n", menor);
        printf("Leituras acima do limite..: %d (%.1f%%)\n", totalAcimaLimite, percentualAcima);
        printf("Encerramento automatico...: %s\n", encerramentoAuto ? "SIM" : "NAO");
    }

    printf("======================================================\n");

    return 0;
}
