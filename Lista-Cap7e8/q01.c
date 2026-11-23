/* Questão 01 - Notas da turma */
#include <stdio.h>

#define TAM 10

int main(void)
{
    float notas[TAM], soma = 0, media, maior, menor;
    int i, acimaDaMedia = 0;

    for (i = 0; i < TAM; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / TAM;
    maior = menor = notas[0];
    for (i = 1; i < TAM; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }
    for (i = 0; i < TAM; i++)
        if (notas[i] > media)
            acimaDaMedia++;

    printf("\nMedia da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
    printf("Alunos acima da media: %d\n", acimaDaMedia);

    return 0;
}
