/* Questão 14 - Soma dos digitos com recursao */
#include <stdio.h>

int somaDigitos(int n);

int main(void)
{
    int numero;

    printf("Digite um inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("O numero deve ser positivo.\n");
        return 1;
    }

    printf("Soma dos digitos de %d = %d\n", numero, somaDigitos(numero));

    return 0;
}

int somaDigitos(int n)
{
    /* Caso base: numero de um digito so (0 a 9) -> a soma e o proprio numero */
    if (n < 10)
        return n;

    /* Passo recursivo: ultimo digito (n % 10) + soma dos digitos restantes (n / 10) */
    return (n % 10) + somaDigitos(n / 10);
}
