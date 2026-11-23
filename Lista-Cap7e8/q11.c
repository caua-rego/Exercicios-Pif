/* Questão 11 - Ocupacao de um condominio (matriz 3D) */
#include <stdio.h>

#define BLOCOS 3
#define ANDARES 2
#define APTOS 4

int main(void)
{
    int ocup[BLOCOS][ANDARES][APTOS];
    int b, a, p, totalBloco, totalGeral = 0;

    for (b = 0; b < BLOCOS; b++)
        for (a = 0; a < ANDARES; a++)
            for (p = 0; p < APTOS; p++) {
                printf("Bloco %d, andar %d, apto %d - moradores: ", b + 1, a + 1, p + 1);
                scanf("%d", &ocup[b][a][p]);
            }

    printf("\n");
    for (b = 0; b < BLOCOS; b++) {
        totalBloco = 0;
        for (a = 0; a < ANDARES; a++)
            for (p = 0; p < APTOS; p++)
                totalBloco += ocup[b][a][p];
        printf("Bloco %d: %d moradores\n", b + 1, totalBloco);
        totalGeral += totalBloco;
    }
    printf("Total do condominio: %d moradores\n", totalGeral);

    return 0;
}
