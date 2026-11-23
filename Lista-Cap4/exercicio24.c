/* Questão 24 - Classificacao de triangulos pelos angulos */
#include <stdio.h>

int main(void)
{
    int a1, a2, a3;

    printf("Digite os tres angulos internos: ");
    scanf("%d %d %d", &a1, &a2, &a3);

    if (a1 <= 0 || a2 <= 0 || a3 <= 0 || a1 + a2 + a3 != 180) {
        printf("Angulos invalidos: a soma deve ser 180 e todos positivos.\n");
        return 1;
    }

    if (a1 == 90 || a2 == 90 || a3 == 90)
        printf("Triangulo Retangulo\n");
    else if (a1 > 90 || a2 > 90 || a3 > 90)
        printf("Triangulo Obtusangulo\n");
    else
        printf("Triangulo Acutangulo\n");

    return 0;
}
