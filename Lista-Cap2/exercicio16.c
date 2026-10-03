/* Questão 16 - Número mínimo de degraus de uma escada
 * Compilar com: gcc -Wall -o exercicio16 exercicio16.c -lm
 */
#include <stdio.h>
#include <math.h>   /* ceil() */

int main(void)
{
    double degrau_cm, altura_m, altura_cm;
    int degraus;

    printf("Altura de cada degrau (cm): ");
    scanf("%lf", &degrau_cm);
    printf("Altura que deseja alcancar (m): ");
    scanf("%lf", &altura_m);

    altura_cm = altura_m * 100.0;                   /* 1 m = 100 cm: mesma unidade */

    /* ceil() arredonda para cima: se a divisão não for exata, ainda é preciso
       subir mais um degrau para atingir (ou ultrapassar) a altura desejada. */
    degraus = (int) ceil(altura_cm / degrau_cm);

    printf("Numero minimo de degraus: %d\n", degraus);

    return 0;
}
