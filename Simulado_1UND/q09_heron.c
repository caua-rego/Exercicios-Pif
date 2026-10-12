/*
 * Questao 9 - Geometria do triangulo e Formula de Heron
 * Le os tres lados (a, b, c) e calcula a area:
 *   p    = (a + b + c) / 2.0                (semiperimetro)
 *   Area = sqrt(p * (p - a) * (p - b) * (p - c))
 *
 * Compilar: gcc q09_heron.c -o q09 -lm
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, p, area;

    printf("Informe os tres lados do triangulo (a b c): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Erro: valores invalidos.\n");
        return 1;
    }

    /* Lados devem ser positivos e respeitar a desigualdade triangular:
       cada lado tem que ser menor que a soma dos outros dois. */
    if (a <= 0 || b <= 0 || c <= 0 || a >= b + c || b >= a + c || c >= a + b) {
        printf("Erro: esses lados nao formam um triangulo.\n");
        return 1;
    }

    p = (a + b + c) / 2.0;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("\nSemiperimetro (p): %.3f\n", p);
    printf("Area do triangulo: %.3f\n", area);

    return 0;
}
