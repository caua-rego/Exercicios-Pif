/* Questão 03 - Controle de ingressos de cinema (Cap. 4) */
#include <stdio.h>

#define PRECO_INTEIRA 40.00f
#define QUARTA_FEIRA 4

int main(void)
{
    int idade, diaSemana;
    float valor;

    printf("Idade do cliente: ");
    scanf("%d", &idade);
    printf("Dia da semana (1 = Domingo ... 7 = Sabado): ");
    scanf("%d", &diaSemana);

    if (idade < 0 || diaSemana < 1 || diaSemana > 7) {
        printf("Dados invalidos.\n");
        return 1;
    }

    /* meia-entrada por idade OU por ser quarta-feira (nao acumula) */
    if (idade < 12 || idade > 60 || diaSemana == QUARTA_FEIRA)
        valor = PRECO_INTEIRA / 2;
    else
        valor = PRECO_INTEIRA;

    printf("Valor do ingresso: R$ %.2f\n", valor);

    return 0;
}
