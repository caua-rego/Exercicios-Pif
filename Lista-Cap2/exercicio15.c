/* Questão 15 - Média aritmética simples e ponderada de quatro notas */
#include <stdio.h>

int main(void)
{
    double n1, n2, n3, n4, simples, ponderada;

    printf("Digite as quatro notas: ");
    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

    simples   = (n1 + n2 + n3 + n4) / 4.0;

    /* Pesos: 1 para as provas 1 e 2, 2 para as provas 3 e 4 -> soma dos pesos = 6 */
    ponderada = (n1 * 1 + n2 * 1 + n3 * 2 + n4 * 2) / 6.0;

    printf("a) Media simples:   %.2f\n", simples);
    printf("b) Media ponderada: %.2f\n", ponderada);

    return 0;
}
