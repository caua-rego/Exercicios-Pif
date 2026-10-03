/* Questão 28 - Salário anual bruto e imposto progressivo com o operador ? : */
#include <stdio.h>

#define HORA_NORMAL   10.00
#define HORA_EXTRA    15.00     /* 10,00 + 50% */
#define ISENCAO    12000.00
#define ALIQUOTA       0.10     /* 10% sobre o que exceder a isenção */

int main(void)
{
    double horas_normais, horas_extras, bruto, imposto, liquido;

    printf("Horas normais trabalhadas no ano: ");
    scanf("%lf", &horas_normais);
    printf("Horas extras trabalhadas no ano: ");
    scanf("%lf", &horas_extras);

    bruto = horas_normais * HORA_NORMAL + horas_extras * HORA_EXTRA;

    /* Operador condicional no lugar de if: se o bruto passa da faixa de
       isenção, tributa só o excedente; caso contrário o imposto é zero. */
    imposto = bruto > ISENCAO ? (bruto - ISENCAO) * ALIQUOTA : 0.0;
    liquido = bruto - imposto;

    printf("a) Salario anual bruto: R$ %.2f\n", bruto);
    printf("b) Imposto a pagar:     R$ %.2f\n", imposto);
    printf("   Salario liquido:     R$ %.2f\n", liquido);

    return 0;
}
