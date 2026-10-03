/* Questão 22 - Triângulo de Floyd com N linhas */
#include <stdio.h>

int main(void)
{
    int n, linha, coluna, numero = 1;

    printf("Digite o numero de linhas (N > 0): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Erro: N deve ser positivo.\n");
        return 1;
    }

    for (linha = 1; linha <= n; linha++) {           /* uma linha por vez... */
        for (coluna = 1; coluna <= linha; coluna++) /* ...com 'linha' numeros nela */
            printf("%d ", numero++);
        printf("\n");
    }

    return 0;
}
