/* Questão 20 - Cadastro de aluno */
#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota1, nota2;
} Aluno;

int main(void)
{
    Aluno aluno;
    float media;

    printf("Nome: ");
    scanf(" %49[^\n]", aluno.nome);
    printf("Matricula: ");
    scanf("%d", &aluno.matricula);
    printf("Duas notas: ");
    scanf("%f %f", &aluno.nota1, &aluno.nota2);

    media = (aluno.nota1 + aluno.nota2) / 2;
    printf("\n%s (matricula %d) - media %.2f: ", aluno.nome, aluno.matricula, media);

    if (media >= 7)
        printf("Aprovado\n");
    else if (media >= 4)
        printf("Final\n");
    else
        printf("Reprovado\n");

    return 0;
}
