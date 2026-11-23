/* Questão 04 - Analise de emprestimo pessoal (Cap. 4) */
#include <stdio.h>

int main(void)
{
    int idade;
    float renda, valorSolicitado;

    printf("Idade: ");
    scanf("%d", &idade);
    printf("Renda mensal: R$ ");
    scanf("%f", &renda);
    printf("Valor solicitado: R$ ");
    scanf("%f", &valorSolicitado);

    if (idade >= 18 && idade <= 70 && renda >= 2000.0f) {
        if (valorSolicitado <= renda * 10)
            printf("Emprestimo aprovado!\n");
        else
            printf("Valor acima do limite permitido.\n");
    } else {
        printf("Emprestimo negado.\n");
    }

    return 0;
}
