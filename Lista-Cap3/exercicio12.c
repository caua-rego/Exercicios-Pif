/* Questão 12 - Tabela de conversão Celsius / Fahrenheit / Kelvin (0 a 100, de 5 em 5) */
#include <stdio.h>

int main(void)
{
    int celsius;
    double fahrenheit, kelvin;

    printf("%10s %12s %10s\n", "Celsius", "Fahrenheit", "Kelvin");
    printf("%10s %12s %10s\n", "-------", "----------", "------");

    for (celsius = 0; celsius <= 100; celsius += 5) {
        fahrenheit = (9.0 * celsius) / 5 + 32;   /* 9.0 evita divisão inteira */
        kelvin     = celsius + 273.15;
        printf("%10.2f %12.2f %10.2f\n", (double) celsius, fahrenheit, kelvin);
    }

    return 0;
}
