/* Questão 21 - Jogo de adivinhação de letra com dicas (rand()) */
#include <stdio.h>
#include <stdlib.h>   /* rand(), srand() */
#include <time.h>     /* time() */

int main(void)
{
    char secreta, chute;
    int tentativas = 0;

    srand((unsigned) time(NULL));
    secreta = rand() % 26 + 'a';       /* 0..25 deslocado para 'a'..'z' */

    printf("Sorteei uma letra minuscula entre 'a' e 'z'. Tente adivinhar!\n");

    do {
        printf("Sua letra: ");
        scanf(" %c", &chute);          /* o espaço ignora o ENTER anterior */
        tentativas++;

        if (chute < secreta)
            printf("Errou! A letra secreta vem DEPOIS de '%c' no alfabeto.\n", chute);
        else if (chute > secreta)
            printf("Errou! A letra secreta vem ANTES de '%c' no alfabeto.\n", chute);
    } while (chute != secreta);

    printf("Parabens! A letra era '%c'. Total de tentativas: %d\n", secreta, tentativas);

    return 0;
}
