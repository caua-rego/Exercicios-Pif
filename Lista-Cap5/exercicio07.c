/* Questão 07 - Soma de dois inteiros */
#include <stdio.h>

int soma(int a, int b);

int main(void)
{
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    printf("Soma = %d\n", soma(num1, num2));

    return 0;
}

/* Recebe dois inteiros e devolve a soma deles */
int soma(int a, int b)
{
    return a + b;
}
