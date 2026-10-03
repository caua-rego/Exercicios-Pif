/* Questão 03 - Flexibilidade do laço for (trechos A, B e C) */
#include <stdio.h>

int main(void)
{
    int a, ch, contador;

    /* Trecho A: incremento por divisão. Imprime 36 18 9 4 2 1 e para
       quando a divisão inteira chega a 0 (1 / 2 = 0). */
    printf("Trecho A: ");
    for (a = 36; a > 0; a /= 2)
        printf("%d\t", a);
    printf("\n");

    /* Trecho B (versão portável com getchar() no lugar de getch()):
       sem inicialização nem incremento; lê caracteres até receber 'X' e
       imprime o caractere seguinte na tabela ASCII (ch + 1). Os parênteses
       em (ch = getchar()) são obrigatórios porque != tem precedência maior
       que =; sem eles ch receberia 0 ou 1. */
    printf("Trecho B: digite caracteres e termine com X: ");
    for (; (ch = getchar()) != 'X' && ch != EOF;)
        if (ch != '\n')            /* ignora o ENTER para não imprimir lixo */
            printf("%c", ch + 1);
    printf("\n");

    /* Trecho C: for (;;) é um laço infinito. A forma programática de sair
       é testar uma condição dentro do corpo e usar break. */
    printf("Trecho C: ");
    contador = 0;
    for (;;) {
        printf("Laco %d  ", contador);
        contador++;
        if (contador == 3)
            break;                 /* encerra o laço infinito */
    }
    printf("\n");

    return 0;
}
