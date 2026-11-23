/* Questão 03 - Frequencia de valores (30 lancamentos de um dado) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANCAMENTOS 30
#define FACES 6

int main(void)
{
    int lancamentos[LANCAMENTOS];
    int frequencia[FACES] = {0};
    int i;

    srand(time(NULL));

    for (i = 0; i < LANCAMENTOS; i++) {
        lancamentos[i] = rand() % 6 + 1;
        frequencia[lancamentos[i] - 1]++;   /* face 1 fica na posicao 0 */
    }

    printf("Lancamentos: ");
    for (i = 0; i < LANCAMENTOS; i++)
        printf("%d ", lancamentos[i]);
    printf("\n\n");

    for (i = 0; i < FACES; i++)
        printf("Face %d: %d vezes\n", i + 1, frequencia[i]);

    return 0;
}
