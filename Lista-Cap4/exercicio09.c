/* Questão 09 - Media ponderada e situacao academica */
#include <stdio.h>

int main(void)
{
    float laboratorio, semestral, exameFinal, media;

    printf("Nota do trabalho de laboratorio (peso 2): ");
    scanf("%f", &laboratorio);
    printf("Nota da avaliacao semestral (peso 3): ");
    scanf("%f", &semestral);
    printf("Nota do exame final (peso 5): ");
    scanf("%f", &exameFinal);

    media = (laboratorio * 2 + semestral * 3 + exameFinal * 5) / 10;
    printf("Media ponderada: %.2f\n", media);

    if (media >= 5.0f)
        printf("Situacao: Aprovado\n");
    else if (media >= 3.0f)
        printf("Situacao: Em Recuperacao\n");
    else
        printf("Situacao: Reprovado\n");

    return 0;
}
