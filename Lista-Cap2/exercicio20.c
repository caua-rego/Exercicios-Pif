/* Questão 20 - Hipotenusa pelo Teorema de Pitágoras
 * Compilar com: gcc -Wall -o exercicio20 exercicio20.c -lm
 */
#include <stdio.h>
#include <math.h>   /* sqrt(), pow() */

int main(void)
{
    double lado_a, lado_b, hipotenusa;

    printf("Digite o cateto a: ");
    scanf("%lf", &lado_a);
    printf("Digite o cateto b: ");
    scanf("%lf", &lado_b);

    hipotenusa = sqrt(pow(lado_a, 2) + pow(lado_b, 2));

    printf("Hipotenusa: %.2f\n", hipotenusa);

    return 0;
}
