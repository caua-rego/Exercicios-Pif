/* Questão 26 - Primos no intervalo fechado [A, B] e sua soma */
#include <stdio.h>

int main(void)
{
    int a, b, numero, i, eh_primo, encontrados = 0;
    long soma = 0;

    do {
        printf("Digite A e B (inteiros positivos, A < B): ");
        scanf("%d %d", &a, &b);
        if (a < 1 || a >= b)
            printf("Valores invalidos!\n");
    } while (a < 1 || a >= b);

    printf("Primos em [%d, %d]:\n", a, b);

    for (numero = a; numero <= b; numero++) {
        if (numero < 2)
            continue;                    /* 0 e 1 não são primos */

        eh_primo = 1;
        for (i = 2; i * i <= numero; i++) {  /* basta testar até a raiz quadrada */
            if (numero % i == 0) {
                eh_primo = 0;
                break;
            }
        }

        if (eh_primo) {
            printf("%d ", numero);
            soma += numero;
            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("(nenhum)");

    printf("\nQuantidade: %d | Soma dos primos: %ld\n", encontrados, soma);

    return 0;
}
