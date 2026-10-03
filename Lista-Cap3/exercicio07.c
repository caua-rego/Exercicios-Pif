/* Questão 07 - Contagem de 0 a 100 com for, while e do-while */
#include <stdio.h>

void contar_com_for(void)
{
    int i;
    for (i = 0; i <= 100; i++)
        printf("%d ", i);
    printf("\n");
}

void contar_com_while(void)
{
    int i = 0;
    while (i <= 100) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

void contar_com_do_while(void)
{
    int i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 100);
    printf("\n");
}

int main(void)
{
    printf("Versao 1 (for):\n");
    contar_com_for();

    printf("\nVersao 2 (while):\n");
    contar_com_while();

    printf("\nVersao 3 (do-while):\n");
    contar_com_do_while();

    return 0;
}

/* Qual estrutura é a mais adequada?
 * O laço for. O número de repetições é conhecido de antemão (101 valores) e
 * depende de um contador: o for reúne inicialização, teste e incremento em
 * uma única linha, deixando a intenção clara e evitando esquecer o i++.
 * O while serve melhor quando não se sabe quantas vezes o laço vai rodar, e
 * o do-while quando o corpo precisa executar ao menos uma vez (menus,
 * validação de entrada).
 */
