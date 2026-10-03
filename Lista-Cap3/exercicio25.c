/* Questão 25 - Teste de primalidade contando divisores */
#include <stdio.h>

int main(void)
{
    int n, i, divisores = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Erro: o numero deve ser positivo.\n");
        return 1;
    }

    for (i = 1; i <= n; i++)
        if (n % i == 0)
            divisores++;

    printf("%d possui %d divisor(es).\n", n, divisores);

    /* Primo: maior que 1 e com exatamente dois divisores (1 e ele mesmo).
       O número 1 tem só um divisor, logo não é primo. */
    if (n > 1 && divisores == 2)
        printf("%d e um numero PRIMO.\n", n);
    else
        printf("%d NAO e um numero primo.\n", n);

    return 0;
}
