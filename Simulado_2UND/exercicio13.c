/* Questão 13 - Vendas por loja e produto (matriz) (Cap. 7) */
#include <stdio.h>

#define LOJAS 4
#define PRODUTOS 3

int main(void)
{
    int vendas[LOJAS][PRODUTOS];
    int totalProduto[PRODUTOS] = {0};
    int loja, produto, totalLoja, produtoMaisVendido = 0;

    for (loja = 0; loja < LOJAS; loja++)
        for (produto = 0; produto < PRODUTOS; produto++) {
            printf("Loja %d - quantidade vendida do produto %d: ", loja + 1, produto + 1);
            scanf("%d", &vendas[loja][produto]);
        }

    printf("\n");
    for (loja = 0; loja < LOJAS; loja++) {
        totalLoja = 0;
        for (produto = 0; produto < PRODUTOS; produto++) {
            totalLoja += vendas[loja][produto];
            totalProduto[produto] += vendas[loja][produto];
        }
        printf("Total vendido pela loja %d: %d\n", loja + 1, totalLoja);
    }

    for (produto = 1; produto < PRODUTOS; produto++)
        if (totalProduto[produto] > totalProduto[produtoMaisVendido])
            produtoMaisVendido = produto;

    printf("Produto mais vendido na rede: produto %d (%d unidades)\n",
           produtoMaisVendido + 1, totalProduto[produtoMaisVendido]);

    return 0;
}
