/* Questão 21 - Macros utilitarias */
#include <stdio.h>

/* Parenteses em volta de cada argumento e da expressao inteira */
#define SQR(x)    ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void)
{
    int num1, num2;

    printf("Digite dois inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("Quadrado de %d = %d\n", num1, SQR(num1));
    printf("Quadrado de %d = %d\n", num2, SQR(num2));
    printf("Maior = %d\n", MAX(num1, num2));
    printf("Menor = %d\n", MIN(num1, num2));

    return 0;
}
