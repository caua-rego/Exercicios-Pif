/* Questão 21 - Versão 1: uma única chamada de printf() */
#include <stdio.h>

int main(void)
{
    printf("Treinamento em programa\x87\xC6o.\nLinguagem C.\n"); /* \x87 = 'ç', \xC6 = 'ã' (CP850) */

    return 0;
}
