/* Questão 24 - Tabela de notas alinhada com largura de campo
 * Os nomes acentuados usam escapes da CP850 (\xB5 = 'Á', \x90 = 'É') para que
 * cada letra ocupe 1 byte e o %-12s alinhe corretamente no console do Windows.
 */
#include <stdio.h>

int main(void)
{
    printf("%-12s%5s\n", "ALUNO(A)", "NOTA");
    printf("%-12s%5s\n", "=========", "=====");
    printf("%-12s%5.1f\n", "ALINE", 9.0);
    printf("%-12s%5s\n", "M\xB5RIO", "DEZ");
    printf("%-12s%5.1f\n", "S\x90RGIO", 4.5);
    printf("%-12s%5.1f\n", "SHIRLEY", 7.0);

    return 0;
}
