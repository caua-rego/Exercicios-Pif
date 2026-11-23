/* Questão 28 - Atendimento automatico bancario (URA) */
#include <stdio.h>

int main(void)
{
    int opcao;

    printf("===== BANCO - ATENDIMENTO =====\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Efetuar Extrato\n");
    printf("3 - Fazer Transferencia\n");
    printf("4 - Falar com Atendente\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        printf("Direcionando para a consulta de saldo...\n");
        break;
    case 2:
        printf("Direcionando para a emissao de extrato...\n");
        break;
    case 3:
        printf("Direcionando para a area de transferencias...\n");
        break;
    case 4:
        printf("Aguarde, voce sera atendido por um de nossos atendentes.\n");
        break;
    default:
        printf("Opcao invalida! Tente novamente.\n");
    }

    return 0;
}
