/* Questão 19 - Salário bruto e líquido de um encanador */
#include <stdio.h>

#define DIARIA   30.00
#define IMPOSTO  0.08    /* 8% retido na fonte */

int main(void)
{
    int dias;
    double bruto, liquido;

    printf("Numero de dias trabalhados: ");
    scanf("%d", &dias);

    bruto   = dias * DIARIA;
    liquido = bruto - bruto * IMPOSTO;   /* equivale a bruto * 0.92 */

    printf("Salario bruto:   R$ %.2f\n", bruto);
    printf("Imposto (8%%):    R$ %.2f\n", bruto * IMPOSTO);
    printf("Salario liquido: R$ %.2f\n", liquido);

    return 0;
}
