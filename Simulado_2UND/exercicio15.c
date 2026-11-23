/* Questão 15 - Lista de convidados (matriz de strings) (Cap. 7) */
#include <stdio.h>
#include <string.h>

#define QTD 5
#define TAM_NOME 30

void leLinha(char destino[], int tamanho);

int main(void)
{
    char convidados[QTD][TAM_NOME];
    char procurado[TAM_NOME];
    int i, posicao = -1;

    for (i = 0; i < QTD; i++) {
        printf("Nome do convidado %d: ", i + 1);
        leLinha(convidados[i], TAM_NOME);
    }

    printf("Nome a procurar: ");
    leLinha(procurado, TAM_NOME);

    for (i = 0; i < QTD && posicao == -1; i++)
        if (strcmp(convidados[i], procurado) == 0)
            posicao = i + 1;

    if (posicao != -1)
        printf("%s esta na lista, na posicao %d.\n", procurado, posicao);
    else
        printf("%s nao esta na lista.\n", procurado);

    return 0;
}

/* Le uma linha com limite de tamanho e remove o '\n' */
void leLinha(char destino[], int tamanho)
{
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}
