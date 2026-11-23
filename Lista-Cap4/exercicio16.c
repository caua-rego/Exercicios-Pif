/* Questão 16 - Eficiencia de consumo de combustivel */
#include <stdio.h>

int main(void)
{
    float distancia, litros, consumo;

    printf("Distancia percorrida (km): ");
    scanf("%f", &distancia);
    printf("Litros consumidos: ");
    scanf("%f", &litros);

    if (litros <= 0) {
        printf("A quantidade de litros deve ser maior que zero.\n");
        return 1;
    }

    consumo = distancia / litros;
    printf("Consumo: %.2f km/l\n", consumo);

    if (consumo < 8.0f)
        printf("Venda o carro!\n");
    else if (consumo <= 14.0f)
        printf("Economico!\n");
    else
        printf("Super economico!\n");

    return 0;
}
