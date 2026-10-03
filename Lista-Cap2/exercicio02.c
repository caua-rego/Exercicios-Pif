/* Questão 02 - Leitura portável de um caractere com <stdio.h>
 * Substitui getch()/getche() de <conio.h>, que não existem fora do Windows.
 */
#include <stdio.h>

int main(void)
{
    int c;      /* int (e não char) para poder comparar com EOF */
    int sobra;

    printf("Digite um caractere: ");

    /* Pula quebras de linha que tenham ficado no buffer de leituras anteriores */
    do {
        c = getchar();
    } while (c == '\n');

    /* Descarta o resto da linha atual (inclusive o '\n' do ENTER), para que
       a próxima leitura não receba lixo do buffer do teclado. */
    while ((sobra = getchar()) != '\n' && sobra != EOF)
        ;

    printf("Voce digitou: ");
    putchar(c);
    putchar('\n');

    /* Alternativa só com scanf(): o ESPAÇO antes de %c faz a função ignorar
       espaços, tabulações e quebras de linha pendentes antes de ler. */
    char ch;
    printf("Digite outro caractere: ");
    scanf(" %c", &ch);
    printf("Agora voce digitou: %c\n", ch);

    return 0;
}
