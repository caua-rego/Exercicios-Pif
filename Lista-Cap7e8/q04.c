/* Questão 04 - Dias corridos no ano (sem considerar bissexto) */
#include <stdio.h>

int main(void)
{
    int dmes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dia, mes, i, diasPassados = 0;

    printf("Digite a data (dia mes): ");
    scanf("%d %d", &dia, &mes);

    if (mes < 1 || mes > 12 || dia < 1 || dia > dmes[mes - 1]) {
        printf("Data invalida.\n");
        return 1;
    }

    for (i = 0; i < mes - 1; i++)
        diasPassados += dmes[i];
    diasPassados += dia;

    printf("Dias desde 1 de janeiro (contando o dia informado): %d\n", diasPassados);
    printf("Dias que faltam para o fim do ano: %d\n", 365 - diasPassados);

    return 0;
}
