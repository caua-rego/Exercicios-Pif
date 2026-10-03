/* Questão 05 - Operador vírgula com duas variáveis de controle */
#include <stdio.h>

int main(void)
{
    int i, j;

    /* Versão original com for: 5 iterações (i,j) = (0,10) (1,9) (2,8) (3,7) (4,6).
       Para quando i = 5 e j = 5, pois 5 < 5 é falso. */
    printf("--- for ---\n");
    for (i = 0, j = 10; i < j; i++, j--) {
        printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
    }

    /* Mesma lógica reescrita com while: a inicialização vem antes do laço e
       o "incremento" (i++, j--) vai para o FINAL do corpo. */
    printf("--- while ---\n");
    i = 0;
    j = 10;
    while (i < j) {
        printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
        i++;
        j--;
    }

    return 0;
}
