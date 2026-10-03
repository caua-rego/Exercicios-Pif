/* Questão 04 - Versão corrigida do programa com erros
 * (a lista dos erros encontrados está em respostas.md)
 */
#include <stdio.h>
#include <stdlib.h>              /* removido o ';' após a diretiva */

int main()                       /* 'main' minúsculo e com parênteses */
{                                /* corpo delimitado por chaves */
    printf("Existem %d semanas no ano.", 52); /* string entre aspas */
    printf("\n");                /* 'cout << endl;' é C++; em C usa-se \n */
    system("PAUSE");
    return 0;
}
