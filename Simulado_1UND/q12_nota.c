/*
 * Questao 12 - Validacao de entrada com laco garantido (do-while)
 * Pede uma nota no intervalo fechado [0.0, 10.0] e repete enquanto
 * o valor for invalido. O do-while garante que a pergunta seja
 * feita pelo menos uma vez.
 */
#include <stdio.h>

int main(void) {
    double nota;
    int lidos, ch;

    do {
        printf("Digite uma nota (0.0 a 10.0): ");
        lidos = scanf("%lf", &nota);

        if (lidos == EOF) {             /* entrada encerrada (Ctrl+D / Ctrl+Z) */
            return 1;
        }

        if (lidos != 1) {               /* digitou letra ou simbolo */
            while ((ch = getchar()) != '\n' && ch != EOF) { }  /* limpa o buffer */
            nota = -1;                  /* forca o valor a ser invalido */
        }

        if (nota < 0.0 || nota > 10.0) {
            printf("Erro: nota invalida! A nota deve estar entre 0.0 e 10.0.\n");
        }
    } while (nota < 0.0 || nota > 10.0);

    printf("Nota valida registrada: %.1f\n", nota);

    return 0;
}
