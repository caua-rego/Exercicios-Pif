/* Questão 07 - Numeros primos com funcao (Cap. 5) */
#include <stdio.h>

int ehPrimo(int n);

int main(void)
{
    int limite, i;

    printf("Digite N: ");
    scanf("%d", &limite);

    printf("Primos de 1 ate %d:\n", limite);
    for (i = 1; i <= limite; i++)
        if (ehPrimo(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}

/* Devolve 1 se n for primo e 0 caso contrario */
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
