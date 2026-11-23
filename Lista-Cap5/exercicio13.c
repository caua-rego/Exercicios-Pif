/* Questão 13 - Calculadora com quatro operacoes */
#include <stdio.h>

float soma(float a, float b);
float subtrai(float a, float b);
float multiplica(float a, float b);
float divide(float a, float b);

int main(void)
{
    int opcao;
    float valor1, valor2;

    printf("===== CALCULADORA =====\n");
    printf("1 - Somar\n");
    printf("2 - Subtrair\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4) {
        printf("Opcao invalida!\n");
        return 1;
    }

    printf("Digite os dois operandos: ");
    scanf("%f %f", &valor1, &valor2);

    switch (opcao) {
    case 1:
        printf("%.2f + %.2f = %.2f\n", valor1, valor2, soma(valor1, valor2));
        break;
    case 2:
        printf("%.2f - %.2f = %.2f\n", valor1, valor2, subtrai(valor1, valor2));
        break;
    case 3:
        printf("%.2f * %.2f = %.2f\n", valor1, valor2, multiplica(valor1, valor2));
        break;
    case 4:
        /* valida a divisao por zero antes de chamar a funcao */
        if (valor2 == 0)
            printf("Erro: divisao por zero!\n");
        else
            printf("%.2f / %.2f = %.2f\n", valor1, valor2, divide(valor1, valor2));
        break;
    }

    return 0;
}

float soma(float a, float b)       { return a + b; }
float subtrai(float a, float b)    { return a - b; }
float multiplica(float a, float b) { return a * b; }
float divide(float a, float b)     { return a / b; }
