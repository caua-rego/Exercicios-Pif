/* Questão 15 - Media ponderada e situacao */
#include <stdio.h>

float mediaPonderada(float n1, float n2, float n3);
void exibeSituacao(float media);

int main(void)
{
    float nota1, nota2, nota3, media;

    printf("Digite as tres notas: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    media = mediaPonderada(nota1, nota2, nota3);
    printf("Media ponderada = %.2f\n", media);
    exibeSituacao(media);

    return 0;
}

/* Pesos 2, 3 e 5 (soma dos pesos = 10) */
float mediaPonderada(float n1, float n2, float n3)
{
    return (n1 * 2 + n2 * 3 + n3 * 5) / 10;
}

void exibeSituacao(float media)
{
    if (media >= 5.0f)
        printf("Situacao: Aprovado\n");
    else if (media >= 3.0f)
        printf("Situacao: Em Recuperacao\n");
    else
        printf("Situacao: Reprovado\n");
}
