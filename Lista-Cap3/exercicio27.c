/* Questão 27 - Caixa eletrônico: menor quantidade de cédulas por subtrações sucessivas */
#include <stdio.h>

int main(void)
{
    int valor, restante;
    int c100 = 0, c50 = 0, c20 = 0, c10 = 0, c5 = 0, c2 = 0;

    printf("Valor do saque (R$, inteiro positivo): ");
    scanf("%d", &valor);

    if (valor <= 0) {
        printf("Erro: o valor deve ser positivo.\n");
        return 1;
    }

    restante = valor;

    /* Da maior para a menor cédula: enquanto couber, subtrai e conta uma nota. */
    while (restante >= 100) { restante -= 100; c100++; }
    while (restante >= 50)  { restante -= 50;  c50++;  }
    while (restante >= 20)  { restante -= 20;  c20++;  }
    while (restante >= 10)  { restante -= 10;  c10++;  }
    while (restante >= 5)   { restante -= 5;   c5++;   }
    while (restante >= 2)   { restante -= 2;   c2++;   }

    printf("\nCedulas para R$ %d:\n", valor);
    if (c100) printf("%3d x R$ 100\n", c100);
    if (c50)  printf("%3d x R$  50\n", c50);
    if (c20)  printf("%3d x R$  20\n", c20);
    if (c10)  printf("%3d x R$  10\n", c10);
    if (c5)   printf("%3d x R$   5\n", c5);
    if (c2)   printf("%3d x R$   2\n", c2);

    if (restante > 0)
        printf("Atencao: R$ %d nao pode ser pago com as cedulas disponiveis.\n", restante);

    return 0;
}
