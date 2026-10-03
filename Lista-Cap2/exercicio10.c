/* Questão 10 - Celsius para Fahrenheit e Kelvin */
#include <stdio.h>

int main(void)
{
    double celsius, fahrenheit, kelvin;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%lf", &celsius);

    /* celsius é double, então (celsius * 9) / 5 já é divisão real */
    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin     = celsius + 273.15;

    printf("%.2f C = %.2f F = %.2f K\n", celsius, fahrenheit, kelvin);

    return 0;
}
