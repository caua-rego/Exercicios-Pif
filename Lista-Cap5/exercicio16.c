/* Questão 16 - Ano bissexto */
#include <stdio.h>

int ehBissexto(int ano);

int main(void)
{
    int ano;

    printf("Digite um ano: ");
    scanf("%d", &ano);

    if (ehBissexto(ano))
        printf("%d e bissexto.\n", ano);
    else
        printf("%d nao e bissexto.\n", ano);

    return 0;
}

/* Bissexto: divisivel por 400, ou divisivel por 4 e nao por 100 */
int ehBissexto(int ano)
{
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}
