/* Questão 11 - Verificacao de numero par */
#include <stdio.h>

int ehPar(int n);

int main(void)
{
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (ehPar(numero))
        printf("%d e par.\n", numero);
    else
        printf("%d e impar.\n", numero);

    return 0;
}

/* Retorna 1 se n for par e 0 caso contrario */
int ehPar(int n)
{
    return (n % 2 == 0) ? 1 : 0;
}
