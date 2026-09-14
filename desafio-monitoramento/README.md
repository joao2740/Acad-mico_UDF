# Sistema Inteligente de Monitoramento Industrial

## 1. Identificação

- **Nome do aluno:** João Vitor Lino Teixeira 
- **Disciplina:** Programação em C
- **Professora:** Profa. Karla Sartin
- **Título do projeto:** Sistema Inteligente de Monitoramento Industrial

## 2. Objetivo

O programa resolve o problema de **monitorar a temperatura de uma máquina industrial** a partir das leituras de um sensor, identificando automaticamente situações de risco. Ele valida os dados de entrada, calcula estatísticas (média, maior e menor temperatura), conta quantas leituras ficaram acima do limite de segurança e interrompe o monitoramento sozinho quando detecta 3 leituras consecutivas acima desse limite — simulando um mecanismo de segurança automático.

## 3. Funcionamento do programa

- **Definição do limite de temperatura:** o limite é informado pelo usuário no início da execução. O programa só aceita valores numéricos positivos maiores que zero; qualquer outro valor é rejeitado e a leitura é solicitada novamente.
- **Realização das leituras:** as temperaturas são lidas uma a uma, simulando os dados enviados por um sensor. A cada leitura válida, o programa atualiza soma, maior valor, menor valor e total de leituras.
- **Tratamento de valores inválidos:** entradas que não são números (ex.: letras) são rejeitadas com mensagem de erro e o buffer de entrada é limpo antes de solicitar o valor novamente. Também são rejeitados valores fora de uma faixa fisicamente plausível (-50 °C a 200 °C).
- **Identificação de temperaturas acima do limite:** toda leitura maior que o limite configurado gera um alerta na tela e incrementa o contador de leituras acima do limite.
- **Contagem de temperaturas consecutivas:** existe um contador específico de leituras **consecutivas** acima do limite. Ele é incrementado a cada leitura acima do limite e **reiniciado (zerado)** assim que uma leitura dentro do limite é recebida — garantindo que só contem sequências ininterruptas.
- **Condição de encerramento:** o monitoramento é encerrado automaticamente quando o contador de consecutivas atinge 3. O usuário também pode encerrar manualmente a qualquer momento digitando o valor sentinela `-999`.
- **Relatório final:** ao final (por encerramento automático ou manual), o programa exibe limite configurado, total de leituras, média, maior e menor temperatura, quantidade e percentual de leituras acima do limite, e se houve encerramento automático.

## 4. Estruturas de repetição utilizadas

O programa utiliza **while** e **do...while** em conjunto, cada um no contexto mais adequado:

- **do...while** é usado nas três validações de entrada (limite de temperatura e cada leitura de temperatura). Isso porque, para validar um dado, primeiro é preciso lê-lo — ou seja, o corpo do laço (ler o valor) precisa ser executado **pelo menos uma vez** antes de a condição (o valor é válido?) poder ser avaliada. Um `while` tradicional exigiria uma leitura "fantasma" antes do laço para inicializar a condição, o que tornaria o código redundante.
- **while** é usado no laço principal do monitoramento, que controla a sequência de leituras do sensor. Aqui não se sabe, a priori, quantas leituras serão feitas — o laço deve continuar enquanto nenhuma condição de parada (encerramento manual ou 3 consecutivas acima do limite) tiver ocorrido. Como é possível que a condição de parada já seja satisfeita a qualquer momento (inclusive nunca, teoricamente), faz mais sentido testar a condição **antes** de executar cada nova iteração, característica do `while`.

## 5. Como executar

Compile e execute com:

```bash
gcc monitoramento.c -o monitoramento
./monitoramento
```

Em seguida, informe o limite de temperatura e vá digitando as temperaturas lidas, uma por linha. Digite `-999` para encerrar manualmente a qualquer momento.

## 6. Testes realizados

As evidências completas (saída de terminal) estão na pasta `evidencias/`.

### Teste 1 — Validação de entradas inválidas
Arquivo: `evidencias/teste01_entradas_invalidas.txt`

Foram informados um limite não numérico (`abc`), uma temperatura não numérica (`abc`) e uma temperatura fora da faixa aceitável (`999`). Em todos os casos o programa exibiu a mensagem de erro correspondente e solicitou o valor novamente, sem travar ou aceitar o dado inválido. As leituras válidas (25 e 30, ambas acima do limite de 10) foram contabilizadas corretamente antes do encerramento manual.

### Teste 2 — Temperaturas acima do limite, porém não consecutivas
Arquivo: `evidencias/teste02_acima_nao_consecutivas.txt`

Com limite de 30 °C e a sequência de temperaturas 25, 35, 20, 40, 15, o programa identificou corretamente as duas leituras acima do limite (35 e 40), mas como elas não ocorreram em sequência (houve leituras dentro do limite entre elas), o contador de consecutivas foi reiniciado a cada vez e **o encerramento automático não ocorreu**, confirmando o funcionamento correto do reinício do contador.

### Teste 3 — Três temperaturas consecutivas acima do limite
Arquivo: `evidencias/teste03_tres_consecutivas.txt`

Com limite de 30 °C e a sequência 25, 35, 36, 37, as três últimas leituras ficaram consecutivamente acima do limite. O programa detectou corretamente essa sequência e **encerrou o monitoramento automaticamente** após a terceira leitura consecutiva, exibindo o relatório final com `Encerramento automatico...: SIM`.

## Questão final de reflexão

**Por que você escolheu `while`, `do...while` ou uma combinação das duas estruturas? Em qual parte do algoritmo a diferença entre testar a condição antes ou depois da execução foi importante para sua solução?**

O programa utiliza while e do...while em conjunto, cada um no contexto mais adequado:
do...while é usado nas três validações de entrada (limite de temperatura e cada leitura de temperatura). Isso porque, para validar um dado, primeiro é preciso lê-lo — ou seja, o corpo do laço (ler o valor) precisa ser executado pelo menos uma vez antes de a condição (o valor é válido?) poder ser avaliada. Um while tradicional exigiria uma leitura "fantasma" antes do laço para inicializar a condição, o que tornaria o código redundante.
while é usado no laço principal do monitoramento, que controla a sequência de leituras do sensor. Aqui não se sabe, a priori, quantas leituras serão feitas — o laço deve continuar enquanto nenhuma condição de parada (encerramento manual ou 3 consecutivas acima do limite) tiver ocorrido. Como é possível que a condição de parada já seja satisfeita a qualquer momento (inclusive nunca, teoricamente), faz mais sentido testar a condição antes de executar cada nova iteração, característica do while.
