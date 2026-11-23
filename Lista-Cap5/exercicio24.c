/* Questão 24 - Compilacao condicional para depuracao */
#include <stdio.h>

/* Comente/descomente a linha abaixo para ligar ou desligar a depuracao.
 * Tambem da para definir na compilacao: gcc -Wall -DDEBUG -o exercicio24 exercicio24.c */
#define DEBUG

int somaAteN(int n);

int main(void)
{
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    printf("Soma de 1 ate %d = %d\n", n, somaAteN(n));

    return 0;
}

int somaAteN(int n)
{
    int soma = 0, i;

    for (i = 1; i <= n; i++) {
        soma += i;
#ifdef DEBUG
        printf("[DEBUG] i = %d, soma parcial = %d\n", i, soma);
#endif
    }

    return soma;
}

/* Diferenca de comportamento:
 * - COM #define DEBUG: o pre-processador mantem o printf dentro do laco, e o
 *   programa mostra a soma parcial a cada iteracao antes do resultado final.
 *   Ex.: n = 4 -> soma parcial 1, 3, 6, 10 e depois "Soma de 1 ate 4 = 10".
 * - SEM #define DEBUG: o bloco entre #ifdef e #endif e removido antes da
 *   compilacao; o executavel nem contem esse printf e so mostra o resultado
 *   final. */
