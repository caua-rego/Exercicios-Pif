/* Questão 27 - Tarifador de estacionamento progressivo */
#include <stdio.h>

int main(void)
{
    int horas;
    float valor;

    printf("Horas de permanencia: ");
    scanf("%d", &horas);

    if (horas <= 0) {
        printf("Quantidade de horas invalida.\n");
        return 1;
    }

    if (horas <= 2)
        valor = horas * 2.00f;
    else if (horas <= 4)
        valor = 2 * 2.00f + (horas - 2) * 2.50f;
    else
        valor = 2 * 2.00f + 2 * 2.50f + (horas - 4) * 3.00f;

    printf("Tempo total: %d hora(s)\n", horas);
    printf("Valor a pagar: R$ %.2f\n", valor);

    return 0;
}
