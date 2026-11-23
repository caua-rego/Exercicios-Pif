/* Questão 18 - Conversor de escalas termometricas */
#include <stdio.h>

int main(void)
{
    int opcao;
    float entrada;

    printf("1 - Celsius para Fahrenheit\n");
    printf("2 - Celsius para Kelvin\n");
    printf("3 - Fahrenheit para Celsius\n");
    printf("4 - Kelvin para Celsius\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4) {
        printf("Opcao invalida!\n");
        return 1;
    }

    printf("Temperatura de entrada: ");
    scanf("%f", &entrada);

    switch (opcao) {
    case 1: printf("%.2f C = %.2f F\n", entrada, entrada * 1.8f + 32); break;
    case 2: printf("%.2f C = %.2f K\n", entrada, entrada + 273.15f); break;
    case 3: printf("%.2f F = %.2f C\n", entrada, (entrada - 32) / 1.8f); break;
    case 4: printf("%.2f K = %.2f C\n", entrada, entrada - 273.15f); break;
    }

    return 0;
}
