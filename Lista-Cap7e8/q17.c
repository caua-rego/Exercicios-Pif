/* Questão 17 - Nome completo no formato "Sobrenome, Nome" */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[30], sobrenome[30], completo[64];

    printf("Primeiro nome: ");
    scanf("%29s", nome);
    printf("Sobrenome: ");
    scanf("%29s", sobrenome);

    strcpy(completo, sobrenome);
    strcat(completo, ", ");
    strcat(completo, nome);

    puts(completo);
    printf("Quantidade de caracteres: %d\n", (int)strlen(completo));

    return 0;
}
