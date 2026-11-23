/* Questão 25 - Meses com enumeracao */
#include <stdio.h>

enum Mes { Jan = 1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez };

int main(void)
{
    int dmes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int numero;
    enum Mes m;

    printf("Numero do mes: ");
    scanf("%d", &numero);

    switch (numero) {
    case Jan: printf("Janeiro\n"); break;
    case Fev: printf("Fevereiro\n"); break;
    case Mar: printf("Marco\n"); break;
    case Abr: printf("Abril\n"); break;
    case Mai: printf("Maio\n"); break;
    case Jun: printf("Junho\n"); break;
    case Jul: printf("Julho\n"); break;
    case Ago: printf("Agosto\n"); break;
    case Set: printf("Setembro\n"); break;
    case Out: printf("Outubro\n"); break;
    case Nov: printf("Novembro\n"); break;
    case Dez: printf("Dezembro\n"); break;
    default:  printf("Mes invalido\n");
    }

    /* o enum comeca em 1, por isso o indice do vetor e m - 1 */
    printf("\nDias de cada mes:\n");
    for (m = Jan; m <= Dez; m++)
        printf("Mes %2d: %d dias\n", m, dmes[m - 1]);

    return 0;
}
