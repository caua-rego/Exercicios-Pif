/* Questão 10 - Os 100 primeiros múltiplos positivos de 3, 10 por linha */
#include <stdio.h>

int main(void)
{
    int i;

    for (i = 1; i <= 100; i++) {
        printf("%d\t", 3 * i);

        if (i % 10 == 0)        /* a cada 10 números, quebra a linha */
            printf("\n");
    }

    return 0;
}
