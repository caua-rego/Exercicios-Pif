/* Questão 19 - Tabulação em cascata com um único printf() */
#include <stdio.h>

int main(void)
{
    printf("um\n\tdois\n\t\ttr\x88s\n"); /* \x88 = 'ê' na codepage 850/437 do console Windows */

    return 0;
}
