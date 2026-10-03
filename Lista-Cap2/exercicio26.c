/* Questão 26 - Orçamento para cercamento de terreno com 3 fios de arame */
#include <stdio.h>

#define FIOS 3

int main(void)
{
    double comprimento, largura, preco_metro, perimetro, metros_arame, custo;

    printf("Comprimento do terreno (m): ");
    scanf("%lf", &comprimento);
    printf("Largura do terreno (m): ");
    scanf("%lf", &largura);
    printf("Preco do metro de arame (R$): ");
    scanf("%lf", &preco_metro);

    perimetro    = 2 * (comprimento + largura);
    metros_arame = perimetro * FIOS;
    custo        = metros_arame * preco_metro;

    printf("Perimetro do terreno:  %.2f m\n", perimetro);
    printf("Arame a comprar:       %.2f m\n", metros_arame);
    printf("Custo total:           R$ %.2f\n", custo);

    return 0;
}
