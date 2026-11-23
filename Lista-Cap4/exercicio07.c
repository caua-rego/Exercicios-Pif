/* Questão 07 - Raiz quadrada ou quadrado de um numero real
 * Compilar com: gcc -Wall -o exercicio07 exercicio07.c -lm */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double numero;

    printf("Digite um numero real: ");
    scanf("%lf", &numero);

    if (numero >= 0)
        printf("Raiz quadrada de %.2f = %.4f\n", numero, sqrt(numero));
    else
        printf("Numero negativo. Quadrado de %.2f = %.2f\n", numero, numero * numero);

    return 0;
}
