/* Questão 20 - Numero primo */
#include <stdio.h>

int ehPrimo(int n);

int main(void)
{
    int numero, i;

    printf("Digite um inteiro: ");
    scanf("%d", &numero);

    if (ehPrimo(numero))
        printf("%d e primo.\n", numero);
    else
        printf("%d nao e primo.\n", numero);

    printf("\nPrimos de 1 a 50:\n");
    for (i = 1; i <= 50; i++)
        if (ehPrimo(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}

/* Retorna 1 se n for primo (so divisivel por 1 e por ele mesmo) e 0 caso contrario */
int ehPrimo(int n)
{
    int divisor;

    if (n < 2)
        return 0;

    for (divisor = 2; divisor * divisor <= n; divisor++)
        if (n % divisor == 0)
            return 0;

    return 1;
}
