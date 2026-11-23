/* Questão 21 - Reajuste salarial por categoria */
#include <stdio.h>

int main(void)
{
    float salario, percentual, aumento;
    int cargo;

    printf("Salario atual: R$ ");
    scanf("%f", &salario);
    printf("Cargo (1 - Tecnico, 2 - Gerente, 3 - Demais cargos): ");
    scanf("%d", &cargo);

    switch (cargo) {
    case 1:
        percentual = (salario <= 3000) ? 0.15f : 0.10f;
        break;
    case 2:
        percentual = (salario <= 5000) ? 0.10f : 0.05f;
        break;
    case 3:
        percentual = 0.08f;
        break;
    default:
        printf("Codigo de cargo invalido.\n");
        return 1;
    }

    aumento = salario * percentual;
    printf("Aumento (%.0f%%): R$ %.2f\n", percentual * 100, aumento);
    printf("Novo salario: R$ %.2f\n", salario + aumento);

    return 0;
}
