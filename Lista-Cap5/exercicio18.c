/* Questão 18 - Potencia com recursao */
#include <stdio.h>

long potencia(int base, int expoente);

int main(void)
{
    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("O expoente nao pode ser negativo.\n");
        return 1;
    }

    printf("%d ^ %d = %ld\n", base, expoente, potencia(base, expoente));

    return 0;
}

long potencia(int base, int expoente)
{
    /* Caso base: qualquer numero elevado a 0 vale 1 */
    if (expoente == 0)
        return 1;

    /* Passo recursivo: base^exp = base * base^(exp - 1) */
    return base * potencia(base, expoente - 1);
}
