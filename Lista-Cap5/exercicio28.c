/* Questão 28 - Caixa simples de mercadinho */
#include <stdio.h>

#define A_VISTA 1
#define CARTAO  2

float calculaSubtotal(float preco, int quantidade);
float aplicaDesconto(float valor, int opcaoPagamento);
float calculaTroco(float total, float pago);

int main(void)
{
    float preco, subtotal, total, pago;
    int quantidade, opcaoPagamento;

    printf("Preco do produto: R$ ");
    scanf("%f", &preco);
    printf("Quantidade: ");
    scanf("%d", &quantidade);

    if (preco < 0 || quantidade <= 0) {
        printf("Preco ou quantidade invalidos.\n");
        return 1;
    }

    printf("Forma de pagamento (1 - A vista, 2 - Cartao): ");
    scanf("%d", &opcaoPagamento);

    if (opcaoPagamento != A_VISTA && opcaoPagamento != CARTAO) {
        printf("Forma de pagamento invalida.\n");
        return 1;
    }

    subtotal = calculaSubtotal(preco, quantidade);
    total = aplicaDesconto(subtotal, opcaoPagamento);

    printf("Subtotal: R$ %.2f\n", subtotal);
    printf("Total a pagar: R$ %.2f\n", total);

    printf("Valor pago: R$ ");
    scanf("%f", &pago);

    if (pago < total)
        printf("Valor insuficiente! Faltam R$ %.2f\n", total - pago);
    else
        printf("Troco: R$ %.2f\n", calculaTroco(total, pago));

    return 0;
}

float calculaSubtotal(float preco, int quantidade)
{
    return preco * quantidade;
}

/* 10% de desconto no pagamento a vista */
float aplicaDesconto(float valor, int opcaoPagamento)
{
    if (opcaoPagamento == A_VISTA)
        return valor * 0.9f;
    return valor;
}

float calculaTroco(float total, float pago)
{
    return pago - total;
}
