/* Questão 05 - Expressões relacionais e lógicas (verificação dos resultados) */
#include <stdio.h>

int main(void)
{
    int i = 1, j = 2, k = 3, n = 2;
    float x = 3.3, y = 4.4;

    printf("a) i < j + 3                  = %d\n", i < j + 3);
    printf("b) 2 * i - 7 <= j - 8         = %d\n", 2 * i - 7 <= j - 8);
    printf("c) -x + y >= 2.0 * y          = %d\n", -x + y >= 2.0 * y);
    printf("d) x == y                     = %d\n", x == y);
    printf("e) !(n - j)                   = %d\n", !(n - j));
    printf("f) !n - j                     = %d  (valor aritmetico; como condicao e 'verdadeiro')\n", !n - j);
    printf("g) i && j && k                = %d\n", i && j && k);
    printf("h) i || j - 3 && k            = %d\n", i || (j - 3 && k));   /* && antes de || */
    printf("i) i < j && 2 >= k            = %d\n", i < j && 2 >= k);
    printf("j) i == 2 || j == 4 || k == 5 = %d\n", i == 2 || j == 4 || k == 5);

    return 0;
}
