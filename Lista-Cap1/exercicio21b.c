/* Questão 21 - Versão 2: exatamente duas instruções de impressão */
#include <stdio.h>

int main(void)
{
    printf("Treinamento em programa\x87\xC6o.\n"); /* \x87 = 'ç', \xC6 = 'ã' (CP850) */
    printf("Linguagem C.\n");

    return 0;
}
