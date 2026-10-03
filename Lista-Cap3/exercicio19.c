/* Questão 19 - N-ésimo termo da sequência de Fibonacci */
#include <stdio.h>

int main(void)
{
    int n, i;
    long long anterior = 1, atual = 1, proximo;

    printf("Qual termo da sequencia de Fibonacci deseja (N >= 1)? ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Erro: N deve ser maior ou igual a 1.\n");
        return 1;
    }

    printf("Termos ate N:\n");

    /* Os dois primeiros termos valem 1; a partir do 3o cada termo e a soma dos anteriores */
    for (i = 1; i <= n; i++) {
        if (i <= 2) {
            printf("%d: 1\n", i);
        } else {
            proximo  = anterior + atual;
            anterior = atual;
            atual    = proximo;
            printf("%d: %lld\n", i, atual);
        }
    }

    printf("\nO termo %d da sequencia de Fibonacci e %lld\n", n, atual);

    return 0;
}
