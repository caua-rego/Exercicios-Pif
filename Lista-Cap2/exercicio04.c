/* Questão 04 - Atribuições compostas e precedência (verificação dos cálculos) */
#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4;

    a += b + c;        /* a = 1 + (2 + 3) = 6 */
    printf("a += b + c;        -> a = %d\n", a);

    b *= c = d + 2;    /* c = 4 + 2 = 6, depois b = 2 * 6 = 12 */
    printf("b *= c = d + 2;    -> b = %d, c = %d\n", b, c);

    d %= a + a + a;    /* d = 4 % (6 + 6 + 6) = 4 % 18 = 4 */
    printf("d %%= a + a + a;    -> d = %d\n", d);

    d -= c -= b -= a;  /* b = 12 - 6 = 6; c = 6 - 6 = 0; d = 4 - 0 = 4 */
    printf("d -= c -= b -= a;  -> d = %d, c = %d, b = %d\n", d, c, b);

    a += b += c += 7;  /* c = 0 + 7 = 7; b = 6 + 7 = 13; a = 6 + 13 = 19 */
    printf("a += b += c += 7;  -> a = %d, b = %d, c = %d\n", a, b, c);

    printf("\nValores finais: a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    return 0;
}
