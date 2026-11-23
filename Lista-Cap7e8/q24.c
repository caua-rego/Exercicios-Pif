/* Questão 24 - Controle de dieta */
#include <stdio.h>

#define QTD 5

typedef struct {
    char alimento[40];
    float porcao;      /* gramas */
    int calorias;
} Dieta;

int main(void)
{
    Dieta refeicao[QTD];
    int i, totalCalorias = 0, maisCalorico = 0;

    for (i = 0; i < QTD; i++) {
        printf("\nAlimento %d: ", i + 1);
        scanf(" %39[^\n]", refeicao[i].alimento);
        printf("Peso da porcao (g): ");
        scanf("%f", &refeicao[i].porcao);
        printf("Calorias: ");
        scanf("%d", &refeicao[i].calorias);
    }

    printf("\n%-20s %10s %10s\n", "Alimento", "Porcao(g)", "Calorias");
    for (i = 0; i < QTD; i++) {
        printf("%-20s %10.1f %10d\n", refeicao[i].alimento, refeicao[i].porcao, refeicao[i].calorias);
        totalCalorias += refeicao[i].calorias;
        if (refeicao[i].calorias > refeicao[maisCalorico].calorias)
            maisCalorico = i;
    }

    printf("\nTotal de calorias: %d kcal\n", totalCalorias);
    printf("Mais calorico: %s (%d kcal)\n", refeicao[maisCalorico].alimento,
           refeicao[maisCalorico].calorias);

    return 0;
}
