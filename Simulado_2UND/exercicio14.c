/* Questão 14 - Cifra de Cesar (Cap. 7)
 * Obs.: o enunciado pede gets(), mas ela foi removida do padrao C11 por nao
 * controlar o tamanho do vetor (risco de estouro). Usamos fgets(), que faz a
 * mesma leitura de linha inteira com limite, e removemos o '\n' do final. */
#include <stdio.h>
#include <string.h>

#define TAM_MSG 100

int main(void)
{
    char mensagem[TAM_MSG];
    int k, i;

    printf("Mensagem (letras maiusculas): ");
    fgets(mensagem, TAM_MSG, stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0';

    printf("Deslocamento k: ");
    scanf("%d", &k);
    k = ((k % 26) + 26) % 26;   /* aceita k negativo ou maior que 26 */

    for (i = 0; mensagem[i] != '\0'; i++)
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z')
            mensagem[i] = 'A' + (mensagem[i] - 'A' + k) % 26;

    printf("Mensagem criptografada: ");
    puts(mensagem);

    return 0;
}
