/* Questão 28 - Média aritmética de três inteiros como double */
#include <stdio.h>

int main(void)
{
    int a, b, c;
    double media;

    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    media = (a + b + c) / 3.0; /* 3.0 força divisão real (sem truncar) */

    printf("Media: %.2f\n", media);

    return 0;
}
