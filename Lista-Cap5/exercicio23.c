/* Questão 23 - Macro versus funcao */
#include <stdio.h>

#define DOBRO(x) x*2                  /* versao sem protecao */
#define DOBRO_CORRIGIDO(x) ((x) * 2)  /* versao corrigida */

int dobro(int x);

int main(void)
{
    printf("Macro DOBRO(2+3)           = %d\n", DOBRO(2+3));
    printf("Funcao dobro(2+3)          = %d\n", dobro(2+3));
    printf("Macro DOBRO_CORRIGIDO(2+3) = %d\n", DOBRO_CORRIGIDO(2+3));

    return 0;
}

int dobro(int x)
{
    return x * 2;
}

/* Por que os resultados diferem?
 * A macro e uma substituicao de texto feita pelo pre-processador:
 * DOBRO(2+3) vira 2+3*2. Como * tem precedencia sobre +, o resultado e
 * 2 + 6 = 8.
 * Na funcao, o argumento 2+3 e avaliado ANTES da chamada; x recebe 5 e a
 * funcao devolve 10.
 * Com os parenteses de protecao, DOBRO_CORRIGIDO(2+3) vira ((2+3) * 2) = 10,
 * igual a funcao. */
