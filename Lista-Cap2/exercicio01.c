/* Questão 01 - Truncamento na atribuição de double para int (verificação) */
#include <stdio.h>
#include <math.h>   /* round() -> compile com -lm */

int main(void)
{
    int valor_inteiro;

    /* Conversão implícita (coerção): a parte fracionária é descartada. */
    valor_inteiro = 2.97;
    printf("O valor armazenado eh: %d\n", valor_inteiro);          /* 2 */

    /* Formas de o programador controlar a conversão explicitamente: */
    valor_inteiro = (int) 2.97;              /* cast explícito: deixa claro que trunca */
    printf("Com cast (int):      %d\n", valor_inteiro);             /* 2 */

    valor_inteiro = (int) (2.97 + 0.5);      /* arredondamento "manual" para positivos */
    printf("Com (int)(x + 0.5):  %d\n", valor_inteiro);             /* 3 */

    valor_inteiro = (int) round(2.97);       /* arredondamento com round() de <math.h> */
    printf("Com round():         %d\n", valor_inteiro);             /* 3 */

    double valor_real = 2.97;                /* para manter a precisão, use float/double */
    printf("Mantendo a precisao: %.2f\n", valor_real);              /* 2.97 */

    return 0;
}
