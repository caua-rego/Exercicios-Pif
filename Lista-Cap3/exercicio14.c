/* Questão 14 - Quadrados de 1 a 100 e soma total */
#include <stdio.h>

int main(void)
{
    int i;
    long soma = 0;

    for (i = 1; i <= 100; i++) {
        printf("%3d -> %5d\n", i, i * i);
        soma += i * i;          /* acumulador */
    }

    printf("\nSoma dos quadrados de 1 a 100 = %ld\n", soma);   /* 338350 */

    return 0;
}
