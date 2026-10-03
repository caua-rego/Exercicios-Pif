/* Questão 03 - Um inteiro em decimal, hexadecimal, octal e como caractere ASCII */
#include <stdio.h>

int main(void)
{
    int numero;

    printf("Digite um numero inteiro (ex.: 65): ");
    scanf("%d", &numero);

    printf("Decimal: %d | Hexadecimal: %x | Octal: %o | Caractere ASCII: %c\n",
           numero, numero, numero, numero);

    return 0;
}
