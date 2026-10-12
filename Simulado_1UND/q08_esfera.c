/*
 * Questao 8 - Calculos geometricos e constantes com <math.h>
 * Le o raio R de uma esfera e calcula:
 *   a) Area da superficie: A = 4 * PI * R^2
 *   b) Volume:             V = (4.0 / 3.0) * PI * R^3
 *
 * Compilar: gcc q08_esfera.c -o q08 -lm
 */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void) {
    double raio, area, volume;

    printf("Informe o raio R da esfera: ");
    if (scanf("%lf", &raio) != 1) {
        printf("Erro: valor invalido.\n");
        return 1;
    }

    if (raio < 0) {
        printf("Erro: o raio nao pode ser negativo.\n");
        return 1;
    }

    area = 4 * PI * pow(raio, 2);
    /* 4.0 / 3.0 e divisao real (1.333...). Com 4 / 3 seria divisao inteira e daria 1. */
    volume = (4.0 / 3.0) * PI * pow(raio, 3);

    printf("\n--- Esfera de raio %.3f ---\n", raio);
    printf("a) Area da superficie: %.3f\n", area);
    printf("b) Volume:             %.3f\n", volume);

    return 0;
}
