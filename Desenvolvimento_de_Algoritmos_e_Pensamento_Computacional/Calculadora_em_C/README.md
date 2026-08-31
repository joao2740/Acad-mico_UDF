# Calculadora em C

Resumo
-----
Projeto: Calculadora em C  
Pasta do projeto: Desenvolvimento_de_Algoritmos_e_Pensamento_Computacional/Calculadora_em_C

Descrição
---------
Esta é uma calculadora de linha de comando implementada em linguagem C. O objetivo é demonstrar o uso de variáveis, entrada/saída, estruturas condicionais, estruturas de repetição, modularização por funções e utilização da biblioteca `math.h`.

Objetivo da calculadora
-----------------------
Fornecer um conjunto de operações matemáticas (mínimo de 20 funções) acessíveis via um menu, com tratamento básico de erro e possibilidade de executar múltiplas operações até o usuário encerrar o programa.

Funcionalidades implementadas
-----------------------------
- Menu interativo que permite escolher entre 20 operações distintas e sair (opção 0).
- Tratamento de entradas inválidas (quando possível) e verificação de domínio para operações que exigem argumentos específicos (ex.: divisão por zero, log de número não positivo, raiz quadrada de número negativo).
- Execução repetida até que o usuário opte por encerrar.

Lista das 20 funções desenvolvidas
---------------------------------
1. somar(a, b) — soma de dois números  
2. subtrair(a, b) — subtração  
3. multiplicar(a, b) — multiplicação  
4. dividir(a, b, resultado) — divisão com verificação de divisor zero  
5. potencia(base, expoente) — potenciação usando pow()  
6. raiz_quadrada(x, resultado) — raiz quadrada com verificação de domínio  
7. raiz_cubica(x) — raiz cúbica usando cbrt()  
8. seno(graus) — seno, entrada em graus (converte para rad)  
9. cosseno(graus) — cosseno, entrada em graus  
10. tangente(graus, resultado) — tangente com verificação de cos ~= 0  
11. logaritmo_natural(x, resultado) — ln(x) com verificação x > 0  
12. logaritmo_base10(x, resultado) — log10(x) com verificação x > 0  
13. valor_absoluto(x) — valor absoluto usando fabs()  
14. porcentagem(total, percentual) — calcula percentual de um total  
15. media_aritmetica_n(values[], n) — média aritmética de N valores (uso de repetição)  
16. graus_para_radianos(graus) — conversão graus -> radianos  
17. radianos_para_graus(rad) — conversão radianos -> graus  
18. area_circulo(raio) — área do círculo (PI * r^2)  
19. area_retangulo(base, altura) — área do retângulo  
20. hipotenusa(a, b) — cálculo via teorema de Pitágoras

Bibliotecas utilizadas
---------------------
- stdio.h — entrada/saída (scanf/printf)  
- stdlib.h — alocação dinâmica (malloc/free) e utilitários  
- math.h — funções matemáticas (pow, sqrt, cbrt, sin, cos, tan, log, log10, fabs, acos)

Organização do código
---------------------
- `calculadora.c` — arquivo único contendo todas as funções, protótipos, a função `main()` com o menu e utilitários para limpar buffer/esperar Enter.
- O programa é modularizado por funções, cada operação está implementada preferencialmente em sua própria função.

Instruções para compilação e execução
------------------------------------
1. Compilar (necessário link com a biblioteca matemática):
   gcc calculadora.c -o calculadora -lm

2. Executar:
   ./calculadora

Exemplos de uso
---------------
- Soma:
  1) Escolher opção 1  
  2) Digitar: 3 4  
  3) Resultado: 7.00000000

- Média de N valores:
  1) Escolher opção 15  
  2) Digitar, por exemplo, 3 (quantidade)  
  3) Informar os 3 valores um a um

Conceitos de programação aplicados
---------------------------------
- Funções: cada operação matemárica está encapsulada em uma função com protótipo e implementação separados.
- Estruturas condicionais: `switch...case` no menu e validações com `if` para tratar domínios inválidos.
- Estruturas de repetição: `do...while` para manter o menu ativo; `for` para leitura de N valores na média.
- Entrada/saída: `scanf()` e `printf()` são usados para interação com usuário.
- Biblioteca math.h: utilizada para operações como `pow`, `sqrt`, `sin`, `cos`, `tan`, `log`, `log10`, `cbrt`, `fabs`.

Tratamento de erros
-------------------
- Divisão por zero: detectada e reportada ao usuário.
- Raiz quadrada de número negativo: detectada e reportada.
- Logaritmo de número não positivo: detectado e reportado.
- Tangente quando cosseno muito próximo de zero: detectado e reportado.
- Verificação básica de entradas com scanf (quando possível).

Entrega e organização no GitHub
------------------------------
O projeto deve ser colocado na pasta:
Desenvolvimento_de_Algoritmos_e_Pensamento_Computacional/Calculadora_em_C/

Arquivos mínimos:
- calculadora.c
- README.md

Identificacao do estudante
--------------------------
(Coloque aqui seu nome completo e matrícula ou identificação acadêmica)

Observações finais
------------------
Se quiser, eu posso:
- Ajustar o estilo do menu/textos (ex.: português formal/informal).  
- Adicionar validações mais robustas de entrada (leitura por linha e parsing).  
- Criar um pull request da branch "calculadora-em-c" para a branch padrão do repositório. Para isso preciso da sua confirmação e do nome (autoria) que deve constar no README.
