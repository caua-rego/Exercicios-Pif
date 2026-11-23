/* Questão 26 - Sequencia de Fibonacci recursiva (questao avancada) */
#include <stdio.h>

long fibonacci(int n);

int main(void)
{
    int quantidade, i;

    printf("Quantos termos deseja exibir? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Digite um valor positivo.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++)
        printf("%ld ", fibonacci(i));
    printf("\n");

    return 0;
}

/* Caso base: fibonacci(0) = 0 e fibonacci(1) = 1
 * Passo recursivo: fibonacci(n) = fibonacci(n-1) + fibonacci(n-2) */
long fibonacci(int n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* Por que fica lenta para n grande?
 * Cada chamada gera outras duas, e os mesmos termos sao recalculados muitas
 * vezes (fibonacci(5) calcula fibonacci(3) duas vezes, fibonacci(2) tres
 * vezes...). O numero de chamadas cresce de forma exponencial (cerca de 2^n),
 * entao para n perto de 40 ja sao centenas de milhoes de chamadas. Uma versao
 * com laco, que guarda os dois termos anteriores, faz apenas n passos. */
