/* Questão 22 - Maiúscula para minúscula pela tabela ASCII (sem <ctype.h>) */
#include <stdio.h>

int main(void)
{
    char maiuscula, minuscula;

    printf("Digite uma letra maiuscula: ");
    scanf(" %c", &maiuscula);

    /* Na tabela ASCII as minúsculas ficam 32 posições após as maiúsculas:
       'A' = 65 e 'a' = 97. Logo, minuscula = maiuscula + 32, ou, de forma
       mais legível, maiuscula - 'A' + 'a' (posição na sequência das letras
       somada ao início do bloco das minúsculas). */
    minuscula = maiuscula - 'A' + 'a';

    printf("Maiuscula: %c (%d) -> Minuscula: %c (%d)\n",
           maiuscula, maiuscula, minuscula, minuscula);

    return 0;
}
