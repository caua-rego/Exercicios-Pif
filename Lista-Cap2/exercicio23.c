/* Questão 23 - Horário de término de um experimento (hh:mm:ss) */
#include <stdio.h>

int main(void)
{
    int h, m, s, duracao, total;

    printf("Horario de inicio - horas: ");
    scanf("%d", &h);
    printf("Horario de inicio - minutos: ");
    scanf("%d", &m);
    printf("Horario de inicio - segundos: ");
    scanf("%d", &s);
    printf("Duracao do experimento (segundos): ");
    scanf("%d", &duracao);

    total = h * 3600 + m * 60 + s + duracao;   /* tudo em segundos */
    total %= 24 * 3600;                        /* se passar da meia-noite, volta a 00:00:00 */

    h = total / 3600;           /* horas completas */
    m = (total % 3600) / 60;    /* minutos que sobram das horas */
    s = total % 60;             /* segundos que sobram dos minutos */

    printf("Termino: %02d:%02d:%02d\n", h, m, s);

    return 0;
}
