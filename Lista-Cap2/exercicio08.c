/* Questão 08 - Quadrado e décima parte de um inteiro */
#include <stdio.h>

int main(void)
{
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    printf("a) Quadrado:     %d\n", n * n);
    printf("b) Decima parte: %.2f\n", n / 10.0);  /* 10.0 (double) forca divisao real */

    return 0;
}
