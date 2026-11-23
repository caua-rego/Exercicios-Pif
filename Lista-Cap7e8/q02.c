/* Questão 02 - Vetor invertido com controle de limite */
#include <stdio.h>

#define TAMANHO 15

int main(void)
{
    int vet[TAMANHO];
    int n = 0, num, i;

    printf("Digite numeros inteiros (0 para encerrar):\n");
    do {
        printf("Numero: ");
        scanf("%d", &num);
        if (num != 0) {
            if (n == TAMANHO) {
                printf("BUFFER LOTADO\n");
                break;
            }
            vet[n++] = num;
        }
    } while (num != 0);

    printf("Valores em ordem inversa:\n");
    for (i = n - 1; i >= 0; i--)
        printf("%d ", vet[i]);
    printf("\n");

    return 0;
}
