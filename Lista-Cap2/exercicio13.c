/* Questão 13 - Áreas do quadrado, do retângulo e do triângulo retângulo */
#include <stdio.h>

int main(void)
{
    float lado, base, altura;

    printf("Lado do quadrado: ");
    scanf("%f", &lado);
    printf("Base do retangulo / triangulo: ");
    scanf("%f", &base);
    printf("Altura do retangulo / triangulo: ");
    scanf("%f", &altura);

    printf("\na) Area do quadrado:            %.2f\n", lado * lado);
    printf("b) Area do retangulo:           %.2f\n", base * altura);
    printf("c) Area do triangulo retangulo: %.2f\n", (base * altura) / 2.0f);

    return 0;
}
