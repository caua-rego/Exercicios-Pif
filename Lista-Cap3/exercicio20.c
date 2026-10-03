/* Questão 20 - Tabela ASCII dos caracteres imprimíveis (32 a 126) */
#include <stdio.h>

int main(void)
{
    int codigo;

    printf("%8s %5s %10s\n", "Decimal", "Hex", "Caractere");
    printf("%8s %5s %10s\n", "-------", "---", "---------");

    for (codigo = 32; codigo <= 126; codigo++)
        printf("%8d %5X %10c\n", codigo, codigo, codigo);

    return 0;
}
