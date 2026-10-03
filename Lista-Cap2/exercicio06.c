/* Questão 06 - Incremento prefixado (++n) x pós-fixado (m++) */
#include <stdio.h>

int main(void)
{
    /* Trecho A: ++n incrementa ANTES de entregar o valor para a atribuição */
    int n = 5;
    int x = ++n;
    printf("Trecho A: n = %d, x = %d\n", n, x);   /* n = 6, x = 6 */

    /* Trecho B: m++ entrega o valor ANTIGO e só depois incrementa */
    int m = 5;
    int y = m++;
    printf("Trecho B: m = %d, y = %d\n", m, y);   /* m = 6, y = 5 */

    /* Item b: printf("%d\t%d\t%d\n", n, n+1, n++); e COMPORTAMENTO INDEFINIDO,
       pois n e modificado e lido na mesma expressao sem ponto de sequencia.
       A forma segura e separar a modificacao em uma instrucao propria: */
    printf("%d\t%d\t%d\n", n, n + 1, n);
    n++;

    return 0;
}
