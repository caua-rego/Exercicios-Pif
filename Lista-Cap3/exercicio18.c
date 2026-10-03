/* Questão 18 - Inversão dos dígitos de um inteiro positivo */
#include <stdio.h>

int main(void)
{
    int numero, invertido = 0, digito;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: o numero deve ser positivo.\n");
        return 1;
    }

    int original = numero;

    while (numero > 0) {
        digito    = numero % 10;            /* separa o último dígito */
        invertido = invertido * 10 + digito; /* "empurra" os anteriores para a esquerda */
        numero   /= 10;                     /* descarta o último dígito */
    }

    printf("%d invertido = %d\n", original, invertido);

    return 0;
}
