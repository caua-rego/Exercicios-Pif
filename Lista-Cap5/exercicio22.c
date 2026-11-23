/* Questão 22 - Biblioteca de areas com arquivo de cabecalho
 * Compilar com o areas.h na mesma pasta: gcc -Wall -o exercicio22 exercicio22.c */
#include <stdio.h>
#include "areas.h"

int main(void)
{
    float raio, base, altura;

    printf("Raio do circulo: ");
    scanf("%f", &raio);
    printf("Area do circulo = %.2f\n\n", A_CIRC(raio));

    printf("Base e altura do retangulo: ");
    scanf("%f %f", &base, &altura);
    printf("Area do retangulo = %.2f\n\n", A_RET(base, altura));

    printf("Base e altura do triangulo: ");
    scanf("%f %f", &base, &altura);
    printf("Area do triangulo = %.2f\n", A_TRI(base, altura));

    return 0;
}
