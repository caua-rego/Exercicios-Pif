/* Questão 12 - Antecessor e sucessor usando apenas ++ e -- */
#include <stdio.h>

int main(void)
{
    int n, antecessor, sucessor;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    /* Copiamos n para duas variáveis e aplicamos os operadores unários:
       -- subtrai 1 (antecessor) e ++ soma 1 (sucessor). Trabalhar em cópias
       preserva o valor original de n para a impressão final. */
    antecessor = sucessor = n;
    --antecessor;
    ++sucessor;

    printf("Antecessor: %d\n", antecessor);
    printf("Numero:     %d\n", n);
    printf("Sucessor:   %d\n", sucessor);

    return 0;
}
