# Atividade – Vetores em C

## Identificação do estudante
- **Nome:** [SEU NOME COMPLETO]
- **RA/Matrícula:** [SEU RA]
- **Curso/Disciplina:** [CURSO] / [DISCIPLINA]
- **Professor(a):** [NOME]

## Objetivo da atividade
Desenvolver um programa em C que aplique os conceitos de arrays (vetores), estruturas de repetição, estruturas condicionais, entrada de dados e operações matemáticas. O programa lê 20 números inteiros e calcula estatísticas sobre eles.

## Lógica utilizada
1. Um vetor `int vetor[20]` recebe os números digitados, usando um laço `for`.
2. `maior` e `menor` começam com o primeiro elemento do vetor.
3. Um segundo laço `for` percorre o vetor e, para cada elemento, com `if`:
   - se `vetor[i] % 3 == 0`, soma em `somaMultiplos3`;
   - se `vetor[i] % 2 == 0`, soma em `somaPares` e incrementa `qtdPares`;
   - se `> 0`, incrementa positivos; se `< 0`, incrementa negativos (o **zero não é contado** em nenhum);
   - atualiza `maior` e `menor` quando necessário.
4. A média dos pares é `somaPares / qtdPares`. Se `qtdPares == 0`, o programa informa que não há pares, **evitando divisão por zero**.
5. Um último laço `for` exibe todos os elementos do vetor.

## Como compilar e executar

Requisito: compilador GCC.

```bash
gcc main.c -o programa
./programa          # Linux/macOS
programa.exe        # Windows
```

## Exemplo de entrada e saída

**Entrada** (20 números, um por vez):
```
3 -6 7 0 12 -5 8 9 -2 15 4 -1 10 21 -14 5 6 -9 11 2
```

**Saída:**
```
=== RESULTADOS ===
Soma dos multiplos de 3: 51
Media dos numeros pares: 2.00
Quantidade de positivos: 13
Quantidade de negativos: 6
Maior valor: 21
Menor valor: -14

Elementos do vetor:
[0] = 3
[1] = -6
[2] = 7
[3] = 0
[4] = 12
[5] = -5
[6] = 8
[7] = 9
[8] = -2
[9] = 15
[10] = 4
[11] = -1
[12] = 10
[13] = 21
[14] = -14
[15] = 5
[16] = 6
[17] = -9
[18] = 11
[19] = 2
```

## Captura de tela da execução

![Execução do programa](captura.png)
