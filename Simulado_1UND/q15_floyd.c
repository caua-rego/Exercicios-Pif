/*
 * Questao 15 - Padroes visuais com lacos aninhados: Triangulo de Floyd
 * A linha L tem L numeros; os numeros seguem em sequencia (1, 2, 3, ...).
 * Exemplo para N = 5:
 *   1
 *   2 3
 *   4 5 6
 *   7 8 9 10
 *   11 12 13 14 15
 */
#include <stdio.h>

int main(void) {
    int n, linha, coluna;
    int numero = 1;

    printf("Informe um inteiro positivo N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erro: N deve ser um inteiro positivo.\n");
        return 1;
    }

    for (linha = 1; linha <= n; linha++) {             /* laco externo: linhas  */
        for (coluna = 1; coluna <= linha; coluna++) {  /* laco interno: numeros */
            printf("%d", numero);
            numero++;
            if (coluna < linha) {
                printf(" ");                           /* espaco so entre numeros */
            }
        }
        printf("\n");
    }

    return 0;
}
