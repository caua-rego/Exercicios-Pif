/*
 * Questao 10 - Resto da divisao (%) e decomposicao do tempo
 * Converte uma quantidade de segundos em horas, minutos e segundos.
 * Exemplo: 3665 segundos = 1 hora, 1 minuto e 5 segundos.
 */
#include <stdio.h>

int main(void) {
    int total, horas, minutos, segundos;

    printf("Informe a quantidade de segundos: ");
    if (scanf("%d", &total) != 1 || total < 0) {
        printf("Erro: informe um numero inteiro nao negativo.\n");
        return 1;
    }

    horas    = total / 3600;           /* 1 hora = 3600 segundos         */
    minutos  = (total % 3600) / 60;    /* o que sobra das horas, em min. */
    segundos = total % 60;             /* o que sobra dos minutos        */

    printf("%d segundos correspondem a %d %s, %d %s e %d %s.\n",
           total,
           horas,    horas    == 1 ? "hora"    : "horas",
           minutos,  minutos  == 1 ? "minuto"  : "minutos",
           segundos, segundos == 1 ? "segundo" : "segundos");

    return 0;
}
