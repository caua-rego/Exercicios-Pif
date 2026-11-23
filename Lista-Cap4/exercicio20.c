/* Questão 20 - Equacao do segundo grau (Bhaskara)
 * Compilar com: gcc -Wall -o exercicio20 exercicio20.c -lm */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, delta, x1, x2;

    printf("Coeficientes a, b e c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("Erro: 'a' deve ser diferente de zero.\n");
        return 1;
    }

    delta = b * b - 4 * a * c;
    printf("Delta = %.2f\n", delta);

    if (delta < 0) {
        printf("A equacao nao possui raizes reais.\n");
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("Raiz unica: x = %.2f\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);
    }

    return 0;
}
