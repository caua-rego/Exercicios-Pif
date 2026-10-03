/* Questão 17 - Estatísticas da turma: total, maior, menor e média (sentinela -1.0) */
#include <stdio.h>

int main(void)
{
    double nota, soma = 0.0, maior = 0.0, menor = 0.0;
    int total = 0;

    printf("Digite as notas (0.0 a 10.0). Digite -1.0 para encerrar.\n");

    while (1) {
        printf("Nota: ");
        scanf("%lf", &nota);

        if (nota == -1.0)
            break;                              /* sentinela */

        if (nota < 0.0 || nota > 10.0) {
            printf("Nota invalida, ignorada.\n");
            continue;                           /* volta para a leitura */
        }

        total++;
        soma += nota;

        if (total == 1 || nota > maior) maior = nota;   /* primeira nota inicia maior/menor */
        if (total == 1 || nota < menor) menor = nota;
    }

    if (total == 0) {
        printf("\nNenhuma nota foi informada.\n");
        return 0;
    }

    printf("\na) Total de alunos: %d\n", total);
    printf("b) Maior nota:      %.2f\n", maior);
    printf("c) Menor nota:      %.2f\n", menor);
    printf("d) Media geral:     %.2f\n", soma / total);

    return 0;
}
