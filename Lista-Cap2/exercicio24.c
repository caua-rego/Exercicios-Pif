/* Questão 24 - Velocidade de km/h para m/s */
#include <stdio.h>

int main(void)
{
    double kmh, ms;

    printf("Digite a velocidade em km/h: ");
    scanf("%lf", &kmh);

    ms = kmh / 3.6;   /* 1 km/h = 1000 m / 3600 s = 1 / 3.6 m/s */

    printf("%.2f km/h = %.2f m/s\n", kmh, ms);

    return 0;
}
