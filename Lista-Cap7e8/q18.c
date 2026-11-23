/* Questão 18 - Ordem alfabetica de tres nomes */
#include <stdio.h>
#include <string.h>

#define TAM 50

int main(void)
{
    char nome1[TAM], nome2[TAM], nome3[TAM], aux[TAM];

    printf("Digite tres nomes:\n");
    scanf("%49s %49s %49s", nome1, nome2, nome3);

    /* tres comparacoes com troca garantem a ordem */
    if (strcmp(nome1, nome2) > 0) { strcpy(aux, nome1); strcpy(nome1, nome2); strcpy(nome2, aux); }
    if (strcmp(nome1, nome3) > 0) { strcpy(aux, nome1); strcpy(nome1, nome3); strcpy(nome3, aux); }
    if (strcmp(nome2, nome3) > 0) { strcpy(aux, nome2); strcpy(nome2, nome3); strcpy(nome3, aux); }

    printf("Em ordem alfabetica:\n%s\n%s\n%s\n", nome1, nome2, nome3);

    return 0;
}
