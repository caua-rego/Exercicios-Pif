/* Questão 06 - Laço sem corpo com incremento pós-fixado */
#include <stdio.h>

int main(void)
{
    /* Versão original: o corpo é vazio (só o ';'). Todo o trabalho acontece
       no teste: compara o valor ANTIGO de x com 5 e depois incrementa x.
       Quando x = 5 o teste falha, mas o ++ ainda é executado -> x = 6. */
    int x = 0;
    while (x++ < 5);
    printf("Valor final de x = %d\n", x);   /* 6 */

    /* Versão explícita, sem corpo vazio, com o mesmo resultado: */
    int z = 0;
    while (z < 5) {
        z++;            /* z vai de 0 a 5 */
    }
    z++;                /* o último teste (5 < 5, falso) também incrementava */
    printf("Valor final de z = %d\n", z);   /* 6 */

    return 0;
}
