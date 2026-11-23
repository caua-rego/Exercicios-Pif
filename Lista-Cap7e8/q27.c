/* Questão 27 - Dado generico com union */
#include <stdio.h>

#define QTD 3

typedef union {
    int i;
    float f;
    char c;
} Valor;

typedef enum { INTEIRO, REAL, CARACTERE } Tipo;

typedef struct {
    Tipo tipo;
    Valor valor;
} Registro;

int main(void)
{
    Registro registros[QTD];
    int i, opcao;

    for (i = 0; i < QTD; i++) {
        do {
            printf("\nRegistro %d - tipo (0 - inteiro, 1 - real, 2 - caractere): ", i + 1);
            scanf("%d", &opcao);
        } while (opcao < INTEIRO || opcao > CARACTERE);

        registros[i].tipo = (Tipo)opcao;
        printf("Valor: ");
        switch (registros[i].tipo) {
        case INTEIRO:   scanf("%d", &registros[i].valor.i); break;
        case REAL:      scanf("%f", &registros[i].valor.f); break;
        case CARACTERE: scanf(" %c", &registros[i].valor.c); break;
        }
    }

    printf("\n");
    for (i = 0; i < QTD; i++) {
        printf("Registro %d: ", i + 1);
        /* o campo "tipo" indica qual membro da union e valido */
        switch (registros[i].tipo) {
        case INTEIRO:   printf("inteiro %d\n", registros[i].valor.i); break;
        case REAL:      printf("real %.2f\n", registros[i].valor.f); break;
        case CARACTERE: printf("caractere '%c'\n", registros[i].valor.c); break;
        }
    }

    printf("\nsizeof(Valor) = %d bytes\n", (int)sizeof(Valor));

    return 0;
}

/* Por que sizeof(Valor) vale 4?
 * Em uma union todos os membros compartilham o mesmo espaco de memoria, entao
 * ela ocupa o tamanho do MAIOR membro (e nao a soma, como na struct).
 * Aqui int e float ocupam 4 bytes e char 1 byte, logo a union tem 4 bytes.
 * Por isso so um membro guarda um valor valido por vez, e o campo "tipo" do
 * Registro e necessario para saber qual ler. */
