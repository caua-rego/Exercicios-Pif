/* Questão 21 - Código ASCII de um caractere */
#include <stdio.h>

int main(void)
{
    char c;

    printf("Digite um caractere: ");
    scanf(" %c", &c);

    /* Um char ocupa 1 byte e guarda, na verdade, um número inteiro: o código
       do caractere na tabela ASCII. Ao imprimir com %d mostramos esse código
       (ex.: 'A' = 65, 'a' = 97, '0' = 48); com %c mostramos o desenho do
       caractere associado a esse mesmo número. */
    printf("Caractere: %c | Codigo ASCII: %d\n", c, c);

    return 0;
}
