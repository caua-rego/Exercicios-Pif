/* Questão 25 - Maximo divisor comum com recursao (questao avancada) */
#include <stdio.h>

int mdc(int a, int b);
void simplifica(int num, int den);

int main(void)
{
    int a, b;

    printf("Digite dois inteiros positivos: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Os numeros devem ser positivos.\n");
        return 1;
    }

    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    printf("Fracao %d/%d simplificada: ", a, b);
    simplifica(a, b);

    return 0;
}

/* Algoritmo de Euclides
 * Caso base: mdc(a, 0) = a
 * Passo recursivo: mdc(a, b) = mdc(b, a % b) */
int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

/* Divide numerador e denominador pelo MDC */
void simplifica(int num, int den)
{
    int divisor = mdc(num, den);
    printf("%d/%d\n", num / divisor, den / divisor);
}
