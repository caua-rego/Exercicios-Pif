/* Questão 26 - Pedidos e status */
#include <stdio.h>

#define QTD 6

typedef enum { PENDENTE, PAGO, ENTREGUE } Status;

typedef struct {
    int codigo;
    float valor;
    Status status;
} Pedido;

const char *nomeStatus(Status s);

int main(void)
{
    Pedido pedidos[QTD];
    int quantidade[3] = {0};
    float total[3] = {0};
    int i, codigo, novoStatus, encontrado = 0;

    for (i = 0; i < QTD; i++) {
        printf("\nPedido %d - codigo: ", i + 1);
        scanf("%d", &pedidos[i].codigo);
        printf("Valor: R$ ");
        scanf("%f", &pedidos[i].valor);
        pedidos[i].status = PENDENTE;   /* todo pedido comeca pendente */
    }

    printf("\nCodigo do pedido para alterar o status: ");
    scanf("%d", &codigo);
    printf("Novo status (0 - Pendente, 1 - Pago, 2 - Entregue): ");
    scanf("%d", &novoStatus);

    if (novoStatus < PENDENTE || novoStatus > ENTREGUE) {
        printf("Status invalido, nada foi alterado.\n");
    } else {
        for (i = 0; i < QTD; i++)
            if (pedidos[i].codigo == codigo) {
                pedidos[i].status = (Status)novoStatus;
                encontrado = 1;
            }
        if (!encontrado)
            printf("Pedido %d nao encontrado.\n", codigo);
    }

    for (i = 0; i < QTD; i++) {
        quantidade[pedidos[i].status]++;
        total[pedidos[i].status] += pedidos[i].valor;
    }

    printf("\n");
    for (i = PENDENTE; i <= ENTREGUE; i++)
        printf("%-9s: %d pedido(s), total R$ %.2f\n", nomeStatus((Status)i), quantidade[i], total[i]);

    return 0;
}

const char *nomeStatus(Status s)
{
    switch (s) {
    case PENDENTE: return "Pendente";
    case PAGO:     return "Pago";
    case ENTREGUE: return "Entregue";
    }
    return "?";
}
