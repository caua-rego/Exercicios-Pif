/* Questão 10 - Gerador de jogos de loteria */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JOGOS 5
#define DEZENAS 6

int main(void)
{
    int jogos[JOGOS][DEZENAS];
    int i, j, k, dezena, repetida;

    srand(time(NULL));

    for (i = 0; i < JOGOS; i++) {
        j = 0;
        while (j < DEZENAS) {
            dezena = rand() % 60 + 1;

            /* verifica se a dezena ja saiu neste jogo */
            repetida = 0;
            for (k = 0; k < j; k++)
                if (jogos[i][k] == dezena)
                    repetida = 1;

            if (!repetida)
                jogos[i][j++] = dezena;
        }
    }

    for (i = 0; i < JOGOS; i++) {
        printf("Jogo %d: ", i + 1);
        for (j = 0; j < DEZENAS; j++)
            printf("%02d ", jogos[i][j]);
        printf("\n");
    }

    return 0;
}
