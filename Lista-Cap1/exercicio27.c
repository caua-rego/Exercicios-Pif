/* Questão 27 - Converte segundos em horas, minutos e segundos */
#include <stdio.h>

int main(void)
{
    int total, horas, minutos, segundos;

    printf("Digite um intervalo de tempo em segundos: ");
    scanf("%d", &total);

    horas    = total / 3600;         /* 1 hora = 3600 s */
    minutos  = (total % 3600) / 60;  /* o que sobra das horas, em minutos */
    segundos = total % 60;           /* o que sobra dos minutos */

    printf("%d segundos correspondem a %d hora(s), %d minuto(s) e %d segundo(s).\n",
           total, horas, minutos, segundos);

    return 0;
}
