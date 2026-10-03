/* Questão 09 - Quatro operações com dois inteiros e cast na divisão */
#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &b);

    printf("Soma:          %d\n", a + b);
    printf("Subtracao:     %d\n", a - b);
    printf("Multiplicacao: %d\n", a * b);

    /* (double) a converte UM operando antes de dividir; assim a divisão é real
       e não descarta a parte fracionária (sem o cast, 7 / 2 daria 3).
       Divisão por zero: como neste capítulo ainda não usamos if, o operador
       condicional (? :) só efetua a divisão quando b != 0; caso contrário
       exibe 0.00 acompanhado de um aviso de operação indefinida. */
    printf("Divisao:       %.2f%s\n",
           b != 0 ? (double) a / b : 0.0,
           b != 0 ? "" : "  (indefinida: divisor zero)");

    return 0;
}
