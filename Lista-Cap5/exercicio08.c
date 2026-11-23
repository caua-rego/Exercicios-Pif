/* Questão 08 - Conversor de Fahrenheit para Celsius */
#include <stdio.h>

float celsius(float fahr);

int main(void)
{
    float fahrenheit;

    printf("Temperatura em Fahrenheit: ");
    scanf("%f", &fahrenheit);

    printf("%.2f F = %.2f C\n", fahrenheit, celsius(fahrenheit));

    return 0;
}

/* Converte Fahrenheit para Celsius: C = (F - 32) * 5 / 9 */
float celsius(float fahr)
{
    return (fahr - 32.0f) * 5.0f / 9.0f;
}
