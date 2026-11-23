/* Questão 19 - Agenda de nomes (matriz de strings) */
#include <stdio.h>
#include <string.h>

#define QTD 5
#define TAM 30

int main(void)
{
    char nomes[QTD][TAM];
    int i, maisLongo = 0, maisCurto = 0, mesmaInicial = 0;

    for (i = 0; i < QTD; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%29s", nomes[i]);
    }

    for (i = 1; i < QTD; i++) {
        if (strlen(nomes[i]) > strlen(nomes[maisLongo])) maisLongo = i;
        if (strlen(nomes[i]) < strlen(nomes[maisCurto])) maisCurto = i;
    }

    /* conta os outros nomes que comecam com a mesma letra do primeiro */
    for (i = 1; i < QTD; i++)
        if (nomes[i][0] == nomes[0][0])
            mesmaInicial++;

    printf("Nome mais longo: %s\n", nomes[maisLongo]);
    printf("Nome mais curto: %s\n", nomes[maisCurto]);
    printf("Outros nomes que comecam com '%c': %d\n", nomes[0][0], mesmaInicial);

    return 0;
}
