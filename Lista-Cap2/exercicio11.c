/* Questão 11 - Conversão de graus para radianos */
#include <stdio.h>

#define PI 3.141593

int main(void)
{
    double graus, radianos;

    printf("Digite o angulo em graus: ");
    scanf("%lf", &graus);

    radianos = graus * (PI / 180.0);

    printf("%.2f graus = %.4f radianos\n", graus, radianos);

    return 0;
}
