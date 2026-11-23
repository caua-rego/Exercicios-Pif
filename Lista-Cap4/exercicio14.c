/* Questão 14 - Conceito por nota e faltas */
#include <stdio.h>

int main(void)
{
    float nota;
    int faltas;
    char conceito;

    printf("Nota final (0 a 10): ");
    scanf("%f", &nota);
    printf("Numero de faltas: ");
    scanf("%d", &faltas);

    if (nota < 0 || nota > 10 || faltas < 0) {
        printf("Dados invalidos.\n");
        return 1;
    }

    if (nota >= 9.0f)
        conceito = (faltas <= 20) ? 'A' : 'B';
    else if (nota >= 7.5f)
        conceito = (faltas <= 20) ? 'B' : 'C';
    else if (nota >= 5.0f)
        conceito = (faltas <= 20) ? 'C' : 'D';
    else if (nota >= 4.0f)
        conceito = (faltas <= 20) ? 'D' : 'E';
    else
        conceito = 'E';

    printf("Conceito: %c\n", conceito);

    return 0;
}
