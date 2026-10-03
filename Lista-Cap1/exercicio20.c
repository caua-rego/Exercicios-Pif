/* Questão 20 - Moldura 4x4 com caracteres gráficos (Codepage 437/850)
 *   \xC9 = canto sup. esq.   \xBB = canto sup. dir.
 *   \xC8 = canto inf. esq.   \xBC = canto inf. dir.
 *   \xCD = linha horizontal  \xBA = linha vertical
 */
#include <stdio.h>

int main(void)
{
    printf("\xC9\xCD\xCD\xBB\n");
    printf("\xBA  \xBA\n");
    printf("\xBA  \xBA\n");
    printf("\xC8\xCD\xCD\xBC\n");

    return 0;
}
