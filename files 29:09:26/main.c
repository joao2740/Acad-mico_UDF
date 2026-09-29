/*
 * Atividade: Vetores em C
 * Estudante: [SEU NOME COMPLETO] - RA/Matrícula: [SEU RA]
 *
 * O programa lê 20 números inteiros e calcula:
 *  - soma dos múltiplos de 3
 *  - média dos números pares
 *  - quantidade de positivos e negativos (zero não conta)
 *  - maior e menor valor
 * Ao final, exibe todos os elementos do vetor.
 */

#include <stdio.h>

#define TAMANHO 20

int main(void) {
    int vetor[TAMANHO];   // vetor com 20 posições
    int i;

    int somaMultiplos3 = 0;  // soma dos múltiplos de 3
    int somaPares = 0;       // soma dos pares (para a média)
    int qtdPares = 0;        // quantidade de pares
    int qtdPositivos = 0;
    int qtdNegativos = 0;
    int maior, menor;

    /* ---------- Leitura dos 20 números ---------- */
    printf("=== Leitura de %d numeros inteiros ===\n", TAMANHO);
    for (i = 0; i < TAMANHO; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    /* Inicializa maior e menor com o primeiro elemento */
    maior = vetor[0];
    menor = vetor[0];

    /* ---------- Processamento ---------- */
    for (i = 0; i < TAMANHO; i++) {

        // Múltiplos de 3 (o zero também é múltiplo, mas não altera a soma)
        if (vetor[i] % 3 == 0) {
            somaMultiplos3 += vetor[i];
        }

        // Números pares (o zero é par)
        if (vetor[i] % 2 == 0) {
            somaPares += vetor[i];
            qtdPares++;
        }

        // Positivos e negativos (zero não é contabilizado)
        if (vetor[i] > 0) {
            qtdPositivos++;
        } else if (vetor[i] < 0) {
            qtdNegativos++;
        }

        // Maior e menor valor
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    /* ---------- Resultados ---------- */
    printf("\n=== RESULTADOS ===\n");
    printf("Soma dos multiplos de 3: %d\n", somaMultiplos3);

    // Evita divisão por zero quando não há pares
    if (qtdPares > 0) {
        printf("Media dos numeros pares: %.2f\n", (float)somaPares / qtdPares);
    } else {
        printf("Media dos numeros pares: nao existem numeros pares.\n");
    }

    printf("Quantidade de positivos: %d\n", qtdPositivos);
    printf("Quantidade de negativos: %d\n", qtdNegativos);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    /* ---------- Exibição do vetor ---------- */
    printf("\nElementos do vetor:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
