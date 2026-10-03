/* Questão 23 - Quadrado vazado de lado L (3 a 20) com o caractere 'X' */
#include <stdio.h>

int main(void)
{
    int lado, linha, coluna;

    do {
        printf("Digite o lado do quadrado (3 a 20): ");
        scanf("%d", &lado);
        if (lado < 3 || lado > 20)
            printf("Valor invalido!\n");
    } while (lado < 3 || lado > 20);

    for (linha = 1; linha <= lado; linha++) {
        for (coluna = 1; coluna <= lado; coluna++) {
            /* imprime X na primeira/ultima linha e na primeira/ultima coluna */
            if (linha == 1 || linha == lado || coluna == 1 || coluna == lado)
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
