/*
 * Questao 14 - Autenticacao de senha com limite de tentativas
 * Senha secreta: 2026. O usuario tem no maximo 3 tentativas.
 */
#include <stdio.h>

#define SENHA_SECRETA   2026
#define MAX_TENTATIVAS  3

int main(void) {
    int senha, lidos, ch;
    int tentativa = 1;
    int acertou = 0;

    while (tentativa <= MAX_TENTATIVAS && !acertou) {
        printf("Tentativa %d de %d - Digite a senha: ", tentativa, MAX_TENTATIVAS);
        lidos = scanf("%d", &senha);

        if (lidos == EOF) {             /* entrada encerrada */
            break;
        }

        if (lidos != 1) {               /* digitou algo que nao e numero */
            while ((ch = getchar()) != '\n' && ch != EOF) { }  /* limpa o buffer */
            senha = -1;                 /* conta como senha errada */
        }

        if (senha == SENHA_SECRETA) {
            acertou = 1;
        } else if (tentativa < MAX_TENTATIVAS) {
            printf("Senha incorreta! Restam %d tentativa(s).\n", MAX_TENTATIVAS - tentativa);
        }

        tentativa++;
    }

    if (acertou) {
        printf("Acesso Concedido!\n");
    } else {
        printf("Conta Bloqueada por Seguranca!\n");
    }

    return 0;
}
