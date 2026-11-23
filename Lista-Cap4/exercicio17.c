/* Questão 17 - Pagamento e comissao de vendas */
#include <stdio.h>

int main(void)
{
    float valorCompra, valorFinal, comissao;
    int opcao;

    printf("Valor total da compra: R$ ");
    scanf("%f", &valorCompra);
    printf("Pagamento (1 - A vista com 10%% de desconto, 2 - Parcelado em 3x): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        valorFinal = valorCompra * 0.90f;
        comissao = valorFinal * 0.05f;
        printf("Valor a pagar a vista: R$ %.2f\n", valorFinal);
    } else if (opcao == 2) {
        comissao = valorCompra * 0.05f;
        printf("3 parcelas de R$ %.2f (total R$ %.2f)\n", valorCompra / 3, valorCompra);
    } else {
        printf("Opcao de pagamento invalida.\n");
        return 1;
    }

    printf("Comissao do vendedor: R$ %.2f\n", comissao);

    return 0;
}
