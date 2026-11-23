/* Questão 16 - Autenticacao de usuario */
#include <stdio.h>
#include <string.h>

#define SENHA_CORRETA "c@esar2026"
#define MAX_TENTATIVAS 3
#define TAM_MINIMO 6

int main(void)
{
    char senha[50];
    int tentativas = 0, liberado = 0;

    while (tentativas < MAX_TENTATIVAS && !liberado) {
        printf("Senha (tentativa %d de %d): ", tentativas + 1, MAX_TENTATIVAS);
        scanf("%49s", senha);

        if (strlen(senha) < TAM_MINIMO) {
            printf("A senha deve ter pelo menos %d caracteres (nao contou como tentativa).\n", TAM_MINIMO);
            continue;
        }

        tentativas++;
        if (strcmp(senha, SENHA_CORRETA) == 0)
            liberado = 1;
        else
            printf("Senha incorreta.\n");
    }

    if (liberado)
        printf("Acesso liberado\n");
    else
        printf("Acesso bloqueado\n");

    return 0;
}
