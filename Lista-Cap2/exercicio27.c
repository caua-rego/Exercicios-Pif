/* Questão 27 - Lançamento de três dados com rand() e o operador % */
#include <stdio.h>
#include <stdlib.h>   /* rand(), srand() */
#include <time.h>     /* time() */

int main(void)
{
    int dado1, dado2, dado3;

    /* Semente baseada no relógio: sem isso rand() repete a mesma sequência
       a cada execução do programa. */
    srand((unsigned) time(NULL));

    /* rand() % 6 devolve um valor de 0 a 5; somando 1 obtemos de 1 a 6. */
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;
    dado3 = rand() % 6 + 1;

    printf("Dado 1: %d\n", dado1);
    printf("Dado 2: %d\n", dado2);
    printf("Dado 3: %d\n", dado3);
    printf("Soma:   %d\n", dado1 + dado2 + dado3);

    return 0;
}
