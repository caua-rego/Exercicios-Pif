/* Questão 05 - Funcoes que recebem vetores */
#include <stdio.h>

#define TAM 8

int somaVetor(int v[], int n);
int maiorValor(int v[], int n);
int buscaValor(int v[], int n, int x);

int main(void)
{
    int vetor[TAM], i, procurado, posicao;

    for (i = 0; i < TAM; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Soma: %d\n", somaVetor(vetor, TAM));
    printf("Maior valor: %d\n", maiorValor(vetor, TAM));

    printf("Valor a buscar: ");
    scanf("%d", &procurado);
    posicao = buscaValor(vetor, TAM, procurado);
    if (posicao == -1)
        printf("%d nao encontrado.\n", procurado);
    else
        printf("%d encontrado na posicao %d (indice do vetor).\n", procurado, posicao);

    return 0;
}

int somaVetor(int v[], int n)
{
    int i, soma = 0;
    for (i = 0; i < n; i++)
        soma += v[i];
    return soma;
}

int maiorValor(int v[], int n)
{
    int i, maior = v[0];
    for (i = 1; i < n; i++)
        if (v[i] > maior)
            maior = v[i];
    return maior;
}

/* devolve a posicao da primeira ocorrencia de x, ou -1 */
int buscaValor(int v[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (v[i] == x)
            return i;
    return -1;
}
