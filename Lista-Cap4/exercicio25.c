/* Questão 25 - Troco na menor quantidade de cedulas */
#include <stdio.h>

int main(void)
{
    int total, entregue, troco, qtd;

    printf("Valor total a pagar: R$ ");
    scanf("%d", &total);
    printf("Valor entregue: R$ ");
    scanf("%d", &entregue);

    if (total <= 0 || entregue < total) {
        printf("Erro: valor entregue insuficiente ou valores invalidos.\n");
        return 1;
    }

    troco = entregue - total;
    printf("Troco: R$ %d\n", troco);

    qtd = troco / 100; troco %= 100;
    if (qtd > 0) printf("%d cedula(s) de R$ 100\n", qtd);
    qtd = troco / 50;  troco %= 50;
    if (qtd > 0) printf("%d cedula(s) de R$ 50\n", qtd);
    qtd = troco / 20;  troco %= 20;
    if (qtd > 0) printf("%d cedula(s) de R$ 20\n", qtd);
    qtd = troco / 10;  troco %= 10;
    if (qtd > 0) printf("%d cedula(s) de R$ 10\n", qtd);
    qtd = troco / 5;   troco %= 5;
    if (qtd > 0) printf("%d cedula(s) de R$ 5\n", qtd);
    qtd = troco / 2;   troco %= 2;
    if (qtd > 0) printf("%d cedula(s) de R$ 2\n", qtd);

    /* nao existe cedula de R$ 1: o que sobrar e informado a parte */
    if (troco > 0)
        printf("R$ %d nao pode ser dado em cedulas (use moeda)\n", troco);

    return 0;
}
