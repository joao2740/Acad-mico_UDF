# Cadastro de Equipamentos em C

Atividade da disciplina de Desenvolvimento de Algoritmos e Programação em C, do curso de TI do UDF – Centro Universitário do Distrito Federal.

## Descrição

Este projeto consiste em um sistema simples de cadastro de equipamentos em linguagem C. O programa permite ao usuário inserir dados de equipamentos, armazená-los em um arquivo de texto e listá-los posteriormente na tela.

## Objetivo

Praticar a manipulação de arquivos em linguagem C, além de reforçar conceitos como:

- entrada e saída de dados;
- uso de funções;
- leitura e gravação em arquivos;
- estrutura de um programa em console.

## Funcionalidades

- Cadastrar um novo equipamento;
- Informar código, nome, local/setor e estado;
- Salvar os dados em um arquivo chamado `equipamentos.txt`;
- Listar todos os equipamentos cadastrados;
- Encerrar o programa.

## Conceitos praticados

| Conceito | Descrição |
|---|---|
| `FILE` | Representa um arquivo em C |
| `fopen()` | Abre um arquivo |
| `fgets()` | Lê uma linha do arquivo ou do teclado |
| `fprintf()` | Escreve dados em um arquivo |
| `fclose()` | Fecha o arquivo |
| `strtok()` | Separa strings por delimitadores |
| `"a"` | Abre o arquivo em modo de acréscimo |
| `"r"` | Abre o arquivo em modo de leitura |

## Como executar

### Compilar no terminal

```bash
gcc -Wall -o cadastro cadastro_equipamentos.c
./cadastro
```

### Windows

No Windows, o executável gerado pode ser chamado de `cadastro.exe`.

## Exemplo de uso

```text
===== CADASTRO DE EQUIPAMENTOS =====
1 - Cadastrar equipamento
2 - Listar equipamentos
0 - Sair
Escolha: 1

--- Novo equipamento ---
Codigo: PC001
Nome: Notebook Dell
Local/Setor: Laboratorio 2
Estado (Novo/Bom/Manutencao): Bom
Equipamento salvo com sucesso!
```

## Formato do arquivo

Os dados s��o gravados em `equipamentos.txt` em um formato por linha, com os campos separados por ponto e vírgula:

```text
PC001;Notebook Dell;Laboratorio 2;Bom
PJ002;Projetor Epson;Sala 5;Manutencao
```

## Estrutura do projeto

```text
.
├── cadastro_equipamentos.c
├── equipamentos.txt
└── README.md
```

## Observações

- O programa usa o modo `"a"` para não apagar os registros já gravados.
- O caractere `;` é usado como separador entre os campos, então é recomendado não utilizá-lo nos textos digitados.
- O arquivo `equipamentos.txt` é criado automaticamente quando o primeiro cadastro é realizado.

## Autor

João Victor

Curso de TI – UDF
