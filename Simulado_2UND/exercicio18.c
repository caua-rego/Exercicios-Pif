/* Questão 18 - Cadastro de funcionarios (vetor de estruturas) (Cap. 8) */
#include <stdio.h>
#include <string.h>

#define QTD 4

typedef struct {
    char nome[50];
    int codigo;
    float salario;
} Funcionario;

int main(void)
{
    Funcionario funcionarios[QTD];
    float soma = 0, media;
    int i, indiceMaior = 0;

    for (i = 0; i < QTD; i++) {
        printf("\nFuncionario %d\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", funcionarios[i].nome);
        printf("Codigo: ");
        scanf("%d", &funcionarios[i].codigo);
        printf("Salario: R$ ");
        scanf("%f", &funcionarios[i].salario);

        soma += funcionarios[i].salario;
        if (funcionarios[i].salario > funcionarios[indiceMaior].salario)
            indiceMaior = i;
    }

    media = soma / QTD;

    printf("\nMaior salario: %s (codigo %d) - R$ %.2f\n",
           funcionarios[indiceMaior].nome, funcionarios[indiceMaior].codigo,
           funcionarios[indiceMaior].salario);
    printf("Media salarial: R$ %.2f\n", media);

    printf("\nReajuste de 10%% para quem ganha abaixo da media:\n");
    for (i = 0; i < QTD; i++)
        if (funcionarios[i].salario < media)
            printf("%s: R$ %.2f -> R$ %.2f\n", funcionarios[i].nome,
                   funcionarios[i].salario, funcionarios[i].salario * 1.10f);

    return 0;
}
