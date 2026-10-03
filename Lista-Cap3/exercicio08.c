/* Questão 08 - Validação de nota (0.0 a 10.0) com do-while */
#include <stdio.h>

int main(void)
{
    double nota;

    do {
        printf("Digite uma nota entre 0.0 e 10.0: ");
        scanf("%lf", &nota);

        if (nota < 0.0 || nota > 10.0)
            printf("Erro: nota invalida! Tente novamente.\n");
    } while (nota < 0.0 || nota > 10.0);

    printf("Nota registrada com sucesso!\n");

    return 0;
}
