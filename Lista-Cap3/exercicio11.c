/* Questão 11 - Intervalo fechado entre A e B, crescente ou decrescente */
#include <stdio.h>

int main(void)
{
    int a, b, i;

    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    if (a <= b) {
        printf("Ordem crescente:\n");
        for (i = a; i <= b; i++)
            printf("%d ", i);
    } else {
        printf("Ordem decrescente:\n");
        for (i = a; i >= b; i--)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
