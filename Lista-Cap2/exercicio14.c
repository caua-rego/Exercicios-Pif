/* Questão 14 - Área de um triângulo qualquer pela Fórmula de Heron
 * Compilar com: gcc -Wall -o exercicio14 exercicio14.c -lm
 */
#include <stdio.h>
#include <math.h>   /* sqrt() */

int main(void)
{
    double a, b, c, p, area;

    printf("Digite os tres lados do triangulo (a b c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    p    = (a + b + c) / 2.0;                       /* semiperímetro */
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("Semiperimetro: %.2f\n", p);
    printf("Area:          %.2f\n", area);

    return 0;
}
