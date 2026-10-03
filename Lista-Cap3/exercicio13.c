/* Questão 13 - Fatorial de N com long long int */
#include <stdio.h>

int main(void)
{
    int n, i;
    long long int fatorial = 1;   /* 0! = 1 e 1! = 1 já saem corretos */

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: nao existe fatorial de numero negativo.\n");
        return 1;
    }

    for (i = 2; i <= n; i++)      /* para n = 0 ou 1 o laço não executa */
        fatorial *= i;

    printf("%d! = %lld\n", n, fatorial);

    /* long long int (64 bits) guarda com exatidão até 20!; a partir de 21!
       o valor estoura e o resultado deixa de ser confiável. */
    if (n > 20)
        printf("Aviso: acima de 20! o resultado excede a capacidade de long long.\n");

    return 0;
}
