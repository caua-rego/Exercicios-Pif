/* Questão 19 - Contagem regressiva recursiva */
#include <stdio.h>

void contagem(int n);
void contagemCrescente(int n);

int main(void)
{
    int n;

    printf("Digite um numero positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O numero deve ser positivo.\n");
        return 1;
    }

    printf("Contagem regressiva:\n");
    contagem(n);
    printf("Fogo!\n");

    printf("\nContagem crescente:\n");
    contagemCrescente(n);
    printf("\n");

    return 0;
}

/* Imprime de n ate 1: o printf vem ANTES da chamada recursiva */
void contagem(int n)
{
    if (n == 0)          /* caso base: nada a imprimir */
        return;
    printf("%d ", n);
    contagem(n - 1);
}

/* Imprime de 1 ate n: o printf vem DEPOIS da chamada recursiva.
 * O que muda: na versao regressiva cada chamada imprime o seu valor e so
 * depois desce para n-1, entao os numeros saem na ordem de empilhamento
 * (n, n-1, ..., 1). Aqui cada chamada primeiro desce ate o caso base e so
 * imprime ao retornar, entao os numeros saem na ordem de desempilhamento
 * (1, 2, ..., n). */
void contagemCrescente(int n)
{
    if (n == 0)
        return;
    contagemCrescente(n - 1);
    printf("%d ", n);
}
