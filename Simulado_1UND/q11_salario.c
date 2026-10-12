/*
 * Questao 11 - Calculo salarial com gratificacao e impostos
 * Tecnico ganha R$ 45,00 por dia trabalhado.
 *   Bruto        = dias * 45,00
 *   Gratificacao = 5% sobre o bruto
 *   IR           = 8% sobre o bruto
 *   Liquido      = bruto + gratificacao - IR
 */
#include <stdio.h>

#define VALOR_DIA     45.00
#define TAXA_GRATIF    0.05
#define TAXA_IR        0.08

int main(void) {
    int dias;
    double bruto, gratificacao, imposto, liquido;

    printf("Informe o numero de dias trabalhados: ");
    if (scanf("%d", &dias) != 1 || dias < 0) {
        printf("Erro: informe um numero inteiro nao negativo.\n");
        return 1;
    }

    bruto        = dias * VALOR_DIA;
    gratificacao = bruto * TAXA_GRATIF;
    imposto      = bruto * TAXA_IR;
    liquido      = bruto + gratificacao - imposto;

    printf("\n=============== HOLERITE ===============\n");
    printf("Dias trabalhados:          %d\n", dias);
    printf("Valor da diaria:           R$ %9.2f\n", VALOR_DIA);
    printf("----------------------------------------\n");
    printf("Salario bruto:             R$ %9.2f\n", bruto);
    printf("(+) Gratificacao (5%%):     R$ %9.2f\n", gratificacao);
    printf("(-) Imposto de renda (8%%): R$ %9.2f\n", imposto);
    printf("----------------------------------------\n");
    printf("Liquido a receber:         R$ %9.2f\n", liquido);
    printf("========================================\n");

    return 0;
}
