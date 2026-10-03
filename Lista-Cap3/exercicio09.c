/* Questão 09 - Soma e média de valores reais até um valor negativo (sentinela) */
#include <stdio.h>

int main(void)
{
    double valor, soma = 0.0;
    int quantidade = 0;

    printf("Digite valores reais positivos (um negativo encerra):\n");

    while (1) {
        printf("Valor: ");
        scanf("%lf", &valor);

        if (valor < 0.0)
            break;              /* sentinela: sai sem incluir o valor nos cálculos */

        soma += valor;
        quantidade++;
    }

    printf("\nQuantidade de valores: %d\n", quantidade);
    printf("Soma total:            %.2f\n", soma);

    if (quantidade > 0)
        printf("Media aritmetica:      %.2f\n", soma / quantidade);
    else
        printf("Media aritmetica:      indefinida (nenhum valor valido)\n");

    return 0;
}
