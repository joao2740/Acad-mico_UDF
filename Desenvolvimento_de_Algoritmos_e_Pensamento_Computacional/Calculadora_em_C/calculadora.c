/*
  calculadora.c
  Calculadora em C com 20 operacoes minimas exigidas no enunciado.
  Requisitos: stdio.h, math.h, funcao int main(), menu, scanf/printf,
  switch...case, laco de repeticao, tratamento basico de erros.

  Para compilar:
    gcc calculadora.c -o calculadora -lm

  Autor: (Coloque seu nome no README)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-12
#define PI acos(-1.0)

/* Prototipos das funcoes (cada operacao em funcao propria) */
double somar(double a, double b);
double subtrair(double a, double b);
double multiplicar(double a, double b);
int dividir(double a, double b, double *resultado); /* retorna 0 em erro (divisao por zero) */
double potencia(double base, double expoente);
int raiz_quadrada(double x, double *resultado); /* erro se x < 0 */
double raiz_cubica(double x);
double seno(double graus);
double cosseno(double graus);
int tangente(double graus, double *resultado); /* verifica cos ~= 0 */
int logaritmo_natural(double x, double *resultado); /* erro se x <= 0 */
int logaritmo_base10(double x, double *resultado); /* erro se x <= 0 */
double valor_absoluto(double x);
double porcentagem(double total, double percentual);
double media_aritmetica_n(double values[], int n);
double graus_para_radianos(double graus);
double radianos_para_graus(double rad);
double area_circulo(double raio);
double area_retangulo(double base, double altura);
double hipotenusa(double a, double b);

/* Utilitarios */
void limpar_buffer();
void esperar_enter();

