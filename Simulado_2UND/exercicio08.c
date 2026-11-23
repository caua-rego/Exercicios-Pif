/* Questão 08 - Funcoes recursivas: soma de digitos e potencia (Cap. 5) */
#include <stdio.h>

int somaDigitos(int n);
long potencia(int base, int exp);

int main(void)
{
    int numero, base, expoente;

    printf("Numero para somar os digitos: ");
    scanf("%d", &numero);
    if (numero < 0)
        numero = -numero;   /* trabalha com o valor absoluto */
    printf("Soma dos digitos = %d\n", somaDigitos(numero));

    printf("Base e expoente (expoente >= 0): ");
    scanf("%d %d", &base, &expoente);
    if (expoente < 0)
        printf("Expoente invalido.\n");
    else
        printf("%d ^ %d = %ld\n", base, expoente, potencia(base, expoente));

    return 0;
}

/* caso base: n < 10; passo: ultimo digito + soma do restante */
int somaDigitos(int n)
{
    if (n < 10)
        return n;
    return n % 10 + somaDigitos(n / 10);
}

/* caso base: exp == 0 -> 1; passo: base * base^(exp-1) */
long potencia(int base, int exp)
{
    if (exp == 0)
        return 1;
    return base * potencia(base, exp - 1);
}
