/* Questão 19 - Niveis de acesso com enumeracao (Cap. 8) */
#include <stdio.h>

typedef enum { VISITANTE = 1, USUARIO, ADMIN } Nivel;

typedef struct {
    char nome[50];
    Nivel nivel;
} Usuario;

int main(void)
{
    Usuario usuario;
    int nivelLido;

    printf("Nome: ");
    scanf(" %49[^\n]", usuario.nome);
    printf("Nivel (1 - Visitante, 2 - Usuario, 3 - Administrador): ");
    scanf("%d", &nivelLido);
    usuario.nivel = (Nivel)nivelLido;

    printf("%s: ", usuario.nome);
    switch (usuario.nivel) {
    case VISITANTE:
        printf("apenas leitura\n");
        break;
    case USUARIO:
        printf("leitura e escrita\n");
        break;
    case ADMIN:
        printf("leitura, escrita e gerenciamento de usuarios\n");
        break;
    default:
        printf("nivel de acesso invalido\n");
    }

    return 0;
}
