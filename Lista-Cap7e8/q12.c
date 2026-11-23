/* Questão 12 - Jogo da velha (questao avancada) */
#include <stdio.h>

#define N 3

void imprimeTabuleiro(char tab[][N]);
char verificaVencedor(char tab[][N]);

int main(void)
{
    char tab[N][N];
    char jogador = 'X', vencedor = ' ';
    int linha, coluna, jogadas = 0, i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tab[i][j] = ' ';

    imprimeTabuleiro(tab);

    while (vencedor == ' ' && jogadas < N * N) {
        printf("Jogador %c, informe linha e coluna (0 a 2): ", jogador);
        if (scanf("%d %d", &linha, &coluna) != 2) {
            while (getchar() != '\n');   /* descarta entrada invalida */
            printf("Entrada invalida.\n");
            continue;
        }

        if (linha < 0 || linha >= N || coluna < 0 || coluna >= N) {
            printf("Posicao fora do tabuleiro!\n");
            continue;
        }
        if (tab[linha][coluna] != ' ') {
            printf("Posicao ja ocupada!\n");
            continue;
        }

        tab[linha][coluna] = jogador;
        jogadas++;
        imprimeTabuleiro(tab);

        vencedor = verificaVencedor(tab);
        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    if (vencedor != ' ')
        printf("Jogador %c venceu!\n", vencedor);
    else
        printf("Empate!\n");

    return 0;
}

void imprimeTabuleiro(char tab[][N])
{
    int i;
    printf("\n");
    for (i = 0; i < N; i++) {
        printf(" %c | %c | %c\n", tab[i][0], tab[i][1], tab[i][2]);
        if (i < N - 1)
            printf("---+---+---\n");
    }
    printf("\n");
}

/* Devolve 'X' ou 'O' se alguem fechou linha, coluna ou diagonal; ' ' caso contrario */
char verificaVencedor(char tab[][N])
{
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i][0] != ' ' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2])
            return tab[i][0];
        if (tab[0][i] != ' ' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i])
            return tab[0][i];
    }
    if (tab[1][1] != ' ' &&
        ((tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) ||
         (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0])))
        return tab[1][1];
    return ' ';
}
