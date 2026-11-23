/* Questão 08 - Verificacao de ano bissexto */
#include <stdio.h>

int main(void)
{
    int ano;

    printf("Digite um ano: ");
    scanf("%d", &ano);

    if (ano <= 0) {
        printf("Digite um ano positivo.\n");
        return 1;
    }

    /* bissexto: divisivel por 400 OU (divisivel por 4 E nao divisivel por 100) */
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
        printf("O ano %d e bissexto.\n", ano);
    else
        printf("O ano %d nao e bissexto.\n", ano);

    return 0;
}
