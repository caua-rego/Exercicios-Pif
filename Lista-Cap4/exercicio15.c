/* Questão 15 - Elegibilidade para aposentadoria */
#include <stdio.h>

int main(void)
{
    int idade, tempoServico;

    printf("Idade: ");
    scanf("%d", &idade);
    printf("Tempo de servico (anos): ");
    scanf("%d", &tempoServico);

    if (idade >= 65 || tempoServico >= 30 || (idade >= 60 && tempoServico >= 25))
        printf("O trabalhador PODE se aposentar.\n");
    else
        printf("O trabalhador AINDA NAO pode se aposentar.\n");

    return 0;
}
