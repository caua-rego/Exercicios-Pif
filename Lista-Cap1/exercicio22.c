/* Questão 22 - Carro e caminhonete com caracteres de bloco (CP437/850)
 *   \xDC = meio bloco inferior   \xDF = meio bloco superior   \xDB = bloco cheio
 */
#include <stdio.h>

int main(void)
{
    /* carro */
    printf(" \xDC\xDC\xDB\xDB\xDB\xDB\xDC\xDC\n");
    printf("\xDFO\xDF\xDF\xDF\xDF\xDFO\xDF\n");
    printf("\n");
    /* caminhonete */
    printf("\xDC\xDC\xDB \xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\xDFO\xDF\xDF\xDF\xDF\xDFOO\xDF\n");

    return 0;
}
