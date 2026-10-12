/*
 * Questao 13 - Fatorial com tratamento do zero e tipo long long int
 *   0! = 1, 1! = 1, N! = 1 * 2 * ... * N
 *
 * Observacao: mesmo com long long int (64 bits), o maior fatorial que cabe
 * e 20! = 2432902008176640000. A partir de 21! ocorre estouro (overflow),
 * por isso a entrada tambem e limitada a 20.
 */
#include <stdio.h>

int main(void) {
    int n, i;
    long long int fatorial = 1;   /* comeca em 1: elemento neutro da multiplicacao */

    printf("Informe um numero inteiro N: ");
    if (scanf("%d", &n) != 1) {
        printf("Erro: valor invalido.\n");
        return 1;
    }

    if (n < 0) {
        printf("Erro: nao existe fatorial de numero negativo.\n");
        return 1;
    }

    if (n > 20) {
        printf("Erro: %d! ultrapassa o limite de long long int (maximo 20!).\n", n);
        return 1;
    }

    /* Para n = 0 ou n = 1 o laco nao executa e o resultado fica 1. */
    for (i = 2; i <= n; i++) {
        fatorial *= i;
    }

    printf("%d! = %lld\n", n, fatorial);

    return 0;
}
