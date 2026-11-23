/* Questão 13 - Contador de vogais e consoantes
 * Obs.: o enunciado pede gets(), mas ela foi removida do C11 por nao limitar
 * o tamanho da leitura. Usamos fgets(), que le a linha inteira com limite. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 200

int main(void)
{
    char frase[TAM], letra;
    int i, tamanho, vogais = 0, consoantes = 0, espacos = 0;

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    tamanho = strlen(frase);
    for (i = 0; i < tamanho; i++) {
        letra = tolower(frase[i]);
        if (letra == ' ')
            espacos++;
        else if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
            vogais++;
        else if (letra >= 'a' && letra <= 'z')
            consoantes++;
    }

    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);
    printf("Espacos: %d\n", espacos);

    return 0;
}
