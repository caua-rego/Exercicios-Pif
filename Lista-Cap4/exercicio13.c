/* Questão 13 - Calculadora aritmetica e cientifica com switch
 * Compilar com: gcc -Wall -o exercicio13 exercicio13.c -lm */
#include <stdio.h>
#include <math.h>

int main(void)
{
    char operacao;
    double valor1, valor2;

    printf("===== CALCULADORA =====\n");
    printf("+ Soma\n- Subtracao\n* Multiplicacao\n/ Divisao\n^ Potenciacao\n");
    printf("Escolha a operacao: ");
    scanf(" %c", &operacao);

    printf("Digite os dois operandos: ");
    scanf("%lf %lf", &valor1, &valor2);

    switch (operacao) {
    case '+':
        printf("%.2f + %.2f = %.2f\n", valor1, valor2, valor1 + valor2);
        break;
    case '-':
        printf("%.2f - %.2f = %.2f\n", valor1, valor2, valor1 - valor2);
        break;
    case '*':
        printf("%.2f * %.2f = %.2f\n", valor1, valor2, valor1 * valor2);
        break;
    case '/':
        if (valor2 == 0)
            printf("Erro: divisao por zero!\n");
        else
            printf("%.2f / %.2f = %.2f\n", valor1, valor2, valor1 / valor2);
        break;
    case '^':
        printf("%.2f ^ %.2f = %.2f\n", valor1, valor2, pow(valor1, valor2));
        break;
    default:
        printf("Operacao invalida!\n");
    }

    return 0;
}
