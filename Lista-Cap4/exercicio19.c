/* Questão 19 - Existencia e tipo de triangulo (lados) */
#include <stdio.h>

int main(void)
{
    float a, b, c;

    printf("Digite os tres lados (A B C): ");
    scanf("%f %f %f", &a, &b, &c);

    if (a < b + c && b < a + c && c < a + b) {
        if (a == b && b == c)
            printf("Triangulo Equilatero\n");
        else if (a == b || a == c || b == c)
            printf("Triangulo Isosceles\n");
        else
            printf("Triangulo Escaleno\n");
    } else {
        printf("Erro: Os lados fornecidos nao formam um triangulo!\n");
    }

    return 0;
}
