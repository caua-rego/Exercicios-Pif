/* Questão 15 - Minhas proprias funcoes de string (sem string.h) */
#include <stdio.h>

#define TAM 100

int meuStrlen(char s[]);
void inverte(char s[]);
void removeChar(char s[], int pos);

int main(void)
{
    char texto[TAM];
    int posicao;

    printf("Digite uma palavra: ");
    scanf("%99s", texto);

    printf("Tamanho: %d\n", meuStrlen(texto));

    inverte(texto);
    printf("Invertida: %s\n", texto);
    inverte(texto);   /* volta ao original para o proximo teste */

    printf("Posicao do caractere a remover (0 a %d): ", meuStrlen(texto) - 1);
    scanf("%d", &posicao);
    removeChar(texto, posicao);
    printf("Resultado: %s\n", texto);

    return 0;
}

/* conta caracteres ate o terminador nulo */
int meuStrlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

/* troca as pontas ate chegar ao meio */
void inverte(char s[])
{
    int inicio = 0, fim = meuStrlen(s) - 1;
    char aux;

    while (inicio < fim) {
        aux = s[inicio];
        s[inicio] = s[fim];
        s[fim] = aux;
        inicio++;
        fim--;
    }
}

/* desloca para a esquerda tudo o que vem depois de pos (inclusive o '\0') */
void removeChar(char s[], int pos)
{
    int i, tamanho = meuStrlen(s);

    if (pos < 0 || pos >= tamanho)
        return;   /* posicao invalida: nao altera a string */

    for (i = pos; i < tamanho; i++)
        s[i] = s[i + 1];
}
