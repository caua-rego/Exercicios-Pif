/* Questão 02 - Soma dos quadrados de 1 a 9 (versão corrigida)
 * Erro original: 'soma' era declarada DENTRO do bloco do for. Fora dele a
 * variável não existe (erro no printf) e, a cada iteração, ela era recriada
 * e zerada, perdendo o valor acumulado.
 */
#include <stdio.h>

int main(void)
{
    int i;
    int soma = 0;   /* declarada no escopo de main: vive até o fim da função */

    for (i = 1; i < 10; i++) {
        soma += i * i;
    }

    printf("Soma final = %d\n", soma);   /* 1+4+9+...+81 = 285 */

    return 0;
}
