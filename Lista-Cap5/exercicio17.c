/* Questão 17 - Fatorial iterativo e recursivo */
#include <stdio.h>

long fatorialIterativo(int n);
long fatorialRecursivo(int n);

int main(void)
{
    int numero;
    long resultadoIterativo, resultadoRecursivo;

    printf("Digite um inteiro nao negativo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Nao existe fatorial de numero negativo.\n");
        return 1;
    }

    resultadoIterativo = fatorialIterativo(numero);
    resultadoRecursivo = fatorialRecursivo(numero);

    printf("Iterativo: %d! = %ld\n", numero, resultadoIterativo);
    printf("Recursivo: %d! = %ld\n", numero, resultadoRecursivo);

    if (resultadoIterativo == resultadoRecursivo)
        printf("Os dois resultados coincidem.\n");
    else
        printf("Os resultados sao diferentes!\n");

    return 0;
}

/* Versao com laco: multiplica 1 * 2 * ... * n */
long fatorialIterativo(int n)
{
    long resultado = 1;
    int i;

    for (i = 2; i <= n; i++)
        resultado *= i;

    return resultado;
}

/* Versao recursiva: caso base 0! = 1; passo n! = n * (n-1)! */
long fatorialRecursivo(int n)
{
    if (n == 0)
        return 1;
    return (long)n * fatorialRecursivo(n - 1);
}
