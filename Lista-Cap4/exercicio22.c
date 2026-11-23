/* Questão 22 - Imposto estadual sobre produtos */
#include <stdio.h>

int main(void)
{
    float valor, aliquota;
    int estado;

    printf("Valor do produto: R$ ");
    scanf("%f", &valor);
    printf("Estado de destino (1 - MG, 2 - SP, 3 - RJ, 4 - MS): ");
    scanf("%d", &estado);

    switch (estado) {
    case 1: aliquota = 0.07f; break;
    case 2: aliquota = 0.12f; break;
    case 3: aliquota = 0.15f; break;
    case 4: aliquota = 0.08f; break;
    default:
        printf("Erro: codigo de estado invalido!\n");
        return 1;
    }

    printf("Imposto: R$ %.2f\n", valor * aliquota);
    printf("Preco final: R$ %.2f\n", valor * (1 + aliquota));

    return 0;
}
