/* Questão 25 - Salário líquido com gratificação de 5% e imposto de 7% */
#include <stdio.h>

int main(void)
{
    double base, gratificacao, imposto, liquido;

    printf("Digite o salario-base: R$ ");
    scanf("%lf", &base);

    gratificacao = base * 0.05;   /* soma 5% da base */
    imposto      = base * 0.07;   /* desconta 7% da base */

    /* liquido = base + 5% da base - 7% da base
               = base * (1 + 0.05 - 0.07)
               = base * 0.98  -> o funcionario recebe 2% a menos que a base */
    liquido = base + gratificacao - imposto;

    printf("Gratificacao (5%%): R$ %.2f\n", gratificacao);
    printf("Imposto (7%%):      R$ %.2f\n", imposto);
    printf("Salario liquido:   R$ %.2f\n", liquido);

    return 0;
}
