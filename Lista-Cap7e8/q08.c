/* Questão 08 - Matriz transposta (3x4 -> 4x3) */
#include <stdio.h>

#define LIN 3
#define COL 4

int main(void)
{
    int original[LIN][COL], transposta[COL][LIN];
    int i, j;

    for (i = 0; i < LIN; i++)
        for (j = 0; j < COL; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &original[i][j]);
            transposta[j][i] = original[i][j];
        }

    printf("\nOriginal (%dx%d):\n", LIN, COL);
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++)
            printf("%5d", original[i][j]);
        printf("\n");
    }

    printf("\nTransposta (%dx%d):\n", COL, LIN);
    for (i = 0; i < COL; i++) {
        for (j = 0; j < LIN; j++)
            printf("%5d", transposta[i][j]);
        printf("\n");
    }

    return 0;
}
