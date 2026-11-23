/* Questão 11 - Ordenacao crescente de tres valores (sem vetores) */
#include <stdio.h>

int main(void)
{
    int a, b, c, temp;

    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    /* trocas sucessivas: ao final a <= b <= c */
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (b > c) { temp = b; b = c; c = temp; }

    printf("Ordem crescente: %d %d %d\n", a, b, c);

    return 0;
}
