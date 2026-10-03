/* Questão 18 - Área da superfície e volume de uma esfera */
#include <stdio.h>

#define PI 3.141593

int main(void)
{
    double raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%lf", &raio);

    area   = 4 * PI * raio * raio;                   /* A = 4 * Pi * R^2 */

    /* 4.0 / 3.0 e nao 4 / 3: com inteiros o resultado seria 1 (truncamento)
       e o volume sairia 25% menor que o correto. */
    volume = (4.0 / 3.0) * PI * raio * raio * raio;  /* V = (4/3) * Pi * R^3 */

    printf("Area da superficie: %.2f\n", area);
    printf("Volume:             %.2f\n", volume);

    return 0;
}
