/* Questão 06 - Soma de matrizes 3x3 */
#include <stdio.h>

#define N 3

void lerMatriz(int m[][N], char nome);
void imprimeMatriz(int m[][N], char nome);

int main(void)
{
    int a[N][N], b[N][N], soma[N][N];
    int i, j;

    lerMatriz(a, 'A');
    lerMatriz(b, 'B');

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            soma[i][j] = a[i][j] + b[i][j];

    imprimeMatriz(a, 'A');
    imprimeMatriz(b, 'B');
    imprimeMatriz(soma, 'S');

    return 0;
}

void lerMatriz(int m[][N], char nome)
{
    int i, j;
    printf("Matriz %c:\n", nome);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            printf("  %c[%d][%d]: ", nome, i, j);
            scanf("%d", &m[i][j]);
        }
}

void imprimeMatriz(int m[][N], char nome)
{
    int i, j;
    printf("\nMatriz %c:\n", nome);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%6d", m[i][j]);   /* largura fixa mantem as colunas alinhadas */
        printf("\n");
    }
}
