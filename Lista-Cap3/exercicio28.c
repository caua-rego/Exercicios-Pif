/* Questão 28 - Folha de pagamento com menu contínuo (do-while + switch) */
#include <stdio.h>

int main(void)
{
    int opcao, c;
    double salario, novo_salario, imposto;

    do {
        printf("\n===== FOLHA DE PAGAMENTO =====\n");
        printf("1. Reajuste salarial\n");
        printf("2. Retencao de imposto de renda\n");
        printf("3. Encerrar programa\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            /* Entrada não numérica: descarta a linha e trata como opção inválida.
               Se a entrada acabou (EOF), encerra o programa. */
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            opcao = (c == EOF) ? 3 : 0;
        }

        switch (opcao) {
        case 1:
            printf("Salario atual: R$ ");
            scanf("%lf", &salario);
            /* 15% de aumento ate R$ 2.000,00; 10% acima disso */
            novo_salario = (salario <= 2000.0) ? salario * 1.15 : salario * 1.10;
            printf("Novo salario: R$ %.2f\n", novo_salario);
            break;

        case 2:
            printf("Salario: R$ ");
            scanf("%lf", &salario);
            /* 8% de desconto ate R$ 3.000,00; 15% acima disso */
            imposto = (salario <= 3000.0) ? salario * 0.08 : salario * 0.15;
            printf("Imposto retido: R$ %.2f | Salario liquido: R$ %.2f\n",
                   imposto, salario - imposto);
            break;

        case 3:
            printf("Programa encerrado.\n");
            break;

        default:
            printf("Opcao invalida! Digite 1, 2 ou 3.\n");
        }
    } while (opcao != 3);

    return 0;
}
