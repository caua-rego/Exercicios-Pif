/* Questão 09 - Maior de dois numeros */
#include <stdio.h>

int maior(int a, int b);

int main(void)
{
    int num1, num2;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("O maior e: %d\n", maior(num1, num2));

    return 0;
}

/* Devolve o maior entre a e b (se forem iguais, devolve qualquer um) */
int maior(int a, int b)
{
    return (a > b) ? a : b;
}
