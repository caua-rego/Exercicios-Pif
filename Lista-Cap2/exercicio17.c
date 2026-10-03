/* Questão 17 - Área e circunferência de um círculo */
#include <stdio.h>

#define PI 3.141593

int main(void)
{
    double raio, area, circunferencia;

    printf("Digite o raio do circulo: ");
    scanf("%lf", &raio);

    area           = PI * raio * raio;   /* A = Pi * R^2 */
    circunferencia = 2 * PI * raio;      /* C = 2 * Pi * R */

    printf("Area:           %.2f\n", area);
    printf("Circunferencia: %.2f\n", circunferencia);

    return 0;
}