int main() {
    int opcao;
    printf("Calculadora em C - Menu de Operacoes\n");
    do {
        printf("\n--- MENU ---\n");
        printf(" 1  - Soma\n");
        printf(" 2  - Subtracao\n");
        printf(" 3  - Multiplicacao\n");
        printf(" 4  - Divisao\n");
        printf(" 5  - Potenciacao (base^expoente)\n");
        printf(" 6  - Raiz quadrada\n");
        printf(" 7  - Raiz cubica\n");
        printf(" 8  - Seno (graus)\n");
        printf(" 9  - Cosseno (graus)\n");
        printf("10  - Tangente (graus)\n");
        printf("11  - Logaritmo natural (ln)\n");
        printf("12  - Logaritmo base 10 (log10)\n");
        printf("13  - Valor absoluto\n");
        printf("14  - Calculo de porcentagem (parte de um total)\n");
        printf("15  - Media aritmetica (N valores)\n");
        printf("16  - Conversao graus -> radianos\n");
        printf("17  - Conversao radianos -> graus\n");
        printf("18  - Area do circulo\n");
        printf("19  - Area do retangulo\n");
        printf("20  - Calculo da hipotenusa (teorema de Pitagoras)\n");
        printf(" 0  - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor digite um numero inteiro.\n");
            limpar_buffer();
            continue;
        }

        switch (opcao) {
            case 0:
                printf("Encerrando a calculadora. Ate mais!\n");
                break;
            case 1: {
                double a,b; printf("Digite dois numeros (a b): "); if (scanf("%lf %lf",&a,&b)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Resultado: %.8f\n", somar(a,b)); break;
            }
            case 2: {
                double a,b; printf("Digite dois numeros (a b): "); if (scanf("%lf %lf",&a,&b)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Resultado: %.8f\n", subtrair(a,b)); break;
            }
            case 3: {
                double a,b; printf("Digite dois numeros (a b): "); if (scanf("%lf %lf",&a,&b)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Resultado: %.8f\n", multiplicar(a,b)); break;
            }
            case 4: {
                double a,b, res; printf("Digite dividendo e divisor (a b): "); if (scanf("%lf %lf",&a,&b)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (dividir(a,b,&res)==0) { printf("Erro: divisao por zero nao permitida.\n"); }
                else printf("Resultado: %.8f\n", res);
                break;
            }
            case 5: {
                double base, expo; printf("Digite base e expoente: "); if (scanf("%lf %lf",&base,&expo)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Resultado: %.8f\n", potencia(base, expo)); break;
            }
            case 6: {
                double x, res; printf("Digite o numero (x): "); if (scanf("%lf",&x)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (raiz_quadrada(x, &res)==0) { printf("Erro: raiz quadrada de numero negativo.\n"); }
                else printf("Resultado: %.8f\n", res);
                break;
            }
            case 7: {
                double x; printf("Digite o numero (x): "); if (scanf("%lf",&x)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Resultado: %.8f\n", raiz_cubica(x)); break;
            }
            case 8: {
                double g; printf("Digite angulo em graus: "); if (scanf("%lf",&g)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Seno(%.8f graus) = %.8f\n", g, seno(g)); break;
            }
            case 9: {
                double g; printf("Digite angulo em graus: "); if (scanf("%lf",&g)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("Cosseno(%.8f graus) = %.8f\n", g, cosseno(g)); break;
            }
            case 10: {
                double g, res; printf("Digite angulo em graus: "); if (scanf("%lf",&g)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (tangente(g,&res)==0) { printf("Erro: tangente indefinida (coseno muito proximo de zero).\n"); }
                else printf("Tangente(%.8f graus) = %.8f\n", g, res);
                break;
            }
            case 11: {
                double x, res; printf("Digite x para ln(x): "); if (scanf("%lf",&x)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (logaritmo_natural(x,&res)==0) { printf("Erro: ln definido apenas para x > 0.\n"); }
                else printf("ln(%.8f) = %.8f\n", x, res);
                break;
            }
            case 12: {
                double x, res; printf("Digite x para log10(x): "); if (scanf("%lf",&x)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (logaritmo_base10(x,&res)==0) { printf("Erro: log10 definido apenas para x > 0.\n"); }
                else printf("log10(%.8f) = %.8f\n", x, res);
                break;
            }
            case 13: {
                double x; printf("Digite numero: "); if (scanf("%lf",&x)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("|%.8f| = %.8f\n", x, valor_absoluto(x)); break;
            }
            case 14: {
                double total, perc; printf("Digite total e percentual (total perc): "); if (scanf("%lf %lf",&total,&perc)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("%.8f%% de %.8f = %.8f\n", perc, total, porcentagem(total, perc)); break;
            }
            case 15: {
                int n; printf("Quantos valores? "); if (scanf("%d",&n)!=1 || n<=0) { printf("Numero de valores invalido.\n"); limpar_buffer(); break; }
                double *vals = (double*) malloc(sizeof(double)*n);
                if (!vals) { printf("Erro de memoria.\n"); break; }
                for (int i=0;i<n;i++) {
                    printf("Valor %d: ", i+1);
                    if (scanf("%lf", &vals[i])!=1) { printf("Entrada invalida.\n"); limpar_buffer(); free(vals); vals=NULL; break; }
                }
                if (vals) {
                    double media = media_aritmetica_n(vals, n);
                    printf("Media aritmetica = %.8f\n", media);
                    free(vals);
                }
                break;
            }
            case 16: {
                double g; printf("Digite graus: "); if (scanf("%lf",&g)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("%.8f graus = %.8f radianos\n", g, graus_para_radianos(g)); break;
            }
            case 17: {
                double r; printf("Digite radianos: "); if (scanf("%lf",&r)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                printf("%.8f rad = %.8f graus\n", r, radianos_para_graus(r)); break;
            }
            case 18: {
                double raio; printf("Digite o raio do circulo: "); if (scanf("%lf",&raio)!=1) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (raio < 0) { printf("Erro: raio nao pode ser negativo.\n"); break; }
                printf("Area do circulo = %.8f\n", area_circulo(raio)); break;
            }
            case 19: {
                double b,h; printf("Digite base e altura: "); if (scanf("%lf %lf",&b,&h)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (b < 0 || h < 0) { printf("Erro: dimensoes nao podem ser negativas.\n"); break; }
                printf("Area do retangulo = %.8f\n", area_retangulo(b,h)); break;
            }
            case 20: {
                double a,b; printf("Digite catetos a e b: "); if (scanf("%lf %lf",&a,&b)!=2) { printf("Entrada invalida.\n"); limpar_buffer(); break; }
                if (a < 0 || b < 0) { printf("Erro: catetos nao podem ser negativos.\n"); break; }
                printf("Hipotenusa = %.8f\n", hipotenusa(a,b)); break;
            }
            default:
                printf("Opcao invalida. Tente novamente.\n");
        } /* fim switch */

        if (opcao != 0) {
            esperar_enter();
        }

    } while (opcao != 0);

    return 0;
}

/* Implementacoes */

double somar(double a, double b) { return a + b; }
double subtrair(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
int dividir(double a, double b, double *resultado) {
    if (fabs(b) < EPS) return 0;
    *resultado = a / b;
    return 1;
}
double potencia(double base, double expoente) { return pow(base, expoente); }
int raiz_quadrada(double x, double *resultado) {
    if (x < 0.0) return 0;
    *resultado = sqrt(x);
    return 1;
}
double raiz_cubica(double x) { return cbrt(x); }
double seno(double graus) { return sin(graus * PI / 180.0); }
double cosseno(double graus) { return cos(graus * PI / 180.0); }
int tangente(double graus, double *resultado) {
    double rad = graus * PI / 180.0;
    double c = cos(rad);
    if (fabs(c) < EPS) return 0;
    *resultado = tan(rad);
    return 1;
}
int logaritmo_natural(double x, double *resultado) {
    if (x <= 0.0) return 0;
    *resultado = log(x);
    return 1;
}
int logaritmo_base10(double x, double *resultado) {
    if (x <= 0.0) return 0;
    *resultado = log10(x);
    return 1;
}
double valor_absoluto(double x) { return fabs(x); }
double porcentagem(double total, double percentual) { return total * (percentual / 100.0); }
double media_aritmetica_n(double values[], int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) s += values[i];
    return s / n;
}
double graus_para_radianos(double graus) { return graus * PI / 180.0; }
double radianos_para_graus(double rad) { return rad * 180.0 / PI; }
double area_circulo(double raio) { return PI * raio * raio; }
double area_retangulo(double base, double altura) { return base * altura; }
double hipotenusa(double a, double b) { return sqrt(a*a + b*b); }

/* Funcoes utilitarias para interacao com usuario */
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* descartar */ }
}
void esperar_enter() {
    printf("\nPressione Enter para continuar...");
    limpar_buffer();
    /* ler uma vez mais caso buffer vazio */
    getchar();
}
