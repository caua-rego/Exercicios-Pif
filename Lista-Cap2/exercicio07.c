/* Questão 07 - Lê uma data dd/mm/aaaa e a exibe como aaaa/mm/dd */
#include <stdio.h>

int main(void)
{
    int dia, mes, ano;

    printf("Digite uma data (dd/mm/aaaa): ");
    /* As barras na string de controle do scanf() devem aparecer na entrada:
       elas são "casadas" e descartadas, e só os números são armazenados. */
    scanf("%d/%d/%d", &dia, &mes, &ano);

    printf("Data invertida: %04d/%02d/%02d\n", ano, mes, dia);

    return 0;
}
