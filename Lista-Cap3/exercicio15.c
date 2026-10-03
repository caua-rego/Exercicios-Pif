/* Questão 15 - Múltiplos de 3 E de 5 ao mesmo tempo, de 1 até NUM */
#include <stdio.h>

int main(void)
{
    int num, i, encontrados = 0;

    printf("Digite o limite NUM (inteiro positivo): ");
    scanf("%d", &num);

    printf("Multiplos de 3 e de 5 entre 1 e %d:\n", num);

    for (i = 1; i <= num; i++) {
        if (i % 3 == 0 && i % 5 == 0) {   /* as duas condições juntas */
            printf("%d ", i);
            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("Nenhum numero no intervalo e multiplo de 3 e de 5.");
    printf("\n");

    return 0;
}
