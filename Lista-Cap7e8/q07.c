/* Questão 07 - Diagonais da matriz 4x4 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int main(void)
{
    int m[N][N], i, j;
    int diagPrincipal = 0, diagSecundaria = 0, acimaPrincipal = 0;

    srand(time(NULL));

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() % 20 + 1;

    printf("Matriz:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        diagPrincipal += m[i][i];
        diagSecundaria += m[i][N - 1 - i];
        for (j = i + 1; j < N; j++)   /* acima da principal: coluna > linha */
            acimaPrincipal += m[i][j];
    }

    printf("\nSoma da diagonal principal: %d\n", diagPrincipal);
    printf("Soma da diagonal secundaria: %d\n", diagSecundaria);
    printf("Soma acima da diagonal principal: %d\n", acimaPrincipal);

    return 0;
}
