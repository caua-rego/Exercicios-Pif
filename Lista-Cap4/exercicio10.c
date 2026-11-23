/* Questão 10 - Paridade e sinal de inteiros */
#include <stdio.h>

int main(void)
{
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    /* a) paridade com o operador resto */
    if (numero % 2 == 0)
        printf("%d e PAR\n", numero);
    else
        printf("%d e IMPAR\n", numero);

    /* b) sinal */
    if (numero > 0)
        printf("%d e POSITIVO\n", numero);
    else if (numero < 0)
        printf("%d e NEGATIVO\n", numero);
    else
        printf("O numero e ZERO\n");

    return 0;
}
