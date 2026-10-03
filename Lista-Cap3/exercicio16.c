/* Questão 16 - Autenticação de senha com no máximo 3 tentativas */
#include <stdio.h>

#define SENHA           2026
#define MAX_TENTATIVAS  3

int main(void)
{
    int digitada, tentativas = 0, acertou = 0;

    while (tentativas < MAX_TENTATIVAS && !acertou) {
        printf("Digite a senha (tentativa %d de %d): ", tentativas + 1, MAX_TENTATIVAS);
        scanf("%d", &digitada);
        tentativas++;

        if (digitada == SENHA)
            acertou = 1;
        else if (tentativas < MAX_TENTATIVAS)
            printf("Senha incorreta!\n");
    }

    if (acertou)
        printf("Acesso Concedido! Tentativas utilizadas: %d\n", tentativas);
    else
        printf("Conta Bloqueada por Seguranca!\n");

    return 0;
}
